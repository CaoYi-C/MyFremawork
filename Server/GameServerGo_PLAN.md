# GameServerGo 项目搭建计划

> 目标:在 `Server/GameServerGo/` 搭建一个基于 due 框架的 Go 游戏服务器骨架,
> 能从你们现有 `.proto` 源生成 Go 代码,跑起 Gate + Node,
> 处理至少一条 PING/PONG 消息。

---

## 1. 范围

### IN (本计划要做)

- 在 `Server/GameServerGo/` 创建一个**独立 Go 项目**(新 module)
- 用 `github.com/dobyte/due/v2` 作依赖,不复用 due-main 源码
- 实现 Gate 和 Node 两个进程的最小骨架
- 写一个 PING/PONG handler,验证从客户端→Gate→Node→回客户端的链路
- 写 `gen_proto_go.bat` 把现有 `.proto` 源生成 `.pb.go`
- 写 README 说明怎么跑

### OUT (本计划**不做**)

- ❌ 不改 `Server/GoServer/due-main/` 任何东西(它是只读的参考)
- ❌ 不改任何 `.proto` 源文件(保持 `testserver/proto/xxxPB` 不动)
- ❌ 不实现完整业务(只 PING/PONG)
- ❌ 不部署上生产(Redis/Consul 必须,单机本地跑即可)
- ❌ 不接真实数据库(数据层骨架用内存实现,跟 C# mock server 一致;GORM/Mongo 等以后再加)
- ❌ 不解决 Unity 客户端协议和 due 协议不互通的问题(那是独立话题)

---

## 2. 环境侦察结论

| 项目 | 现状 | 影响 |
| --- | --- | --- |
| Go 工具链 | **未安装** | 必须先装,且要 **Go 1.25+**(due-main `go.mod` 要求) |
| `protoc-gen-go` | **未安装** | 必须 `go install google.golang.org/protobuf/cmd/protoc-gen-go@latest` |
| `protoc.exe` | ✅ 已在 `ProtoTool/protoc.exe` | 直接复用 |
| Docker / docker-compose | **未知**,本机没跑过 due-main 的 compose | 必须有,否则 Redis/Consul 起不来 |
| due 注册中心 | **只支持 Consul / Etcd / Nacos** | 必须 Docker 跑其中一个 |
| due 用户定位 | **只支持 Redis** | 必须 Docker 跑 Redis |

**结论:due 框架本身不支持 in-memory / 单进程模式**。要跑 Gate + Node 必然需要 Redis + 至少一个注册中心(Consul 最简单)。

---

## 3. 关键决策(我已选定,你随时推翻)

| 决策点 | 选择 | 理由 |
| --- | --- | --- |
| **Module 名** | `testserver` | 你指定;**所有 `.proto` 的 `option go_package = "p3server/..."` 要改成 `testserver/..."`**(10 个文件,阶段 A 一次性改完) |
| **仓库结构** | 单 repo 两个 binary(`cmd/gate/`、`cmd/node/`)**不合并** | 标准 Go layout,以后想横向扩(多 Node 节点)直接起多个进程 |
| **网络协议** | TCP(`network/tcp/v2`) | 跟你们 Unity 客户端 + C# mock server 同协议族,方便后续做适配层 |
| **编解码** | Protobuf(`encoding/proto/v2`) | 跟客户端 Protobuf 对齐,body 序列化用同一份 .proto 定义 |
| **注册中心** | **Consul(默认推荐),可换 Etcd/Nacos** | 下面 §10 有对比,简单说:Consul 单二进制最简单;详见对比章节 |
| **MsgId 宽度** | 4 字节 Route | 你们 ProtoCmds 最大到 10011,留 buffer 给以后扩展 |
| **首个 handler** | PING/PONG(4000/4001) | 链路最小验证 |

---

## 4. 目标目录结构

```
Server/GameServerGo/                          ← 本计划要创建的根
├── README.md                                  跑通指南
├── go.mod                                     module testserver, require due v2
├── go.sum                                     (go mod tidy 后生成)
├── .gitignore                                 忽略 proto/、*.exe
├── gen_proto_go.bat                           把 .proto 生成 .pb.go 的脚本
├── cmd/
│   ├── gate/main.go                           Gate 进程入口
│   └── node/main.go                           Node 进程入口
├── internal/
│   ├── routeids/routeids.go                   MsgId 常量表(对齐 Unity ProtoCmds)
│   ├── data/                                  数据层抽象(参照 C# mock server)
│   │   ├── entity.go                          Entity 接口
│   │   ├── repository.go                      Repository[T] 接口
│   │   ├── unitofwork.go                      UnitOfWork 接口
│   │   └── memory/                            内存实现(开发期)
│   │       ├── memory_repository.go
│   │       └── memory_unitofwork.go
│   └── handler/
│       ├── ping.go                            PING/PONG handler(不依赖 data)
│       └── login.go                           占位,先写空 handler
├── proto/                                     ← 跑 bat 后生成,先 .gitignore
│   ├── base.pb.go
│   ├── error.pb.go
│   ├── login/login.pb.go
│   ├── common/command.pb.go
│   └── ... (跟 .proto 源镜像)
├── etc/                                       due 配置(可放端口、连接信息)
│   ├── gate.yaml
│   └── node.yaml
└── docker/
    └── docker-compose.yaml                    精简版,只起 redis + consul
```

---

## 5. 核心代码骨架预览

### `go.mod`

```go
module testserver

go 1.25

require (
    github.com/dobyte/due/v2 v2.3.2
    google.golang.org/protobuf v1.36.6
)
```

### `internal/routeids/routeids.go`

```go
package routeids

// 跟 Assets/Scripts/Generated/Proto/ProtoCmds.cs 对齐
const (
    UNKNOWN         = 0
    PING            = 4000
    PONG            = 4001
    LOGIN_REQ       = 10003
    LOGIN_RSP       = 10004
    LOGOUT_PUSH     = 10005
    // ... 按需补
)
```

### `internal/handler/ping.go`

```go
package handler

import (
    "github.com/dobyte/due/v2/cluster/node"
    "github.com/dobyte/due/v2/log"
    "testserver/internal/routeids"
)

func PingHandler(ctx node.Context) {
    log.Infof("got PING, cid=%d uid=%d", ctx.Conn().ID(), ctx.Conn().UID())
    ctx.Response(map[string]any{
        // 或用 Protobuf body,取决于 Codec 配置
        "pong": true,
    })
}
```

### `cmd/node/main.go`(最简)

```go
package main

import (
    "github.com/dobyte/due/v2"
    "github.com/dobyte/due/v2/cluster/node"
    "github.com/dobyte/due/encoding/proto/v2"
    "github.com/dobyte/due/locate/redis/v2"
    "github.com/dobyte/due/registry/consul/v2"
    "testserver/internal/handler"
    "testserver/internal/routeids"
)

func main() {
    container := due.NewContainer()
    component := node.NewNode(
        node.WithLocator(redis.NewLocator()),
        node.WithRegistry(consul.NewRegistry()),
        node.WithCodec(proto.NewCodec()),
        node.WithRouteBytes(4),
    )
    component.Proxy().Router().AddRouteHandler(routeids.PING, false, handler.PingHandler)
    container.Add(component)
    container.Serve()
}
```

### `cmd/gate/main.go`(最简)

```go
package main

import (
    "github.com/dobyte/due/v2"
    "github.com/dobyte/due/v2/cluster/gate"
    "github.com/dobyte/due/encoding/proto/v2"
    "github.com/dobyte/due/locate/redis/v2"
    "github.com/dobyte/due/network/tcp/v2"
    "github.com/dobyte/due/registry/consul/v2"
)

func main() {
    container := due.NewContainer()
    container.Add(gate.NewGate(
        gate.WithServer(tcp.NewServer()),
        gate.WithLocator(redis.NewLocator()),
        gate.WithRegistry(consul.NewRegistry()),
    ))
    container.Serve()
}
```

### `gen_proto_go.bat`

```bat
@echo off
setlocal
set "PROTO_ROOT=<绝对路径到 ProtoTool\Proto>"
set "OUT_ROOT=%~dp0proto"
set "PROTOC_EXE=<绝对路径到 ProtoTool\protoc.exe>"

if not exist "%OUT_ROOT%" mkdir "%OUT_ROOT%"

for /r "%PROTO_ROOT%" %%F in (*.proto) do (
    echo [GO ] "%%F"
    "%PROTOC_EXE%" --proto_path="%PROTO_ROOT%" --go_out="%OUT_ROOT%" --go_opt=paths=source_relative "%%F"
    if errorlevel 1 ( echo [ERR] %%F ) else ( echo [OK ] %%F )
)
endlocal
```

---

## 6. 执行步骤(分两阶段)

### 阶段 A:我现在写(不依赖 Go 工具链)

1. 建 `Server/GameServerGo/` 目录树
2. 写 `go.mod`、`go.sum` 占位
3. 写 `cmd/gate/main.go`、`cmd/node/main.go`
4. 写 `internal/routeids/routeids.go`、`internal/handler/ping.go`
5. 写 `gen_proto_go.bat`、`docker/docker-compose.yaml`、`.gitignore`
6. 写 `README.md`(说明怎么跑、怎么验)

### 阶段 B:你来做(需要 Go + Docker)

1. 安装 Go 1.25+(到 https://go.dev/dl/)
2. `go install google.golang.org/protobuf/cmd/protoc-gen-go@latest`
3. `cd Server/GameServerGo && go mod tidy`
4. `gen_proto_go.bat`(路径在 bat 里写死)
5. `cd docker && docker-compose up -d redis consul`
6. 终端 1:`cd cmd/gate && go run main.go`
7. 终端 2:`cd cmd/node && go run main.go`
8. 用 due-client-go 或 Unity 客户端连 Gate 发 PING,看日志

---

## 7. 验证 / 验收

满足以下算"骨架跑通":

- ☐ `go mod tidy` 成功(无 missing / 不兼容)
- ☐ `gen_proto_go.bat` 产出至少 `proto/login/login.pb.go`
- ☐ Gate 日志显示 `[ws/tcp] listening on 0.0.0.0:3553`(或你配的端口)
- ☐ Node 日志显示 `Node ... Codec: proto ... ready`
- ☐ due-client-go 发 PING(任意 message) → Node 收到 → 回 PONG(或自定义 body)
- ☐ `docker ps` 显示 redis + consul 两个容器 healthy

跑通后可以再扩展:
- 加 LoginHandler(走 `testserver/proto/login` 包)
- 写 `internal/router/router.go` 把所有 handler 注册集中起来
- 加 Dockerfile 把 GameServerGo 本身容器化

---

## 8. 不做的"伏笔"(以后再说)

| 议题 | 原因 |
| --- | --- |
| Unity 客户端协议 vs due 协议互通 | 两个协议层不一样,需要适配层或客户端改协议格式,独立工作量 |
| 真正业务 handler(登录/聊天/物品/任务) | 等骨架跑通后再做 |
| AOT 编译 / 性能调优 | 骨架先跑起来再说 |

---

## 9. 注册中心选型对比(Etcd / Nacos / Consul)

due 框架三者都支持。下面从你的"测试项目"角度对比:

### 三个候选的核心差异

| 维度 | **Consul** | **Etcd** | **Nacos** |
| --- | --- | --- | --- |
| 出品 | HashiCorp(Vagrant/Terraform 一家) | CNCF(K8s 同门) | Alibaba |
| 语言/运行时 | Go(单二进制,启动飞快) | Go(单二进制,启动飞快) | **Java**(要 JVM,内存占用大,启动慢) |
| 主要定位 | 服务发现 + 健康检查 + 多 DC | 分布式 KV 存储 | 服务发现 + **配置中心** |
| 一致性协议 | Raft(强一致) | Raft(强一致) | **可切**:Raft(CP)或自研 Distro(AP) |
| 健康检查 | ✅ 内置 HTTP/TCP/gRPC 检查 | ⚠️ 弱(主要靠 TTL/lease) | ✅ 内置 HTTP/TCP 检查 |
| KV 存储 | ✅ 有 | ✅ 强项(就是 KV) | ✅ 有 |
| 配置中心(Push) | ❌ 没,只能 KV watch | ⚠️ 半成品(只 watch 没历史) | ✅ **专业级**(带 namespace/版本/灰度) |
| 多数据中心 | ✅ **天生**(WAN Federation) | ❌ 不支持 | ❌ 不支持 |
| 服务网格 | ⚠️ 有 Consul Connect 但偏弱 | ❌ 没 | ❌ 没 |
| Docker 启动命令 | `consul agent -dev` | `etcd` | 要起 JVM 容器 |
| 镜像大小(alpine) | ~80MB | ~50MB | **~400MB** |
| 中文文档 | 中等 | 少(英文为主) | **多**(阿里主力推) |
| 跟 K8s 集成 | 一般 | **天衣无缝**(K8s 自己就用 etcd) | 一般 |
| 跟 Spring Cloud 集成 | 一般 | 一般 | **天衣无缝** |

### 跟你场景的对位

| 你的场景 | 关键诉求 | 最匹配 |
| --- | --- | --- |
| 现在:跑通 due 骨架 | 起得快、配置少、跑得动 | **Consul**(镜像小,`consul agent -dev` 一行起) |
| 以后:可能要上 K8s | 原生集成 | **Etcd** |
| 以后:可能用 Spring Cloud mesh 或要配置中心 | 多合一 | **Nacos** |
| 永远单机/单 DC 测试 | 简单 | **Consul** |

### 我的推荐

**先 Consul**。理由:
1. 你这个项目叫 `testserver`,目标是"跑起来",不是"上生产"
2. Consul 是 due 文档里 example 最完整的(README 默认就是 Consul)
3. 镜像小、启动快、配置项少,Windows Docker 起容器秒开
4. 后期想换 Etcd/Nacos,due 接口一样,改 import + 配置就行,业务代码零改动

**唯一可能动摇的情况**:
- 你团队后面要上 K8s → 直接 Etcd
- 你团队后面要接 Spring Cloud 那一套 → 直接 Nacos

### 切换成本对比

| 切换路径 | 改的东西 |
| --- | --- |
| Consul → Etcd | 改 2 个 import + 2 处 `consul.NewRegistry()` 换成 `etcd.NewRegistry()`,业务代码不动 |
| Consul → Nacos | 改 2 个 import + 2 处换 `nacos.NewRegistry()`,可能要加 namespace 配置 |
| 任意 → 任意 | 大约 5 行代码差异,1 小时工作量 |

---

## 10. 数据层设计(对照 C# mock server 的 Repository 模式)

### due 框架本身**没有 DB 模块**

我扫了 due-main 顶层目录:

```
due-main/
├── cache/      ← Redis/Memcache(只是 KV 缓存,有 TTL,非持久化)
├── lock/       ← Redis/Memcache 分布式锁
├── locate/     ← Redis 用户位置(uid → gate)
├── registry/   ← 服务发现
├── config/     ← 配置中心
├── eventbus/   ← 事件总线
├── transport/  ← 节点间 RPC(grpc/rpcx)
├── network/    ← 客户端协议(tcp/kcp/ws)
├── cluster/    ← gate/node/mesh/client
├── encoding/   ← json/yaml/toml/xml/proto/msgpack
├── log/        ← 日志
└── ...

// 没有 db/  database/  sql/  orm/  mysql/  postgres/  mongo/
```

due 提供的数据相关模块**只到缓存层**,不涉及任何持久化 DB。**数据库完全由业务自己接**。

### 跟 C# mock server 的对位

你们 C# mock server 的数据层架构是这个项目骨架要复刻的范式:

```
Server/C#Server/TestTcpServer/TestTcpServer/Data/
├── Abstractions/
│   ├── IEntity.cs         ← 实体基接口
│   ├── IRepository<T>.cs  ← 仓储接口
│   └── IUnitOfWork.cs     ← 工作单元(跨表事务)
└── InMemory/
    ├── InMemoryRepository.cs
    └── InMemoryUnitOfWork.cs
```

Go 这边对称写一份:

```
internal/data/
├── entity.go              ← Entity interface
├── repository.go          ← Repository[T] interface
├── unitofwork.go          ← UnitOfWork interface
└── memory/
    ├── memory_repository.go     ← 用 sync.Map 实现
    └── memory_unitofwork.go
```

### 接口定义预览

```go
// internal/data/entity.go
package data

type Entity interface {
    GetID() any  // comparable ID,推荐 int64
}

// internal/data/repository.go
package data

type Repository[T Entity] interface {
    Insert(ctx context.Context, entity T) error
    Update(ctx context.Context, entity T) error
    Remove(ctx context.Context, id any) error
    FindOne(ctx context.Context, id any) (T, error)
    FindMany(ctx context.Context, ids ...any) ([]T, error)
    FindAll(ctx context.Context) ([]T, error)
    Count(ctx context.Context) (int64, error)
}

// internal/data/unitofwork.go
package data

type UnitOfWork interface {
    Repository[T Entity]() Repository[T]
    Begin(ctx context.Context) (UnitOfWork, error)
    Commit() error
    Rollback() error
}
```

### 为什么骨架阶段先用内存实现

| 阶段 | 数据层 | 理由 |
| --- | --- | --- |
| **阶段 A(本计划)** | `MemoryRepository[T]` 用 `sync.Map` | 跟 C# mock 一致;零外部依赖;PING/PONG 不需要数据层,但骨架要先把接口和内存实现准备好 |
| 阶段 B(加 LoginHandler 时) | 还是内存 | 让 LoginHandler 跑通,验证数据层接口够不够用 |
| 生产前 | GORM 或 mongo-driver | 加一个 `GormRepository[T]` / `MongoRepository[T]` 实现相同接口,handler 改 DI 注册即可 |

### Go 端 ORM 选项(以后选)

| 库 | 类型 | 适合场景 | 推荐度 |
| --- | --- | --- | --- |
| **GORM v2** | 关系型 ORM(MySQL/PostgreSQL/SQLite) | 传统游戏服、SQL 思维、需要事务 | ⭐⭐⭐⭐⭐(首选) |
| **sqlx** | 轻量 SQL 增强 | 想自己写 SQL,不要 ORM 重型 | ⭐⭐⭐ |
| **ent** | 类型安全 ORM(Facebook 出) | 复杂关系图、代码生成风格 | ⭐⭐⭐ |
| **mongo-driver** | MongoDB 官方驱动 | 文档型、半结构化数据 | ⭐⭐⭐⭐(如果选 MongoDB) |
| **go-redis** | Redis 驱动 | 已经在 due 的 `cache/redis` 里用了 | 缓存,不是 DB |

### 跟 due 的 cache 模块配合

业务经常的用法是:**DB 持久化 + Redis 缓存**

```go
// 伪代码
func (h *LoginHandler) HandleLogin(req LoginReq) (LoginRsp, error) {
    // 1. 先查 Redis 缓存
    if cached, err := cache.Get("player:" + uid); err == nil {
        return LoginRsp{Player: cached.(*Player)}, nil
    }
    // 2. 缓存未命中查 DB
    player, err := h.repo.FindOne(ctx, uid)
    if err != nil { return nil, err }
    // 3. 写回缓存
    cache.Set("player:" + uid, player, 5*time.Minute)
    return LoginRsp{Player: player}, nil
}
```

due 的 `cache/redis` 模块已经在那里了,以后直接 `cache.Get/Set` 就行,不用自己拼 redis client。

---

## 11. Next Step

你看完这个计划后:

- **同意** → 我按阶段 A 一次性写完所有文件,你再装 Go + Docker 跑阶段 B
- **想调整**(比如想用 Etcd 不用 Consul、或想先加 LoginHandler)→ 告诉我哪条
- **想先讨论某一处**(比如 due 的具体 option 怎么写、protobuf Codec 怎么注入)→ 挑出来单聊