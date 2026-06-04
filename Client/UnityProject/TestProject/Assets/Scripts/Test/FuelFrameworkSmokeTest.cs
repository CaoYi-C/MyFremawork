using System;
using System.Collections.Generic;
using Cysharp.Threading.Tasks;
using Fuel.GameEvent;
using Fuel.LocalData;
using Fuel.Pools;
using Fuel.Scene;
using Fuel.Tools;
using Game.UI.TestPanel;
using Fuel.AssetManager;
using Manager.SceneManager;
using Manager.UIManager;
using UnityEngine;
using UnityEngine.Profiling;
using UnityEngine.SceneManagement;
using FuelSceneManager = Manager.SceneManager.SceneManager;

public sealed class FuelFrameworkSmokeTest : MonoBehaviour
{
    [SerializeField] private string testPanelPrefabPath = "TestPanel";
    [SerializeField] private string testScenePath = "SampleScene";
    [SerializeField] private int leakTestIterations = 100;
    [SerializeField] private int sceneLeakTestIterations = 20;
    [SerializeField] private long managedMemoryToleranceBytes = 4 * 1024 * 1024;
    [SerializeField] private bool runOnStart;

    private bool _isRunning;
    private readonly List<string> _results = new List<string>();

    private void Start()
    {
        DontDestroyOnLoad(gameObject);
        if (runOnStart)
            RunAll().Forget();
    }

    private void OnGUI()
    {
        const int width = 520;
        if (GUI.Button(new Rect(10, 10, 160, 35), _isRunning ? "Running..." : "Run Fuel Smoke Test") && !_isRunning)
            RunAll().Forget();
        if (GUI.Button(new Rect(180, 10, 180, 35), _isRunning ? "Running..." : "Run Leak Loop Test") && !_isRunning)
            RunLeakLoopOnly().Forget();

        GUI.Box(new Rect(10, 55, width, Mathf.Min(Screen.height - 65, 520)), string.Join("\n", _results));
    }

    private async UniTaskVoid RunAll()
    {
        _isRunning = true;
        _results.Clear();
        Log("Fuel framework smoke test started.");

        await RunStep("LocalData", TestLocalData);
        await RunStep("EventDispatcher", TestEventDispatcher);
        await RunStep("TimerManager", TestTimerManager);
        await RunStep("ObjectPools", TestObjectPools);
        await RunStep("UI prefab/window", TestUI);
        await RunStep("Scene load/unload", TestSceneLoadUnload);
        await RunStep("Resource leak loop", TestResourceLeakLoop);

        Log("Fuel framework smoke test finished.");
        _isRunning = false;
    }

    private async UniTaskVoid RunLeakLoopOnly()
    {
        _isRunning = true;
        _results.Clear();
        Log("Fuel resource leak loop test started.");
        await RunStep("Resource leak loop", TestResourceLeakLoop);
        Log("Fuel resource leak loop test finished.");
        _isRunning = false;
    }

    private async UniTask RunStep(string name, Func<UniTask> step)
    {
        try
        {
            await step();
            Log($"PASS {name}");
        }
        catch (Exception e)
        {
            Log($"FAIL {name}: {e.Message}");
            Debug.LogException(e);
        }
    }

    private UniTask TestLocalData()
    {
        var manager = LocalDataManager.Instance;
        string key = "FuelSmokeTest_LocalData";

        manager.SetStorageType(LocalDataStorageType.JsonFile);
        manager.SetEncryption(false);
        manager.Delete(key);
        manager.SaveStringDeferred(key, "deferred-value");
        Assert(manager.HasPendingSaves, "deferred save flag not set");
        manager.FlushPendingSaves();
        Assert(!manager.HasPendingSaves, "deferred save flag not cleared");
        Assert(manager.TryLoadString(key, out string loaded) && loaded == "deferred-value", "deferred value load failed");

        manager.SetEncryption(true, "FuelSmokeTestKey");
        manager.SaveString(key, "encrypted-value");
        Assert(manager.TryLoadString(key, out loaded) && loaded == "encrypted-value", "encrypted value load failed");
        manager.Delete(key);
        manager.SetEncryption(false);
        return UniTask.CompletedTask;
    }

    private UniTask TestEventDispatcher()
    {
        int firstCount = 0;
        int secondCount = 0;
        Action<SmokeEvent> second = _ => secondCount++;
        Action<SmokeEvent> first = null;
        first = _ =>
        {
            firstCount++;
            EventDispatcher.Instance.Unregister(first);
            EventDispatcher.Instance.Register(second);
        };

        EventDispatcher.Instance.Clear<SmokeEvent>();
        EventDispatcher.Instance.Register(first);
        EventDispatcher.Instance.Dispatch(new SmokeEvent());
        EventDispatcher.Instance.Dispatch(new SmokeEvent());
        EventDispatcher.Instance.Clear<SmokeEvent>();

        Assert(firstCount == 1, "handler remove during dispatch failed");
        Assert(secondCount == 1, "handler add during dispatch failed");
        return UniTask.CompletedTask;
    }

    private UniTask TestTimerManager()
    {
        var timer = new TimerManager();
        int repeatCount = 0;
        int cancelledCount = 0;
        timer.Repeat(() => repeatCount++, 0.1f, 3);
        int cancelId = timer.Repeat(() => cancelledCount++, 0.1f, -1);
        timer.RemoveTimer(cancelId);
        timer.Update(0.35f);

        Assert(repeatCount == 3, $"repeat timer expected 3, got {repeatCount}");
        Assert(cancelledCount == 0, "cancelled timer executed");
        timer.ClearAll();
        return UniTask.CompletedTask;
    }

    private UniTask TestObjectPools()
    {
        var item = ObjectPools.Instance.Get<SmokePoolItem>();
        item.Value = 10;
        Assert(ObjectPools.Instance.Recycle(item), "pool recycle failed");
        Assert(!ObjectPools.Instance.Recycle(item), "repeated recycle should be rejected");
        var reused = ObjectPools.Instance.Get<SmokePoolItem>();
        Assert(reused.Value == 0, "pooled item was not cleared");
        ObjectPools.Instance.Recycle(reused);
        return UniTask.CompletedTask;
    }

    private async UniTask TestUI()
    {
#if UNITY_EDITOR
        await AssetsManager.Instance.EnsureYooAssetInitializedAsync();
#endif
        var manager = UIManager.Instance;
        manager.RegisterWindow("TestPanel", testPanelPrefabPath, _ => new TestPanelWindow());

        var window = manager.OpenWindow("TestPanel") as TestPanelWindow;
        Assert(window != null, "window open returned null");
        Assert(window.ViewObject != null, "UI prefab instance was not created");
        Assert(window.ViewObject.transform.parent == manager.GetLayerRoot(UILayer.Normal), "UI prefab parent layer incorrect");
        Assert(window.Nodes != null, "TestPanelNodeProvider not bound");

        var oldView = window.ViewObject;
        manager.ReloadWindow(window.WindowId);
        Assert(window.ViewObject != null && window.ViewObject != oldView, "window reload did not recreate view");

        manager.CloseWindow(window.WindowId);
        Assert(!window.IsShow, "window close did not hide window");
        window.OnRelease();
        manager.ResourceManager.UnregisterWindow(window.WindowId);
        manager.ResourceManager.ReleasePrefab(window.WindowId);
    }

    private async UniTask TestSceneLoadUnload()
    {
        const string sceneId = "FuelSmokeTest_AdditiveScene";
        await LoadAndUnloadSmokeScene(sceneId);
    }

    private async UniTask TestResourceLeakLoop()
    {
#if UNITY_EDITOR
        await AssetsManager.Instance.EnsureYooAssetInitializedAsync();
#endif
        var manager = UIManager.Instance;
        manager.RegisterWindow("TestPanel", testPanelPrefabPath, _ => new TestPanelWindow());

        await ForceUnloadUnusedAssets();
        int baselineObjects = Resources.FindObjectsOfTypeAll<GameObject>().Length;
        long baselineManaged = GC.GetTotalMemory(true);
        long baselineMono = Profiler.GetMonoUsedSizeLong();
        long baselineTotal = Profiler.GetTotalAllocatedMemoryLong();

        for (int i = 0; i < leakTestIterations; i++)
        {
            var window = manager.OpenWindow("TestPanel") as TestPanelWindow;
            Assert(window != null, "leak loop window open returned null");
            Assert(window.ViewObject != null, "leak loop UI prefab instance was not created");
            manager.CloseWindow(window.WindowId);
            window.OnRelease();
            manager.ResourceManager.UnregisterWindow(window.WindowId);
            manager.ResourceManager.ReleasePrefab(window.WindowId);
            await UniTask.Yield();
        }

        if (CanRunSceneLeakLoop())
        {
            for (int i = 0; i < sceneLeakTestIterations; i++)
            {
                await LoadAndUnloadSmokeScene($"FuelSmokeTest_LeakScene_{i}");
                await UniTask.Yield();
            }
        }
        else
        {
            Log($"SKIP Scene leak loop: active scene is {testScenePath}; run from another scene to test repeated scene load/unload.");
        }

        await ForceUnloadUnusedAssets();
        int afterObjects = Resources.FindObjectsOfTypeAll<GameObject>().Length;
        long afterManaged = GC.GetTotalMemory(true);
        long afterMono = Profiler.GetMonoUsedSizeLong();
        long afterTotal = Profiler.GetTotalAllocatedMemoryLong();
        long managedDelta = afterManaged - baselineManaged;

        Log($"Leak loop UI x{leakTestIterations}, Scene x{(CanRunSceneLeakLoop() ? sceneLeakTestIterations : 0)}: GameObjects {baselineObjects}->{afterObjects}, managed {FormatBytes(baselineManaged)}->{FormatBytes(afterManaged)} delta {FormatBytes(managedDelta)}, mono {FormatBytes(baselineMono)}->{FormatBytes(afterMono)}, total {FormatBytes(baselineTotal)}->{FormatBytes(afterTotal)}");
        Assert(afterObjects <= baselineObjects + 2, $"GameObject count increased: {baselineObjects}->{afterObjects}");
        Assert(managedDelta <= managedMemoryToleranceBytes, $"managed memory increased too much: {FormatBytes(managedDelta)}");
    }

    private bool CanRunSceneLeakLoop()
    {
        var activeScene = UnityEngine.SceneManagement.SceneManager.GetActiveScene();
        return activeScene.path != testScenePath && activeScene.name != testScenePath;
    }

    private async UniTask LoadAndUnloadSmokeScene(string sceneId)
    {
        var activeScene = UnityEngine.SceneManagement.SceneManager.GetActiveScene();
        if (activeScene.path == testScenePath || activeScene.name == testScenePath)
        {
            Log($"SKIP Scene load/unload: active scene is already {testScenePath}; run this from another scene to avoid unloading the active scene.");
            return;
        }

        var manager = FuelSceneManager.Instance;
        manager.RegisterScene(new SceneInfo
        {
            SceneId = sceneId,
            SceneName = "Fuel Smoke Test Additive Scene",
            ScenePath = testScenePath,
            IsMainScene = false
        });
        manager.RegisterSceneScript<SmokeSceneScript>(sceneId);

        bool loaded = false;
        bool unloaded = false;
        manager.LoadAdditiveScene(sceneId, null, null, () => loaded = true);
        await UniTask.WaitUntil(() => loaded || !manager.IsLoading).Timeout(TimeSpan.FromSeconds(10));
        Assert(loaded, "scene load callback not invoked");
        Assert(manager.IsSceneLoaded(sceneId), "scene script not registered after load");
        Assert(manager.GetSceneScript<SmokeSceneScript>(sceneId) != null, "scene script type lookup failed");

        manager.UnloadScene(sceneId, () => unloaded = true);
        await UniTask.WaitUntil(() => unloaded).Timeout(TimeSpan.FromSeconds(10));
        Assert(!manager.IsSceneLoaded(sceneId), "scene still marked loaded after unload");
    }

    private static async UniTask ForceUnloadUnusedAssets()
    {
        await Resources.UnloadUnusedAssets().ToUniTask();
        GC.Collect();
        GC.WaitForPendingFinalizers();
        GC.Collect();
        await UniTask.Yield();
    }

    private static string FormatBytes(long bytes)
    {
        return $"{bytes / 1048576f:F2} MB";
    }

    private void Log(string message)
    {
        _results.Add(message);
        Debug.Log($"[FuelFrameworkSmokeTest] {message}");
    }

    private static void Assert(bool condition, string message)
    {
        if (!condition)
            throw new InvalidOperationException(message);
    }

    private sealed class SmokeEvent : IEventMessage
    {
    }

    private sealed class SmokePoolItem : IObjectPool
    {
        public int Value;

        public void Clear()
        {
            Value = 0;
        }

        public void Disposable()
        {
            Clear();
        }
    }

    private sealed class SmokeSceneScript : SceneBase
    {
        public override void OnEnter(SceneData sceneData)
        {
            if (ViewObject == null)
                throw new InvalidOperationException("scene root was not injected");
        }
    }
}
