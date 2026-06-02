using System.Collections.Generic;
using Fuel.AssetManager;
using UnityEngine;

namespace Manager.UIManager
{
    public class UIResourceManager
    {
        private Dictionary<string, UIWindow> _windowMap = new Dictionary<string, UIWindow>();
        private Dictionary<string, string> _prefabPaths = new Dictionary<string, string>();

        public void RegisterWindow(string windowId, UIWindow window)
        {
            if (!_windowMap.ContainsKey(windowId))
            {
                _windowMap.Add(windowId, window);
            }
            else
            {
                _windowMap[windowId] = window;
            }
        }

        public void UnregisterWindow(string windowId)
        {
            if (_windowMap.ContainsKey(windowId))
            {
                _windowMap.Remove(windowId);
            }
        }

        public UIWindow GetWindow(string windowId)
        {
            return _windowMap.TryGetValue(windowId, out var window) ? window : null;
        }

        public bool HasWindow(string windowId)
        {
            return _windowMap.ContainsKey(windowId);
        }

        public void RegisterPrefabPath(string windowId, string prefabPath)
        {
            if (!_prefabPaths.ContainsKey(windowId))
            {
                _prefabPaths.Add(windowId, prefabPath);
            }
            else
            {
                _prefabPaths[windowId] = prefabPath;
            }
        }

        public string GetPrefabPath(string windowId)
        {
            return _prefabPaths.TryGetValue(windowId, out var path) ? path : null;
        }

        public GameObject LoadPrefab(string windowId)
        {
            string path = GetPrefabPath(windowId);
            if (string.IsNullOrEmpty(path)) return null;

            return AssetsLoadManager.Instance.LoadSync<GameObject>(path, windowId);
        }

        public GameObject CreateInstance(string windowId, Transform parent = null)
        {
            var instance = LoadPrefab(windowId);
            if (instance == null) return null;

            instance.transform.SetParent(parent, false);
            return instance;
        }

        public void ReleasePrefab(string windowId)
        {
            AssetsLoadManager.Instance.ReleaseAllByGroup(windowId);
        }

        public void Clear()
        {
            foreach (var windowId in _prefabPaths.Keys)
            {
                AssetsLoadManager.Instance.ReleaseAllByGroup(windowId);
            }
            _windowMap.Clear();
            _prefabPaths.Clear();
        }
    }
}
