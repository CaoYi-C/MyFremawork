using System;
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
        /// 将消息编码为完整数据包字节。
        /// 返回的 byte[] 是新分配的，调用方无需也无法归还（无所有权/生命周期约定）。
        /// </summary>
        /// <param name="cmdId">消息命令号</param>
        /// <param name="body">Protobuf 序列化后的消息体（可为 null 或空数组）</param>
        /// <returns>完整数据包字节（含长度头）</returns>
        public static byte[] Encode(uint cmdId, byte[] body)
        {
            int bodyLen = body?.Length ?? 0;
            int length = CmdIdSize + bodyLen;
            int totalLen = HeaderLengthSize + length;

            byte[] packet = new byte[totalLen];

            // Length (big-endian int32)
            packet[0] = (byte)(length >> 24);
            packet[1] = (byte)(length >> 16);
            packet[2] = (byte)(length >> 8);
            packet[3] = (byte)length;

            // CmdId (big-endian uint32)
            packet[4] = (byte)(cmdId >> 24);
            packet[5] = (byte)(cmdId >> 16);
            packet[6] = (byte)(cmdId >> 8);
            packet[7] = (byte)cmdId;

            // Body
            if (body != null && bodyLen > 0)
            {
                Buffer.BlockCopy(body, 0, packet, TotalHeaderSize, bodyLen);
            }

            return packet;
        }

        /// <summary>
        /// 从字节缓冲区解码一个完整的数据包。
        /// Body 会被拷贝到一个独立的 byte[] 中以保证生命周期独立：
        /// 接收缓冲区会被 BeginReceive 复用并被后续数据覆盖，handler 在主线程上派发时
        /// 必须读到的不是已被污染的内存，所以这里必须拷一份。
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

            // Body 拷贝到独立 buffer
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

        // ---- Big-endian 读写工具（供 NetworkManager 拼 PING/PONG 简包使用） ----

        public static void WriteInt32BigEndian(byte[] dst, int offset, int value)
        {
            dst[offset]     = (byte)(value >> 24);
            dst[offset + 1] = (byte)(value >> 16);
            dst[offset + 2] = (byte)(value >> 8);
            dst[offset + 3] = (byte)value;
        }

        public static int ReadInt32BigEndian(byte[] src, int offset)
        {
            return (src[offset] << 24)
                 | (src[offset + 1] << 16)
                 | (src[offset + 2] << 8)
                 |  src[offset + 3];
        }

        public static void WriteInt64BigEndian(byte[] dst, int offset, long value)
        {
            dst[offset]     = (byte)(value >> 56);
            dst[offset + 1] = (byte)(value >> 48);
            dst[offset + 2] = (byte)(value >> 40);
            dst[offset + 3] = (byte)(value >> 32);
            dst[offset + 4] = (byte)(value >> 24);
            dst[offset + 5] = (byte)(value >> 16);
            dst[offset + 6] = (byte)(value >> 8);
            dst[offset + 7] = (byte)value;
        }

        public static long ReadInt64BigEndian(byte[] src, int offset)
        {
            return ((long)src[offset]     << 56)
                 | ((long)src[offset + 1] << 48)
                 | ((long)src[offset + 2] << 40)
                 | ((long)src[offset + 3] << 32)
                 | ((long)src[offset + 4] << 24)
                 | ((long)src[offset + 5] << 16)
                 | ((long)src[offset + 6] << 8)
                 |  (long)src[offset + 7];
        }
    }
}
