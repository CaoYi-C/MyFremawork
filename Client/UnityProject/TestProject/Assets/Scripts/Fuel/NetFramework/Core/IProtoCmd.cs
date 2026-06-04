using System;

namespace Fuel.NetFramework.Core
{
    /// <summary>
    /// 业务侧实现的命令号查找器（可选）。
    /// 如果不实现，NetworkManager 会回退到 <see cref="Attributes.ProtoCmdsLookup"/>
    /// 通过 ProtoCmds 类反射查找。
    /// </summary>
    public interface IProtoCmd
    {
        /// <summary>
        /// 通过泛型 T（protobuf 消息类型）查命令号
        /// </summary>
        uint GetCmdId<T>();

        /// <summary>
        /// 通过 Type 查命令号
        /// </summary>
        uint GetCmdId(Type type);

        /// <summary>
        /// 业务侧启动时调用一次，注册所有 T→cmdId 映射
        /// </summary>
        void RegisterAll();
    }
}
