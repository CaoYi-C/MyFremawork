using System;
using System.Collections.Generic;
using System.Reflection;
using Fuel.NetFramework.Core;
using Fuel.NetFramework.Dispatcher;
using UnityEngine;

namespace Fuel.NetFramework.Attributes
{
    /// <summary>
    /// 启动时扫描所有已加载程序集，收集带 [NetMessageHandler] 特性标记的静态方法，
    /// 把它们注册到 MessageDispatcher。
    ///
    /// 用法（业务侧）：
    ///   1. 标记 [NetMessageHandler(typeof(LoginRsp))] static void OnLoginRsp(LoginRsp msg) { ... }
    ///   2. 启动时调一次：NetMessageHandlerScanner.ScanAndRegister(NetworkManager.Instance.Dispatcher);
    ///   3. 如果有 hot-update DLL，加载后再次调用 ScanAndRegister 把新 assembly 的 handler 注入。
    /// </summary>
    public static class NetMessageHandlerScanner
    {
        public static int ScanAndRegister(MessageDispatcher dispatcher)
        {
            if (dispatcher == null)
            {
                Debug.LogError("[NetMessageHandlerScanner] Dispatcher is null. Abort.");
                return 0;
            }

            int registered = 0;
            foreach (var assembly in AppDomain.CurrentDomain.GetAssemblies())
            {
                try
                {
                    registered += ScanAssembly(assembly, dispatcher);
                }
                catch (Exception ex)
                {
                    Debug.LogError($"[NetMessageHandlerScanner] Failed to scan {assembly.GetName().Name}: {ex.Message}");
                }
            }

            Debug.Log($"[NetMessageHandlerScanner] Scanned and registered {registered} [NetMessageHandler] method(s).");
            return registered;
        }

        public static int ScanAssembly(Assembly assembly, MessageDispatcher dispatcher)
        {
            if (assembly == null || dispatcher == null) return 0;

            int registered = 0;
            Type[] types;
            try
            {
                types = assembly.GetTypes();
            }
            catch (ReflectionTypeLoadException ex)
            {
                // 部分类型加载失败（比如 hot-update DLL 引用了未加载的依赖），
                // 跳过 loader exceptions 继续处理已加载的
                types = ex.Types;
            }

            foreach (var type in types)
            {
                if (type == null) continue;

                MethodInfo[] methods;
                try
                {
                    methods = type.GetMethods(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static);
                }
                catch
                {
                    continue;
                }

                foreach (var method in methods)
                {
                    var attr = method.GetCustomAttribute<NetMessageHandlerAttribute>(false);
                    if (attr == null) continue;

                    uint cmdId = attr.MsgId;
                    if (cmdId == 0)
                    {
                        Debug.LogWarning(
                            $"[NetMessageHandlerScanner] Skipping {type.FullName}.{method.Name}: MsgId is 0 (ProtoCmds not loaded yet?). " +
                            "Call ProtoCmdsLookup.Initialize(typeof(ProtoCmds)) before scanning if you need hot-update-before-scan.");
                        continue;
                    }
                    // TODO: 字段 _cachedMsgId / _cached 暂未在 NetMessageHandlerAttribute 中声明，
                    // 暂时注释。功能上：cmdId 已存为本地变量，下面的注册逻辑直接使用即可。
                    // attr._cachedMsgId = cmdId;
                    // attr._cached = true;

                    // 把方法注册到 dispatcher — 用 generic Register 路径反射调
                    if (attr.ReqMsgType != null)
                    {
                        // Request-Response 模式
                        RegisterReqRsp(dispatcher, cmdId, attr.ReqMsgType, attr.MsgType, method);
                    }
                    else
                    {
                        // 单向 Push/响应
                        RegisterOneWay(dispatcher, cmdId, attr.MsgType, method);
                    }
                    registered++;
                }
            }

            return registered;
        }

        // 反射调 MessageDispatcher.Register<TResp>(uint, Action<TResp>) — 用 Delegate.CreateDelegate
        // 比 MethodInfo.Invoke 性能好，且会做参数类型校验
        private static void RegisterOneWay(MessageDispatcher dispatcher, uint cmdId, Type msgType, MethodInfo method)
        {
            try
            {
                var actionType = typeof(Action<>).MakeGenericType(msgType);
                var del = Delegate.CreateDelegate(actionType, method);

                // dispatcher.Register<TResp>(uint, Action<TResp>)
                var registerMethod = typeof(MessageDispatcher).GetMethod(
                    "Register", BindingFlags.Public | BindingFlags.Instance, null,
                    new[] { typeof(uint), actionType }, null);

                if (registerMethod == null)
                {
                    Debug.LogError($"[NetMessageHandlerScanner] Register<{msgType.Name}>(uint, Action<{msgType.Name}>) not found on MessageDispatcher.");
                    return;
                }
                registerMethod.Invoke(dispatcher, new object[] { cmdId, del });
            }
            catch (Exception ex)
            {
                Debug.LogError($"[NetMessageHandlerScanner] Failed to register one-way handler {method.DeclaringType?.FullName}.{method.Name}: {ex.Message}");
            }
        }

        // 反射调 MessageDispatcher.Register<TReq, TRsp>(uint, Action<TReq, TRsp>)
        private static void RegisterReqRsp(MessageDispatcher dispatcher, uint cmdId, Type reqType, Type rspType, MethodInfo method)
        {
            try
            {
                var actionType = typeof(Action<,>).MakeGenericType(reqType, rspType);
                var del = Delegate.CreateDelegate(actionType, method);

                var registerMethod = typeof(MessageDispatcher).GetMethod(
                    "Register", BindingFlags.Public | BindingFlags.Instance, null,
                    new[] { typeof(uint), actionType }, null);

                if (registerMethod == null)
                {
                    Debug.LogError($"[NetMessageHandlerScanner] Register<{reqType.Name},{rspType.Name}>(uint, Action<{reqType.Name},{rspType.Name}>) not found on MessageDispatcher.");
                    return;
                }
                registerMethod.Invoke(dispatcher, new object[] { cmdId, del });
            }
            catch (Exception ex)
            {
                Debug.LogError($"[NetMessageHandlerScanner] Failed to register req-rsp handler {method.DeclaringType?.FullName}.{method.Name}: {ex.Message}");
            }
        }
    }
}
