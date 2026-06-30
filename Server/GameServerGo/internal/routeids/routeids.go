// Package routeids 定义了所有消息的 MsgId 常量。
//
// 数值必须跟 Unity 客户端和 C# 测试服的 ProtoCmds.cs 严格一致;
// 改任何一个值都要同步改另外两端。
//
// 命名规则:跟 .proto 里的 message 名一致(去掉 Req/Rsp/Push 后缀的不一致,
// 直接用 ProtoCmds 里的常量名)。
package routeids

// ---- base ----
const (
	IntTrace    = 1000
	StringTrace = 1001
)

// ---- error ----
const (
	ErrorInfo    = 2000
	ErrorMessage = 2001
)

// ---- attr ----
const (
	Attr = 3000
)

// ---- command(心跳) ----
const (
	PING = 4000
	PONG = 4001
	// GameTrace = 4002
)

// ---- item ----
const (
	Item         = 5000
	SmallItem    = 5001
	ItemChange   = 5002
	ItemChanges  = 5003
)

// ---- task ----
const (
	TaskCond      = 6000
	Task          = 6001
	ActiveRewards = 6002
)

// ---- acego ----
const (
	AcegoRegisterReq          = 7000
	AcegoRegisterRsp          = 7001
	AcegoLoginReq             = 7002
	AcegoLoginRsp             = 7003
	AcegoSendValidReq         = 7004
	AcegoSendValidRsp         = 7005
	AcegoCheckEmailReq        = 7006
	AcegoCheckEmailRsp        = 7007
	AcegoResetPwdReq          = 7008
	AcegoResetPwdRsp          = 7009
	AcegoLoginInvalidationPush = 7010
	AcegoInfo                 = 7011
	GetAcegoInfoOnlyServerReq = 7012
	GetAcegoInfoOnlyServerRsp = 7013
	GetAcegoUidOnlyServerReq  = 7014
	GetAcegoUidOnlyServerRsp  = 7015
)

// ---- admin ----
const (
	AdminRoleInfo        = 8000
	AdminGetRoleInfoReq  = 8001
	AdminGetRoleInfoRsp  = 8002
)

// ---- chat ----
const (
	GetChatTokenReq = 9000
	GetChatTokenRsp = 9001
	ChatTokenPush   = 9002
)

// ---- login ----
const (
	WhiteListOptReq     = 10000
	WhiteListOptRsp     = 10001
	CloseServerPush     = 10002
	LoginReq            = 10003
	LoginRsp            = 10004
	LogoutPush          = 10005
	IsVisitorReq        = 10006
	IsVisitorRsp        = 10007
	CheatSetFormalReq   = 10008
	CheatSetFormalRsp   = 10009
	GetAnnouncementReq  = 10010
	GetAnnouncementRsp  = 10011
)