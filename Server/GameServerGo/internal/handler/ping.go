// Package handler 包含所有的 due Node 业务消息处理器。
//
// 当前实现:
//   - PingHandler   PING/PONG 链路验证(对应 ProtoCmds.PING = 4000)
//
// 后续可加:
//   - LoginHandler  登录(对应 ProtoCmds.LOGIN_REQ = 10003)
//   - ChatHandler   聊天(对应 ProtoCmds.GetChatTokenReq = 9000)
//   - ...
//
// 每个 handler 必须按 due 的签名:
//
//	func(ctx node.Context) { ... }
//
// 注册方式(在 cmd/node/main.go):
//
//	proxy.AddRouteHandler(routeids.PING, handler.PingHandler)
package handler

import (
	"time"

	"github.com/dobyte/due/v2/cluster/node"
	"github.com/dobyte/due/v2/log"

	commonPB "testserver/proto/commonPB"
)

// PingHandler 处理客户端 PING,回 PONG。
//
// Wire 格式(对齐 Unity 客户端和 C# mock):
//   - 请求:PING  body = int64 client_time (毫秒)
//   - 响应:PONG  body = int64 client_time + int64 server_time (毫秒)
//
// 注意:本文件依赖 testserver/proto/commonPB 包,
// 编译前必须先运行根目录的 gen_proto_go.bat 生成 .pb.go。
func PingHandler(ctx node.Context) {
	req := &commonPB.PING{}
	if err := ctx.Parse(req); err != nil {
		log.Errorf("parse PING failed: %v", err)
		return
	}

	clientTime := req.GetClientTime()
	serverTime := time.Now().UnixMilli()

	log.Infof("PING cid=%d uid=%d client_time=%d -> server_time=%d",
		ctx.CID(), ctx.UID(), clientTime, serverTime)

	if err := ctx.Response(&commonPB.PONG{
		ClientTime: clientTime,
		ServerTime: serverTime,
	}); err != nil {
		log.Errorf("send PONG failed: %v", err)
	}
}