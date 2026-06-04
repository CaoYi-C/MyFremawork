namespace Fuel.NetFramework.Protocol
{
    /// <summary>
    /// 协议工厂，根据协议类型创建对应的 IProtocol 实例
    /// 扩展新协议时只需在 switch 中添加对应分支并实现 IProtocol
    /// </summary>
    public static class ProtocolFactory
    {
        public static IProtocol Create(ProtocolType protocolType)
        {
            switch (protocolType)
            {
                case ProtocolType.TCP:
                    return new TcpProtocol();

                // ---- 以下为占位 ----
                // 选定 WebSocket / KCP 前请先实现对应的 ProtocolType 实现类并去掉注释，
                // 不要在生产环境选择未实现的协议 — 会直接抛 ArgumentException。
                //
                // case ProtocolType.WebSocket:
                //     return new WebSocketProtocol();
                // case ProtocolType.KCP:
                //     return new KcpProtocol();

                default:
                    throw new System.ArgumentException(
                        $"Unsupported protocol type: {protocolType}. " +
                        $"WebSocket/KCP are not yet implemented — see ProtocolFactory.");
            }
        }
    }
}
