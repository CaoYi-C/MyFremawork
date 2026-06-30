package handler

import (
	"github.com/dobyte/due/v2/cluster/node"
)

// LoginHandler 是登录业务的占位 handler。
//
// 对应 ProtoCmds.LOGIN_REQ = 10003 / LOGIN_RSP = 10004。
//
// 待完成的工作(等加登录业务时再实现):
//
//  1. 解析 LoginReq (testserver/proto/loginPB.LoginReq)
//  2. 走 internal/data 的 Repository 查/建玩家记录
//  3. 校验密码、生成 session token
//  4. 绑定 UID 到当前连接: ctx.BindUID(uid)
//  5. 构造 LoginRsp 返回
//
// 注册方式(在 cmd/node/main.go):
//
//	proxy.AddRouteHandler(routeids.LOGIN_REQ, handler.LoginHandler)
//
// 当前是个空壳,不会做任何业务处理——真正接 LoginReq 时替换这里。
func LoginHandler(_ node.Context) {
	// TODO: implement
}