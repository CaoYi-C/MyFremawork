// Unity shim — 最小可用 stub，覆盖 NetFramework 源码用到的 UnityEngine 类型
// 生产环境是 Unity Editor / Player，本文件仅用于脱离 Unity 的命令行烟测。
using System;
using System.Globalization;

namespace UnityEngine
{
    public static class Debug
    {
        public static void Log(object message) => Console.WriteLine("[LOG] " + message);
        public static void LogWarning(object message) => Console.WriteLine("[WARN] " + message);
        public static void LogError(object message) => Console.Error.WriteLine("[ERR] " + message);
    }

    public static class Time
    {
        // 测试可注入；默认走 Stopwatch
        private static double _nowSeconds = -1;

        public static float realtimeSinceStartup
        {
            get => (float)(_nowSeconds < 0
                ? (System.Diagnostics.Stopwatch.GetTimestamp() / (double)System.Diagnostics.Stopwatch.Frequency)
                : _nowSeconds);
            set => _nowSeconds = value;
        }

        public static float unscaledTime => realtimeSinceStartup;
    }

    public static class Mathf
    {
        public static float Min(float a, float b) => a < b ? a : b;
        public static int   Min(int a,   int b) => a < b ? a : b;
    }
}
