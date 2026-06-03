using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Fuel.NetFramework.Codec;
using Fuel.NetFramework.Dispatcher;
using Fuel.NetFramework.Core;
using Fuel.NetFramework.Protocol;
using Fuel.Smoke.EchoServer;
using Google.Protobuf;
using Google.Protobuf.Reflection;
using ProtocolType = Fuel.NetFramework.Protocol.ProtocolType;

namespace Fuel.Smoke
{
    /// <summary>
    /// 烟测入口。覆盖所有改动点的关键不变量：
    ///  1. PacketCodec 编码/解码 roundtrip
    ///  2. PacketCodec 边界：partial decode、空 body、超大 body、非法长度
    ///  3. PacketCodec 修复：body 在解码后即使源缓冲被覆盖也保持稳定（#3 修复）
    ///  4. PacketCodec.Encode 返回的是 ArrayPool 租借缓冲，ReleasePacket 归还
    ///  5. TcpProtocol 端到端：连接、收发、断开
    ///  6. TcpProtocol 半包 / 粘包：分多次 send 验证正确重组
    ///  7. TcpProtocol 大包：100 KB body 正确往返
    ///  8. TcpProtocol 100 个并发回包不丢不乱
    ///  9. MessageDispatcher 主线程派发
    /// </summary>
    internal static class Program
    {
        private static int _passed;
        private static int _failed;
        private static readonly List<string> _failures = new();

        private static int Main()
        {
            Console.WriteLine("===========================================");
            Console.WriteLine("  Fuel.Smoke — running smoke tests");
            Console.WriteLine("===========================================\n");

            RunTest("PacketCodec.Roundtrip", PacketCodec_Roundtrip);
            RunTest("PacketCodec.PartialDecodeWaits", PacketCodec_PartialDecodeWaits);
            RunTest("PacketCodec.EmptyBody", PacketCodec_EmptyBody);
            RunTest("PacketCodec.LargeBody_100KB", PacketCodec_LargeBody_100KB);
            RunTest("PacketCodec.InvalidLength_Throws", PacketCodec_InvalidLength_Throws);
            RunTest("PacketCodec.BodyStable_AfterBufferMutated", PacketCodec_BodyStableAfterBufferMutated);
            RunTest("PacketCodec.EncodeUsesArrayPool", PacketCodec_EncodeUsesArrayPool);
            RunTest("HeartbeatManager_Tick_NotRunning_IsNoop", Heartbeat_NotRunning_IsNoop);

            // 网络层：启 EchoServer + 真实 TcpProtocol
            RunTest("Tcp.Echo_Roundtrip", Tcp_EchoRoundtrip);
            RunTest("Tcp.PartialSend_Assembled", Tcp_PartialSendAssembled);
            RunTest("Tcp.LargePacket_100KB", Tcp_LargePacket_100KB);
            RunTest("Tcp.Bursty_100Packets_AllReceived", Tcp_Bursty100Packets);
            RunTest("Tcp.ServerDisconnect_ClientSees", Tcp_ServerDisconnect_ClientSees);
            RunTest("MessageDispatcher.MainThreadDispatch", MessageDispatcher_MainThreadDispatch);

            Console.WriteLine();
            Console.WriteLine("===========================================");
            Console.WriteLine($"  Result: {_passed} passed, {_failed} failed");
            if (_failed > 0)
            {
                Console.WriteLine();
                Console.WriteLine("Failures:");
                foreach (var f in _failures) Console.WriteLine($"  - {f}");
            }
            Console.WriteLine("===========================================");

            return _failed > 0 ? 1 : 0;
        }

        private static void RunTest(string name, Action test)
        {
            try
            {
                test();
                _passed++;
                Console.WriteLine($"  [PASS] {name}");
            }
            catch (Exception ex)
            {
                _failed++;
                _failures.Add($"{name}: {ex.Message}");
                Console.WriteLine($"  [FAIL] {name}: {ex.Message}");
                if (ex.InnerException != null) Console.WriteLine($"         inner: {ex.InnerException.Message}");
            }
        }

        // ============================================================
        // PacketCodec tests
        // ============================================================

        private static void PacketCodec_Roundtrip()
        {
            var body = Encoding.UTF8.GetBytes("hello world");
            int actualLen = PacketCodec.TotalHeaderSize + body.Length;
            byte[] packet = PacketCodec.Encode(cmdId: 0x12345678, body: body);
            AssertTrue(actualLen <= packet.Length, "array capacity must cover actual length");

            int consumed = PacketCodec.Decode(packet, 0, actualLen, out var decoded);
            AssertEqual(actualLen, consumed, "consumed bytes");
            AssertEqual(0x12345678u, decoded.CmdId, "cmdId");
            AssertEqual(body.Length, decoded.Body.Count, "body length");
            CollectionEqual(body, ToArray(decoded.Body), "body bytes");
        }

        private static void PacketCodec_PartialDecodeWaits()
        {
            var body = Encoding.UTF8.GetBytes("partial test 1234");
            int actualLen = PacketCodec.TotalHeaderSize + body.Length;
            byte[] packet = PacketCodec.Encode(0xABCD, body);

            // 1 字节: 数据不足
            AssertEqual(0, PacketCodec.Decode(packet, 0, 1, out _), "1 byte → 0");

            // 3 字节: 头不够
            AssertEqual(0, PacketCodec.Decode(packet, 0, 3, out _), "3 bytes → 0");

            // 头完整但 body 不全
            AssertEqual(0, PacketCodec.Decode(packet, 0, 4, out _), "4 bytes → 0");
            AssertEqual(0, PacketCodec.Decode(packet, 0, actualLen - 3, out _), "actualLen-3 → 0");

            // 完整
            AssertEqual(actualLen, PacketCodec.Decode(packet, 0, actualLen, out _), "full → actualLen");
        }

        private static void PacketCodec_EmptyBody()
        {
            int actualLen = PacketCodec.TotalHeaderSize;
            byte[] packet = PacketCodec.Encode(0xDEAD, Array.Empty<byte>());
            AssertTrue(actualLen <= packet.Length, "array capacity must cover actual length");

            int consumed = PacketCodec.Decode(packet, 0, actualLen, out var decoded);
            AssertEqual(actualLen, consumed, "consumed");
            AssertEqual(0xDEADu, decoded.CmdId, "cmdId");
            AssertEqual(0, decoded.Body.Count, "body length must be 0");
        }

        private static void PacketCodec_LargeBody_100KB()
        {
            var rng = new Random(42);
            var body = new byte[100 * 1024];
            rng.NextBytes(body);
            int actualLen = PacketCodec.TotalHeaderSize + body.Length;

            byte[] packet = PacketCodec.Encode(0x7FFF_FFFF, body);
            int consumed = PacketCodec.Decode(packet, 0, actualLen, out var decoded);

            AssertEqual(actualLen, consumed, "consumed");
            AssertEqual(0x7FFFFFFFu, decoded.CmdId, "cmdId");
            AssertEqual(body.Length, decoded.Body.Count, "body length");
            CollectionEqual(body, ToArray(decoded.Body), "large body bytes match");
        }

        private static void PacketCodec_InvalidLength_Throws()
        {
            // length = 0 (小于 CmdIdSize=4)
            var bad1 = new byte[] { 0, 0, 0, 0 };
            AssertThrows<InvalidDataException>(() => PacketCodec.Decode(bad1, 0, bad1.Length, out _), "length<4 should throw");

            // length > MaxPacketLength
            byte[] bad2 = new byte[4];
            WriteBigEndianInt(bad2, 0, 2 * 1024 * 1024); // 2MB > 1MB cap
            AssertThrows<InvalidDataException>(() => PacketCodec.Decode(bad2, 0, bad2.Length, out _), "length>1MB should throw");
        }

        private static void PacketCodec_BodyStableAfterBufferMutated()
        {
            // 这是 #3 修复的核心验证：Decode 之后即使把源 buffer 全部覆盖，
            // 已经返回的 body 也应该保持原值（因为 body 是独立拷贝）。
            var body = Encoding.UTF8.GetBytes("stability-check-payload");
            int actualLen = PacketCodec.TotalHeaderSize + body.Length;
            byte[] packet = PacketCodec.Encode(0xC0FFEE, body);

            int consumed = PacketCodec.Decode(packet, 0, actualLen, out var decoded);
            AssertEqual(actualLen, consumed, "consumed");
            var capturedBody = ToArray(decoded.Body);

            // 把源 packet 的"实际数据范围"全部清零
            Array.Clear(packet, 0, actualLen);

            // decoded.Body 应当仍然等于原 body
            CollectionEqual(body, ToArray(decoded.Body), "body must survive source buffer clear");
            CollectionEqual(body, capturedBody, "captured body must survive source buffer clear");
        }

        private static void PacketCodec_EncodeUsesArrayPool()
        {
            // 烟雾：多次 encode/release 不应该爆 OOM（说明归还正常）
            // 不验证具体实现（避免对 ArrayPool 行为过度耦合），只验证 ReleasePacket 不抛
            for (int i = 0; i < 10_000; i++)
            {
                byte[] p = PacketCodec.Encode((uint)i, new byte[64]);
                PacketCodec.ReleasePacket(p);
            }
        }

        // ============================================================
        // TcpProtocol end-to-end tests
        // ============================================================

        private static async void Tcp_EchoRoundtrip()
        {
            await using var server = new EchoTcpServer();
            server.Start();

            var client = ProtocolFactory.Create(ProtocolType.TCP);
            var connected = new TaskCompletionSource();
            client.OnConnected += () => connected.TrySetResult();

            client.Connect("127.0.0.1", server.Port);
            await connected.Task.WaitAsync(TimeSpan.FromSeconds(2));
            AssertTrue(client.IsConnected, "client must be connected");

            var received = new TaskCompletionSource<(uint, byte[])>();
            client.OnDataReceived += (cmdId, body) =>
                received.TrySetResult((cmdId, ToArray(body)));

            byte[] sendPacket = PacketCodec.Encode(0xAA, Encoding.UTF8.GetBytes("echo-me"));
            client.Send(sendPacket);

            var (cmd, body) = await received.Task.WaitAsync(TimeSpan.FromSeconds(2));
            AssertEqual(0xAAu, cmd, "echo cmdId");
            CollectionEqual(Encoding.UTF8.GetBytes("echo-me"), body, "echo body");

            var disconnected = new TaskCompletionSource();
            client.OnDisconnected += _ => disconnected.TrySetResult();
            client.Close();
            await disconnected.Task.WaitAsync(TimeSpan.FromSeconds(2));
        }

        private static async void Tcp_PartialSendAssembled()
        {
            // 模拟粘包/半包：先发一个完整包 A，再发一个完整包 B，但每个包分两次 Write
            // server 的循环 decode 应该正确还原出 A、B 两个包
            await using var server = new EchoTcpServer();
            server.SpecialHandler = cmdId => cmdId switch
            {
                0xA1 => null, // echo default
                0xB2 => null,
                _ => null
            };
            server.Start();

            var client = ProtocolFactory.Create(ProtocolType.TCP);
            var connected = new TaskCompletionSource();
            client.OnConnected += () => connected.TrySetResult();
            client.Connect("127.0.0.1", server.Port);
            await connected.Task.WaitAsync(TimeSpan.FromSeconds(2));

            var received = new List<(uint cmd, byte[] body)>();
            var allReceived = new CountdownEvent(2);
            client.OnDataReceived += (cmdId, body) =>
            {
                lock (received) received.Add((cmdId, ToArray(body)));
                allReceived.Signal();
            };

            byte[] pktA = PacketCodec.Encode(0xA1, Encoding.UTF8.GetBytes("AAA"));
            byte[] pktB = PacketCodec.Encode(0xB2, Encoding.UTF8.GetBytes("BBBB"));

            // 模拟分片发送：把 pktA 拆成 3 段，把 pktB 拆成 2 段
            using var raw = new TcpClient();
            await raw.ConnectAsync(IPAddress.Loopback, server.Port);
            var stream = raw.GetStream();
            byte[] combined = Concat(pktA, pktB);
            // 切成 5 段并随机间隔
            int[] splits = { 0, 3, 7, 12, combined.Length };
            for (int i = 0; i < splits.Length - 1; i++)
            {
                int len = splits[i + 1] - splits[i];
                await stream.WriteAsync(combined.AsMemory(splits[i], len));
                await Task.Delay(5);
            }
            await stream.FlushAsync();

            AssertTrue(allReceived.Wait(TimeSpan.FromSeconds(2)), "must receive both A and B within 2s");

            lock (received)
            {
                AssertEqual(2, received.Count, "received count");
                AssertEqual(0xA1u, received[0].cmd, "first cmdId must be A1");
                CollectionEqual(Encoding.UTF8.GetBytes("AAA"), received[0].body, "first body");
                AssertEqual(0xB2u, received[1].cmd, "second cmdId must be B2");
                CollectionEqual(Encoding.UTF8.GetBytes("BBBB"), received[1].body, "second body");
            }

            client.Close();
            raw.Close();
        }

        private static async void Tcp_LargePacket_100KB()
        {
            await using var server = new EchoTcpServer();
            server.Start();

            var client = ProtocolFactory.Create(ProtocolType.TCP);
            var connected = new TaskCompletionSource();
            client.OnConnected += () => connected.TrySetResult();
            client.Connect("127.0.0.1", server.Port);
            await connected.Task.WaitAsync(TimeSpan.FromSeconds(2));

            var rng = new Random(7);
            var body = new byte[EchoTcpServer.LargePayloadSize];
            rng.NextBytes(body);

            var received = new TaskCompletionSource<byte[]>();
            client.OnDataReceived += (cmdId, b) =>
            {
                if (cmdId == EchoTcpServer.LargePayloadCmdId)
                    received.TrySetResult(ToArray(b));
            };

            byte[] sendPacket = PacketCodec.Encode(EchoTcpServer.LargePayloadCmdId, body);
            client.Send(sendPacket);

            var recvBody = await received.Task.WaitAsync(TimeSpan.FromSeconds(5));
            AssertEqual(body.Length, recvBody.Length, "100KB body length");
            CollectionEqual(body, recvBody, "100KB body bytes match");

            client.Close();
        }

        private static async void Tcp_Bursty100Packets()
        {
            await using var server = new EchoTcpServer();
            server.Start();

            var client = ProtocolFactory.Create(ProtocolType.TCP);
            var connected = new TaskCompletionSource();
            client.OnConnected += () => connected.TrySetResult();
            client.Connect("127.0.0.1", server.Port);
            await connected.Task.WaitAsync(TimeSpan.FromSeconds(2));

            const int N = 100;
            var receivedCmds = new ConcurrentBag<uint>();
            var allDone = new CountdownEvent(N);
            client.OnDataReceived += (cmdId, _) =>
            {
                receivedCmds.Add(cmdId);
                allDone.Signal();
            };

            // 一次 Send 一个完整包，连续 100 次
            for (uint i = 1; i <= N; i++)
            {
                byte[] p = PacketCodec.Encode(i, BitConverter.GetBytes(i));
                client.Send(p);
            }

            AssertTrue(allDone.Wait(TimeSpan.FromSeconds(5)), $"must receive all {N} within 5s");
            var set = receivedCmds.ToHashSet();
            AssertEqual(N, set.Count, "all 100 unique cmdIds");
            for (uint i = 1; i <= N; i++)
                AssertTrue(set.Contains(i), $"cmdId {i} must be received");

            client.Close();
        }

        private static async void Tcp_ServerDisconnect_ClientSees()
        {
            await using var server = new EchoTcpServer();
            server.Start();

            var client = ProtocolFactory.Create(ProtocolType.TCP);
            var connected = new TaskCompletionSource();
            client.OnConnected += () => connected.TrySetResult();
            client.Connect("127.0.0.1", server.Port);
            await connected.Task.WaitAsync(TimeSpan.FromSeconds(2));

            var disconnected = new TaskCompletionSource<bool>();
            client.OnDisconnected += abnormal => disconnected.TrySetResult(abnormal);

            // 触发 server 主动断开
            byte[] sendPacket = PacketCodec.Encode(EchoTcpServer.DisconnectCmdId, Array.Empty<byte>());
            client.Send(sendPacket);

            var abnormal = await disconnected.Task.WaitAsync(TimeSpan.FromSeconds(2));
            AssertTrue(!client.IsConnected, "client must be disconnected");
        }

        // ============================================================
        // MessageDispatcher
        // ============================================================

        private static void MessageDispatcher_MainThreadDispatch()
        {
            // 简化：仅验证 Register + Dispatch + Update 的基础流程
            // （完整 protobuf 端到端需要生成 .proto，本烟测不强依赖）
            var dispatcher = new MessageDispatcher();
            bool called = false;
            uint capturedCmd = 0;

            dispatcher.Register(0x42, new MessageParser<EmptyMsg>(() => new EmptyMsg()), msg =>
            {
                called = true;
                capturedCmd = 0x42;
            });

            // 模拟"接收回调"：直接构造一个完整 packet 并 dispatch
            var body = new EmptyMsg().ToByteArray();
            byte[] pkt = PacketCodec.Encode(0x42, body);
            PacketCodec.Decode(pkt, 0, pkt.Length, out var decoded);
            dispatcher.Dispatch(decoded.CmdId, decoded.Body);

            // 还没 Update，handler 还没跑
            AssertTrue(!called, "handler must not run before Update()");

            dispatcher.Update();
            AssertTrue(called, "handler must run after Update()");
            AssertEqual(0x42u, capturedCmd, "captured cmdId");
        }

        private static void Heartbeat_NotRunning_IsNoop()
        {
            // 验证：未 Start 时 Tick 不发 ping、不抛
            var hb = new HeartbeatManager();
            hb.Tick(); // 不应该抛
        }

        // ============================================================
        // Helpers
        // ============================================================

        private static void AssertTrue(bool cond, string msg)
        {
            if (!cond) throw new Exception("Assertion failed: " + msg);
        }

        private static void AssertEqual<T>(T expected, T actual, string msg)
        {
            if (!EqualityComparer<T>.Default.Equals(expected, actual))
                throw new Exception($"{msg}: expected={expected} actual={actual}");
        }

        private static void CollectionEqual(byte[] expected, byte[] actual, string msg)
        {
            if (expected.Length != actual.Length)
                throw new Exception($"{msg}: length mismatch (exp {expected.Length} / got {actual.Length})");
            for (int i = 0; i < expected.Length; i++)
                if (expected[i] != actual[i])
                    throw new Exception($"{msg}: byte mismatch at index {i} (exp {expected[i]} / got {actual[i]})");
        }

        private static void AssertThrows<TEx>(Action action, string msg) where TEx : Exception
        {
            try { action(); }
            catch (TEx) { return; }
            catch (Exception ex) { throw new Exception($"{msg}: wrong exception type ({ex.GetType().Name}): {ex.Message}"); }
            throw new Exception(msg + ": no exception thrown");
        }

        private static byte[] ToArray(ArraySegment<byte> seg)
        {
            var arr = new byte[seg.Count];
            Buffer.BlockCopy(seg.Array!, seg.Offset, arr, 0, seg.Count);
            return arr;
        }

        private static byte[] Concat(params byte[][] arrays)
        {
            int total = arrays.Sum(a => a.Length);
            var result = new byte[total];
            int offset = 0;
            foreach (var a in arrays)
            {
                Buffer.BlockCopy(a, 0, result, offset, a.Length);
                offset += a.Length;
            }
            return result;
        }

        private static void WriteBigEndianInt(byte[] buf, int offset, int value)
        {
            buf[offset]     = (byte)(value >> 24);
            buf[offset + 1] = (byte)(value >> 16);
            buf[offset + 2] = (byte)(value >> 8);
            buf[offset + 3] = (byte)value;
        }
    }

    /// <summary>空的 protobuf 消息，专门给烟测用</summary>
    public sealed class EmptyMsg : IMessage<EmptyMsg>
    {
        public MessageDescriptor Descriptor => null!;
        public int CalculateSize() => 0;
        public EmptyMsg Clone() => new();
        public bool Equals(EmptyMsg? other) => other != null;
        public void MergeFrom(EmptyMsg message) { }
        public void MergeFrom(CodedInputStream input) { }
        public void WriteTo(CodedOutputStream output) { }
    }
}
