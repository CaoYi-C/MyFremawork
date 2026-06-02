using System;
using System.Collections.Generic;
namespace Fuel.Tools
{
    public class TimerManager
    {
        private class TimerTask
        {
            public int Id;

            /// <summary>
            /// 间隔时间
            /// </summary>
            public float Interval;

            /// <summary>
            /// 当前累计时间
            /// </summary>
            public float Elapsed;

            /// <summary>
            /// 回调方法
            /// </summary>
            public Action Callback;

            /// <summary>
            /// 总执行次数，-1 表示无限次
            /// </summary>
            public int RepeatCount;

            /// <summary>
            /// 已执行次数
            /// </summary>
            public int ExecutedCount;

            /// <summary>
            /// 是否已取消
            /// </summary>
            public bool Cancelled;

            /// <summary>
            /// 重置为初始状态以便复用
            /// </summary>
            public void Reset()
            {
                Id = 0;
                Interval = 0f;
                Elapsed = 0f;
                Callback = null;
                RepeatCount = 0;
                ExecutedCount = 0;
                Cancelled = false;
            }
        }

        private readonly Dictionary<int, TimerTask> _timers = new Dictionary<int, TimerTask>();
        private readonly List<int> _removeList = new List<int>();

        // TimerTask 对象池，避免每次 AddTimer 都 new
        private readonly Stack<TimerTask> _taskPool = new Stack<TimerTask>();
        private const int MaxPoolSize = 64;

        private int _timerId = 0;

        // 缓存 Dictionary values 用于遍历，避免 foreach Dictionary 迭代器分配
        private readonly List<TimerTask> _iterationCache = new List<TimerTask>();

        private TimerTask RentTask()
        {
            return _taskPool.Count > 0 ? _taskPool.Pop() : new TimerTask();
        }

        private void ReturnTask(TimerTask task)
        {
            if (_taskPool.Count < MaxPoolSize)
            {
                task.Reset();
                _taskPool.Push(task);
            }
        }

        /// <summary>
        /// 创建一个定时器
        /// </summary>
        /// <param name="callback">回调方法</param>
        /// <param name="interval">间隔时间，单位秒</param>
        /// <param name="repeatCount">
        /// 执行次数：
        /// 1 表示执行一次；
        /// 大于 1 表示执行指定次数；
        /// -1 表示无限执行
        /// </param>
        /// <returns>定时器ID</returns>
        public int AddTimer(Action callback, float interval, int repeatCount = 1)
        {
            if (callback == null)
                throw new ArgumentNullException(nameof(callback));

            if (interval <= 0)
                throw new ArgumentException("interval 必须大于 0");

            if (repeatCount == 0 || repeatCount < -1)
                throw new ArgumentException("repeatCount 必须为 -1 或大于 0");

            int id = ++_timerId;

            TimerTask task = RentTask();
            task.Id = id;
            task.Interval = interval;
            task.Elapsed = 0f;
            task.Callback = callback;
            task.RepeatCount = repeatCount;
            task.ExecutedCount = 0;
            task.Cancelled = false;

            _timers.Add(id, task);

            return id;
        }

        /// <summary>
        /// 延迟多少秒后执行一次
        /// </summary>
        public int Delay(Action callback, float delaySeconds)
        {
            return AddTimer(callback, delaySeconds, 1);
        }

        /// <summary>
        /// 每隔一段时间执行一次
        /// </summary>
        /// <param name="callback">回调</param>
        /// <param name="interval">间隔秒数</param>
        /// <param name="repeatCount">执行次数，-1 表示无限次</param>
        public int Repeat(Action callback, float interval, int repeatCount = -1)
        {
            return AddTimer(callback, interval, repeatCount);
        }

        /// <summary>
        /// 每秒执行一次，无限执行
        /// </summary>
        public int EverySecond(Action callback)
        {
            return Repeat(callback, 1f, -1);
        }

        /// <summary>
        /// 每秒执行一次，执行指定次数
        /// </summary>
        public int EverySecond(Action callback, int repeatCount)
        {
            return Repeat(callback, 1f, repeatCount);
        }

        /// <summary>
        /// 取消指定定时器
        /// </summary>
        public void RemoveTimer(int timerId)
        {
            if (_timers.TryGetValue(timerId, out TimerTask task))
            {
                task.Cancelled = true;
            }
        }

        /// <summary>
        /// 清理所有定时器
        /// </summary>
        public void ClearAll()
        {
            foreach (var pair in _timers)
            {
                ReturnTask(pair.Value);
            }
            _timers.Clear();
            _removeList.Clear();
            _iterationCache.Clear();
        }

        /// <summary>
        /// Update 驱动，所有时间累计都在这里
        /// 使用缓存 List 遍历替代 Dictionary foreach，避免迭代器 GC 分配
        /// </summary>
        /// <param name="deltaTime">每帧间隔时间，单位秒</param>
        public void Update(float deltaTime)
        {
            if (deltaTime <= 0)
                return;

            _removeList.Clear();

            // 将 values 拷贝到缓存 List 中遍历，避免 Dictionary enumerator 分配
            _iterationCache.Clear();
            foreach (var pair in _timers)
            {
                _iterationCache.Add(pair.Value);
            }

            for (int idx = 0; idx < _iterationCache.Count; idx++)
            {
                TimerTask task = _iterationCache[idx];

                if (task.Cancelled)
                {
                    _removeList.Add(task.Id);
                    continue;
                }

                task.Elapsed += deltaTime;

                if (task.Elapsed >= task.Interval)
                {
                    // 防止 deltaTime 过大时丢失周期
                    while (task.Elapsed >= task.Interval)
                    {
                        task.Elapsed -= task.Interval;

                        if (task.Cancelled)
                            break;

                        task.Callback?.Invoke();

                        task.ExecutedCount++;

                        // 非无限次数，并且达到执行次数
                        if (task.RepeatCount != -1 && task.ExecutedCount >= task.RepeatCount)
                        {
                            task.Cancelled = true;
                            break;
                        }
                    }
                }

                if (task.Cancelled)
                {
                    _removeList.Add(task.Id);
                }
            }

            for (int i = 0; i < _removeList.Count; i++)
            {
                int removeId = _removeList[i];
                if (_timers.TryGetValue(removeId, out TimerTask removedTask))
                {
                    _timers.Remove(removeId);
                    ReturnTask(removedTask);
                }
            }
        }
    }
}
