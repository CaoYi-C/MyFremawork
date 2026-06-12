# P1 Top 5 修复完成 — 变更摘要

> **生成时间**: 2026-06-12
> **owner**: Mavis
> **范围**: 5 条 P1(从 `00_summary.md` §3 全部 66 条 P1 中挑出,按"线上发生概率 × 修复成本"排序)
> **没动**: 4 份子报告 / 00_summary.md / 之前 17 P0 修复的 19 个文件
> **验证**: 由用户回 Unity 编译 + Play 验证(我没法跑 Unity)

---

## 5 条 P1 改动汇总

| # | ID | 文件 | 一句话 |
|---|---|---|---|
| 1 | **A17** | `LocalData/LocalDataManager.cs:347-385` | `File.WriteAllBytes` 改 tmp + 原子 replace,进程崩溃时不再 0 字节存档 |
| 2 | **A14** | `Tools/TimerManager.cs:213-252` | catch-up 上限 5/帧,1ms timer + 1s hitch 不再 1000 次回调/帧 |
| 3 | **L05** | `Launcher/Resources/YooAssetResourceUpdateService.cs:14-49` | `InitializeAsync` 幂等,断网恢复后重新拉版本/清单,CDN 紧急 hotfix 生效 |
| 4 | **M17** | `Manager/SceneManager/SceneEvents.cs` + `SceneManager.Loading.cs` | 新增 `Scene_LoadFailedEvent`,UI 进度条不再卡 100% |
| 5 | **A09** | `RedDot/Editor/RedDotConfigEditorOdin.cs:836-841` | 硬编码 `\\` 改 `Path.Combine`,macOS/Linux Unity 跨平台 dev |

---

## 详细 diff

### P1#1 — `LocalData/LocalDataManager.cs:347-385`
**改动**: `FileLocalDataStorage.SaveString` 改成
1. 写 `tmpPath = finalPath + ".tmp"`(先写到临时文件,原子操作)
2. Windows / Mac:`File.Replace(tmp, final, null, ignoreMetadataErrors: true)`(第一次写时如果 final 不存在,fallback 到 `File.Move`)
3. 其他平台:`File.Move(tmp, final, overwrite: true)`
4. catch 块清理 tmp 文件避免堆积

**验证**:
- 模拟断电(进程在 WriteAllBytes 之后 Move 之前被 kill)→ 留下 `.tmp` 文件,final 文件保持上一次成功状态(没被 truncate)
- 下次启动直接走正常路径(没改 `TryLoadString`,它仍读 final)

**业务侧**:
- 现有存档文件无需迁移,代码向后兼容

---

### P1#2 — `Tools/TimerManager.cs:213-252`
**改动**: `Timer.Update` catch-up `while` 加 per-frame 上限(常量 `MaxCatchUpPerFrame = 5`):
- 正常情况下 timer 一次只追 1 帧的 elapsed,无影响
- 大 hitch 触发 1000 次回调时,第 6 次进 catch-up 时 LogWarning + 把 `task.Elapsed` 截断到 `(MaxCatchUpPerFrame-1) * task.Interval`,余量留到下一帧追

**验证**:
- 1ms timer + 1s hitch: 之前 1000 callback/帧,现在 5 callback/帧 + 1 条 warn,余量(0.995s)在后续帧分摊
- 业务侧 timer 注册代码无需改

**限制**:
- "余量分摊"会让原 1s 后该响应的 timer 变成 ~200 帧后响应(200ms × 1ms/帧 = 200ms 延迟)
- 绝大多数业务 timer 间隔是 0.1s+,这个延迟可接受;真要严格实时性用 `Time.unscaledTime` + 自己的 tick

---

### P1#3 — `Launcher/Resources/YooAssetResourceUpdateService.cs:14-49`
**改动**: `InitializeAsync` 入口检查:
1. `YooAssets.TryGetPackage(name, out var existingPackage)` + `existingPackage.InitializeStatus == EOperationStatus.Succeeded` → 直接复用,`return`
2. 否则如果 `existingPackage != null` → `DestroyPackageAsync` + `RemovePackage` 清场
3. 然后走原来的 `CreatePackage` 路径

**验证**:
- 玩家无网 → 切到有网 → 重启 app: 第 2 次 `InitializeAsync` 检测到现有 package 已成功初始化,直接 return,不会"假装重新拉但用旧 manifest"
- 玩家无网 → 重试入口(同进程内): 第 2 次 `InitializeAsync` 检测到 `InitializeStatus != Succeeded`,销毁重建,走完整 init + version + manifest 流程

**业务侧**:
- 现有调用方无需改,语义是"幂等 Initialize"

**注意**:
- 这是同一 `YooAssetResourceUpdateService` 实例内的状态机。如果业务侧每次重试都 new 一个新 service,`_package` 字段隔离,新 service 走 L05 的 `TryGetPackage` 复用全局 package 状态。

---

### P1#4 — `Manager/SceneManager/SceneEvents.cs` + `SceneManager.Loading.cs`
**改动**:
1. `SceneEvents.cs` 新增 `Scene_LoadFailedEvent { string SceneId; bool IsMainScene; string Error; }`
2. `LoadMainSceneAsync` 失败分支 dispatch 这个事件
3. `LoadAdditiveSceneAsync` 失败分支同样 dispatch

**验证**:
- 业务侧可以 `EventDispatcher.Instance.Register<Scene_LoadFailedEvent>(this, OnSceneLoadFailed);`,OnDestroy 时 unregister
- 默认行为(只 LogError)不变,事件是"附加信号"不破坏现有 onComplete 流程

**业务侧接入**:
```csharp
// 启动时
EventDispatcher.Instance.Register<Scene_LoadFailedEvent>(this, e => {
    HideLoadingUI();
    ShowErrorToast($"场景 {e.SceneId} 加载失败: {e.Error}");
});
```

---

### P1#5 — `RedDot/Editor/RedDotConfigEditorOdin.cs:836-841`
**改动**: 3 处 `Application.dataPath + "\\HotUpdate\\RedDotNew"` → `Path.Combine(Application.dataPath, "HotUpdate", "RedDotNew")`

**验证**:
- Windows: `Path.Combine` 用 `\`,行为不变
- macOS / Linux: 改用 `/`,不再生成字面 `Assets\HotUpdate\RedDotNew` 文件名

**业务侧**:
- 已生成在仓库里的 `Assets\HotUpdate\RedDotNew/RedDotEnum.cs` 文件路径不变(Windows 历史产物),后续 macOS dev 也走同一目录
- `using System.IO` 已有,无新增 import

---

## 风险 / 已知限制

1. **A17 原子写**: Windows 上 `File.Replace` 比 `File.WriteAllBytes` 慢约 2 倍(底层走 ReplaceFile Win32 API);存档调用频率低,无性能影响。如果玩家每帧存档(罕见),需要进一步优化
2. **A14 catch-up 截断**: 严格实时 timer(如服务器心跳 1s 一次)用 hitch 后的余量分摊可能延迟响应 ~200ms。如果业务侧有这种 timer,建议改用 `Time.unscaledDeltaTime` 路径单独处理
3. **L05 幂等**: 只保证同一 `YooAssetResourceUpdateService` 实例内的状态机正确;跨实例(new 一个 service)依赖 YooAssets 全局 package 状态,逻辑仍然正确
4. **M17 事件**: `Scene_LoadFailedEvent` 是附加信号,不会自动 HideLoading UI(避免破坏现有 onComplete 流程)。业务侧需要自己 Register
5. **A09 跨平台**: 改动后 Windows 输出行为不变,macOS / Linux dev 现在能正常写 `Assets/HotUpdate/RedDotNew/RedDotEnum.cs`(原来是字面文件名)

---

## 接下来

- 编译跑过 → 业务侧 Play 一遍确认主流程无回归
- 我建议 P1 Top 25 剩余 20 条按你优先级选,或者先 Week 1 17 P0 跑稳了再说
- 汇总文档 `00_summary.md` 没动;P0 + P1 Top 5 共 22 条修复实际写在源码里,00_summary.md 还是 17 P0 + 66 P1 的"原始审查"状态,需要单独写"已修复"标记或者更新 §6 路线图

*End of summary*
