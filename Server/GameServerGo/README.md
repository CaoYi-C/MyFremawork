# GameServerGo

基于 [due](https://github.com/dobyte/due) 框架的 Go 游戏服务器骨架,使用 `testserver` 作为 module 名。

## 项目结构

```
Server/GameServerGo/
├── cmd/
│   ├── gate/main.go              ← Gate 网关进程入口
│   └── node/main.go              ← Node 逻辑进程入口
├── internal/
│   ├── packetsetup/              ← 注册 4 字节 Route 的全局 Packer
│   ├── routeids/                 ← MsgId 常量表(对齐 Unity ProtoCmds)
│   ├── data/                     ← 数据层抽象(Entity/Repository/UnitOfWork)
│   │   └── memory/               ← 内存实现(开发期)
│   └── handler/
│       ├── ping.go               ← PING/PONG 业务 handler
│       └── login.go              ← 占位
├── proto/                        ← 跑 gen_proto_go.bat 后生成(.gitignore)
├── etc/etc.yaml                  ← due 集群配置
├── docker/docker-compose.yaml    ← Redis + Consul
├── gen_proto_go.bat              ← .proto → .pb.go 生成脚本
├── go.mod / go.sum
└── README.md
```

## 前置依赖

- **Go 1.25+**(due-main 要求)
- **protoc-gen-go**:`go install google.golang.org/protobuf/cmd/protoc-gen-go@latest`
- **Docker + docker-compose**(跑 Redis + Consul)
- **protoc.exe** 已自带(在 `Client/UnityProject/TestProject/Assets/Scripts/Fuel/.Common/ProtoTool/protoc.exe`)

## 跑通步骤

### 1. 起 Redis + Consul

```powershell
cd Server\GameServerGo\docker
docker-compose up -d
```

确认:

```powershell
docker ps
# 应该看到 testserver-redis 和 testserver-consul healthy

# Consul Web UI: 浏览器打开 http://127.0.0.1:8500
```

### 2. 生成 .pb.go

```powershell
cd Server\GameServerGo
.\gen_proto_go.bat
```

成功的话会看到类似:

```
[GO ] base.proto
[OK ] base.proto
[GO ] login/login.proto
[OK ] login/login.proto
...
Done. Total=10 Errors=0
Generated files under: ...\Server\GameServerGo\proto
```

### 3. 拉依赖

```powershell
cd Server\GameServerGo
go mod tidy
```

### 4. 启动两个进程

**终端 1 — Gate:**

```powershell
cd Server\GameServerGo
go run .\cmd\gate
```

预期日志:`gate listening on :3553 ...`

**终端 2 — Node:**

```powershell
cd Server\GameServerGo
go run .\cmd\node
```

预期日志:`node registered to consul ... codec: proto ...`

### 5. 验证 PING/PONG 链路

最快验证用 due 自带的 due-client-go(在 due 仓库的 example 里):

```bash
# 在 due-main 仓库内
go run .\examples\client  # 或对应路径
```

或者用你们 Unity 客户端连 `127.0.0.1:3553`,发一个 PING(ProtoCmds.PING = 4000,body = 当前毫秒时间戳),Node 会回 PONG(4001,body = client_time + server_time)。

**预期看到 Node 日志**:

```
PING cid=... uid=0 client_time=... -> server_time=...
```

## MsgId 编号约定

- 所有 MsgId 在 `internal/routeids/routeids.go` 里集中定义
- 数值必须跟 `Assets/Scripts/Generated/Proto/ProtoCmds.cs` 严格一致
- 改任何一边的值都要同步改另外两端

当前最大用到 `GetAnnouncementRsp = 10011`,由于 due 默认 Route 是 2 字节 int16(范围 -32768~32767),我们通过 `internal/packetsetup` 把 Route 强制成 4 字节,给未来扩展留 buffer。

## 跟 Unity 客户端的协议差异(待解决)

due 的 wire 格式跟 Unity 客户端的 `Fuel.NetFramework` 不直接兼容:

| 维度 | due | Fuel 客户端 |
| --- | --- | --- |
| 头 | size(4) + header(1) + route(2/4) + seq(2) + body | length(4) + cmdId(4) + body |
| 字节序 | BigEndian | BigEndian |
| 心跳 | wire 标记(header 高位置 1) | 应用层 PING/PONG |

要让两边互通,要么改 Unity 客户端按 due 格式解,要么在 Gate 前加一层适配把两种格式互转。当前骨架暂时不解决这个,等业务接 Login 时再做适配层。

## 数据层说明

骨架阶段数据层全部用内存实现(`internal/data/memory/`),进程重启数据丢失。

生产替换路径:

1. 实现 `internal/data/gorm.GormRepository[T]` 满足 `data.Repository[T]` 接口
2. 在 `cmd/node/main.go` 里改 DI 注册
3. 业务代码(handler)零改动

## 后续可扩展

- 加 LoginHandler(等 LoginReq 业务时填 `internal/handler/login.go`)
- 加更多 due 组件(NATS/Kafka 事件总线、RSA 加密、gRPC mesh)
- 加 Dockerfile 把 GameServerGo 本身容器化
- 加 GitHub Actions CI

## 已知问题 / TODO

- [ ] `internal/data/unitofwork.go` 的 `RepositoryOf[T]` 内存版会返回 nil,生产实现必须修
- [ ] 跟 Unity 客户端协议适配层
- [ ] docker-compose.yaml 没有 consul 的数据持久化(因为是 `-dev` 模式),重启 consul 数据丢失

## 配套文档

- 项目计划:`Server/GameServerGo_PLAN.md`
- due 框架源码:`Server/GoServer/due-main/`(只读参考)
- .proto 源:`Client/UnityProject/TestProject/Assets/Scripts/Fuel/.Common/ProtoTool/Proto/`
- Unity 客户端网络层:`Client/UnityProject/TestProject/Assets/Scripts/Fuel/NetFramework/`