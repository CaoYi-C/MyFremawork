using System;
using System.Collections.Generic;

#if UNITY_EDITOR
using Sirenix.OdinInspector;
#endif
using UnityEngine;

namespace Fuel.RedDot.RunTime
{
    public class RedDotTree
    {
        private static RedDotTree m_instance;

        public static RedDotTree Instance
        {
            get
            {
                if (m_instance == null)
                {
                    m_instance = new RedDotTree();
                    if (RedDotConfigAsset.Instance != null)
                    {
                        foreach (var redDotConfigData in RedDotConfigAsset.Instance.Data)
                        {
                            if (redDotConfigData.Path.Contains("{") || redDotConfigData.Path.Contains("}"))
                            {
                                continue;
                            }

                            m_instance.InitRedDotNode(redDotConfigData.Path, redDotConfigData.IsView,
                                redDotConfigData.BindRole,
                                redDotConfigData.ViewType, redDotConfigData.UseLocalSave);
                        }
                    }
                }

                return m_instance;
            }
        }

        private const string TREE_ROOT = "RedDotTreeRoot";
        public RedDotNodeBase Root;

        /// <summary>
        /// 缓存已格式化的路径，避免重复 string.Format 分配
        /// key = (redDotId, args的组合hashcode), value = 格式化后的路径
        /// </summary>
        private readonly Dictionary<long, string> _formattedPathCache = new Dictionary<long, string>();
        private const int MaxFormattedPathCacheCount = 1024;

        public RedDotTree()
        {
            Root = new RedDotNumberNode(TREE_ROOT);
            // 退出时强制 flush 所有攒批中的 PlayerPrefs
            Application.quitting += FlushPendingSaves;
        }

        private RedDotNodeBase GetRedDotNode(string path) => Root.GetRedDotNode(path);

        /// <summary>
        /// 获取格式化路径，优先从缓存读取
        /// </summary>
        private string GetFormattedPath(int redDotId, string pathTemplate, object[] args)
        {
            if (args == null || args.Length == 0)
                return pathTemplate;

            long cacheKey = GetCacheKey(redDotId, args);

            if (!_formattedPathCache.TryGetValue(cacheKey, out string path))
            {
                path = string.Format(pathTemplate, args);
                if (_formattedPathCache.Count >= MaxFormattedPathCacheCount)
                    _formattedPathCache.Clear();
                _formattedPathCache[cacheKey] = path;
            }
            return path;
        }

        /// <summary>
        /// 初始化红点节点
        /// </summary>
        /// <param name="path">红点路径</param>
        /// <param name="isView">是否是查看红点</param>
        /// <param name="bindRole">是否是绑定玩家ID</param>
        /// <param name="viewType">查看红点类型</param>
        public RedDotNodeBase InitRedDotNode(string path, bool isView, bool bindRole, ViewType viewType, bool localSave)
        {
            var redDotNode = Root.InitNode(path, isView, bindRole);
            if (isView)
            {
                string timestamp = GetLocalSaveData(bindRole, TREE_ROOT + "/" + path);
                if (!string.IsNullOrEmpty(timestamp))
                {
                    DateTime lastWatchTime = DateTimeOffset.FromUnixTimeSeconds(long.Parse(timestamp)).LocalDateTime;
                    DateTime now = DateTime.Now;
                    if (ShouldShowViewRedDot(viewType, lastWatchTime, now))
                    {
                        redDotNode.SetStatus(1);
                    }
                }
                else
                {
                    redDotNode.SetStatus(1);
                }
            }
            else
            {
                if (localSave)
                {
                    string localSaveData = GetLocalSaveData(bindRole, path);
                    if (int.TryParse(localSaveData, out int count))
                    {
                        redDotNode.SetStatus(count);
                    }
                }
            }

            return redDotNode;
        }

        /// <summary>
        /// 修改红点数量
        /// </summary>
        /// <param name="redDotId">红点ID</param>
        /// <param name="count">数量</param>
        /// <param name="args">红点路径参数</param>
        public void ChangeRedDotCount(int redDotId, int count, params object[] args)
        {
            if (RedDotConfigAsset.Instance.DataDic.TryGetValue(redDotId, out var redDotConfigData))
            {
                string path = GetFormattedPath(redDotId, redDotConfigData.Path, args);
                var redDotNode = GetRedDotNode(path);
                if (redDotNode == null)
                {
                    redDotNode = InitRedDotNode(path, redDotConfigData.IsView,
                        redDotConfigData.BindRole, redDotConfigData.ViewType, redDotConfigData.UseLocalSave);
                }

                if (redDotNode is RedDotNumberNode redDotNumberNode)
                {
                    redDotNumberNode.SetStatus(count);
                    if (redDotConfigData.UseLocalSave)
                    {
                        LocalSave(redDotConfigData.BindRole, path, count.ToString());
                    }
                }
            }
        }

        /// <summary>
        /// 修改红点数量（无参数重载，避免 params 数组分配）
        /// </summary>
        public void ChangeRedDotCount(int redDotId, int count)
        {
            if (RedDotConfigAsset.Instance.DataDic.TryGetValue(redDotId, out var redDotConfigData))
            {
                string path = redDotConfigData.Path;
                var redDotNode = GetRedDotNode(path);
                if (redDotNode == null)
                {
                    redDotNode = InitRedDotNode(path, redDotConfigData.IsView,
                        redDotConfigData.BindRole, redDotConfigData.ViewType, redDotConfigData.UseLocalSave);
                }

                if (redDotNode is RedDotNumberNode redDotNumberNode)
                {
                    redDotNumberNode.SetStatus(count);
                    if (redDotConfigData.UseLocalSave)
                    {
                        LocalSave(redDotConfigData.BindRole, path, count.ToString());
                    }
                }
            }
        }

        /// <summary>
        /// 通过累加值修改红点数量
        /// </summary>
        /// <param name="redDotId">红点ID</param>
        /// <param name="count">数量</param>
        /// <param name="args">红点路径参数</param>
        public void ChangeRedDotCountByAccumulation(int redDotId, int count, params object[] args)
        {
            if (RedDotConfigAsset.Instance.DataDic.TryGetValue(redDotId, out var redDotConfigData))
            {
                string path = GetFormattedPath(redDotId, redDotConfigData.Path, args);
                var redDotNode = GetRedDotNode(path);
                if (redDotNode == null)
                {
                    redDotNode = InitRedDotNode(path, redDotConfigData.IsView,
                        redDotConfigData.BindRole, redDotConfigData.ViewType, redDotConfigData.UseLocalSave);
                }

                if (redDotNode is RedDotNumberNode redDotNumberNode)
                {
                    redDotNumberNode.SetStateByAccumulation(count);
                    if (redDotConfigData.UseLocalSave)
                    {
                        LocalSave(redDotConfigData.BindRole, path, redDotNumberNode.RedDotCount.ToString());
                    }
                }
            }
        }

        /// <summary>
        /// 通过累加值修改红点数量（无参数重载，避免 params 数组分配）
        /// </summary>
        public void ChangeRedDotCountByAccumulation(int redDotId, int count)
        {
            if (RedDotConfigAsset.Instance.DataDic.TryGetValue(redDotId, out var redDotConfigData))
            {
                string path = redDotConfigData.Path;
                var redDotNode = GetRedDotNode(path);
                if (redDotNode == null)
                {
                    redDotNode = InitRedDotNode(path, redDotConfigData.IsView,
                        redDotConfigData.BindRole, redDotConfigData.ViewType, redDotConfigData.UseLocalSave);
                }

                if (redDotNode is RedDotNumberNode redDotNumberNode)
                {
                    redDotNumberNode.SetStateByAccumulation(count);
                    if (redDotConfigData.UseLocalSave)
                    {
                        LocalSave(redDotConfigData.BindRole, path, redDotNumberNode.RedDotCount.ToString());
                    }
                }
            }
        }

        /// <summary>
        /// 设置待查看
        /// </summary>
        /// <param name="redDotId">红点id</param>
        /// <param name="args">路径匹配参数</param>
        public void SetWaitWatch(int redDotId, params object[] args)
        {
            if (RedDotConfigAsset.Instance.DataDic.TryGetValue(redDotId, out var redDotConfigData))
            {
                string path = GetFormattedPath(redDotId, redDotConfigData.Path, args);
                var redDotNode = GetRedDotNode(path);
                if (redDotNode == null)
                {
                    redDotNode = InitRedDotNode(path, redDotConfigData.IsView,
                        redDotConfigData.BindRole, redDotConfigData.ViewType, redDotConfigData.UseLocalSave);
                }

                if (redDotNode is RedDotViewNode redDotViewNode)
                {
                    if (CanChangView(redDotConfigData,
                            GetLocalSaveData(redDotConfigData.BindRole, TREE_ROOT + "/" + path)))
                    {
                        redDotViewNode.SetStatus(1);
                    }
                    else
                    {
                        redDotViewNode.SetStatus(0);
                    }
                }
                else
                {
                    Debug.LogWarning("非查看红点，设置待查看状态默认设置数量未为1");
                }
            }
        }

        /// <summary>
        /// 设置待查看（无参数重载，避免 params 数组分配）
        /// </summary>
        public void SetWaitWatch(int redDotId)
        {
            if (RedDotConfigAsset.Instance.DataDic.TryGetValue(redDotId, out var redDotConfigData))
            {
                string path = redDotConfigData.Path;
                var redDotNode = GetRedDotNode(path);
                if (redDotNode == null)
                {
                    redDotNode = InitRedDotNode(path, redDotConfigData.IsView,
                        redDotConfigData.BindRole, redDotConfigData.ViewType, redDotConfigData.UseLocalSave);
                }

                if (redDotNode is RedDotViewNode redDotViewNode)
                {
                    if (CanChangView(redDotConfigData,
                            GetLocalSaveData(redDotConfigData.BindRole, TREE_ROOT + "/" + path)))
                    {
                        redDotViewNode.SetStatus(1);
                    }
                    else
                    {
                        redDotViewNode.SetStatus(0);
                    }
                }
                else
                {
                    Debug.LogWarning("非查看红点，设置待查看状态默认设置数量未为1");
                }
            }
        }

        private bool CanChangView(RedDotConfigAsset.RedDotConfigData redDotConfigData, string saveKey)
        {
            if (string.IsNullOrEmpty(saveKey))
            {
                return true;
            }

            DateTime lastWatchTime = DateTimeOffset.FromUnixTimeSeconds(long.Parse(saveKey)).LocalDateTime;
            return ShouldShowViewRedDot(redDotConfigData.ViewType, lastWatchTime, DateTime.Now);
        }

        private bool ShouldShowViewRedDot(ViewType viewType, DateTime lastWatchTime, DateTime now)
        {
            switch (viewType)
            {
                case ViewType.Once:
                    return false;
                case ViewType.Day:
                    return lastWatchTime.Date != now.Date;
                case ViewType.Week:
                    return !IsInSameWeek(lastWatchTime, now);
                case ViewType.Month:
                    return lastWatchTime.Year != now.Year || lastWatchTime.Month != now.Month;
            }

            return true;
        }


        public void Watch(int redDotId, params object[] args)
        {
            if (RedDotConfigAsset.Instance.DataDic.TryGetValue(redDotId, out var redDotConfigData))
            {
                string path = GetFormattedPath(redDotId, redDotConfigData.Path, args);
                var redDotNode = GetRedDotNode(path);
                if (redDotNode == null)
                {
                    redDotNode = InitRedDotNode(path, redDotConfigData.IsView,
                        redDotConfigData.BindRole, redDotConfigData.ViewType, redDotConfigData.UseLocalSave);
                }

                redDotNode.SetStatus(0);
            }
        }

        public void Watch(string path)
        {
            GetRedDotNode(path)?.SetStatus(0);
        }

        /// <summary>
        /// 注册红点
        /// </summary>
        /// <param name="redDotId">红点id</param>
        /// <param name="changeCb">回调</param>
        /// <param name="args">路径匹配参数</param>
        public void Register(int redDotId, Action<int> changeCb, params object[] args)
        {
            if (RedDotConfigAsset.Instance.DataDic.TryGetValue(redDotId, out var redDotData))
            {
                string path = args.Length > 0 ? string.Format(redDotData.Path, args) : redDotData.Path;
                RedDotNodeBase redDotNode = GetRedDotNode(path);
                if (redDotNode == null)
                {
                    redDotNode = InitRedDotNode(path, redDotData.IsView, redDotData.BindRole, redDotData.ViewType, redDotData.UseLocalSave);
                }

                redDotNode.Register(changeCb);
            }
        }

        /// <summary>
        /// 用 (redDotId, args) 组合 HashCode 代替字符串拼装，避免每帧 string.Join 分配
        /// 旧版返回 string 还会触发 Dictionary<string,string> 的字符串哈希开销
        /// </summary>
        private static long GetCacheKey(int redDotId, object[] args)
        {
            // redDotId 占高 32 位，args 组合 hash 占低 32 位
            unchecked
            {
                int argsHash = HashCode.Combine(args.Length, args.Length > 0 ? args[0] : null);
                for (int i = 1; i < args.Length; i++)
                {
                    argsHash = HashCode.Combine(argsHash, args[i]);
                }
                return ((long)redDotId << 32) | (uint)argsHash;
            }
        }

        /// <summary>
        /// 从缓存中移除指定 redDotId + args 对应的路径
        /// </summary>
        private void RemoveFormattedPathCache(int redDotId, object[] args)
        {
            long cacheKey = GetCacheKey(redDotId, args);
            _formattedPathCache.Remove(cacheKey);
        }

        /// <summary>
        /// 移除红点数据结构
        /// </summary>
        /// <param name="redDotId"></param>
        /// <param name="args"></param>
        public void RemoveRedDotNode(int redDotId, params object[] args)
        {
            if (RedDotConfigAsset.Instance.DataDic.TryGetValue(redDotId, out var redDotData))
            {
                var redPath = GetFormattedPath(redDotId, redDotData.Path, args);
                RedDotNodeBase redDotNode = GetRedDotNode(redPath);
                if (redDotNode == null)
                {
                    Debug.LogWarning($"移除红点数据节点失败，路径：{redPath}");
                }
                else
                {
                    redDotNode.Clear();
                }

                // 节点已移除，清理对应的路径缓存
                RemoveFormattedPathCache(redDotId, args);
            }
        }

        /// <summary>
        /// 重置红点节点数据（清除红点状态，不删除节点结构）
        /// </summary>
        /// <param name="redDotId"></param>
        /// <param name="args"></param>
        public void ResetRedDotNode(int redDotId, params object[] args)
        {
            if (RedDotConfigAsset.Instance.DataDic.TryGetValue(redDotId, out var redDotData))
            {
                var redPath = GetFormattedPath(redDotId, redDotData.Path, args);
                RedDotNodeBase redDotNode = GetRedDotNode(redPath);
                if (redDotNode == null)
                {
                    Debug.LogWarning($"重置红点数据节点失败，路径：{redPath}");
                }
                else
                {
                    redDotNode.ClearStatus();
                }
            }
        }

        /// <summary>
        /// 注销红点
        /// </summary>
        /// <param name="path">红点路径</param>
        /// <param name="changeCb">修改事件</param>
        public void Unregister(string path, Action<int> changeCb)
        {
            GetRedDotNode(path)?.Unregister(changeCb);
        }

        /// <summary>
        /// 储存的特殊key,跟玩家的RoleID绑定
        /// </summary>
        public static string UniqueKey;

        // 攒批落盘：高频 SetString 期间不立即 PlayerPrefs.Save，
        // 由 FlushPendingSaves() 触发一次性 Save() 避免卡帧。
        private static readonly Dictionary<string, string> _pendingRedDotSaves = new Dictionary<string, string>();
        private static readonly HashSet<string> _pendingRedDotDeletes = new HashSet<string>();
        private static bool _hasPendingRedDotWrites;

        /// <summary>
        /// 是否有待刷新的攒批写盘（用于测试和外部判断）
        /// </summary>
        public static bool HasPendingSaves => _hasPendingRedDotWrites;

        /// <summary>
        /// 本地储存红点数据。
        /// 写值立即生效到 PlayerPrefs 内存，但 PlayerPrefs.Save() 改为攒批——
        /// 默认仅当达到 <see cref="PendingRedDotFlushThreshold"/> 次写入或调用 <see cref="FlushPendingSaves"/> 时才刷盘。
        /// </summary>
        public static void LocalSave(bool bindRole, string key, string value)
        {
            string localKey = bindRole ? UniqueKey + key : key;
            PlayerPrefs.SetString(localKey, value);
            _pendingRedDotSaves[localKey] = value;
            _pendingRedDotDeletes.Remove(localKey);
            _hasPendingRedDotWrites = true;
            MaybeFlush();
        }

        /// <summary>
        /// 删除本地储存的红点数据
        /// </summary>
        /// <param name="bindRole"></param>
        /// <param name="key"></param>
        public static void RemoveLocalSave(bool bindRole, string key)
        {
            string localKey = bindRole ? UniqueKey + key : key;
            if (PlayerPrefs.HasKey(localKey))
            {
                PlayerPrefs.DeleteKey(localKey);
                _pendingRedDotDeletes.Add(localKey);
                _pendingRedDotSaves.Remove(localKey);
                _hasPendingRedDotWrites = true;
                MaybeFlush();
            }
        }

        /// <summary>
        /// 自动攒批阈值：攒够 N 次写盘或 M 秒后强制 flush
        /// </summary>
        public static int PendingRedDotFlushThreshold = 16;
        private static float _lastFlushTime;

        private static void MaybeFlush()
        {
            if (_pendingRedDotSaves.Count + _pendingRedDotDeletes.Count >= PendingRedDotFlushThreshold)
            {
                FlushPendingSaves();
                return;
            }
            // 兜底：超过 5 秒未刷盘也强制 flush（防止崩溃丢数据）
            if (_hasPendingRedDotWrites && UnityEngine.Time.realtimeSinceStartup - _lastFlushTime > 5f)
            {
                FlushPendingSaves();
            }
        }

        /// <summary>
        /// 主动 flush 所有攒批中的 PlayerPrefs 写盘
        /// 建议在场景切换、应用暂停、退出前调用
        /// </summary>
        public static void FlushPendingSaves()
        {
            if (!_hasPendingRedDotWrites) return;
            PlayerPrefs.Save();
            _pendingRedDotSaves.Clear();
            _pendingRedDotDeletes.Clear();
            _hasPendingRedDotWrites = false;
            _lastFlushTime = UnityEngine.Time.realtimeSinceStartup;
        }

        /// <summary>
        /// 获取本地储存的红点数据
        /// </summary>
        public static string GetLocalSaveData(bool bindRole, string key)
        {
            string localKey = bindRole ? UniqueKey + key : key;
            return PlayerPrefs.GetString(localKey);
        }

        #region 工具

        /// <summary> 
        /// 判断两个日期是否在同一周 
        /// </summary> 
        /// <param name="dtmS">开始日期</param> 
        /// <param name="dtmE">结束日期</param>
        /// <returns></returns> 
        private bool IsInSameWeek(DateTime dtmS, DateTime dtmE)
        {
            DateTime startDate = dtmS.Date;
            DateTime endDate = dtmE.Date;
            int startDayOfWeek = (int)startDate.DayOfWeek;
            int endDayOfWeek = (int)endDate.DayOfWeek;
            if (startDayOfWeek == 0) startDayOfWeek = 7;
            if (endDayOfWeek == 0) endDayOfWeek = 7;

            DateTime startWeekMonday = startDate.AddDays(1 - startDayOfWeek);
            DateTime endWeekMonday = endDate.AddDays(1 - endDayOfWeek);
            return startWeekMonday == endWeekMonday;
        }
        #endregion
    }

    public enum ViewType
    {
        /// <summary>
        /// 一次
        /// </summary>
#if UNITY_EDITOR
        [LabelText("单次查看")]
#endif
        Once,

        /// <summary>
        /// 每日查看
        /// </summary>
#if UNITY_EDITOR
        [LabelText("每日查看")]
#endif
        Day,

        /// <summary>
        /// 每周查看
        /// </summary>
#if UNITY_EDITOR
        [LabelText("每周查看")]
#endif
        Week,

        /// <summary>
        /// 每月查看
        /// </summary>
#if UNITY_EDITOR
        [LabelText("每月查看")]
#endif
        Month,
    }
}