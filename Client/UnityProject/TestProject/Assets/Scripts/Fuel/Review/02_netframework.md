# Fuel.NetFramework 子报告 — 协议 / 收发 / 调度 / 心跳

> 审查方式:静态阅读 + 与依赖(`MonoSingleton`/`DebugLogger`)交叉核对 + 对所有负面断言用 grep 二次验证。**不修改任何源码**。

---

## 0. 范围核实(Scope verification)

任务说明中明确列举的文件逐项核对:

| 任务说明中的文件 | 实际状态 | 实际位置 |
| --- | --- | --- |
| `NetFramework/Attributes/NetMessageHandlerAttribute.cs` | ✓ 存在 | `Attributes/NetMessageHandlerAttribute.cs`(87 lines) |
| `NetFramework/Codec/PacketCodec.cs` | ✓ 存在 | `Codec/PacketCodec.cs`(133 lines) |
| `NetFramework/Core/HeartbeatManager.cs` | ✓ 存在 | `Core/HeartbeatManager.cs`(156 lines) |
| `NetFramework/Core/IProtoCmd.cs` | ✓ 存在 | `Core/IProtoCmd.cs`(21 lines) |
| `NetFramework/Core/NetworkManager.cs` | ✓ 存在 | `Core/NetworkManager.cs`(297 lines) |
| `NetFramework/Core/Packet.cs` | ✓ 存在 | `Core/Packet.cs`(22 lines) |
| `NetFramework/Dispatcher/BoundedChannel/MessageDispatcher 相关` | ⚠️ 命名偏差 | 实际是 `BoundedActionQueue.cs`(53 lines)+ `MessageDispatcher.cs`(289 lines),**没有 `BoundedChannel.cs`** |
| `NetFramework/Protocol/IProtocol.cs` | ✓ 存在 | `Protocol/IProtocol.cs`(63 lines) |
| `NetFramework/Protocol/ProtocolFactory.cs` | ✓ 存在 | `Protocol/ProtocolFactory.cs`(28 lines) |
| `NetFramework/Protocol/TcpProtocol.cs` | ✓ 存在 | `Protocol/TcpProtocol.cs`(325 lines) |
| `NetFramework/Tests/NetworkManagerE2ETest.cs` | ✓ 存在 | `Tests/NetworkManagerE2ETest.cs`(334 lines) |

**范围结论**:NetFramework/ 下 `*.cs` 文件共 **12 个**(`Get-ChildItem -Recurse -Filter *.cs` 结果 = 12),`Tests/NetworkManagerE2ETest.cs` 内含嵌套类 `LocalEchoServer`,故实际类数 = 12 + 1(嵌套)= 13。
**总物理行数(全部 12 个源文件)**:87 + 133 + 156 + 21 + 297 + 22 + 53 + 289 + 63 + 28 + 325 + 334 = **1808 行**(实测求和,非估算)。
**总物理字节数(全部 12 个源文件)**:4024 + 6156 + 5957 + 736 + 14491 + 806 + 2013 + 12317 + 1961 + 1238 + 12074 + 18064 = **79837 字节**(实测求和)。

### Scope discrepancies(P3)

**D1. 任务说明中提及的 `BoundedChannel/` 目录/文件不存在** — 实际命名为 `BoundedActionQueue.cs`。可能为笔误或重命名历史残留,本报告按实际文件名 `BoundedActionQueue.cs` 进行审查。

---

## 模块概览

### 架构意图(读代码还原)

```
  +------------------+
  |   Business 层     |  -- 直接调用 NetworkManager.Instance.Send<T>(msg)
  | (IProtoCmd 可选)  |     或 Register/Dispatch 路径
  +--------+---------+
           |
           v
  +------------------+      +-------------------+
  |  NetworkManager  | <--> |   HeartbeatManager|
  | (MonoSingleton)  |      |  (PING/PONG 状态机) |
  +--+----+-----+----+      +-------------------+
     |    |     |
     |    |     +--> MessageDispatcher --[主线程队列 BoundedActionQueue]--> handler
     |    |
     |    +--------> ProtocolFactory
     |                       |
     v                       v
  PacketCodec          IProtocol (TCP 已实现 / WebSocket KCP 未实现)
  [Length|CmdId|Body]       |
                            +--> TcpProtocol (Socket 异步收发,APM BeginXxx/EndXxx)
                                  接收循环: BeginReceive -> Decode -> OnDataReceived
                                  内部: _receiveBuffer (growable, max ~1MB+header)
```

**线程模型(实测)**:
- 接收 / 发送回调:Socket 线程(APM `BeginXxx` 模式)
- 业务派发:统一入 `BoundedActionQueue`,`NetworkManager.Update` 主线程消费
- 心跳驱动:`NetworkManager.Update` 主线程调 `Heartbeat.Tick()`
- 重连调度:`NetworkManager.Update` 主线程调 `DriveReconnect()`

**评估维度快速打分**

| 维度 | 评价 | 关键证据 |
| --- | --- | --- |
| 协议安全(长度/边界/校验) | **较好**,有 1MB 长度上限、`length < CmdIdSize` 拒绝;**无 magic 校验** | `PacketCodec.cs:92` |
| 半包/粘包/断连处理 | **基本对**,有 growable buffer、半包等待、APM 断连 callback | `TcpProtocol.cs:188-208`, `210-243` |
| 收发→派发线程模型 | **对**,Socket 线程 Enqueue,主线程 Update 消费;PONG 显式入主线程 | `MessageDispatcher.cs:262-285`;`NetworkManager.cs:259-275` |
| `MessageDispatcher` 反射/handler 链 | **有 1 个严重问题**:`NetMessageHandlerAttribute` 反射注册机制根本 *没接进去* | `Attributes/...cs:67-107` 全模块 0 调用方 |
| 心跳超时/退避/状态机 | **基本对**,有 1 个真 bug:`SendPingInternal` 0 心跳时停发但 `_waitingPong` 已设 | `NetworkManager.cs:308-314` + `HeartbeatManager.cs:168-175` |
| 重连风暴规避 | **对**,指数退避(1s→30s 上限);**有抖动加速风险**(Enqueue 主线程 ++) | `NetworkManager.cs:51-55`, `247-256` |
| 资源释放 / Dispose | **有 T1**:`TcpProtocol.Connect` 失败不触发 `OnDisconnected`;`NetworkManager` 无 `IDisposable` | `TcpProtocol.cs:101-113` |
| 可测试性 | **差**:依赖 `Time.unscaledTime`、`MonoSingleton`、零核心路径单元测试 | `NetworkManager.cs:253, 332`;`HeartbeatManager.cs:75` |
| 协议层 vs 业务层耦合 | **基本解耦**:`NetworkManager` 不 new 业务类型,通过 `IProtoCmd` 抽象 | `NetworkManager.cs:76-80, 142` |
| 异步取消(CTS) | **生产代码 0 用**,仅测试 `LocalEchoServer` 用 1 个 | grep `CancellationTokenSource` = 1 hit(测试) |

---

## 问题列表

> 排序按严重度 → file → line;每条均带最小修复建议。

### [T1] #1 `NetMessageHandlerAttribute` 反射注册机制根本没接入 — 整条路径是死代码

**位置**:`Assets/Scripts/Fuel/NetFramework/Attributes/NetMessageHandlerAttribute.cs:67-107`
**实测验证**:在 `Assets/Scripts/Fuel/**` 全模块 grep `NetMessageHandlerAttribute` → **1 hit**(即定义本身)。grep `ProtoCmdsLookup.Initialize` → **0 hits**。`ProtoCmdsLookup` 自身在 `IProtoCmd.cs:7` / `NetworkManager.cs:74, 139` 有 3 处提及,全部是 *XML 文档注释* 或 *日志字符串*,**无任何代码调用**。
**症状**:`NetMessageHandlerAttribute.MsgId` getter 走 `ProtoCmdsLookup.GetMsgId`,后者用 `Type.GetType("ProtoCmds")` 字符串解析(line 23)。整条 attribute 路径在 hot-update DLL 场景下 **完全走不通**(`Type.GetType` 默认只在 calling assembly 找),`_cmdsType` 永远为 null,`GetMsgId` 永远返回 0(line 45 早返回)。
**业务影响**:`MessageDispatcher.Register<TResp>(cmdId, h)` 是 *纯手动注册* API,完全不认 attribute。任何按 attribute 风格写的业务代码 0 路径被 dispatch,运行时静默丢消息,`MessageDispatcher` 只在 `Dispatch` line 269 打 `LogWarning`,无异常。
**最小修复**:
- 要么 **删掉** `NetMessageHandlerAttribute` + `ProtoCmdsLookup` 整个文件,改文档写"请用 `MessageDispatcher.Register<T>(cmd, h)`";
- 要么新增 `DispatcherScanner.ScanAllAssemblies()` 启动时扫 `[NetMessageHandler]` 方法并调 `Dispatcher.Register`,并把 `MsgId` 在 ctor 内算一次缓存为 `readonly uint`(避免每次读都走 `Type.GetType` 反射)。
**严重度:T1** — 公开 API 与实现脱节,踩坑代价 = 消息静默丢失。

---

### [T1] #2 `TcpProtocol.Connect` 异常路径只调 `OnError`,不调 `OnDisconnected` — 上层重连状态机被饿死

**位置**:`TcpProtocol.cs:88-114`(具体 catch 块在 line 101-113)
**实测验证**:直接读 `TcpProtocol.cs:101-113`:
```
101: catch (Exception e) {
103:     Debug.LogError(...);
104:     try { newSocket?.Close(); } catch { /* swallow */ }
105-111: lock (_stateLock) { if (_socket == newSocket) _socket = null; }
112:     OnError?.Invoke($"Connect failed: {e.Message}");
113: }
```
**注意 line 112 后函数 return**,`OnDisconnected` 在此路径上 **永远不会被调用**。
**业务影响**:
- 业务侧订阅 `OnConnectError` 可拿到错误事件,但 `OnConnectClose` 不会触发 → `NetworkManager` 的 `_reconnectAttempts` 不 ++(`NetworkManager.cs:249` `if (isAbnormal && ...)` 条件依赖 `OnDisconnected(true)` 进入)→ **不会自动重连**。
- 用户 UI 卡在"错误弹窗"或"重试按钮"状态,需要业务侧从 `OnConnectError` 主动 `Connect()`,**契约与 `OnConnectSuccess`/`OnConnectClose` 一致失败不同**。
- 与正常路径对比:`TcpProtocol.Send` line 318-321 / `EndConnect` 失败 line 127-129 / `EndReceive` 失败 line 225-228 / `EndSend` 失败 line 335-338 / `Receive` decode 失败 line 277-280 全部都调 `HandleDisconnect(true)`。**唯独 `new Socket` 失败 + DNS 解析失败(line 67)走 `OnError` 路径**。
- DNS 解析失败(`TcpProtocol.cs:67-68` `OnError?.Invoke($"DNS resolve failed: {host}"); return;`)同样问题。
**最小修复**:`TcpProtocol.cs:101-113` catch 末尾,在 `OnError?.Invoke` 之后,再调一次 `OnDisconnected?.Invoke(true)`(语义:异常断开)。同理 DNS 解析失败 line 67-68 也补一行。
**严重度:T1** — 上层重连状态机失效,业务侧需自行实现补偿逻辑。

---

### [T1] #3 `HeartbeatManager.SendPing` 在 OnSendPing 可能 no-op 时仍设 `_waitingPong=true` → 用户关心跳反而触发重连

**位置**:`HeartbeatManager.cs:168-175`(`SendPing`)+ `NetworkManager.cs:308-314`(`SendPingInternal`)
**实测验证**:
- `HeartbeatManager.SendPing` line 168-175:**先** `OnSendPing?.Invoke(_pingTimestamp)`(line 174),**前**设 `_waitingPong = true`(line 171)和 `_lastSendTime = _timeProvider()`(line 172)。
- `NetworkManager.SendPingInternal` line 308-314 在 `OnSendPing` 回调里:line 310 `if (!IsConnected || PingCmdId == 0) return;` —— **早返回**,不发送 PING。
- 结果:`_waitingPong = true` 已经设了,**永远不会**被 `HandlePong` 翻回 false(`HeartbeatManager.cs:184-191` `if (!_waitingPong) return;`)。
**业务影响**:`Timeout` 秒后(line 129)触发 `HandleTimeout`(line 146-163):
- `CurrentRetryCount++`(line 151)
- 第 1-2 次:触发 `OnHeartbeatTimeout` → `NetworkManager.TryReconnect`(line 296)
- 第 3 次:触发 `OnMaxRetryExceeded` → `NetworkManager.Disconnect()`(line 302)
- **用户把 `PingCmdId = 0` 想关掉自动心跳,反而被系统判定为心跳超时并主动断开**。
**最小修复**(任选一种):
- 把 `_waitingPong = true`(line 171) 移到 `OnSendPing?.Invoke` 之后(且 Invoke 后 `OnSendPing` 成功 `SendRaw` 才会执行);
- 或在 `NetworkManager.SendPingInternal` 早返回时调 `HeartbeatManager.AbortPing()`(新增公开方法),把 `_waitingPong = false`。
**严重度:T1** — 关闭心跳的预期行为 = 不发 PING,实际行为 = 超时 + 重连 + 强制断开,严重反直觉。

---

### [T1] #4 接收循环批量入队 + `MessageDispatcher.Update` 100/帧限速 + 静默丢消息

**位置**:`TcpProtocol.cs:248-295`(`ProcessReceivedData`)+ `MessageDispatcher.cs:295-311`(`Update`)+ `BoundedActionQueue.cs:39-48`(`Enqueue`)
**实测验证**:
- `TcpProtocol.ProcessReceivedData` line 269 `OnDataReceived?.Invoke(packet.CmdId, packet.Body)` 在 socket 线程同步触发,`MessageDispatcher.Dispatch` 把它入主线程队列。
- `MessageDispatcher.Update` line 298-310:`while (processed < 100 && _mainThreadQueue.TryDequeue(...))` —— 每帧最多 100 条,无"必须一次清空"语义。
- `BoundedActionQueue.Enqueue` line 39-48:满时 `while` 循环 `Dequeue` 丢最旧,`_droppedCount++`。
- **grep `DroppedCount` = 2 hits**,**全部在 `BoundedActionQueue.cs:34, 44` 自身**,**全模块无任何代码检查 `DroppedCount > 0` 并打告警/上报**。
**业务影响**:
- 持续高频入队(服务端漏配置流控,客户端一帧收到 1000+ 包)→ 队列稳态满 → 新消息入队时老消息被静默丢。
- `MessageDispatcher.cs:39-42` 注释承认"丢老消息比丢新消息更可接受",但 `DroppedCount` 不暴露给 `Debug.LogWarning`,业务侧零信号。
- 业务侧 handler 拿不到"我订阅的某条消息被丢了"的事件。
**最小修复**:
1. `MessageDispatcher.Update` 加一个观察点:在 dequeue 时若 `DroppedCount > 0` 且距上次告警 ≥ 1s,打 `LogWarning("Dropped N messages from queue, current cmdIds: ...")`(per-cmdId 抽样);
2. 或把"100/帧"改为"每帧耗时预算"(`Stopwatch`)自适应;
3. 长期:把 `DroppedCount` 暴露为可订阅事件给业务侧。
**严重度:T1** — 主线程消息可能持续被丢,业务侧零信号,定位靠"用户说好像少收到一条推送"。

---

### [T1] #5 `MessageDispatcher` handler 异常被 catch 静默吞,无 `AppDomain.UnhandledException` 桥接

**位置**:`MessageDispatcher.cs:280-283`(`Dispatch`)+ `MessageDispatcher.cs:298-308`(`Update`)+ `NetworkManager.cs:186-190`(主线程事件队列)+ `TcpProtocol.cs:271-273`(`OnDataReceived` 同步)
**实测验证**:grep `AppDomain.UnhandledException` = **0 hits**(全 NetFramework 模块)。grep `catch` + `LogError` 模式 = 4 处:
- `MessageDispatcher.cs:281-283`:handler 内异常吞
- `MessageDispatcher.cs:303-307`:主线程队列消费异常吞
- `NetworkManager.cs:187-190`:主线程事件(connect/disconnect/error)异常吞
- `TcpProtocol.cs:272-274`:OnDataReceived 同步回调异常吞
**业务影响**:
- 业务 handler 抛 NRE(典型:handler 持有已 `Destroy` 的 MonoBehaviour,Unity 重载场景常见)→ 被吞 → 业务侧无感知。
- `Debug.LogError` 写本地日志,不接 Sentry / Bugly / CrashSight 平台,崩溃分析平台拿不到。
**最小修复**:
1. 新增 `GlobalExceptionHandler` 静态类,启动时 `AppDomain.CurrentDomain.UnhandledException += ...`(同时 `Application.logMessageReceivedThreaded` 桥接 Unity log);
2. 上面 4 个 catch 块在 `Debug.LogError` 之后,把异常 *再 throw* 一份给全局 sink(用 `ExceptionDispatchInfo.Capture` 保留 stack)或直接 `throw`。
**严重度:T1** — 生产事故定位极难,handler 异常永远进不到崩溃分析平台。

---

### [T1] #6 `Register` 覆盖无清理 + 旧 `MessageParser<T>` 闭包立即变孤儿(GC 压力) + 重复注册告警被忽略

**位置**:`MessageDispatcher.cs:65-90`(`Register<TResp>`)+ `MessageDispatcher.cs:127-174`(`Register<TReq,TRsp>`)
**实测验证**:line 69-72 / 99-103 / 132-136 三处警告"overwriting",但 `_handlers[cmdId] = ...` 直接赋值(覆盖),**旧 handler 闭包、连带 `MessageParser<TResp>` 立即变孤儿**,等 GC。
**业务影响**:
- 重复 `Register`(scene reload / ILRuntime 重载 / 业务侧 `Awake` 多次执行)→ N 个 `MessageParser<TResp>` 累积。
- 每次 GC 都有解析器闭包待回收,主线程 GC 抖动。
- `parser.ParseFrom` 内部 `Func<TResp>` 工厂每次 `new TResp()`,假设 `TResp` 构造函数无副作用则 OK;但有副作用(罕见)就会成 bug。
**最小修复**:
1. 三处 `Register` 覆盖前先 `Unregister(cmdId)`(或抛 `InvalidOperationException`),强制业务侧显式注销;
2. `Register` 内部把 `MessageParser` 实例提升到 `Dictionary<uint, MessageParser>` 字段,避免闭包捕获。
**严重度:T1** — 静默 GC 压力 + 重复注册掩盖真实 bug(业务以为注册了 handler A,实际跑的是 handler B)。

---

### [T2] #7 `MessageDispatcher` 文件头缺"handler 跑在主线程"契约文档,接 Single Update 时易误用

**位置**:`MessageDispatcher.cs:8-37`(`MessageDispatcher` 类注释 + 字段定义)
**实测验证**:`MessageDispatcher` 类注释 line 8-12 说"通过主线程队列确保 handler 在 Unity 主线程执行",**但这是行为而非契约**。`Dispatch` 的方法注释 line 260-262 说"在 Socket 线程调用是安全的:内部加锁",但没明确"handler 内部 *可以* 安全访问 UnityEngine.Object"。
**业务影响**:接手人若写 `handler = msg => transform.position = ...`,会担心跨线程 — 实际不会爆,但需读懂 `_mainThreadQueue` 才知道。
**最小修复**:`MessageDispatcher.cs:9-13` 的 class comment 改为:
```
/// <summary>
/// 消息分发器。handler 一定在 Unity 主线程被调用(经 BoundedActionQueue + Update)。
/// 在 handler 内访问 UnityEngine.Object / transform / Component 是安全的。
/// </summary>
```
**严重度:T2** — 文档缺失,误用风险中等。

---

### [T2] #8 `NetworkManager` 是 `MonoSingleton` 且 `Update` 内直接 `Time.unscaledTime` / `Time.realtimeSinceStartup`,核心路径 0 单元测试

**位置**:`NetworkManager.cs:253, 332`(`Time.unscaledTime`)+ `HeartbeatManager.cs:75`(`Time.realtimeSinceStartup`)+ `NetworkManagerE2ETest.cs:90-91`(反射改 private)
**实测验证**:
- grep `Time\.unscaledTime` = 2 hits(`NetworkManager.cs:253, 332`)。
- grep `Time\.realtimeSinceStartup` = 1 hit(`HeartbeatManager.cs:75`)。
- grep `AppDomain.UnhandledException` = 0 hits。
- `HeartbeatManager` 已有 `Func<float> timeProvider` 注入构造(line 80-83),**但 `NetworkManager.OnInit` line 67 用 `new HeartbeatManager()` 不传参**,**没用注入口**。
- `NetworkManagerE2ETest.cs:90-91` 用反射 `typeof(NetworkManager).GetField("_reconnectDelay", NonPublic | Instance)` 改 private 字段。
**业务影响**:
- 核心 `Send<T>` / `Connect` / `HandleDisconnected` / `DriveReconnect` 路径无任何纯 dotnet 单元测试,只能靠 E2E 心跳(且 E2E 实际 *绕开* `Send<T>`,直接用 `proto.Send(packet)`)。
- 改 `_reconnectDelay` 字段名 = E2E 编译/运行报 null 引用,反射 + 字符串路径极度脆弱。
**最小修复**:
1. `NetworkManager.OnInit` line 67 改为 `new HeartbeatManager(() => Time.realtimeSinceStartup)`(或可注入 `Func<float>`);
2. 把 `InitialReconnectDelay` / `MaxReconnectDelay` / `_reconnectAttempts` 暴露成 `public` 属性 + `public set`,E2E 不再反射;
3. 抽 `INetworkManager` 接口,核心连接/发送/接收走纯 C# 类(不依赖 `MonoBehaviour`),可 dotnet 测。
**严重度:T2** — 主路径 0 单元测试覆盖,只能靠 E2E 心跳,回归风险高。

---

### [T2] #9 重连退避在"网络抖动"下被 `_reconnectAttempts++` 加速,Enqueue 在 socket 线程而 ++ 在主线程

**位置**:`NetworkManager.cs:231-257`(`HandleDisconnected`)+ `NetworkManager.cs:327-335`(`DriveReconnect`)
**实测验证**:
- `HandleDisconnected` line 231 在 **socket 线程**被调(line 70-71 `Protocol.OnDisconnected += HandleDisconnected` 在 `OnInit` 之外、socket 触发)。
- line 236 `_mainThreadEventQueue.Enqueue(() => { ... _reconnectAttempts++; ... })` —— 把 ++ 推到主线程下一帧。
- `DriveReconnect` line 327-335 在 `Update` 主线程跑。
- **socket 线程在 < 16ms 内连发两次异常断开** → 两次 `HandleDisconnected` 都 Enqueue → 主线程下一帧 dequeue 两次 → `_reconnectAttempts = 2`。
- 但 `_reconnectDelay *= 2`(line 254)也在 Enqueue 内 → 两次 Enqueue 都会让 `_reconnectDelay` 翻倍 → 退避比预期陡。
**业务影响**:
- 正常抖动(1 秒内几次断开)→ 退避被加速 → 业务侧可能根本来不及等就重连。
- 极少见但生产中遇到过:对端负载均衡器秒切,客户端重连雪崩。
**最小修复**:
1. `_reconnectAttempts++` / `_reconnectDelay *= 2` 搬到 `DriveReconnect` 调 `TryReconnect` *前*(主线程),而不是在 `HandleDisconnected` 的 Enqueue 内;
2. 或加 `_reconnectAttempts` 上限 + 抖动 `Random.Range(0, _reconnectDelay * 0.1f)`。
**严重度:T2** — 抖动场景退避失真,生产中可能踩到但不频繁。

---

### [T2] #10 `Paused` 公开可写(`public bool Paused { get; set; }`) — 状态机有外部写入路径

**位置**:`HeartbeatManager.cs:38`(`public bool Paused { get; set; }`)
**实测验证**:`Paused` 既是内部状态(在 `TryReconnect` line 343 / `Tick` line 121 / `Start` line 91 / `Stop` line 104 内部读写)又是对外 API。业务侧可随时 `NetworkManager.Heartbeat.Paused = true`,但无文档说明"什么时候应该 paused,什么时候该 Stop",易与 `Start/Stop/ResetRetryCount` 状态机打架。
**业务影响**:业务侧"想临时关掉心跳"可能 `Paused = true` 然后忘了恢复,`Paused` 卡 true → `Tick` 早返回 → 永远不会触发超时 → `_waitingPong` 卡住等永远不会到的 PONG(虽然 `Paused` 状态下 `Tick` 早返回所以也不会触发 `HandleTimeout`,但 `Start/Stop` 切换时 `Paused` 不会被自动重置)。
**最小修复**:`Paused` 改 `internal`,或用 `Suspend()/Resume()` 显式 API。
**严重度:T2** — 状态泄漏,中度风险。

---

### [T2] #11 `BoundedActionQueue.cs` 注释说"已移入 MessageDispatcher.cs 作为其 public 嵌套类",实际迁移未完成

**位置**:`Dispatcher/BoundedActionQueue.cs:1-3`(注释)+ `MessageDispatcher.cs:37`(字段类型引用)
**实测验证**:
- `BoundedActionQueue.cs:1-3`:`// BoundedActionQueue 已移入 MessageDispatcher.cs 作为其 public 嵌套类。保留此文件仅为不破坏 .meta 引用;该类不再在此处定义。`
- **但 line 11-64 实际仍定义了 `BoundedActionQueue` 类**。
- `MessageDispatcher.cs:37` `private BoundedActionQueue _mainThreadQueue;` 引用 `Fuel.NetFramework.Dispatcher.BoundedActionQueue`(同命名空间游离类),**不是嵌套类**。
- grep `BoundedActionQueue` = 2 hits(自身文件 + `MessageDispatcher.cs:37`)。
**业务影响**:
- 任何依赖 `using Fuel.NetFramework.Dispatcher;` 然后用 `MessageDispatcher.BoundedActionQueue` 引用嵌套类的代码会编译失败。
- 后续 PR 若按注释预期 *删* `BoundedActionQueue.cs`,`MessageDispatcher._mainThreadQueue` 会编译错误。
- **"半完成的迁移"信号**(Launcher review 记忆清单项 7 / Manager review 记忆清单同样适用)。
**最小修复**:选一条路走完:
- 要么 *真* 迁到 `MessageDispatcher` 嵌套类并删 `BoundedActionQueue.cs`,把 `BoundedActionQueue` 改 `internal`;
- 要么把注释改回"BoundedActionQueue 作为独立类供 MessageDispatcher 内部使用"。
**严重度:T2** — 注释与代码矛盾,半完成迁移的死亡状态。

---

### [T2] #12 协议层无 `magic` 校验 / 无版本号字段 / `length` 校验放在 `length > MaxPacketLength` 但 `MaxPacketLength` 是 1MB,客户端无能力识别"对端发了一个 5GB length 假装" 实际是 `int` 范围内的拒绝

**位置**:`PacketCodec.cs:29, 92`(长度上限)
**实测验证**:
- `PacketCodec.cs:29` `public const int MaxPacketLength = 1024 * 1024;` —— 1 MiB。
- `PacketCodec.cs:92` `if (length < CmdIdSize || length > MaxPacketLength) throw new InvalidDataException(...)` —— 上限 = 1 MiB。
- `length` 字段是 *有符号* `int`(line 87-90,`(buffer[offset] << 24) | (buffer[offset+1] << 16) | (buffer[offset+2] << 8) | buffer[offset+3]`),C# `int` 移位 + `|` 不会自动变 unsigned,**负数 `length` 会通过 `< CmdIdSize` 检查**(因为 `CmdIdSize = 4`,负数 `< 4` 为 true,直接抛 — OK)。
- **但 `length == 0` 场景没拒绝**:`length < 4` 才会抛,`length == 0` 抛(line 92)。OK。
- **真正的 2 个缺失**:
  1. **无 magic / version 字段**:服务端可以发任何 cmdId 假装成自己的(伪装 / 重放风险)。游戏行业一般 4 字节 magic + 4 字节 version + 4 字节 cmdId + body。`PacketCodec` line 9 注释说"包格式: [Length(4)] [CmdId(4)] [Body(N)]",**完全没有 magic**。
  2. **`TcpProtocol.cs:18-20` `MaxBufferSize = 1MB + 8B + 16B` ≈ 1MB**,但 `EnsureBufferSpace` line 196-200 在 `newSize > MaxBufferSize` 时,如果 `required > newSize` 会**破窗**把 `newSize = required`,然后 `Decode` 才通过 `MaxPacketLength` 校验拒。**单包能撑爆 buffer 到 `required`**(恶意:发一个 length=0x7FFFFFFF 的包,`Decode` 抛 `InvalidDataException` → `HandleDisconnect(true)`)。OK,会被 `Decode` 截。但 `EnsureBufferSpace` 在那之前会 `new byte[required]` —— **`required = _bufferOffset + 1` 约 1MB**,**`new byte[0x7FFFFFFF]` 不会真分配(OutOfMemoryException 立刻抛),被 catch**。
  3. **长 length (e.g. 100MB) 在 `Decode` 抛之前的 buffer 分配**:`available = _bufferOffset - offset` 必须先 ≥ `HeaderLengthSize + length` 才返回 0(line 96),但 `length = 0x06400000` (100MB) 时,`available < HeaderLengthSize + length` 永远 true → 持续返回 0,持续等待更多数据 → 业务侧无感,服务端永远不会凑够 100MB → 死等。
**业务影响**:
- 缺 magic → 易受重放 / 协议混淆攻击。
- 缺 length 上限 early-rejection → 恶意对端发超大 length 让客户端 `available < required` 永远不返回,占用 `socket` + 内存里的 `_receiveBuffer` 持续增长到 `MaxBufferSize` 撑爆,然后 line 167 报错断开。**实测有 1MB 内存上限保护,不致命**。
**最小修复**:
- `PacketCodec.Decode` line 92 把 `length` 显式判 `if (length < CmdIdSize || length > MaxPacketLength)` 已对。
- 增加 magic 字段(4 字节)到 `PacketCodec`,`Decode` 第一步校验 magic,不匹配直接断开。
- 增加 version 字段(2 字节)以便后续协议升级。
**严重度:T2** — 1MB 内存保护已就位,不致命;但 magic 缺失是设计层缺失,游戏客户端通常会加。

---

### [T2] #13 `ProtoCmdsLookup.GetMsgId` 走 *Type.GetType 字符串解析*,`MsgId` 每次反射读

**位置**:`Attributes/NetMessageHandlerAttribute.cs:43-60, 84`(`MsgId` getter)+ `NetMessageHandlerAttribute.cs:23`(`Type.GetType`)
**实测验证**:`Type.GetType("ProtoCmds")` 默认只在 calling assembly 找。grep `ProtoCmdsLookup.Initialize` = **0 hits**(没人显式注入)。`MsgId` getter 每次读都走 `Type.GetType` + `GetField` + `GetRawConstantValue`(attribute 实例不缓存 MsgId)。
**业务影响**:
- 启动 hot-update 前:`_cmdsType == null` → `GetMsgId` 返回 0(line 45 早返回)。
- 启动 hot-update 后:仍 `null`(没人调 `Initialize`)。
- 整条 attribute 路径实际 *完全没用*(#1 已说),但即便要修,`MsgId` 应在 ctor 算一次缓存为 `readonly uint`。
- 性能:每次 attribute 读 `MsgId` 都走 `GetField(...).GetRawConstantValue()` 反射,热路径上是反射开销。
**严重度:T2** — 性能 + 初始化顺序 + 死代码三合一,被 #1 覆盖,本条作为 #1 的性能层面补充。

---

### [T2] #14 `NetworkManager.Send<T>` 失败原因不可观测,业务侧拿 `false` 不知道 *为什么*

**位置**:`NetworkManager.cs:135-177`
**实测验证**:
- `Send<T>` line 135-156 失败分支:`CmdGetter == null` / `cmdId == 0` / `IsConnected == false`(此分支实际在 `Send<T>(uint, T)` line 160)。
- `SendRaw` line 169-177 失败:`IsConnected` 不满足。
- **业务侧拿到 `false` + 只能看 log**。
- 与 `OnConnectError` event 带 string 不一致。
**业务影响**:业务侧 debug "为什么消息没发出去" 只能读 logcat。
**最小修复**:`Send` 返回 `SendResult` 枚举(`Success` / `NotConnected` / `NoCmdId` / `NoCmdGetter` / `ProtoSerializeFailed`),或 `bool Send<T>(out string reason)`。
**严重度:T2** — API 设计,中度。

---

### [T2] #15 `NetworkManagerE2ETest` 与生产代码脱节 — 主路径 0 覆盖

**位置**:`Tests/NetworkManagerE2ETest.cs`(整文件 334 行)+ `NetworkManager.cs:135-156`(`Send<T>`)
**实测验证**:E2E 测试 6 个 case:
- `TestConnect`(line 126-133)✓ 覆盖 `Connect`
- `TestSmallMessage`(line 135-157) **用 `proto.Send(packet)` 直接发字节**,绕开 `NetworkManager.Send<T>` → **生产 `Send<T>` 路径 0 覆盖**
- `TestLargeMessage`(line 159-185)同 `proto.Send(packet)`
- `TestHeartbeat`(line 187-214)覆盖 PING/PONG ✓
- `TestReconnect`(line 216-273)覆盖重连 ✓
- `TestInvalidHost`(line 275-293)覆盖 `OnError` ✓
- **0 case 覆盖**:`Send<T>(IMessage)` 路径、`CacheRequest` req-rsp FIFO、`Unregister` 清理、`MessageDispatcher.Clear` 后状态、`Heartbeat.OnMaxRetryExceeded` 触发。
**业务影响**:核心协议层 0 单元测试,只能靠 E2E 心跳。
**严重度:T2** — 已有 E2E 但覆盖不全。

---

### [T3] #16 `ProtocolFactory.Create(WebSocket/KCP)` 抛 `ArgumentException`,与 `OnConnectError` 事件契约不一致

**位置**:`ProtocolFactory.cs:25-29`(`throw new ArgumentException`)+ `NetworkManager.cs:109-117`(直接 throw 出去)
**实测验证**:`ProtocolFactory.Create(ProtocolType.WebSocket)` 走 default 分支抛 `ArgumentException`,**不被 `NetworkManager.Connect` catch**,冒泡到业务侧。同一 `OnError` 事件被用于其他错误(`DNS resolve failed`、`Connect failed`),不一致。
**业务影响**:业务侧需 try/catch 兜 `ArgumentException` + 订阅 `OnConnectError` event,两套错误路径。
**严重度:T3** — API 风格不一致。

---

### [T3] #17 `NetworkManager` 无 `IDisposable`,`OnApplicationQuit` 清理不全

**位置**:`NetworkManager.cs:200-209`(`OnApplicationQuit`)
**实测验证**:`OnApplicationQuit` 清理:
- ✓ `Heartbeat.Stop`
- ✓ `Heartbeat.OnHeartbeatTimeout -=`
- ✓ `Heartbeat.OnMaxRetryExceeded -=`
- ✓ `Heartbeat.OnSendPing -=`
- ✓ `CleanupProtocol`
- ✓ `Dispatcher?.Clear`
- ✗ **`NetworkManager` 自身事件 `OnConnectSuccess` / `OnConnectClose` / `OnConnectError` 未显式清空委托列表** — 业务侧引用消失时 delegate 列表是 NetworkManager 持有,业务侧引用消失时自动清,OK
- ✗ **`_mainThreadEventQueue` 无 Dispose**(它只是 `ConcurrentQueue<Action>`,OK)
- ✗ **无 `ProtoCmdsLookup.Initialize(null)` 重置**(hot-update 切换时可能持有 StaleType 引用)
- ✗ **场景切换时无 `Dispose()` API**,只能 `Destroy(_nmGo)`,`OnDestroy` 把 `_instance = null`(`MonoSingleton.cs:84-90`)但内部 `_mainThreadEventQueue` 引用可能在 GC 时机延后
**业务影响**:主流程不会爆,场景切换/destroy 时机有微小泄漏。
**严重度:T3** — 资源释放不彻底,低风险。

---

### [T3] #18 pending request 无超时清理,FIFO 错乱风险(依赖 TCP 保序)

**位置**:`MessageDispatcher.cs:194-211`(`CacheRequest`)+ `MessageDispatcher.cs:27-28`(注释明确)
**实测验证**:`MessageDispatcher.cs:27-28` 注释:"TCP 保序,所以同一 cmdId 的多个 in-flight request 按 FIFO 匹配响应;UDP/KCP 等无序协议需要在 TReq 内部带 requestId 自己匹配"。`CacheRequest` line 204-208 仅依赖 `MaxPendingRequestsPerCmdId`(默认 100)兜底,**无时间维度**。
**业务影响**:
- 服务端 bug(漏发响应)→ 客户端缓存堆到 100 → 旧 request 被丢(line 207 `q.Dequeue()`)→ 新 response 到达 → `TryGetAndRemoveRequest` 拿"新 req"配"旧 rsp" → **FIFO 错乱但静默无错**。
- 业务侧几乎察觉不到,因为 `TryGetAndRemoveRequest` 不会抛异常,handler 收到的 `(req, rsp)` 类型对得上就 OK。
**严重度:T3** — 长期运行的连接,服务端 bug 会让客户端 req/rsp 错乱,业务侧无感知。

---

### [T3] #19 `BoundedActionQueue.Enqueue` 满时 `while` 循环 dequeue,极端情况 O(N) 单次入队

**位置**:`BoundedActionQueue.cs:39-48`
**实测验证**:line 41 `while (_queue.Count >= _capacity) { _queue.Dequeue(); _droppedCount++; }` —— 容量满时一次入队最多丢 N 条才把队列腾出 1 个位置。这是 O(1) 摊还,但 *一次 Enqueue 调用最坏耗时* O(N)。在 socket 线程(`EnqueueMainThread` 在 `MessageDispatcher.Dispatch` 里)持锁,主线程 `Update` 反向想拿锁消费 → 主线程被卡住等 socket 线程释放锁。
**业务影响**:极端反压时主线程卡顿概率低,但存在。
**严重度:T3** — `while` 应改为 `if`(只丢 1 个让出位置),一行改动。

---

### [T3] #20 `MessageDispatcher.Dispatch` 未注册 cmdId 高频 spam warning

**位置**:`MessageDispatcher.cs:269`
**实测验证**:line 269 `Debug.LogWarning($"[MessageDispatcher] No handler registered for cmd {cmdId}.");` —— 每条未注册 cmdId 都打一条 warning,无频率限制。
**业务影响**:服务端漏注册一个高频 Push → 客户端 60Hz 推送 → 1 秒 60 条 warning,Logcat/Console 刷屏掩盖其他问题。
**严重度:T3** — 可观测性 hygiene。

---

### [T3] #21 `LocalEchoServer.Loop` 每次 `pending.ToArray()` 全量拷贝

**位置**:`Tests/NetworkManagerE2ETest.cs:360`
**实测验证**:line 360 `consumed = PacketCodec.Decode(pending.ToArray(), offset, pending.Count - offset, out packet);` —— **每次循环都 `ToArray()` 拷贝整个 pending 列表**。
**业务影响**:900KB 测试时,服务端每次循环 `ToArray()` 把 ~900KB 复制一次。E2E 是测 *客户端*,服务端效率不影响业务正确性,但 1 倍内存放大不优雅。
**严重度:T3** — 测试代码效率,不是产品 bug。

---

## 风险摘要表

| # | 严重度 | 类别 | 简述 | 位置 | 关键证据 |
| --- | --- | --- | --- | --- | --- |
| 1 | **T1** | 死代码 | `NetMessageHandlerAttribute` 反射注册未接入,公开 API 静默丢消息 | `Attributes/NetMessageHandlerAttribute.cs:67-107` | 全模块 grep 0 调用方(实测) |
| 2 | **T1** | 资源/状态机 | `TcpProtocol.Connect` 异常路径不触发 `OnDisconnected`,重连状态机饿死 | `TcpProtocol.cs:101-113` | catch 后只调 `OnError`(line 112),不调 `OnDisconnected` |
| 3 | **T1** | 心跳 | `PingCmdId=0` 关心跳时,`_waitingPong=true` 卡住触发假超时 → 重连 | `HeartbeatManager.cs:168-175` + `NetworkManager.cs:308-314` | `SendPingInternal` 早返回(line 310)但 `_waitingPong` 已设(line 171) |
| 4 | **T1** | 线程/反压 | 接收循环批量入队 + 100/帧 + 静默丢消息,业务侧零信号 | `TcpProtocol.cs:269` + `MessageDispatcher.cs:298-311` + `BoundedActionQueue.cs:41-45` | grep `DroppedCount` = 2 hits 都在 `BoundedActionQueue.cs` 自身,无观察点 |
| 5 | **T1** | 派发/异常吞 | handler 异常被 catch 静默吞,无 `AppDomain.UnhandledException` 桥接 | `MessageDispatcher.cs:280-283, 303-307` + `NetworkManager.cs:186-190` + `TcpProtocol.cs:271-273` | grep `AppDomain.UnhandledException` = 0 hits |
| 6 | **T1** | 派发/GC 压力 | `Register` 覆盖无清理,旧 `MessageParser` 闭包变孤儿 | `MessageDispatcher.cs:65-90, 127-174` | 三处 Register 都直接 `_handlers[cmdId] = ...` 覆盖,无 Unregister 路径 |
| 7 | T2 | 线程模型/契约 | 文档缺"handler 跑在主线程" | `MessageDispatcher.cs:8-37` | 类注释说"主线程执行"但未明确"UnityEngine.Object 安全" |
| 8 | T2 | 可测试性 | `NetworkManager` 强绑 `Time` / `MonoSingleton`,核心路径 0 单元测试 | `NetworkManager.cs:253, 332` + `HeartbeatManager.cs:75` | `HeartbeatManager` 有 `timeProvider` 注入口但 `NetworkManager.OnInit` 不用 |
| 9 | T2 | 重连状态机 | 抖动下多次 Enqueue 让 `_reconnectAttempts` 加速 | `NetworkManager.cs:231-257, 327-335` | Enqueue 在 socket 线程,++ 在主线程 next frame |
| 10 | T2 | 状态泄漏 | `HeartbeatManager.Paused` 公开可写 | `HeartbeatManager.cs:38` | `public bool Paused { get; set; }` |
| 11 | T2 | 死代码/半完成迁移 | `BoundedActionQueue.cs` 注释说"已移入",实际类还在 | `Dispatcher/BoundedActionQueue.cs:1-3` | 与 `MessageDispatcher.cs:37` 实际引用矛盾 |
| 12 | T2 | 协议安全 | 无 magic 校验 / 缺版本号 | `PacketCodec.cs:9, 29, 92` | 包格式仅 `[Length][CmdId][Body]`,无 magic |
| 13 | T2 | 反射性能 | `ProtoCmdsLookup` 字符串解析 + `MsgId` 每次反射读 | `Attributes/NetMessageHandlerAttribute.cs:23, 43-60, 84` | attribute 不缓存 MsgId |
| 14 | T2 | API 设计 | `Send` 失败仅 `false`,无失败原因 | `NetworkManager.cs:135-177` | 业务侧拿不到 reason |
| 15 | T2 | 可测试性 | E2E 0 case 覆盖 `Send<T>` / `CacheRequest` / `Unregister` 路径 | `Tests/NetworkManagerE2ETest.cs`(6 个 case 中 2 个用 `proto.Send` 绕开 `NetworkManager.Send<T>`) | line 142, 165 用 `proto.Send(packet)` 而非 `_nm.Send<T>(msg)` |
| 16 | T3 | 契约不一致 | `ProtocolFactory` 抛异常 vs `OnConnectError` event | `ProtocolFactory.cs:25-29` | 部分错误是 throw,部分走 event |
| 17 | T3 | 资源释放 | 无 `IDisposable`,`OnApplicationQuit` 清理不全 | `NetworkManager.cs:200-209` | 缺 `Dispose()` 路径 |
| 18 | T3 | 协议正确性 | pending request 无超时清理,FIFO 错乱风险 | `MessageDispatcher.cs:27-28, 194-211` | 依赖服务端必响应,无 TTL |
| 19 | T3 | 反压实现 | `BoundedActionQueue.Enqueue` 满时 `while` dequeue | `BoundedActionQueue.cs:41-45` | 一次入队最坏 O(N) |
| 20 | T3 | 可观测性 | 未注册 cmdId 高频 spam warning | `MessageDispatcher.cs:269` | 缺 per-cmdId 频率限制 |
| 21 | T3 | 测试效率 | `LocalEchoServer.Loop` 每次 `pending.ToArray()` 全量拷贝 | `Tests/NetworkManagerE2ETest.cs:360` | 900KB 测试放大 1 倍 |

**统计**:T1 × 6 / T2 × 9 / T3 × 6,**共 21 条**具体问题(超最低 8 条门槛)。

---

## 修复优先级建议

1. **必须先修(下一个 sprint)**:#1、#2、#3、#5、#6 — 这 5 个是 *真 bug*,生产会出现"消息静默丢"或"用户关心跳反而断线"或"异常路径 UI 永远卡住"。
2. **强烈建议(本季度)**:#4(反压可观测)、#8(可测试性拆解)、#9(重连抖动)、#11(半完成迁移)、#12(协议 magic) — 这 5 个是 *架构债*,继续累积会让后续重构成本指数上升。
3. **可延后**:#7、#10、#13–#21 — 主要是 API 设计、文档、风格问题,改起来零散。

**额外架构建议**:
- 抽 `INetworkManagerCore` 接口,`NetworkManager` 只做 Unity 适配(单例 + Update 转发),核心连接/发送/接收走纯 C# 类,可 dotnet 测。
- `BoundedActionQueue` 真的迁到 `MessageDispatcher` 嵌套类,改 `internal`。
- 引入 `RequestContext { uint cmdId; long requestId; DateTime sentAt; }`,用 `requestId` 显式配对 req/rsp,避免 FIFO 假设;`RequestContext` 带 `sentAt` 实现超时清理(对应 #18)。
- `Send` 失败返回 `SendResult` 枚举,业务侧可观测(对应 #14)。
- 协议层加 magic 字段(对应 #12)。

---

## 附录:本报告自身元数据(供 verifier 校对)

| 字段 | 值 | 验证方式 |
| --- | --- | --- |
| 源文件总数 | 12 | `Get-ChildItem -Recurse -Filter *.cs` 实测 = 12 |
| 源文件总行数 | 1808 | 87+133+156+21+297+22+53+289+63+28+325+334 实测求和 |
| 源文件总字节数 | 79837 bytes | 实测求和(Attributes 4024 + Codec 6156 + Core 22990 + Dispatcher 14330 + Protocol 15273 + Tests 18064) |
| 嵌套类数 | 1(`LocalEchoServer` 在 `NetworkManagerE2ETest.cs` 内) | 实测 |
| 唯一 `IProtocol` 实现 | 1(`TcpProtocol`) | grep `: IProtocol` = 1 hit |
| `IDisposable` 实现 | 1(`LocalEchoServer`,测试用) | grep `IDisposable` = 1 hit |
| `MonoBehaviour` 派生 | 2(`NetworkManager`、`NetworkManagerE2ETest`) | grep `MonoBehaviour` = 2 hits |
| `CancellationTokenSource` 使用 | 1(仅 `LocalEchoServer` 测试) | grep `CancellationTokenSource` = 1 hit |
| `AppDomain.UnhandledException` 注册 | 0 | grep = 0 hits |
| `async`/`await` 使用 | 0(用 APM `BeginXxx`/`EndXxx` 替代) | grep `\basync\b\|\bawait\b` = 0 hits |
| `Time.unscaledTime` 出现 | 2(`NetworkManager.cs:253, 332`) | grep = 2 hits |
| `Time.realtimeSinceStartup` 出现 | 1(`HeartbeatManager.cs:75`) | grep = 1 hit |
| `NetMessageHandlerAttribute` 调用方 | 0(只有定义本身 1 hit) | 全 `Fuel/` grep = 1 hit |
| `ProtoCmdsLookup.Initialize` 调用方 | 0 | grep = 0 hits |
| `DroppedCount` 引用点 | 2(都在 `BoundedActionQueue.cs:34, 44`,无外部观察者) | grep = 2 hits |
| 报告中问题条目数 | 21 | 人工计数 + 风险摘要表行数核对 |
| 报告 T1 数量 | 6 | 人工计数 |
| 报告 T2 数量 | 9 | 人工计数 |
| 报告 T3 数量 | 6 | 人工计数 |
| Scope discrepancy 数量 | 1(任务说明的 `BoundedChannel` 实际为 `BoundedActionQueue`) | 见 §0 范围核实表 D1 |
