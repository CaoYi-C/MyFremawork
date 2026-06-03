// 与 Unity 工程同名的 Packet 类，仅用于非 Unity 烟测。
// 不要在 Unity 工程内引用此文件。
using System;

namespace Fuel.NetFramework.Core
{
    public class Packet
    {
        public uint CmdId { get; set; }
        public ArraySegment<byte> Body { get; set; }
        public Packet() { }
        public Packet(uint cmdId, ArraySegment<byte> body)
        {
            CmdId = cmdId;
            Body = body;
        }
    }
}
