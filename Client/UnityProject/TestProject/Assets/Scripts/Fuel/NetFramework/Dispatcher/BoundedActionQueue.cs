// BoundedActionQueue 已移入 MessageDispatcher.cs 作为其 public 嵌套类。
// 保留此文件仅为不破坏 .meta 引用；该类不再在此处定义。
using System;
using System.Collections.Generic;

namespace Fuel.NetFramework.Dispatcher
{
    /// <summary>
    /// 有界 Action 队列。满了丢最旧（背压策略：保护主线程，老消息比新消息更可能已经过期）。
    /// </summary>
    public sealed class BoundedActionQueue
    {
        private readonly Queue<Action> _queue = new Queue<Action>();
        private readonly object _lock = new object();
        private readonly int _capacity;
        private long _droppedCount;

        public BoundedActionQueue(int capacity)
        {
            if (capacity <= 0) throw new ArgumentOutOfRangeException(nameof(capacity), "capacity must be > 0");
            _capacity = capacity;
        }

        public int Capacity => _capacity;

        public int Count
        {
            get { lock (_lock) return _queue.Count; }
        }

        /// <summary>
        /// 从启动以来因为队列满被丢掉的 Action 总数（诊断用）
        /// </summary>
        public long DroppedCount => System.Threading.Interlocked.Read(ref _droppedCount);

        public void Enqueue(Action action)
        {
            if (action == null) return;
            lock (_lock)
            {
                while (_queue.Count >= _capacity)
                {
                    _queue.Dequeue();
                    System.Threading.Interlocked.Increment(ref _droppedCount);
                }
                _queue.Enqueue(action);
            }
        }

        public bool TryDequeue(out Action action)
        {
            lock (_lock)
            {
                if (_queue.Count == 0) { action = null; return false; }
                action = _queue.Dequeue();
                return true;
            }
        }

        public void Clear()
        {
            lock (_lock) _queue.Clear();
        }
    }
}
