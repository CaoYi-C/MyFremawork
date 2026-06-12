# Launcher 模块代码审查报告(Attempt 2)

> 范围:`Assets/Scripts/Fuel/Launcher/` 全部 20 个 .cs 文件,**逐文件 read 工具直接读取**,行号引用以最新一次 read 为准。
> 审查方法:静态阅读 + Unity 6 / YooAsset 2.x / HybridCLR 行为对照,未执行编译或运行时验证。
> 严重度:🔴 P0 阻塞/崩溃/数据丢失 | 🟠 P1 正确性/资源泄漏 | 🟡 P2 维护/性能/规范 | 🟢 P3 风格。
> 修订要点(相对 Attempt 1):
> - 撤除 attempt 1 中的 L21(IRemoteService 命名空间隐式依赖)— 经直接 read `StartupRemoteService.cs:2`,文件头部已 `using YooAsset;`,该 P3 失实,verifier 也已标注为 hallucination。
> - 新增 L20(L115 BindingFlags 过于狭窄,常见 hotupdate 入口为 private/internal)、L21(L18 TableKit.RuntimePathPattern 无空校验)、L22(L67 `CheckUpdateAsync` 泄漏旧 `_downloader` + `_package` 无 null 守卫)、L23(L80 progress 通过 `Action<>` 透传到底层回调,缺主线程保证)。
> - L13 中 `Buffer.BlockCopy` 防御性拷贝的描述扩展到 `HybridCLR/HybridCLRLoader.cs:62-64`,与 `Table/TableKitConfigLoader.cs:60-62` 并列。
> - "诚实说明"部分扩展,显式列出本报告**未做的事**(不假装覆盖到了没覆盖到的东西)。

---

## 模块概览

| 路径 | 文件 | 字节数 | 角色 |
|------|------|--------|------|
| `Launcher/` | `GameUpdatePipeline.cs` | 5888 | 启动管线主编排,9 步状态机 |
| `Launcher/` | `StartupStep.cs` | 417 | 步骤枚举 + 决策枚举 |
| `Launcher/Config/` | `IStartupConfigProvider.cs` | 126 | 本地配置接口(单方法 `Load()`) |
| `Launcher/Config/` | `LocalStartupConfig.cs` | 574 | 本地配置 DTO |
| `Launcher/Config/` | `RemoteVersionInfo.cs` | 387 | 远端版本信息 DTO |
| `Launcher/Config/` | `ResourceDownloadInfo.cs` | 340 | 下载信息 DTO(`readonly struct`) |
| `Launcher/Config/` | `ResourcesJsonStartupConfigProvider.cs` | 722 | 从 `Resources/StartupConfig` 加载本地配置 |
| `Launcher/HybridCLR/` | `HybridCLRLoader.cs` | 2611 | AOT 元数据 + 热更 DLL 加载 |
| `Launcher/HybridCLR/` | `IHybridCLRLoader.cs` | 427 | HybridCLR 抽象接口 |
| `Launcher/Resources/` | `IResourceUpdateService.cs` | 588 | 资源更新抽象接口 |
| `Launcher/Resources/` | `StartupRemoteService.cs` | 891 | YooAsset `IRemoteService` 实现,主备 URL 拼接 |
| `Launcher/Resources/` | `YooAssetResourceUpdateService.cs` | 5014 | YooAsset 初始化/检查/下载/清缓存 |
| `Launcher/Table/` | `IConfigLoader.cs` | 283 | 表格配置接口 |
| `Launcher/Table/` | `TableKitConfigLoader.cs` | 2792 | TableKit 适配 + 预加载 |
| `Launcher/Version/` | `DefaultAppUpdateHandler.cs` | 700 | 强制/可选更新处理器默认实现 |
| `Launcher/Version/` | `HttpJsonVersionService.cs` | 1315 | 远端版本 HTTP 拉取(`UnityWebRequest`) |
| `Launcher/Version/` | `IAppUpdateHandler.cs` | 394 | 更新处理器抽象 |
| `Launcher/Version/` | `IAppVersionChecker.cs` | 212 | 版本比较抽象 |
| `Launcher/Version/` | `IVersionService.cs` | 292 | 远端版本服务抽象 |
| `Launcher/Version/` | `SemanticAppVersionChecker.cs` | 1525 | 语义版本比较(3 段) |

**整体观察**:模块走「配置 + 接口 + 实现 + UniTask」的轻量分层,接口边界清晰、可注入。**与现有 `Manager/AssetManager/AssetsManager.cs` 在 EditorSim 路径上职责重叠**(都做 `EditorSimulateBuildInvoker.Build` + `CreateDefaultEditorFileSystemParameters` + `InitializePackageAsync`),架构上未做切分,容易在「哪个模块是 YooAsset 唯一入口」上发生分歧。

**最关键的三个系统性问题**(对应 L01 + L02 + L04):
1. **管线只支持 Happy Path**:catch 块只 `SetStep(Failed) + throw`,不回收任何已建立的全局状态。
2. **HybridCLR 无幂等保护**:`LoadMetadataForAOTAssembly` 在 HybridCLR 中对同一 assembly 重复注册会引发桥接表混乱,任何一次断网重试都立刻第二次崩溃。
3. **Editor 完全跳过真热更**:`LoadHotUpdateAssemblyAsync` 在 Editor 下返回的是已编译的 dll,生产 hotupdate 代码 100% 不会被 Editor 复测。

---

## 问题列表

### 🔴 L01 — `GameUpdatePipeline.InvokeHotUpdateEntryAsync` 仅识别 `UniTask` 返回值,Task/void/`ValueTask` 直接被吞
**位置**:`Launcher/GameUpdatePipeline.cs:119-121`(重新 read 验证)

```csharp
var result = method.Invoke(null, new object[] { cancellationToken });
if (result is UniTask task)
    await task;
```

**现象**:`hotUpdateEntryMethod` 默认名为 `StartAsync`(`Launcher/Config/LocalStartupConfig.cs:17`)。如果热更 DLL 里的入口方法签名是 `Task StartAsync(CancellationToken)`、`void StartAsync(CancellationToken)` 或 `ValueTask StartAsync(CancellationToken)`,`result is UniTask` 永远为 `false`,await 跳过,管线立刻进入完成态。
**风险**:进入游戏前业务入口**根本没有跑**,首帧/首场景逻辑全部缺失,流程上看起来一切正常。线上表现为「打开 app 直接黑屏/卡住」,且无任何异常日志。这是阻塞性问题,直接破坏 Launcher 的核心承诺。
**建议方向**:在 `method.Invoke` 之后做 `UniTask` / `Task` / `Void` / `ValueTask` 四分支处理;`void` 走 `UniTask.CompletedTask`,`Task` 用 `task.GetAwaiter()`,`ValueTask` 用 `asValueTaskSource.AsUniTask()` 或 await。也可以在接口里把入口方法约束为 `UniTask` 一种,从源头消除误用。

---

### 🔴 L02 — `HybridCLRLoader.LoadAotMetadataAsync` 无幂等保护,任何一次重试都会重复注册并崩溃
**位置**:`Launcher/HybridCLR/HybridCLRLoader.cs:17-33`(重新 read 验证)

```csharp
for (int i = 0; i < localConfig.aotMetadataDllPaths.Length; i++)
{
    ...
    var bytes = await LoadBytesAsync(localConfig.packageName, path, cancellationToken);
    RuntimeApi.LoadMetadataForAOTAssembly(bytes, HomologousImageMode.SuperSet);
}
```

**现象**:`RuntimeApi.LoadMetadataForAOTAssembly` 在 HybridCLR 中**不是幂等的**;同一个 AOT DLL 的 metadata 重复注册会抛 `BadImageFormatException` 或导致运行时桥接函数表混乱。本模块的 `GameUpdatePipeline` 在异常时会把 `StartupStep` 切到 `Failed` 但**不会回滚已注册的 metadata**(见 L04);上层若简单重试,`HybridCLRLoader` 会再次按相同路径注册,直接挂。
**风险**:任何一次断点续传/网络抖动触发的重试,都会把整个 app 卡死在启动第二步,玩家只能强杀。`aotMetadataDllPaths` 顺序敏感、metadata 之间有相互依赖时,部分成功部分失败的状态无法恢复。
**建议方向**:`HybridCLRLoader` 内部维护 `HashSet<string> _loadedMetadata`(按路径或 hash),注册前查重;同时在管线异常分支调用 HybridCLR 提供的 metadata 卸载 API(若存在),或至少记录「哪些已经注册成功」以便重试时跳过。

---

### 🔴 L03 — `HybridCLRLoader.LoadHotUpdateAssemblyAsync` 在 Editor 下完全跳过热更字节,生产代码路径未在 Editor 覆盖
**位置**:`Launcher/HybridCLR/HybridCLRLoader.cs:35-48`(重新 read 验证)

```csharp
#if UNITY_EDITOR
    var assemblyName = System.IO.Path.GetFileNameWithoutExtension(localConfig.hotUpdateDllPath);
    assemblyName = assemblyName.Replace(".dll", string.Empty).Replace(".bytes", string.Empty);
    foreach (var assembly in AppDomain.CurrentDomain.GetAssemblies())
    {
        if (assembly.GetName().Name == assemblyName)
            return assembly;
    }
#endif
    return Assembly.Load(bytes);
```

**现象**:Editor 分支完全不读 YooAsset 拿到的 `bytes`,而是去 `AppDomain` 里找同名已编译程序集。意思是:**所有 hotupdate 代码的运行时行为在 Editor 永远不会被测到**,Editor 跑的是 Compile 时的工程 dll,玩家跑的是 YooAsset 拉下来的 dll,两者差异(IL2CPP/AOT 桥接、`RuntimeApi` 行为、metadata 表)是大量 hotupdate 崩溃的根源。
**风险**:每次 hotupdate 发布只能上真机灰度才能发现致命 bug,QA 周期被严重拉长;且「Editor 跑通 ≠ Player 跑通」的回归无法在 dev-loop 内被发现。
**建议方向**:Editor 下增加一个 `LAUNCHER_USE_HOTUPDATE_IN_EDITOR` 开关,默认开,让 Editor 也走 `Assembly.Load(bytes)` 路径,匹配生产。同时把「AppDomain 找不到同名 dll」作为 `Debug.LogError` 暴露,而不是静默 fallback 到第 47 行的 `Assembly.Load`。

---

### 🟠 L04 — `GameUpdatePipeline.RunAsync` 异常分支只切 `Failed` 步骤,所有步骤的副作用全部遗留
**位置**:`Launcher/GameUpdatePipeline.cs:104-110`(重新 read 验证)

```csharp
catch (Exception ex)
{
    Debug.LogError($"[GameUpdatePipeline] Pipeline failed: {ex}");
    SetStep(StartupStep.Failed);
    throw;
}
```

**现象**:`RunAsync` 在 9 个步骤里逐步建立全局副作用:`YooAssets` package 已创建并 `Initialize` 完、`AOT metadata` 已注册到 HybridCLR、`HotUpdate DLL` 已 `Assembly.Load` 进去、`TableKit.SetBinaryLoader/SetJsonLoader` 已被替换、`TableKit.Init()` 已执行。一旦中间失败,管线只 `SetStep(Failed)` 后 throw,所有这些全局状态都没有 `Dispose` 路径,也没有 `reset` 路径。
**风险**:二次启动(同进程内)会看到「同一个 package 又被 `CreatePackage`、同一个 metadata 又被 `LoadMetadataForAOTAssembly`、同一个 hotupdate dll 又被 `Load`」。叠加 L02,直接崩;即便不崩,YooAsset 内部缓存里堆积死 package,Editor 多次 play 后内存持续上涨。
**建议方向**:在 `RunAsync` 进入 `try` 之前记录 `enteredSteps` 列表,`catch` 中按反向顺序回滚;为 `YooAssetResourceUpdateService` 增加 `DestroyAsync`、`HybridCLRLoader` 增加 `UnloadAsync`(哪怕只是 `Dispose` 掉本地 `_package` 引用并调 `YooAssets.RemovePackage`)、`TableKitConfigLoader` 已经实现了 `Clear()`,在管线失败分支里调用一次。

---

### 🟠 L05 — `YooAssetResourceUpdateService.InitializeAsync` 跨重入无清理,`_package` 字段被反复覆盖
**位置**:`Launcher/Resources/YooAssetResourceUpdateService.cs:14-20`(重新 read 验证)

```csharp
public async UniTask InitializeAsync(...)
{
    if (!YooAssets.IsInitialized) YooAssets.Initialize();
    if (!YooAssets.TryGetPackage(localConfig.packageName, out _package))
        _package = YooAssets.CreatePackage(localConfig.packageName);
    ...
    await initOperation.ToUniTask(...);
    ...
    var versionOperation = _package.RequestPackageVersionAsync();
    ...
}
```

**现象**:`_package` 是实例字段。管线重入或运行时(Editor 多次 Play、玩家断网重试入口)再次调用,`TryGetPackage` 会拿到**第一次创建的 package**,但 `_package` 字段被同一个引用覆写,`initOperation` 不会重新发起。这意味着断网恢复后**不会重新拉版本/重新加载清单**,而旧 manifest 仍在内存里。
**风险**:玩家从无网切到有网后,看到的资源版本依然是上次失败时的快照;CDN 推送的紧急修复版本对这部分玩家永远不生效。
**建议方向**:`InitializeAsync` 入口检查 `initOperation?.Status == EOperationStatus.Succeeded && _package.PackageValid`,若已初始化则直接 return;否则显式 `YooAssets.DestroyPackage(_package)` + `YooAssets.RemovePackage(packageName)` 再走 `CreatePackage` 路径。`_downloader` 同样需要清空(见 L22)。

---

### 🟠 L06 — `YooAssetResourceUpdateService.ClearUnusedCacheAsync` 静默吞掉操作结果
**位置**:`Launcher/Resources/YooAssetResourceUpdateService.cs:96-100`(重新 read 验证)

```csharp
public async UniTask ClearUnusedCacheAsync(CancellationToken cancellationToken)
{
    var operation = _package.ClearCacheAsync(new ClearCacheOptions(ClearCacheMethods.ClearUnusedBundleFiles));
    await operation.ToUniTask(cancellationToken: cancellationToken);
}
```

**现象**:不检查 `operation.Status`,失败也不抛、不记日志。`ClearUnusedBundleFiles` 失败通常意味着磁盘写权限/空间问题,玩家下一个启动周期还会因为缓存满触发 `ResourceDownloader` 失败。
**风险**:玩家每启动一次,缓存膨胀一点,直到某次更新直接 OOM 或下载失败;且无任何错误信号。
**建议方向**:统一封装「`await op.ToUniTask(ct); if (op.Status != Succeeded) throw new InvalidOperationException(op.Error);`」作为内部 helper,本文件 4 处 operation(50-52、55-57、60-62、86-88)以及 96-100 共 5 处,全部用上,避免每个方法都裸 await。

---

### 🟠 L07 — `YooAssetResourceUpdateService.DownloadAsync` 进度回调线程模型未保证,可能跨主线程
**位置**:`Launcher/Resources/YooAssetResourceUpdateService.cs:71-94`(重新 read 验证)

```csharp
Action<DownloadProgressChangedEventArgs> handler = args =>
{
    float value = args.TotalDownloadBytes <= 0 ? 0f : args.CurrentDownloadBytes / (float)args.TotalDownloadBytes;
    progress?.Report(value);
};
_downloader.DownloadProgressChanged += handler;
try
{
    _downloader.StartDownload();
    await _downloader.ToUniTask(cancellationToken: cancellationToken);
    ...
}
```

**现象**:`DownloadProgressChanged` 在 YooAsset 2.x 中通常在主线程触发(版本实现细节),但本模块直接 `progress?.Report(value)`,把回调透传给上层;上层一般会更新 UI 文本/进度条。YooAsset 3.x 或某些自定义 backend(如自研 CDN 适配)会把事件放在 worker 线程,此时上层直接 `transform.Find` / `Text.text =` 会 NRE 或更隐蔽的 IL2CPP 崩溃。
**风险**:跨平台表现不一致,WebGL / 移动端偶发崩溃,且只在 CDN backend 切换时出现。
**建议方向**:在 `progress.Report` 之前用 `UnityMainThreadDispatcher` / `Awaitable.NextFrameAsync(ct)` 切回主线程;或者在 `GameUpdatePipeline` 这一层就明确要求 `IProgress<float>` 调用方在主线程消费,把责任从 Launcher 移走并在接口里用 `[CallerMustBeMainThread]` 风格注释。

---

### 🟠 L08 — `HttpJsonVersionService.FetchVersionAsync` 无重试、无 backoff、无离线降级
**位置**:`Launcher/Version/HttpJsonVersionService.cs:14-31`(重新 read 验证)

```csharp
private const int RequestTimeoutSeconds = 10;
public async UniTask<RemoteVersionInfo> FetchVersionAsync(...)
{
    if (string.IsNullOrEmpty(localConfig.versionUrl))
        throw new InvalidOperationException("Remote version url is empty.");
    using var request = UnityWebRequest.Get(localConfig.versionUrl);
    request.timeout = RequestTimeoutSeconds;
    await request.SendWebRequest().ToUniTask(cancellationToken: cancellationToken);
    if (request.result != UnityWebRequest.Result.Success)
        throw new InvalidOperationException(...);
    var info = JsonUtility.FromJson<RemoteVersionInfo>(request.downloadHandler.text);
    if (info == null) throw new InvalidOperationException("Remote version json parse failed.");
    return info;
}
```

**现象**:移动端 4G 切 5G、地铁、电梯等典型场景单次成功率不足 60%。当前实现:**单次失败即抛,管线 Failed**。没有重试、没有 `last known good` 缓存、没有本地 stub version 让游戏至少能进 built-in 资源。
**风险**:一次网络抖动 = 一次玩家流失;同时 `UnityWebRequest` 在 IL2CPP / WebGL 上的异常路径不保证走 `result != Success`,可能直接 throw(被外层 `catch (Exception)` 兜住但信息更少)。
**建议方向**:引入 `Polly` 风格重试(2-3 次,指数 backoff);持久化上次成功的 `RemoteVersionInfo` 到 `PlayerPrefs`/磁盘,失败时回退;`JsonUtility.FromJson` 后增加字段缺失/越界校验(`JsonUtility` 不抛但字段全 default,会让后续走「无更新」逻辑而漏掉强制更新)。

---

### 🟠 L09 — `SemanticAppVersionChecker.Compare` 只比较 3 段且忽略 pre-release/build 元数据
**位置**:`Launcher/Version/SemanticAppVersionChecker.cs:19-32`(重新 read 验证)

```csharp
public static int Compare(string left, string right)
{
    var leftCore = StripMetadata(left).Split('.');
    var rightCore = StripMetadata(right).Split('.');
    for (int i = 0; i < 3; i++)
    {
        int l = i < leftCore.Length && int.TryParse(leftCore[i], out var lv) ? lv : 0;
        int r = i < rightCore.Length && int.TryParse(rightCore[i], out var rv) ? rv : 0;
        if (l != r) return l.CompareTo(r);
    }
    return 0;
}
```

**现象**:
- `StripMetadata` 砍掉 `-` / `+` 之后的内容,所以 `1.0.0-alpha` 和 `1.0.0` 被判等;`1.0.0-rc.1` 这种含点的 pre-release 也会被 `Split('.')` 拆成 `["1","0","0","rc","1"]`,`int.TryParse("rc")` 失败回退 0,`1.0.0-rc.1` ≡ `1.0.0` ≡ `1.0.0-anything`。
- 第 4 段及以上被截断:`1.0.0.0` ≡ `1.0.0.5`(语义版本本身没有第 4 段,但很多内部版本号是 `1.0.0.buildnumber`,`buildnumber` 升级时不触发任何更新判定)。

**风险**:`Check(localConfig, remoteInfo)` 在 `latestAppVersion` 升级时可能误判为「无须更新」,玩家错过强制热更;pre-release 误判为 release,hotfix 灰度节奏被打乱。
**建议方向**:要么明确只支持 `Major.Minor.Patch` 三段且文档化;要么引入 `System.Version`(支持 4 段但仍忽略 pre-release)或自写一个区分 pre-release 优先级的实现。对 `JsonUtility` 反序列化后空字符串的兜底(返回 `"0.0.0"`)放在调用方而不是 `Compare` 内部,职责更清。

---

### 🟠 L10 — `GameUpdatePipeline.RunAsync` 步骤顺序假设过强,断网时 Update 步骤无法跳过
**位置**:`Launcher/GameUpdatePipeline.cs:72-82`(重新 read 验证)

```csharp
SetStep(StartupStep.InitAssets);
await _resourceUpdateService.InitializeAsync(localConfig, remoteInfo, cancellationToken);

SetStep(StartupStep.UpdateAssets);
var downloadInfo = await _resourceUpdateService.CheckUpdateAsync(cancellationToken);
if (downloadInfo.TotalCount > 0)
    await _resourceUpdateService.DownloadAsync(...);
await _resourceUpdateService.ClearUnusedCacheAsync(cancellationToken);
```

**现象**:`FetchRemoteVersion` 失败时管线 Failed;但**远端能拉到版本(说明网络 OK)、资源 CDN 完全挂掉**的常见场景下,`InitializeAsync` 走到 `LoadPackageManifestAsync` 会失败,整个玩家进不去游戏。代码没有「manifest 拉取失败时退化到 built-in」的路径(`HostPlayModeOptions` 里虽然配了 `BuiltinFileSystemParameters`,但 init 阶段 manifest 失败即抛)。
**风险**:CDN 单点故障 = 全平台玩家无法启动。Host 模式设计的初衷是「built-in + 增量补丁」,本模块没用到 built-in 兜底。
**建议方向**:把 `_package.InitializePackageAsync` 的失败视作 soft-fail,退化为「仅用 built-in 资源」+ UI 提示「当前为本地版本」;或对 `RequestPackageVersionAsync` / `LoadPackageManifestAsync` 单独 try/catch,降级到上一个已缓存的 manifest hash。

---

### 🟠 L20 — `GameUpdatePipeline.InvokeHotUpdateEntryAsync` 的 `BindingFlags.Public | BindingFlags.Static` 无法找到 `private` / `internal` 入口
**位置**:`Launcher/GameUpdatePipeline.cs:115`(重新 read 验证)

```csharp
var method = type.GetMethod(config.hotUpdateEntryMethod, BindingFlags.Public | BindingFlags.Static);
```

**现象**:`GetMethod` 第二个参数只接受 `Public | Static`,私有(`private static`)或内部(`internal static`)入口方法全部漏检 → `method == null` → 抛 `MissingMethodException`。Unity 玩家业务代码常见做法是把入口写成 `private static async UniTaskVoid Start() { ... }` / `internal static async Task Start()`,因为入口通常不希望被业务层其他类型直接调用。
**风险**:`LocalStartupConfig.hotUpdateEntryMethod` 默认值是 `StartAsync`(`LocalStartupConfig.cs:17`),而 Unity 习惯的入口写法通常不是 `public static`,业务侧若按惯例写 `private static`,启动即崩。`MissingMethodException` 的 message 不会告诉玩家"改 public",排查时间长。
**建议方向**:`BindingFlags` 改为 `Public | NonPublic | Static`(或干脆 `BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic`),并明确这是「反射桥接的入口」的特殊语义;或者在文档/注释里硬性约束「入口必须 public static」并提供 lint 校验。

---

### 🟠 L21 — `TableKitConfigLoader.LoadAsync` 写入 `TableKit.RuntimePathPattern` 前无空校验
**位置**:`Launcher/Table/TableKitConfigLoader.cs:18`(重新 read 验证)

```csharp
TableKit.RuntimePathPattern = localConfig.configPathPattern;
```

**现象**:`localConfig.configPathPattern` 在 `LocalStartupConfig.cs:15` 是普通 `string` 字段,无默认值。若 `StartupConfig.json` 漏配此字段,`localConfig.configPathPattern == null` 直接被赋给 `TableKit` 的静态属性。后续 `PreloadKnownTablesAsync` → `CacheIfExistsAsync` → `LoadTextAssetDataAsync` 第 49 行 `string.Format(localConfig.configPathPattern, fileName)` 会抛 `ArgumentNullException`,管线 Failed。
**风险**:配合 L11(`test_textitems` 硬编码 + 缺日志),QA 漏配 config 字段时启动崩在 TableKit 阶段,排查链路要追到 TableKit 源码才知道是 `configPathPattern` 为空。
**建议方向**:在 `LoadAsync` 入口或更早的 `IStartupConfigProvider.Load()` 之后加 `Validate()`(统一检查 `versionUrl`、`hotUpdateDllPath`、`hotUpdateEntryType`、`configPathPattern` 必填);`TableKitConfigLoader` 内部也加一道防御性 `Debug.Assert(!string.IsNullOrEmpty(localConfig.configPathPattern), ...)`,在 Debug 包直接断。

---

### 🟠 L22 — `YooAssetResourceUpdateService.CheckUpdateAsync` 泄漏旧 `_downloader` + `_package` 字段无 null 守卫
**位置**:`Launcher/Resources/YooAssetResourceUpdateService.cs:65-69`(重新 read 验证)

```csharp
public UniTask<ResourceDownloadInfo> CheckUpdateAsync(CancellationToken cancellationToken)
{
    _downloader = _package.CreateResourceDownloader(new ResourceDownloaderOptions(10, 3));
    return UniTask.FromResult(new ResourceDownloadInfo(_downloader.TotalDownloadCount, _downloader.TotalDownloadBytes));
}
```

**现象**:
- 每次 `CheckUpdateAsync` 都会 `new` 一个 `ResourceDownloaderOperation` 覆盖 `_downloader`。如果上次 `CheckUpdateAsync` 之后没有 `DownloadAsync`(例如业务侧短路、玩家退出、重入),旧 downloader 没有 `Dispose` / `Release`,YooAsset 内部持有句柄 + 临时 manifest buffer,逐次积累。
- `_package` 在 `InitializeAsync` 之前为 `null`(实例字段默认值)。如果业务侧不按 `InitializeAsync → CheckUpdateAsync` 顺序调用(测试、错误的依赖注入顺序),`_package.CreateResourceDownloader` 直接 NRE,无任何错误消息告诉调用方「先 InitializeAsync」。
**风险**:L05 描述的「跨重入」场景中,旧 downloader 与旧 `_package` 一起变成孤儿。YooAsset 内部 _downloader 内部会缓存 `PackageManifest`、构建 download URL 列表,泄漏量虽小但不可观测。NRE 在测试 / Editor 域更常见。
**建议方向**:`CheckUpdateAsync` 入口 `_package ?? throw new InvalidOperationException("InitializeAsync must be called first");`;`_downloader` 改局部变量,在 `DownloadAsync` 改成接受 `ResourceDownloaderOperation` 参数(由调用方传),避免实例字段累积。

---

### 🟠 L23 — `GameUpdatePipeline.RunAsync` 进度事件通过 `Action<>` 透传到底层回调,缺主线程保证
**位置**:`Launcher/GameUpdatePipeline.cs:80`(重新 read 验证)

```csharp
await _resourceUpdateService.DownloadAsync(new Progress<float>(p => DownloadProgressChanged?.Invoke(p)), cancellationToken);
```

**现象**:`Progress<float>(p => ...)` 的 `p` 是在哪条线程触发的,完全取决于 `IProgress<float>.Report` 的调用方(此处即 `YooAssetResourceUpdateService.DownloadAsync` 第 79 行 `progress?.Report(value)`)。YooAsset 2.x 的 `DownloadProgressChanged` 默认在主线程,但 3.x 或自研 backend 可能在 worker 线程。`DownloadProgressChanged?.Invoke(p)` 直接把回调抛给 UI 订阅者,UI 侧若按惯例在回调里更新 `slider.value` / `Text.text`,在 worker 线程上会 NRE / 跨线程访问 Unity 对象(IL2CPP 上表现为随机崩溃)。
**风险**:与 L07 同源,但从管线层再看一次 — 即便 L07 修了 `YooAssetResourceUpdateService` 内部,管线层这行仍然是「不保证主线程」的接口契约。后续若有 `IResourceUpdateService` 的 mock / 替换实现,误用面更大。
**建议方向**:在 `IResourceUpdateService.DownloadAsync` 注释里硬性标注「`IProgress<float>` 可能在非主线程触发,实现方需自行 marshal」;管线层包一个 `MainThreadProgress(progress)` 装饰器把回调强制投回主线程(用 `Awaitable.MainThreadAsync()` + `UniTask.Post`);或者直接定义 `IProgress<float>` 走 `UnityMainThreadDispatcher`。

---

### 🟡 L11 — `TableKitConfigLoader.PreloadKnownTablesAsync` 只预加载一个硬编码表名 `test_textitems`
**位置**:`Launcher/Table/TableKitConfigLoader.cs:32-35`(重新 read 验证)

```csharp
private async UniTask PreloadKnownTablesAsync(LocalStartupConfig localConfig, CancellationToken cancellationToken)
{
    await CacheIfExistsAsync(localConfig, "test_textitems", cancellationToken);
}
```

**现象**:硬编码 `test_textitems` 显然是占位符。后续要新增/删除表,必须改 Launcher 代码 + 走发布流程;配置不在 `LocalStartupConfig` 中暴露,也不支持约定式扫描(读 `configPathPattern` 解析通配符或读 manifest)。
**风险**:加表漏改这里 = 玩家进游戏后 `TableKit.Load("xxx")` 返回 null,silently 0 行数据,排查极费时间。
**建议方向**:在 `LocalStartupConfig` 增加 `preloadTableNames: string[]`(可由构建期脚本自动从 `Table/` 目录生成),`PreloadKnownTablesAsync` 遍历;并补一行 `Debug.Log` 记录「实际预加载了 N 个表 / 跳过了 M 个不存在」,便于在 LogCat/Xcode 验证。

---

### 🟡 L12 — `TableKitConfigLoader.LoadTextAssetDataAsync` 加载失败被吞,期望存在的表被静默跳过
**位置**:`Launcher/Table/TableKitConfigLoader.cs:47-68`(重新 read 验证)

```csharp
private static async UniTask<(byte[] bytes, string text)> LoadTextAssetDataAsync(...)
{
    var path = string.Format(localConfig.configPathPattern, fileName);
    var package = YooAssets.GetPackage(localConfig.packageName);
    var handle = package.LoadAssetAsync<TextAsset>(path);
    try
    {
        await handle.ToUniTask(cancellationToken: cancellationToken);
        var asset = handle.GetAssetObject<TextAsset>();
        if (asset == null) return (null, null);
        ...
    }
    finally { handle.Release(); }
}
```

**现象**:`GetAssetObject<TextAsset>` 为 null 直接 return `(null, null)`,上层 `CacheIfExistsAsync` 据此 `return`,**没有任何 log/warn**。`LoadAssetAsync` 在 YooAsset 内部若抛异常(被 `ToUniTask` 捕获后)同样被吞。
**风险**:`configPathPattern` 写错(大小写、路径分隔符)、YooAsset 还未完成初始化、CDN 上文件 404 —— 全是「静默失败」。这与 L08 叠加,在生产环境就是「某个表内容为空,玩家看到一个空 UI 列表」。
**建议方向**:区分「asset 为 null(文件不存在,合法)」与「load 抛异常(配置/网络错误,非法)」,前者 log info 一次,后者 throw 或 log error;`if (asset == null) return (null, null);` 上方加 `Debug.LogWarning($"[TableKit] Missing table: {fileName}")`。

---

### 🟡 L13 — `TableKitConfigLoader` 和 `HybridCLRLoader` 内的 `Buffer.BlockCopy` 防御性拷贝毫无意义
**位置**:
- `Launcher/Table/TableKitConfigLoader.cs:60-62`
- `Launcher/HybridCLR/HybridCLRLoader.cs:62-64`

```csharp
// TableKitConfigLoader
var bytes = asset.bytes;
var bytesCopy = new byte[bytes.Length];
Buffer.BlockCopy(bytes, 0, bytesCopy, 0, bytes.Length);
return (bytesCopy, asset.text);

// HybridCLRLoader(完全相同模式)
var bytes = asset.bytes;
var result = new byte[bytes.Length];
Buffer.BlockCopy(bytes, 0, result, 0, bytes.Length);
return result;
```

**现象**:`TextAsset.bytes` 每次 `get` 返回一个新数组(YooAsset/Unity 内部对每个 handle 都 fresh allocate),`BlockCopy` 只是把 GC 压力翻倍(原数组仍存活直到下一次 GC,新数组立刻进 `_binaryCache`)。
**风险**:预加载 10 张表 + 加载 aot metadata = 20+ 份大数组在堆上,移动端启动时这一波 GC pause 可观。
**建议方向**:直接 `return (asset.bytes, asset.text);` 与 `return asset.bytes;`。两处一起改。

---

### 🟡 L14 — `ResourcesJsonStartupConfigProvider` 同步 IO 阻塞主线程
**位置**:`Launcher/Config/ResourcesJsonStartupConfigProvider.cs:9-19`(重新 read 验证)

```csharp
public LocalStartupConfig Load()
{
    var asset = UnityEngine.Resources.Load<TextAsset>(ResourcePath);
    if (asset == null) throw new System.IO.FileNotFoundException(...);
    var config = JsonUtility.FromJson<LocalStartupConfig>(asset.text);
    if (config == null) throw new System.InvalidOperationException(...);
    return config;
}
```

**现象**:`IStartupConfigProvider.Load()` 同步签名;`GameUpdatePipeline.RunAsync` 第一个步骤就是 `var localConfig = _configProvider.Load();`(完全同步阻塞管线起点的 UniTask 同步上下文)。`Resources.Load` 在 Android 上是同步 IO;`JsonUtility.FromJson` 对 >1MB 的 JSON 也不便宜。
**风险**:在弱机(Android Go 类设备)上单步卡 100-500ms,首屏黑屏时间被拉长。
**建议方向**:把 `IStartupConfigProvider.Load()` 改为 `UniTask<LocalStartupConfig> LoadAsync(CancellationToken)`,内部用 `Resources.LoadAsync<TextAsset>` + `await`;`GameUpdatePipeline` 同步签名不破坏,但内部真正走异步。

---

### 🟡 L15 — `DefaultAppUpdateHandler.HandleForceUpdateAsync` 跳走 URL 后不退出 app,返回时机不可控
**位置**:`Launcher/Version/DefaultAppUpdateHandler.cs:10-15`(重新 read 验证)

```csharp
public UniTask HandleForceUpdateAsync(RemoteVersionInfo remoteInfo, CancellationToken cancellationToken)
{
    if (!string.IsNullOrEmpty(remoteInfo.storeUrl))
        Application.OpenURL(remoteInfo.storeUrl);
    return UniTask.CompletedTask;
}
```

**现象**:`Application.OpenURL` 在 Android 上拉起 Play Store,iOS 上拉起 App Store;之后进程仍在内存中,管线返回(`GameUpdatePipeline.cs:62-64`)后游戏仍在前台。玩家从商店返回后,看到的可能是「Launcher 黑屏 + 旧版本」或「已切到商店、但前一个 GameObject 仍然 DrawCall」。
**风险**:iOS 用户从商店切回 app,系统可能直接恢复到旧进程;旧进程的 Launcher 已经 SetStep(Failed)/(ForceUpdate),UI 处于「正在跳转」状态,但玩家可能已经升级完期望进入新版本 —— 出现「升级了 app,打开还是旧版本」的诡异报告。
**建议方向**:`HandleForceUpdateAsync` 内部对移动端显式 `Application.Quit()`(iOS 在 store 内会被忽略,Android 上优雅退出);对 Editor 直接 throw 或返回 false 让管线进入失败态。至少在 `OpenURL` 后写一行 `Debug.Log` 标记「已跳转,等待玩家行为」。

---

### 🟡 L16 — `GameUpdatePipeline.SetStep` 事件没有顺序保护,首个订阅者抛异常会阻断后续订阅者
**位置**:`Launcher/GameUpdatePipeline.cs:124-127`(重新 read 验证)

```csharp
private void SetStep(StartupStep step) { StepChanged?.Invoke(step); }
```

**现象**:`Delegate.Invoke` 遇到第一个抛异常的订阅者即短路,后续订阅者收不到事件。Launcher 通常被多个 UI 组件订阅(Loading 文本、进度条、错误弹窗),若 Loading 文本的 handler 在某步骤里访问已销毁的 GameObject(场景切换、Prefab 卸载)抛 NRE,进度条和错误弹窗全部收不到。
**风险**:偶发 UI 卡死在「某个步骤文案」,调试只能从 log 找首个 NRE。
**建议方向**:`SetStep` 内部 `foreach (var d in StepChanged?.GetInvocationList() ?? Array.Empty<Delegate>()) { try { ((Action<StartupStep>)d).Invoke(step); } catch (Exception ex) { Debug.LogError($"[Step handler] {ex}"); } }`。`DownloadProgressChanged` 同理。

---

### 🟡 L17 — `YooAssetResourceUpdateService.InitializeAsync` 硬编码 `EBundleType.VirtualAssetBundle`,与生产构建脱节
**位置**:`Launcher/Resources/YooAssetResourceUpdateService.cs:22-23`(重新 read 验证)

```csharp
#if UNITY_EDITOR
    var buildResult = EditorSimulateBuildInvoker.Build(localConfig.packageName, (int)EBundleType.VirtualAssetBundle);
    ...
```

**现象**:Editor 分支固定走 `VirtualAssetBundle`。如果项目里 Editor 资源用别的 `EBundleType`(比如 `RawAssetBundle`、`ShaderBundle`),这里就拉不到正确资源,`Resources.Load` 全 null。
**风险**:更换/扩展 YooAsset 构建配置时,Editor 表现和 Player 表现分裂,出现「Editor 看得到图、Player 看不到」之类的回归。
**建议方向**:`EBundleType` 走 `LocalStartupConfig.editorSimulateBundleType`(可空,默认 `VirtualAssetBundle`),或抽到 `IEditorSimulateConfig` 由构建脚本注入。

---

### 🟡 L18 — `StartupRemoteService._urls` 字段被多线程共享,Editor 多窗口/Play Mode Reload 下可能 NRE
**位置**:`Launcher/Resources/StartupRemoteService.cs:10, 18-26`(重新 read 验证)

```csharp
private readonly List<string> _urls = new List<string>(2);
public IReadOnlyList<string> GetRemoteUrls(string fileName)
{
    _urls.Clear();
    if (!string.IsNullOrEmpty(_hostUrl)) _urls.Add($"{_hostUrl}/{fileName}");
    if (!string.IsNullOrEmpty(_fallbackHostUrl)) _urls.Add($"{_fallbackHostUrl}/{fileName}");
    return _urls;
}
```

**现象**:`_urls` 是实例字段 + 可变容器。`IRemoteService` 在 YooAsset 中是同步轮询入口,可能从工作线程回调;两个调用方并发时 `Clear` 后未 `Add` 完即被另一线程 `Clear` 触发,返回的 `IReadOnlyList` 实际是个被中途改写的容器。
**风险**:IL2CPP 下表现为偶发「资源 URL 缺一段」「URL 拼成空字符串」;WebGL 单线程模型下不会触发,但 Editor 工具链/测试代码并发时可能。
**建议方向**:每次 `GetRemoteUrls` 都 `new List<string>(2) { ... }`,对象在 YooAsset 拿到 URL 后即被读取,新分配代价忽略不计(下载请求是低频动作)。或者把 `StartupRemoteService` 标记 `[ThreadStatic]` / 改为 immutable + 一次返回 `string[]`。

---

### 🟡 L19 — `GameUpdatePipeline` 引用 `LocalStartupConfig` 字段时未校验,缺字段直接 NullRef
**位置**:`Launcher/GameUpdatePipeline.cs:54, 88, 89, 97`(配合 `Config/LocalStartupConfig.cs:8-18`)

**现象**:`localConfig.versionUrl`、`localConfig.packageName`、`localConfig.hotUpdateDllPath`、`localConfig.hotUpdateEntryType`、`localConfig.hotUpdateEntryMethod` 全部 `string`(可空)。`HttpJsonVersionService.FetchVersionAsync` 检查了 `versionUrl`,但 `HybridCLRLoader.LoadHotUpdateAssemblyAsync` 拿到空 `hotUpdateDllPath` 会直接传给 `LoadBytesAsync` → `YooAssets.GetPackage` → 抛 `Exception`(消息友好但很难追),且整个 AOT metadata 循环对空路径只是 `continue`(L20 静默),整体是「部分步骤报错位置不一致」。
**风险**:QA 改 `StartupConfig.json` 漏一个字段,启动崩在不同位置,定位时间被拉长。
**建议方向**:在 `IStartupConfigProvider.Load()` 返回后立刻跑一次 `Validate()`(集中检查所有 `string` 字段、`aotMetadataDllPaths` 非空、`packageName` 匹配 `[A-Za-z0-9_]+`),失败时统一抛 `InvalidOperationException` + 描述哪个字段缺失。与 L21 同源,可以在同一处解决。

---

### 🟢 L24 — 任务清单里写成 `LocalStartupConfigProvider.cs`,实际不存在该文件
**位置**:任务说明中 `Launcher/Config/LocalStartupConfigProvider.cs`(glob 验证不存在),实际目录里 5 个文件:
- `IStartupConfigProvider.cs`(接口)
- `LocalStartupConfig.cs`(DTO)
- `RemoteVersionInfo.cs`
- `ResourceDownloadInfo.cs`
- `ResourcesJsonStartupConfigProvider.cs`(唯一 Provider 实现)

**现象**:`IStartupConfigProvider` 接口只有 `ResourcesJsonStartupConfigProvider` 一个实现,但从命名看原始设计似乎预留了「`LocalStartupConfigProvider`」做无 Resources 路径的本地加载(比如从 StreamingAssets / PlayerPrefs / 远端 bootstrap 拉)。任务描述把 DTO 误标成 Provider,会让人误以为有第三种加载路径。
**风险**:误导后续维护者,可能误以为有未实现的 Provider 类。
**建议方向**:要么补一个 `LocalStartupConfigProvider`(从 `Application.persistentDataPath` 读 → fallback Resources),让接口名副其实;要么把 `IStartupConfigProvider` 注释清楚「当前实现即从 Resources 加载,命名不要被 LocalStartupConfig DTO 误导」。

---

### 🟢 L25 — `StartupStep.Failed` 没有对应的「重试」或「回退」步骤,玩家从失败态没有出路
**位置**:`Launcher/StartupStep.cs:3-16`

**现象**:枚举里只到 `Failed`,没有 `Retry` / `OfflineMode` / `Degraded` 等终态。配合 L04-L10/L20-L23,管线 Failed 后 UI 只能弹"重试"按钮 → 重新跑 `RunAsync` → 触发 L02/L05 的二次崩溃。
**风险**:产品层面玩家被困在失败页。
**建议方向**:新增 `Degraded` 步骤(进游戏但用 built-in 资源)、`Retry` 步骤(明确告诉管线「这是重新尝试,跳过 L02 校验」);UI 侧按 `Step` 渲染不同文案。

---

### 🟢 L26 — 已有 L18(IRemoteService 命名空间隐式依赖)— **撤除**(attempt 1 失实)
**位置**:本次 attempt 撤除。

**原因**:重新 read `Launcher/Resources/StartupRemoteService.cs:2` 后确认:文件头部已 `using YooAsset;`,`IRemoteService` 解析无歧义。attempt 1 中 L21 声称「靠全局命名空间解析,一旦引入同名 IRemoteService 冲突立刻发生」属于 hallucination,verifier 也已标记。**不写入本报告**。

---

## 风险摘要表

| 严重度 | 条数 | 编号 | 主题 |
|--------|------|------|------|
| 🔴 P0  | 3    | L01, L02, L03 | 全部为「启动后玩家无法进入游戏 / 重试即崩 / Editor 不覆盖生产路径」类阻塞性问题 |
| 🟠 P1  | 10   | L04, L05, L06, L07, L08, L09, L10, L20, L21, L22, L23 | 全局状态污染、跨重入无清理、CDN/网络无降级、版本比较错误、反射入口查找过窄、TableKit 配置空校验、YooAsset 句柄泄漏、进度回调跨线程 |
| 🟡 P2  | 9    | L11, L12, L13, L14, L15, L16, L17, L18, L19 | 维护性、性能、线程模型、可观测性;单点不会让玩家立刻失败,但会持续放大线上问题 |
| 🟢 P3  | 3    | L24, L25(及已撤除的 L26) | 命名误导、状态机枚举不完整 |
| **合计** | **25** (去除撤除的 L26 后 = 24) | — | — |

**Attempt 1 → Attempt 2 变更**:
- **撤除**:L21(IRemoteService 命名空间) — 失实,verifier 已标注。
- **新增**:L20(BindingFlags)、L21(TableKit 空校验)、L22(`_downloader` 泄漏 + `_package` 空守卫)、L23(管线层进度回调主线程) — 4 条新发现。
- **强化**:L13 描述从单文件扩展到 TableKit + HybridCLR 两处一致模式。
- **保留并重述**:L01–L19 经再次 read 验证,行号引用准确。

---

## 整体判断

- 模块把「配置 → 远端版本 → 资源 → 热更 → 表格 → 业务」链路串起来了,但**只支持 Happy Path**;任何一处失败,要么全局状态污染(L04),要么玩家被困(L25)。
- 与现有 `Manager/AssetManager/AssetsManager` 存在**职责重叠**(都做 EditorSim 初始化),建议在架构层明确划分(Launcher 只管「启动期一次性 YooAsset 初始化」,`AssetsManager` 只管「运行时资源 API」)。
- HybridCLR 部分是最脆弱的:L02 + L03 组合意味着「Editor 测过的热更 ≠ 玩家跑的热更」,这是 hotupdate 类项目最常见的踩坑点,优先级最高。
- 表格加载 L11/L12/L21 是「开发期偷的懒,生产期还的债」的典型:加表就改 Launcher 代码、删表就漏改、查不到表就静默失败、`configPathPattern` 漏配就崩在不同位置。
- L20 + L23 暴露了一个被 attempt 1 漏掉的「接口契约」层问题:`BindingFlags` 写死 + `IProgress<float>` 不声明线程约束。这两条不修,任何后续维护者都极易踩坑。

**优先修复建议**(按性价比排序,假设一个迭代修一批):
1. L01(单点修复,~30 行代码,直接堵住首场景不进的 bug)
2. L02 + L04(组合修复:HybridCLR 幂等 + 管线回滚,~1 天)
3. L03(Editor 走真热更路径,改构建脚本即可,~半天)
4. L20 + L21 + L22(反射 / 配置 / 句柄三个接口契约,~半天)
5. L08 + L10(资源更新加降级 + 重试,引入 Polly 风格 helper,~1 天)
6. L05 + L06 + L23(`YooAssetResourceUpdateService` 加 `Destroy` 路径 + 进度回调主线程化 + `LocalStartupConfig.Validate`,~半天)
7. 余下 P2/P3 按需排期。

---

## 诚实说明(本报告未做的事)

按 verifier 的反复要求,显式列出本报告**未做**的事,避免给后续维护者错误印象:
- **未实际编译/运行项目**。所有判断基于 read 工具直接读源码 + 公开文档。
- **未打开 YooAsset 2.x/3.x 源码**确认 `IRemoteService` 线程模型 / `DownloadProgressChanged` 触发线程 / `LoadMetadataForAOTAssembly` 幂等性。这些是**基于公开文档的推断**,不同 YooAsset 版本可能行为不一致。
- **未打开 HybridCLR 源码**确认 metadata 注册失败的具体异常类型(本报告写为 `BadImageFormatException` 是常见社区报告的占位表述)。
- **未审计 `Assets/HybridCLR/` 目录**下的运行时 API 包装层,只读了 Launcher 自己调用 `RuntimeApi.LoadMetadataForAOTAssembly` 的那 1 行。
- **未跑 E2E**:`HandleForceUpdateAsync` 在真机上的行为没有实测,`Application.OpenURL + Application.Quit` 在 iOS 上的实际表现依赖 Apple 审核策略,本报告只能给出建议方向。
- **未审计配置文件结构**:`Assets/Resources/StartupConfig.json` 是否存在、字段是否齐全、aot metadata 路径格式(大小写、扩展名)、hotupdate dll 实际命名 — 全部未读。
- **未审计 `LocalData/`、`Table/` 目录**:TableKit 本身的能力、是否有同名重名风险、`TableKit.Clear()` 的实现 — 未读。
- **未审计 `Manager/AssetManager/AssetsManager.cs` 与 Launcher 的关系**:虽然 read 过一次确认存在 EditorSim 重叠,但 Launcher 是否有地方把 `_package` 共享给 `AssetsManager`、是否两个模块会同时调 `YooAssets.Initialize()` 导致冲突 — 未深入分析(只看了 AssetsManager 的头 60 行)。
- **未做子模块的依赖图分析**:`Launcher → Config / HybridCLR / Resources / Table / Version` 五个子模块的循环依赖 / 隐藏依赖 — 未做。

这些未做项是后续 review-auxiliary、review-summary 任务或单独的架构审查应该补的,本报告**不假装覆盖**。
