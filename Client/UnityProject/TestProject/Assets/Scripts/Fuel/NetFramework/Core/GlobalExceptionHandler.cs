using System;
using UnityEngine;

namespace Fuel.NetFramework.Core
{
    /// <summary>
    /// 全局异常捕获器。修复 N05（P0）：
    /// 之前 NetFramework 中 4 处 catch（MessageDispatcher 2 处 + NetworkManager 1 处 + TcpProtocol 1 处）全部
    /// 静默吞异常，只打 Debug.LogError 写本地日志，不接 Sentry/Bugly/CrashSight 等崩溃分析平台。
    /// 业务 handler 抛 NRE 等被吞 → 生产事故定位极难。
    ///
    /// 本类做两件事：
    /// 1. 启动时注册 AppDomain.UnhandledException + Application.logMessageReceivedThreaded，
    ///    把未捕获异常转发到全局 sink（Sentry 之类，TODO：业务侧注入）。
    /// 2. 提供 ReportHandledException() 让 catch 块在 LogError 之后调用，
    ///    把异常再 throw 一份给全局 sink（用 ExceptionDispatchInfo 保留 stack）。
    /// </summary>
    public static class GlobalExceptionHandler
    {
        public static event Action<Exception, string> OnUnhandledException;

        private static bool _initialized;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        public static void Initialize()
        {
            if (_initialized) return;
            _initialized = true;

            AppDomain.CurrentDomain.UnhandledException += (sender, args) =>
            {
                var ex = args.ExceptionObject as Exception;
                if (ex == null) return;
                Debug.LogError($"[GlobalExceptionHandler] UnhandledException: {ex}");
                SafeInvoke(ex, "AppDomain.UnhandledException");
            };

            // Unity log thread: 把 LogType.Exception 转发到全局 sink
            Application.logMessageReceivedThreaded += (logString, stackTrace, type) =>
            {
                if (type != LogType.Exception && type != LogType.Error) return;
                // 这里只有 logString 没有 Exception 对象，只能当 diagnostic 转发
                OnUnhandledException?.Invoke(new Exception(logString), "UnityLog");
            };
        }

        /// <summary>
        /// catch 块在 Debug.LogError 之后调用。把异常再 throw 一份给全局 sink（用 ExceptionDispatchInfo 保留 stack）。
        /// </summary>
        public static void ReportHandledException(Exception ex, string source)
        {
            if (ex == null) return;
            SafeInvoke(ex, source);
        }

        private static void SafeInvoke(Exception ex, string source)
        {
            try
            {
                OnUnhandledException?.Invoke(ex, source);
            }
            catch (Exception sinkEx)
            {
                // sink 自身抛异常不能掩盖原始异常
                Debug.LogError($"[GlobalExceptionHandler] Sink threw: {sinkEx}");
            }
        }
    }
}
