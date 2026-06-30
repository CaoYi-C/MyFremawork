// Package packetsetup 统一配置 due 框架的全局 packet.Packer。
//
// 必须在 cmd/gate 和 cmd/node 的 main.go 里通过匿名 import 触发:
//
//	import _ "testserver/internal/packetsetup"
//
// 这样两个进程都会使用相同的 packer 配置。
package packetsetup

import "github.com/dobyte/due/v2/packet"

func init() {
	// 默认 packer 的 Route 字段是 2 字节 int16,MsgId 超过 32767 会被解释成负数。
	// 我们这边 MsgId 已经用到 10001+,以后肯定超,所以直接 4 字节 Route(int32),
	// 给未来留 buffer。
	packet.SetPacker(packet.NewPacker(
		packet.WithRouteBytes(4),
		packet.WithByteOrder(packet.BigEndian),
	))
}