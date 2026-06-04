using System;
using Google.Protobuf;
using Google.Protobuf.Reflection;

namespace Fuel.NetFramework.SmokeTest
{
    /// <summary>
    /// 最小可用的 IMessage stub — 只够让 MessageDispatcher 的 Register/ParseFrom
    /// 走通，具体字段不解析。独立烟测不需要真正序列化业务字段。
    /// 只需要 IMessage（不是 IMessage&lt;T&gt;）就够了——CacheRequest API 收 IMessage。
    /// </summary>
    internal sealed class StubMessage : IMessage
    {
        public int Marker { get; }

        public StubMessage() : this(0) { }
        public StubMessage(int marker) { Marker = marker; }

        public MessageDescriptor Descriptor => null;
        public int CalculateSize() => 0;
        public void MergeFrom(CodedInputStream input) { /* stub: 不解析 */ }
        public void WriteTo(CodedOutputStream output) { /* stub: 不写入 */ }
    }
}
