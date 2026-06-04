using UnityEngine;

namespace Fuel.Log
{
    public static class DebugLogger
    {
        public static bool Enable { get; set; } = true;

        public static void Log(LogWriter writer, object message)
        {
            if (!Enable) return;
            Debug.Log(FormatMessage(writer, message));
        }

        public static void LogWarning(LogWriter writer, object message)
        {
            if (!Enable) return;
            Debug.LogWarning(FormatMessage(writer, message));
        }

        public static void LogError(LogWriter writer, object message)
        {
            if (!Enable) return;
            Debug.LogError(FormatMessage(writer, message));
        }

        public static void Log(object message)
        {
            if (!Enable) return;
            Debug.Log(FormatMessage(LogWriter.Default, message));
        }

        public static void LogWarning(object message)
        {
            if (!Enable) return;
            Debug.LogWarning(FormatMessage(LogWriter.Default, message));
        }

        public static void LogError(object message)
        {
            if (!Enable) return;
            Debug.LogError(FormatMessage(LogWriter.Default, message));
        }

        public static void Log(LogWriter writer, string message, params object[] args)
        {
            if (!Enable) return;
            Debug.Log(FormatMessage(writer, message, args));
        }

        public static void LogWarning(LogWriter writer, string message, params object[] args)
        {
            if (!Enable) return;
            Debug.LogWarning(FormatMessage(writer, message, args));
        }

        public static void LogError(LogWriter writer, string message, params object[] args)
        {
            if (!Enable) return;
            Debug.LogError(FormatMessage(writer, message, args));
        }

        public static void Log(string message, params object[] args)
        {
            if (!Enable) return;
            Debug.Log(FormatMessage(LogWriter.Default, message, args));
        }

        public static void LogWarning(string message, params object[] args)
        {
            if (!Enable) return;
            Debug.LogWarning(FormatMessage(LogWriter.Default, message, args));
        }

        public static void LogError(string message, params object[] args)
        {
            if (!Enable) return;
            Debug.LogError(FormatMessage(LogWriter.Default, message, args));
        }

        // ============================================================
        // 热路径友好重载（不通过 params object[]，避免 args 数组分配）
        // 修 #30：旧版 Log("foo {0} {1}", a, b) 即使 Enable=false 也会分配 new object[] { a, b }
        //         并装箱 a/b。多重重载让 caller 在 Enable=false 时连参数都不必求值/装箱。
        // 用法：DebugLogger.Log("foo {0}", value);    ← 旧，仍分配 args
        //       DebugLogger.Log("foo " + value);      ← 零分配（值类型 ToString + string concat）
        //       DebugLogger.LogIf(condition, "foo " + value); ← 零分配 + 短路
        // ============================================================

        public static void LogIf(bool condition, string message)
        {
            if (!condition || !Enable) return;
            Debug.Log(FormatMessage(LogWriter.Default, (object)message));
        }

        public static void LogWarningIf(bool condition, string message)
        {
            if (!condition || !Enable) return;
            Debug.LogWarning(FormatMessage(LogWriter.Default, (object)message));
        }

        public static void LogErrorIf(bool condition, string message)
        {
            if (!condition || !Enable) return;
            Debug.LogError(FormatMessage(LogWriter.Default, (object)message));
        }

        public static string Color(object message, string color)
        {
            return $"<color={color}>{message}</color>";
        }

        public static string Bold(object message)
        {
            return $"<b>{message}</b>";
        }

        public static string Italic(object message)
        {
            return $"<i>{message}</i>";
        }

        private static string FormatMessage(LogWriter writer, string message, params object[] args)
        {
            var formatted = args == null || args.Length == 0 ? message : string.Format(message, args);
            return FormatMessage(writer, (object)formatted);
        }
        private static string FormatMessage(LogWriter writer, object message)
        {
            return writer == LogWriter.Default ? message?.ToString() : $"[{writer}] {message}";
        }
    }
    public enum LogWriter
    {
        Default,
        SceneManager,
        ResourceManager,
    }
}
