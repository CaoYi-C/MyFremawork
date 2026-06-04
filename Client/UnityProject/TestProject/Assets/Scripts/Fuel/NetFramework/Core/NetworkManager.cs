using System;
using System.Collections.Concurrent;
using Google.Protobuf;
using Fuel.NetFramework.Codec;
using Fuel.NetFramework.Dispatcher;
using Fuel.NetFramework.Protocol;
using Fuel.Singleton;
using UnityEngine;

namespace Fuel.NetFramework.Core
{
    /// <summary>
    /// 网络管理器 (MonoBehaviour 单例)
    /// 对外统一入口: Connect / Send / Disconnect
    /// 管理协议层和消息分发器的生命周期
    /// </summary>
    public class NetworkManager : MonoSingleton<NetworkManager>
    {
        // ---- 对外只读状态 ----
        public IProtocol Protocol { get; private set; }
        public MessageDispatcher Dispatcher { get; private set; }
        public IProtoCmd CmdGetter { get; private set; }
        public HeartbeatManager Heartbeat { get; private set; }

        public bool IsConnected => Protocol != null && Protocol.IsConnected;

        // ---- 业务事件 ----
        public event Action OnConnectSuccess;
        public event Action<bool> OnConnectClose;        // bool: 是否异常断开
        public event Action<string> OnConnectError;

        // ---- 心跳 PING/PONG 协议 ----
        /// <summary>
        /// PING 命令号。设为 0 关闭自动心跳。
        /// PING body: 8 字节 big-endian long，客户端时间戳。
        /// </summary>
        public uint PingCmdId { get; set; }

        /// <summary>
        /// PONG 命令号。设为 0 关闭自动收 PONG。
        /// PONG body: 16 字节 big-endian long[2] = [clientTimestamp, serverTimestamp]。
        /// </summary>
        public uint PongCmdId { get; set; }

        /// <summary>
        /// 自动重连开关（默认 true）。关闭后异常断开时只发事件，不尝试重连。
        /// </summary>
        public bool AutoReconnect { get; set; } = true;

        // ---- 重连退避参数 ----
        private const float InitialReconnectDelay = 1f;
        private const float MaxReconnectDelay = 30f;

        private float _reconnectDelay = InitialReconnectDelay;
        private float _reconnectDeadline;     // 下一次允许重连的 Unity 时间（unscaledTime）
        private int _reconnectAttempts;       // 用于：首次立即重连，后续走退避
        private ProtocolType _lastProtocolType;
        private string _lastHost;
        private int _lastPort;

        // ---- 主线程事件队列 ----
        private readonly ConcurrentQueue<Action> _mainThreadEventQueue = new ConcurrentQueue<Action>();

        protected override void OnInit()
        {
            Dispatcher = new MessageDispatcher();
            Heartbeat = new HeartbeatManager();
            Heartbeat.OnHeartbeatTimeout += HandleHeartbeatTimeout;
            Heartbeat.OnMaxRetryExceeded += HandleMaxRetryExceeded;
            // OnSendPing 在 OnConnected 后 subscribe；这里集中处理，OnConnected 内统一 subscribe/unsubscribe
        }

        /// <summary>
        /// 设置命令获取器（业务侧实现 IProtoCmd 时调用一次；不调则回退到 ProtoCmdsLookup 反射）
        /// </summary>
        public void InitCmdGetter(IProtoCmd cmdGetter)
        {
            CmdGetter = cmdGetter;
            CmdGetter.RegisterAll();
        }

        #region Connect / Disconnect

        public void Connect(string host, int port)
        {
            Connect(ProtocolType.TCP, host, port);
        }

        public void Connect(ProtocolType protocolType, string host, int port)
        {
            if (IsConnected)
            {
                Debug.LogWarning("[NetworkManager] Already connected, disconnect first.");
                return;
            }

            // 1. 清理旧实例
            CleanupProtocol();

            // 2. 重置重连状态：手动 Connect 视为新目标，旧 _lastHost / _reconnectDelay 全部作废
            _lastProtocolType = protocolType;
            _lastHost = host;
            _lastPort = port;
            _reconnectDelay = InitialReconnectDelay;
            _reconnectDeadline = 0f;
            _reconnectAttempts = 0;

            // 3. 建新协议
            Protocol = ProtocolFactory.Create(protocolType);
            Protocol.OnConnected += HandleConnected;
            Protocol.OnDisconnected += HandleDisconnected;
            Protocol.OnDataReceived += HandleDataReceived;
            Protocol.OnError += HandleError;

            Debug.Log($"[NetworkManager] Connecting to {host}:{port} via {protocolType}...");
            Protocol.Connect(host, port);
        }

        public void Disconnect()
        {
            if (Protocol == null) return;

            // 主动断开 — 关掉自动重连，避免 HandleDisconnected 触发自动重连
            _reconnectAttempts = 0;
            _lastHost = null;

            Debug.Log("[NetworkManager] Disconnecting...");
            Protocol.Close();
        }

        #endregion

        #region Send

        public bool Send<T>(T msg) where T : IMessage
        {
            if (CmdGetter == null)
            {
                Debug.LogError("[NetworkManager] CmdGetter is null. Call InitCmdGetter or wire ProtoCmdsLookup. Cannot send.");
                return false;
            }
            uint cmdId = CmdGetter.GetCmdId<T>();
            if (cmdId == 0)
            {
                Debug.LogError($"[NetworkManager] No ProtoCmds entry for type '{typeof(T).Name}', cannot send.");
                return false;
            }

            // Req-Rsp 模式：在发包前缓存 request，响应包到达时 dispatcher 会取出并和 rsp 一起 invoke
            if (Dispatcher != null && Dispatcher.IsRequestResponseHandler(cmdId))
            {
                Dispatcher.CacheRequest(cmdId, msg);
            }

            return Send(cmdId, msg);
        }

        private bool Send<T>(uint cmdId, T msg) where T : IMessage
        {
            if (!IsConnected) { Debug.LogWarning("[NetworkManager] Cannot send, not connected."); return false; }
            if (Protocol == null) { Debug.LogWarning("[NetworkManager] Cannot send, no protocol instance."); return false; }

            byte[] body = msg?.ToByteArray();
            byte[] packet = PacketCodec.Encode(cmdId, body);
            Protocol.Send(packet);
            return true;
        }

        public bool SendRaw(uint cmdId, byte[] body)
        {
            if (!IsConnected) { Debug.LogWarning("[NetworkManager] Cannot send, not connected."); return false; }
            if (Protocol == null) { Debug.LogWarning("[NetworkManager] Cannot send, no protocol instance."); return false; }

            byte[] packet = PacketCodec.Encode(cmdId, body);
            Protocol.Send(packet);
            return true;
        }

        #endregion

        #region Update / Lifecycle

        private void Update()
        {
            // 处理连接/断开/错误事件（从 Socket 线程转发到主线程）
            while (_mainThreadEventQueue.TryDequeue(out Action eventAction))
            {
                try { eventAction?.Invoke(); }
                catch (Exception e) { Debug.LogError($"[NetworkManager] Main thread event error: {e}"); }
            }

            Dispatcher?.Update();
            Heartbeat?.Tick();

            // 驱动重连退避：把"重连何时尝试"从事件 handler 移到这里，
            // 避免 _isReconnecting 卡死后永远不再尝试（之前的 bug）
            DriveReconnect();
        }

        protected override void OnApplicationQuit()
        {
            base.OnApplicationQuit();
            Heartbeat.Stop();
            Heartbeat.OnHeartbeatTimeout -= HandleHeartbeatTimeout;
            Heartbeat.OnMaxRetryExceeded -= HandleMaxRetryExceeded;
            Heartbeat.OnSendPing -= SendPingInternal;
            CleanupProtocol();
            Dispatcher?.Clear();
        }

        #endregion

        #region Protocol Event Handlers

        private void HandleConnected()
        {
            _reconnectDelay = InitialReconnectDelay;
            _reconnectDeadline = 0f;
            _reconnectAttempts = 0;

            _mainThreadEventQueue.Enqueue(() =>
            {
                Debug.Log("[NetworkManager] Connected.");
                Heartbeat.OnSendPing += SendPingInternal;
                Heartbeat.Start();
                Heartbeat.ResetRetryCount();
                OnConnectSuccess?.Invoke();
            });
        }

        private void HandleDisconnected(bool isAbnormal)
        {
            // 总是先解订阅 PING，避免 Stop 后还有 PING 在飞
            Heartbeat.OnSendPing -= SendPingInternal;

            _mainThreadEventQueue.Enqueue(() =>
            {
                Debug.Log($"[NetworkManager] Disconnected. Abnormal: {isAbnormal}");
                Heartbeat.Stop();

                // 清掉所有 pending request，避免旧连接的 req 在重连后被新响应用错
                // （或者更糟：永远等不到响应，handler 不被触发，request 永远占着缓存）
                Dispatcher?.ClearPendingRequests();

                OnConnectClose?.Invoke(isAbnormal);

                // 异常断开 + 启用自动重连 + 目标存在 → 设置 _reconnectAttempts 让 Update 驱动重连
                // 首次 _reconnectAttempts=1，deadline 设为 now（立即）；后续 attempt 走退避
                if (isAbnormal && AutoReconnect && _lastHost != null)
                {
                    _reconnectAttempts++;
                    float delay = (_reconnectAttempts == 1) ? 0f : _reconnectDelay;
                    _reconnectDeadline = Time.unscaledTime + delay;
                    _reconnectDelay = Mathf.Min(_reconnectDelay * 2f, MaxReconnectDelay);
                }
            });
        }

        private void HandleDataReceived(uint cmdId, ArraySegment<byte> body)
        {
            // 在 Socket 线程执行；Dispatcher 内部会把 handler 推到主线程
            if (PongCmdId != 0 && cmdId == PongCmdId && body.Count >= 16)
            {
                long clientTime = PacketCodec.ReadInt64BigEndian(body.Array, body.Offset);
                long serverTime = PacketCodec.ReadInt64BigEndian(body.Array, body.Offset + 8);
                _mainThreadEventQueue.Enqueue(() => Heartbeat.HandlePong(clientTime, serverTime));
                return;
            }

            Dispatcher.Dispatch(cmdId, body);
        }

        private void HandleError(string errorMsg)
        {
            _mainThreadEventQueue.Enqueue(() =>
            {
                Debug.LogError($"[NetworkManager] Error: {errorMsg}");
                OnConnectError?.Invoke(errorMsg);
            });
        }

        #endregion

        #region Heartbeat

        private void HandleHeartbeatTimeout()
        {
            Debug.LogWarning($"[NetworkManager] Heartbeat timeout, attempting reconnect in {_reconnectDelay:F1}s...");
            TryReconnect();
        }

        private void HandleMaxRetryExceeded()
        {
            Debug.LogError("[NetworkManager] Max retry count exceeded, disconnecting.");
            Disconnect();
        }

        /// <summary>
        /// Heartbeat 触发 PING 时回调。把 8 字节时间戳打成 body 并发送。
        /// </summary>
        private void SendPingInternal(long clientTimestamp)
        {
            if (!IsConnected || PingCmdId == 0) return;
            byte[] body = new byte[8];
            PacketCodec.WriteInt64BigEndian(body, 0, clientTimestamp);
            SendRaw(PingCmdId, body);
        }

        #endregion

        #region Reconnect

        /// <summary>
        /// 由 Update 每帧调用，检查是否到了重连时间点。
        /// 关键：判断"已连接"要看 Protocol.IsConnected，不能看 Protocol != null。
        /// 断开时 Protocol 引用还在（旧 TcpProtocol 仍被 NetworkManager.Protocol 持有，
        /// socket 已经在 HandleDisconnect 里置 null），所以 != null 永远是 true，
        /// 会把 DriveReconnect 永远卡住、永远不调 TryReconnect。
        /// </summary>
        private void DriveReconnect()
        {
            if (!AutoReconnect || _lastHost == null) return;
            if (_reconnectAttempts == 0) return;          // 没有待执行的重连
            if (Protocol != null && Protocol.IsConnected) return; // 已连接
            if (Time.unscaledTime < _reconnectDeadline) return;   // 退避未到

            TryReconnect();
        }

        /// <summary>
        /// 实际发起一次重连（不检查退避，由 DriveReconnect 负责调度）。
        /// </summary>
        protected virtual void TryReconnect()
        {
            // 暂停心跳，避免重连窗口里继续发 PING 失败刷屏
            if (Heartbeat != null) Heartbeat.Paused = true;

            // 关闭旧协议（如果还活着）
            if (Protocol != null)
            {
                Protocol.OnConnected -= HandleConnected;
                Protocol.OnDisconnected -= HandleDisconnected;
                Protocol.OnDataReceived -= HandleDataReceived;
                Protocol.OnError -= HandleError;
                try { Protocol.Close(); } catch { /* swallow */ }
                Protocol = null;
            }

            Debug.Log($"[NetworkManager] Reconnect attempt {_reconnectAttempts} to {_lastHost}:{_lastPort}");

            Protocol = ProtocolFactory.Create(_lastProtocolType);
            Protocol.OnConnected += HandleConnected;
            Protocol.OnDisconnected += HandleDisconnected;
            Protocol.OnDataReceived += HandleDataReceived;
            Protocol.OnError += HandleError;
            Protocol.Connect(_lastHost, _lastPort);
        }

        #endregion

        #region Cleanup

        private void CleanupProtocol()
        {
            if (Protocol == null) return;

            Protocol.OnConnected -= HandleConnected;
            Protocol.OnDisconnected -= HandleDisconnected;
            Protocol.OnDataReceived -= HandleDataReceived;
            Protocol.OnError -= HandleError;

            if (Protocol.IsConnected)
            {
                Protocol.Close();
            }

            Protocol = null;
        }

        #endregion
    }
}
