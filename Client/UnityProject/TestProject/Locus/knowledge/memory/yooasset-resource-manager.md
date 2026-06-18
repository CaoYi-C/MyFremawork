---
id: kd_d3191568-9359-48b0-9e65-a27fafcdf79e
type: memory
path: yooasset-resource-manager.md
title: yooasset-resource-manager
inheritInjectMode: true
summaryEnabled: true
commandEnabled: false
readOnly: false
aiMaintained: true
explicitMaintenanceRules: true
createdAt: 1779242958684
updatedAt: 1781748296865
---

# yooasset-resource-manager

## Summary
YooAsset 桥接资源管理层的位置、初始化方式、主要接口；项目运行时资源加载地址统一使用资源名/文件名，不使用完整路径；Scene/UI 资源生命周期约束。

<!-- locus:maintain-rules:start -->
Record verified resource-management architecture and usage constraints. Keep entries concise and update when API or initialization flow changes.
<!-- locus:maintain-rules:end -->

<!-- locus:body:start -->
- 项目已接入 `com.tuyoogame.yooasset` 3.0.1-beta。
- 桥接层当前位于 `Assets/Scripts/Fuel/Manager/AssetManager/AssetsManager.cs`，命名空间 `HotFarmework.AssetManager`，继承现有 `Singleton<T>`。
- `AssetsManager` 默认包名为 `Main`，与 `Assets/Resources/StartupConfig.json` 和 `LocalStartupConfig.packageName` 保持一致。
- 初始化流见 `Assets/Scripts/Fuel/Launcher/Resources/YooAssetResourceUpdateService.cs`，启动时会初始化 YooAssets 与资源包。
- 编辑器烟测或未走启动更新管线时，SceneManager Core Loading 会在 `UNITY_EDITOR` 下通过 `AssetsManager.Instance.EnsureYooAssetInitializedAsync()` 懒初始化 YooAsset；测试 UI 加载前也需要初始化，避免 `YooAssets is not initialized`。
- 当前 `Assets/BundleCollectorSetting.asset` 的 Main 包启用 `SupportExtensionless`，且 UIPrefab 使用 `AddressByFileName`，运行时地址可使用文件名形式，例如 `TestPanel`。
- 当前项目 YooAsset 使用可寻址加载约定：凡是运行时资源加载地址都优先使用资源名/文件名，不使用完整 `Assets/...` 路径；例如 HOT/AOT DLL 记录文件只记录 `xxx.dll.bytes` 名称，加载时也按名称传给 YooAsset。
- 当前 Scene 收集路径是 `Assets/Scenes`，运行时可被 YooAsset 地址解析的烟测场景是 `Test`；`Assets/AssetsPackage/Main/Scene/SampleScene.unity` 当前不在 Scene 收集器内，`SampleScene` 会解析失败。
- `AssetsManager` 主资源接口包括同步/异步加载资源、子资源加载、`LoadSceneAsync`、`UnloadSceneAsync(SceneHandle)`、`RemoveUnusedAssets`。
- YooAsset 场景加载应保留 `SceneHandle`，卸载通过该 handle 的 `UnloadSceneAsync()`；不要再用 Unity 原生 `SceneManager.UnloadSceneAsync` 卸载由 YooAsset 加载的场景。
- `Assets/Scripts/Fuel/Manager/SceneManager/SceneManager.Loading.cs` 的 Core Loading 当前通过 `AssetsManager.Instance.LoadSceneAsync` 加载场景，并用 `_sceneHandles` 缓存 `YooAsset.SceneHandle` 供卸载。
- `Assets/Scripts/Fuel/Manager/UIManager/UIResourceManager.cs` 已移除 `Resources.Load` 与本地 prefab 缓存，UI prefab 现在通过 `AssetsLoadManager.Instance.LoadSync<GameObject>(path, windowId)` 获取实例，并用窗口 ID 作为资源组释放。
- `Assets/Scripts/Test/FuelFrameworkSmokeTest.cs` 包含 Resource leak loop 烟测：默认循环 UI 打开/关闭 100 次、场景加载/卸载 20 次，并在 `Resources.UnloadUnusedAssets` 与 GC 后对比 GameObject 数量和托管内存增量。
<!-- locus:body:end -->
