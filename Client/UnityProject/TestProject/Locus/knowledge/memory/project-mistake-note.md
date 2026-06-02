---
id: kd_builtin_memory_project_mistake_note
type: memory
path: project-mistake-note.md
title: project-mistake-note
injectMode: full
summaryEnabled: false
summaryCache: project-mistake-note
commandEnabled: false
readOnly: false
aiMaintained: true
explicitMaintenanceRules: true
createdAt: 1778427694230
updatedAt: 1780367172301
---

# project-mistake-note

<!-- locus:maintain-rules:start -->
Record only verified problems, rework causes, and avoidance steps
Prioritize recurring pitfalls, constraints, regression points, and confirmed fixes
Keep each entry short and focused on one lesson or constraint
Keep the list within 20 items and merge duplicates regularly
Remove outdated issues, non-reproducible issues, and unsupported guesses
<!-- locus:maintain-rules:end -->

<!-- locus:body:start -->
- `LocalDataManager` 继承非 MonoBehaviour 的 `Singleton<T>`，不能添加 `OnApplicationPause` 或 override `OnApplicationQuit`；退出刷新应使用 `Application.quitting` 注册。
- YooAsset 版本的下载进度事件类型是 `DownloadProgressChangedEventArgs`，不要误用旧/其他版本的 `DownloadUpdateData`。
- `GameObjectPool.InitSync/InitAsync` 必须校验 YooAsset `AssetHandle` 有效且成功后再 `InstantiateSync/Async`；加载地址无效时直接实例化会触发空引用。
<!-- locus:body:end -->
