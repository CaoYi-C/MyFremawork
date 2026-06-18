---
id: kd_929c4995-37d8-4652-a748-d5c9bf58b862
type: memory
path: fuel-auto-build-pipeline.md
title: fuel-auto-build-pipeline
inheritInjectMode: true
summaryEnabled: true
commandEnabled: false
readOnly: false
inheritAiConfig: true
createdAt: 1781747715202
updatedAt: 1781747715203
---

# fuel-auto-build-pipeline

## Summary
Fuel 自动打包流程入口、菜单、命令行参数与 HybridCLR/YooAsset/BuildPlayer 执行顺序。

<!-- locus:body:start -->
- 自动打包入口位于 `Assets/Scripts/Fuel/Editor/FuelAutoBuildPipeline.cs`，菜单为 `Tools/Fuel/Build/Build Full HotUpdate Resources`、`Build Incremental HotUpdate Resources`、`Build Full Package`。
- 命令行入口：`Fuel.Editor.BuildPipeline.FuelAutoBuildPipeline.AutoBuild`、`AutoBuildFullHotUpdateResources`、`AutoBuildIncrementalHotUpdateResources`。支持参数 `-buildTarget`、`-packageName`、`-assetsVersion`、`-appVersion`/`-bundleVersion`、`-androidVersionCode`/`-bundleVersionCode`、`-buildAppBundle`/`-isbundleAbb`、`-developmentBuild`/`-useDevelopmentBuild`、`-generateHybridCLRAll`/`-genAllAot`。
- 流程：HybridCLR `GenerateAll` 或 `CompileDll` -> `HybridCLRDllBytesExporter.CopyActiveBuildTargetDllsToBytes()` -> YooAsset 根据 BundleBuilderSetting 构建 Main 包；完整包再调用 `BuildPipeline.BuildPlayer`。
<!-- locus:body:end -->
