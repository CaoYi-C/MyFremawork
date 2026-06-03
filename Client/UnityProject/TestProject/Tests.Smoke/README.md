# Fuel.Smoke — 独立烟测项目

## 它是什么

一个**不依赖 Unity Editor** 的 .NET 8 控制台项目，用来端到端验证 `Assets/Scripts/Fuel/NetFramework/`
里修过/没修过的网络栈。`.csproj` 通过 `<Compile Include="..\Assets\..." Link="..." />` **直接 link 真项目的源文件**，
确保测的就是 Unity 客户端编进 `Assembly-CSharp.dll` 的同一份字节。

跑它不需要 Unity Editor、不需要装 Editor 包，CI 里能直接 `dotnet run`。

## 怎么跑

```bash
cd Tests.Smoke
dotnet run
```

期望输出：

```
===========================================
  Fuel.Smoke — running smoke tests
===========================================

  [PASS] PacketCodec.Roundtrip
  [PASS] PacketCodec.PartialDecodeWaits
  [PASS] PacketCodec.EmptyBody
  [PASS] PacketCodec.LargeBody_100KB
  [PASS] PacketCodec.InvalidLength_Throws
  [PASS] PacketCodec.BodyStable_AfterBufferMutated
  [PASS] PacketCodec.EncodeUsesArrayPool
  [PASS] HeartbeatManager_Tick_NotRunning_IsNoop
  [PASS] Tcp.Echo_Roundtrip
  [PASS] Tcp.PartialSend_Assembled
  [PASS] Tcp.LargePacket_100KB
  [PASS] Tcp.Bursty_100Packets_AllReceived
  [PASS] Tcp.ServerDisconnect_ClientSees
  [PASS] MessageDispatcher.MainThreadDispatch

===========================================
  Result: 14 passed, 0 failed
===========================================
```

## 它测什么

| # | 测试 | 验证的修复点 |
|---|------|-------------|
| 1 | `PacketCodec.Roundtrip` | 编码 → 解码 cmdId/body 一致 |
| 2 | `PacketCodec.PartialDecodeWaits` | 半包（1/3/4 字节、actualLen-3 字节）正确返回 0 |
| 3 | `PacketCodec.EmptyBody` | 空 body 包正常 roundtrip |
| 4 | `PacketCodec.LargeBody_100KB` | 100 KB body 正确往返 |
| 5 | `PacketCodec.InvalidLength_Throws` | length<4 或 >1MB 抛 `InvalidDataException` |
| 6 | `PacketCodec.BodyStable_AfterBufferMutated` | **#3 修复核心**：Decode 后清空源 buffer，body 仍然完整 |
| 7 | `PacketCodec.EncodeUsesArrayPool` | **#8 修复**：10000 次 encode/release 不爆 OOM |
| 8 | `Heartbeat_NotRunning_IsNoop` | 未 Start 时 Tick 不抛 |
| 9 | `Tcp.Echo_Roundtrip` | 真实 TcpProtocol 连本地 EchoTcpServer，收发一致 |
| 10 | `Tcp.PartialSend_Assembled` | **粘包/半包**：分 4 段 send 23 字节，server 端解出 2 个完整包 |
| 11 | `Tcp.LargePacket_100KB` | 100 KB body 端到端不丢 |
| 12 | `Tcp.Bursty_100Packets_AllReceived` | 100 个并发包，cmdId 1..100 全到且不重复 |
| 13 | `Tcp.ServerDisconnect_ClientSees` | server 主动断开 → client OnDisconnected 触发 |
| 14 | `MessageDispatcher.MainThreadDispatch` | Dispatch 后 handler 不会立即跑，Update 后才跑 |

## 文件结构

```
Tests.Smoke/
├── FuelSmoke.csproj              # .NET 8 控制台项目，link Fuel 真源码
├── Program.cs                    # 14 个测试 + 入口
├── EchoServer/
│   └── EchoTcpServer.cs          # 本地 TCP echo 服务器，支持大包/断开等特殊 cmdId
└── Stubs/
    ├── Packet.cs                 # Fuel.NetFramework.Core.Packet 的非 Unity 版本
    └── UnityShim.cs              # UnityEngine.Debug / Time 的最小桩
```

## 已知限制

- `TcpProtocol` 的 APM 异步 API 在 .NET 8 上跑得跟 Unity 上略有差异（Unity 用 `Mono`，.NET 8 用 CoreFX），
  但协议正确性是一致的。
- 测试不验 Protobuf 序列化/反序列化（需要生成 .proto），用 `EmptyMsg` 占位。
- 测试不验重连退避（#16）—— `NetworkManager` 依赖 `MonoSingleton<MonoBehaviour>`，跑不了独立测试；
  请在 Unity Editor 里手测或在 `Assets/Tests/Editor/` 加 PlayMode 测试。

## 在 CI 里跑

```yaml
# GitHub Actions 示例
- name: Run Fuel smoke tests
  run: dotnet run --project Tests.Smoke
  working-directory: TestProject
```
