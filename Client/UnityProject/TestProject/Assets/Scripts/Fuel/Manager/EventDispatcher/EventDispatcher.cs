using System;
using System.Collections.Generic;
using Fuel.Singleton;

namespace Fuel.GameEvent
{
    /// <summary>
    /// 事件处理器容器 — 使用 List 管理订阅列表，避免 delegate +=/-= 产生的 GC 分配
    /// 支持在 Invoke 期间安全地 Add/Remove（延迟到 Invoke 结束后生效）
    /// </summary>
    internal class EventHandlerList<T>
    {
        // 预设初始容量，减少热路径上 List.Add 触发扩容 + 数组重新分配
        private const int InitialCapacity = 4;

        private readonly List<Action<T>> _handlers = new List<Action<T>>(InitialCapacity);
        private bool _isInvoking;
        private readonly List<Action<T>> _pendingAdds = new List<Action<T>>(InitialCapacity);
        private readonly List<Action<T>> _pendingRemoves = new List<Action<T>>(InitialCapacity);

        public void Add(Action<T> handler)
        {
            if (_isInvoking)
                _pendingAdds.Add(handler);
            else
                _handlers.Add(handler);
        }

        public void Remove(Action<T> handler)
        {
            if (_isInvoking)
                _pendingRemoves.Add(handler);
            else
                _handlers.Remove(handler);
        }

        public void Invoke(T arg)
        {
            _isInvoking = true;
            try
            {
                for (int i = 0; i < _handlers.Count; i++)
                {
                    _handlers[i]?.Invoke(arg);
                }
            }
            finally
            {
                _isInvoking = false;
                ApplyPending();
            }
        }

        public void Clear()
        {
            _handlers.Clear();
            _pendingAdds.Clear();
            _pendingRemoves.Clear();
            _isInvoking = false;
        }

        public bool HasHandlers => _handlers.Count > 0 || _pendingAdds.Count > 0;

        private void ApplyPending()
        {
            if (_pendingRemoves.Count > 0)
            {
                for (int i = 0; i < _pendingRemoves.Count; i++)
                    _handlers.Remove(_pendingRemoves[i]);
                _pendingRemoves.Clear();
            }

            if (_pendingAdds.Count > 0)
            {
                _handlers.AddRange(_pendingAdds);
                _pendingAdds.Clear();
            }
        }
    }

    /// <summary>
    /// 通用事件分发器
    /// 通过消息类型注册和触发事件，使用纯 Action 实现
    /// </summary>
    public class EventDispatcher : Singleton<EventDispatcher>
    {
        private static int _typeIdCounter;
        private static readonly Dictionary<Type, int> _typeIdMap = new Dictionary<Type, int>();
        private readonly Dictionary<int, object> _events = new Dictionary<int, object>();

        private static int GetTypeId<T>()
        {
            Type type = typeof(T);
            if (!_typeIdMap.TryGetValue(type, out int id))
            {
                id = _typeIdCounter++;
                _typeIdMap[type] = id;
            }
            return id;
        }

        private EventHandlerList<T> GetHandlerList<T>() where T : IEventMessage
        {
            int id = GetTypeId<T>();
            if (!_events.TryGetValue(id, out object obj))
            {
                obj = new EventHandlerList<T>();
                _events[id] = obj;
            }
            return (EventHandlerList<T>)obj;
        }

        #region Register

        public void Register<T>(Action<T> handler) where T : IEventMessage
        {
            GetHandlerList<T>().Add(handler);
        }

        #endregion

        #region Unregister

        public void Unregister<T>(Action<T> handler) where T : IEventMessage
        {
            int id = GetTypeId<T>();
            if (_events.TryGetValue(id, out object obj))
            {
                var list = (EventHandlerList<T>)obj;
                list.Remove(handler);
                if (!list.HasHandlers)
                {
                    _events.Remove(id);
                }
            }
        }

        #endregion

        #region Dispatch

        public void Dispatch<T>(T message) where T : IEventMessage
        {
            if (_events.TryGetValue(GetTypeId<T>(), out object obj))
            {
                ((EventHandlerList<T>)obj).Invoke(message);
            }
        }

        #endregion

        #region Clear

        public void Clear<T>() where T : IEventMessage
        {
            _events.Remove(GetTypeId<T>());
        }

        public void ClearAll()
        {
            _events.Clear();
        }

        #endregion
    }
}
