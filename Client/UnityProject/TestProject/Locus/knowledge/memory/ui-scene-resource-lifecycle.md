---
id: kd_8f8435a4-96f6-4288-8dde-80691558a9d2
type: memory
path: ui-scene-resource-lifecycle.md
title: ui-scene-resource-lifecycle
inheritInjectMode: true
summaryEnabled: true
commandEnabled: false
readOnly: false
inheritAiConfig: true
createdAt: 1779262546081
updatedAt: 1781145438784
---

# ui-scene-resource-lifecycle

## Summary
UIWindow 与 SceneBase 的资源加载接口和生命周期组释放约定。

<!-- locus:body:start -->
- `Assets/Scripts/Fuel/Manager/UIManager/UIWindow.cs` 提供受保护资源加载接口：`LoadAssetSync<T>`、`LoadAssetAsync<T>`、`LoadAssetAuto<T>`、`ReleaseAsset`、`ReleaseAssetsByGroup`，窗口侧不直接引用 `AssetsLoadManager`，而是统一委托 `UIManager.Instance.ResourceManager`。
- `LoadAssetAuto<T>(path, groupName)` 根据 `AssetsLoadManager.UseAsyncLoad` 全局开关决定同步/异步加载；切换使用 `AssetsLoadManager.SetUseAsyncLoad(bool enabled)`。
- `UIWindow.AssetsGroupName` 默认使用 `WindowId`；`OnRelease()` 会调用 `UIResourceManager.ReleaseWindow(this, ViewObject)`，通过窗口资源组释放资源并从 UI 缓存移除。
- `Assets/Scripts/Fuel/Manager/UIManager/UIResourceManager.cs` 是 UI 资源访问入口，内部调用 `Fuel.AssetManager.AssetsLoadManager` 的加载、按组释放和单资源释放接口。
- `Assets/Scripts/Fuel/Manager/SceneManager/Data/SceneBase.cs` 提供同样的受保护资源加载接口。
- `SceneBase.AssetsGroupName` 默认使用 `SceneInfo?.SceneId`；`OnExit()` 默认调用 `ReleaseAssetsByGroup()`，通过组名释放场景资源。
- 子类如需共享或自定义资源组，可覆写 `AssetsGroupName` 或在加载接口中显式传入 `groupName`。
<!-- locus:body:end -->
