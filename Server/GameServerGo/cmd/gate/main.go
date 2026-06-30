// Package main 启动 Gate 网关服。
//
// Gate 负责:
//   - 接受 Unity 客户端的 TCP 连接(默认 :3553)
//   - 通过 Redis 定位用户所在的 Node
//   - 转发客户端消息到 Node
//   - 把 Node 的响应/推送转发回客户端
//
// 不在 Gate 上注册业务 handler(业务在 Node)。
package main

import (
	"github.com/dobyte/due/v2"
	"github.com/dobyte/due/v2/cluster/gate"
	"github.com/dobyte/due/locate/redis/v2"
	"github.com/dobyte/due/network/tcp/v2"
	"github.com/dobyte/due/registry/consul/v2"

	// 匿名导入:触发 packetsetup.init() 注册 4 字节 Route 的全局 Packer。
	_ "testserver/internal/packetsetup"
)

func main() {
	container := due.NewContainer()
	container.Add(gate.NewGate(
		gate.WithServer(tcp.NewServer()),     // 客户端走 TCP 协议
		gate.WithLocator(redis.NewLocator()), // 用户定位(Redis)
		gate.WithRegistry(consul.NewRegistry()), // 服务注册(Consul)
	))
	container.Serve()
}