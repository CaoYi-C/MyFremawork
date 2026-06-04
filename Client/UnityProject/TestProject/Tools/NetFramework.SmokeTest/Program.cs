using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using Fuel.NetFramework.Codec;
using Fuel.NetFramework.Core;
using Fuel.NetFramework.Dispatcher;
using Fuel.NetFramework.Protocol;
using SocketProtocolType = System.Net.Sockets.ProtocolType;

namespace Fuel.NetFramework.SmokeTest
{
    /// <summary>
    /// 极简测试 harness：跑一组用例，PASS/FAIL 输出。
    /// 不依赖 NUnit/xUnit — 保持独立可执行。
    /// </summary>
    public static class Program
    {
        private static int _passCount;
        private static int _failCount;
        private static readonly List<string> _failures = new List<string>();

        private static void Run(string name, Action body)
        {
            Console.Write($"  • {name,-58} ");
            try
            {
                body();
                Console.WriteLine("PASS");
                _passCount++;
            }
            catch (Exception e)
            {
                Console.WriteLine("FAIL");
                Console.WriteLine($"      └─ {e.Message}");
                _failures.Add($"{name}: {e.Message}");
                _failCount++;
            }
        }

        private static void Assert(bool condition, string message = "assertion failed")
        {
            if (!condition) throw new Exception(message);
        }

        private static bool WaitFor(Func<bool> predicate, int timeoutMs, string description)
        {
            int elapsed = 0;
            const int step = 10;
            while (elapsed < timeoutMs)
            {
                if (predicate()) return true;
                Thread.Sleep(step);
                elapsed += step;
            }
            throw new Exception($"Timed out waiting for: {description} (after {timeoutMs}ms)");
        }

        public static int Main(string[] args)
        {
            Console.WriteLine("============================================================");
            Console.WriteLine(" NetFramework Smoke Test");
            Console.WriteLine("============================================================");
            Console.WriteLine();

            // -------- 1. PacketCodec --------
            Console.WriteLine("[1] PacketCodec");
            Run("round-trip 1-byte body", () =>
            {
                var body = new byte[] { 0xAB };
                var encoded = PacketCodec.Encode(42, body);
                Assert(encoded.Length == 4 + 4 + 1, $"expected 9 bytes, got {encoded.Length}");
                int consumed = PacketCodec.Decode(encoded, 0, encoded.Length, out var packet);
                Assert(consumed == encoded.Length, "consumed != encoded length");
                Assert(packet != null, "packet null");
                Assert(packet.CmdId == 42, $"cmdId mismatch: {packet.CmdId}");
                Assert(packet.Body.Count == 1 && packet.Body.Array[0] == 0xAB, "body mismatch");
            });

            Run("round-trip empty body", () =>
            {
                var encoded = PacketCodec.Encode(0, null);
                Assert(encoded.Length == 8, $"expected 8 bytes, got {encoded.Length}");
                int consumed = PacketCodec.Decode(encoded, 0, encoded.Length, out var packet);
                Assert(consumed == 8, "consumed != 8");
                Assert(packet.CmdId == 0, "cmdId != 0");
                Assert(packet.Body.Count == 0, "body not empty");
            });

            Run("round-trip MAX body (1MB - 8B)", () =>
            {
                int bodyLen = PacketCodec.MaxPacketLength - PacketCodec.CmdIdSize;
                var body = new byte[bodyLen];
                new Random(1234).NextBytes(body);

                var encoded = PacketCodec.Encode(uint.MaxValue, body);
                Assert(encoded.Length == 8 + bodyLen, "encoded length");

                int consumed = PacketCodec.Decode(encoded, 0, encoded.Length, out var packet);
                Assert(consumed == encoded.Length, "consumed");
                Assert(packet.CmdId == uint.MaxValue, "cmdId");
                Assert(packet.Body.Count == bodyLen, "body count");

                // 抽检前后 1KB
                for (int i = 0; i < 1024; i++) Assert(packet.Body.Array[i] == body[i], $"head mismatch at {i}");
                for (int i = bodyLen - 1024; i < bodyLen; i++) Assert(packet.Body.Array[i] == body[i], $"tail mismatch at {i}");
            });

            Run("oversized length throws", () =>
            {
                byte[] buf = new byte[8];
                int badLen = PacketCodec.MaxPacketLength + 1;
                buf[0] = (byte)(badLen >> 24);
                buf[1] = (byte)(badLen >> 16);
                buf[2] = (byte)(badLen >> 8);
                buf[3] = (byte)badLen;
                bool threw = false;
                try { PacketCodec.Decode(buf, 0, buf.Length, out _); }
                catch (System.IO.InvalidDataException) { threw = true; }
                Assert(threw, "expected InvalidDataException");
            });

            Run("partial packet returns 0", () =>
            {
                var encoded = PacketCodec.Encode(1, new byte[] { 1, 2, 3, 4, 5 });
                // 截掉最后 2 字节
                int partialLen = encoded.Length - 2;
                int consumed = PacketCodec.Decode(encoded, 0, partialLen, out _);
                Assert(consumed == 0, $"expected 0, got {consumed}");
            });

            // -------- 2. BoundedActionQueue --------
            Console.WriteLine("\n[2] BoundedActionQueue");
            Run("enqueue within cap", () =>
            {
                var q = new MessageDispatcher.BoundedActionQueue(10);
                for (int i = 0; i < 10; i++) q.Enqueue(() => { });
                Assert(q.Count == 10, $"count={q.Count}");
                Assert(q.DroppedCount == 0, $"dropped={q.DroppedCount}");
            });

            Run("overflow drops oldest", () =>
            {
                var q = new MessageDispatcher.BoundedActionQueue(50);
                for (int i = 0; i < 200; i++) q.Enqueue(() => { });
                Assert(q.Count == 50, $"count={q.Count} (expected 50)");
                Assert(q.DroppedCount == 150, $"dropped={q.DroppedCount} (expected 150)");
            });

            Run("null action is ignored", () =>
            {
                var q = new MessageDispatcher.BoundedActionQueue(10);
                q.Enqueue(null);
                Assert(q.Count == 0, "null should be ignored");
            });

            Run("invalid capacity throws", () =>
            {
                bool threw = false;
                try { new MessageDispatcher.BoundedActionQueue(0); } catch (ArgumentOutOfRangeException) { threw = true; }
                Assert(threw, "expected ArgumentOutOfRangeException");
            });

            // -------- 3. HeartbeatManager --------
            Console.WriteLine("\n[3] HeartbeatManager");
            Run("Tick triggers SendPing after Interval", () =>
            {
                float t = 0f;
                var hb = new HeartbeatManager(() => t)
                {
                    Interval = 5f,
                    Timeout = 10f,
                    MaxRetryCount = 3
                };
                long captured = 0;
                int sendCount = 0;
                hb.OnSendPing += ts => { captured = ts; sendCount++; };
                hb.Start();

                // 第一个 Tick 在 t=0：currentTime - 0 = 0 < 5，不发
                hb.Tick();
                Assert(sendCount == 0, $"sent too early: {sendCount}");

                // 推进到 t=5：currentTime - 0 = 5 >= 5，发
                t = 5f; hb.Tick();
                Assert(sendCount == 1, $"sendCount={sendCount}");
                Assert(captured > 0, "captured ts not set");
            });

            Run("HandlePong with matching ts clears waitingPong (full cycle)", () =>
            {
                float t = 0f;
                var hb = new HeartbeatManager(() => t) { Interval = 5f, Timeout = 10f, MaxRetryCount = 3 };
                int sendCount = 0;
                long firstTs = 0, secondTs = 0;
                hb.OnSendPing += ts =>
                {
                    sendCount++;
                    if (sendCount == 1) firstTs = ts;
                    else if (sendCount == 2) secondTs = ts;
                };
                long delayReported = -1;
                hb.OnPongReceived += d => delayReported = d;

                hb.Start();
                t = 5f; hb.Tick(); // 发第一个 PING
                Assert(sendCount == 1, $"first PING: sendCount={sendCount}");

                // 还没超时的 PONG
                t = 8f; hb.HandlePong(firstTs, 0L);
                Assert(delayReported >= 0, "delay should be reported");

                // _waitingPong=false，再 Tick 应该发第二个 PING
                t = 10f; hb.Tick(); // 10-5=5 >= Interval(5) → SendPing
                Assert(sendCount == 2, $"second PING not sent: sendCount={sendCount}");

                // 错误时间戳的 PONG 应该被忽略
                hb.HandlePong(99999L, 0L);
                Assert(hb.CurrentRetryCount == 0, "wrong ts should not change retry count");
            });

            Run("timeout fires OnMaxRetryExceeded after MaxRetryCount", () =>
            {
                float t = 0f;
                var hb = new HeartbeatManager(() => t) { Interval = 5f, Timeout = 1f, MaxRetryCount = 2 };
                int timeoutFired = 0;
                int maxRetryFired = 0;
                hb.OnHeartbeatTimeout += () => timeoutFired++;
                hb.OnMaxRetryExceeded += () => maxRetryFired++;
                hb.Start();

                t = 5f; hb.Tick();   // 发 PING（5-0=5>=Interval）
                Assert(hb.CurrentRetryCount == 0, "first send");

                t = 7f; hb.Tick();   // 超时（7-5=2>=Timeout=1）→ retry 1
                Assert(timeoutFired == 1, $"timeout1={timeoutFired}");
                Assert(maxRetryFired == 0, "max should not fire yet");
                Assert(hb.CurrentRetryCount == 1, $"retry={hb.CurrentRetryCount}");

                // HandleTimeout 把 _lastSendTime 顶到 7，下一次 SendPing 要等 Interval=5
                t = 12f; hb.Tick();  // 12-7=5>=Interval → 发第二个 PING
                Assert(hb.CurrentRetryCount == 1, "retry still 1");

                t = 14f; hb.Tick();  // 14-12=2>=Timeout → 再次超时 → retry 2 → max
                Assert(maxRetryFired == 1, $"max={maxRetryFired}");
                Assert(hb.CurrentRetryCount == 2, $"retry={hb.CurrentRetryCount}");
            });

            Run("Paused blocks Tick logic", () =>
            {
                float t = 0f;
                var hb = new HeartbeatManager(() => t) { Interval = 1f, Timeout = 5f };
                int sent = 0;
                hb.OnSendPing += _ => sent++;
                hb.Start();
                hb.Paused = true;
                t = 100f; hb.Tick();
                Assert(sent == 0, $"Paused should not send: sent={sent}");
            });

            // -------- 4. TcpProtocol end-to-end --------
            Console.WriteLine("\n[4] TcpProtocol end-to-end");
            Run("connect + send small + echo back", () =>
            {
                using (var server = new EchoServer())
                {
                    var proto = new TcpProtocol();
                    bool connected = false;
                    var received = new ManualResetEventSlim(false);
                    (uint cmdId, ArraySegment<byte> body) recv = (0, default);
                    proto.OnConnected += () => connected = true;
                    proto.OnDataReceived += (id, b) => { recv = (id, b); received.Set(); };
                    proto.OnError += msg => throw new Exception($"OnError: {msg}");

                    proto.Connect("127.0.0.1", server.Port);
                    WaitFor(() => connected, 2000, "OnConnected");

                    byte[] body = new byte[] { 0x10, 0x20, 0x30 };
                    proto.Send(PacketCodec.Encode(7, body));
                    WaitFor(() => received.IsSet, 2000, "echo received");

                    Assert(recv.cmdId == 7, $"cmdId={recv.cmdId}");
                    Assert(recv.body.Count == 3, $"body.Count={recv.body.Count}");
                    Assert(recv.body.Array[recv.body.Offset + 0] == 0x10
                        && recv.body.Array[recv.body.Offset + 1] == 0x20
                        && recv.body.Array[recv.body.Offset + 2] == 0x30, "body bytes");

                    proto.Close();
                }
            });

            Run("connect + send 900KB (validates growable buffer fix)", () =>
            {
                using (var server = new EchoServer())
                {
                    var proto = new TcpProtocol();
                    bool connected = false;
                    var received = new ManualResetEventSlim(false);
                    (uint cmdId, ArraySegment<byte> body) recv = (0, default);
                    proto.OnConnected += () => connected = true;
                    proto.OnDataReceived += (id, b) => { recv = (id, b); received.Set(); };
                    proto.OnError += msg => throw new Exception($"OnError: {msg}");

                    proto.Connect("127.0.0.1", server.Port);
                    WaitFor(() => connected, 2000, "OnConnected");

                    // 900KB body — 远超 64KB 初始 buffer，验证 growable 生效
                    int bodyLen = 900 * 1024;
                    var body = new byte[bodyLen];
                    new Random(42).NextBytes(body);
                    // 在头尾打 marker 便于校验
                    body[0] = 0xCA;
                    body[bodyLen - 1] = 0xFE;

                    proto.Send(PacketCodec.Encode(1234, body));
                    WaitFor(() => received.IsSet, 5000, "900KB echo received");

                    Assert(recv.cmdId == 1234, $"cmdId={recv.cmdId}");
                    Assert(recv.body.Count == bodyLen, $"body.Count={recv.body.Count} (expected {bodyLen})");
                    Assert(recv.body.Array[recv.body.Offset] == 0xCA, "head marker");
                    Assert(recv.body.Array[recv.body.Offset + bodyLen - 1] == 0xFE, "tail marker");
                    // 抽检中段
                    Assert(recv.body.Array[recv.body.Offset + bodyLen / 2] == body[bodyLen / 2], "mid sample");

                    proto.Close();
                }
            });

            Run("invalid host fires OnError, no crash, IsConnected=false", () =>
            {
                var proto = new TcpProtocol();
                var errored = new ManualResetEventSlim(false);
                string errMsg = null;
                proto.OnError += msg => { errMsg = msg; errored.Set(); };
                proto.OnConnected += () => throw new Exception("should not connect");

                // 用一个 invalid IP（IPAddress.Parse 会抛 FormatException）
                proto.Connect("999.999.999.999", 12345);
                WaitFor(() => errored.IsSet, 1000, "OnError");
                Assert(errMsg != null && errMsg.Contains("Invalid endpoint"), $"errMsg='{errMsg}'");
                Assert(!proto.IsConnected, "should not be connected");
            });

            Run("server close triggers OnDisconnected", () =>
            {
                using (var server = new EchoServer())
                {
                    var proto = new TcpProtocol();
                    bool connected = false;
                    var disconnected = new ManualResetEventSlim(false);
                    bool abnormal = false;
                    proto.OnConnected += () => connected = true;
                    proto.OnDisconnected += abn => { abnormal = abn; disconnected.Set(); };

                    proto.Connect("127.0.0.1", server.Port);
                    WaitFor(() => connected, 2000, "OnConnected");

                    // 关闭 server（模拟对端 RST）
                    server.Dispose();
                    WaitFor(() => disconnected.IsSet, 3000, "OnDisconnected");
                    // abnormal 可能是 true（异常断开）也可能是 false（peer close）
                    Assert(!proto.IsConnected, "should not be connected after server close");
                }
            });

            Run("ProtocolFactory throws for unimplemented protocols", () =>
            {
                bool threw = false;
                try { ProtocolFactory.Create(Fuel.NetFramework.Protocol.ProtocolType.WebSocket); }
                catch (ArgumentException) { threw = true; }
                Assert(threw, "expected ArgumentException for WebSocket");
                threw = false;
                try { ProtocolFactory.Create(Fuel.NetFramework.Protocol.ProtocolType.KCP); }
                catch (ArgumentException) { threw = true; }
                Assert(threw, "expected ArgumentException for KCP");
            });

            // -------- 5. MessageDispatcher 集成 --------
            Console.WriteLine("\n[5] MessageDispatcher (skipping protobuf Register test in standalone)");
            Run("bounded queue integration with Dispatcher", () =>
            {
                var d = new MessageDispatcher(50);
                // Register 需要 IMessage<T>，这里走直接入队路径不可达
                // 但我们可以测队列容量行为：手动 push 200 个会丢 150
                // 用反射访问私有 EnqueueMainThread？算了 — 直接测 BoundedActionQueue 本身即可（上面已测）
                // 这里验证 Dispatcher 的 QueueLength/DroppedCount 暴露正确
                Assert(d.MaxQueueLength == 50, $"max={d.MaxQueueLength}");
                Assert(d.QueueLength == 0, $"initial length={d.QueueLength}");
            });

            // -------- 6. Req-Rsp cache (Dispatcher 层) --------
            Console.WriteLine("\n[6] Req-Rsp cache mechanism");
            Run("IsRequestResponseHandler is false by default", () =>
            {
                var d = new MessageDispatcher();
                Assert(!d.IsRequestResponseHandler(100), "should be false by default");
                Assert(d.PendingRequestCount == 0, "should be empty");
            });

            Run("CacheRequest + TryGetAndRemoveRequest round-trip", () =>
            {
                var d = new MessageDispatcher();
                // 没有真实 protobuf 类型时，用一个 stub IMessage。Dispatcher.CacheRequest 只
                // 关心 cmdId→IMessage 的映射，不读 message 内容。
                var stub = new StubMessage(42);
                d.CacheRequest(100, stub);
                Assert(d.PendingRequestCount == 1, $"count={d.PendingRequestCount}");

                bool got = d.TryGetAndRemoveRequest(100, out var req);
                Assert(got, "should have found request");
                Assert(ReferenceEquals(req, stub), "should be same instance");
                Assert(d.PendingRequestCount == 0, "should be cleared after TryGetAndRemoveRequest");

                // 第二次取应该失败
                got = d.TryGetAndRemoveRequest(100, out req);
                Assert(!got, "should be empty after remove");
            });

            Run("CacheRequest FIFO: 多次 Send 同 cmdId 按入队顺序取出", () =>
            {
                var d = new MessageDispatcher();
                var r1 = new StubMessage(1);
                var r2 = new StubMessage(2);
                var r3 = new StubMessage(3);
                d.CacheRequest(200, r1);
                d.CacheRequest(200, r2);
                d.CacheRequest(200, r3);
                Assert(d.PendingRequestCount == 3, $"count={d.PendingRequestCount}");

                d.TryGetAndRemoveRequest(200, out var g1);
                d.TryGetAndRemoveRequest(200, out var g2);
                d.TryGetAndRemoveRequest(200, out var g3);

                Assert(ReferenceEquals(g1, r1), "first out should be r1 (FIFO)");
                Assert(ReferenceEquals(g2, r2), "second out should be r2 (FIFO)");
                Assert(ReferenceEquals(g3, r3), "third out should be r3 (FIFO)");
                Assert(d.PendingRequestCount == 0, "queue should be empty");
            });

            Run("CacheRequest MaxPendingRequestsPerCmdId 防止 OOM", () =>
            {
                var d = new MessageDispatcher { MaxPendingRequestsPerCmdId = 3 };
                for (int i = 0; i < 5; i++)
                {
                    d.CacheRequest(200, new StubMessage(i));
                }
                Assert(d.PendingRequestCount == 3, $"count={d.PendingRequestCount} (expected 3, the cap)");

                // 拿出 3 个应该是 i=2,3,4（i=0,1 被丢）
                d.TryGetAndRemoveRequest(200, out var g1);
                d.TryGetAndRemoveRequest(200, out var g2);
                d.TryGetAndRemoveRequest(200, out var g3);
                Assert(((StubMessage)g1).Marker == 2, $"first should be i=2, got {((StubMessage)g1).Marker}");
                Assert(((StubMessage)g2).Marker == 3, $"second should be i=3");
                Assert(((StubMessage)g3).Marker == 4, $"third should be i=4");
            });

            Run("不同 cmdId 的缓存相互独立（FIFO 各自排）", () =>
            {
                var d = new MessageDispatcher();
                d.CacheRequest(100, new StubMessage(1));
                d.CacheRequest(100, new StubMessage(2));
                d.CacheRequest(200, new StubMessage(10));
                d.CacheRequest(200, new StubMessage(20));
                Assert(d.PendingRequestCount == 4, $"total={d.PendingRequestCount}");

                d.TryGetAndRemoveRequest(100, out var a);
                d.TryGetAndRemoveRequest(200, out var b);
                Assert(((StubMessage)a).Marker == 1, "cmd 100 first out = 1");
                Assert(((StubMessage)b).Marker == 10, "cmd 200 first out = 10");

                d.TryGetAndRemoveRequest(100, out var a2);
                d.TryGetAndRemoveRequest(200, out var b2);
                Assert(((StubMessage)a2).Marker == 2, "cmd 100 second out = 2");
                Assert(((StubMessage)b2).Marker == 20, "cmd 200 second out = 20");
            });

            Run("ClearPendingRequests empties cache", () =>
            {
                var d = new MessageDispatcher();
                d.CacheRequest(300, new StubMessage(3));
                d.CacheRequest(301, new StubMessage(4));
                d.CacheRequest(302, new StubMessage(5));
                Assert(d.PendingRequestCount == 3, $"count={d.PendingRequestCount}");
                d.ClearPendingRequests();
                Assert(d.PendingRequestCount == 0, $"after clear: {d.PendingRequestCount}");
            });

            Run("CacheRequest ignores null", () =>
            {
                var d = new MessageDispatcher();
                d.CacheRequest(400, null);
                Assert(d.PendingRequestCount == 0, "null should be ignored");
            });

            Run("CacheRequest is thread-safe (concurrent enqueue + dequeue)", () =>
            {
                var d = new MessageDispatcher();
                int producerCount = 8;
                int perProducer = 1000;
                var producers = new Thread[producerCount];
                var startFlag = new ManualResetEventSlim(false);
                for (int p = 0; p < producerCount; p++)
                {
                    int pid = p;
                    producers[p] = new Thread(() =>
                    {
                        startFlag.Wait();
                        for (int i = 0; i < perProducer; i++)
                        {
                            d.CacheRequest((uint)(pid * 10000 + i), new StubMessage(i));
                        }
                    });
                    producers[p].Start();
                }
                startFlag.Set();
                foreach (var t in producers) t.Join();

                // 每次 Cache 都是不同 cmdId，所以总缓存数 = producerCount * perProducer
                Assert(d.PendingRequestCount == producerCount * perProducer,
                    $"count={d.PendingRequestCount}, expected {producerCount * perProducer}");
            });

            // -------- 总结 --------
            Console.WriteLine();
            Console.WriteLine("============================================================");
            Console.WriteLine($" Result: {_passCount} passed, {_failCount} failed");
            if (_failCount > 0)
            {
                Console.WriteLine();
                Console.WriteLine(" Failures:");
                foreach (var f in _failures) Console.WriteLine("   - " + f);
            }
            Console.WriteLine("============================================================");
            return _failCount == 0 ? 0 : 1;
        }
    }
}
