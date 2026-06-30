// Package main 启动 Node 逻辑服。
//
// Node 负责:
//   - 注册业务 handler(目前只有 PingHandler)
//   - 处理 Gate 转发过来的客户端消息
//   - 把响应/推送通过 Gate 回给客户端
//
// Codec 默认是 protobuf(body 用 .proto 定义的消息)。
//
// 运行顺序:
//   1. cd Server/GameServerGo
//   2. gen_proto_go.bat   ← 先生成 .pb.go
//   3. go mod tidy
//   4. go run ./cmd/node
package main

import (
	"github.com/dobyte/due/v2"
	"github.com/dobyte/due/v2/cluster/node"
	"github.com/dobyte/due/locate/redis/v2"
	"github.com/dobyte/due/registry/consul/v2"

	"testserver/internal/handler"
	"testserver/internal/routeids"

	// 匿名导入:触发 packetsetup.init() 注册 4 字节 Route 的全局 Packer。
	_ "testserver/internal/packetsetup"
)

func main() {
	container := due.NewContainer()
	component := node.NewNode(
		node.WithLocator(redis.NewLocator()),     // 用户定位(Redis)
		node.WithRegistry(consul.NewRegistry()), // 服务注册(Consul)
		// WithCodec 默认就是 proto,无需显式设置
	)

	proxy := component.Proxy()

	// ---- 注册业务路由 ----
	proxy.AddRouteHandler(routeids.PING, handler.PingHandler)
	// proxy.AddRouteHandler(routeids.LOGIN_REQ, handler.LoginHandler) // TODO: 等 LoginHandler 实现后打开

	container.Add(component)
	container.Serve()
}