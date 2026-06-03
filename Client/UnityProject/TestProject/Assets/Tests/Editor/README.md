# Fuel.Tests — Unity Test Framework 测试

## 文件

```
Assets/Tests/Editor/
├── Fuel.Tests.Editor.asmdef             # 测试程序集定义（TestAssemblies）
├── AudioSourceDataFadeTests.cs          # 淡入淡出公式烟测（验证 #1 修复）
└── RedDotBatchFlushTests.cs             # 攒批落盘烟测（验证 #6 修复）
```

## 怎么跑

Unity Editor → `Window → General → Test Runner` → 选 `EditMode` → `Run All`。

或命令行（需装好 `com.unity.test-framework`）：

```bash
"<Unity安装路径>/Unity.exe" -batchmode -projectPath . -runTests -testPlatform EditMode -testResults TestResults.xml
```

## 它测什么

### `AudioSourceDataFadeTests`（验 #1 修复）

- `Fade_FadeIn_ReachesTarget_WithinTotalSeconds` — 从 0→1，1s 内精确收敛到 1.0
  （旧公式会一直累加不会收敛）
- `Fade_FadeOut_ReachesZero_WithinTotalSeconds` — 从 1→0，0.5s 内精确收敛到 0.0
- `Fade_Midway_ApproximatesLinearProgression` — 0.5s 处约 0.5
- `Fade_ZeroFadeTime_SnapsImmediately` — fadeTime=0 时直接跳到目标

### `RedDotBatchFlushTests`（验 #6 修复）

- `LocalSave_StoresValue_AndFlushPersists` — LocalSave 立即可见，flush 后仍可见
- `LocalSave_Overwrite_LatestWins` — 多次写同一 key，flush 后读到的是最后一次的值
- `FlushPendingSaves_IsIdempotent_WhenNoPending` — 无 pending 时 flush 不抛、是 no-op
- `RemoveLocalSave_DeletesKey_AndFlushPersists` — 删 key + flush 后真的没了
- `BindRole_PrefixesKeyWithUniqueKey` — bindRole=true 时 key 会被 UniqueKey 前缀

## 注意

- `Assembly-CSharp` 是 Unity 默认程序集（无 asmdef），Fuel 代码都编进去。
  测试 asmdef 通过 `autoReferenced: true` + `overrideReferences: false` 隐式引用它。
- 如果你的 Fuel 代码未来加了独立 asmdef，需要在 `Fuel.Tests.Editor.asmdef` 的 `references` 里加上。
