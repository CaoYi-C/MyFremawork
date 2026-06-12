---
id: kd_eca5d94f-f5e2-4364-9608-992bd7a02251
type: memory
path: fuel-code-review.md
title: fuel-code-review
inheritInjectMode: true
summaryEnabled: true
commandEnabled: false
readOnly: false
inheritAiConfig: true
createdAt: 1781143188939
updatedAt: 1781249549868
---

# fuel-code-review

## Summary
Fuel static-review status: fixed YooAsset TextAsset handle leaks, protocol event threading and socket callback races, MessageDispatcher handler locking, AssetsGroup async cancellation, AssetsManager handle validation, GameObjectPool/OtherPool load-failure handling, AssetsGroupManager cleanup, LocalData atomic writes, SceneManager load failure reporting, and AudioManager now loading/releasing clips through AssetsLoadManager by direct YooAsset address/name.

<!-- locus:body:start -->
# Fuel code review status

Observed and fixed during static review of `Assets/Scripts/Fuel`:
- `HybridCLRLoader.LoadBytesAsync` and `TableKitConfigLoader.LoadTableAsync` copy `TextAsset` content and release YooAsset handles in `finally`.
- `PacketCodec.Decode` provides independent packet body arrays; `TcpProtocol` queues protocol events, and `IProtocol.Update` is driven by `NetworkManager.Update`, avoiding direct socket-thread business callbacks.
- `TcpProtocol` socket callbacks now pass and validate the callback-owned `Socket` via `AsyncState`; disconnect is guarded so stale callbacks from old sockets cannot close a newer connection.
- `MessageDispatcher._handlers` is protected by `_handlersLock` for register/dispatch/unregister/clear.
- `AssetsGroup` async loads no longer increment `_loadVersion` per request; `Init/StopLoad/Clear` remain cancellation boundaries, so same-group parallel loads no longer cancel each other.
- `AssetsManager` validates YooAsset `AssetHandle`/`SubAssetsHandle` status for sync and async asset loads; failed loads release handles and return null instead of caching invalid handles.
- `GameObjectPool.GetSync` returns null when `InitSync` fails instead of calling `_baseHandle.InstantiateSync()`.
- `OtherPool<T>.InitSync/InitAsync` now return false when base asset loading fails, and `GetSync/GetAsync` return null instead of instantiating a null base.
- `AssetsGroupManager.Init` initializes Destroy/Dispose events, subscribes `Application.quitting`, and exposes explicit `Clear/Dispose`.
- `LocalDataManager` file storage now writes to `.tmp` then atomically replaces/moves into the final save path.
- `SceneManager.Loading` wraps fire-and-forget scene operations in `RunSceneOperation`, logs exceptions, and dispatches `Scene_LoadFailedEvent` on load failure.
- `AudioManager` now loads audio clips by direct YooAsset address/name via `AssetsLoadManager.Instance.LoadSync<AudioClip>(clipName, "AudioManager")` and releases cached clips through `AssetsLoadManager.Instance.Recycle` / `ReleaseAllByGroup`, rather than `Resources.Load` / `Resources.UnloadAsset`.

Still worth checking later:
- `AssetsLoadManager`/pool lifecycle is still partly based on non-MonoBehaviour `Singleton<T>` patterns; newly added explicit cleanup reduces exit leaks, but broader lifecycle ownership can be simplified later.
- `AudioClipPools` currently routes through `InstantiatePools<AudioClip>`; if cloned `AudioClip` instances are undesirable, switch audio clips to a reference-style pool.
<!-- locus:body:end -->
