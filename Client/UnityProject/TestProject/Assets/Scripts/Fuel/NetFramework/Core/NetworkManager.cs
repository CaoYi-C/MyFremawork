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
        /// <summary>
        /// 当前使用的协议实例
        /// </summary>
        public IProtocol Protocol { get; private set; }

        /// <summary>
        /// 消息分发器
        /// </summary>
        public MessageDispatcher Dispatcher { get; private set; }

        /// <summary>
        /// 命令获取器
        /// </summary>
        public IProtoCmd CmdGetter { get; private set; }

        /// <summary>
        /// 心跳管理器
        /// </summary>
        public HeartbeatManager Heartbeat { get; private set; }

        /// <summary>
        /// 是否已连接
        /// </summary>
        public bool IsConnected => Protocol != null && Protocol.IsConnected;

        /// <summary>
        /// 连接成功事件
        /// </summary>
        public event Action OnConnectSuccess;

        /// <summary>
        /// 连接断开事件 (参数: 是否异常断开)
        /// </summary>
        public event Action<bool> OnConnectClose;

        /// <summary>
        /// 网络错误事件
        /// </summary>
        public event Action<string> OnConnectError;

        protected override void OnInit()
        {
            Dispatcher = new MessageDispatcher();
            Heartbeat = new HeartbeatManager();
            Heartbeat.OnHeartbeatTimeout += HandleHeartbeatTimeout;
            Heartbeat.OnMaxRetryExceeded += HandleMaxRetryExceeded;
        }
        
        /// <summary>
        /// 设置命令获取器
        /// </summary>
        /// <param name="cmdGetter">命令获取器实例</param>
        public void InitCmdGetter(IProtoCmd cmdGetter)
        {
            CmdGetter = cmdGetter;
            CmdGetter.RegisterAll();
        }
        /// <summary>
        /// 连接到服务器 (默认使用 TCP 协议)
        /// </summary>
        /// <param name="host">服务器地址</param>
        /// <param name="port">服务器端口</param>
        public void Connect(string host, int port)
        {
            Connect(ProtocolType.TCP, host, port);
        }

        /// <summary>
        /// 连接到服务器 (指定协议类型)
        /// </summary>
        /// <param name="protocolType">协议类型</param>
        /// <param name="host">服务器地址</param>
        /// <param name="port">服务器端口</param>
        public void Connect(ProtocolType protocolType, string host, int port)
        {
            if (IsConnected)
            {
                Debug.LogWarning("[NetworkManager] Already connected, disconnect first.");
                return;
            }

            // 清理旧的协议实例
            CleanupProtocol();

            // 创建新的协议实例
            Protocol = ProtocolFactory.Create(protocolType);
            Protocol.OnConnected += HandleConnected;
            Protocol.OnDisconnected += HandleDisconnected;
            Protocol.OnDataReceived += HandleDataReceived;
            Protocol.OnError += HandleError;

            Debug.Log($"[NetworkManager] Connecting to {host}:{port} via {protocolType}...");
            Protocol.Connect(host, port);
        }

        /// <summary>
        /// 发送 Protobuf 消息 (自动从 ProtoCmds 查找 cmdId)
        /// </summary>
        /// <typeparam name="T">消息类型 (必须在 ProtoCmds 中有对应常量)</typeparam>
        /// <param name="msg">Protobuf 消息实例</param>
        public void Send<T>(T msg) where T : IMessage
        {
            uint cmdId = CmdGetter.GetCmdId<T>();
            if (cmdId == 0)
            {
                Debug.LogError($"[NetworkManager] No ProtoCmds entry for type '{typeof(T).Name}', cannot send.");
                return;
            }
            Send(cmdId, msg);
        }

        /// <summary>
        /// 发送 Protobuf 消息 (手动指定 cmdId)
        /// </summary>
        /// <typeparam name="T">消息类型</typeparam>
        /// <param name="cmdId">消息命令号 (ProtoCmds.Xxx)</param>
        /// <param name="msg">Protobuf 消息实例</param>
        public void Send<T>(uint cmdId, T msg) where T : IMessage
        {
            if (!IsConnected)
            {
                Debug.LogWarning("[NetworkManager] Cannot send, not connected.");
                return;
            }

            byte[] body = msg?.ToByteArray();
            byte[] packet = PacketCodec.Encode(cmdId, body);
            Protocol.Send(packet);
        }

        /// <summary>
        /// 发送原始字节数据 (非 Protobuf 场景)
        /// </summary>
        /// <param name="cmdId">消息命令号</param>
        /// <param name="body">原始字节</param>
        public void SendRaw(uint cmdId, byte[] body)
        {
            if (!IsConnected)
            {
                Debug.LogWarning("[NetworkManager] Cannot send, not connected.");
                return;
            }

            byte[] packet = PacketCodec.Encode(cmdId, body);
            Protocol.Send(packet);
        }

        /// <summary>
        /// 断开连接
        /// </summary>
        public void Disconnect()
        {
            if (Protocol == null) return;

            Debug.Log("[NetworkManager] Disconnecting...");
            Protocol.Close();
        }

        /// <summary>
        /// 主线程事件队列 — 连接/断开/错误事件通过此队列转发到主线程
        /// </summary>
        private readonly ConcurrentQueue<Action> _mainThreadEventQueue = new ConcurrentQueue<Action>();

        /// <summary>
        /// 每帧驱动消息分发和心跳，同时处理主线程事件队列
        /// </summary>
        private void Update()
        {
            // 处理连接/断开等事件（从 Socket 线程转发到主线程）
            while (_mainThreadEventQueue.TryDequeue(out Action eventAction))
            {
                try
                {
                    eventAction?.Invoke();
                }
                catch (Exception e)
                {
                    Debug.LogError($"[NetworkManager] Main thread event error: {e}");
                }
            }

            Dispatcher?.Update();
            Heartbeat?.Tick();
        }

        /// <summary>
        /// 应用退出时清理
        /// </summary>
        protected override void OnApplicationQuit()
        {
            base.OnApplicationQuit();
            Heartbeat.Stop();
            Heartbeat.OnHeartbeatTimeout -= HandleHeartbeatTimeout;
            Heartbeat.OnMaxRetryExceeded -= HandleMaxRetryExceeded;
            CleanupProtocol();
            Dispatcher?.Clear();
        }

        #region Protocol Event Handlers

        private void HandleDisconnected(bool isAbnormal)
        {
            _mainThreadEventQueue.Enqueue(() =>
            {
                Debug.Log($"[NetworkManager] Disconnected. Abnormal: {isAbnormal}");
                Heartbeat.Stop();
                OnConnectClose?.Invoke(isAbnormal);
            });
        }

        private void HandleDataReceived(uint cmdId, ArraySegment<byte> body)
        {
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

        /// <summary>
        /// 心跳超时处理（尝试重连）
        /// </summary>
        private void HandleHeartbeatTimeout()
        {
            Debug.LogWarning($"[NetworkManager] Heartbeat timeout, attempting reconnect in {_reconnectDelay:F1}s...");
            TryReconnect();
        }

        /// <summary>
        /// 超过最大重连次数（断开连接）
        /// </summary>
        private void HandleMaxRetryExceeded()
        {
            Debug.LogError("[NetworkManager] Max retry count exceeded, disconnecting...");
            Disconnect();
        }

        // 重连退避：每次重连失败后加倍延迟（指数退避），到达上限后保持上限
        private float _reconnectDelay = 1f;
        private float _reconnectDeadline;   // 下一次允许重连的 Unity 时间
        private const float InitialReconnectDelay = 1f;
        private const float MaxReconnectDelay = 30f;
        private ProtocolType _lastProtocolType;
        private string _lastHost;
        private int _lastPort;

        /// <summary>
        /// 尝试重连（子类可重写自定义重连逻辑）。
        /// 旧实现是"断开后立即重连"，服务端挂掉时会以最高频反复重连。
        /// 新实现按指数退避延迟：1s → 2s → 4s → 8s → 16s → 30s (上限)。
        /// </summary>
        protected virtual void TryReconnect()
        {
            if (Protocol != null)
            {
                _lastProtocolType = Protocol.Type;
                _lastHost = Protocol.Host;
                _lastPort = Protocol.Port;
                Protocol.Close();
            }
            else if (_lastHost == null)
            {
                return; // 没有可重连的目标
            }

            if (Time.unscaledTime < _reconnectDeadline)
                return; // 退避窗口未到，等待下一帧

            Debug.Log($"[NetworkManager] Reconnecting to {_lastHost}:{_lastPort} (delay was {_reconnectDelay:F1}s)");
            Connect(_lastProtocolType, _lastHost, _lastPort);
            _reconnectDeadline = Time.unscaledTime + _reconnectDelay;
            _reconnectDelay = Mathf.Min(_reconnectDelay * 2f, MaxReconnectDelay);
        }

        /// <summary>
        /// 连接成功时重置退避状态
        /// </summary>
        private void HandleConnected()
        {
            _reconnectDelay = InitialReconnectDelay;
            _reconnectDeadline = 0f;
            _mainThreadEventQueue.Enqueue(() =>
            {
                Debug.Log("[NetworkManager] Connected.");
                Heartbeat.Start();
                Heartbeat.ResetRetryCount();
                OnConnectSuccess?.Invoke();
            });
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
