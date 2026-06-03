using System;

namespace Fuel.NetFramework.Core
{
    public interface IProtoCmd
    {
        uint GetCmdId<T>();
        uint GetCmdId(Type type);
        void RegisterAll();
    }
}