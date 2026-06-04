using System;

namespace Fuel.Singleton
{
    public abstract class Singleton<T> where T : Singleton<T>, new()
    {
        // volatile 保证多线程下读到最新值，避免 double-check locking 的可见性问题
        private static volatile bool _initialized;
        private static T _instance;
        private readonly static object _lock = new object();
        public static T Instance
        {
            get
            {
                if (!_initialized)
                {
                    lock (_lock)
                    {
                        if (!_initialized)
                        {
                            _instance = new T();
                            _initialized = true;
                            _instance.Init();
                        }
                    }
                }
                return _instance;
            }
            set => _instance = value;
        }

        protected virtual void Init()
        {

        }
    }
}
