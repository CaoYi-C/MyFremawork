---
id: kd_06c27da3-056a-4dad-92ee-68cc34e96f92
type: memory
path: hybridclr-tablekit-startup.md
title: hybridclr-tablekit-startup
inheritInjectMode: true
summaryEnabled: true
commandEnabled: false
readOnly: false
inheritAiConfig: true
createdAt: 1781509586809
updatedAt: 1781509586810
---

# hybridclr-tablekit-startup

## Summary
HybridCLR/TableKit startup dependency direction and current placement constraints.

<!-- locus:body:start -->
- HybridCLR/TableKit 启动依赖方向：AOT `Fuel` 不应引用 HOT 的 `TableKit`/`Test.TableKit`。启动管线只负责 YooAsset 更新、AOT 元数据、HOT DLL 加载，然后调用 HOT 入口；`TableKitConfigLoader` 放在 HOT 程序集里由 `HotUpdateEntry.StartAsync(LocalStartupConfig, CancellationToken)` 调用。
- `Assets/HotUpdate/ConfigRuntime/TableKitConfigLoader.cs` 必须位于 `Assets/HotUpdate/Configs/Test.TableKit.asmdef` 目录之外，否则会被编进 `Test.TableKit`，导致无法引用 `Fuel`/`YooAsset`。`HotUpdate.asmdef` 引用 `Fuel`、`YooAsset`、`Test.TableKit`、`UniTask`。
<!-- locus:body:end -->
