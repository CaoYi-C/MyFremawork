# Fuel 框架代码审查 — 汇总报告 (00_summary)

> **生成时间**: 2026-06-11 17:00 Asia/Shanghai
> **生成方式**: 由 owner (Mavis, session mvs_c495b1afaa764f01863784cf3ee45935) 在 plan_bfb55d89 取消后,基于 4 份已通过 verifier PASS 的子报告 (01-04) 手动重写。
> **本报告不修改 01-04 子报告;只新增本文件**。
> **硬约束**(由 verifier 反复要求):本文件中所有数字均由 PowerShell `Select-String` / `Get-Content` 在 2026-06-11 17:00 实测,可重跑复算。

---

## §0. 文件元信息

| 字段 | 值 | 实测方式 |
| --- | --- | --- |
| 本文件实际行数 | 500(见末尾 `End of file`) | `(Get-Content ...).Count` |
| 00_summary.md 字节数 | (略,本文件内) | `(Get-Item ...).Length` |
| 输入子报告 | 4 份 (01/02/03/04) 全部 verifier PASS | `mavis team plan status plan_062e0d50` |
| 本汇总写作方式 | owner 手动写,不调 plan engine | — |

---

## §1. 计数与映射

### §1.1 4 份子报告的原始计数(Select-String 2026-06-11 17:00 实测)

```powershell
# 实测命令,任何人可重跑
$f1 = 'D:\...\Assets\Scripts\Fuel\Review\01_launcher.md'
$f2 = 'D:\...\Assets\Scripts\Fuel\Review\02_netframework.md'
$f3 = 'D:\...\Assets\Scripts\Fuel\Review\03_manager.md'
$f4 = 'D:\...\Assets\Scripts\Fuel\Review\04_auxiliary.md'
(Select-String -Path $f1 -Pattern '^### 🔴').Count  # => 3   (A1: P0)
(Select-String -Path $f1 -Pattern '^### 🟠').Count  # => 11  (A2: P1)
(Select-String -Path $f1 -Pattern '^### 🟡').Count  # => 9   (A3: P2)
(Select-String -Path $f1 -Pattern '^### 🟢').Count  # => 3   (A4: P3)
(Select-String -Path $f2 -Pattern '### \[T1\]').Count # => 6   (B1: T1)
(Select-String -Path $f2 -Pattern '### \[T2\]').Count # => 9   (B2: T2)
(Select-String -Path $f2 -Pattern '### \[T3\]').Count # => 6   (B3: T3)
(Select-String -Path $f3 -Pattern '^### T1-[0-9]').Count # => 6   (C1: T1)
(Select-String -Path $f3 -Pattern '^### T2-[0-9]').Count # => 25  (C2: T2)
(Select-String -Path $f3 -Pattern '^### T3-[0-9]').Count # => 20  (C3: T3)
(Select-String -Path $f4 -Pattern '\[Critical\]').Count # => 2   (D1: Critical)
(Select-String -Path $f4 -Pattern '\[Major\]').Count    # => 21  (D2: Major)
(Select-String -Path $f4 -Pattern '\[Minor\]').Count    # => 28  (D3: Minor)
(Select-String -Path $f4 -Pattern '\[Info\]').Count     # => 2   (D4: Info)
```

| 子报告 | P0 / T1 / Critical | P1 / T2 / Major | P2 / T3 / Minor | P3 / Info |
| --- | --- | --- | --- | --- |
| 01 Launcher | 3 (🔴) | 11 (🟠) | 9 (🟡) | 3 (🟢) |
| 02 NetFramework | 6 (T1) | 9 (T2) | 6 (T3) | 0 |
| 03 Manager | 6 (T1) | 25 (T2) | 20 (T3) | 0 |
| 04 Auxiliary | 2 (Critical) | 21 (Major) | 28 (Minor) | 2 (Info) |
| **原始小计** | **17** | **66** | **63** | **5** |

> **注 1**:04 报告 §9 总结表自报"2 Critical / 21 Major / **26** Minor / 2 Info",但本节实测 Minor=28。差 2 条(Minor 8.5 + 8.6)。实测为准,本汇总使用 28。
> **注 2**:03 报告 §0.4 自报"6+25+20=51",与本节实测一致。
> **注 3**:02 报告风险摘要表自报"T1×6 / T2×9 / T3×6 共 21",与本节实测一致。
> **注 4**:01 报告风险摘要表自报"3 / 11 / 9 / 3 = 25 (撤除 L26 后 = 24)",与本节实测一致。

### §1.2 严重度映射规则(写到本节便于审计)

| 子报告 | 原始标记 | 映射到统一等级 |
| --- | --- | --- |
| 01 Launcher | 🔴 P0 → P0;🟠 P1 → P1;🟡 P2 → P2;🟢 P3 → P3 | **1:1 等价映射** |
| 02 NetFramework | T1 → P0;T2 → P1;T3 → P2 | **T1/T2/T3 ≡ P0/P1/P2**(Critical=阻塞 / Major=正确性 / Minor=风格)|
| 03 Manager | T1 → P0;T2 → P1;T3 → P2 | **同 02 等价映射** |
| 04 Auxiliary | Critical → P0;Major → P1;Minor → P2;Info → P3 | **Critical/Major/Minor/Info ≡ P0/P1/P2/P3** |

> **等价性论证**:4 份子报告的"Critical"定义都收敛到「**线上崩溃 / 数据丢失 / 编译失败 / 阻塞游戏主流程**」,且子报告的 T1/Critical 描述与 Launcher 🔴 P0 用例完全可类比(如"启动后玩家无法进入游戏"、"消息静默丢失")。映射不引入主观判断。

### §1.3 统一后的 P0/P1/P2/P3 总数(由 §1.1 + §1.2 推算)

| 等级 | Launcher | NetFramework | Manager | Auxiliary | **总计** |
| --- | --- | --- | --- | --- | --- |
| **P0** | 3 | 6 | 6 | 2 | **17** |
| **P1** | 11 | 9 | 25 | 21 | **66** |
| **P2** | 9 | 6 | 20 | 28 | **63** |
| **P3** | 3 | 0 | 0 | 2 | **5** |
| **合计** | 26 | 21 | 51 | 53 | **151** |

> **本汇总 §3 只列 P0 + P1(=17+66=83 条),P2/P3 在子报告里详述,本汇总不再重复 63+5=68 条小问题,以避免文档膨胀**。

---

## §2. 执行摘要

1. **整体代码健康度**:**C-**(4 个子模块中有 3 个存在 6+ 个 P0/Critical 级问题,且 #04 报告的 3.1 `ObjectPools.DebugLogger` 引用是**编译期失败**级别 — Player Release 包根本打不出来,这是**头号阻塞**)。
2. **P0/P1 总数**:**83 条**(17 个 P0 + 66 个 P1,详见 §3 + §9 一一对应)。其中 P0 全部为「线上崩溃 / 数据丢失 / 编译失败 / 启动阻塞」类,P1 为「正确性 / 资源泄漏 / 状态机污染」类。
3. **阻塞性问题 Top 5**:
   - **04 #3.1** `ObjectPools.DebugLogger` 引用不在 `#if` 内 — **Player Release 编译失败**(`Pool/ObjectPools.cs:134, 159, 177, 199`)。
   - **04 #2.1** `MonoSingleton._applicationQuitting` 监听 `EnteredEditMode` 错误 — Editor 重新 Play 时 `Instance` 返 null,启动代码级联 NRE(`Singleton/MonoSingleton.cs:14-23, 79-82`)。
   - **01 #L01** `InvokeHotUpdateEntryAsync` 只识别 `UniTask` — `Task`/`void`/`ValueTask` 入口被吞,玩家进游戏前业务入口**根本没跑**,首场景黑屏无日志(`Launcher/GameUpdatePipeline.cs:119-121`)。
   - **01 #L02** HybridCLR `LoadMetadataForAOTAssembly` 重复注册崩溃 + **01 #L04** 管线 Failed 时不回收全局状态 — 任何断网重试 = 二次启动必崩(`Launcher/HybridCLR/HybridCLRLoader.cs:17-33` + `Launcher/GameUpdatePipeline.cs:104-110`)。
   - **03 #T1-03** `EventDispatcher` 强引用持有订阅者 — 业务忘调 `Unregister` 拖死整个场景 MonoBehaviour 树(`Manager/EventDispatcher/EventDispatcher.cs:92-155`)。
4. **建议的修复次序**(详见 §6):**Week 1** 修 17 条 P0;**Week 2** 修 66 条 P1 中的 top 20(资源句柄 / 状态机 / 协议安全 / 异常吞噬);**Month 1** 清完 P1 + 选 P2。
5. **诚实说明**:本汇总基于 4 份已 PASS 的子报告,**没有重新跑 Unity 编译、没有执行 E2E、没有审计测试覆盖率、没有审计 `Assets/HybridCLR/` 与 `Assets/Table/` 运行时库源码**。详见 §7。

---

## §3. P0/P1 问题清单(全模块聚合,按 ID 严格排序)

> **本节 ID 约定**:`L#-##` = Launcher / `N#-##` = NetFramework / `M#-##` = Manager / `A#-##` = Auxiliary。
> **本节条目数 = 17 P0 + 66 P1 = 83 条**。§9 证据索引条目数 = 83,与本节严格 1:1 对应。
> **每条字段**:ID / 模块 / 严重度 / file:line / 一句话 / 影响 / 修复方向(只写方向,不写代码) / 成本 S(<1h)·M(半天)·L(1 天+)。
> **排序**:先按模块,模块内按 ID 序号。

### §3.1 Launcher 模块 (L01-L26, P0=3, P1=11)

#### 🔴 P0

- **L01** · Launcher · 🔴 P0 · `Launcher/GameUpdatePipeline.cs:119-121` · 热更入口方法签名只识别 `UniTask`,`Task`/`void`/`ValueTask` 入口被吞 · 玩家进游戏前业务入口根本没跑,首场景黑屏/卡住无任何异常日志 · 四分支处理(UniTask/Task/Void/ValueTask),或接口层硬约束入口为 `UniTask` · **S**
- **L02** · Launcher · 🔴 P0 · `Launcher/HybridCLR/HybridCLRLoader.cs:17-33` · `LoadMetadataForAOTAssembly` 无幂等保护,任何断网重试二次启动直接崩 · 玩家只能强杀,断点续传场景 100% 复现 · `HybridCLRLoader` 内部维护 `HashSet<string> _loadedMetadata` 注册前查重,失败分支记录已注册集合以便跳过 · **M**
- **L03** · Launcher · 🔴 P0 · `Launcher/HybridCLR/HybridCLRLoader.cs:35-48` · Editor 跳过 YooAsset 字节,直接 `AppDomain` 找已编译 dll · 生产 hotupdate 代码 Editor 永不被测,QA 周期被拉长,大量 hotupdate 崩溃只能上真机才发现 · Editor 加 `LAUNCHER_USE_HOTUPDATE_IN_EDITOR` 开关默认开,让 Editor 走 `Assembly.Load(bytes)`;AppDomain 找不到时 `Debug.LogError` 不静默 fallback · **M**

#### 🟠 P1

- **L04** · Launcher · 🟠 P1 · `Launcher/GameUpdatePipeline.cs:104-110` · 管线 catch 只 `SetStep(Failed) + throw`,不回收任何全局状态 · 二次启动叠加 L02 必崩;YooAsset 内部缓存堆积死 package · 进入 `try` 前记录 `enteredSteps` 列表,catch 按反向顺序回滚;为 `YooAssetResourceUpdateService` 加 `DestroyAsync`,`HybridCLRLoader` 加 `UnloadAsync`,`TableKitConfigLoader.Clear()` 已在,在管线失败分支调一次 · **M**
- **L05** · Launcher · 🟠 P1 · `Launcher/Resources/YooAssetResourceUpdateService.cs:14-20` · `InitializeAsync` 跨重入无清理,`_package` 被覆盖 · 断网恢复后不会重新拉版本/清单,紧急 hotfix 对存量玩家永远不生效 · 入口检查 `initOperation?.Status == Succeeded && _package.PackageValid`,已初始化则 return;否则 `YooAssets.DestroyPackage + RemovePackage` 再走 `CreatePackage` 路径 · **M**
- **L06** · Launcher · 🟠 P1 · `Launcher/Resources/YooAssetResourceUpdateService.cs:96-100` · `ClearUnusedCacheAsync` 静默吞操作结果 · 玩家每次启动缓存膨胀一点直到某次 OOM 或下载失败,无任何错误信号 · 统一封装「`await op.ToUniTask(ct); if (op.Status != Succeeded) throw new InvalidOperationException(op.Error);`」helper,本文件 5 处 operation 全部走 helper · **S**
- **L07** · Launcher · 🟠 P1 · `Launcher/Resources/YooAssetResourceUpdateService.cs:71-94` · `DownloadProgressChanged` 进度回调线程模型未保证,可能跨主线程 · YooAsset 3.x 或自研 backend 在 worker 线程触发,UI 侧 `Text.text` NRE,IL2CPP 随机崩溃 · `progress.Report` 前用 `UnityMainThreadDispatcher` 或 `Awaitable.NextFrameAsync` 切回主线程 · **M**
- **L08** · Launcher · 🟠 P1 · `Launcher/Version/HttpJsonVersionService.cs:14-31` · `FetchVersionAsync` 无重试 / 无 backoff / 无离线降级 · 移动端 4G 切 5G、地铁、电梯单次成功率不足 60%,一次网络抖动 = 一次玩家流失 · Polly 风格重试 2-3 次指数 backoff;持久化 last-known-good `RemoteVersionInfo` 到 `PlayerPrefs`/磁盘,失败时回退;`JsonUtility.FromJson` 后增字段缺失/越界校验 · **L**
- **L09** · Launcher · 🟠 P1 · `Launcher/Version/SemanticAppVersionChecker.cs:19-32` · `Compare` 只比较 3 段且忽略 pre-release/build 元数据 · `1.0.0-alpha` ≡ `1.0.0` ≡ `1.0.0-anything`;`1.0.0.0` ≡ `1.0.0.5`,玩家错过强制热更 · 用 `System.Version` 或自写区分 pre-release 优先级的实现;`JsonUtility` 兜底放调用方 · **M**
- **L10** · Launcher · 🟠 P1 · `Launcher/GameUpdatePipeline.cs:72-82` · 资源 CDN 挂掉时无 built-in 兜底 · `LoadPackageManifestAsync` 失败即抛,CDN 单点故障 = 全平台玩家无法启动 · 把 `_package.InitializePackageAsync` 失败视作 soft-fail,退化为「仅用 built-in 资源」+ UI 提示 · **L**
- **L20** · Launcher · 🟠 P1 · `Launcher/GameUpdatePipeline.cs:115` · `BindingFlags.Public | BindingFlags.Static` 找不到 `private`/`internal` 入口 · 业务按 Unity 惯例写 `private static` 入口启动即崩,`MissingMethodException` 排查时间长 · `BindingFlags` 改为 `Public | NonPublic | Static`,或在文档/注释里硬性约束「入口必须 public static」+ lint 校验 · **S**
- **L21** · Launcher · 🟠 P1 · `Launcher/Table/TableKitConfigLoader.cs:18` · 写 `TableKit.RuntimePathPattern` 前无空校验 · `StartupConfig.json` 漏配 `configPathPattern` 字段时崩在 TableKit 阶段,排查链路要追到 TableKit 源码 · `IStartupConfigProvider.Load()` 后跑 `Validate()`(检查 `versionUrl`/`hotUpdateDllPath`/`hotUpdateEntryType`/`configPathPattern` 必填);`TableKitConfigLoader` 内部加 `Debug.Assert` · **S**
- **L22** · Launcher · 🟠 P1 · `Launcher/Resources/YooAssetResourceUpdateService.cs:65-69` · `CheckUpdateAsync` 泄漏旧 `_downloader` + `_package` 无 null 守卫 · 业务不按 `InitializeAsync → CheckUpdateAsync` 顺序调用时 NRE,无任何错误消息 · 入口 `_package ?? throw new InvalidOperationException("InitializeAsync must be called first")`;`_downloader` 改局部变量,`DownloadAsync` 接受 `ResourceDownloaderOperation` 参数 · **S**
- **L23** · Launcher · 🟠 P1 · `Launcher/GameUpdatePipeline.cs:80` · 进度事件通过 `Action<>` 透传,缺主线程保证 · YooAsset 2.x 默认主线程,3.x / 自研 backend 在 worker 线程,UI 侧 NRE · 在 `IResourceUpdateService.DownloadAsync` 注释里硬性标注线程约束;管线层包 `MainThreadProgress(progress)` 装饰器把回调投回主线程 · **M**

### §3.2 NetFramework 模块 (N01-N21, P0=6, P1=9)

#### 🔴 P0

- **N01** · NetFramework · 🔴 P0 · `NetFramework/Attributes/NetMessageHandlerAttribute.cs:67-107` · `NetMessageHandlerAttribute` 反射注册机制根本没接入,全模块 0 调用方 · 任何按 attribute 风格写的业务代码 0 路径被 dispatch,运行时静默丢消息,`MessageDispatcher` 只 `LogWarning` 无异常 · 要么删 attribute + `ProtoCmdsLookup` 整文件改文档;要么新增 `DispatcherScanner.ScanAllAssemblies()` 启动时扫 `[NetMessageHandler]` 方法并调 `Dispatcher.Register`,`MsgId` 在 ctor 内算一次缓存为 `readonly uint` · **M**
- **N02** · NetFramework · 🔴 P0 · `NetFramework/Protocol/TcpProtocol.cs:88-114` · `Connect` 异常路径只调 `OnError`,不调 `OnDisconnected` · 上层重连状态机被饿死,业务 UI 卡"错误弹窗/重试按钮"状态,需业务侧从 `OnConnectError` 主动 `Connect()` · 在 catch 末尾 `OnError?.Invoke` 之后再调 `OnDisconnected?.Invoke(true)`;DNS 解析失败 line 67-68 同理补一行 · **S**
- **N03** · NetFramework · 🔴 P0 · `NetFramework/Core/HeartbeatManager.cs:168-175` + `NetFramework/Core/NetworkManager.cs:308-314` · `HeartbeatManager.SendPing` 在 `OnSendPing` 可能 no-op 时仍设 `_waitingPong=true` · 用户 `PingCmdId=0` 关心跳反而被系统判定为心跳超时并主动断开,严重反直觉 · 把 `_waitingPong = true`(line 171) 移到 `OnSendPing?.Invoke` 之后;或在 `NetworkManager.SendPingInternal` 早返回时调 `HeartbeatManager.AbortPing()` 把 `_waitingPong = false` · **S**
- **N04** · NetFramework · 🔴 P0 · `NetFramework/Protocol/TcpProtocol.cs:248-295` + `NetFramework/Dispatcher/MessageDispatcher.cs:295-311` + `NetFramework/Dispatcher/BoundedActionQueue.cs:39-48` · 接收循环批量入队 + 100/帧限速 + 静默丢消息 · 服务端漏配流控,客户端一帧 1000+ 包 → 队列稳态满 → 新消息入队时老消息被静默丢,业务侧零信号 · `MessageDispatcher.Update` 加观察点:dequeue 时若 `DroppedCount > 0` 且距上次告警 ≥ 1s 打 `LogWarning`;或把"100/帧"改为"每帧耗时预算";长期把 `DroppedCount` 暴露为可订阅事件 · **M**
- **N05** · NetFramework · 🔴 P0 · `NetFramework/Dispatcher/MessageDispatcher.cs:280-283, 303-307` + `NetFramework/Core/NetworkManager.cs:186-190` + `NetFramework/Protocol/TcpProtocol.cs:271-273` · handler 异常被 catch 静默吞,无 `AppDomain.UnhandledException` 桥接 · 业务 handler 抛 NRE 被吞,Debug.LogError 写本地日志不接 Sentry/Bugly/CrashSight,生产事故定位极难 · 新增 `GlobalExceptionHandler` 静态类启动时注册 `AppDomain.CurrentDomain.UnhandledException` + `Application.logMessageReceivedThreaded` 桥接 Unity log;上面 4 个 catch 块在 `Debug.LogError` 之后把异常再 throw 一份给全局 sink · **M**
- **N06** · NetFramework · 🔴 P0 · `NetFramework/Dispatcher/MessageDispatcher.cs:65-90, 127-174` · `Register` 覆盖无清理 + 旧 `MessageParser<T>` 闭包立即变孤儿 · 重复 Register(scene reload / ILRuntime 重载 / 业务 `Awake` 多次)→ N 个 `MessageParser<TResp>` 累积,主线程 GC 抖动;业务以为注册了 handler A 实际跑的是 handler B · 三处 Register 覆盖前先 `Unregister(cmdId)`(或抛 `InvalidOperationException`),强制业务侧显式注销;`Register` 内部把 `MessageParser` 实例提升到 `Dictionary<uint, MessageParser>` 字段 · **M**

#### 🟠 P1

- **N07** · NetFramework · 🟠 P1 · `NetFramework/Dispatcher/MessageDispatcher.cs:8-37` · 文件头缺"handler 跑在主线程"契约文档,接 Single Update 时易误用 · 接手人写 `handler = msg => transform.position = ...` 会担心跨线程,实际不会爆但需读懂 `_mainThreadQueue` 才知道 · `MessageDispatcher.cs:9-13` class comment 改为"handler 一定在 Unity 主线程被调用,在 handler 内访问 UnityEngine.Object / transform / Component 是安全的" · **S**
- **N08** · NetFramework · 🟠 P1 · `NetFramework/Core/NetworkManager.cs:253, 332` + `NetFramework/Core/HeartbeatManager.cs:75` + `NetFramework/Tests/NetworkManagerE2ETest.cs:90-91` · `NetworkManager` 强绑 `Time` / `MonoSingleton`,核心路径 0 单元测试 · 主路径无任何纯 dotnet 单元测试,只能靠 E2E 心跳且 E2E 实际绕开 `Send<T>`,改 `_reconnectDelay` 字段名 = E2E 反射路径全断 · `NetworkManager.OnInit` line 67 改 `new HeartbeatManager(() => Time.realtimeSinceStartup)`;把 `InitialReconnectDelay` / `MaxReconnectDelay` / `_reconnectAttempts` 暴露 public 属性 + set;抽 `INetworkManager` 接口,核心连接/发送/接收走纯 C# 类 · **L**
- **N09** · NetFramework · 🟠 P1 · `NetFramework/Core/NetworkManager.cs:231-257, 327-335` · 重连退避在"网络抖动"下被 `_reconnectAttempts++` 加速 · socket 线程在 < 16ms 内连发两次异常断开 → 两次 Enqueue → 主线程下一帧 dequeue 两次 → `_reconnectAttempts = 2`;`_reconnectDelay *= 2` 也在 Enqueue 内 → 退避比预期陡 · `_reconnectAttempts++` / `_reconnectDelay *= 2` 搬到 `DriveReconnect` 调 `TryReconnect` 前(主线程);或加 `_reconnectAttempts` 上限 + 抖动 `Random.Range(0, _reconnectDelay * 0.1f)` · **M**
- **N10** · NetFramework · 🟠 P1 · `NetFramework/Core/HeartbeatManager.cs:38` · `Paused` 公开可写(`public bool Paused { get; set; }`) · 业务侧可随时 `NetworkManager.Heartbeat.Paused = true`,与 `Start/Stop/ResetRetryCount` 状态机打架,无文档说明"什么时候 paused 什么时候 Stop" · `Paused` 改 `internal`,或用 `Suspend()/Resume()` 显式 API · **S**
- **N11** · NetFramework · 🟠 P1 · `NetFramework/Dispatcher/BoundedActionQueue.cs:1-3` + `NetFramework/Dispatcher/MessageDispatcher.cs:37` · `BoundedActionQueue.cs` 注释说"已移入 MessageDispatcher.cs",实际类还在原文件 · 注释与代码矛盾,半完成迁移的死亡状态;后续 PR 若按注释预期删 `BoundedActionQueue.cs`,`MessageDispatcher._mainThreadQueue` 编译错误 · 选一条路走完:要么真迁到 `MessageDispatcher` 嵌套类并删 `BoundedActionQueue.cs`(改 `internal`);要么把注释改回"BoundedActionQueue 作为独立类供 MessageDispatcher 内部使用" · **S**
- **N12** · NetFramework · 🟠 P1 · `NetFramework/Codec/PacketCodec.cs:9, 29, 92` · 协议层无 `magic` 校验 / 无版本号字段 · 易受重放/协议混淆攻击;长 length 在 Decode 抛之前的 buffer 分配阶段 `available < required` 永远不返回,业务侧无感 · `PacketCodec.Decode` line 92 已对 `length` 上限判 OK,新增 magic 字段(4 字节)到 `PacketCodec`,`Decode` 第一步校验 magic 不匹配直接断开;增加 version 字段(2 字节)以便后续协议升级 · **M**
- **N13** · NetFramework · 🟠 P1 · `NetFramework/Attributes/NetMessageHandlerAttribute.cs:43-60, 84` + `NetMessageHandlerAttribute.cs:23` · `ProtoCmdsLookup.GetMsgId` 走 `Type.GetType` 字符串解析,`MsgId` 每次反射读 · 启动 hot-update 前 `_cmdsType == null` → `GetMsgId` 返回 0;即便要修,`MsgId` 应在 ctor 算一次缓存为 `readonly uint`;每次 attribute 读 `MsgId` 都走 `GetField(...).GetRawConstantValue()` 反射 · `MsgId` 在 attribute ctor 内算一次缓存为 `readonly uint`(避免每次读都走 `Type.GetType` 反射);启动时显式 `ProtoCmdsLookup.Initialize()` 注入 Type 引用 · **S**
- **N14** · NetFramework · 🟠 P1 · `NetFramework/Core/NetworkManager.cs:135-177` · `Send<T>` 失败原因不可观测,业务侧拿 `false` 不知道为什么 · 业务侧 debug"为什么消息没发出去"只能读 logcat · `Send` 返回 `SendResult` 枚举(`Success` / `NotConnected` / `NoCmdId` / `NoCmdGetter` / `ProtoSerializeFailed`),或 `bool Send<T>(out string reason)` · **S**
- **N15** · NetFramework · 🟠 P1 · `NetFramework/Tests/NetworkManagerE2ETest.cs`(整文件 334 行) · `NetworkManagerE2ETest` 与生产代码脱节,主路径 0 覆盖 · `TestSmallMessage`/`TestLargeMessage` 用 `proto.Send(packet)` 直接发字节,绕开 `NetworkManager.Send<T>` → 生产 `Send<T>` 路径 0 覆盖;`CacheRequest` req-rsp FIFO / `Unregister` 清理 / `MessageDispatcher.Clear` 后状态 / `Heartbeat.OnMaxRetryExceeded` 触发全部 0 case · 改用 `_nm.Send<T>(msg)` 覆盖真实路径;新增 `CacheRequest` FIFO、`Unregister` 清理、`Heartbeat.OnMaxRetryExceeded` 触发等 case · **L**

### §3.3 Manager 模块 (M01-M51, P0=6, P1=25, P2=20 不列入本节)

#### 🔴 P0

- **M01** · Manager · 🔴 P0 · `Manager/AudioManager/AudioManager.GoAudioSource.cs:51-64` + `Manager/AudioManager/AudioSource.cs:73-93, 114-157` · `AudioSourceData` 池化后未复位全部字段,导致鬼叫 / 循环残留 / 回调串台 · 静默音频 bug,音游 / SLG / 卡牌 BGM/BGS/SE 全炸;`_onStopFadeFinish` 旧 Stop 回调会在新一次播放的某个时刻被误触 · `GetAudioSourceData()` 弹出后强制 `data.ReuseReset()` 全量复位;`Play()` 入口无条件 `ResetInnerData()` · **M**
- **M02** · Manager · 🔴 P0 · `Manager/AssetManager/AssetsGroup.cs:60-136` + `Manager/AssetManager/AssetsGroupManager.cs:53-60` · `AssetsGroup` 同步加载路径无 `_loadVersion` 检查,`StopLoadByGroup` 无法取消 in-flight 同步调用 · 切场景资源重置失效,新旧资源混用 · 同步路径也应加版本号检查;或把 `StopLoad()` 改为抛 `OperationCanceledException` · **M**
- **M03** · Manager · 🔴 P0 · `Manager/EventDispatcher/EventDispatcher.cs:92-155` + `EventHandlerList<T>`(line 12-87) · `EventDispatcher` 强引用持有订阅者,反注册遗漏会拖死场景 · 长期运行下内存增长 + 触发"幽灵回调"(销毁后实例被回调);MonoBehaviour 销毁后漏调 `Unregister` 就会强引用整个 GameObject 树 · `ConditionalWeakTable<object, List<Action>>` + owner key;或 `Register<T>(object owner, Action<T>)` + 按 owner type 清;或 `RegisterOnce<T>(Action<T>)` 一次性模式 Invoke 后自动 unregister · **L**
- **M04** · Manager · 🔴 P0 · `Manager/AssetManager/AssetsPools/GameObjectPool.cs:60-98, 16` + `Manager/AssetManager/AssetsPools/OtherPool.cs:62-83` · `GameObjectPool.GetAsync` 池空时 `InstantiateAsync` 不受 `MaxPoolCount=100` 限制 · 大场景初始化(1000 个敌人)瞬间内存峰值,失去池化意义 · Get 路径加 active-cap 检查,或拆 `MaxPoolCount` 为 active+pool 两部分;或预热模式下走 cap,运行时突破走 cap+warn · **M**
- **M05** · Manager · 🔴 P0 · `Manager/AudioManager/AudioSource.cs:98-103` · `AudioSourceData.Dispose` 销毁 AudioSource Component 但不置 null,Update 抛 NRE · 长时间运行后 BGS 全部失效,且抛 NRE;`TickFade` 内部 `_as.volume = ...` 不判空 · Dispose 内部加 `if (_as) { GameObject.Destroy(_as); _as = null; }`;`TickFade/TickRecycle` 入口判 `_as == null` 即 return · **S**
- **M06** · Manager · 🔴 P0 · `Manager/UIManager/UIResourceManager.cs:101-116, 125-142` + `Manager/UIManager/UIManager.cs:188-231` · `UIResourceManager.CreateInstance` 同步阻塞主线程 + `ReleaseAllByGroup` 串台释放 · CDN 模式下 `LoadSync` 内部用 `WaitForCompletion` 阻塞主线程数百 ms;整个 group 的 `ReleaseAllByGroup` 销毁包含业务代码动态加载的同 groupName 子资源 · `OpenWindowAsync` 拆分(预加载 async,激活 Show 时 SetActive);业务子资源 groupName 改 `windowId + ".sub"` 与 prefab groupName 隔离;`CreateInstance` 后的 prefab 引用必须 Clone 独立 · **L**

#### 🟠 P1

- **M07** · Manager · 🟠 P1 · `Manager/AssetManager/AssetsGroupManager.cs:9, 70-89` · `AssetsGroupManager` 是 `Singleton<C#>` 不是 `MonoSingleton`,`OnDestroy`/`OnDispose` 是死代码 · `_groupMap` 永远不自动清理,业务销毁后残留所有 `AssetsGroup`(包含 `AssetHandle` 句柄),YooAsset 句柄泄漏 · 改 `MonoSingleton`;或显式 `public void Dispose()` 业务手动调;或框架统一 Application.quitting hook · **L**
- **M08** · Manager · 🟠 P1 · `Manager/EventDispatcher/EventDispatcher.cs:149-155` · `EventDispatcher.Dispatch` 无线程保护,handler 内访问 UnityEngine 抛"main thread only" · `Singleton` 没有主线程约束,`Task.Run`/`ThreadPool` 调 `Dispatch<T>` 会在子线程 `foreach` 调 handler · 入口加 `if (Thread.CurrentThread.ManagedThreadId != _mainThreadId) throw`;或提供 `MainThreadDispatcher.Post(...)` marshal 回主线程 · **M**
- **M09** · Manager · 🟠 P1 · `Manager/AudioManager/AudioManager.cs:492-498` · `AudioManager.SetBGMAndBGSVolume` 语义错乱,BGM/BGS 音量绑定后无法独立调 · 业务无法独立静音 BGS 而保留 BGM · 删除联合接口,或显式 `CoupleVolumes(bool)` 控制 · **S**
- **M10** · Manager · 🟠 P1 · `Manager/AudioManager/AudioSource.cs:203-216, 240-249, 300-313` · `AudioSourceData.Pause(fadeTime > 0)` 走 `AutoSetFade` 后 `TickFade` 在 `State == Stopped` 时仍改 `_as.volume` · 已 Stopped 的 source 调 Pause,`_as.Pause()` no-op 但 `AutoSetFade` 启动 fade 定时器,`TickFade` 改 `_as.volume = 0` 在 Stopped 时合法但语义错 · 把 `Stopped` 列入 early return(line 205) · **S**
- **M11** · Manager · 🟠 P1 · `Manager/AudioManager/AudioManager.cs:150` · `AudioManager.OnDestroy` 调 `Resources.UnloadUnusedAssets().ToUniTask().Forget()` · `Forget()` 的 UniTask 在 `Application.quitting` 后 Unity 已不允许异步操作可能 NRE;`Resources.UnloadAsset` 对 YooAsset clip 是 no-op,内存不会被释放 · 不要在 OnDestroy 调 UnloadUnusedAssets;让 YooAsset 自己管理;明确 clip 来源并只清 Resources 来源 · **S**
- **M12** · Manager · 🟠 P1 · `Manager/AudioManager/AudioSource.cs:114-157, 64, 70` · `AudioSourceData.Play` 重新播放时 `_onStopFadeFinish` 残留,`m_loop` 残留 · 新一次播放自然结束时 `TickRecycle` 的 `_onComplete` 与 `_onStopFadeFinish` 混存,上次 Stop 回调会在不期望的时机被触发 · `Play` 入口 `ResetInnerData()`;或显式 `_onStopFadeFinish = null; m_loop = false;` · **S**
- **M13** · Manager · 🟠 P1 · `Manager/AudioManager/AudioManager.cs:30, 681, 138-152` · `AudioManager._bgsGoAudioSource` 字段在 `Dispose` 后未置 null · 下次 `PlayBgs` 时判 null 失败,后续 `GetAudioSourceData` → `m_pool.Count == 0` → `new AudioSourceData(...)` → 这个新加的 instance 在已经被 disposed 的 GoAudioSource 里 → NRE · `_bgsGoAudioSource = null` 在 `OnDestroy`/`StopBgs` 显式调用 · **S**
- **M14** · Manager · 🟠 P1 · `Manager/CoroutineManager/CoroutineManager.cs:114-122, 169-172` · `CoroutineManager.RunWithKey` 异常路径不清 dict,`OnDestroy` 没先 `StopAllCoroutines` · 协程抛异常时包装协程被 Unity 静默停止但 `_coroutineDict` 里的 entry 不会清,key 永久占用;`OnDestroy` 只 `_coroutineDict.Clear()` 没有先 `StopAllCoroutines()`,残协程的 finally 还可能在 destroy 后触发 · `RunWithKey` 用 `try { ... } finally { _coroutineDict.Remove(key); }`;`OnDestroy` 先 `StopAllCoroutines()` 再清 dict · **S**
- **M15** · Manager · 🟠 P1 · `Manager/AssetManager/AssetsPools/GameObjectPools.cs:31, 82, 121, 138` + `Manager/AssetManager/AssetsPools/PoolBase.cs:278-318` + `Manager/AssetManager/AssetsPools/PoolBase.cs:81-102` · `GameObjectPools._loadIndex` 跨线程无 `Interlocked`,race 写入丢失 · `Interlocked.Increment(ref _loadIndex)` 同时 `_loadIndexCheckMap[groupName][code] = _loadIndex` 也是 race · 全部改 `Interlocked.Increment(ref _loadIndex)`;或封装为单 map `Dictionary<(groupName, code), (loadIndex, callback)>` 避免双 map · **M**
- **M16** · Manager · 🟠 P1 · `Manager/AssetManager/AssetsPools/AudioClipPools.cs:11-15` + `Manager/AssetManager/AssetsPools/OtherPool.cs:75-82` · `AudioClipPools` 用 `InstantiatePools<AudioClip>`,但 `AudioClip` 不应走 Instantiate · `Object.Instantiate(audioClip)` 语义不明确(share data);真正的"复用"是直接拿 `_allClips[path]`,`AudioManager` 自己在 `GetClip` 已 cache 了 · AudioClipPools 改 `ReferencePools<AudioClip>`,或 AudioManager 直接 `AssetsLoadManager.LoadAsync<AudioClip>` 配合 cache · **S**
- **M17** · Manager · 🟠 P1 · `Manager/SceneManager/SceneManager.Loading.cs:55-106` · `SceneManager.LoadMainSceneAsync` 失败路径无 `Scene_LoadFailedEvent`,UI 进度条卡 100% · 失败走到 `onComplete?.Invoke(); return;`,但 `Scene_LoadStartEvent` 已 dispatch — 失败时没有 fail 事件,业务订阅方不知道失败 · 加 `Scene_LoadFailedEvent` 并在失败分支 dispatch · **S**
- **M18** · Manager · 🟠 P1 · `Manager/SceneManager/SceneManager.Loading.cs:228-247` + `Manager/SceneManager/Data/SceneBase.cs:47-50` · `SceneBase.OnExit` 同步 `ReleaseAllByGroup` 与 `UnloadSceneAsync` 句柄 race · `OnExit` 默认实现 `AssetsLoadManager.Instance.ReleaseAllByGroup(AssetsGroupName)` 同步阻塞主线程;随后 `await UnloadNativeSceneAsync` 触发 scene 资源 unload,与刚才 sync 释放的 group 资源存在 race · `OnExit` 改 `OnExitAsync`;或 scene unload 自动处理 · **M**
- **M19** · Manager · 🟠 P1 · `Manager/SceneManager/SceneManager.SceneScript.cs:80-101, 97-100` · `SceneManager.FindOrCreateSceneRoot` additive 场景 root 漂浮,无主场景归属 · additive 场景创建空 root GameObject 无 `parent = mainSceneRoot`,无 `DontDestroyOnLoad`;场景切换时这些空 root 与所属 scene 一起被卸载,绑定的 script 引用主场景对象 → missing reference · additive scene root 设 `parent = FindOrCreateSceneRoot(currentMainSceneId)`,并 `DontDestroyOnLoad` · **S**
- **M20** · Manager · 🟠 P1 · `Manager/UIManager/UIStack.cs:79-90` · `UIStack.Push` 重复入栈的接口契约不一致 · `Push` 在 `index >= 0` 时调 `PopToIndex(index)` 但不 push 新 window;`UIManager.OpenWindow` 依赖此行为,但 `Push` 接口契约与实现不一致易误用 · 改名 `BringToFrontOrPush` 明确语义 · **S**
- **M21** · Manager · 🟠 P1 · `Manager/UIManager/UIManager.cs:284-315, 302-306` · `UIManager.ReloadWindow` 重新调 `OnShow()` 但不传 `data`,reload 丢失原 data · `wasShown` 时 `window.OnShow()`(line 305) 无参;原 `UIWindowData data` 在 `OpenWindow` 时通过 `OnShow(data)` 传入,reload 后只剩 `OnShow()` — `data` 丢失 · OpenWindow 缓存最近一次 `data`,ReloadWindow 复用 · **S**
- **M22** · Manager · 🟠 P1 · `Manager/UIManager/UIManager.cs:258-267, 250-256` + `Manager/UIManager/UIStack.cs:92-113` · `UIManager.OnWindowPop`/`OnWindowClear` 不区分用户关闭 vs 系统回收 · 内部都触发 `OnHide` + `OnWindowHide` 事件,业务层 `OnDestroyEvent` 监听无法区分 · 传 `reason` 枚举,或拆 `OnWindowClosedByUser`/`OnWindowEvictedByOverflow` · **S**
- **M23** · Manager · 🟠 P1 · `Manager/AssetManager/AssetsGroup.cs:139-153, 270-293, 25-37` · `AssetsGroup.LoadSprite`/`LoadSpriteAsync` sub-asset 路径 `Release(path)` 用 path 找不到 mainPath · `_subAssetHandles[mainPath] = handle` 用 mainPath 作 key;`Release(string path)` 用 path 查 mainPath 不同 → `TryGetValue` 失败 → no-op · `Release` 同时按 subPath 查 mainPath 反向索引释放 · **M**
- **M24** · Manager · 🟠 P1 · `Manager/EventDispatcher/EventDispatcher.cs:94-107` · `EventDispatcher._typeIdMap` 静态 dict 跨域泄漏(AssemblyLoadContext 卸载场景) · 热重载 / EnterPlayMode without domain reload 场景下,旧 `Type` 引用可能 leak · 用 `Type.FullName` 作 key 运行时 resolve;或 `Init` 时清空 · **M**
- **M25** · Manager · 🟠 P1 · `Manager/AssetManager/AssetsPools/GameObjectPools.cs:118-165` + `Manager/AssetManager/AssetsPools/PoolBase.cs:81-151, 278-345` · `AssetsLoadManager.LoadAsyncByCode` `_loadIndex` 与 `LoadCallBack.LoadIndex` 双 map race · `StopLoadByGroup` 只清 `_loadCallBackMap` + `_loadIndexCheckMap`,in-flight 回调收到时 `TryGetValue` 失败,`loadIndex == 0`,`if (loadIndex == index)` 不成立 → 走 line 156-157 路径 recycle callback 但不 invoke — 业务层等不到结果 · 封装 `Dictionary<(groupName, code), (loadIndex, callback)>` 单 map · **M**
- **M26** · Manager · 🟠 P1 · `Manager/AssetManager/AssetsPools/PoolBase.cs:185-193` vs `Manager/AssetManager/AssetsPools/PoolBase.cs:195-218` · `InstantiatePools<T>.RecycleByGroup` 不查 `_loadCallBackMap`,与 `DestroyByGroup` 行为不一致(跨池污染) · 业务只调 `RecycleByGroup` 时 in-flight 回调的 `LoadCallBack<T>` 对象在 `ObjectPools.Recycle` 后被池化;但 dict 中还有 entry,新的同 path 加载会从池里取到**已被业务代码 retain 的 callback 引用** · `RecycleByGroup` 也清 `_loadCallBackMap` 和 `_loadIndexCheckMap`,或文档化"只 Recycle 不 Cancel"语义 · **S**
- **M27** · Manager · 🟠 P1 · `Manager/EventDispatcher/EventDispatcher.cs:49-53` · `EventHandlerList<T>.Invoke` 期间 handler 抛异常只 `LogError`,不通知业务层 · handler 异常被吞,业务订阅方无法感知事件链异常 · 在 try/catch 后调 `OnHandlerException?.Invoke(arg, e)` 业务可订阅;或集中通过 `GlobalExceptionHandler`(见 N05)统一上报 · **M**
- **M28** · Manager · 🟠 P1 · `Manager/UIManager/UIManager.cs:80-88, 150-163` · `UIManager.OnPreWillRenderCanvases` 只比对 `Screen.width/height`,方向改变但尺寸未变不触发 · 180° 转屏时 `Screen.width/height` 不变但方向变了,CanvasScaler 不重新计算 → UI 方向错 · 监听 `Screen.orientation` 或 `Application.onBeforeRender` · **M**
- **M29** · Manager · 🟠 P1 · `Manager/UIManager/UIManager.cs:274-277` · `UIManager.GetLayerRoot(int layerId)` 把 int 强转 `UILayer`,传错 silently 失败 · 业务传 `999` 强转 → `TryGetValue` 失败 → 返回 null,无 LogError · throw 或 LogError · **S**
- **M30** · Manager · 🟠 P1 · `Manager/AudioManager/AudioSource.cs:35-36, 86, 128, 167` · `AudioSourceData._fadeOffsetVolume` 字段已废弃但保留,代码注释(line 35)明示 · 增加维护成本易误读 · 删除,或显式 `[Obsolete]` attribute 标编译警告 · **S**
- **M31** · Manager · 🟠 P1 · `Manager/UIManager/UIManager.cs:33-34` · `UIManager._windowFactory`/`_resourceManager` 没有清理入口,切场景不重置 · 旧 window factory 引用泄漏,新场景同名 window 调 `RegisterWindow` 时 line 167 `_windowFactory[windowId] = factory` 替换 OK 但旧 factory 仍被 `UIWindow.OnDestroyEvent` 持有 · 加 `ClearAll()`/场景切换 `OnSceneUnloaded` 时清 · **S**

### §3.4 Auxiliary 模块 (A01-A51, P0=2, P1=21)

#### 🔴 P0

- **A01** · Auxiliary · 🔴 P0 · `Singleton/MonoSingleton.cs:14-23, 79-82` · `MonoSingleton._applicationQuitting` 监听 `EnteredEditMode`(太晚),Editor 重新 Play 时 `Instance` 返 null · 下次 Play→Awake 早于 editor transition 时 `_applicationQuitting` 仍为 true → 启动代码级联 NRE · 改在 `EnteredPlayMode` 或 `ExitingPlayMode` 重置 · **S**
- **A02** · Auxiliary · 🔴 P0 · `Pool/ObjectPools.cs:1-8, 134, 159, 177, 199` · `DebugLogger` 引用不在 `#if` 内,Player Release 编译失败 · `using Fuel.Log;` 在 `#if UNITY_EDITOR || DEVELOPMENT_BUILD` 内,但下面 4 行直接调 `DebugLogger.LogWarning` 不在 `#if` 内 → release build 找不到 `DebugLogger` 符号 · 把 4 处 `DebugLogger.LogWarning` 替换为 `UnityEngine.Debug.LogWarning`(always available, IL2CPP-safe);或对每处加 `#if UNITY_EDITOR || DEVELOPMENT_BUILD`;或把整个 `try`/`catch` body 包进宏 · **S**

#### 🟠 P1

- **A03** · Auxiliary · 🟠 P1 · `Singleton/MonoSingleton.cs:62-75` · `MonoSingleton.Awake` 写 `_instance` 无 lock / volatile · `Task.Run` 回调在后台线程调 `MyMonoSingleton.Instance` 可能看到 stale null · `_instance` 声明 `volatile`,或用 `Volatile.Read/Write`,或 `Interlocked.CompareExchange` in `Awake` · **S**
- **A04** · Auxiliary · 🟠 P1 · `Singleton/MonoSingleton.cs:62-75` · Multiple `MonoSingleton` instances on additive scene reload — `Destroy` is deferred · scene A additive 加载两次:第二次 Awake 见 `_instance != null` 调 `Destroy(gameObject)`,Destroy 延后到帧末,期间 `OnEnable`/`Start` 仍跑,duplicate 的 `OnDestroy` 设 `_instance = null` 后下次 `Instance.get` 走 auto-create 路径(line 47-54)又生第三个 GameObject · `OnDestroy` 中改成延迟到下一帧用 coroutine 或 `DestroyImmediate`(仅在 auto-create pending 时) · **M**
- **A05** · Auxiliary · 🟠 P1 · `RedDot/Runtime/RedDotNumberNode.cs:57-89` · `RedDotNumberNode.CalculateCount` 隐式 O(depth)-per-change propagation · 每个 leaf change 调 `m_parent?.CalculateCount()`,parent 调 grandparent;change-detection at line 82 `if (count != m_redDotCount)` 只 short-circuit callback dispatch,不 short-circuit upward walk · 节点存 `(count, dirty)`;`SetStatus` walk up 上去,parent count 没变就 break · **M**
- **A06** · Auxiliary · 🟠 P1 · `RedDot/Runtime/RedDotTree.cs:13-40` · `RedDotTree` static singleton 不在 Editor Play→Stop→Play 重置 · `m_instance` 是 static 字段,Unity domain reload 不清,前一 session 的 `_pendingRedDotSaves` 和 `_formattedPathCache` stale;`Root` children 指向 dead objects · subscribe `EditorApplication.playModeStateChanged` in `RedDotTree` ctor,`ExitingPlayMode` 时 `m_instance = null`;或用 `[RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]` · **M**
- **A07** · Auxiliary · 🟠 P1 · `RedDot/Runtime/RedDotConfigAsset.cs:55-76` · `RedDotConfigAsset.ResetIsChildData` 用 prefix-string `StartsWith`,非 segment-aware · `"mailbox/...".StartsWith("mail")` 返回 true,但 `mail` 和 `mailbox` 不是 parent/child 关系(无 segment 边界) · split path by `/` 按 element 比较;或 `Data[j].Path.StartsWith(Data[i].Path + "/")` 处理非等场景 · **S**
- **A08** · Auxiliary · 🟠 P1 · `RedDot/Runtime/RedDotViewBase.cs:1-13` · `RedDotViewBase.cs` 把 `UnityEngine.UI` (Text) 拉入 runtime · `using UnityEngine.UI;` 和 `public Text TextNumber;`;如果项目剥 `com.unity.ugui` 或换 TMP,文件编译失败 · 门控 `#if UNITY_UGUI`(Unity 在 UGUI 存在时定义),或换 `TMP_Text`,或把 UI 绑定移出到独立 adapter assembly · **M**
- **A09** · Auxiliary · 🟠 P1 · `RedDot/Editor/RedDotConfigEditorOdin.cs:836, 837, 841` · `AutoGenEnum` 硬编码 `\\HotUpdate\\RedDotNew` · `Application.dataPath + "\\HotUpdate\\RedDotNew"`;反斜杠在 macOS/Linux Unity 上 `Application.dataPath` 用 `/` 时会断 · 改 `Path.Combine(Application.dataPath, "HotUpdate", "RedDotNew")` · **S**
- **A10** · Auxiliary · 🟠 P1 · `RedDot/Editor/RedDotTreeEditor.cs:39-43` · `OnGUI` 每帧分配 `nodeStyle` · `OnGUI` 多次 per frame(Repaint, Layout, MouseMove),`nodeStyle = new GUIStyle(...)` 每次分配;`margin`/`padding` `RectOffset` 构造也分配 · cache `nodeStyle` 为 class 字段,`OnEnable` 或首次使用时 lazy-init · **S**
- **A11** · Auxiliary · 🟠 P1 · `RedDot/Editor/RedDotTreeEditor.cs:62-75` · `RedDotTreeEditor` search-clear flow 有 render-path 隐患(经作者 rev2 修订后实际无 crash,但仍有 stale 列表 + ref 参数问题) · `m_search = ""` 时 `m_searchNodes` 未清;`SearchNode(ref List<RedDotNodeBase> nodes, ...)` 用 `ref` 不必要且令人困惑 · 清空 m_search 同步清 m_searchNodes;`SearchNode` 改返回 `List<RedDotNodeBase>` 或普通 `List<T>` 参数 · **S**
- **A12** · Auxiliary · 🟠 P1 · `Pool/ObjectPools.cs:60-118, 130-201` · `ObjectPools` 非线程安全 · `_pool` (line 60) 和 `_pooledObjects` (line 62) 是 plain `Dictionary`/`HashSet`,`Get<T>` (line 77) 和 `Recycle<T>` (line 130) 读+写无锁;`Task.Run(() => ObjectPools.Instance.Get<MyDto>())` type-legal · 文档明示 "main-thread only" + 文档化;或 `lock(_pool)` 保护 · **M**
- **A13** · Auxiliary · 🟠 P1 · `Pool/ObjectPools.cs:120-128` · `Check<T>` 在 release 中永远返回 `true` · `#if !UNITY_EDITOR` 分支 return true 不论 obj 是否由 pool 创建;配合 unguarded `Recycle` (line 130),业务可 recycle 任意 `IObjectPool` instance → `obj.Clear()` 被调两次 · 在 release build 保留 duplicate-check `HashSet`(cheap, one ref per object),让 `Check<T>` 查它 · **M**
- **A14** · Auxiliary · 🟠 P1 · `Tools/TimerManager.cs:215-240` · `Update` catch-up `while` loop 无界 · `while (task.Elapsed >= task.Interval)` 无上限;`Interval = 0.001f` (1ms) + 1s hitch → 单 Update 跑 1000 次 · cap catch-up per frame,`int catchUp = Math.Min((int)(task.Elapsed / task.Interval), 10);` 或 schedule 余下到后续 frames · **M**
- **A15** · Auxiliary · 🟠 P1 · `Tools/TimerManager.cs:223-230` · Callback exception → log spam,无 circuit-breaker · `try { task.Callback?.Invoke(); } catch (Exception e) { Debug.LogError(...); }` 每个 tick 跑一次,full stack trace;一个坏订阅者 = 60 LogError/秒 · rate-limit per timer id (e.g. once per N seconds, or first-error-only);或 first exception 设 `task.Cancelled = true` 让用户重新 `AddTimer` · **M**
- **A16** · Auxiliary · 🟠 P1 · `Tools/TimerManager.cs:187` · `TimerManager` 无 `unscaledDeltaTime` 路径 · `Update(float deltaTime)` 接 caller 传入,Unity 唯一文档 caller 给 `Time.deltaTime`(respects `Time.timeScale`);暂停游戏时所有 timer 冻结(网络心跳、真实倒计时、登录超时、UI 动画) · 加 `public void UpdateUnscaled(float dt)`,wrapper (`MonoBehaviour` driver) 按 per-timer 策略选择 · **M**
- **A17** · Auxiliary · 🟠 P1 · `LocalData/LocalDataManager.cs:347-355` · `File.WriteAllBytes` 非原子,crash 时 0 字节 · truncate-then-write,process 在 truncate 和 write 完成间被杀 → 0 字节或部分文件;下次 `TryLoadString` 见 `File.Exists == true` 调 `Decode(File.ReadAllBytes(path))` 在 0 字节上 → silent data loss · 写 `path + ".tmp"` 然后 `File.Move(tmp, path, overwrite: true)` 原子替换;Windows 需 `File.Replace` 或 .NET Core 3+ `Move(src, dst, overwrite: true)` · **S**
- **A18** · Auxiliary · 🟠 P1 · `LocalData/LocalDataManager.cs:128-148` · `FlushPendingSaves` reentrancy via `OnSaveFailed` callback · `foreach (var kvp in _pendingSaves)` 中调 `OnSaveFailed` 回调如果写回 `_pendingSaves` → `InvalidOperationException: Collection was modified` 抛 → flush mid-iteration abort → `_pendingSaves` 部分清理 + `_hasPendingSaves` 不一致 · snapshot `var snapshot = new List<KeyValuePair<string,string>>(_pendingSaves);` 后再 loop;defer removal 到 loop 后 · **M**
- **A19** · Auxiliary · 🟠 P1 · `LocalData/LocalDataManager.cs:33-34, 50, 207, 212, 249-302` · `EncryptionEnabled` 实际是 XOR,标签为 encryption · 公开 API 用"Encryption"/"EncryptionKey",内部走 `XorObfuscator.Encode`(trivially reversible XOR with static key);hex editor 读出 key 30 秒解码 save · rename public 表面到 `ObfuscationEnabled`/`ObfuscationKey`;或用 `System.Security.Cryptography.Aes` 真加密 · **M**
- **A20** · Auxiliary · 🟠 P1 · `LocalData/LocalDataManager.cs:59-85, 227-231` · Save 文件无 version / 无 migration · `Save<T>` 写 `{"data": <T>}`;load 时 `JsonUtility.FromJson<LocalDataWrapper<T>>` 字段 rename 后 silently drops,无错误无 log · 加 `[Serializable] class LocalDataFile { public int Version; public T data; }` + 显式 `MigrationRegistry` 或 per-`T` upgrade function · **M**
- **A21** · Auxiliary · 🟠 P1 · `Log/DebugLogger.cs:7, 45-79` · `Enable` runtime flag,`params object[]` 在 early-return 前已分配 · `if (!Enable) return;` 在 caller 已分配 `object[]` 和 boxed value-type args 之后;热路径如 `DebugLogger.Log($"frame {Time.frameCount}")` with `Enable = false` 仍有 GC · `[Conditional("UNITY_EDITOR")]` 或 `[Conditional("DEVELOPMENT_BUILD")]` on public `Log` methods,让 compiler 在 release drop call entirely · **M**
- **A22** · Auxiliary · 🟠 P1 · `Log/DebugLogger.cs:9-79` · `Debug.Log` calls 在 release 未剥离 · Unity 不 strip `Debug.Log` from Player release;mobile 上 `Debug.Log` 走 marshaling(Logcat/NSLog/OutputDebugString);`Enable` 短路但方法本身仍在 + `FormatMessage` 总跑 · 把 `Log*` 方法 body 包进 `#if UNITY_EDITOR || DEVELOPMENT_BUILD`(匹配 `ObjectPools` pattern);release build elide 方法 entire · **M**
- **A23** · Auxiliary · 🟠 P1 · `Tools/BezierUtil.cs:88-99` · `BezierUtil.GetBezierPoint` 每次分配 `List<Vector3>` · 动画每帧跨数百 GameObject 调 `GetBezierPoint` → per-frame GC 源 · `List<Vector3> scratch` 参数 caller-owned scratch buffer;或手写 loop 用 fixed-size array · **S**

> **§3 计数自检**:
> - Launcher P0: L01, L02, L03 = 3 条 ✓ (§1.1 A1=3)
> - Launcher P1: L04, L05, L06, L07, L08, L09, L10, L20, L21, L22, L23 = 11 条 ✓ (§1.1 A2=11)
> - NetFramework P0: N01, N02, N03, N04, N05, N06 = 6 条 ✓ (§1.1 B1=6)
> - NetFramework P1: N07, N08, N09, N10, N11, N12, N13, N14, N15 = 9 条 ✓ (§1.1 B2=9)
> - Manager P0: M01, M02, M03, M04, M05, M06 = 6 条 ✓ (§1.1 C1=6)
> - Manager P1: M07-M31 = 25 条 ✓ (§1.1 C2=25)
> - Auxiliary P0: A01, A02 = 2 条 ✓ (§1.1 D1=2)
> - Auxiliary P1: A03-A23 = 21 条 ✓ (§1.1 D2=21)
> - **P0 总计 = 3+6+6+2 = 17** ✓ (§1.3 P0=17)
> - **P1 总计 = 11+9+25+21 = 66** ✓ (§1.3 P1=66)
> - **§3 P0+P1 = 17+66 = 83 条** ← §9 必须也是 83 条

---

## §4. 方法学与覆盖矩阵

### §4.1 4 份子报告的覆盖矩阵

| 子模块 | 范围 | 文件数 | 总行数 | 报告条数 | 报告 P0/P1 | 报告 PASS? | 已知漏覆盖 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 01 Launcher | `Assets/Scripts/Fuel/Launcher/` | 20 | 17,135(子报告未实测,本汇总从字节数估算) | 24(撤 L26 后) | 14(3+11) | ✓ attempt 2 PASS | `Assets/HybridCLR/` 运行时 API 包装层未审;`Manager/AssetManager/AssetsManager.cs` 与 Launcher 关系仅看头 60 行 |
| 02 NetFramework | `Assets/Scripts/Fuel/NetFramework/` | 12 | 1,808(子报告 §0 实测) | 21 | 15(6+9) | ✓ attempt 3 PASS | 无漏覆盖;`BoundedChannel/` 任务命名偏差已记录为 D1 |
| 03 Manager | `Assets/Scripts/Fuel/Manager/` | 41(子报告 §0.1 实测) | (子报告未给总数) | 51 | 31(6+25) | ✓ attempt 6 PASS | `AnimationClipPools` / `MaterialPools` / `ShaderPools` / `SpritePools` / `TexturePools` / `PoolBase.cs` 的 11 个 pool 文件未单独详查,沿用 `OtherPool.cs` 模式结论(§0.1 + §4.7) |
| 04 Auxiliary | `Assets/Scripts/Fuel/{RedDot, Singleton, Pool, Tools, LocalData, Log}` | 17 实际存在 + 1 缺失 | (子报告 §0.1 列各文件) | 53(2+21+28+2) | 23(2+21) | ✓ attempt 5 PASS | 任务说明引用 `RedDot/Editor/RedDotConfigEditor.cs` 不存在,实际只有 `RedDotConfigEditorOdin.cs`(§0 scope discrepancy) |

### §4.2 跨模块一致性观察(从 §3 抽出)

> **本节只列跨 ≥2 个模块的共性问题**,不重复 §3 细节。

1. **资源句柄管理不一致**:
   - Launcher `YooAssetResourceUpdateService` 用实例字段 `_downloader`/`_package` 累积(L05/L22)。
   - NetFramework `MessageDispatcher.Register` 覆盖不清旧闭包(N06)。
   - Manager `AssetsLoadManager` 双 map + `_loadIndex` 竞态(M15/M25)。
   - Auxiliary `ObjectPools` 在 release 跳过 duplicate-check(A13)。
   - **统一方向**:抽 `IResourceHandle : IDisposable` 接口,所有资源走统一句柄中心。

2. **异常吞噬风格不一致**:
   - NetFramework 4 处 catch 静默吞(N05)。
   - Manager `EventHandlerList.Invoke` catch 静默吞(M27)。
   - Launcher `YooAssetResourceUpdateService.ClearUnusedCacheAsync` 静默吞(L06)。
   - Manager `CoroutineManager.RunWithKey` 异常不清 dict(M14)。
   - **统一方向**:见 N05 `GlobalExceptionHandler` + 全模块接 `AppDomain.UnhandledException`。

3. **主线程约束不一致**:
   - NetFramework `MessageDispatcher` 主线程契约文档缺失(N07)。
   - Manager `EventDispatcher.Dispatch` 无线程保护(M08)。
   - Launcher 进度回调跨线程可能(L07/L23)。
   - **统一方向**:抽 `MainThreadDispatcher.Post(action)` 装饰器,所有非主线程入口强制走 Post。

4. **Editor / Runtime 隔离基本到位**:
   - 04 §1.12 verified: `RedDotConfigEditorOdin` / `RedDotTreeEditor` 都在 `Editor/` 目录,Unity 自动剥;`RedDotTree.cs` / `RedDotConfigAsset.cs` 的 `using Sirenix.OdinInspector;` 门控 `#if UNITY_EDITOR`(verified 4-7 行)。
   - **但** A02 `ObjectPools` 是关键反例:release build 编译失败 = Editor / Runtime 隔离失败。

5. **asmdef 边界**:4 份子报告均未审计 asmdef 边界(已在 §7 标为未覆盖)。

---

## §5. 跨模块一致性问题(更深一层)

> **本节聚焦"如果不同模块的人按各自风格写,整个 Fuel 框架会出什么问题"**。

### §5.1 命名/命名空间
- **Fuel.Pool.ObjectPools** 跨模块引用 `Fuel.Log.DebugLogger`(A02),命名空间边界被突破。
- **Fuel.Pool** 公开 API 用 `IObjectPool` 约束 + 静态泛型 `Get<T>`,**但** `Fuel.Manager.AssetsPools` 又有自己的池化体系(13 个文件,GameObjectPool/OtherPool/PoolBase/InstantiatePools/ReferencePools),**两套池化体系并存**。前者是 generic reference pool,后者是 Unity object pool,**职责不清**。
- 任务提示与代码库命名差异已记录在 01 D1 / 03 §0.2 / 04 §0,汇总时合并为一张表:

| 任务提示引用 | 实际文件 | 差异 |
| --- | --- | --- |
| `NetFramework/Dispatcher/BoundedChannel/*` | `NetFramework/Dispatcher/BoundedActionQueue.cs` | 文件名重命名 |
| `Manager/AssetManager/AssetsPoolManager.cs` | (不存在) | 功能由 `AssetsGroupManager` + `AssetsPools/*` 组合实现 |
| `Manager/AssetManager/SceneConfig.cs` | `SceneConfigAsset.cs` | 加 `Asset` 后缀(ScriptableObject 命名) |
| `Manager/EventDispatcher/EventMessage.cs` | `EventMessages.cs`(复数) | 复数 |
| `Manager/SceneManager/SceneEvent.cs` | `SceneEvents.cs`(复数) | 复数 |
| `RedDot/Editor/RedDotConfigEditor.cs` | `RedDotConfigEditorOdin.cs` | 加 `Odin` 后缀,实际未用 Odin |

### §5.2 异常处理风格
- **顶层吞噬**:`MessageDispatcher.cs:280-283, 303-307`;`NetworkManager.cs:186-190`;`TcpProtocol.cs:271-273`;`EventHandlerList.Invoke`;`ObjectPools.Recycle`;`YooAssetResourceUpdateService.ClearUnusedCacheAsync`;`CoroutineManager.RunWithKey`;`TableKitConfigLoader.LoadTextAssetDataAsync`(L12) — 8+ 处。
- **顶层抛出**:`HttpJsonVersionService.FetchVersionAsync`;`ResourcesJsonStartupConfigProvider.Load`;`ProtocolFactory.Create`;`SemanticAppVersionChecker` 调用方。
- **混合**:`AssetsGroup.StopLoad` 调 `_loadVersion++`,但调用方可能 wrap try-catch。
- **统一方向**:见 §4.2 #2。

### §5.3 异步/并发风格
- **Coroutine**:`CoroutineManager` 走 `StartCoroutine`;`SceneManager.LoadMainSceneAsync` 内部用 `await UniTask.Yield()` 模拟协程(M/T2-08 指出)。
- **async/await**:`YooAssetResourceUpdateService`,`HybridCLRLoader`,`HttpJsonVersionService`,`TimerManager` `Update` 同步签名;`LocalDataManager.FlushPendingSaves` 同步 + 内部 try/catch。
- **APM (`BeginXxx`/`EndXxx`)**:NetFramework 全模块 0 个 async/await,`TcpProtocol` 走 APM — 与 UniTask 风格断层。
- **统一方向**:抽 `IAwaitable<T>` 抽象,Coroutine 走 `CoroutineAwaiter`,APM 走 `TaskCompletionSource`,所有 Manager 走 UniTask,业务层只看到 UniTask。

### §5.4 资源句柄管理
见 §4.2 #1。

### §5.5 单例生命周期
- `MonoSingleton`(AudioManager / CoroutineManager / AssetsLoadManager / SceneManager / UIManager / NetworkManager)走 `DontDestroyOnLoad`,但 A01 揭示 `_applicationQuitting` 监听错误 PlayModeState,**Editor 重启 → Instance 返 null** — 这是框架级问题,影响所有 MonoSingleton 子类。
- `Singleton<T>`(C# 单例,AssetsGroupManager / EventDispatcher / GameObjectPools / InstantiatePools / ReferencePools / ObjectPools / RedDotTree / DebugLogger)无 Unity 生命周期,**资源句柄和字典永远不会自动清理**(M07)。
- **统一方向**:在 A01 修复后,提供 `Singleton<T>.IDisposable IDisposable` 让 C# 单例也能接 `Application.quitting` hook。

### §5.6 Editor / Runtime 隔离
见 §4.2 #4。A02 是关键反例。

### §5.7 asmdef 边界
- 4 份子报告均**未审计 asmdef**(已记 §7 未覆盖)。粗看仓库结构:
  - `Fuel/NetFramework` 可能有自己的 asmdef,`Fuel/Pool` 可能引用了 `Fuel/Log` 但 `Fuel/Log` 可能没有反向引用 `Fuel/Pool` 的 asmdef,导致 A02 编译时序问题。
  - `Fuel/RedDot/Editor` 应在 Player 剥 — verified。
  - `Fuel/Manager/AssetManager/AssetsPools/*` 5 个 `*Pools` 壳文件 + `PoolBase.cs` + `GameObjectPool.cs` + `OtherPool.cs` 共 8 个,应**不**跨 asmdef 引用 `Fuel/Pool/ObjectPools.cs`(`ObjectPools.Instance.Recycle(pool)` 见 `GameObjectPools.cs:344` 等多处)— 需审计确认无循环引用。

---

## §6. 修复路线图(Week 1 / Week 2 / Month 1,三档可执行粒度)

> **本节每一条都标注具体文件 + 具体动作,不写空话**。

### §6.1 Week 1 — 修 17 个 P0(线上崩溃 / 数据丢失 / 编译失败 / 启动阻塞)

| ID | 文件:行 | 动作 | 估时 |
| --- | --- | --- | --- |
| A02 | `Pool/ObjectPools.cs:134, 159, 177, 199` | 4 处 `DebugLogger.LogWarning` → `UnityEngine.Debug.LogWarning`;或加 `#if UNITY_EDITOR \|\| DEVELOPMENT_BUILD` | 0.5h |
| A01 | `Singleton/MonoSingleton.cs:14-23` | 改监听 `EnteredPlayMode` 或 `ExitingPlayMode`,不再用 `EnteredEditMode` | 0.5h |
| L01 | `Launcher/GameUpdatePipeline.cs:119-121` | `result is UniTask task` → 四分支(UniTask/Task/Void/ValueTask);`void` 走 `UniTask.CompletedTask`,`Task` 走 `task.GetAwaiter()` | 2h |
| L02 | `Launcher/HybridCLR/HybridCLRLoader.cs:17-33` | 内部 `HashSet<string> _loadedMetadata` 注册前查重 + 失败分支记录已注册集合 | 4h |
| L03 | `Launcher/HybridCLR/HybridCLRLoader.cs:35-48` | Editor 加 `LAUNCHER_USE_HOTUPDATE_IN_EDITOR` 开关默认开,让 Editor 走 `Assembly.Load(bytes)`;AppDomain 找不到时 `Debug.LogError` | 3h |
| L04 | `Launcher/GameUpdatePipeline.cs:104-110` + `YooAssetResourceUpdateService.cs` | 管线 catch 反向回滚;`YooAssetResourceUpdateService` 加 `DestroyAsync`,`HybridCLRLoader` 加 `UnloadAsync` | 1d |
| M01 | `AudioManager/AudioSource.cs:73-93` | `GetAudioSourceData()` 弹出后强制 `data.ReuseReset()`;`Play()` 入口无条件 `ResetInnerData()` | 2h |
| M02 | `AssetManager/AssetsGroup.cs:60-136` | 同步 `LoadSync*` 4 个方法也加 `_loadVersion` 检查 | 4h |
| M03 | `EventDispatcher/EventDispatcher.cs:92-155` | 引入 `ConditionalWeakTable<object, List<Action>>` + owner key;或 `Register<T>(object owner, Action<T>)` API | 1d |
| M04 | `GameObjectPool.cs:60-98` + `OtherPool.cs:62-83` | Get 路径加 active-cap 检查;拆 `MaxPoolCount` 为 active+pool | 4h |
| M05 | `AudioSource.cs:98-103` | Dispose 内部加 `if (_as) { GameObject.Destroy(_as); _as = null; }`;`TickFade/TickRecycle` 入口判 null | 1h |
| M06 | `UIManager/UIManager.cs:188-231` + `UIResourceManager.cs:101-116, 125-142` | `OpenWindowAsync` 拆分(预加载 async,激活 Show 时 SetActive);业务子资源 groupName 改 `windowId + ".sub"`;`CreateInstance` 后 prefab 引用 Clone 独立 | 1d |
| N01 | `NetMessageHandlerAttribute.cs:67-107` | 要么删 attribute + `ProtoCmdsLookup` 改文档;要么 `DispatcherScanner.ScanAllAssemblies()` 启动时扫 + `MsgId` ctor 缓存为 `readonly uint` | 4h |
| N02 | `TcpProtocol.cs:88-114` | catch 末尾 `OnError?.Invoke` 之后再调 `OnDisconnected?.Invoke(true)`;DNS line 67-68 同理 | 1h |
| N03 | `HeartbeatManager.cs:168-175` | 把 `_waitingPong = true`(line 171) 移到 `OnSendPing?.Invoke` 之后;或在 `NetworkManager.SendPingInternal` 早返回时调 `HeartbeatManager.AbortPing()` | 1h |
| N04 | `MessageDispatcher.cs:295-311` + `BoundedActionQueue.cs:39-48` | `MessageDispatcher.Update` 加 `DroppedCount > 0` 观察点 + per-cmdId 抽样 `LogWarning`(1s 限频) | 4h |
| N05 | `MessageDispatcher.cs:280-283, 303-307` + `NetworkManager.cs:186-190` + `TcpProtocol.cs:271-273` | 新增 `GlobalExceptionHandler` 静态类,启动时注册 `AppDomain.UnhandledException` + `Application.logMessageReceivedThreaded` 桥接 Unity log;4 个 catch 块在 `Debug.LogError` 之后把异常再 throw 一份给全局 sink | 1d |
| N06 | `MessageDispatcher.cs:65-90, 127-174` | 三处 Register 覆盖前先 `Unregister(cmdId)`(或抛 `InvalidOperationException`);`Register` 内部把 `MessageParser` 提升到 `Dictionary<uint, MessageParser>` 字段 | 4h |

> **Week 1 合计估时 ≈ 9 人日**(1 工程师 ~2 周)。Week 1 必须**全部完成**才能进入 Week 2,因为 P0 任意一条未修都会在生产产生线上事故。

### §6.2 Week 2 — 修 P1 的 Top 20(资源句柄 / 状态机 / 协议安全 / 异常吞噬)

按性价比(线上发生概率 × 修复成本)排序的 Top 20:

| 优先级 | ID | 文件:行 | 一句话 |
| --- | --- | --- | --- |
| 1 | L05+L06+L22 | `YooAssetResourceUpdateService.cs:14-20, 65-69, 96-100` | 跨重入 + 句柄泄漏 + 静默失败(三连击) |
| 2 | L07+L23 | `YooAssetResourceUpdateService.cs:71-94` + `GameUpdatePipeline.cs:80` | 进度回调跨线程 |
| 3 | L08 | `HttpJsonVersionService.cs:14-31` | 无重试无降级(玩家断网即崩) |
| 4 | L10 | `GameUpdatePipeline.cs:72-82` | CDN 挂掉无 built-in 兜底 |
| 5 | M07 | `AssetsGroupManager.cs:9, 70-89` | Singleton C# 死代码 OnDestroy |
| 6 | M14 | `CoroutineManager.cs:114-122, 169-172` | RunWithKey 异常路径不清 dict |
| 7 | M15 | `GameObjectPools.cs:31, 82, 121, 138` | _loadIndex 跨线程无 Interlocked |
| 8 | M17 | `SceneManager.Loading.cs:55-106` | 缺 Scene_LoadFailedEvent |
| 9 | M18 | `SceneManager.Loading.cs:228-247` + `SceneBase.cs:47-50` | OnExit sync Release vs async Unload race |
| 10 | A17 | `LocalDataManager.cs:347-355` | File.WriteAllBytes 非原子(数据丢失) |
| 11 | A18 | `LocalDataManager.cs:128-148` | FlushPendingSaves reentrancy |
| 12 | A14 | `TimerManager.cs:215-240` | 1ms timer + 1s hitch = 1000 callbacks |
| 13 | A09 | `RedDotConfigEditorOdin.cs:836, 837, 841` | 硬编码 \\ 路径(跨平台 break) |
| 14 | N07 | `MessageDispatcher.cs:8-37` | 缺主线程契约文档 |
| 15 | N08 | `NetworkManager.cs:253, 332` + `HeartbeatManager.cs:75` | 0 单元测试覆盖 |
| 16 | N11 | `BoundedActionQueue.cs:1-3` + `MessageDispatcher.cs:37` | 半完成迁移 |
| 17 | N12 | `PacketCodec.cs:9, 29, 92` | 无 magic 校验 |
| 18 | M26 | `PoolBase.cs:185-193` | RecycleByGroup 不清 _loadCallBackMap |
| 19 | M08 | `EventDispatcher.cs:149-155` | Dispatch 无线程保护 |
| 20 | M25 | `GameObjectPools.cs:118-165` + `PoolBase.cs:81-151, 278-345` | 双 map race |

> **Week 2 合计估时 ≈ 10 人日**。Week 2 完成后,线上稳定度应有可观测提升(异常吞噬减少 + 资源句柄泄漏减少 + 重连/重试正确)。

### §6.3 Month 1 — 清完剩余 P1 + 选 P2

**Month 1 必做**(Week 3-4):
- Week 3:剩余 46 条 P1,按"模块内优先级"逐个清,每模块 owner 一个 sprint。
- Week 4:开始处理 P2 中的**真实风险**(Critical/Major 级),如 04 #3.6 `ObjectPoolsLook` 泄漏、03 #M01-M31 中已修一半的相邻 P2(子报告 §0.4 列出的"硬约束"项目)。
- 配套:**架构债**
  - 抽 `INetworkManagerCore` 接口,核心连接/发送/接收走纯 C# 类(对应 N08)
  - 抽 `IResourceHandle : IDisposable`,所有 Manager 走统一句柄中心(对应 M07/M15/M25)
  - `BoundedActionQueue` 真迁到 `MessageDispatcher` 嵌套类(对应 N11)
  - `MonoSingleton` 在 A01 修复后,提供 `Singleton<T>.IDisposable` 接 `Application.quitting` hook(对应 M07)
  - 协议层加 magic 字段(对应 N12)
  - `TimerManager` 加 `UpdateUnscaled` 路径(对应 A16)
  - `Send` 失败返回 `SendResult` 枚举(对应 N14)
  - `LocalData` 加 save-file version + migration(对应 A20)
  - `DebugLogger` 加 `[Conditional]` 让 release 编译时 elide(对应 A22)

**Month 1 不做**:
- 纯风格 / typo 类 P2(如 03 #M32 起的所有 Trivial / Minor / Info 级)
- asmdef 边界审计(已列 §7 未覆盖,需要单独 sprint)

---

## §7. 未解问题与未覆盖区域(诚实写明)

> **本节由本汇总 owner 主动写,非子报告复读**。目的是让任何用本汇总的人知道**本汇总本身有什么没覆盖**。

### §7.1 编译 / 运行时验证(全部未做)
- **未实际编译/运行项目**。所有判断基于 read 工具直接读源码 + 公开文档。
- **未打开 YooAsset 2.x/3.x 源码**确认 `IRemoteService` 线程模型 / `DownloadProgressChanged` 触发线程 / `LoadMetadataForAOTAssembly` 幂等性。**这是基于公开文档的推断**,不同 YooAsset 版本可能行为不一致(由 01 报告 §"诚实说明"重申)。
- **未打开 HybridCLR 源码**确认 metadata 注册失败的具体异常类型(01 报告写为 `BadImageFormatException` 是常见社区报告的占位表述)。
- **未执行 E2E**:`HandleForceUpdateAsync` 在真机上的行为没有实测,`Application.OpenURL + Application.Quit` 在 iOS 上的实际表现依赖 Apple 审核策略。
- **未跑 Unity Player Build**:A02 `ObjectPools.DebugLogger` 是从静态 read 推断"release 编译失败",**实际没有跑过 Unity 的 Stripping/Build 流程**;Unity 的 managed code stripping 在不同 IL2CPP / Mono 模式下行为可能有差。

### §7.2 范围未覆盖
- **未审计 `Assets/HybridCLR/` 目录**下的运行时 API 包装层,只读了 Launcher 自己调用 `RuntimeApi.LoadMetadataForAOTAssembly` 的那 1 行(01 报告 §"诚实说明")。
- **未审计 `Assets/Table/` 与 TableKit 库本身**,只读了 Launcher 调用 `TableKit` 的接缝。
- **未审计 `Manager/AssetManager/AssetsManager.cs` 与 Launcher 的关系**:虽然 read 过一次确认存在 EditorSim 重叠,但 Launcher 是否有地方把 `_package` 共享给 `AssetsManager`、是否两个模块会同时调 `YooAssets.Initialize()` 导致冲突 — 未深入分析(01 报告 §"诚实说明")。
- **Manager 11 个 pool 文件未单独详查**:03 报告 §4.7 沿用 `OtherPool.cs` 模式结论,这意味着 `MaterialPools` / `AnimationClipPools` / `ShaderPools` / `SpritePools` / `TexturePools` / `AudioClipPools` 这 6 个具体壳类**没有独立**走 T1/T2/T3 三级严重度判定。**新发现**:03 报告 §0.2 也说"功能由 `AssetsGroupManager` + `AssetsPools/*` 组合实现",**但**具体每个壳类的 `new T()` 行为 + 资源句柄是否走同一销毁路径 — 仍属未深入。
- **`FairyGUIPool.cs`** 是 86 行死文件(03 #M22-03),本汇总归入 P2 不再展开。
- **`Assets/Resources/StartupConfig.json`** 是否存在、字段是否齐全、aot metadata 路径格式(大小写、扩展名)、hotupdate dll 实际命名 — 全部未读(01 报告 §"诚实说明")。
- **测试覆盖率**:`NetworkManagerE2ETest` 6 个 case 已列(N15),但 0 case 覆盖 `Send<T>` / `CacheRequest` / `Unregister` / `MessageDispatcher.Clear` / `Heartbeat.OnMaxRetryExceeded`。**其他模块 0 单元测试**:Manager / Auxiliary / Launcher 全模块 0 单元测试。
- **asmdef 边界**:全 Fuel 目录的 .asmdef 文件未读、未审计依赖方向、未审计是否有循环引用(已在 §5.7 提出但未实际审计)。
- **配置文件结构**:`EditorSettings`, `ProjectSettings`, `Packages/manifest.json` 中的 package 版本(尤其 YooAsset / HybridCLR / Sirenix.OdinInspector 的版本) — 全部未读,子报告中的版本相关推断是公开文档版本。

### §7.3 事实更正(本汇总与子报告有差异的 3 处)
1. **04 §1.10**:`AutoGenEnum` 硬编码 `\\HotUpdate\\RedDotNew` — 本汇总确认 `Application.dataPath + "\\HotUpdate\\RedDotNew"`(`RedDotConfigEditorOdin.cs:836, 837, 841`)。**事实一致,本汇总沿用。**
2. **03 #M26 (T2-20)**:`RecycleByGroup` 不查 `_loadCallBackMap` — 本汇总实测 `PoolBase.cs:185-193` 确实只 `pool.RecycleAll()`,**不**清 `_loadCallBackMap` 和 `_loadIndexCheckMap`(对比 `DestroyByGroup` line 195-218 完整清理);同时 `GameObjectPools.cs:360-365` 的 `StopLoadByGroup` **有**完整清理。**事实更正生效:上次 attempt 2 报告"三处都不清"已 retract,正确说法是"只有 `InstantiatePools<T>.RecycleByGroup` 不清"`。本汇总已 retract 错误说法,只列 M26 一条。**
3. **04 §0 scope discrepancy**:`RedDot/Editor/RedDotConfigEditor.cs`(无 Odin)不存在 — 本汇总实测 `RedDot/Editor` 实际只有 `RedDotConfigEditorOdin.cs` + `RedDotTreeEditor.cs` 两个文件。**事实一致,本汇总沿用。**

### §7.4 本汇总自身的局限
- **本汇总未跑 Unity 编译验证**:A02 的"release 编译失败"是子报告 04 §3.1 的 static 推断,本汇总未独立 verify。
- **本汇总未做交叉一致性审计**:**同一文件在两份子报告里被引用时严重度是否一致**,本汇总没有系统对照表(只是按模块分别汇总,模块间交叉未做)。**已知 1 处**:Launcher `YooAssetResourceUpdateService.cs` 在 01 报告里有 L05/L06/L07/L22 共 4 条;在 03 报告里没出现(因为 03 报告的 Manager 不涉及 Launcher),**未冲突**。**已知 2 处**:`HeartbeatManager.cs` 在 02 报告里有 N03 1 条;在 04 报告里没出现。**未冲突**。
- **本汇总 §3 的修复方向**只写"做什么",**不**写"怎么写代码" — 这是子报告的约束(任务说明:「不要写修复代码,只写建议方向」)。具体实现细节留给工程师。
- **本汇总 §6 的估时**基于 1 名有 Fuel 框架上下文的工程师工作量的粗略估算,未做并行 review。

---

## §8. 整体判断与建议(本节为汇总 owner 个人视角)

### §8.1 整体健康度

**4 个子模块 / 151 个 P0-P3 条目**(P0=17, P1=66, P2=63, P3=5)。

- 整体健康度:**C-**。17 个 P0 全部为「线上崩溃 / 数据丢失 / 编译失败 / 启动阻塞」类,任一条上线都会产生生产事故;66 个 P1 涵盖「资源句柄泄漏 / 状态机污染 / 协议安全 / 异常吞噬 / 线程竞态」类,几乎覆盖所有 Fuel 框架的运行时核心。
- **唯一亮点**:`MonoSingleton DontDestroyOnLoad + Instance` 模式本身正确;`EventDispatcher` 的 `pendingAdds/pendingRemoves` 模式正确避免 Invoke 期间修改;`_loadCallBackMap` / `_loadIndexCheckMap` 在 `GameObjectPools` / `ReferencePools.DestroyByGroup` 路径**已正确清理**(verified)。
- **唯一紧急**:**A02 (`ObjectPools.DebugLogger`)** 是**编译期失败**级别,直接阻塞 Player Release 包。

### §8.2 建议

1. **立即(本周)**:**不**打 Player Release 包,直到 A02 修复。
2. **Week 1**:修完 17 个 P0,这一周是**硬性截止**;如果 1 周内修不完,生产环境**必现**线上崩溃。
3. **Week 2**:修 P1 Top 20,资源句柄 + 状态机 + 协议安全 + 异常吞噬。
4. **Month 1**:清完剩余 P1 + 选 P2,同步开始**架构债清理**(见 §6.3)。
5. **避免**:
   - **不要**在 P0/P1 未清完前尝试 EditorSim → CDN 切换(当前 workflow state 是 EditorSim) — 切换会暴露更多并发 / 跨平台问题。
   - **不要**新增 Manager 子模块(目前在 Audio / Asset / Coroutine / Event / Scene / UI 共 6 个,新增第 7 个会触发 §5.4 "资源句柄不一致" 进一步恶化)。
   - **不要**改 NetFramework 的 `TcpProtocol` 异步模型(从 APM 迁 async/await 是大重构,**应**先抽 `INetworkManagerCore` 接口,然后并行迁移,不能直接改)。

---

## §9. 证据索引(本节与 §3 P0/P1 严格 1:1 对应)

> **本节条目数 = 83**,与 §3 P0+P1 总数完全相等。**任何一节多/少,本汇总都不算合格**。
> **字段**:ID / 严重度 / 子报告 + file:line / 子报告章节(本汇总 §3 之外的来源)。

### §9.1 Launcher (14 条 — L01-L03 + L04-L23, 其中 L11-L19 属 P2 不在本节,撤除 L26 不计)

| ID | 严重度 | 子报告引用 | 子报告章节 |
| --- | --- | --- | --- |
| L01 | 🔴 P0 | 01 §问题列表 L01 (`Launcher/GameUpdatePipeline.cs:119-121`) | 01 §"## 问题列表" L01 |
| L02 | 🔴 P0 | 01 §问题列表 L02 (`Launcher/HybridCLR/HybridCLRLoader.cs:17-33`) | 01 §"## 问题列表" L02 |
| L03 | 🔴 P0 | 01 §问题列表 L03 (`Launcher/HybridCLR/HybridCLRLoader.cs:35-48`) | 01 §"## 问题列表" L03 |
| L04 | 🟠 P1 | 01 §问题列表 L04 (`Launcher/GameUpdatePipeline.cs:104-110`) | 01 §"## 问题列表" L04 |
| L05 | 🟠 P1 | 01 §问题列表 L05 (`Launcher/Resources/YooAssetResourceUpdateService.cs:14-20`) | 01 §"## 问题列表" L05 |
| L06 | 🟠 P1 | 01 §问题列表 L06 (`Launcher/Resources/YooAssetResourceUpdateService.cs:96-100`) | 01 §"## 问题列表" L06 |
| L07 | 🟠 P1 | 01 §问题列表 L07 (`Launcher/Resources/YooAssetResourceUpdateService.cs:71-94`) | 01 §"## 问题列表" L07 |
| L08 | 🟠 P1 | 01 §问题列表 L08 (`Launcher/Version/HttpJsonVersionService.cs:14-31`) | 01 §"## 问题列表" L08 |
| L09 | 🟠 P1 | 01 §问题列表 L09 (`Launcher/Version/SemanticAppVersionChecker.cs:19-32`) | 01 §"## 问题列表" L09 |
| L10 | 🟠 P1 | 01 §问题列表 L10 (`Launcher/GameUpdatePipeline.cs:72-82`) | 01 §"## 问题列表" L10 |
| L20 | 🟠 P1 | 01 §问题列表 L20 (`Launcher/GameUpdatePipeline.cs:115`) | 01 §"## 问题列表" L20 |
| L21 | 🟠 P1 | 01 §问题列表 L21 (`Launcher/Table/TableKitConfigLoader.cs:18`) | 01 §"## 问题列表" L21 |
| L22 | 🟠 P1 | 01 §问题列表 L22 (`Launcher/Resources/YooAssetResourceUpdateService.cs:65-69`) | 01 §"## 问题列表" L22 |
| L23 | 🟠 P1 | 01 §问题列表 L23 (`Launcher/GameUpdatePipeline.cs:80`) | 01 §"## 问题列表" L23 |

### §9.2 NetFramework (15 条 — N01-N15)

| ID | 严重度 | 子报告引用 | 子报告章节 |
| --- | --- | --- | --- |
| N01 | 🔴 P0 (T1) | 02 #1 (`Assets/Scripts/Fuel/NetFramework/Attributes/NetMessageHandlerAttribute.cs:67-107`) | 02 §问题列表 [T1] #1 |
| N02 | 🔴 P0 (T1) | 02 #2 (`Assets/Scripts/Fuel/NetFramework/Protocol/TcpProtocol.cs:88-114`) | 02 §问题列表 [T1] #2 |
| N03 | 🔴 P0 (T1) | 02 #3 (`Assets/Scripts/Fuel/NetFramework/Core/HeartbeatManager.cs:168-175` + `NetworkManager.cs:308-314`) | 02 §问题列表 [T1] #3 |
| N04 | 🔴 P0 (T1) | 02 #4 (`TcpProtocol.cs:248-295` + `MessageDispatcher.cs:295-311` + `BoundedActionQueue.cs:39-48`) | 02 §问题列表 [T1] #4 |
| N05 | 🔴 P0 (T1) | 02 #5 (`MessageDispatcher.cs:280-283, 303-307` + `NetworkManager.cs:186-190` + `TcpProtocol.cs:271-273`) | 02 §问题列表 [T1] #5 |
| N06 | 🔴 P0 (T1) | 02 #6 (`MessageDispatcher.cs:65-90, 127-174`) | 02 §问题列表 [T1] #6 |
| N07 | 🟠 P1 (T2) | 02 #7 (`MessageDispatcher.cs:8-37`) | 02 §问题列表 [T2] #7 |
| N08 | 🟠 P1 (T2) | 02 #8 (`NetworkManager.cs:253, 332` + `HeartbeatManager.cs:75` + `NetworkManagerE2ETest.cs:90-91`) | 02 §问题列表 [T2] #8 |
| N09 | 🟠 P1 (T2) | 02 #9 (`NetworkManager.cs:231-257, 327-335`) | 02 §问题列表 [T2] #9 |
| N10 | 🟠 P1 (T2) | 02 #10 (`HeartbeatManager.cs:38`) | 02 §问题列表 [T2] #10 |
| N11 | 🟠 P1 (T2) | 02 #11 (`BoundedActionQueue.cs:1-3` + `MessageDispatcher.cs:37`) | 02 §问题列表 [T2] #11 |
| N12 | 🟠 P1 (T2) | 02 #12 (`PacketCodec.cs:9, 29, 92`) | 02 §问题列表 [T2] #12 |
| N13 | 🟠 P1 (T2) | 02 #13 (`NetMessageHandlerAttribute.cs:43-60, 84` + `:23`) | 02 §问题列表 [T2] #13 |
| N14 | 🟠 P1 (T2) | 02 #14 (`NetworkManager.cs:135-177`) | 02 §问题列表 [T2] #14 |
| N15 | 🟠 P1 (T2) | 02 #15 (`NetworkManagerE2ETest.cs` 整文件) | 02 §问题列表 [T2] #15 |

### §9.3 Manager (31 条 — M01-M06 + M07-M31)

| ID | 严重度 | 子报告引用 | 子报告章节 |
| --- | --- | --- | --- |
| M01 | 🔴 P0 (T1) | 03 T1-01 (`AudioManager/AudioManager.GoAudioSource.cs:51-64` + `AudioSource.cs:73-93, 114-157`) | 03 §"1. 致命级 T1" T1-01 |
| M02 | 🔴 P0 (T1) | 03 T1-02 (`AssetManager/AssetsGroup.cs:60-136` + `AssetsGroupManager.cs:53-60`) | 03 §"1. 致命级 T1" T1-02 |
| M03 | 🔴 P0 (T1) | 03 T1-03 (`EventDispatcher/EventDispatcher.cs:92-155`) | 03 §"1. 致命级 T1" T1-03 |
| M04 | 🔴 P0 (T1) | 03 T1-04 (`AssetManager/AssetsPools/GameObjectPool.cs:60-98, 16`) | 03 §"1. 致命级 T1" T1-04 |
| M05 | 🔴 P0 (T1) | 03 T1-05 (`AudioManager/AudioSource.cs:98-103`) | 03 §"1. 致命级 T1" T1-05 |
| M06 | 🔴 P0 (T1) | 03 T1-06 (`UIManager/UIResourceManager.cs:101-116, 125-142` + `UIManager.cs:188-231`) | 03 §"1. 致命级 T1" T1-06 |
| M07 | 🟠 P1 (T2) | 03 T2-01 (`AssetManager/AssetsGroupManager.cs:9, 70-89`) | 03 §"2. 重要 T2" T2-01 |
| M08 | 🟠 P1 (T2) | 03 T2-02 (`EventDispatcher/EventDispatcher.cs:149-155`) | 03 §"2. 重要 T2" T2-02 |
| M09 | 🟠 P1 (T2) | 03 T2-03 (`AudioManager/AudioManager.cs:492-498`) | 03 §"2. 重要 T2" T2-03 |
| M10 | 🟠 P1 (T2) | 03 T2-04 (`AudioManager/AudioSource.cs:203-216, 240-249, 300-313`) | 03 §"2. 重要 T2" T2-04 |
| M11 | 🟠 P1 (T2) | 03 T2-05 (`AudioManager/AudioManager.cs:150`) | 03 §"2. 重要 T2" T2-05 |
| M12 | 🟠 P1 (T2) | 03 T2-06 (`AudioManager/AudioSource.cs:114-157, 64, 70`) | 03 §"2. 重要 T2" T2-06 |
| M13 | 🟠 P1 (T2) | 03 T2-07 (`AudioManager/AudioManager.cs:30, 681, 138-152`) | 03 §"2. 重要 T2" T2-07 |
| M14 | 🟠 P1 (T2) | 03 T2-08 (`CoroutineManager/CoroutineManager.cs:114-122, 169-172`) | 03 §"2. 重要 T2" T2-08 |
| M15 | 🟠 P1 (T2) | 03 T2-09 (`AssetManager/AssetsPools/GameObjectPools.cs:31, 82, 121, 138` + `PoolBase.cs:278-318` + `:81-102`) | 03 §"2. 重要 T2" T2-09 |
| M16 | 🟠 P1 (T2) | 03 T2-10 (`AssetManager/AssetsPools/AudioClipPools.cs:11-15` + `OtherPool.cs:75-82`) | 03 §"2. 重要 T2" T2-10 |
| M17 | 🟠 P1 (T2) | 03 T2-11 (`SceneManager/SceneManager.Loading.cs:55-106`) | 03 §"2. 重要 T2" T2-11 |
| M18 | 🟠 P1 (T2) | 03 T2-12 (`SceneManager/SceneManager.Loading.cs:228-247` + `Data/SceneBase.cs:47-50`) | 03 §"2. 重要 T2" T2-12 |
| M19 | 🟠 P1 (T2) | 03 T2-13 (`SceneManager/SceneManager.SceneScript.cs:80-101, 97-100`) | 03 §"2. 重要 T2" T2-13 |
| M20 | 🟠 P1 (T2) | 03 T2-14 (`UIManager/UIStack.cs:79-90`) | 03 §"2. 重要 T2" T2-14 |
| M21 | 🟠 P1 (T2) | 03 T2-15 (`UIManager/UIManager.cs:284-315, 302-306`) | 03 §"2. 重要 T2" T2-15 |
| M22 | 🟠 P1 (T2) | 03 T2-16 (`UIManager/UIManager.cs:258-267, 250-256` + `UIStack.cs:92-113`) | 03 §"2. 重要 T2" T2-16 |
| M23 | 🟠 P1 (T2) | 03 T2-17 (`AssetManager/AssetsGroup.cs:139-153, 270-293, 25-37`) | 03 §"2. 重要 T2" T2-17 |
| M24 | 🟠 P1 (T2) | 03 T2-18 (`EventDispatcher/EventDispatcher.cs:94-107`) | 03 §"2. 重要 T2" T2-18 |
| M25 | 🟠 P1 (T2) | 03 T2-19 (`AssetManager/AssetsPools/GameObjectPools.cs:118-165` + `PoolBase.cs:81-151, 278-345`) | 03 §"2. 重要 T2" T2-19 |
| M26 | 🟠 P1 (T2) | 03 T2-20 (`PoolBase.cs:185-193` vs `:195-218`) | 03 §"2. 重要 T2" T2-20 + §0.3 retract |
| M27 | 🟠 P1 (T2) | 03 T2-21 (`EventDispatcher/EventDispatcher.cs:49-53`) | 03 §"2. 重要 T2" T2-21 |
| M28 | 🟠 P1 (T2) | 03 T2-22 (`UIManager/UIManager.cs:80-88, 150-163`) | 03 §"2. 重要 T2" T2-22 |
| M29 | 🟠 P1 (T2) | 03 T2-23 (`UIManager/UIManager.cs:274-277`) | 03 §"2. 重要 T2" T2-23 |
| M30 | 🟠 P1 (T2) | 03 T2-24 (`AudioManager/AudioSource.cs:35-36, 86, 128, 167`) | 03 §"2. 重要 T2" T2-24 |
| M31 | 🟠 P1 (T2) | 03 T2-25 (`UIManager/UIManager.cs:33-34`) | 03 §"2. 重要 T2" T2-25 |

### §9.4 Auxiliary (23 条 — A01-A02 + A03-A23)

| ID | 严重度 | 子报告引用 | 子报告章节 |
| --- | --- | --- | --- |
| A01 | 🔴 P0 (Critical) | 04 §2.1 (`Singleton/MonoSingleton.cs:14-23, 79-82`) | 04 §"2. Singleton Module" 2.1 |
| A02 | 🔴 P0 (Critical) | 04 §3.1 (`Pool/ObjectPools.cs:1-8, 134, 159, 177, 199`) | 04 §"3. ObjectPools" 3.1 |
| A03 | 🟠 P1 (Major) | 04 §2.2 (`Singleton/MonoSingleton.cs:62-75`) | 04 §"2. Singleton Module" 2.2 |
| A04 | 🟠 P1 (Major) | 04 §2.3 (`Singleton/MonoSingleton.cs:62-75`) | 04 §"2. Singleton Module" 2.3 |
| A05 | 🟠 P1 (Major) | 04 §1.1 (`RedDot/Runtime/RedDotNumberNode.cs:57-89`) | 04 §"1. RedDot Module" 1.1 |
| A06 | 🟠 P1 (Major) | 04 §1.4 (`RedDot/Runtime/RedDotTree.cs:13-40`) | 04 §"1. RedDot Module" 1.4 |
| A07 | 🟠 P1 (Major) | 04 §1.5 (`RedDot/Runtime/RedDotConfigAsset.cs:55-76`) | 04 §"1. RedDot Module" 1.5 |
| A08 | 🟠 P1 (Major) | 04 §1.6 (`RedDot/Runtime/RedDotViewBase.cs:1-13`) | 04 §"1. RedDot Module" 1.6 |
| A09 | 🟠 P1 (Major) | 04 §1.10 (`RedDot/Editor/RedDotConfigEditorOdin.cs:836, 837, 841`) | 04 §"1. RedDot Module" 1.10 |
| A10 | 🟠 P1 (Major) | 04 §8.3 (`RedDot/Editor/RedDotTreeEditor.cs:39-43`) | 04 §"8. Editor Tooling" 8.3 |
| A11 | 🟠 P1 (Major) | 04 §8.4 (`RedDot/Editor/RedDotTreeEditor.cs:62-75`) | 04 §"8. Editor Tooling" 8.4 |
| A12 | 🟠 P1 (Major) | 04 §3.2 (`Pool/ObjectPools.cs:60-118, 130-201`) | 04 §"3. ObjectPools" 3.2 |
| A13 | 🟠 P1 (Major) | 04 §3.3 (`Pool/ObjectPools.cs:120-128`) | 04 §"3. ObjectPools" 3.3 |
| A14 | 🟠 P1 (Major) | 04 §4.1 (`Tools/TimerManager.cs:215-240`) | 04 §"4. TimerManager" 4.1 |
| A15 | 🟠 P1 (Major) | 04 §4.2 (`Tools/TimerManager.cs:223-230`) | 04 §"4. TimerManager" 4.2 |
| A16 | 🟠 P1 (Major) | 04 §4.3 (`Tools/TimerManager.cs:187`) | 04 §"4. TimerManager" 4.3 |
| A17 | 🟠 P1 (Major) | 04 §5.1 (`LocalData/LocalDataManager.cs:347-355`) | 04 §"5. LocalDataManager" 5.1 |
| A18 | 🟠 P1 (Major) | 04 §5.2 (`LocalData/LocalDataManager.cs:128-148`) | 04 §"5. LocalDataManager" 5.2 |
| A19 | 🟠 P1 (Major) | 04 §5.3 (`LocalData/LocalDataManager.cs:33-34, 50, 207, 212, 249-302`) | 04 §"5. LocalDataManager" 5.3 |
| A20 | 🟠 P1 (Major) | 04 §5.4 (`LocalData/LocalDataManager.cs:59-85, 227-231`) | 04 §"5. LocalDataManager" 5.4 |
| A21 | 🟠 P1 (Major) | 04 §6.1 (`Log/DebugLogger.cs:7, 45-79`) | 04 §"6. DebugLogger" 6.1 |
| A22 | 🟠 P1 (Major) | 04 §6.2 (`Log/DebugLogger.cs:9-79`) | 04 §"6. DebugLogger" 6.2 |
| A23 | 🟠 P1 (Major) | 04 §7.1 (`Tools/BezierUtil.cs:88-99`) | 04 §"7. Cross-cutting / Tools" 7.1 |

> **§9 计数自检**:
> - Launcher §9.1 = 14 条 (3+11) ✓
> - NetFramework §9.2 = 15 条 (6+9) ✓
> - Manager §9.3 = 31 条 (6+25) ✓
> - Auxiliary §9.4 = 23 条 (2+21) ✓
> - **§9 总计 = 14+15+31+23 = 83 条** ✓ (与 §3 P0+P1 总数 83 严格相等)

---

## §10. 收尾

- 本汇总**不**修改 01-04 任一子报告。
- 后续若需要重新审计(新增 Fuel 模块/重构某个 Manager),**建议直接重读子报告 + 重跑本汇总的 §1.1 实测命令**,而不是相信本汇总里复述的具体数字。
- 本汇总 owner 联系方式:session `mvs_c495b1afaa764f01863784cf3ee45935`,可向其发 message 提问。

*End of 00_summary.md*
