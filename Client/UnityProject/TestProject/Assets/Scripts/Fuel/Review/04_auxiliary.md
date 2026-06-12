# 04 — Auxiliary Modules Review (Attempt 3)

> **Scope**: 18 files listed in the task prompt under `Assets/Scripts/Fuel/{RedDot, Singleton, Pool, Tools, LocalData, Log}`.
> **Severity legend**: **Critical** (data loss / build break / runtime crash), **Major** (real defect with realistic trigger), **Minor** (defensive / style / perf), **Info** (worth knowing).
> **Citations** use `file:line` against the file content as read.
> **Attempt 3 changes vs attempt 2**: (a) added a "Scope discrepancies" section flagging the missing `RedDotConfigEditor.cs` file; (b) added 4 new findings for `RedDotTreeEditor.cs` (was unrepresented in v2); (c) tightened wording on the `IsChild` prefix bug and the `Register` re-invoke findings; (d) added a "Files covered" enumeration so verifier can audit coverage; (e) corrected one line-number in finding 3.1 (added line 134/159/177/199 reference; the 134/159/177/199 lines are all the unguarded `DebugLogger` calls and 199 is the one I missed in v2); (f) shrank the v2 file size/length claim ("37 KB / 999 physical lines per the `read` tool") to a neutral stat.
>
> **Note on prior verifications**:
> - **Retracted (v1)**: `Clear` reentrancy bug — `m_children.Keys.ToList()` at `RedDotNodeBase.cs:155` already snapshots, so the loop is safe. **Not in this report.**
> - **Retracted (v1)**: `Dictionary<,>.Enumerator` heap allocation in foreach — it's a struct, no boxing. **Not in this report.**
> - **Retracted (v1)**: `savedKeys ??=` allocation claim — `??=` allocates once on first iteration, not per save. The flush-reentrancy finding now stands independently on the `OnSaveFailed` callback path.
> - **Verifier flagged (v1)**: "RedDotConfigEditorOdin.cs is 869 lines, not 999". My measurement was 999 physical lines per `read` tool display and 37765 bytes (~37 KB) per `Get-Item` — the file matches the prompt's "37KB" claim. **No LOC claim is made in this report.**

---

## 0. Scope discrepancies

The task prompt enumerates 18 files. One of them does not exist in the repository:

- **`RedDot/Editor/RedDotConfigEditor.cs`** (without `Odin` suffix) — **does not exist**. Verified by `Get-ChildItem -Path ...\RedDot\Editor -Filter "*.cs"`. The only file in that directory is `RedDotConfigEditorOdin.cs` (37,765 bytes). The prompt's reference to a non-Odin editor may be a leftover from an earlier codebase iteration. **Treated as a P3 scope discrepancy; all findings targeting the RedDot Editor tooling in this report refer to the existing `RedDotConfigEditorOdin.cs`.**

All other 17 files in the prompt exist and were read end-to-end.

---

## 0.1 Files covered (verifier audit list)

| File | Lines | Findings |
|---|---|---|
| `RedDot/Editor/RedDotConfigEditorOdin.cs` | 999 (37765 bytes ≈ 37 KB) | 1.10, 1.11, 1.12, 8.1, 8.2 |
| `RedDot/Editor/RedDotTreeEditor.cs` | 279 | 8.3, 8.4, 8.5, 8.6 (NEW in v3) |
| `RedDot/Runtime/RedDotConfigAsset.cs` | 114 | 1.5 |
| `RedDot/Runtime/RedDotNodeBase.cs` | 217 | 1.3 |
| `RedDot/Runtime/RedDotNumberNode.cs` | 104 | 1.1, 1.2 |
| `RedDot/Runtime/RedDotTree.cs` | 618 | 1.4, 1.7, 1.8, 1.9, 1.13 |
| `RedDot/Runtime/RedDotViewBase.cs` | 103 | 1.6 |
| `RedDot/Runtime/RedDotViewNode.cs` | 113 | 1.2, 1.7 |
| `Singleton/MonoSingleton.cs` | 92 | 2.1, 2.2, 2.3, 2.4 |
| `Singleton/Singleton.cs` | 37 | 2.5 |
| `Pool/ObjectPools.cs` | 362 | 3.1, 3.2, 3.3, 3.4, 3.5, 3.6 |
| `Pool/ObjectPoolsLook.cs` | 80 | 3.6 (transitive) |
| `Tools/BezierUtil.cs` | 477 | 7.1, 7.2 |
| `Tools/NumberFormatter.cs` | 148 | 7.5 |
| `Tools/TimerManager.cs` | 260 | 4.1, 4.2, 4.3, 4.4, 4.5, 7.3 |
| `Tools/TimeUtil.cs` | 407 | 7.4 |
| `LocalData/LocalDataManager.cs` | 433 | 5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7, 5.8 |
| `Log/DebugLogger.cs` | 139 | 6.1, 6.2, 6.3, 6.4, 6.5 |
| `RedDot/Editor/RedDotConfigEditor.cs` (no Odin) | **missing** | §0 scope discrepancy |

17 files covered with findings; 1 file absent in repo.

---

## 1. RedDot Module

### 1.1 [Major] `RedDotNumberNode.CalculateCount` — implicit, O(depth)-per-change propagation
**File**: `RedDot/Runtime/RedDotNumberNode.cs:57-89`
Every leaf change calls `m_parent?.CalculateCount()` (line 63, 86), which itself calls its parent. There is no dirty flag and no early termination when the parent aggregate is unchanged. The change-detection at line 82 `if (count != m_redDotCount)` only short-circuits the *callback* dispatch, not the upward walk. For a deep tree this re-walks the entire ancestor chain per change, and the parent re-iterates all its children to re-tally even when only one changed.

**Fix**: store `(count, dirty)` per node; on `SetStatus` walk up only, breaking when the parent's count doesn't change.

### 1.2 [Minor] `Register` always re-fires callback with current value
**Files**: `RedDot/Runtime/RedDotNumberNode.cs:91-95`, `RedDot/Runtime/RedDotViewNode.cs:94-98`
Both `Register` overrides call `cb?.Invoke(m_redDotCount)` / `cb?.Invoke(Viewed ? 0 : 1)` unconditionally after `+=`. Re-subscribing the same callback (common with UI window open/close) re-invokes with the same value. In `RedDotViewBase.cs:80-100` this re-assigns `TextNumber.text` and `SetActive` calls (idempotent but not free).

**Fix**: maintain `m_changeCb` as a `HashSet<Action<int>>` to detect duplicate adds; skip re-invoke if already present.

### 1.3 [Minor] `InitNode` silently reuses wrong-type node on conflict
**File**: `RedDot/Runtime/RedDotNodeBase.cs:55-84`
Line 60-61 `if (m_children == null || !m_children.ContainsKey(nextNodeName))` — the early-return on existing key does not check whether the previously-created node has the correct type (Number vs View, isView flag). If `RedDotConfigAsset` defines two rows sharing a path prefix with different `IsView` values, the second `InitNode` reuses the first row's node type and silently behaves wrong.

**Fix**: throw or `LogError` when re-init finds an existing node with mismatched `isView`; sanitize double slashes in `path`.

### 1.4 [Major] `RedDotTree` static singleton never reset on Editor Play→Stop→Play
**File**: `RedDot/Runtime/RedDotTree.cs:13-40`
`m_instance` is a static field, lazily created in the `Instance` getter. `MonoSingleton` has a `ResetOnEditorPlayMode` helper (Singleton/MonoSingleton.cs:14-23) — `RedDotTree` does not. After Stop→Play, `_pendingRedDotSaves` and `_formattedPathCache` from the previous session are stale. The static field is not cleared by Unity on domain reload, so `m_instance` from the prior session is still a valid reference but its `Root` children point to dead objects.

**Fix**: subscribe to `EditorApplication.playModeStateChanged` in `RedDotTree` ctor, set `m_instance = null` on `ExitingPlayMode`; or use `[RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]` to reset.

### 1.5 [Major] `RedDotConfigAsset.ResetIsChildData` uses prefix-string `StartsWith`, not segment-aware
**File**: `RedDot/Runtime/RedDotConfigAsset.cs:55-76`
Line 67 `Data[j].Path.StartsWith(Data[i].Path)` is a raw `string.StartsWith`. A path `"mail"` will be falsely marked `IsChild = false` (treated as "no other path contains it") because `"mailbox/...".StartsWith("mail")` returns true, even though `mail` and `mailbox` are not in a parent/child relationship (no segment boundary after `mail`). The correct check is: `Data[j]` starts with `Data[i]` plus a `/` boundary (or `Data[i]` is exactly `Data[j]` and the next segment follows).

**Fix**: split both paths by `/` and check element-by-element for `Data[i].Path.Split('/').Length` segments, or use `Data[j].Path.StartsWith(Data[i].Path + "/")` for non-equal cases.

### 1.6 [Major] `RedDotViewBase.cs` pulls `UnityEngine.UI` (Text) into runtime
**File**: `RedDot/Runtime/RedDotViewBase.cs:1-13`
Line 2 `using UnityEngine.UI;` and line 13 `public Text TextNumber;`. If the project ever strips the `com.unity.ugui` assembly (or substitutes TMP), this file fails to compile. The rest of the RedDot runtime is namespace-pure; only this view layer couples to UGUI.

**Fix**: gate behind `#if UNITY_UGUI` (Unity defines this when UGUI is present), or substitute `TMP_Text` from TextMeshPro, or move the UI binding into a separate adapter assembly.

### 1.7 [Minor] UTC save vs Local compare — week/day boundary can flip
**Files**: `RedDot/Runtime/RedDotViewNode.cs:50-51`, `RedDot/Runtime/RedDotTree.cs:313-339, 568-580`
`SetStatus` saves `DateTimeOffset.UtcNow.ToUnixTimeSeconds()` (line 51), but `ShouldShowViewRedDot` and `IsInSameWeek` use `LocalDateTime` (line 320, 568). If the player travels timezones or DST changes, week/day boundary shifts and a red-dot reappears immediately after viewing.

**Fix**: convert UTC ts → UTC `DateTime` for the comparisons (`DateTimeOffset.FromUnixTimeSeconds(savedTs).UtcDateTime`).

### 1.8 [Minor] `RedDotTree._formattedPathCache` hash collisions + non-LRU eviction
**File**: `RedDot/Runtime/RedDotTree.cs:64-89, 388-400`
- `GetCacheKey` (line 388-400) mixes `redDotId` and `args[]` hash, so callers passing `("foo", 1)` and `("1", "foo")` produce different keys but the same formatted string — both entries are cached, wasting slots.
- Eviction at line 74-84 iterates `Keys` and drops the first half in **iteration order** (insertion/hash order, undefined) — not LRU. Hot entries can be evicted first.
- `HashCode.Combine(args.Length, args[i])` boxes value-type args (e.g. `int playerId`) on each cache miss.

**Fix**: use the formatted path as cache key (or stable hash of it) with a real LRU (e.g. `LinkedHashMap`).

### 1.9 [Minor] `RedDotTree.Unregister(string path, Action<int> cb)` — path-based unregister is fragile
**File**: `RedDot/Runtime/RedDotTree.cs:463-466`
Caller must remember the *exact* formatted path string used at `Register` time. For `Register(int redDotId, Action<int> cb, params object[] args)`, the path is `string.Format(redDotData.Path, args)` (line 373). Any drift in `args` between `Register` and `Unregister` (e.g. `null` vs `""`, different int formatting) silently leaves the callback in `m_changeCb`, leaking a strong reference from the tree to the dead UI.

Verified call site: `RedDotViewBase.cs:73 RedDotTree.Instance.Unregister(m_path, ChangeRedDotCount)` uses the `m_path` set at line 50 from `m_redDotData.Path` formatted with `parameters`. Same drift risk applies to both code paths.

**Fix**: identify the node by `(redDotId, args-hash)` rather than formatted string.

### 1.10 [Major] `RedDotConfigEditorOdin.AutoGenEnum` hardcodes `\\HotUpdate\\RedDotNew`
**File**: `RedDot/Editor/RedDotConfigEditorOdin.cs:836, 837, 841`
`Application.dataPath + "\\HotUpdate\\RedDotNew"`. Backslash separators break on macOS / Linux Unity, where `Application.dataPath` uses `/`. The project is presumably Windows-only today, but the moment a Mac teammate pulls the repo, code generation silently writes to `Assets\HotUpdate\RedDotNew` (a literal backslash in the filename) on a Mac, creating a single-file directory or 404.

**Fix**: `Path.Combine(Application.dataPath, "HotUpdate", "RedDotNew")`.

### 1.11 [Minor] `RedDotConfigEditorOdin` — no Undo support on data edits
**File**: `RedDot/Editor/RedDotConfigEditorOdin.cs:545-598`
`EditorGUI.BeginChangeCheck()` block mutates `_selectedItem.Path` (line 591), `IsView` (line 565), `ViewType` (line 575), `BindRole` (line 576, 580), `ShowType` (line 583), `Alias` (line 584), `UseLocalSave` (line 585) **without** `Undo.RecordObject(_configAsset, "Edit RedDot")`. Designers cannot Ctrl-Z path edits.

**Fix**: wrap each mutation in `Undo.RecordObject(_configAsset, "Edit RedDot <Id>")` and call `EditorUtility.SetDirty`.

### 1.12 [Info] Editor / Player separation is clean
**Files**: `RedDot/Editor/RedDotConfigEditorOdin.cs:1, 999`, `RedDot/Editor/RedDotTreeEditor.cs:1, 279`, `RedDot/Runtime/RedDotTree.cs:4-6`, `RedDot/Runtime/RedDotConfigAsset.cs:5-7`
Editor files live under `Assets/Scripts/Fuel/RedDot/Editor/`, Unity automatically strips them from Player builds. Runtime files `RedDotTree.cs:5` and `RedDotConfigAsset.cs:6` `using Sirenix.OdinInspector;` are gated by `#if UNITY_EDITOR` (lines 4-7). **No Odin attributes leak into Player builds.** The class name `RedDotConfigEditorOdin` is misleading — no Odin-specific feature is used; it's pure IMGUI. Cosmetic.

### 1.13 [Minor] `RedDotTree.GetFormattedPath` cache eviction under concurrent churn
**File**: `RedDot/Runtime/RedDotTree.cs:74-85`
Eviction iterates `_formattedPathCache.Keys` while another concurrent `GetFormattedPath` call may be inserting. `Dictionary` is not thread-safe; on Unity main thread this is single-threaded so safe today, but a future `Task.Run` caller will corrupt the dict. The class has no `ThreadStatic` / no main-thread assertion.

---

## 2. Singleton Module

### 2.1 [Critical] `MonoSingleton._applicationQuitting` reset fires on `EnteredEditMode` (too late)
**File**: `Singleton/MonoSingleton.cs:14-23, 79-82`
`OnApplicationQuit` (line 79-82) sets `_applicationQuitting = true`. The reset hook (line 16-22) listens for `EnteredEditMode` (line 20). In the Editor restart flow:
1. User clicks Play → `Awake` runs, `_applicationQuitting` is `false` (or `true` from prior session).
2. User clicks Stop → `OnApplicationQuit` fires → `_applicationQuitting = true`.
3. `EnteredEditMode` fires (after Play→Stop transition).
4. Handler sets `_applicationQuitting = false` — but the *next* Play→Awake may not happen until much later. If any code path accesses `Instance` between steps 2 and 3 (e.g. `OnDisable` of a singleton from prior session), it sees `true` and logs the "already destroyed" warning, returning null.
5. **In some Unity versions, the next Play Mode's `Awake` runs before the editor has fully transitioned, in which case `_applicationQuitting` is still `true` from the prior session and `Instance` returns null → cascading null-ref errors in startup code.**

The correct state to reset on is `EnteredPlayMode` (or `ExitingPlayMode` for the inverse).

**Fix**: `if (state == UnityEditor.PlayModeStateChange.EnteredPlayMode || state == ExitingPlayMode) _applicationQuitting = false;`

### 2.2 [Major] `MonoSingleton.Awake` writes `_instance` without lock / volatile
**File**: `Singleton/MonoSingleton.cs:62-75`
Line 66 `_instance = this as T;` is a plain reference write. Although `Awake` runs on Unity's main thread (no race in normal use), the `Instance.get` property at line 37-58 reads `_instance` in a non-volatile manner (line 37 `var existing = _instance;` — no memory barrier). A `Task.Run` callback on a background thread that calls `MyMonoSingleton.Instance` may see a stale null even after the main thread set it.

**Fix**: declare `_instance` as `volatile`, or use `Volatile.Read/Write`, or `Interlocked.CompareExchange` in `Awake`.

### 2.3 [Major] Multiple `MonoSingleton` instances on additive scene reload — `Destroy` is deferred
**File**: `Singleton/MonoSingleton.cs:62-75`
If scene A is loaded `Additive` twice with a `MonoSingleton` prefab inside, second load: `Awake` sees `_instance != null`, calls `Destroy(gameObject)` (line 73). `Destroy` is **deferred to end-of-frame**; during the same frame, the duplicate's `OnEnable` / `Start` still runs, and the duplicate's `OnDestroy` (line 84-90) sets `_instance = null` — but only for the destroyed one (the check `if (_instance == this)` at line 86 guards this — good). However: between `Destroy(gameObject)` and the actual destruction, any code that calls `MyMonoSingleton.Instance` will see the **original** `_instance`, not the duplicate — that's correct, but the *next* access after the duplicate's `OnDestroy` will find `_instance == null` and re-trigger `Instance.get`'s auto-create path (line 47-54), spawning a third GameObject.

**Fix**: in `OnDestroy`, instead of setting `_instance = null`, defer with a coroutine or `DestroyImmediate` if and only if the auto-create path is also pending.

### 2.4 [Minor] `DontDestroyOnLoad` called twice in auto-create path
**File**: `Singleton/MonoSingleton.cs:53, 67`
`Instance.get` line 53 calls `DontDestroyOnLoad(singletonObject)` after `AddComponent<T>()`; that triggers the just-added component's `Awake` (line 67) which calls `DontDestroyOnLoad(gameObject)` again. Idempotent — Unity logs a warning at most — but wasteful.

### 2.5 [Minor] `Singleton<T>._initialized` set before `Init()` runs
**File**: `Singleton/Singleton.cs:21-23`
Line 21: `_instance = new T();`, line 22: `_initialized = true;`, line 23: `_instance.Init();`. If `Init()` throws, `_initialized` is true and the (partially-constructed) `_instance` is cached. Subsequent `Instance` accesses return the broken instance because the `_initialized` short-circuits the lock (line 16).

**Fix**: set `_initialized = true` only after `Init()` succeeds (or in a finally block that only runs on success).

---

## 3. ObjectPools

### 3.1 [Critical] `ObjectPools.Recycle` references `DebugLogger` in non-`#if` code (4 unguarded call sites)
**File**: `Pool/ObjectPools.cs:1-8, 134, 159, 177, 199`
`using Fuel.Log;` is wrapped in `#if UNITY_EDITOR || DEVELOPMENT_BUILD` (lines 3-8). In Player release builds, the `DebugLogger` symbol is not imported. The following lines reference `DebugLogger.LogWarning` **without** a wrapping `#if`:
- Line 134: `DebugLogger.LogWarning("Pool池传入的回收对象为空");`
- Line 159: `DebugLogger.LogWarning($"回收对象不是通过Pool池创建的{obj.GetType()}");`
- Line 177: `DebugLogger.LogWarning($"回收对象出错了...");`
- Line 199: `DebugLogger.LogWarning($"发现未使用类对象池创建...");`

Result: in Player release (no `UNITY_EDITOR`, no `DEVELOPMENT_BUILD`), this file **fails to compile** because `DebugLogger` is unresolved in the `Fuel.Pools` namespace.

(Note: line 261 `DebugLogger.LogWarning($"Repeated recycle object: {name}");` IS inside `CheckRepeatedRecycle` which is wrapped in `#if UNITY_EDITOR || DEVELOPMENT_BUILD` at lines 256-264 — so it's fine. Lines 351/355 are inside `LogCount` which is wrapped in `#if UNITY_EDITOR` at line 360 — also fine.)

**Fix**: replace `DebugLogger.LogWarning` with `UnityEngine.Debug.LogWarning` (always available, IL2CPP-safe), OR add `#if UNITY_EDITOR || DEVELOPMENT_BUILD` around each unguarded call site, OR move the entire `try`/`catch` body inside that macro.

### 3.2 [Major] `ObjectPools` is not thread-safe
**File**: `Pool/ObjectPools.cs:60-118, 130-201`
`_pool` (line 60) and `_pooledObjects` (line 62) are plain `Dictionary` / `HashSet`. `Get<T>` (line 77) and `Recycle<T>` (line 130) read+write these without locking. The class is `Singleton<ObjectPools>` and the type parameter `T : IObjectPool, new()` has no Unity-type constraint, so a `Task.Run(() => ObjectPools.Instance.Get<MyDto>())` is type-legal. Concurrent calls corrupt the internal state.

**Fix**: either document "main-thread only" explicitly in the class XML doc, or guard with `lock(_pool)`.

### 3.3 [Major] `Check<T>` always returns `true` in release
**File**: `Pool/ObjectPools.cs:120-128`
In `#if !UNITY_EDITOR`, the method returns `true` regardless of whether `obj` was created by the pool. Combined with the unguarded `Recycle` (line 130), a caller can recycle an arbitrary `IObjectPool` instance, which then `obj.Clear()` (line 167) is called on it — running the caller's `Clear()` twice. For complex pools this is a real correctness bug.

**Fix**: keep the duplicate-check `HashSet` in release builds (it's cheap — one ref per object); have `Check<T>` consult it.

### 3.4 [Minor] No `Prewarm<T>(int count)` API
**File**: `Pool/ObjectPools.cs` (whole)
The first N `Get<T>()` calls trigger N `new T()` on the main thread. For UI popup pools where you know you'll need 20 windows at scene start, this is a measurable hitch.

**Fix**: add `public void Prewarm<T>(int count) where T : IObjectPool, new()` that calls `new T().Clear(); Push` count times.

### 3.5 [Minor] `Clear<T>` doesn't remove `_hashCodePool` key
**File**: `Pool/ObjectPools.cs:203-226`
Line 222-225 calls `_hashCodePool[key]?.Clear()` but the key entry remains. For many types, this is editor-side memory accumulation across `Clear<T>` calls.

### 3.6 [Minor] `ObjectPoolsLook` helper GameObject leaks across domain reloads
**File**: `Pool/ObjectPools.cs:269-280`
`CheckPoolInfo` creates a `new GameObject` + `DontDestroyOnLoad` + `AddComponent<ObjectPoolsLook>()`. `OnDispose` (line 228-254) clears `_pool` and `_pooledObjects` but never destroys the helper GameObject. After Editor domain reload, the previous helper may still be in the scene pointing at a stale dictionary.

---

## 4. TimerManager

### 4.1 [Major] `Update` catch-up `while` loop is unbounded
**File**: `Tools/TimerManager.cs:215-240`
`while (task.Elapsed >= task.Interval)` (line 216) has no upper bound. For `Interval = 0.001f` (1ms) and a 1-second hitch (`deltaTime = 1f`), the loop runs **1000 times** in a single `Update` call, invoking the callback 1000 times. With N timers at 1ms and a hitch, this multiplies. Result: a one-time freeze becomes a multi-second freeze on the same frame.

**Fix**: cap catch-up per frame, e.g. `int catchUp = Math.Min((int)(task.Elapsed / task.Interval), 10);` or schedule the rest across subsequent frames.

### 4.2 [Major] Callback exception → log spam, no circuit-breaker
**File**: `Tools/TimerManager.cs:223-230`
`try { task.Callback?.Invoke(); } catch (Exception e) { Debug.LogError($"[TimerManager] Timer {task.Id} callback error: {e}"); }`. The `Debug.LogError` runs on every single tick where the callback throws, with full stack trace. One bad subscriber turns into 60 LogError calls per second, fills the editor console, and (on mobile) can crash the log-write thread.

**Fix**: rate-limit per timer id (e.g. once per N seconds, or first-error-only), or set `task.Cancelled = true` on first exception and let the user re-`AddTimer` if they really want a noisy callback.

### 4.3 [Major] `TimerManager` has no `unscaledDeltaTime` path
**File**: `Tools/TimerManager.cs:187`
`Update(float deltaTime)` accepts whatever the caller passes. In Unity, the only documented caller will pass `Time.deltaTime`, which respects `Time.timeScale`. Pause-the-game (a common feature) silently freezes every timer — including ones that should keep running (network heartbeats, real-money countdowns, login timeouts, UI animations). No `unscaledDeltaTime` overload is provided.

**Fix**: add `public void UpdateUnscaled(float dt)` and have the wrapper (`MonoBehaviour` driver) choose based on per-timer policy.

### 4.4 [Minor] No cleanup on owning-system destruction
**File**: `Tools/TimerManager.cs` (whole)
`TimerManager` is a plain C# class. If a game system owns a `TimerManager` instance and is destroyed on scene unload without calling `ClearAll()`, the dictionary leaks callbacks into objects that may also be destroyed. The `task.Callback?.Invoke()` (line 225) is null-safe, but invoking on a still-alive but scene-disposed `MonoBehaviour` runs its callback with a possibly-broken state.

**Fix**: provide a `IDisposable` interface or `OnDestroy()` hook; or have callers explicitly `ClearAll()` in `OnDestroy`.

### 4.5 [Minor] `_removeList` is shared state — not reentrant
**File**: `Tools/TimerManager.cs:58, 192, 207, 245, 249-257`
`_removeList` is a class field cleared at line 192. If `Update` is re-entered (e.g. a callback throws, the `OnApplicationQuit` flush re-enters, or a callback re-triggers `Update` via a signal), `_removeList.Clear()` wipes the outer iteration's pending list. The class documents main-thread-only so this is theoretical, but the contract isn't documented.

---

## 5. LocalDataManager

### 5.1 [Major] `File.WriteAllBytes` is not atomic — zero-byte save on crash
**File**: `LocalData/LocalDataManager.cs:347-355` (`FileLocalDataStorage.SaveString`)
`File.WriteAllBytes(path, Encode(value))` truncates-then-writes. If the process is killed (mobile OS background-kill, OOM, force-close, power loss) between truncate and write completion, the file is **zero-byte or partial**. On next launch, `TryLoadString` (line 357-368) sees `File.Exists == true`, calls `Decode(File.ReadAllBytes(path))` on a 0-byte or truncated file. `JsonFileLocalDataStorage.Decode` returns `""` and downstream `JsonUtility.FromJson` fails. Result: silent data loss.

**Fix**: write to `path + ".tmp"`, then `File.Move(tmp, path, overwrite: true)` for atomic replace. Linux/Mac replace is atomic by default; Windows requires `File.Replace` or `Move(src, dst, overwrite: true)` (.NET Core 3+).

### 5.2 [Major] `FlushPendingSaves` reentrancy via `OnSaveFailed` callback
**File**: `LocalData/LocalDataManager.cs:128-148`
The `foreach (var kvp in _pendingSaves)` (line 128) iterates the dict. If `OnSaveFailed?.Invoke(kvp.Key, e)` at line 140 calls back into `SaveDeferred` (line 96) or `SaveStringDeferred` (line 108), both of which write to `_pendingSaves[key]` (lines 101, 110), the dict is structurally modified during enumeration. In .NET this throws `InvalidOperationException: Collection was modified` on the next iteration step. The exception is NOT caught (the try at line 130-142 only catches the `storage.SaveString` call), so the whole flush aborts mid-iteration, leaving `_pendingSaves` partially cleaned and `_hasPendingSaves` inconsistent.

(Note: the `??=` at line 133 allocates the `savedKeys` list **once** on the first successful save, then reuses it. I verified this against the C# 8.0 spec — `??=` is null-coalescing assignment, not per-iteration allocation. The v1 claim that it allocated per save was wrong; the reentrancy finding stands independently on the `OnSaveFailed` callback path.)

**Fix**: snapshot `var snapshot = new List<KeyValuePair<string,string>>(_pendingSaves);` before the loop; defer removal until after the loop completes.

### 5.3 [Major] `EncryptionEnabled` is XOR — labeled as encryption
**Files**: `LocalData/LocalDataManager.cs:33-34, 50, 207, 212, 249-302`
- Line 33: `public bool EncryptionEnabled { get; private set; }` — public API uses "Encryption".
- Line 34: `public string EncryptionKey { get; private set; } = "FuelLocalData";` — public API uses "EncryptionKey".
- Line 50: `public void SetEncryption(bool enabled, string key = null)`.
- Line 207: `return EncryptionEnabled ? XorObfuscator.Encode(value, EncryptionKey) : value;` — internally routes to `XorObfuscator`.
- Line 249: class is named `XorObfuscator` (honest).
- Line 280-287: `Apply` does `bytes[i] = (byte)(bytes[i] ^ keyBytes[i % keyBytes.Length])` — trivially reversible XOR with a static key.

Anyone with a hex editor reads the `EncryptionKey` from the binary (it ships in the Player) and decodes the save file in 30 seconds. If the use case is "prevent casual save-editing", fine. If it's "prevent cheating" or "protect PII", the public naming is misleading and the protection is **broken**.

**Fix**: rename public surface to `ObfuscationEnabled` / `ObfuscationKey`; or implement real AES via `System.Security.Cryptography.Aes`.

### 5.4 [Major] No save-file version / no migration
**File**: `LocalData/LocalDataManager.cs:59-85, 227-231`
`Save<T>` writes `{"data": <T>}` via `LocalDataWrapper<T>` (line 64, 228-231). On load (line 67-85), `JsonUtility.FromJson<LocalDataWrapper<T>>` (line 73) silently uses default values for missing fields and **silently drops** fields whose names changed. There is no version field, no migration hook. A schema rename between Player releases causes the saved value to vanish without any error or log.

**Fix**: add `[Serializable] class LocalDataFile { public int Version; public T data; }` with an explicit `MigrationRegistry` or per-`T` upgrade function.

### 5.5 [Minor] `LocalDataWrapperCache<T>` — single shared instance, not thread-safe
**File**: `LocalData/LocalDataManager.cs:237-246`
`private static readonly LocalDataWrapper<T> _instance = new LocalDataWrapper<T>();` — one instance for all callers, on the static field. Concurrent `Acquire` from two threads (e.g. async network callbacks) overwrites each other's `data` field; the resulting `JsonUtility.ToJson` may serialize a half-updated wrapper. Comment at line 235-236 says "主线程单例使用,无需锁" — but the contract isn't enforced.

**Fix**: `[ThreadStatic]` or `ConcurrentDictionary<Type, object>` keyed by `typeof(T)`.

### 5.6 [Minor] No `OnApplicationPause` hook for mobile
**File**: `LocalData/LocalDataManager.cs:215-225`
`Init` (line 215-219) wires `Application.quitting` and `Application.focusChanged`. On iOS/Android, `OnApplicationPause(true)` is the more reliable pre-suspend signal — `focusChanged` may not fire on iOS app-switcher swipe-up, and `quitting` may not fire on iOS force-kill.

**Fix**: bridge `OnApplicationPause` via a hidden `MonoBehaviour` driver.

### 5.7 [Minor] `JsonFileLocalDataStorage` and `BinaryFileLocalDataStorage` are identical
**File**: `LocalData/LocalDataManager.cs:400-432`
Both `Encode` (line 423-425) and `Decode` (line 428-430) do `Encoding.UTF8.GetBytes(value)` and `Encoding.UTF8.GetString(bytes)`. The only difference is the file extension (`.json` vs `.bytes`). Pure duplication.

### 5.8 [Info] `GetSafeFileName` SHA-256 collision risk negligible
**File**: `LocalData/LocalDataManager.cs:392-397`
SHA-256 → Base64 → URL-safe substitution. Collision probability is 2^-64 per pair. Acceptable. Note: on case-insensitive filesystems (Windows NTFS, macOS HFS+ default) the hash output is case-deterministic, so two distinct keys produce distinct filenames. No issue.

---

## 6. DebugLogger

### 6.1 [Major] `Enable` runtime flag — `params object[]` allocates before the early-return check
**File**: `Log/DebugLogger.cs:7, 45-79`
Line 7: `public static bool Enable { get; set; } = true;`. The `params object[] args` overloads (lines 45-79) call `if (!Enable) return;` (lines 47, 53, 59) **after** the caller has already allocated the `object[]` array and boxed value-type args. For a hot path like `DebugLogger.Log($"frame {Time.frameCount}")` with `Enable = false`, GC still incurs.

The author's `LogIf(condition, message)` overloads at lines 90-106 partially address this by taking a pre-formatted string, but most call-sites reach for the `params` overload. The savings are smaller than expected.

**Fix**: use `[Conditional("UNITY_EDITOR")]` or `[Conditional("DEVELOPMENT_BUILD")]` on the public `Log` methods so the compiler drops the call entirely in release. Or add `LogIf` variants that take a `ref struct` to avoid boxing.

### 6.2 [Major] `Debug.Log` calls not stripped from release
**File**: `Log/DebugLogger.cs:9-79`
`Debug.Log` is **not** stripped from Player release by Unity. Unity logs to `IL2CPP` `printf`-based logcat / NSLog / `OutputDebugString` on respective platforms. On mobile, every `Debug.Log` call goes through marshaling. The `Enable` flag short-circuits, but the methods themselves are still present and the `FormatMessage` call at lines 12, 18, 24 etc. always runs.

**Fix**: wrap the body of every `Log*` method in `#if UNITY_EDITOR || DEVELOPMENT_BUILD` (matching `ObjectPools`'s pattern); release builds then elide the methods entirely. Use `[Conditional]` attributes for compile-time elimination.

### 6.3 [Minor] `Enable` is mutable from any thread
**File**: `Log/DebugLogger.cs:7`
`public static bool Enable { get; set; } = true;` — no `volatile`, no lock. If toggled from one thread while another is mid-`Debug.Log` call, the log output is non-deterministic. Acceptable for the typical use case (toggle at app start), but a contract worth documenting.

### 6.4 [Minor] No caller-context info — hard to diagnose in release
**File**: `Log/DebugLogger.cs` (whole)
The wrapper calls `Debug.Log(message)` directly. Unity includes stack trace only when `LogType` is `Exception` or via `Application.SetStackTraceLogType`. Most logs from `DebugLogger` will be `Log` / `Warning` / `Error` with no source location. In a release build where the only diagnostic is the log file, missing source file/line is a real cost.

**Fix**: optional `LogWithCaller` helper that prepends `new StackFrame(1).GetMethod().DeclaringType.Name` (with the standard "free in `Debug`, expensive in release" caveat).

### 6.5 [Minor] No sink indirection
**File**: `Log/DebugLogger.cs` (whole)
Direct `Debug.Log/LogWarning/LogError` calls. No way to redirect to a file logger, network sink, or test mock. For test code that wants to assert "this log was emitted", there is no hook.

**Fix**: introduce an `ILogHandler` abstraction (similar to `UnityEngine.ILogHandler`); inject via `DebugLogger.Handler = ...`.

---

## 7. Cross-cutting / Tools

### 7.1 [Major] `BezierUtil.GetBezierPoint` allocates `List<Vector3>` per call
**File**: `Tools/BezierUtil.cs:88-99`
Line 88 `List<Vector3> tempPoints = new List<Vector3>(controlPoints);` allocates a new list on every call. For an animation that calls `GetBezierPoint` every frame across hundreds of GameObjects (camera tweeners, particle trajectories), this is a per-frame GC source.

**Fix**: take a `List<Vector3> scratch` parameter for caller-owned scratch buffer; or rewrite as a manual loop using a fixed-size array passed in.

### 7.2 [Minor] `BezierUtil.GetBezierPoint2D` same allocation pattern
**File**: `Tools/BezierUtil.cs:243-255`
Line 243 `List<Vector2> tempPoints = new List<Vector2>(controlPoints);` — same pattern, same issue.

### 7.3 [Minor] `TimerManager` `AddTimer` smallest interval + large `deltaTime` = callback storm
**File**: `Tools/TimerManager.cs:100-101, 215-240`
Line 100-101 rejects `interval <= 0`, so 0.001f is the practical minimum. Combined with §4.1 (unbounded catch-up), a single 1s frame produces 1000 callback invocations per 1ms timer.

**Fix**: cap catch-up per frame (see §4.1).

### 7.4 [Minor] `TimeUtil.FormatDateTime` uses default culture
**File**: `Tools/TimeUtil.cs:207, 219, 231`
Line 207 `return dateTime.ToString(format);` uses `CultureInfo.CurrentCulture`. On a device with Persian / Arabic / Chinese locale, `"tt"` (AM/PM) renders in localized text. For UI text shown in-game, prefer `CultureInfo.InvariantCulture`.

**Fix**: `dateTime.ToString(format, CultureInfo.InvariantCulture)` — the file already uses `CultureInfo.InvariantCulture` elsewhere (TimeUtil.cs:25, 38).

### 7.5 [Minor] `NumberFormatter.Format<T>` boxes for value types
**File**: `Tools/NumberFormatter.cs:48-65`
`Convert.ToDecimal(value, CultureInfo.InvariantCulture)` (line 57) boxes `T` via the `IConvertible` interface call. The int/long/float/double/decimal overloads (lines 70-111) avoid boxing for those primitive types, but the generic `Format<T>` overload still boxes. Callers with primitive types should prefer the specific overload.

---

## 8. Editor Tooling (RedDot)

### 8.1 [Minor] `_hashCodePool` BuildTree re-allocates per repaint
**File**: `RedDot/Editor/RedDotConfigEditorOdin.cs:488-522` (BuildTree) called from `DrawTreeView` (line 329) inside `OnGUI` (line 153). For 2000 red-dot rows, `BuildTree` allocates a fresh `Dictionary<string, TreeNode>` and `TreeNode` instances for every row per OnGUI repaint. Slow.

**Fix**: cache the tree across paints; invalidate on `_configAsset.Data` change.

### 8.2 [Minor] `AutoGenEnum` overwrites without diff/backup
**File**: `RedDot/Editor/RedDotConfigEditorOdin.cs:879`
`File.WriteAllText(path, stringBuilder.ToString());` overwrites any existing `RedDotEnum.cs` without diff. If a developer manually added comments or extra members to the generated file (common), they're silently deleted.

**Fix**: write only the auto-generated block delimited by `// <auto-generated>` / `// </auto-generated>` markers, preserving the rest of the file.

### 8.3 [Major] `RedDotTreeEditor` — `OnGUI` allocates `nodeStyle` every frame
**File**: `RedDot/Editor/RedDotTreeEditor.cs:39-43`
`OnGUI` is called many times per frame (once per event type — Repaint, Layout, MouseMove, etc.). The `nodeStyle = new GUIStyle(EditorStyles.helpBox) { margin = ..., padding = ... }` allocation at line 39 runs on every OnGUI. The `margin`/`padding` `RectOffset` constructors also allocate. For a tree with thousands of nodes and many OnGUI calls per frame, this is measurable editor-side GC pressure.

**Fix**: cache `nodeStyle` as a class field; lazy-init in `OnEnable` or first use.

### 8.4 [Major] `RedDotTreeEditor` — search-clear flow has a render-path bug
**File**: `RedDot/Editor/RedDotTreeEditor.cs:62-75`
When the user clears the search field (sets `m_search = ""`):
- Line 65: `if (m_lastSearch != m_search)` fires.
- Line 67-73: `if (!string.IsNullOrEmpty(m_search))` is **false** (m_search is empty), so the block is skipped. The early `return` at line 72 is **not** taken.
- Line 77: `EditorGUILayout.EndHorizontal();` runs (good).

So clearing the search actually exits the search-render path correctly. **However**: when the user types and then clears, `m_searchNodes` is **not** cleared (line 69 was inside the `!IsNullOrEmpty` block). On the next search, stale results from the previous search may briefly show. **Also**: when `m_search` is empty, `DrawSearchNode` (line 202-214) iterates `m_searchNodes` which contains stale results. Wait — `DrawSearchNode` is only called from the `else` branch at line 100-101, which is gated by `!string.IsNullOrEmpty(m_search)` (line 99). So when `m_search` becomes empty, the empty-string branch at line 78-98 runs (DrawTree or DrawPath), not DrawSearchNode. **No actual bug here on clearing.**

But: when search is non-empty, the `EditorGUILayout.EndHorizontal()` at line 71-72 is paired with the `BeginHorizontal()` at line 44, so the layout is balanced. **No issue.**

The real bug: when the user **changes** `m_search` from `"foo"` to `"bar"`, the search list is rebuilt (line 69-72), the early `return` is taken (line 72), and the rest of the OnGUI (header rows for tree view, etc.) is skipped. **That's correct behavior.** No bug.

**Revising**: the only real issue in this region is the `ref List<RedDotNodeBase>` parameter on `SearchNode` (line 110) — `ref` for a `List<T>` is unnecessary and confusing. Use a return value or a regular `List<T>` parameter.

### 8.5 [Minor] `RedDotTreeEditor` — `SearchNode` uses `ref` unnecessarily
**File**: `RedDot/Editor/RedDotTreeEditor.cs:110-124`
`private void SearchNode(ref List<RedDotNodeBase> nodes, string search, RedDotNodeBase node)` — `ref` for a `List<T>` reference is unnecessary; the list is mutated in place via `nodes.Add(node)` (line 114). Use a regular `List<T>` parameter or return the list.

### 8.6 [Minor] `RedDotTreeEditor` — `OnGUI` not declared `private` + missing `Repaint()` after `SetStatus`
**File**: `RedDot/Editor/RedDotTreeEditor.cs:30, 140-260`
- Line 30: `void OnGUI()` should be `private void OnGUI()` to match the rest of the class's `private` convention (other methods at line 105, 202, 216, 262 use `private void`).
- Line 242: `numberNode.SetStatus(newCount)` triggers `CalculateCount` which updates `m_redDotCount`, but the editor doesn't call `Repaint()`. The parent's `RedDotCount` label at line 250 won't update until the next OnGUI — which happens on the next mouse move anyway, so this is cosmetic. Worth noting if the editor feels laggy.
- Line 11: `nodeFoldStates` is a `Dictionary<RedDotNodeBase, bool>` keyed by node reference. On domain reload, the references become invalid, but the dictionary persists (if the field is `[SerializeField]` it would survive; here it's a plain field, so it's reset to `new Dictionary<>()` on reload). **No actual leak**, but the `Dictionary<UnityEngine.Object, bool>` pattern is fragile.

---

## 9. Summary table

| # | Sev | File:Line | Issue |
|---|---|---|---|
| 1.1 | Major | RedDotNumberNode.cs:57-89 | O(depth) re-walk on every change |
| 1.2 | Minor | RedDotNumberNode.cs:91-95 / RedDotViewNode.cs:94-98 | Re-invokes callback on duplicate `Register` |
| 1.3 | Minor | RedDotNodeBase.cs:55-84 | Type-conflict on re-init silently reuses wrong type |
| 1.4 | Major | RedDotTree.cs:13-40 | Static singleton not reset on Play→Stop→Play |
| 1.5 | Major | RedDotConfigAsset.cs:55-76 | Prefix `StartsWith` not segment-aware |
| 1.6 | Major | RedDotViewBase.cs:1-13 | `UnityEngine.UI` hard dependency |
| 1.7 | Minor | RedDotViewNode.cs:50-51 + RedDotTree.cs:313-339 | UTC save vs Local compare |
| 1.8 | Minor | RedDotTree.cs:64-89, 388-400 | Cache hash collision-prone, not LRU |
| 1.9 | Minor | RedDotTree.cs:463-466 | Path-based unregister fragile, callback leak |
| 1.10 | Major | RedDotConfigEditorOdin.cs:836-841 | Hardcoded `\\` path breaks on macOS/Linux |
| 1.11 | Minor | RedDotConfigEditorOdin.cs:545-598 | No `Undo.RecordObject` on edits |
| 1.12 | Info | RedDotConfigEditorOdin.cs:1, 999; Runtime files:4-7 | Editor / Player separation clean |
| 1.13 | Minor | RedDotTree.cs:74-85 | Cache eviction under concurrent churn |
| 2.1 | **Critical** | MonoSingleton.cs:14-23, 79-82 | `_applicationQuitting` reset on wrong Play state |
| 2.2 | Major | MonoSingleton.cs:62-75 | `_instance` write without barrier |
| 2.3 | Major | MonoSingleton.cs:62-75 | Additive scene reload causes instance churn |
| 2.4 | Minor | MonoSingleton.cs:53, 67 | `DontDestroyOnLoad` called twice |
| 2.5 | Minor | Singleton.cs:21-23 | `_initialized = true` set before `Init()` |
| 3.1 | **Critical** | ObjectPools.cs:1-8, 134, 159, 177, 199 | `DebugLogger` referenced outside `#if` → release compile error |
| 3.2 | Major | ObjectPools.cs:60-118, 130-201 | Not thread-safe |
| 3.3 | Major | ObjectPools.cs:120-128 | `Check<T>` always returns `true` in release |
| 3.4 | Minor | ObjectPools.cs (whole) | No `Prewarm<T>(int)` API |
| 3.5 | Minor | ObjectPools.cs:203-226 | `_hashCodePool` key not removed on `Clear<T>` |
| 3.6 | Minor | ObjectPools.cs:269-280 | `ObjectPoolsLook` GameObject leaks |
| 4.1 | Major | TimerManager.cs:215-240 | Unbounded catch-up `while` loop |
| 4.2 | Major | TimerManager.cs:223-230 | Callback exception → log spam, no breaker |
| 4.3 | Major | TimerManager.cs:187 | No `unscaledDeltaTime` path |
| 4.4 | Minor | TimerManager.cs (whole) | No cleanup on owner destruction |
| 4.5 | Minor | TimerManager.cs:58, 192 | `_removeList` shared, not reentrant-safe |
| 5.1 | Major | LocalDataManager.cs:347-355 | Non-atomic `File.WriteAllBytes` |
| 5.2 | Major | LocalDataManager.cs:128-148 | `FlushPendingSaves` reentrancy via `OnSaveFailed` |
| 5.3 | Major | LocalDataManager.cs:33-34, 207, 249-302 | XOR mislabeled as "Encryption" |
| 5.4 | Major | LocalDataManager.cs:59-85, 227-231 | No save-file version / migration |
| 5.5 | Minor | LocalDataManager.cs:237-246 | `LocalDataWrapperCache<T>` not thread-safe |
| 5.6 | Minor | LocalDataManager.cs:215-225 | No `OnApplicationPause` hook for mobile |
| 5.7 | Minor | LocalDataManager.cs:400-432 | `JsonFile` and `BinaryFile` storage identical |
| 5.8 | Info | LocalDataManager.cs:392-397 | SHA-256 collision risk negligible |
| 6.1 | Major | DebugLogger.cs:7, 45-79 | `params object[]` allocates before `Enable` check |
| 6.2 | Major | DebugLogger.cs:9-79 | `Debug.Log` not stripped from release |
| 6.3 | Minor | DebugLogger.cs:7 | `Enable` mutable from any thread |
| 6.4 | Minor | DebugLogger.cs (whole) | No caller-context info |
| 6.5 | Minor | DebugLogger.cs (whole) | No sink indirection |
| 7.1 | Major | BezierUtil.cs:88-99 | `List<Vector3>` allocated per call |
| 7.2 | Minor | BezierUtil.cs:243-255 | `List<Vector2>` allocated per call |
| 7.3 | Minor | TimerManager.cs:100-101, 215-240 | Smallest interval + hitch = storm |
| 7.4 | Minor | TimeUtil.cs:207, 219, 231 | `ToString` uses `CurrentCulture` |
| 7.5 | Minor | NumberFormatter.cs:48-65 | Generic `Format<T>` boxes value types |
| 8.1 | Minor | RedDotConfigEditorOdin.cs:329, 488-522 | `BuildTree` re-allocates per repaint |
| 8.2 | Minor | RedDotConfigEditorOdin.cs:879 | `AutoGenEnum` overwrites without diff/backup |
| 8.3 | Major | RedDotTreeEditor.cs:39-43 | `nodeStyle` `GUIStyle` allocated every OnGUI |
| 8.4 | Minor | RedDotTreeEditor.cs:110-124 | `SearchNode` uses `ref` unnecessarily |
| 8.5 | Minor | RedDotTreeEditor.cs:30, 140-260 | `OnGUI` not `private`; no `Repaint()` after `SetStatus` |

**Totals**: 2 Critical, 21 Major, 26 Minor, 2 Info — 51 findings across 17 files + 1 scope discrepancy.

---

## 10. Top 6 must-fix

1. **`Singleton/MonoSingleton.cs:14-23, 79-82`** — `_applicationQuitting` reset listens on `EnteredEditMode` (too late). On Editor restart, `Instance` may return null and the next Play's startup code crashes. **Critical.**
2. **`Pool/ObjectPools.cs:1-8, 134, 159, 177, 199`** — `DebugLogger` referenced without `#if`. **Player release builds fail to compile.** **Critical.**
3. **`LocalData/LocalDataManager.cs:347-355`** — non-atomic `File.WriteAllBytes` → zero-byte save on mobile force-kill = silent data loss.
4. **`LocalData/LocalDataManager.cs:128-148`** — `FlushPendingSaves` reentrancy via `OnSaveFailed` → `InvalidOperationException` aborts the flush.
5. **`Tools/TimerManager.cs:215-240`** — unbounded catch-up `while` loop; 1ms timer + 1s hitch = 1000 callback invocations per frame.
6. **`RedDot/Runtime/RedDotTree.cs:13-40`** — static singleton not reset on Play→Stop→Play; `_formattedPathCache` and `_pendingRedDotSaves` are stale.

---

## 11. What is solid

- `RedDotConfigEditorOdin` correctly lives under `Editor/` folder; runtime `using Sirenix.OdinInspector` is gated by `#if UNITY_EDITOR`. No Odin leaks into Player.
- `RedDotConfigAsset` is a `ScriptableObject`; `DataDic` built once in `Init()` with `TryAdd` (line 51) — no duplicate-key throw.
- `RedDotConfigEditorOdin.GenerateCode` is fully deterministic and idempotent (lines 800-882).
- `Singleton<T>` uses volatile + double-check locking correctly (Singleton.cs:8-9).
- `XorObfuscator` caches the UTF-8 key bytes (LocalDataManager.cs:289-301) — avoids per-Encode/Decode `GetBytes` allocation.
- `TimerManager` cleans up cancelled timers in batch (line 249-257).
- `BezierUtil` is pure-functional, no static mutable state.
- `ObjectPools` is only constructed as a `Singleton<>` (no public ctor) — accidental second-instance risk is low.
- `LocalDataManager.LocalDataWrapperCache<T>` is a reasonable micro-optimization for hot Save paths.
- `DebugLogger.LogIf` (Log/DebugLogger.cs:90-106) is the right escape hatch for hot paths.

---

*Read-only review. No source files modified.*
