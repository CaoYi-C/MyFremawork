using System;
using System.Collections;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using Fuel.NetFramework.Codec;
using Fuel.NetFramework.Core;
using Fuel.NetFramework.Dispatcher;
using Fuel.NetFramework.Protocol;
using UnityEngine;
using static Fuel.NetFramework.Tests.LocalEchoServer;
using SocketProtocolType = System.Net.Sockets.ProtocolType;

namespace Fuel.NetFramework.Tests
{
    /// <summary>
    /// 完整 NetworkManager E2E 烟测：起本地 TcpListener，验证 connect/send/recv/重连/heartbeat。
    /// 独立 dotnet 烟测覆盖不到 NetworkManager（依赖 MonoBehaviour），所以走 Unity PlayMode。
    /// 用法：在场景里挂这个组件，进 Play Mode 后右键 "Run All Tests" 或勾选 runOnStart 自动跑。
    /// </summary>
    public class NetworkManagerE2ETest : MonoBehaviour
    {
        [Header("Run Settings")]
        public bool runOnStart = false;
        public bool verboseLog = true;

        [Header("PING/PONG 测试用 cmdId（设为非 0 启用）")]
        public uint pingCmdId = 100;
        public uint pongCmdId = 101;
        public float heartbeatInterval = 0.5f;
        public float heartbeatTimeout = 2f;

        [Header("重连退避（测试用，调快）")]
        public float initialReconnectDelay = 0.5f;

        private readonly List<TestResult> _results = new List<TestResult>();
        private GameObject _nmGo;
        private NetworkManager _nm;

        private class TestResult
        {
            public string Name;
            public bool Passed;
            public string Message;
            public override string ToString() => $"[{(Passed ? "PASS" : "FAIL")}] {Name}{(Passed ? "" : " — " + Message)}";
        }

        // -------- 工具方法 --------

        private IEnumerator WaitFor(Func<bool> predicate, float timeoutSec, string description)
        {
            float t = 0f;
            while (t < timeoutSec)
            {
                if (predicate()) yield break;
                t += Time.unscaledDeltaTime;
                yield return null;
            }
            throw new Exception($"Timed out waiting for: {description} (after {timeoutSec}s)");
        }

        private void Record(string name, bool passed, string message = null)
        {
            var r = new TestResult { Name = name, Passed = passed, Message = message };
            _results.Add(r);
            if (verboseLog) Debug.Log(r.ToString());
        }

        // -------- 测试入口 --------

        [ContextMenu("Run All Tests")]
        public void RunAllMenu() => StartCoroutine(RunAll());

        private void Start()
        {
            if (runOnStart) StartCoroutine(RunAll());
        }

        private IEnumerator RunAll()
        {
            _results.Clear();
            Debug.Log("[E2E] ============ NetFramework E2E Smoke Test START ============");

            // 1. 准备 NetworkManager
            _nmGo = new GameObject("NetTest_NM");
            _nm = _nmGo.AddComponent<NetworkManager>();
            // MonoSingleton.Awake 在 AddComponent 时触发，OnInit 已跑过
            // 重连参数调快（用反射覆盖 private）
            var fldDelay = typeof(NetworkManager).GetField("_reconnectDelay", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
            fldDelay?.SetValue(_nm, initialReconnectDelay);

            // 2. 起本地服务器
            using (var server = new LocalEchoServer { Verbose = verboseLog })
            {
                Debug.Log($"[E2E] Echo server listening on 127.0.0.1:{server.Port}");

                // Test: connect
                yield return TestConnect(server);
                // Test: small msg send/recv
                yield return TestSmallMessage(server);
                // Test: large packet (>64KB, validates growable buffer)
                yield return TestLargeMessage(server);
                // Test: heartbeat PING/PONG
                yield return TestHeartbeat(server);
                // Test: server kill → reconnect after server restart
                yield return TestReconnect(server);
                // Test: invalid host
                yield return TestInvalidHost();
            }

            // 收尾
            if (_nm != null) { try { _nm.Disconnect(); } catch { } }
            if (_nmGo != null) Destroy(_nmGo);

            // 总结
            int pass = 0, fail = 0;
            foreach (var r in _results) if (r.Passed) pass++; else fail++;
            Debug.Log($"[E2E] ============ Result: {pass} passed, {fail} failed ============");
            if (fail > 0)
            {
                foreach (var r in _results) if (!r.Passed) Debug.LogError(r.ToString());
            }
        }

        private IEnumerator TestConnect(LocalEchoServer server)
        {
            bool connected = false;
            _nm.OnConnectSuccess += () => connected = true;
            _nm.Connect("127.0.0.1", server.Port);
            yield return WaitFor(() => connected, 2f, "OnConnectSuccess");
            Record("connect to local echo server", _nm.IsConnected);
        }

        private IEnumerator TestSmallMessage(LocalEchoServer server)
        {
            // 收包用 dispatcher（需要业务侧注册 fake handler；这里用一个无 protobuf 路径）
            // 由于 Register 需要 IMessage<T>，而我们没有 proto 生成代码，
            // 直接用反射或新增无 proto 重载。最简方案：把收到的 body 字节读出来比对。
            // 这里用 "未注册 handler 也能收到原包" 的方式 — 我们用 _nm.Protocol.OnDataReceived 监听。
            var proto = _nm.Protocol;
            var got = new ManualResetEventSlim(false);
            (uint cmdId, ArraySegment<byte> body) recv = (0, default);
            proto.OnDataReceived += (id, b) => { recv = (id, b); got.Set(); };

            byte[] body = new byte[] { 1, 2, 3, 4, 5, 6, 7, 8 };
            byte[] packet = PacketCodec.Encode(200, body);
            proto.Send(packet);

            yield return WaitFor(() => got.IsSet, 2f, "echo back");
            bool ok = recv.cmdId == 200 && recv.body.Count == 8
                && recv.body.Array[recv.body.Offset] == 1
                && recv.body.Array[recv.body.Offset + 7] == 8;
            Record("small message round-trip", ok, ok ? null : $"cmdId={recv.cmdId} body.Count={recv.body.Count}");

            proto.OnDataReceived -= (id, b) => { recv = (id, b); got.Set(); };
        }

        private IEnumerator TestLargeMessage(LocalEchoServer server)
        {
            // 900KB body — 远超 64KB 初始 buffer，验证 growable 生效
            var proto = _nm.Protocol;
            var got = new ManualResetEventSlim(false);
            (uint cmdId, ArraySegment<byte> body) recv = (0, default);
            System.Action<uint, ArraySegment<byte>> handler = (id, b) => { recv = (id, b); got.Set(); };
            proto.OnDataReceived += handler;

            int bodyLen = 900 * 1024;
            byte[] body = new byte[bodyLen];
            var rng = new System.Random(7);
            rng.NextBytes(body);
            body[0] = 0xCA; body[bodyLen - 1] = 0xFE;

            proto.Send(PacketCodec.Encode(201, body));

            yield return WaitFor(() => got.IsSet, 5f, "900KB echo");
            bool ok = recv.cmdId == 201
                && recv.body.Count == bodyLen
                && recv.body.Array[recv.body.Offset] == 0xCA
                && recv.body.Array[recv.body.Offset + bodyLen - 1] == 0xFE;
            Record("900KB packet round-trip (validates growable buffer)", ok,
                ok ? null : $"cmdId={recv.cmdId} count={recv.body.Count}");

            proto.OnDataReceived -= handler;
        }

        private IEnumerator TestHeartbeat(LocalEchoServer server)
        {
            // 改 server 模式：收到 PING 就回 PONG
            server.Mode = LocalEchoServerMode.PingPong;
            server.PingCmdId = pingCmdId;
            server.PongCmdId = pongCmdId;

            _nm.PingCmdId = pingCmdId;
            _nm.PongCmdId = pongCmdId;
            _nm.Heartbeat.Interval = heartbeatInterval;
            _nm.Heartbeat.Timeout = heartbeatTimeout;

            // 重置 heartbeat 状态：之前几个 test 期间 heartbeat 一直在跑（默认 Interval=5s）。
            // Stop 不会解绑 OnSendPing/OnPongReceived 订阅，所以重订阅 PONG 监听即可；
            // _waitingPong/_lastSendTime 由 Stop+Start 重置为初值，避免之前卡住的状态。
            _nm.Heartbeat.Stop();
            long pongDelay = -1;
            _nm.Heartbeat.OnPongReceived -= d => pongDelay = d; // 重复订阅不报错（多次 -= 安全）
            _nm.Heartbeat.OnPongReceived += d => pongDelay = d;
            _nm.Heartbeat.Start();

            // 给 server 线程一帧时间看到 Mode 变更（volatile 写后通常一帧内可见）
            yield return null;

            // 等 PING 发出来 + PONG 回来（多给 3s 缓冲）
            yield return WaitFor(() => pongDelay >= 0, heartbeatTimeout + 3f, "PONG");
            Record("heartbeat PING/PONG", pongDelay >= 0, $"delay={pongDelay}ms");
        }

        private IEnumerator TestReconnect(LocalEchoServer server)
        {
            // 关掉 server 模拟断网。LingerState(true,0) 让 server 端发 RST，
            // 客户端 BeginReceive 抛异常 → TcpProtocol 走 HandleDisconnect(true) →
            // NetworkManager 触发 OnConnectClose(true) 并自动重连
            bool disconnectFired = false;
            System.Action<bool> closeHandler = abn => disconnectFired = true;
            _nm.OnConnectClose += closeHandler;

            int serverPort = server.Port;
            server.Dispose();

            // 等 NetworkManager 触发 OnConnectClose（不论 abnormal 还是 clean 都行）
            yield return WaitFor(() => disconnectFired, 3f, "OnConnectClose on server kill");

            // 启新 server 在**原端口**（SO_REUSEADDR 让我们能立即 bind 回同一端口，
            // 旧连接的 TIME_WAIT 不会阻塞）。NetworkManager 用 _lastHost/_lastPort 重连，
            // port 必须一致。
            LocalEchoServer newServer = null;
            for (int attempt = 1; attempt <= 5; attempt++)
            {
                try
                {
                    newServer = new LocalEchoServer(serverPort) { Verbose = verboseLog };
                    if (newServer.Port != serverPort)
                    {
                        Debug.LogError($"[TestReconnect] newServer bound to {newServer.Port}, expected {serverPort} — wrong port, will fail to reconnect");
                        newServer.Dispose();
                        newServer = null;
                    }
                    else break;
                }
                catch (Exception e)
                {
                    Debug.LogWarning($"[TestReconnect] bind attempt {attempt} failed: {e.Message}");
                    newServer?.Dispose();
                    newServer = null;
                }
            }
            if (newServer == null)
            {
                Record("auto-reconnect on abnormal disconnect + server restart", false, "could not bind new server on same port");
                _nm.OnConnectClose -= closeHandler;
                yield break;
            }

            // 等 NetworkManager 自动重连成功
            bool reconnected = false;
            System.Action onSuccess = () => reconnected = true;
            _nm.OnConnectSuccess += onSuccess;

            yield return WaitFor(() => reconnected, 8f, "auto-reconnect after server restart");
            Record("auto-reconnect on abnormal disconnect + server restart", reconnected);

            _nm.OnConnectSuccess -= onSuccess;
            _nm.OnConnectClose -= closeHandler;
            newServer.Dispose();
        }

        private IEnumerator TestInvalidHost()
        {
            // 先断开当前连接
            _nm.Disconnect();
            yield return new WaitForSeconds(0.1f);

            // 用无效 IP 触发 OnError
            string captured = null;
            System.Action<string> errHandler = msg => captured = msg;
            _nm.OnConnectError += errHandler;

            _nm.Connect("999.999.999.999", 12345);
            yield return WaitFor(() => captured != null, 1f, "OnConnectError");

            bool ok = captured != null && captured.Contains("Invalid endpoint");
            Record("invalid host fires OnError without crash", ok, $"err='{captured}'");

            _nm.OnConnectError -= errHandler;
        }
    }

    /// <summary>
    /// 测试用本地 echo 服务器。
    /// Echo 模式：原样回包。
    /// PingPong 模式：收到 pingCmdId 的包就回 pongCmdId + [clientTs(8B), 0(8B)]。
    /// </summary>
    public sealed class LocalEchoServer : IDisposable
    {
        public enum LocalEchoServerMode { Echo, PingPong }
        // volatile：这些属性由主线程改、由 server 线程读，没有 volatile 的话
        // 主线程的写可能延迟才在 server 线程可见，导致 server 用了旧 Mode 处理新包
        public volatile LocalEchoServerMode Mode = LocalEchoServerMode.Echo;
        public volatile uint PingCmdId;
        public volatile uint PongCmdId;
        public volatile bool Verbose;

        private TcpListener _listener;
        private Thread _thread;
        private TcpClient _client;
        private CancellationTokenSource _cts = new CancellationTokenSource();
        public int Port { get; private set; }

        public LocalEchoServer() : this(0) { }

        /// <summary>
        /// 显式指定端口（重连测试要用同端口重启）。SO_REUSEADDR 让旧连接 TIME_WAIT 期间
        /// 也能立即 bind 回同一个端口。
        /// </summary>
        public LocalEchoServer(int port)
        {
            _listener = new TcpListener(IPAddress.Loopback, port);
            _listener.Server.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReuseAddress, true);
            _listener.Start();
            Port = ((IPEndPoint)_listener.LocalEndpoint).Port;
            _thread = new Thread(Loop) { IsBackground = true, Name = "LocalEchoServer" };
            _thread.Start();
        }

        private void Loop()
        {
            try
            {
                _client = _listener.AcceptTcpClient();
                // 关键：让 client close 时发 RST，模拟服务端异常断开
                // 不然 TcpProtocol 看到的是 bytesRead==0 走 clean disconnect，
                // 不会触发 NetworkManager 的 abnormal→reconnect 流程
                _client.Client.LingerState = new LingerOption(true, 0);
                if (Verbose) Debug.Log($"[LocalEchoServer] Accepted on {Port}");
                var stream = _client.GetStream();
                var pending = new List<byte>();
                byte[] buf = new byte[64 * 1024];

                while (!_cts.IsCancellationRequested)
                {
                    int read;
                    try { read = stream.Read(buf, 0, buf.Length); }
                    catch { break; }
                    if (read == 0) break;
                    for (int i = 0; i < read; i++) pending.Add(buf[i]);

                    int offset = 0;
                    while (offset < pending.Count)
                    {
                        int consumed;
                        Packet packet;
                        try { consumed = PacketCodec.Decode(pending.ToArray(), offset, pending.Count - offset, out packet); }
                        catch { goto done; }
                        if (consumed == 0) break;
                        offset += consumed;

                        byte[] outBody;
                        uint outCmdId;
                        if (Mode == LocalEchoServerMode.PingPong && packet.CmdId == PingCmdId)
                        {
                            outCmdId = PongCmdId;
                            outBody = new byte[16];
                            Buffer.BlockCopy(packet.Body.Array, packet.Body.Offset, outBody, 0, Math.Min(8, packet.Body.Count));
                        }
                        else
                        {
                            outCmdId = packet.CmdId;
                            outBody = new byte[packet.Body.Count];
                            if (packet.Body.Count > 0)
                                Buffer.BlockCopy(packet.Body.Array, packet.Body.Offset, outBody, 0, packet.Body.Count);
                        }

                        try
                        {
                            byte[] encoded = PacketCodec.Encode(outCmdId, outBody);
                            stream.Write(encoded, 0, encoded.Length);
                            stream.Flush();
                        }
                        catch { goto done; }
                    }
                    if (offset > 0) pending.RemoveRange(0, offset);
                }
            done: ;
            }
            catch (Exception e) { Debug.LogWarning($"[LocalEchoServer] Loop ended: {e.Message}"); }
        }

        public void Dispose()
        {
            try { _cts.Cancel(); } catch { }
            if (_client != null)
            {
                // 强制 RST 而不是 FIN：仅设置 LingerState(true,0) 配合 TcpClient.Close()
                // 不一定可靠（不同 .NET 实现里 NetworkStream 的 Dispose 路径可能绕过 linger），
                // 最稳的做法是直接对底层 Socket 调 Close(0) 强制 abort
                try
                {
                    _client.Client.LingerState = new LingerOption(true, 0);
                    _client.Client.Close(0);
                }
                catch { /* swallow */ }
            }
            try { _listener.Stop(); } catch { }
            try { _thread.Join(2000); } catch { }
        }
    }
}
