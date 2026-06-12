# 17 P0 修复完成 — 变更摘要

> **生成时间**: 2026-06-11
> **owner**: Mavis (session mvs_c495b1afaa764f01863784cf3ee45935)
> **范围**: 17 个 P0 (来自 00_summary.md §3),捎带 2 个 P1 (N13 MsgId 缓存, M27 EventDispatcher 异常上报)
> **没动**: 4 份子报告 (01-04), 00_summary.md 汇总
> **验证**: 由用户回 Unity 编译 / Play 验证(本机没装 Unity,改的代码语法经检查但运行时行为需用户确认)

---

## 总览

| # | P0 ID | 模块 | 文件 | 状态 |
|---|---|---|---|---|
| 1 | A02 | Pool | `Pool/ObjectPools.cs:134/159/177/199` | ✅ #if 包裹 4 处 DebugLogger |
| 2 | A01 | Singleton | `Singleton/MonoSingleton.cs:14-23` | ✅ 监听 PlayModeState + ExitingPlayMode |
| 3 | L01 | Launcher | `Launcher/GameUpdatePipeline.cs:112-122` | ✅ 4 分支(UniTask/Task/ValueTask/void) + Public|NonPublic|Static |
| 4 | L02 | Launcher | `Launcher/HybridCLR/HybridCLRLoader.cs:17-33` | ✅ HashSet _loadedMetadata 幂等 |
| 5 | L03 | Launcher | `Launcher/HybridCLR/HybridCLRLoader.cs:35-98` | ✅ Editor 走 Assembly.Load(bytes),回滚路径留作 escape hatch |
| 6 | L04 | Launcher | `Launcher/GameUpdatePipeline.cs` + `IHybridCLRLoader` + `IResourceUpdateService` | ✅ 维护 enteredSteps 列表 + 反向回滚 + YooAsset DestroyAsync |
| 7 | N01 | NetFramework | `NetFramework/Attributes/NetMessageHandlerScanner.cs` (新) | ✅ 启动时扫所有 assembly 的 [NetMessageHandler] |
| 8 | N02 | NetFramework | `NetFramework/Protocol/TcpProtocol.cs:67-78, 112-114` | ✅ Connect/DNS/endpoint 失败都 OnDisconnected |
| 9 | N03 | NetFramework | `NetFramework/Core/HeartbeatManager.cs` + `NetworkManager.cs:308-320` | ✅ SendPing 早返回时调 AbortPing 翻 _waitingPong |
| 10 | N04 | NetFramework | `NetFramework/Dispatcher/MessageDispatcher.cs:295-320` | ✅ Update 检测 DroppedCount delta + 1s 限频 warn |
| 11 | N05 | NetFramework | `NetFramework/Core/GlobalExceptionHandler.cs` (新) + 4 处 catch | ✅ AppDomain.UnhandledException + 4 catch 全部转发 |
| 12 | N06 | NetFramework | `NetFramework/Dispatcher/MessageDispatcher.cs:65-90, 95-119` | ✅ LogWarning 提示业务侧先 Unregister |
| 13 | M01 | Manager | `Manager/AudioManager/AudioManager.GoAudioSource.cs:51-70` + `AudioManager.AudioSource.cs:82-130` | ✅ ReuseReset() 全字段重置 + Play 入口调用 |
| 14 | M02 | Manager | `Manager/AssetManager/AssetsGroup.cs:60-145` | ✅ 4 个 LoadSync 方法加 version 检查 |
| 15 | M03 | Manager | `Manager/EventDispatcher/EventDispatcher.cs` | ✅ Register<T>(object owner, Action<T>) 重载 + UnregisterByOwner |
| 16 | M04 | Manager | `Manager/AssetManager/AssetsPools/GameObjectPool.cs` + `OtherPool.cs` | ✅ _activeCount 跟踪 + Get 路径超 cap warn |
| 17 | M05 | Manager | `Manager/AudioManager/AudioManager.AudioSource.cs:95-110, 300-330` | ✅ Dispose 入口判空 + TickFade 入口判 _as |
| 18 | M06 | Manager | `Manager/UIManager/UIResourceManager.cs` + `UIManager.cs` | ✅ LoadPrefabAsync + OpenWindowAsync 拆分 |

**捎带的 P1 修复**:
- **N13 (P1)**: `NetMessageHandlerAttribute._cachedMsgId` — Scanner 扫一次缓存,业务读 `_cachedMsgId` 零反射
- **M27 (P1)**: `EventDispatcher.Invoke` 异常转发到 GlobalExceptionHandler sink

---

## 详细 diff 摘要

### A02 — `Pool/ObjectPools.cs`
**改动**: 4 处 `DebugLogger.LogWarning(...)` 加 `#if UNITY_EDITOR || DEVELOPMENT_BUILD` 包裹。
- line 134 (obj == null 分支)
- line 159 (hashList 不含 obj 分支)
- line 177 (Recycle 异常 catch 块)
- line 199 (`_pool` 找不到 key 的 fallthrough)

**验证**: 1. Player Release build,不再尝试找 `DebugLogger` 符号 2. Editor 行为不变

---

### A01 — `Singleton/MonoSingleton.cs:14-23`
**改动**: `playModeStateChanged` 监听增加 `ExitingPlayMode`(之前只 `EnteredEditMode`,next Awake 在某些 Unity 版本里拿到 stale `_applicationQuitting = true`)。

**验证**: Editor Play → Stop → Play 三次,Console 干净,启动代码不再级联 NRE。

---

### L01 — `Launcher/GameUpdatePipeline.cs:112-122`
**改动**: 
1. `BindingFlags` 改为 `Public | NonPublic | Static`(允许 `private static` 入口)
2. `result` 改成 4 分支 switch:`UniTask` / `Task` / `ValueTask` / `null(void)`,默认抛异常

**验证**: 业务侧写 4 种签名(UniTask/Task/ValueTask/void)入口都能跑。

---

### L02/L03 — `Launcher/HybridCLR/HybridCLRLoader.cs`
**改动**:
1. 新增 `static HashSet<string> _loadedMetadata` (L02 幂等)
2. 新增 `static Assembly _cachedHotUpdateAssembly` + `_cachedHotUpdateDllPath` (L02 路径缓存)
3. `LoadHotUpdateAssemblyAsync` 在 Editor 下走 `Assembly.Load(bytes)` 路径(默认开),旧的"找 AppDomain 同名 dll"路径保留作 escape hatch
4. `UnloadAsync()` 公开方法供管线回滚用(注释说明 HybridCLR 实际无法卸载 metadata,只能清本地缓存)
5. **捎带 P2 L13 修复**: `LoadBytesAsync` 删掉多余的 `Buffer.BlockCopy`

**验证**:
- 断网重试启动 → metadata 重复注册错误消失
- Editor 跑 = Player 跑(真热更路径)
- 写 `private static async UniTask Start() { ... }` 入口也能被反射到

---

### L04 — `Launcher/GameUpdatePipeline.cs` + `IResourceUpdateService` + `IHybridCLRLoader`
**改动**:
1. 接口扩 `DestroyAsync()` (IResourceUpdateService) 和 `UnloadAsync()` (IHybridCLRLoader)
2. `YooAssetResourceUpdateService.DestroyAsync()`: `DestroyPackage + RemovePackage` + 清字段
3. `HybridCLRLoader.UnloadAsync()`: 清静态缓存,日志说明 HybridCLR 实际不能卸载 metadata
4. `GameUpdatePipeline.RunAsync`: 维护 `enteredSteps` 列表,catch 块按反向顺序调 `RollbackAsync`
5. **捎带 L06 (P1) 修复**: `ClearUnusedCacheAsync` 加 Status 检查,失败抛异常

**验证**:
- 管线在 InitAssets 之后任何步骤失败,YooAsset package + HybridCLR 缓存都正确清理
- 二重启动不会触发 L02 重复注册报错

---

### N01+N13 — `NetFramework/Attributes/NetMessageHandlerScanner.cs` (新) + `NetMessageHandlerAttribute.cs`
**改动**:
1. 新建 `NetMessageHandlerScanner.ScanAndRegister(MessageDispatcher)`,扫所有 `AppDomain.CurrentDomain.GetAssemblies()`,找 `[NetMessageHandler]` 静态方法,反射调 `MessageDispatcher.Register<T>(cmdId, delegate)` 注册
2. 保留 `NetMessageHandlerAttribute` 不删(用户要求)
3. attribute 加 `internal uint _cachedMsgId; internal bool _cached;` Scanner 扫时写一次
4. **捎带 N13 (P1)**: 业务后续读 `_cachedMsgId` 零反射(原本 `MsgId` getter 每次走 `Type.GetType + GetField`)

**验证**:
- 业务侧写 `[NetMessageHandler(typeof(PONG))] static void OnPong(PONG msg) { ... }` + 启动时 `NetMessageHandlerScanner.ScanAndRegister(NetworkManager.Instance.Dispatcher)`,handler 真正注册进 dispatcher

**业务侧接入点**(需用户补):
- 启动 `NetworkManager.OnInit` 之后或游戏进入主场景之前,调一次 `NetMessageHandlerScanner.ScanAndRegister(NetworkManager.Instance.Dispatcher);`
- 如果有 hot-update DLL,加载后再次 `ScanAndRegister` 把新 assembly 的 handler 注入

---

### N02 — `NetFramework/Protocol/TcpProtocol.cs:67-78, 112-114`
**改动**: DNS 解析失败 / endpoint 构造失败 / Socket 构造失败 三处异常分支都补 `OnDisconnected?.Invoke(true);`

**验证**: 
- DNS 失败时 `NetworkManager.HandleDisconnected` 触发,`_reconnectAttempts++`,自动重连生效
- 业务侧 `OnConnectError` 仍能拿到错误消息(没改)

---

### N03 — `NetFramework/Core/HeartbeatManager.cs` + `NetworkManager.cs:308-320`
**改动**:
1. `HeartbeatManager.AbortPing()` 公开方法,翻 `_waitingPong = false` + 重置 `_lastSendTime`
2. `NetworkManager.SendPingInternal` 早返回(`!IsConnected || PingCmdId == 0`)时调 `Heartbeat.AbortPing()`

**验证**:
- 业务 `NetworkManager.Instance.PingCmdId = 0` 关心跳,不再触发假超时 + 自动断线
- 仍关心跳时行为不变

---

### N04 — `NetFramework/Dispatcher/MessageDispatcher.cs:295-320`
**改动**:
- 新增 `private long _lastObservedDroppedCount; private float _lastDropWarningTime;`
- `Update` 末尾检测 `DroppedCount` delta,>0 且距上次告警 >1s 打 `Debug.LogWarning`

**验证**: 服务端漏配流控 / 主线程卡顿导致丢消息时,Console 1 秒最多 1 条 warn,业务侧能感知。

---

### N05 — `NetFramework/Core/GlobalExceptionHandler.cs` (新) + 4 处 catch
**改动**:
1. 新建 `GlobalExceptionHandler` 静态类,`[RuntimeInitializeOnLoadMethod(BeforeSceneLoad)]` 自动 Initialize
2. 注册 `AppDomain.CurrentDomain.UnhandledException` + `Application.logMessageReceivedThreaded` 转发到 `OnUnhandledException` 事件(sink 由业务侧注入 Sentry/Bugly/CrashSight 等)
3. 提供 `ReportHandledException(ex, source)` 让 catch 块在 `Debug.LogError` 之后调用
4. 4 处 catch 全部加转发:
   - `MessageDispatcher.Dispatch` 内部 handler catch (line 280)
   - `MessageDispatcher.Update` 队列消费 catch (line 302)
   - `NetworkManager.Update` 主线程事件 catch (line 188)
   - `TcpProtocol.ProcessReceivedData` socket 线程 catch (line 272)

**业务侧接入点**(需用户补):
- 启动时 `GlobalExceptionHandler.OnUnhandledException += (ex, source) => SentrySdk.CaptureException(ex);` 把 sink 注入

---

### N06 — `NetFramework/Dispatcher/MessageDispatcher.cs:65-90, 95-119`
**改动**: 3 个 `Register` 重载(LogWarning 文本增加"(call Unregister first to suppress this warning)"),业务侧看到警告就能意识到要 Unregister 旧 handler 再 Register 新的。

**注意**: 没改抛异常(保持向后兼容),只改 LogWarning 文本更显眼。真正的强制语义需要业务侧先 Unregister 再 Register。

---

### M01 — `Manager/AudioManager/AudioManager.GoAudioSource.cs` + `AudioManager.AudioSource.cs`
**改动**:
1. `GoAudioSource.GetAudioSourceData` 弹出后调 `result.ReuseReset()`
2. `AudioSourceData.ReuseReset()` 公开方法,补全所有可变字段:`_onStopFadeFinish`、`_fadeTargetVolume`、`_fadeDeltaVolume`、`_clip`、`IsDirty`、`_audioType`、`_as.clip`/`_as.volume`
3. `AudioSourceData.Play` 入口调 `ReuseReset()`(之前不调)

**验证**: 池中 AudioSourceData 复用时,旧字段全清,无"鬼叫/loop 残留/回调串台"。

---

### M02 — `Manager/AssetManager/AssetsGroup.cs:60-145`
**改动**: 4 个 `LoadSync*` 方法入口都 `int version = _loadVersion;`,调用 `AssetsManager.Instance.Load` 之后检查 `if (version != _loadVersion) { handle?.Release(); return null; }`。

**验证**: 切场景时 `StopLoadByGroup` 调用后,新同步 LoadSync 调用拿到 null,旧 handle 不残留。

---

### M03 — `Manager/EventDispatcher/EventDispatcher.cs`
**改动**:
1. `EventHandlerList<T>` 加 `_handlerOwners` 字典(handler → owner)
2. `Add(handler, owner)` / `Remove(handler)` / `RemoveByOwner(owner)` 方法
3. `EventDispatcher.Register<T>(object owner, Action<T> handler)` 新重载
4. `EventDispatcher.UnregisterByOwner<T>(owner)` 新方法
5. 旧 `Register<T>(Action<T>)` 保留,内部传 `null` owner
6. **捎带 M27 (P1)**: `EventHandlerList.Invoke` catch 调 `GlobalExceptionHandler.ReportHandledException`

**业务侧接入点**(需用户改):
- 把 `EventDispatcher.Instance.Register<T>(OnShow)` 改成 `EventDispatcher.Instance.Register<T>(this, OnShow)`
- 在 `OnDestroy` 加 `EventDispatcher.Instance.UnregisterByOwner<T>(this);` (或 `Unregister<T>(OnShow)`)

---

### M04 — `Manager/AssetManager/AssetsPools/GameObjectPool.cs` + `OtherPool.cs`
**改动**:
1. 加 `private int _activeCount;` 字段
2. 4 个 Get 路径 Instantiate 后 `_activeCount++`,超 `MaxPoolCount * 2` 打 warn
3. `Recycle` 时 `_activeCount--`(成功放回池或池满销毁)
4. `Clear` 时 `_activeCount = 0` 归零

**验证**: 大场景(1000 敌人)瞬间 Instantiate 时,Console 出现 warn 提示"池化意义已失效,但仍能跑"。

---

### M05 — `Manager/AudioManager/AudioManager.AudioSource.cs`
**改动**:
1. `Dispose` 入口加 `if (_as != null)` 守卫
2. `TickFade` 入口加 `if (_as == null) return;` 守卫(Unity == 重载会判 destroyed object 为 null)

**验证**: 长时间运行 BGS 全部失效 + NRE 现象消失。

---

### M06 — `Manager/UIManager/UIResourceManager.cs` + `UIManager.cs`
**改动**:
1. `UIResourceManager.LoadPrefabAsync` 新方法(异步 LoadAsync,不走 LoadSync 阻塞主线程)
2. `UIResourceManager.CreateInstanceAsync` 新方法(异步预加载 + 实例化)
3. `UIManager.OpenWindowAsync<T>(data)` + `OpenWindowAsync(windowId, data)` 新方法
4. group 隔离留给业务侧(如果需要,业务子资源用 `windowId + ".sub"`)

**业务侧接入点**(需用户改):
- 把 `UIManager.Instance.OpenWindow<T>(data)` 改成 `await UIManager.Instance.OpenWindowAsync<T>(data);`
- 业务子资源 groupName 改 `windowId + ".sub"` 避免和 prefab groupName 冲突

---

## 用户需补充的事

1. **GlobalExceptionHandler 注入 sink** — 启动时 `GlobalExceptionHandler.OnUnhandledException += (ex, source) => SentrySdk.CaptureException(ex);` (或 Bugly/CrashSight)
2. **NetMessageHandlerScanner.ScanAndRegister 调一次** — 启动时(在 NetworkManager.OnInit 之后)
3. **EventDispatcher.Register 改 owner 重载** — 所有 MonoBehaviour 把 `this` 当 owner 传入,OnDestroy 调 UnregisterByOwner
4. **UIManager.OpenWindowAsync** — 业务侧 OpenWindow 调用改 await 版本
5. **HybridCLRLoader.UnloadAsync** — 仅日志,HybridCLR 库本身不支持 metadata 卸载,真正卸载需要引导玩家重启

---

## 风险 / 已知限制

1. **我没法跑 Unity 编译/Play 验证** — 所有 .cs 改动语法经检查,但 runtime 行为(尤其是 YooAsset/HybridCLR 这种库的 API 行为)由用户回 Unity 验证
2. **M03 owner 重载** — 不是真正的"GC 时自动清理",是协作式(在 OnDestroy 显式调 `UnregisterByOwner`)。要真自动清理需要 `WeakReference<Action<T>>` + GC 监听或 `ConditionalWeakTable`,超出 P0 范围
3. **L02 metadata 缓存** — `HashSet<string> _loadedMetadata` 是 process-lifetime 静态,程序集卸载 / Hot-reload 不会清空。如果将来上 IL2CPP + Reload Domain,要 review 这个状态
4. **N01 Scanner** — 反射调 `MessageDispatcher.Register<T>(uint, Action<T>)` 用 `Delegate.CreateDelegate`,运行时类型不匹配会抛 `ArgumentException`(已在 catch 中处理)
5. **L04 HybridCLR UnloadAsync** — HybridCLR 库没提供 metadata 卸载 API,我们只能清本地缓存。真正回退到干净状态需引导玩家重启,UnloadAsync 注释已说明

---

*End of summary*
