using System;
using Cysharp.Threading.Tasks;
using Fuel.Log;
using Fuel.Singleton;
using YooAsset;

namespace HotFarmework.AssetManager
{
#if UNITY_EDITOR
    public static class AssetsManagerEditor
    {
        public static async UniTask InitYooAsset(string packageName = "Main")
        {
            if (!YooAssets.IsInitialized)
                YooAssets.Initialize();

            if (!YooAssets.TryGetPackage(packageName, out var package))
                package = YooAssets.CreatePackage(packageName);

            if (package.PackageValid)
                return;

            //编辑器模拟模式
            var buildResult = EditorSimulateBuildInvoker.Build(packageName, (int)EBundleType.VirtualAssetBundle);
            var packageRoot = buildResult.PackageRootDirectory;
            var fileSystemParams = FileSystemParameters.CreateDefaultEditorFileSystemParameters(packageRoot);

            var createParameters = new EditorSimulateModeOptions();
            createParameters.EditorFileSystemParameters = fileSystemParams;

            var initOperation = package.InitializePackageAsync(createParameters);
            await initOperation.ToUniTask();
            if (initOperation.Status != EOperationStatus.Succeeded)
            {
                DebugLogger.LogError($"资源包初始化失败：{initOperation.Error}");
            }
            var getVersionOperation = package.RequestPackageVersionAsync();
            await getVersionOperation.ToUniTask();

            string packageVersion = string.Empty;
            if (getVersionOperation.Status == EOperationStatus.Succeeded)
            {
                //更新成功
                packageVersion = getVersionOperation.PackageVersion;
                DebugLogger.Log($"Request package Version : {packageVersion}");

            }
            else
            {
                //更新失败
                DebugLogger.LogError(getVersionOperation.Error);
                return;
            }

            var loadPackageManifestOperation = package.LoadPackageManifestAsync(new LoadPackageManifestOptions(packageVersion, 60));
            await loadPackageManifestOperation.ToUniTask();
            if (loadPackageManifestOperation.Status != EOperationStatus.Succeeded)
            {
                DebugLogger.LogError($"资源包LoadPackageManifestAsync失败：{loadPackageManifestOperation.Error}");
            }
        }
    }
#endif

    // ReSharper disable once ClassNeverInstantiated.Global
    public class AssetsManager : Singleton<AssetsManager>
    {
        /// <summary>
        /// 公共加载组
        /// </summary>
        internal const string NomalAssetGroupName = "NomalAssetGroup";
        private const string DefaultPackageName = "Main";

#if UNITY_EDITOR
        public async UniTask EnsureYooAssetInitializedAsync(string packageName = null)
        {
            await AssetsManagerEditor.InitYooAsset(string.IsNullOrEmpty(packageName) ? DefaultPackageName : packageName);
        }
#endif

        internal ResourcePackage GetPackage(string packageName = null)
        {
            if (string.IsNullOrEmpty(packageName))
                packageName = DefaultPackageName;
            return YooAssets.GetPackage(packageName);
        }

        #region 同步加载

        public UnityEngine.Object Load(string path, Type type, string packageName = null) => Load(path, type, out _, packageName);

        public UnityEngine.Object Load(string path, Type type, out AssetHandle handle, string packageName = null)
        {
            handle = GetPackage(packageName).LoadAssetSync(path, type);
            return handle.AssetObject;
        }

        public T Load<T>(string path, string packageName = null) where T : UnityEngine.Object => Load<T>(path, out _, packageName);

        public T Load<T>(string path, out AssetHandle handle, string packageName = null) where T : UnityEngine.Object
        {
            handle = GetPackage(packageName).LoadAssetSync<T>(path);
            return handle.AssetObject as T;
        }

        public T LoadSub<T>(string mainPath, string path, string packageName = null) where T : UnityEngine.Object => LoadSub<T>(mainPath, path, out _, packageName);

        public T LoadSub<T>(string mainPath, string path, out SubAssetsHandle handle, string packageName = null) where T : UnityEngine.Object
        {
            handle = GetPackage(packageName).LoadSubAssetsSync<T>(mainPath);
            return handle.GetSubAssetObject<T>(path);
        }

        #endregion

        #region 异步加载

        public async UniTask<UnityEngine.Object> LoadAsync(string path, Type type, string packageName)
        {
            var handle = GetPackage(packageName).LoadAssetAsync(path, type);
            await handle.ToUniTask();
            return handle.AssetObject;
        }

        public async UniTask<T> LoadAsync<T>(string path, string packageName = null) where T : UnityEngine.Object
        {
            var handle = GetPackage(packageName).LoadAssetAsync<T>(path);
            await handle.ToUniTask();
            return handle.GetAssetObject<T>();
        }

        public async UniTask<(UnityEngine.Object, AssetHandle)> LoadAsyncWithHandle(string path, Type type, string packageName = null)
        {
            var handle = GetPackage(packageName).LoadAssetAsync(path, type);
            await handle.ToUniTask();
            return (handle.AssetObject, handle);
        }

        public async UniTask<(T, AssetHandle)> LoadAsyncWithHandle<T>(string path, string packageName = null) where T : UnityEngine.Object
        {
            var handle = GetPackage(packageName).LoadAssetAsync<T>(path);
            await handle.ToUniTask();
            return (handle.GetAssetObject<T>(), handle);
        }

        public async UniTask<T> LoadSubAsync<T>(string mainPath, string path, string packageName = null) where T : UnityEngine.Object
        {
            var handle = GetPackage(packageName).LoadSubAssetsAsync<T>(mainPath);
            await handle.ToUniTask();
            return handle.GetSubAssetObject<T>(path);
        }

        public async UniTask<(T, SubAssetsHandle)> LoadSubAsyncWithHandle<T>(string mainPath, string path, string packageName = null) where T : UnityEngine.Object
        {
            var handle = GetPackage(packageName).LoadSubAssetsAsync<T>(mainPath);
            await handle.ToUniTask();
            return (handle.GetSubAssetObject<T>(path), handle);
        }

        public SceneHandle LoadSceneAsync(string path, bool additive = false, string packageName = null)
        {
            return GetPackage(packageName).LoadSceneAsync(path, additive ? UnityEngine.SceneManagement.LoadSceneMode.Additive : UnityEngine.SceneManagement.LoadSceneMode.Single);
        }

        public async UniTask UnloadSceneAsync(SceneHandle handle)
        {
            if (handle == null || !handle.IsValid)
                return;

            var operation = handle.UnloadSceneAsync();
            await operation.ToUniTask();
        }

        public void RemoveUnusedAssets(string packageName = null)
        {
            GetPackage(packageName)?.UnloadUnusedAssetsAsync();
        }
        #endregion
    }
}
