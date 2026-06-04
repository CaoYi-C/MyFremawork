using System;
using System.Collections.Generic;
using Google.Protobuf;
using UnityEngine;

namespace Fuel.NetFramework.Dispatcher
{
    /// <summary>
    /// 消息分发器
    /// 负责注册消息处理器，并在收到消息时分发到对应处理器
    /// 通过主线程队列确保 handler 在 Unity 主线程执行
    /// </summary>
    public class MessageDispatcher
    {
        /// <summary>
        /// 消息处理器：收到一个完整包后被调用（cmdId 用于日志/分发，body 是解码后的 protobuf 字节）
        /// </summary>
        private delegate void MessageHandler(uint cmdId, ArraySegment<byte> body);

        private readonly Dictionary<uint, MessageHandler> _handlers = new Dictionary<uint, MessageHandler>();

        // ---- Request-Response 缓存 ----
        // 哪些 cmdId 是 Req-Rsp 模式（双参数 handler）
        private readonly HashSet<uint> _reqRspCmdIds = new HashSet<uint>();
        // 等待响应的 request（cmdId → 队列）。TCP 保序，所以同一 cmdId 的多个 in-flight
        // request 按 FIFO 匹配响应；UDP/KCP 等无序协议需要在 TReq 内部带 requestId 自己匹配
        private readonly Dictionary<uint, Queue<IMessage>> _pendingRequests = new Dictionary<uint, Queue<IMessage>>();
        private readonly object _pendingLock = new object();

        /// <summary>
        /// 每个 cmdId 最多缓存多少个待响应 request。超过后新的 Send 不缓存（响应会带 default(TReq)），
        /// 防止服务器卡死时把内存吃光。默认 100，业务侧可以调大调小。
        /// </summary>
        public int MaxPendingRequestsPerCmdId { get; set; } = 100;

        private BoundedActionQueue _mainThreadQueue;

        /// <summary>
        /// 主线程派发队列容量上限。超出后丢最旧的（背压策略：保护主线程不卡死，
        /// 同时丢老消息比丢新消息更可接受，老消息更可能已经过期）。
        /// </summary>
        public int MaxQueueLength
        {
            get => _mainThreadQueue.Capacity;
            set => _mainThreadQueue = new BoundedActionQueue(value);
        }

        public MessageDispatcher() : this(1000) { }

        public MessageDispatcher(int maxQueueLength)
        {
            _mainThreadQueue = new BoundedActionQueue(maxQueueLength);
        }

        public int QueueLength => _mainThreadQueue.Count;
        public long DroppedCount => _mainThreadQueue.DroppedCount;

        #region Register

        /// <summary>
        /// 注册消息处理器（用于 Push 消息或响应，无原 request 上下文）
        /// 使用 MessageParser 直接反序列化，避免先 new 再 MergeFrom 的两步分配
        /// </summary>
        public void Register<TResp>(uint cmdId, Action<TResp> handler) where TResp : IMessage<TResp>, new()
        {
            if (_handlers.ContainsKey(cmdId))
            {
                Debug.LogWarning($"[MessageDispatcher] Handler for cmd {cmdId} already registered, overwriting.");
            }

            lock (_pendingLock)
            {
                _reqRspCmdIds.Remove(cmdId);
                _pendingRequests.Remove(cmdId); // 从 Req-Rsp 改回单参时清掉旧缓存
            }

            var parser = new MessageParser<TResp>(() => new TResp());
            _handlers[cmdId] = (id, body) =>
            {
                TResp msg = parser.ParseFrom(body.Array, body.Offset, body.Count);
                handler?.Invoke(msg);
            };
        }

        /// <summary>
        /// 注册消息处理器（无泛型约束版本，使用显式 MessageParser）
        /// </summary>
        public void Register(uint cmdId, MessageParser respParser, Action<IMessage> handler)
        {
            if (_handlers.ContainsKey(cmdId))
            {
                Debug.LogWarning($"[MessageDispatcher] Handler for cmd {cmdId} already registered, overwriting.");
            }

            lock (_pendingLock)
            {
                _reqRspCmdIds.Remove(cmdId);
                _pendingRequests.Remove(cmdId);
            }

            _handlers[cmdId] = (id, body) =>
            {
                IMessage msg = respParser.ParseFrom(body.Array, body.Offset, body.Count);
                handler?.Invoke(msg);
            };
        }

        /// <summary>
        /// 注册 Request-Response 处理器。收到响应包时，会从 FIFO 队列里取出最早入队的 request
        /// （由 NetworkManager.Send 在发包前缓存），handler 收到 (req, rsp) 两个参数。
        /// 同一 cmdId 多次 Send 会按发送顺序排队匹配（依赖 TCP 保序）。
        /// UDP/KCP 等无序协议需在 TReq 内部带 requestId 自己做匹配。
        /// </summary>
        public void Register<TReq, TRsp>(uint cmdId, Action<TReq, TRsp> handler)
            where TReq : IMessage<TReq>, new()
            where TRsp : IMessage<TRsp>, new()
        {
            if (_handlers.ContainsKey(cmdId))
            {
                Debug.LogWarning($"[MessageDispatcher] Handler for cmd {cmdId} already registered, overwriting.");
            }

            lock (_pendingLock)
            {
                _reqRspCmdIds.Add(cmdId);
                _pendingRequests.Remove(cmdId); // 清掉旧缓存（如果有）
            }

            var rspParser = new MessageParser<TRsp>(() => new TRsp());
            _handlers[cmdId] = (id, body) =>
            {
                TRsp rsp = rspParser.ParseFrom(body.Array, body.Offset, body.Count);

                TReq req = default;
                IMessage reqMsg;
                if (TryGetAndRemoveRequest(cmdId, out reqMsg))
                {
                    if (reqMsg is TReq typed)
                    {
                        req = typed;
                    }
                    else
                    {
                        Debug.LogWarning($"[MessageDispatcher] Cached request for cmd {cmdId} is {reqMsg.GetType().Name}, expected {typeof(TReq).Name}");
                    }
                }
                else
                {
                    Debug.LogWarning($"[MessageDispatcher] Req-Rsp handler for cmd {cmdId} but no cached request (out-of-order, dropped, or none sent) — invoking with default(TReq).");
                }

                handler?.Invoke(req, rsp);
            };
        }

        #endregion

        #region Request Cache (public API for NetworkManager.Send)

        /// <summary>
        /// 是否为 Request-Response 类型的 cmdId（决定 Send 时是否缓存）
        /// </summary>
        public bool IsRequestResponseHandler(uint cmdId)
        {
            lock (_pendingLock) return _reqRspCmdIds.Contains(cmdId);
        }

        /// <summary>
        /// 缓存一个 request（FIFO 入队），等对应 cmdId 的响应包到达时按发送顺序回传给 handler。
        /// 同一 cmdId 多次 Send 会按顺序排队；TCP 保序的场景下保证匹配正确。
        /// 超过 <see cref="MaxPendingRequestsPerCmdId"/> 时丢最旧（FIFO 满则 dequeue 队首再入队），
        /// 防止服务器卡死时 OOM。
        /// </summary>
        public void CacheRequest(uint cmdId, IMessage request)
        {
            if (request == null) return;
            lock (_pendingLock)
            {
                if (!_pendingRequests.TryGetValue(cmdId, out var q))
                {
                    q = new Queue<IMessage>();
                    _pendingRequests[cmdId] = q;
                }
                if (q.Count >= MaxPendingRequestsPerCmdId)
                {
                    Debug.LogWarning($"[MessageDispatcher] Pending request queue for cmd {cmdId} full ({MaxPendingRequestsPerCmdId}), dropping oldest. Server may be too slow to keep up.");
                    q.Dequeue();
                }
                q.Enqueue(request);
            }
        }

        /// <summary>
        /// 取出并移除最早入队的 request（dispatcher 内部用）
        /// </summary>
        public bool TryGetAndRemoveRequest(uint cmdId, out IMessage request)
        {
            lock (_pendingLock)
            {
                if (_pendingRequests.TryGetValue(cmdId, out var q) && q.Count > 0)
                {
                    request = q.Dequeue();
                    if (q.Count == 0) _pendingRequests.Remove(cmdId); // 空队列清理，节省内存
                    return true;
                }
                request = null;
                return false;
            }
        }

        /// <summary>
        /// 当前待响应总数（所有 cmdId 累加，诊断用）
        /// </summary>
        public int PendingRequestCount
        {
            get
            {
                lock (_pendingLock)
                {
                    int total = 0;
                    foreach (var q in _pendingRequests.Values) total += q.Count;
                    return total;
                }
            }
        }

        /// <summary>
        /// 清空所有待响应 request（断线/重置时调用，避免旧连接 req 串到新连接）
        /// </summary>
        public void ClearPendingRequests()
        {
            lock (_pendingLock) _pendingRequests.Clear();
        }

        #endregion

        #region Dispatch

        /// <summary>
        /// 分发收到的消息到主线程队列（在 Socket 线程调用是安全的：内部加锁）
        /// </summary>
        public void Dispatch(uint cmdId, ArraySegment<byte> body)
        {
            if (!_handlers.TryGetValue(cmdId, out MessageHandler handler))
            {
                Debug.LogWarning($"[MessageDispatcher] No handler registered for cmd {cmdId}.");
                return;
            }

            EnqueueMainThread(() =>
            {
                try
                {
                    handler.Invoke(cmdId, body);
                }
                catch (Exception e)
                {
                    Debug.LogError($"[MessageDispatcher] Handler error for cmd {cmdId}: {e}");
                }
            });
        }

        private void EnqueueMainThread(Action action)
        {
            _mainThreadQueue.Enqueue(action);
        }

        /// <summary>
        /// 在主线程 Update 中调用，处理所有排队的消息
        /// </summary>
        public void Update()
        {
            // 每帧最多处理 100 条消息，避免卡顿
            int processed = 0;
            while (processed < 100 && _mainThreadQueue.TryDequeue(out Action action))
            {
                try
                {
                    action?.Invoke();
                }
                catch (Exception e)
                {
                    Debug.LogError($"[MessageDispatcher] Action error: {e}");
                }
                processed++;
            }
        }

        #endregion

        #region Unregister

        public bool Unregister(uint cmdId)
        {
            lock (_pendingLock)
            {
                _reqRspCmdIds.Remove(cmdId);
                _pendingRequests.Remove(cmdId);
            }
            return _handlers.Remove(cmdId);
        }

        public void Clear()
        {
            _handlers.Clear();
            lock (_pendingLock)
            {
                _reqRspCmdIds.Clear();
                _pendingRequests.Clear();
            }
            _mainThreadQueue.Clear();
        }

        #endregion
    }
}
