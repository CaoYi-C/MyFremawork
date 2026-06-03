// UnityEngine.Debug / Time 的最小桩，给非 Unity 烟测用。
// 真实生产代码里的 UnityEngine.Debug.Log/LogError/LogWarning 会被桩替换。
using System;
using System.Collections.Generic;

namespace UnityEngine
{
    public static class Debug
    {
        public static void Log(object message) => Console.WriteLine($"[LOG] {message}");
        public static void LogWarning(object message) => Console.WriteLine($"[WARN] {message}");
        public static void LogError(object message) => Console.Error.WriteLine($"[ERR] {message}");
    }

    public static class Time
    {
        public static Func<float> RealtimeSinceStartupProvider { get; set; } = () => _stopwatch.ElapsedTicks * 1000f / System.Diagnostics.Stopwatch.Frequency;
        private static readonly System.Diagnostics.Stopwatch _stopwatch = System.Diagnostics.Stopwatch.StartNew();
        public static float realtimeSinceStartup => RealtimeSinceStartupProvider();
    }
}
