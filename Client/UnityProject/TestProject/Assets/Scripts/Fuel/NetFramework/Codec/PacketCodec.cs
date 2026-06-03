using System;
using System.Buffers;
using System.IO;
using Fuel.NetFramework.Core;

namespace Fuel.NetFramework.Codec
{
    /// <summary>
    /// 数据包编解码器
    /// 包格式: [Length(4字节, big-endian)] [CmdId(4字节, big-endian)] [Body(N字节)]
    /// Length = CmdId(4) + Body.Length
    /// </summary>
    public static class PacketCodec
    {
        /// <summary>
        /// 长度字段占用的字节数
        /// </summary>
        public const int HeaderLengthSize = 4;

        /// <summary>
        /// CmdId 字段占用的字节数
        /// </summary>
        public const int CmdIdSize = 4;

        /// <summary>
        /// 包头总长度 (Length + CmdId)
        /// </summary>
        public const int TotalHeaderSize = HeaderLengthSize + CmdIdSize;

        public const int MaxPacketLength = 1024 * 1024;

        /// <summary>
        /// 共享的 ArrayPool 实例，给 Encode/Decode 复用字节数组
        /// </summary>
        private static readonly ArrayPool<byte> _pool = ArrayPool<byte>.Shared;

        /// <summary>
        /// 将消息编码为完整数据包字节
        /// 返回的 byte[] 是从 ArrayPool 租借的，调用方在使用完毕后应调用 <see cref="ReleasePacket"/> 归还。
        /// 包的"实际数据长度"为 <c>HeaderLengthSize + CmdIdSize + body.Length</c>。
        /// 注意：ArrayPool.Rent 会把数组向上取到 2 的幂次，所以 <c>buffer.Length</c> 可能比实际数据长度大。
        /// 调用方若需要确切的数据长度（例如 <see cref="Decode"/> 的 available 参数），请用
        /// <c>HeaderLengthSize + CmdIdSize + (body?.Length ?? 0)</c> 计算，而不是 buffer.Length。
        /// </summary>
        /// <param name="cmdId">消息命令号</param>
        /// <param name="body">Protobuf 序列化后的消息体</param>
        /// <returns>完整数据包字节（含长度头）</returns>
        public static byte[] Encode(uint cmdId, byte[] body)
        {
            int bodyLen = body?.Length ?? 0;
            int length = CmdIdSize + bodyLen;
            int totalLen = HeaderLengthSize + length;

            // 从池里租一块可能更大的 buffer，但返回的 byte[] 视图长度为 totalLen
            byte[] rented = _pool.Rent(totalLen);

            // Length (big-endian int32)
            rented[0] = (byte)(length >> 24);
            rented[1] = (byte)(length >> 16);
            rented[2] = (byte)(length >> 8);
            rented[3] = (byte)length;

            // CmdId (big-endian uint32)
            rented[4] = (byte)(cmdId >> 24);
            rented[5] = (byte)(cmdId >> 16);
            rented[6] = (byte)(cmdId >> 8);
            rented[7] = (byte)cmdId;

            // Body
            if (body != null && bodyLen > 0)
            {
                Buffer.BlockCopy(body, 0, rented, TotalHeaderSize, bodyLen);
            }

            return rented;
        }

        /// <summary>
        /// 归还通过 <see cref="Encode"/> 租借的字节数组回 ArrayPool
        /// </summary>
        public static void ReleasePacket(byte[] packet)
        {
            if (packet == null) return;
            _pool.Return(packet);
        }

        /// <summary>
        /// 从字节缓冲区解码一个完整的数据包
        /// Body 会被拷贝到一个独立的 byte[] 中以保证生命周期独立。
        /// 因为 TcpProtocol 会复用同一个 receive buffer，若不拷贝，主线程派发时 body 指向的内存
        /// 已经被下一帧 BeginReceive 覆盖，protobuf 反序列化就会读到脏数据。
        /// </summary>
        /// <param name="buffer">数据缓冲区</param>
        /// <param name="offset">起始偏移</param>
        /// <param name="available">可用字节数</param>
        /// <param name="packet">输出的数据包</param>
        /// <returns>消耗的字节数，数据不足时返回 0</returns>
        public static int Decode(byte[] buffer, int offset, int available, out Packet packet)
        {
            packet = null;

            // 至少需要 4 字节的 Length 头
            if (available < HeaderLengthSize)
                return 0;

            // 读取 Length (big-endian int32)
            int length = (buffer[offset] << 24)
                       | (buffer[offset + 1] << 16)
                       | (buffer[offset + 2] << 8)
                       | buffer[offset + 3];

            if (length < CmdIdSize || length > MaxPacketLength)
                throw new InvalidDataException($"Invalid packet length: {length}");

            // 检查数据是否完整
            if (available < HeaderLengthSize + length)
                return 0;

            // 读取 CmdId (big-endian uint32)
            uint cmdId = (uint)((buffer[offset + HeaderLengthSize] << 24)
                              | (buffer[offset + HeaderLengthSize + 1] << 16)
                              | (buffer[offset + HeaderLengthSize + 2] << 8)
                              | buffer[offset + HeaderLengthSize + 3]);

            // Body 拷贝到独立 buffer，避开 receive buffer 复用导致的脏数据问题
            int bodyLen = length - CmdIdSize;
            byte[] body;
            if (bodyLen > 0)
            {
                body = new byte[bodyLen];
                Buffer.BlockCopy(buffer, offset + TotalHeaderSize, body, 0, bodyLen);
            }
            else
            {
                body = Array.Empty<byte>();
            }

            packet = new Packet(cmdId, new ArraySegment<byte>(body));
            return HeaderLengthSize + length;
        }
    }
}
