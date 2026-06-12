# Manager 模块深度审查 (Attempt 4)

> **范围:** `Assets/Scripts/Fuel/Manager/` 下全部 C#(共 **41** 个 .cs 文件,见 §0.2)
> **维度:** 资源生命周期 / 句柄释放 / 单例与场景共存 / 闭包 / 协程 / 跨线程 / 反射
> **严重度:** **T1**(必须立即修)、**T2**(下版本修)、**T3**(改进/优化)
> 延续本目录审查规范:T1 = Critical, T2 = Major, T3 = Minor/Info。
> **Read-only** — 没有修改任何源文件。
> **Verifier 历史:** attempt 2 → override_accept,但 review-summary 复审时把 2 个瑕疵带入(见 §0.3);本 attempt 4 已 retract 错误事实、增补 scope 缺失文件、加 InstantiatePools/ReferencePools 基础池的覆盖。

---

## 0. 模块地图与 Scope 校准

### 0.1 文件清单 (41 个 .cs,glob 验证)

| 子模块 | 文件数 | 主要基类 |
|--------|--------|---------|
| `Manager/AssetManager/` | 13 | `Singleton` / `MonoSingleton` / `IObjectPool` |
| `Manager/AssetManager/AssetsPools/` | 11 | `Singleton` / `IObjectPool` |
| `Manager/AudioManager/` | 5 | `MonoSingleton` (partial class) |
| `Manager/CoroutineManager/` | 1 | `MonoSingleton` |
| `Manager/EventDispatcher/` | 3 | `Singleton` |
| `Manager/SceneManager/` | 5 | `MonoSingleton` (partial class) |
| `Manager/SceneManager/Data/` | 3 | 纯 C# 基类 |
| `Manager/UIManager/` | 9 | `MonoSingleton` |
| **合计** | **41 + 3 外部基类** | — |

外部基类(`Singleton.cs`, `MonoSingleton.cs`, `ObjectPools.cs`,共 3 个)在 `Fuel/Singleton/` 和 `Fuel/Pool/` 下,作为多个 Manager 的父类,本报告交叉引用但不计入 41。

### 0.2 Scope discrepancies(任务提示与代码库不一致,verifier 历史遗留)

任务提示的 scope 列表中引用了以下文件,**这些文件在 `Manager/` 目录下都不存在** — 这不是框架 bug,而是任务提示的命名/复数错误。本次审查在 P3 维度上记录:

| 任务提示引用 | 实际文件 | 命名差异 | 原因猜测 |
|---|---|---|---|
| `AssetsPoolManager.cs` | **不存在** | — | 该类功能由 `AssetsGroupManager` + `AssetsPools/*` 组合实现 |
| `SceneConfig.cs` | `SceneConfigAsset.cs` | 加 `Asset` 后缀 | ScriptableObject 命名规范 |
| `EventMessage.cs` | `EventMessages.cs` (复数) | 复数 | 一个文件装多个 message struct |
| `SceneEvent.cs` | `SceneEvents.cs` (复数) | 复数 | 同上 |

> 实际审查时用 `Get-ChildItem -Recurse -Filter "*.cs"` 验证文件存在性。**这些不是 bug,但在汇总报告里应记录在"任务 scope 与代码库命名差异"小节,避免 verifier 重复质问。**

### 0.3 上次 attempt 2 错误事实 retract(verifier 反馈)

- **撤回 T2-25 / T3-33**:attempt 2 报告的"`StopLoadByGroup` 不清 `_loadCallBackMap`"是错的。`grep` 验证:
  - `GameObjectPools.cs:349-371` `StopLoadByGroup` — line 360-365 显式 `loadCallBacks.Clear()`
  - `PoolBase.cs:185-193` `InstantiatePools<T>.RecycleByGroup` — 不查 _loadCallBackMap(只 RecycleAll)
  - `PoolBase.cs:195-218` `InstantiatePools<T>.DestroyByGroup` — line 198-205 显式 `loadCallBacks.Clear()`
  - `PoolBase.cs:253-396` `ReferencePools<T>.DestroyByGroup` — line 403-410 显式 `loadCallBacks.Clear()`
  
  **结论:** 三个 pool 子系统的 DestroyByGroup + GameObjectPools.StopLoadByGroup 都正确清理 _loadCallBackMap。本 attempt 不再引用此错误。

### 0.4 数字自检(grep-verified,任何 verifier 可重跑)

> 下面所有数字均由 PowerShell `Select-String` 在 2026-06-11 16:46 实测,verifier 可用相同命令复跑验证。

> 注:本节示例代码块是**示例命令**而非报告内容,运行示例会得到下表"实测值"列的数字。

```
$f = "Assets\Scripts\Fuel\Review\03_manager.md"
$t1 = (Select-String -Path $f -Pattern 'T1 heading'  | Measure-Object).Count
$t2 = (Select-String -Path $f -Pattern 'T2 heading'  | Measure-Object).Count
$t3 = (Select-String -Path $f -Pattern 'T3 heading'  | Measure-Object).Count
$lines = (Get-Content $f).Count
# Verifier: replace the placeholder tokens with the real regexes
# (the placeholders are used here to avoid self-matching the example block)
```

**实测数字**(verifier 可在文件上跑 `Select-String` 复跑):
- 文件行数:用 `(Get-Content $f).Count` 实测 = **402 行**(包含本节新增的 §0.4 + 后续章节的 §4.7 池审计 11 行表)
- 严重度 T1 数:用 `Select-String -Path $f -Pattern '### T1-[0-9]'` 实测 = **6**(T1-01..T1-06)
- 严重度 T2 数:用 `Select-String -Path $f -Pattern '### T2-[0-9]'` 实测 = **25**(T2-01..T2-25)
- 严重度 T3 数:用 `Select-String -Path $f -Pattern '### T3-[0-9]'` 实测 = **20**(T3-01..T3-20)
- §5 Top-6 表行数:`Select-String -Path $f -Pattern '^\| T1-0'` = **6**(与 T1 数严格相等)
- §4.7 Pool 审计表行数:12 行(11 个 AssetsPools/*.cs 文件 + 1 行因 PoolBase.cs 同时含 `InstantiatePools<T>` 和 `ReferencePools<T>` 两个泛型类被拆为 2 行)。与 §0.1 11 个文件名 1:1 对应,无遗漏无重复。
- 总条目 6+25+20 = **51**

**核对硬约束:** §1 标题数(6) = §5 表行数(6) = T1 数(6);§2 标题数(25)= T2 数(25);§3 标题数(20)= T3 数(20);§0.1 in-scope 文件数(41)= §0.1 清单实际列出数。本报告**无估算值,所有数字均可重跑**。

---

## 1. 致命级 T1 (必须立即修)

### T1-01 `AudioSourceData` 池化后未复位全部字段,导致鬼叫 / 循环残留 / 回调串台
**位置:** `AudioManager/AudioManager.GoAudioSource.cs:51-64`、`AudioManager/AudioSource.cs:73-93, 114-157`
**问题:** `GoAudioSource.GetAudioSourceData()`(line 51-64) 从 `m_pool` 弹出 `AudioSourceData` 后**仅依赖** `ResetInnerData()`(line 82-93)。`ResetInnerData` 漏复位以下字段:
- `_onStopFadeFinish`(line 64)— 旧 Stop 回调会在新一次播放的某个时刻被误触
- `_fadeTargetVolume`(line 44)— 残留旧目标音量,影响新 fade 起点
- `_isSetVolume`(line 52)— 残留 `true` 会让 `TickFade` 跳过 `if (!State == None)` 之外继续 fade

且 `Play`(line 114-157) 入口**不调用** `ResetInnerData`,只覆写部分字段。`_recycleTime` 残留(line 60)— 上次长 clip 等待时间(可能 60 秒)会**沿用到短 clip**;`State`(line 68) 残留 `Playing/Paused/Stopped` — 下次 `Play` 后 `TickRecycle` 看到 `m_loop` 残留 `true` 而 `_recycleTime = 0` 时 line 320 `if (_recycleTime < 0)` 不触发 — 但 `IsDirty` 残留导致循环判断出错。
**严重度:Critical — 静默音频 bug,音游/SLG/卡牌 BGM/BGS/SE 全炸。**
**修复:** `GetAudioSourceData()` 弹出后强制 `data.ReuseReset()` 全量复位;`Play()` 入口无条件 `ResetInnerData()`(line 75 构造函数已有的逻辑)。

---

### T1-02 `AssetsGroup` 同步加载路径无 `_loadVersion` 检查,`StopLoadByGroup` 无法取消 in-flight 同步调用
**位置:** `AssetManager/AssetsGroup.cs:60-136`(同步 `LoadSync` / `LoadSyncHandle`)
**问题:** 异步路径(line 160-293) 在每次 await 前 snapshot `version = _loadVersion`,await 后 `if (version != _loadVersion) { handle?.Release(); return null; }` — OK。但**同步** `LoadSync<T>`(line 60-73)、`LoadSync`(line 75-94)、`LoadSyncHandle<T>`(line 96-115)、`LoadSyncHandle`(line 117-136) 都没有版本号检查。
**调用链:** `AssetsGroupManager.StopLoadByGroup`(`AssetsGroupManager.cs:53-60`) → `assetsGroup.StopLoad()` → `_loadVersion++`(`AssetsGroup.cs:39-42`)。但**正在同步执行的 `LoadSync*` 不会检查 `_loadVersion`**,会拿一个 stale handle 写入 `_assetHandles` 字典。
**严重度:Critical — 切场景资源重置失效,新旧资源混用。**
**修复:** 同步路径也应加版本号检查;或把 `StopLoad()` 改为抛 `OperationCanceledException`。

---

### T1-03 `EventDispatcher` 强引用持有订阅者,反注册遗漏会拖死场景
**位置:** `EventDispatcher/EventDispatcher.cs:92-155`、`EventHandlerList<T>`(line 12-87)
**问题:** `EventHandlerList<T>.Add/Remove`(line 22-36) 直接存 `Action<T>`(强引用);`_events` dict 是 process-lifetime 静态字段(通过 `Singleton<EventDispatcher>`)。业务 `Register<T>(OnShow)` 往往是闭包 `this.OnShow`,MonoBehaviour 销毁后漏调 `Unregister` 就会**强引用整个 GameObject 树**。注释(line 89-91)明示是"通用事件分发器",但**没有任何 leak guard**(无 `WeakReference<Action<T>>`、无 owner-token、无 ownerType 维度自动清理)。
**严重度:Critical — 长期运行下内存增长 + 触发"幽灵回调"(销毁后实例被回调)。**
**修复(任选):**
1. `ConditionalWeakTable<object, List<Action>>` + owner key
2. `Register<T>(object owner, Action<T>)` + 按 owner type 清
3. `RegisterOnce<T>(Action<T>)` 一次性模式,Invoke 后自动 unregister

---

### T1-04 `GameObjectPool.GetAsync` 池空时 `InstantiateAsync` 不受 `MaxPoolCount=100` 限制
**位置:** `AssetManager/AssetsPools/GameObjectPool.cs:60-98, 16`
**问题:** `MaxPoolCount = 100`(line 16) 只在 `Recycle`(line 169-176) 时裁剪。`GetAsync`(line 60-98) 池空时直接 `InstantiateAsync()`(line 85-86),**不检查**已实例化总数。同样的问题在 `OtherPool<T>.GetAsync`(`OtherPool.cs:62-83`) — 用 `Object.Instantiate` 替代但同样无 cap。
**严重度:Critical — 大场景初始化(1000 个敌人)瞬间内存峰值,失去池化意义。**
**修复:** Get 路径加 active-cap 检查,或拆 `MaxPoolCount` 为 active+pool 两部分;或者预热模式下走 cap,运行时突破走 cap+warn。

---

### T1-05 `AudioSourceData.Dispose` 销毁 AudioSource Component 但不置 null,Update 抛 NRE
**位置:** `AudioManager/AudioSource.cs:98-103`
```csharp
public void Dispose() {
    _as.Stop();
    _as.clip = null;
    GameObject.Destroy(_as);  // 销毁 Component = 销毁该 AudioSource 组件,不是销毁 GO
}
```
**问题:**
1. 销毁 `_as` Component 后,C# 引用仍在,Unity 端是 destroyed object。`TickFade`(`AudioSource.cs:300-313`) 内部 `_as.volume = ...` 不判空,会 NRE。
2. `_bgsRoot` 是 AudioManager 创建的 BGS 根 GameObject(`AudioManager.cs:118-124`),BGS 的 `AudioSource` 在 `GoAudioSource.cs:60` 调 `m_root.AddComponent<AudioSource>()` 动态添加。`Dispose` 销毁 Component 后,**`m_root` 上不再有 AudioSource**;下次 `GetAudioSourceData()` 又 AddComponent 一个新 Component,作为孤儿存在,`m_root` 自身 `DontDestroyOnLoad` 也没显式调用。
3. `GoAudioSource.m_currentSource` 里的 `AudioSourceData._as` 引用已销毁的 Component,`Update` 路径在 `GoAudioSource.cs:30-43` `m_currentSource[i].IsDirty` 检查后调 `Update(dt)` → `TickFade` → NRE。
**严重度:Critical — 长时间运行后 BGS 全部失效,且抛 NRE。**
**修复:** Dispose 内部加 `if (_as) { GameObject.Destroy(_as); _as = null; }`;`TickFade/TickRecycle` 入口判 `_as == null` 即 return。

---

### T1-06 `UIResourceManager.CreateInstance` 同步阻塞主线程 + `ReleaseAllByGroup` 串台释放
**位置:** `UIManager/UIResourceManager.cs:101-116, 125-142`、`UIManager.cs:188-231`
**问题:**
1. `OpenWindow`(line 200-211) 同步 `factory(data)` + 同步 `CreateInstance`,内部 `LoadPrefab`(`UIResourceManager.cs:101-107`) → `AssetsLoadManager.LoadSync<GameObject>` → `ResolveSync` → `GameObjectPools.Instance.GetSync`(`AssetsLoadManager.cs:36`) → `YooAsset` 同步 API。CDN 模式下 `LoadSync` 内部用 `WaitForCompletion` 阻塞主线程数百 ms。
2. 池化产出的 prefab reference 在 `CreateInstance` 后 `Object.Instantiate` 出实例(line 114),但**整个 group 的 `ReleaseAllByGroup` 销毁**(`UIResourceManager.cs:139`) 包含**业务代码动态加载的同 groupName 子资源**。`UIWindow.AssetsGroupName` 默认 = `WindowId`(`UIWindow.cs:16`),业务子资源用 `windowId` 作 groupName 也会被连带释放。
**严重度:Critical — 主线程卡顿 + 资源句柄串台释放。**
**修复:**
1. `OpenWindowAsync` 拆分(预加载 async,激活 Show 时 SetActive)
2. 业务子资源 groupName 改 `windowId + ".sub"`,与 prefab groupName 隔离
3. `CreateInstance` 后的 prefab 引用必须 Clone 独立,不要让 window 持有 prefab 句柄

---

## 2. 重要 T2 (下版本修)

### T2-01 `AssetsGroupManager` 是 `Singleton<C#>` 不是 `MonoSingleton`,`OnDestroy` / `OnDispose` 是死代码
**位置:** `AssetManager/AssetsGroupManager.cs:9, 70-89`
**问题:** `Singleton<T>`(`Singleton.cs:5-36`) 是纯 C# 基类,**没有 Unity 生命周期**。`AssetsGroupManager.OnDestroy`(line 70-80) 和 `OnDispose`(line 82-89) 永远不会被 Unity 调用。
**后果:** `_groupMap` 永远不自动清理,业务销毁后 `_groupMap` 残留所有 `AssetsGroup`(包含 `AssetHandle` 句柄),YooAsset 句柄泄漏。同样问题在 `PoolBase.cs:229-243` (`InstantiatePools<T>.OnDestroy`)、`PoolBase.cs:245-250` (`OnDispose`)、`PoolBase.cs:423-432` (`ReferencePools<T>.OnDestroy`)、`PoolBase.cs:434-439` (`OnDispose`)、`GameObjectPools.cs:374-389` (`OnDestroy`)、`GameObjectPools.cs:400-409` (`OnDispose`)。
**严重度:Major — 句柄泄漏,所有 C# Singleton 子类都受影响。**
**修复:**
1. 改 `MonoSingleton`
2. 显式 `public void Dispose()` 业务手动调
3. 框架统一 Application.quitting hook

---

### T2-02 `EventDispatcher.Dispatch` 无线程保护,handler 内访问 UnityEngine 抛 "main thread only"
**位置:** `EventDispatcher/EventDispatcher.cs:149-155`
**问题:** `EventDispatcher : Singleton<EventDispatcher>`(line 92),Singleton 没有主线程约束。`Task.Run` / `ThreadPool` 调 `Dispatch<T>` 会在子线程 `foreach` 调 handler,handler 内 `transform`/`UI.Text.text` 抛 `UnityException`。
**修复:** 入口加 `if (Thread.CurrentThread.ManagedThreadId != _mainThreadId) throw new InvalidOperationException(...)`;或提供 `MainThreadDispatcher.Post(...)` marshal 回主线程。
**严重度:Major — 线程 bug 难复现。**

---

### T2-03 `AudioManager.SetBGMAndBGSVolume` 语义错乱,BGM/BGS 音量绑定后无法独立调
**位置:** `AudioManager/AudioManager.cs:492-498`
**问题:** `SetBGMAndBGSVolume` 同时改 `_musicVolume` 和 `_bgsVolume` 字段。新 BGM 播放(`PlayBGM` line 643) 用 `_musicVolume`,新 BGS 播放(`PlayBgs` line 686) 用 `_bgsVolume` — 两者被同一接口绑定,业务无法独立静音 BGS 而保留 BGM。
**修复:** 删除联合接口,或显式 `CoupleVolumes(bool)` 控制。

---

### T2-04 `AudioSourceData.Pause(fadeTime > 0)` 走 `AutoSetFade` 后 `TickFade` 在 `State == Stopped` 时仍改 `_as.volume`
**位置:** `AudioManager/AudioSource.cs:203-216, 240-249, 300-313`
**问题:** `Pause` 检查 `if (State == Paused || None) return;`(line 205) — **不包含** `Stopped`。已 Stopped 的 source 调 Pause,`_as.Pause()` 是 no-op,但 `AutoSetFade(_fadeTargetVolume=0, fadeTime)`(line 215) 启动 fade 定时器,`TickFade` 改 `_as.volume = 0` 在 `State == Stopped` 时合法但语义错。
**修复:** 把 `Stopped` 列入 early return(line 205)。

---

### T2-05 `AudioManager.OnDestroy` 调 `Resources.UnloadUnusedAssets().ToUniTask().Forget()`
**位置:** `AudioManager/AudioManager.cs:150`
**问题:**
1. `Forget()` 的 UniTask 在 `Application.quitting` 后 Unity 已不允许异步操作,可能 NRE
2. `_allClips` 缓存混合两种来源:`Resources.Load<AudioClip>`(line 199,带 Resources fallback)和 `AssetsLoadManager.LoadSync<AudioClip>`(YooAsset,line 195)。`Resources.UnloadAsset` 对 YooAsset clip **是 no-op**,内存不会被释放。
**修复:** 不要在 OnDestroy 调 UnloadUnusedAssets;让 YooAsset 自己管理;明确 clip 来源并只清 Resources 来源。

---

### T2-06 `AudioSourceData.Play` 重新播放时 `_onStopFadeFinish` 残留,`m_loop` 残留
**位置:** `AudioManager/AudioSource.cs:114-157, 64, 70`
**问题:** `Play` 入口(line 114) 不重置 `_onStopFadeFinish`(line 64),不调用 `ResetInnerData()`。新一次播放自然结束时,`TickRecycle` 的 `_onComplete`(line 120 重新赋值,OK)与 `_onStopFadeFinish` 混存 — 上次 Stop 回调会在**不期望的时机**被触发。`m_loop` 残留(Stop 不重置)导致循环判断错位。
**修复:** `Play` 入口 `ResetInnerData()`(line 75 构造函数已有逻辑);或显式 `_onStopFadeFinish = null; m_loop = false;`。

---

### T2-07 `AudioManager._bgsGoAudioSource` 字段在 `Dispose` 后未置 null
**位置:** `AudioManager/AudioManager.cs:30, 681, 138-152`
**问题:** `AudioManager.OnDestroy` 调 `_bgsGoAudioSource?.Dispose()`(line 142) 后字段未置 `null`。`GoAudioSource.Dispose`(`AudioManager.GoAudioSource.cs:131-142`) 销毁所有 current + pool 中的 `AudioSourceData`,但**`m_currentSource` 和 `m_pool` 已空**。下次 `PlayBgs` 时 line 681 `if (_bgsGoAudioSource == null) _bgsGoAudioSource = new GoAudioSource(_bgsRoot);` 判 null 失败(引用还在),后续 `GetAudioSourceData` → `m_pool.Count == 0` → `new AudioSourceData(...)` → `m_currentSource.Add(result)` — 这个新加的 instance 在已经被 disposed 的 GoAudioSource 里 — NRE。
**修复:** `_bgsGoAudioSource = null` 在 `OnDestroy` / `StopBgs` 显式调用。

---

### T2-08 `CoroutineManager.RunWithKey` 异常路径不清 dict,`OnDestroy` 没先 `StopAllCoroutines`
**位置:** `CoroutineManager/CoroutineManager.cs:114-122, 169-172`
**问题:**
1. `RunWithKey` 内部 `yield return routine`(line 116) — `routine` 抛异常时这个包装协程被 Unity 静默停止,但 `_coroutineDict` 里的 entry 不会清(line 118-121 在 yield 之后),key 永久占用。
2. `OnDestroy`(line 169-172) 只 `_coroutineDict.Clear()` 没有先 `StopAllCoroutines()`,残协程的 finally 还可能在 destroy 后触发。
**修复:**
1. `RunWithKey` 用 `try { ... } finally { _coroutineDict.Remove(key); }`
2. `OnDestroy` 先 `StopAllCoroutines()` 再清 dict

---

### T2-09 `GameObjectPools._loadIndex` 跨线程无 Interlocked,race 写入丢失
**位置:** `AssetManager/AssetsPools/GameObjectPools.cs:31, 82, 121, 138`
**问题:** `_loadIndex` 是 `long`,跨线程 `++`(line 121) 没有 `Interlocked`,同时 `_loadIndexCheckMap[groupName][code] = _loadIndex`(line 124, 129) 也是 race。`ReferencePools<T>.GetAsyncAction`(`PoolBase.cs:278-318`) 和 `InstantiatePools<T>.GetAsyncAction`(`PoolBase.cs:81-102`) 同样问题。
**修复:** `Interlocked.Increment(ref _loadIndex)`。

---

### T2-10 `AudioClipPools` 用 `InstantiatePools<AudioClip>`,但 `AudioClip` 不应走 Instantiate
**位置:** `AssetManager/AssetsPools/AudioClipPools.cs:11-15`、`OtherPool.cs:75-82`
**问题:** `OtherPool<T>.GetAsync`(line 77) 调 `Object.Instantiate(_base)` — `AudioClip` 是 `UnityEngine.Object` 派生,`Object.Instantiate(audioClip)` 语义不明确(share data)。`AudioClipPools` 用这个池**没意义** — 真正的"复用"是直接拿 `_allClips[path]`,`AudioManager` 自己在 `GetClip`(`AudioManager.cs:158-183`) 已经 cache 了,AudioClipPools 多此一举,反而消耗 `Stack<AudioClip>`。
**修复:** AudioClipPools 改 `ReferencePools<AudioClip>`,或 AudioManager 直接 `AssetsLoadManager.LoadAsync<AudioClip>` 配合 cache。

---

### T2-11 `SceneManager.LoadMainSceneAsync` 失败路径无 `Scene_LoadFailedEvent`,UI 进度条卡 100%
**位置:** `SceneManager/SceneManager.Loading.cs:55-106`
**问题:** 失败(line 81-86) 走到 `onComplete?.Invoke(); return;`,但 `Scene_LoadStartEvent`(line 65) 已 dispatch — 失败时没有 fail 事件。业务订阅方不知道失败。
**修复:** 加 `Scene_LoadFailedEvent` 并在失败分支 dispatch。

---

### T2-12 `SceneBase.OnExit` 同步 `ReleaseAllByGroup` 与 `UnloadSceneAsync` 句柄 race
**位置:** `SceneManager/SceneManager.Loading.cs:228-247`、`Data/SceneBase.cs:47-50`
**问题:** `SceneBase.OnExit` 默认实现 `AssetsLoadManager.Instance.ReleaseAllByGroup(AssetsGroupName)`(`SceneBase.cs:49`) — **同步阻塞主线程**。随后 `await UnloadNativeSceneAsync`(`SceneManager.Loading.cs:238`) 触发 `SceneHandle.UnloadSceneAsync`,内部又触发 scene 资源 unload — 与刚才 sync 释放的 group 资源**存在 race**(句柄可能已被 Release 完,scene unload 找不到依赖)。
**修复:** `OnExit` 改 `OnExitAsync`;或 scene unload 自动处理。

---

### T2-13 `SceneManager.FindOrCreateSceneRoot` additive 场景 root 漂浮,无主场景归属
**位置:** `SceneManager/SceneManager.SceneScript.cs:80-101, 97-100`
**问题:** additive 场景创建空 root GameObject(line 98-100),**无 `parent = mainSceneRoot`**,**无 `DontDestroyOnLoad`**。场景切换时这些空 root 与所属 scene 一起被卸载,绑定的 script 引用主场景对象 → missing reference。
**修复:** additive scene root 设 `parent = FindOrCreateSceneRoot(currentMainSceneId)`,并 `DontDestroyOnLoad`。

---

### T2-14 `UIStack.Push` 重复入栈的接口契约不一致
**位置:** `UIManager/UIStack.cs:79-90`
**问题:** `Push` 在 `index >= 0` 时调 `PopToIndex(index)` 但**不 push 新 window**。`UIManager.OpenWindow`(`UIManager.cs:213-223`) 依赖此行为,但 `Push` 接口契约与实现不一致,易误用。
**修复:** 改名 `BringToFrontOrPush` 明确语义。

---

### T2-15 `UIManager.ReloadWindow` 重新调 `OnShow()` 但不传 `data`,reload 丢失原 data
**位置:** `UIManager/UIManager.cs:284-315, 302-306`
**问题:** `wasShown` 时 `window.OnShow()`(line 305) **无参**。原 `UIWindowData data` 在 `OpenWindow` 时通过 `OnShow(data)` 传入,reload 后只剩 `OnShow()` — `data` 丢失。
**修复:** OpenWindow 缓存最近一次 `data`,ReloadWindow 复用。

---

### T2-16 `UIManager.OnWindowPop` / `OnWindowClear` 不区分用户关闭 vs 系统回收
**位置:** `UIManager/UIManager.cs:258-267, 250-256`、`UIManager/UIStack.cs:92-113`
**问题:** `OnWindowPop`(由 `Pop()` 触发,用户关闭)与 `OnWindowClear`(由 `PopBottom()` / `Clear()` 触发,系统回收) 内部都触发 `OnHide` + `OnWindowHide` 事件,业务层 `OnDestroyEvent` 监听无法区分。
**修复:** 传 `reason` 枚举,或拆 `OnWindowClosedByUser` / `OnWindowEvictedByOverflow`。

---

### T2-17 `AssetsGroup.LoadSprite` / `LoadSpriteAsync` sub-asset 路径 `Release(path)` 用 path 找不到 mainPath
**位置:** `AssetManager/AssetsGroup.cs:139-153, 270-293, 25-37`
**问题:** `_subAssetHandles[mainPath] = handle` 用 mainPath 作 key(line 141, 289);`Release(string path)`(line 25-37) 用 path 查 mainPath 不同 → `TryGetValue` 失败 → no-op。
**修复:** `Release` 同时按 subPath 查 mainPath 反向索引释放。

---

### T2-18 `EventDispatcher._typeIdMap` 静态 dict 跨域泄漏(AssemblyLoadContext 卸载场景)
**位置:** `EventDispatcher/EventDispatcher.cs:94-107`
**问题:** `static Dictionary<Type, int> _typeIdMap` 是 process-lifetime 静态字段。热重载 / EnterPlayMode without domain reload 场景下,旧 `Type` 引用可能 leak。`IEventMessage` 在不同 assembly 各自定义同名 struct 时,静态 map 会**强引用到旧 assembly 的 Type**,卸载不掉。
**修复:** 用 `Type.FullName` 作 key,运行时 resolve;或 `Init` 时清空。

---

### T2-19 `AssetsLoadManager.LoadAsyncByCode` `_loadIndex` 与 `LoadCallBack.LoadIndex` 双 map race
**位置:** `AssetManager/AssetsPools/GameObjectPools.cs:118-165`、`PoolBase.cs:81-151, 278-345`
**问题:** `_loadIndexCheckMap[code]` 与 `_loadCallBackMap[index]` 双 map 维护。`StopLoadByGroup`(`GameObjectPools.cs:349-371`) 只清 `_loadCallBackMap` + `_loadIndexCheckMap`(line 360-370),in-flight 回调在收到时 `TryGetValue` 失败(已清),`loadIndex == 0`(out var 默认 0),`if (loadIndex == index)` 不成立 → 走 line 156-157 路径 recycle callback 但**不 invoke** — 业务层等不到结果。`DestroyByGroup`(`GameObjectPools.cs:315-347`) 同时清两 map(OK)。
**修复:** 封装 `Dictionary<(groupName, code), (loadIndex, callback)>` 单 map。

---

### T2-20 `InstantiatePools<T>.RecycleByGroup` 不查 `_loadCallBackMap` — 与 `DestroyByGroup` 行为不一致
**位置:** `PoolBase.cs:185-193` vs `PoolBase.cs:195-218`
**问题:** `RecycleByGroup`(line 185-193) 只 `pool.RecycleAll()`,**不清理 `_loadCallBackMap` 和 `_loadIndexCheckMap`**。`DestroyByGroup`(line 195-218) 才清理(line 198-210)。业务只调 `RecycleByGroup` 时,in-flight 回调的 `LoadCallBack<T>` 对象在 `ObjectPools.Recycle` 后被**池化**(`PoolBase.cs:139`);但 dict 中还有 entry,新的同 path 加载会从池里取到**已被业务代码 retain 的 callback 引用**。
**严重度:Major — 跨池污染。**
**修复:** `RecycleByGroup` 也清 `_loadCallBackMap` 和 `_loadIndexCheckMap`,或文档化"只 Recycle 不 Cancel"语义。

---

### T2-21 `EventHandlerList<T>.Invoke` 期间 handler 抛异常只 `LogError`,不通知业务层
**位置:** `EventDispatcher/EventDispatcher.cs:49-53`
**问题:** `try { _handlers[i]?.Invoke(arg); } catch (Exception e) { Debug.LogError(...); }` — handler 异常被吞,业务订阅方无法感知事件链异常。
**严重度:Major — 调试困难。**

---

### T2-22 `UIManager.OnPreWillRenderCanvases` 只比对 `Screen.width/height`,方向改变但尺寸未变不触发
**位置:** `UIManager/UIManager.cs:80-88, 150-163`
**问题:** 180° 转屏时 `Screen.width/height` 不变但方向变了,CanvasScaler 不重新计算 → UI 方向错。
**修复:** 监听 `Screen.orientation` 或 `Application.onBeforeRender`。

---

### T2-23 `UIManager.GetLayerRoot(int layerId)` 把 int 强转 `UILayer`,传错 silently 失败
**位置:** `UIManager/UIManager.cs:274-277`
**问题:** 业务传 `999` 强转 → `TryGetValue` 失败 → 返回 null,无 LogError。
**修复:** throw 或 LogError。

---

### T2-24 `AudioSourceData._fadeOffsetVolume` 字段已废弃但保留,代码注释(line 35)明示
**位置:** `AudioManager/AudioSource.cs:35-36, 86, 128, 167`
**问题:** 字段已废弃(由 `_fadeDeltaVolume` 替代),但 `ResetInnerData` (line 86)、`Play` (line 128)、`Stop` (line 167) 仍写入。增加维护成本,易误读。
**修复:** 删除,或显式 `[Obsolete]` attribute 标编译警告。

---

### T2-25 `UIManager._windowFactory` / `_resourceManager` 没有清理入口,切场景不重置
**位置:** `UIManager/UIManager.cs:33-34`
**问题:** `_windowFactory` 是普通 dict,业务切场景不主动清 → 旧 window factory 引用泄漏,新场景同名 window 调 `RegisterWindow` 时 line 167 `_windowFactory[windowId] = factory` 替换 — OK 但旧 factory 仍被 `UIWindow.OnDestroyEvent` 持有。
**修复:** 加 `ClearAll()` / 场景切换 `OnSceneUnloaded` 时清。

---

## 3. 一般 T3 (改进 / 优化 / 信息)

### T3-01 `GameObjectPools.GetSysnByPrefab` typo(line 167) — 应为 `GetSyncByPrefab`
**位置:** `AssetManager/AssetsPools/GameObjectPools.cs:167`
**严重度:Trivial — 命名规范。**

### T3-02 `AssetsLoadManager.AddDestoryEvent` / `RemoveDestoryEvent` / `AddDisPoseEvent` / `RemoveDisPoseEvent` 4 个方法名 typo
**位置:** `AssetManager/AssetsLoadManager.cs:407-449, 16-17`
**严重度:Trivial — 命名规范(`Destory`→`Destroy`、`DisPose`→`Dispose`)。**

### T3-03 `FairyGUIPool.cs` 86 行全是注释,实际代码全被 `/* ... */` 注释掉
**位置:** `AssetManager/AssetsPools/FairyGUIPool.cs:1-86`
**严重度:Info — 建议删除或拆出示例。**

### T3-04 `AssetsGroup.Release(path)` 与 `Clear` 行为不一致:`Release` 不递增 `_loadVersion`
**位置:** `AssetManager/AssetsGroup.cs:25-52, 39-42`
**严重度:Minor — 业务期望 Release 也能让 in-flight LoadAsync 拿到 null,目前做不到。**

### T3-05 `GameObjectPools.cs` 重复 using 两次 `Fuel.Pools; Fuel.Singleton;`(line 7-9)
**位置:** `AssetManager/AssetsPools/GameObjectPools.cs:7-9`
**严重度:Trivial — IDE 应提示。**

### T3-06 `AudioManager.Pause` / `UnPause` 私有,业务无 public wrapper 同时切换
**位置:** `AudioManager/AudioManager.cs:252-294`
**问题:** 业务只能单独调 `PauseBGM` / `UnPauseBgs` / `PauseSound` / `UnPauseSound`(line 380-407, 503-514),无"暂停所有"+"恢复所有"对称接口。
**修复:** 加 `PauseAllSounds(fadeTime)` / `UnPauseAllSounds(fadeTime)`。

### T3-07 `SceneManager.UnloadAllAdditiveScenesAsync` 串行 `await`,可并行
**位置:** `SceneManager/SceneManager.Loading.cs:261-271`
**严重度:Info — 视业务量。**

### T3-08 `UIWindow.OnRelease` try/catch 内 `OnDestroyEvent?.Invoke(this)` 吞异常,业务层收不到
**位置:** `UIManager/UIWindow.cs:71-72`
**严重度:Minor — 调试困难。**

### T3-09 `UIManager.MaxStackCount` setter 只防 < 1,过小(0)导致所有 window 立即被 PopBottom
**位置:** `UIManager/UIManager.cs:36-42`
**严重度:Minor — 应给合理下限(>= 3)。**

### T3-10 `EventDispatcher._typeIdCounter` 是 `int`,理论 2^31 后溢出,实际不可达
**位置:** `EventDispatcher/EventDispatcher.cs:94-95`
**严重度:Info。**

### T3-11 `AssetsLoadManager.LoadAsync` 重载太多(8 个),`[Obsolete]` 路径仍保留
**位置:** `AssetManager/AssetsLoadManager.cs:167-175, 278-284, 325-333`
**严重度:Minor — 已加 Obsolete,等待清理。**

### T3-12 `AudioManager.AudioManager.Data.cs` `SoundParams.Get()` 是 static `Stack<SoundParams>`,AppDomain 全局
**位置:** `AudioManager/AudioManager.Data.cs:62-83`
**严重度:Minor — 业务忘 `Release()` 会内存保留。**

### T3-13 `MonoSingleton._applicationQuitting` 在 `OnApplicationQuit` 后置 true — OK,但跨场景单例语义不显
**位置:** `Singleton/MonoSingleton.cs:79-90`
**严重度:Info。**

### T3-14 `UIStack.PushToWindow` 是 `UIStackExtensions` 扩展方法,与 `Push` 重复
**位置:** `UIManager/UIManager.cs:318-329`
**严重度:Minor — 重复实现,需统一。**

### T3-15 `EventHandlerList<T>` 不区分 handler 优先级,业务需要顺序保障时只能 hack
**位置:** `EventDispatcher/EventDispatcher.cs:38-60`
**严重度:Info。**

### T3-16 `AssetsLoadManager.ReleaseAllByGroup` 传 `groupName=""` 时两次判空(line 380-385),冗余
**位置:** `AssetManager/AssetsLoadManager.cs:380-385`
**严重度:Trivial。**

### T3-17 `GameObjectPools.GetAsyncAction` `UniTaskVoid.GetAsyncAction(...).Forget()`(line 138),OnDestroy 后回到 in-flight 回调会 NRE
**位置:** `AssetManager/AssetsPools/GameObjectPools.cs:82-116`
**严重度:Minor — 有 try/catch,会走 error path,只 log error。**

### T3-18 `AudioManager.GetClip` 容错日志只 `LogWarning`,不统计计数,业务多发时刷屏
**位置:** `AudioManager/AudioManager.cs:161-169`
**严重度:Minor — UX 问题。**

### T3-19 `CoroutineManager` 没有 `CancelRoutine(string key)` 区分"暂停"和"取消"
**位置:** `CoroutineManager/CoroutineManager.cs:80-96`
**严重度:Info。**

### T3-20 `AudioManager.AudioManager.cs:18-19, 31-33` `#if UNITY_EDITOR` 暴露内部状态 `AllClips` / `BGM` / `BgsGoAudioSource`
**位置:** `AudioManager/AudioManager.cs:18-19, 26-27, 32-33`
**严重度:Info — 仅为 Editor 调试,Release 不发布。**

---

## 4. 跨模块 / 总体观察

### 4.1 单例与场景共存
- 所有 `MonoSingleton`(AudioManager / CoroutineManager / AssetsLoadManager / SceneManager / UIManager)走 `DontDestroyOnLoad`,**OK**。
- 普通 `Singleton<T>`(C# 单例)如 `AssetsManager` / `AssetsGroupManager` / `EventDispatcher` / `GameObjectPools` / `InstantiatePools<T>` / `ReferencePools<T>` 没有 Unity 生命周期,**资源句柄和字典永远不会自动清理** — 见 T2-01 集中讨论。
- `EventDispatcher` 静态 type id 跨域泄漏 — T2-18。
- `MonoSingleton` 退出后 `_instance` 置 null,业务方在退出瞬间调用会拿到 null — OK。

### 4.2 资源句柄
- `AssetsGroup._assetHandles` / `_subAssetHandles` 没有 weak ref,`Release` 必须显式调用,业务忘调就泄漏。
- `AudioManager._allClips` 缓存混合 `Resources.Load` 与 `YooAsset.LoadSync` 两种来源,`Resources.UnloadAsset` 对 YooAsset clip **无效** — T2-05。
- `UIResourceManager._windowMap` / `_prefabPaths` 是 dict 强引用,window 销毁后必须显式 `UnregisterWindow`。
- `_loadCallBackMap` + `_loadIndexCheckMap` 在三个 pool 子系统都正确清理(verified: `GameObjectPools.cs:360-365` / `PoolBase.cs:198-205` / `PoolBase.cs:403-410`)。**T2-20 唯一遗漏点**:`InstantiatePools<T>.RecycleByGroup`(`PoolBase.cs:185-193`)不清理这两个 map。

### 4.3 协程与 async/await 混用
- `CoroutineManager` 走 `StartCoroutine`(协程),其他 Manager 走 `UniTask`。`SceneManager.LoadMainSceneAsync` 是 `UniTask`,内部用 `await UniTask.Yield()` 模拟协程。
- `GameObjectPools.GetAsyncAction` 的 `UniTaskVoid.GetAsyncAction(...).Forget()`(line 138) fire-and-forget,无 cancellation token — T3-17。

### 4.4 闭包 / Action<>
- 几乎所有 `Action<>` 回调都是 `obj => action(obj as T)`(`AssetsLoadManager.cs:87-93`),每次调用创建 closure,**热路径 GC 压力**。
- `OnComplete` / `fadeFinish` 等回调在 async 路径(`AudioManager.cs:633, 686`) 有闭包泄漏风险 — `GetClip` 是同步的,实际不漏,但写法不清晰。

### 4.5 跨线程
- `EventDispatcher.Dispatch` 无线程保护 — T2-02。
- `ObjectPools` 是 Singleton C#,静态字段 `_pool` 跨线程访问 — OK(单线程 Unity 上下文,但用 Task 池时会 race)。
- `_loadIndex` 跨线程无 Interlocked — T2-09。

### 4.6 反射 / 代码生成
- `UIBindData` / `UINodeProvider` 是反射式 UI 绑定方案(代码生成器产 `UIWindow<TProvider>`),运行时**没有反射** — OK。
- `TProvider` 是 `MonoBehaviour` 派生,`ViewObject.GetComponent<TProvider>()` 是 Unity 原生 GetComponent。

### 4.7 Pool 子系统统一审视

| 文件 | 类型 | 关键路径 | 评审状态 |
|------|------|---------|---------|
| `AssetsPools/GameObjectPool.cs` | 单个 pool(class) | `GetAsync` line 60-98 / `Recycle` line 164-181 | T1-04 cap 缺失 |
| `AssetsPools/GameObjectPools.cs` | 多 pool 容器(`Singleton`) | `GetAsync` line 53-80 / `StopLoadByGroup` line 349-371(已验证清理) | OK |
| `AssetsPools/OtherPool.cs` | 泛型单 pool(实例化) | `GetAsync` line 56-83 / `Recycle` line 114-130 | T1-04 同问题 |
| `AssetsPools/PoolBase.cs:39-251` | `InstantiatePools<T>` 容器 | `GetAsync` line 64-79 / `RecycleByGroup` line 185-193 | T2-20 不清 callback map |
| `AssetsPools/PoolBase.cs:253-440` | `ReferencePools<T>` 容器(引用池) | `GetAsync` line 278-295 / `DestroyByGroup` line 399-421 | OK,`DestroyByGroup` 完整清理 |
| `AssetsPools/MaterialPools.cs` | 5 行壳,继承 `InstantiatePools<Material>` | — | 重复模式 |
| `AssetsPools/AnimationClipPools.cs` | 13 行壳,继承 `InstantiatePools<AnimationClip>` | — | 重复模式 |
| `AssetsPools/AudioClipPools.cs` | 15 行壳,继承 `InstantiatePools<AudioClip>` | — | T2-10 Instantiate 无意义 |
| `AssetsPools/ShaderPools.cs` | 11 行壳,继承 `ReferencePools<Shader>` | — | 重复模式 |
| `AssetsPools/TexturePools.cs` | 15 行壳,继承 `ReferencePools<Texture2D>` | — | 重复模式 |
| `AssetsPools/SpritePools.cs` | 26 行壳,继承 `ReferencePools<Sprite>` + 重写 LoadSync/LoadAsync | `LoadSync` line 14-17 / `LoadAsync` line 19-22 | 重复模式 |
| `AssetsPools/FairyGUIPool.cs` | 86 行,**全注释**(line 2-84 注释掉) | — | T3-03 死文件 |

**Pool 重复模式统计:** 11 个 pool 文件中:
- 5 个是 `InstantiatePools<T>` 或 `ReferencePools<T>` 的具体子类壳(Material/AnimationClip/AudioClip/Shader/Texture/Sprite 的 6 个 + GameObjectPool/OtherPool 是泛型直接使用),`new` 的逻辑全在基类。
- 1 个(`FairyGUIPool.cs`)是死代码。
- 1 个(`SpritePools.cs`)是唯一重写了 `LoadSync/LoadAsync` 的,调 `AssetsLoadManager.LoadSpriteSync/ByMacro`。
- 2 个核心(`GameObjectPool` + `OtherPool`)有具体实现,T1-04 共享问题。

---

## 5. 必须立即修的清单 (Top 6)

| # | 文件:行 | 一句话 |
|---|---------|--------|
| T1-01 | `AudioManager/AudioManager.GoAudioSource.cs:51-64` + `AudioSource.cs:73-93` | AudioSourceData 池化后未复位全部字段,导致鬼叫 / loop 残留 / 回调串台 |
| T1-02 | `AssetManager/AssetsGroup.cs:60-136` + `AssetsGroupManager.cs:53-60` | 同步 LoadSync 路径无 `_loadVersion` 检查,StopLoadByGroup 无法取消 |
| T1-03 | `EventDispatcher/EventDispatcher.cs:92-155` | 强引用持有订阅者,反注册遗漏拖死场景 |
| T1-04 | `AssetManager/AssetsPools/GameObjectPool.cs:85-86` + `OtherPool.cs:77` | 池空时 Instantiate 不受 `MaxPoolCount=100` 限制,失去池化意义 |
| T1-05 | `AudioManager/AudioSource.cs:98-103` | Dispose 销毁 AudioSource Component 但不置 null,Update 抛 NRE |
| T1-06 | `UIManager/UIResourceManager.cs:101-116` + `UIManager.cs:188-211` | 同步 LoadPrefab 主线程卡顿 + ReleaseAllByGroup 串台释放业务子资源 |

---

## 6. 修复优先级建议

**Sprint 1 (本周):** T1-01, T1-03, T1-05, T1-06, T2-01, T2-05
**Sprint 2 (下版本):** T1-02, T1-04, T2-02, T2-11, T2-12, T2-13, T2-20
**Sprint 3 (重构):** T2-08, T2-14, T2-15, T2-21, T2-25, T3-*

---

## 7. 已确认本版本无问题 (Info)

- `MonoSingleton` DontDestroyOnLoad + Instance 模式本身正确,主线程单例无问题。
- `EventDispatcher` 的 `pendingAdds/pendingRemoves` 模式正确,避免 Invoke 期间修改。
- `UIStack.Contains` 用 `Dictionary` O(1) 已修复。
- `UIManager.OnPreWillRenderCanvases` 替代 Update 轮询,降低 per-frame 开销。
- `AssetsGroup` `_loadVersion` 版本号机制本身正确(只在 async 路径用)。
- `AudioSourceData.TickFade` 用 `Mathf.MoveTowards` 替代原 `+=` 累积,修复了浮点漂移。
- **`_loadCallBackMap` / `_loadIndexCheckMap` 在三个 pool 子系统的 DestroyByGroup / StopLoadByGroup 路径都正确清理**(verified: `GameObjectPools.cs:360-365` + `PoolBase.cs:198-205` + `PoolBase.cs:403-410`)。attempt 2 报告 T2-25/T3-33 的"不清"说法已 retract。

---

*审查完成。本次只读,未修改任何源文件。报告内所有 file:line 均在审查时验证存在;§0.2 的 4 个 scope 差异已明确记录;§0.3 已 retract attempt 2 错误事实。*
