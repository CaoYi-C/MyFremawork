using System;
using System.Collections.Generic;
using UnityEngine;
using Cysharp.Threading.Tasks;
using Fuel.GameEvent;
using Fuel.Scene;
using Fuel.Log;
using Fuel.AssetManager;
using YooAsset;

namespace Manager.SceneManager
{
    public partial class SceneManager
    {
        #region Main Scene Loading

        /// <summary>
        /// 异步加载主场景（会卸载当前主场景和所有附加场景）
        /// </summary>
        /// <param name="sceneId">场景ID</param>
        /// <param name="sceneData">场景数据</param>
        /// <param name="onProgress">加载进度回调 (0-1)</param>
        /// <param name="onComplete">加载完成回调</param>
        public void LoadMainScene(string sceneId, SceneData sceneData = null,
            Action<float> onProgress = null, Action onComplete = null)
        {
            if (_currentMainScene != null && _currentMainScene.SceneId == sceneId)
            {
                DebugLogger.LogWarning(LogWriter.SceneManager, $"Main scene {sceneId} is already loaded");
                onComplete?.Invoke();
                return;
            }

            if (_loadingScenes.Contains(sceneId))
            {
                DebugLogger.LogWarning(LogWriter.SceneManager, $"Scene {sceneId} is already loading");
                return;
            }

            if (!_sceneConfigs.TryGetValue(sceneId, out var sceneInfo))
            {
                DebugLogger.LogError(LogWriter.SceneManager, $"Scene config not found: {sceneId}");
                return;
            }

            if (!sceneInfo.IsMainScene)
            {
                DebugLogger.LogWarning(LogWriter.SceneManager, $"Scene {sceneId} is not a main scene, use LoadAdditiveScene instead");
                return;
            }

            RunSceneOperation(LoadMainSceneAsync(sceneInfo, sceneData, onProgress, onComplete), sceneId, true);
        }

        private async UniTask LoadMainSceneAsync(SceneInfo sceneInfo, SceneData sceneData,
            Action<float> onProgress, Action onComplete)
        {
            string sceneId = sceneInfo.SceneId;
            string oldSceneId = _currentMainScene?.SceneId;
            _loadingScenes.Add(sceneId);

            try
            {
                // 通知开始加�?
                EventDispatcher.Instance.Dispatch(new Scene_LoadStartEvent
                {
                    SceneId = sceneId,
                    IsMainScene = true
                });

                // 卸载所有附加场�?
                await UnloadAllAdditiveScenesAsync();

                // 卸载当前主场�?
                if (_currentMainScene != null)
                {
                    await UnloadSceneAsync(_currentMainScene);
                }

                // 异步加载新场�?
                if (!await LoadSceneAsync(sceneInfo, true, sceneData, onProgress))
                    return;

                _currentMainScene = sceneInfo;

                // 通知主场景切�?
                EventDispatcher.Instance.Dispatch(new Scene_MainSceneChangedEvent
                {
                    OldSceneId = oldSceneId,
                    NewSceneId = sceneId
                });

                onComplete?.Invoke();
                OnSceneLoaded?.Invoke(sceneInfo);

                DebugLogger.Log(LogWriter.SceneManager, $"Main scene loaded: {sceneId}");
            }
            finally
            {
                _loadingScenes.Remove(sceneId);
            }
        }

        #endregion

        #region Additive Scene Loading

        /// <summary>
        /// 异步加载附加场景（叠加在当前场景上）
        /// </summary>
        /// <param name="sceneId">场景ID</param>
        /// <param name="sceneData">场景数据</param>
        /// <param name="onProgress">加载进度回调 (0-1)</param>
        /// <param name="onComplete">加载完成回调</param>
        public void LoadAdditiveScene(string sceneId, SceneData sceneData = null,
            Action<float> onProgress = null, Action onComplete = null)
        {
            if (_sceneScripts.ContainsKey(sceneId))
            {
                DebugLogger.LogWarning(LogWriter.SceneManager, $"Scene {sceneId} is already loaded");
                onComplete?.Invoke();
                return;
            }

            if (_loadingScenes.Contains(sceneId))
            {
                DebugLogger.LogWarning(LogWriter.SceneManager, $"Scene {sceneId} is already loading");
                return;
            }

            if (!_sceneConfigs.TryGetValue(sceneId, out var sceneInfo))
            {
                DebugLogger.LogError(LogWriter.SceneManager, $"Scene config not found: {sceneId}");
                return;
            }

            if (sceneInfo.IsMainScene)
            {
                DebugLogger.LogWarning(LogWriter.SceneManager, $"Scene {sceneId} is a main scene, use LoadMainScene instead");
                return;
            }

            RunSceneOperation(LoadAdditiveSceneAsync(sceneInfo, sceneData, onProgress, onComplete), sceneId, false);
        }

        private async UniTask LoadAdditiveSceneAsync(SceneInfo sceneInfo, SceneData sceneData,
            Action<float> onProgress, Action onComplete)
        {
            string sceneId = sceneInfo.SceneId;
            _loadingScenes.Add(sceneId);

            try
            {
                // 通知开始加�?
                EventDispatcher.Instance.Dispatch(new Scene_LoadStartEvent
                {
                    SceneId = sceneId,
                    IsMainScene = false
                });

                // 异步加载场景（additive 模式�?
                if (!await LoadSceneAsync(sceneInfo, false, sceneData, onProgress))
                    return;

                _loadedAdditiveScenes.Add(sceneInfo);

                onComplete?.Invoke();
                OnSceneLoaded?.Invoke(sceneInfo);

                DebugLogger.Log(LogWriter.SceneManager, $"Additive scene loaded: {sceneId}");
            }
            finally
            {
                _loadingScenes.Remove(sceneId);
            }
        }

        #endregion

        #region Scene Unloading

        /// <summary>
        /// 卸载附加场景
        /// </summary>
        /// <param name="sceneId">场景ID</param>
        /// <param name="onComplete">卸载完成回调</param>
        public void UnloadScene(string sceneId, Action onComplete = null)
        {
            if (!_sceneScripts.ContainsKey(sceneId))
            {
                DebugLogger.LogWarning(LogWriter.SceneManager, $"Scene {sceneId} is not loaded");
                return;
            }

            var sceneInfo = GetLoadedSceneInfo(sceneId);
            if (sceneInfo == null)
            {
                onComplete?.Invoke();
                return;
            }

            RunSceneOperation(UnloadSceneAsync(sceneInfo, onComplete), sceneId, sceneInfo.IsMainScene);
        }

        /// <summary>
        /// 卸载所有附加场�?
        /// </summary>
        /// <param name="onComplete">卸载完成回调</param>
        public void UnloadAllAdditiveScenes(Action onComplete = null)
        {
            RunSceneOperation(UnloadAllAdditiveScenesAsync(onComplete), string.Empty, false);
        }

        private async UniTask UnloadSceneAsync(SceneInfo sceneInfo, Action onComplete = null)
        {
            string sceneId = sceneInfo.SceneId;

            // 通知开始卸�?
            EventDispatcher.Instance.Dispatch(new Scene_UnloadStartEvent
            {
                SceneId = sceneId
            });

            // 调用场景脚本�?UnregisterEvents �?OnExit
            if (_sceneScripts.TryGetValue(sceneId, out var sceneScript))
            {
                sceneScript.UnregisterEvents();
                sceneScript.OnExit();
                sceneScript.IsLoaded = false;
                _sceneScripts.Remove(sceneId);
            }

            // 通过 Unity 原生接口卸载场景
            await UnloadNativeSceneAsync(sceneInfo);

            _loadedAdditiveScenes.RemoveAll(s => s.SceneId == sceneId);

            if (_currentMainScene != null && _currentMainScene.SceneId == sceneId)
            {
                _currentMainScene = null;
            }

            ClearSceneRoot(sceneId);

            // 通知卸载完成
            EventDispatcher.Instance.Dispatch(new Scene_UnloadCompleteEvent
            {
                SceneId = sceneId
            });

            onComplete?.Invoke();
            OnSceneUnloaded?.Invoke(sceneInfo);

            DebugLogger.Log(LogWriter.SceneManager, $"Scene unloaded: {sceneId}");
        }

        private async UniTask UnloadAllAdditiveScenesAsync(Action onComplete = null)
        {
            var scenesToUnload = new List<SceneInfo>(_loadedAdditiveScenes);

            foreach (var sceneInfo in scenesToUnload)
            {
                await UnloadSceneAsync(sceneInfo);
            }

            onComplete?.Invoke();
        }

        private SceneInfo GetLoadedSceneInfo(string sceneId)
        {
            if (_currentMainScene != null && _currentMainScene.SceneId == sceneId)
                return _currentMainScene;

            return _loadedAdditiveScenes.Find(s => s.SceneId == sceneId);
        }

        #endregion

        #region Core Loading

        private readonly Dictionary<string, SceneHandle> _sceneHandles = new Dictionary<string, SceneHandle>();

        private async UniTask<bool> LoadSceneAsync(SceneInfo sceneInfo, bool isMainScene,
            SceneData sceneData, Action<float> onProgress)
        {
            var sceneId = sceneInfo.SceneId;
#if UNITY_EDITOR
            await AssetsManager.Instance.EnsureYooAssetInitializedAsync();
#endif
            var handle = AssetsManager.Instance.LoadSceneAsync(sceneInfo.ScenePath, !isMainScene);

            while (!handle.IsDone)
            {
                var progress = Mathf.Clamp01(handle.Progress);
                onProgress?.Invoke(progress);
                EventDispatcher.Instance.Dispatch(new Scene_LoadProgressEvent
                {
                    SceneId = sceneId,
                    Progress = progress
                });
                await UniTask.Yield();
            }

            if (handle == null || !handle.IsValid || handle.Status != EOperationStatus.Succeeded)
            {
                var error = handle != null && handle.IsValid ? handle.Error : "invalid scene handle";
                DispatchLoadFailed(sceneId, isMainScene, error);
                DebugLogger.LogError(LogWriter.SceneManager, $"Failed to load scene by YooAsset AssetsManager: {sceneInfo.ScenePath}, {error}");
                return false;
            }

            _sceneHandles[sceneId] = handle;

            // 加载完成，进度为1
            onProgress?.Invoke(1f);
            EventDispatcher.Instance.Dispatch(new Scene_LoadProgressEvent
            {
                SceneId = sceneId,
                Progress = 1f
            });

            // 创建场景脚本
            CreateSceneScript(sceneInfo, sceneData);

            // 通知加载完成
            EventDispatcher.Instance.Dispatch(new Scene_LoadCompleteEvent
            {
                SceneId = sceneInfo.SceneId,
                IsMainScene = isMainScene
            });

            return true;
        }

        private async UniTask UnloadNativeSceneAsync(SceneInfo sceneInfo)
        {
            if (!_sceneHandles.TryGetValue(sceneInfo.SceneId, out var handle))
            {
                return;
            }

            await AssetsManager.Instance.UnloadSceneAsync(handle);
            _sceneHandles.Remove(sceneInfo.SceneId);
        }

        private void RunSceneOperation(UniTask operation, string sceneId, bool isMainScene)
        {
            RunSceneOperationAsync(operation, sceneId, isMainScene).Forget();
        }

        private async UniTaskVoid RunSceneOperationAsync(UniTask operation, string sceneId, bool isMainScene)
        {
            try
            {
                await operation;
            }
            catch (Exception e)
            {
                DebugLogger.LogError(LogWriter.SceneManager, $"Scene operation failed: {sceneId}, {e}");
                if (!string.IsNullOrEmpty(sceneId))
                    DispatchLoadFailed(sceneId, isMainScene, e.Message);
            }
        }

        private void DispatchLoadFailed(string sceneId, bool isMainScene, string error)
        {
            EventDispatcher.Instance.Dispatch(new Scene_LoadFailedEvent
            {
                SceneId = sceneId,
                IsMainScene = isMainScene,
                Error = error
            });
        }

        #endregion
    }
}
