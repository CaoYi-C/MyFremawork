using System.Collections.Generic;
using Cysharp.Threading.Tasks;
using Fuel.Pools;
using UnityEngine;
using YooAsset;

namespace Fuel.AssetManager.AssetsPools
{
    internal class GameObjectPool : IObjectPool
    {
        private bool _isInit;
        private string _groupName = string.Empty;
        private string _assetName = string.Empty;
        private Stack<GameObject> _pool;
        private AssetHandle _baseHandle;
        private const int MaxPoolCount = 100;
        private int _loadVersion;
        private GameObject _nomalPrefab;

        private List<GameObject> _createList;
        private List<GameObject> _useList;
        // 维护"在池中"集合，O(1) 防重入替代 Stack<T>.Contains O(n) 扫描
        private HashSet<GameObject> _inPoolSet;

        public GameObjectPool()
        {
            _createList = new List<GameObject>();
            _useList = new List<GameObject>();
            _pool = new Stack<GameObject>();
            _inPoolSet = new HashSet<GameObject>();
        }


        private async UniTask<bool> InitAsync(string assetName, string groupName)
        {
            int version = ++_loadVersion;
            _assetName = assetName;
            _groupName = groupName;
            _baseHandle = await AssetsLoadManager.Instance.LoadAsyncHandle<GameObject>(assetName, groupName);
            if (version != _loadVersion)
            {
                _baseHandle?.Release();
                _baseHandle = null;
                return false;
            }
            return _baseHandle != null && _baseHandle.IsValid && _baseHandle.Status == EOperationStatus.Succeeded;
        }

        internal bool InitSync(string assetName, string groupName)
        {
            ++_loadVersion;
            _assetName = assetName;
            _groupName = groupName;
            _pool = new Stack<GameObject>();
            _baseHandle = AssetsLoadManager.Instance.LoadSyncHandle<GameObject>(assetName, groupName);
            return _baseHandle != null && _baseHandle.IsValid && _baseHandle.Status == EOperationStatus.Succeeded;
        }


        internal async UniTask<GameObject> GetAsync(string assetName, string groupName)
        {
            if (!_isInit)
            {
                _isInit = await InitAsync(assetName, groupName);
                if (!_isInit)
                    return null;
            }

           
            if (_pool.Count > 0)
            {
                GameObject go = _pool.Pop();
                _inPoolSet.Remove(go);
                if (go == null)
                {
                    _createList.Remove(go);
                    go = await GetAsync(assetName, groupName);
                    return go;
                }
                _useList.Add(go);
                return go;
            }
            else
            {
                int version = _loadVersion;
                InstantiateOperation instantiate = _baseHandle.InstantiateAsync();
                await instantiate.ToUniTask();
                if (version != _loadVersion)
                {
                    DestroyObject(instantiate.Result);
                    return null;
                }
                GameObject go = instantiate.Result;
                _createList.Add(go);
                go.name = assetName;
                // 移除 instantiate.Cancel() — 对象已实例化完毕，
                // Cancel() 可能释放底层 Handle 导致对象引用失效
                _useList.Add(go);
                return go;
            }
        }
        
        internal void InitByPrefab(GameObject prefab)
        {
            _nomalPrefab = prefab;
            _assetName = prefab.name;
            _isInit = true;
        }
        
        internal GameObject GetSyncByPrefab()
        {
            if (!_isInit)
                return null;
            if (_pool.Count > 0)
            {
                var go = _pool.Pop();
                _inPoolSet.Remove(go);
                if (go == null)
                {
                    _createList.Remove(go);
                    go = GetSyncByPrefab();
                    return go;
                }
                _useList.Add(go);
                return go;
            }
            else
            {
                var go = Object.Instantiate(_nomalPrefab);
                go.name = _nomalPrefab.name;
                _createList.Add(go);
                _useList.Add(go);
                return go;
            }
        }

        internal GameObject GetSync(string assetName, string groupName)
        {
            if (!_isInit)
            {
                _isInit = InitSync(assetName, groupName);
                if (!_isInit)
                    return null;
            }

            if (_pool.Count > 0)
            {
                GameObject go = _pool.Pop();
                _inPoolSet.Remove(go);
                if (go == null)
                {
                    _createList.Remove(go);
                    go = GetSync(assetName, groupName);
                    return go;
                }
                _useList.Add(go);
                return go;
            }
            else
            {
                GameObject go = _baseHandle.InstantiateSync();
                if (go == null)
                    return null;

                go.name = assetName;
                _createList.Add(go);
                _useList.Add(go);
                return go;
            }
        }

        internal void Recycle(GameObject go)
        {
            if (go == null) return;
            // O(1) HashSet 替代 Stack<T>.Contains O(n) 扫描
            if (!_inPoolSet.Add(go)) return;
            if (_pool.Count >= MaxPoolCount)
            {
                _createList.Remove(go);
                _useList.Remove(go);
                _inPoolSet.Remove(go);
                DestroyObject(go);
                return;
            }
            _useList.Remove(go);
            go.transform.SetParent(GameObjectPools.Instance.GameObjectPoolParent);
            go.name = _assetName;
            _pool.Push(go);
        }

        internal void RecycleAll()
        {
            for (int i = _createList.Count - 1; i >= 0; i--)
            {
                Recycle(_createList[i]);
            }
        }

        internal List<GameObject> GetCreateList()
        {
            return _createList;
        }
        internal void StopLoad()
        {
            ++_loadVersion;
        }

        public void Clear()
        {
            StopLoad();
            for (int i = _createList.Count - 1; i >= 0; i--)
            {
                DestroyObject(_createList[i]);
            }
            _useList.Clear();
            _createList.Clear();
            _pool.Clear();
            _inPoolSet.Clear();
            _baseHandle = null;
            AssetsLoadManager.Instance.Release(_assetName, _groupName);
            _assetName = string.Empty;
            _groupName = string.Empty;
            _isInit = false;
        }

        private static void DestroyObject(GameObject go)
        {
            if (go == null) return;
            if (Application.isPlaying)
                Object.Destroy(go);
            else
                Object.DestroyImmediate(go);
        }

        public void Disposable()
        {
            Clear();
        }
    }
}

