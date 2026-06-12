using System.Collections.Generic;
using Fuel.Pools;
using Fuel.Singleton;
using UnityEngine;
using UnityEngine.Events;

namespace Fuel.AssetManager
{
    // ReSharper disable once ClassNeverInstantiated.Global
    internal class AssetsGroupManager : Singleton<AssetsGroupManager>
    {
        internal UnityEvent DestroyEvent;
        internal UnityEvent DisposeEvent;

        private Dictionary<string, AssetsGroup> _groupMap;

        protected void RegistrationLife()
        {
            DestroyEvent = new UnityEvent();
            DisposeEvent = new UnityEvent();
        }

        protected override void Init()
        {
            base.Init();
            DestroyEvent = new UnityEvent();
            DisposeEvent = new UnityEvent();
            _groupMap = new Dictionary<string, AssetsGroup>();
            Application.quitting += Dispose;
        }



        public AssetsGroup GetAssetGroup(string groupName = "")
        {
            if (string.IsNullOrEmpty(groupName)) groupName = AssetsManager.NormalAssetGroupName;
            if (_groupMap.TryGetValue(groupName, out var assetsGroup))
            {
                return assetsGroup;
            }
            assetsGroup = ObjectPools.Instance.Get<AssetsGroup>();
            assetsGroup.Init(groupName);
            _groupMap.Add(groupName, assetsGroup);
            return assetsGroup;
        }

        public void DestoryByGroup(string groupName = "", bool isUnuseAssets = false)
        {
            if (string.IsNullOrEmpty(groupName)) groupName = AssetsManager.NormalAssetGroupName;
            if (!_groupMap.TryGetValue(groupName, out var assetsGroup)) return;
            ObjectPools.Instance.Recycle(assetsGroup);
            _groupMap.Remove(groupName);
            if (isUnuseAssets)
                AssetsManager.Instance.RemoveUnusedAssets();
        }

        public void StopLoadByGroup(string groupName = "")
        {
            if (string.IsNullOrEmpty(groupName)) groupName = AssetsManager.NormalAssetGroupName;
            if (_groupMap.TryGetValue(groupName, out var assetsGroup))
            {
                assetsGroup.StopLoad();
            }
        }

        public void StopLoad()
        {
            foreach (var group in _groupMap.Values)
            {
                group.StopLoad();
            }
        }

        public void Clear(bool unloadUnusedAssets = true)
        {
            if (_groupMap == null) return;
            StopLoad();
            DestroyEvent?.Invoke();
            foreach (var group in _groupMap.Values)
            {
                ObjectPools.Instance.Recycle(group);
            }
            _groupMap.Clear();
            if (unloadUnusedAssets)
                AssetsManager.Instance.RemoveUnusedAssets();
        }

        public void Dispose()
        {
            Application.quitting -= Dispose;
            Clear(false);
            DisposeEvent?.Invoke();
            DestroyEvent?.RemoveAllListeners();
            DisposeEvent?.RemoveAllListeners();
            DestroyEvent = null;
            DisposeEvent = null;
            _groupMap = null;
        }

        protected void OnDestroy()
        {
            Clear();
        }

        protected void OnDispose()
        {
            Dispose();
        }
    }
}
