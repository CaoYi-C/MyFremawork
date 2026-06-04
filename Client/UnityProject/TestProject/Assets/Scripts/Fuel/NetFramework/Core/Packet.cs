using System;

namespace Fuel.NetFramework.Core
{
    /// <summary>
    /// 网络数据包模型
    /// 包格式: [Length(4字节)] [CmdId(4字节)] [Body(N字节)]
    /// </summary>
    public class Packet
    {
        /// <summary>
        /// 消息命令号 (对应 ProtoCmds)
        /// </summary>
        public uint CmdId { get; }

        /// <summary>
        /// Protobuf 序列化后的消息体。
        /// 由 <see cref="Codec.PacketCodec.Decode"/> 拷贝到独立 buffer 而非引用 receive buffer，
        /// 因此 handler 在主线程派发时仍可安全访问。
        /// </summary>
        public ArraySegment<byte> Body { get; }

        public Packet(uint cmdId, ArraySegment<byte> body)
        {
            CmdId = cmdId;
            Body = body;
        }
    }
}
