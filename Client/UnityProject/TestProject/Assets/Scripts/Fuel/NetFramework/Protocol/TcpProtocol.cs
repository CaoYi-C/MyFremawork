using System;
using System.Collections.Concurrent;
using System.Net;
using System.Net.Sockets;
using Fuel.NetFramework.Codec;
using Fuel.NetFramework.Core;
using UnityEngine;
using SocketProtocolType = System.Net.Sockets.ProtocolType;

namespace Fuel.NetFramework.Protocol
{
    /// <summary>
    /// TCP 协议实现
    /// 基于 System.Net.Sockets.Socket，异步收发，自动处理粘包/拆包
    /// 接收缓冲区按需倍增（growable），最大不超过 <see cref="Codec.PacketCodec.MaxPacketLength"/> + 头长度
    /// </summary>
    public class TcpProtocol : IProtocol
    {
        private const int InitialBufferSize = 64 * 1024;
        // 单包上限 (1MB) + Length/CmdId 头 (8B) + 安全余量
        private const int MaxBufferSize = PacketCodec.MaxPacketLength + PacketCodec.TotalHeaderSize + 16;

        private Socket _socket;
        private byte[] _receiveBuffer = new byte[InitialBufferSize];
        private int _bufferOffset; // 缓冲区中已有的数据长度

        private readonly object _sendLock = new object();
        private readonly ConcurrentQueue<Action> _eventQueue = new ConcurrentQueue<Action>();

        public ProtocolType Type => ProtocolType.TCP;
        public string Host { get; private set; }
        public int Port { get; private set; }

        public bool IsConnected => _socket != null && _socket.Connected;

        public event Action OnConnected;
        public event Action<bool> OnDisconnected;
        public event Action<uint, ArraySegment<byte>> OnDataReceived;
        public event Action<string> OnError;

        public void Update()
        {
            while (_eventQueue.TryDequeue(out var action))
            {
                try
                {
                    action?.Invoke();
                }
                catch (Exception e)
                {
                    Debug.LogError($"[TcpProtocol] Queued event error: {e}");
                }
            }
        }

        private void EnqueueEvent(Action action)
        {
            _eventQueue.Enqueue(action);
        }

        public void Connect(string host, int port)
        {
            if (IsConnected)
            {
                Debug.LogWarning("[TcpProtocol] Already connected, close first.");
                return;
            }

            // 先解析地址 — 解析失败时不要 new Socket 避免句柄泄漏
            IPEndPoint endpoint;
            try
            {
                endpoint = new IPEndPoint(IPAddress.Parse(host), port);
            }
            catch (Exception e)
            {
                Debug.LogError($"[TcpProtocol] Invalid endpoint {host}:{port}: {e.Message}");
                EnqueueEvent(() => OnError?.Invoke($"Invalid endpoint: {e.Message}"));
                return;
            }

            // 重置 buffer 状态（如果之前残留）
            _bufferOffset = 0;
            if (_receiveBuffer.Length != InitialBufferSize)
            {
                _receiveBuffer = new byte[InitialBufferSize];
            }

            Socket newSocket = null;
            try
            {
                newSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, SocketProtocolType.Tcp);
                newSocket.NoDelay = true; // 禁用 Nagle
                newSocket.BeginConnect(endpoint, ConnectCallback, newSocket);
                _socket = newSocket;
                Host = host;
                Port = port;
            }
            catch (Exception e)
            {
                Debug.LogError($"[TcpProtocol] Connect failed: {e.Message}");
                try { newSocket?.Close(); } catch { /* swallow */ }
                _socket = null;
                EnqueueEvent(() => OnError?.Invoke($"Connect failed: {e.Message}"));
            }
        }

        private void ConnectCallback(IAsyncResult ar)
        {
            // ar.AsyncState 传的是 newSocket，捕获本实例的 _socket（可能已被替换/关闭）
            var sock = ar.AsyncState as Socket;
            try
            {
                sock?.EndConnect(ar);
            }
            catch (Exception e)
            {
                Debug.LogError($"[TcpProtocol] Connect callback error: {e.Message}");
                EnqueueEvent(() => OnError?.Invoke($"Connect error: {e.Message}"));
                HandleDisconnect(sock, true);
                return;
            }

            // 期间 Close 可能已经发生，_socket != sock
            if (_socket != sock || sock == null)
            {
                try { sock?.Close(); } catch { /* swallow */ }
                return;
            }

            Debug.Log("[TcpProtocol] Connected.");
            EnqueueEvent(() => OnConnected?.Invoke());

            // 开始接收数据
            BeginReceive(sock);
        }

        private void BeginReceive(Socket socket)
        {
            if (socket == null || _socket != socket || !socket.Connected) return;

            // 至少保证有 1 字节可用空间；上限到 MaxBufferSize 后不再增长（仍可能 0 字节可用 = buffer 满）
            EnsureBufferSpace(1);

            int available = _receiveBuffer.Length - _bufferOffset;
            if (available <= 0)
            {
                // 缓冲区撑到上限仍没有完整包 — 视为协议错误（粘包叠加超出单包上限），断开
                Debug.LogError($"[TcpProtocol] Receive buffer full ({_receiveBuffer.Length} bytes), disconnecting.");
                EnqueueEvent(() => OnError?.Invoke("Receive buffer full"));
                HandleDisconnect(socket, true);
                return;
            }

            try
            {
                socket.BeginReceive(
                    _receiveBuffer, _bufferOffset, available,
                    SocketFlags.None,
                    ReceiveCallback, socket);
            }
            catch (Exception e)
            {
                Debug.LogError($"[TcpProtocol] BeginReceive error: {e.Message}");
                EnqueueEvent(() => OnError?.Invoke($"Receive error: {e.Message}"));
                HandleDisconnect(socket, true);
            }
        }

        private void EnsureBufferSpace(int additionalBytesNeeded)
        {
            int required = _bufferOffset + additionalBytesNeeded;
            if (_receiveBuffer.Length >= required) return;

            int newSize = _receiveBuffer.Length;
            while (newSize < required) newSize *= 2;
            if (newSize > MaxBufferSize) newSize = MaxBufferSize;
            if (newSize < required)
            {
                // 超过单包上限，留给 Decode 抛 InvalidDataException 走断开流程
                newSize = required;
            }

            var newBuf = new byte[newSize];
            if (_bufferOffset > 0)
            {
                Buffer.BlockCopy(_receiveBuffer, 0, newBuf, 0, _bufferOffset);
            }
            _receiveBuffer = newBuf;
        }

        private void ReceiveCallback(IAsyncResult ar)
        {
            var socket = ar.AsyncState as Socket;
            if (socket == null || _socket != socket || !socket.Connected) return;

            int bytesRead;
            try
            {
                bytesRead = socket.EndReceive(ar);
            }
            catch (Exception e)
            {
                Debug.LogError($"[TcpProtocol] EndReceive error: {e.Message}");
                HandleDisconnect(socket, true);
                return;
            }

            if (bytesRead <= 0)
            {
                Debug.Log("[TcpProtocol] Server closed connection.");
                HandleDisconnect(socket, false);
                return;
            }

            _bufferOffset += bytesRead;
            ProcessReceivedData(socket);

            // 继续接收下一段数据
            BeginReceive(socket);
        }

        /// <summary>
        /// 处理缓冲区中的数据，循环解码完整包
        /// </summary>
        private void ProcessReceivedData(Socket socket)
        {
            int offset = 0;

            while (offset < _bufferOffset)
            {
                int consumed;
                try
                {
                    consumed = PacketCodec.Decode(
                        _receiveBuffer, offset,
                        _bufferOffset - offset,
                        out Packet packet);

                    if (consumed == 0)
                        break; // 数据不足，等待更多数据

                    offset += consumed;

                    try
                    {
                        uint cmdId = packet.CmdId;
                        ArraySegment<byte> safeBody = packet.Body;
                        EnqueueEvent(() => OnDataReceived?.Invoke(cmdId, safeBody));
                    }
                    catch (Exception e)
                    {
                        Debug.LogError($"[TcpProtocol] OnDataReceived handler error: {e.Message}");
                    }
                }
                catch (Exception e)
                {
                    Debug.LogError($"[TcpProtocol] Decode error: {e.Message}");
                    HandleDisconnect(socket, true);
                    return;
                }
            }

            // 将未处理的数据移到缓冲区头部
            if (offset > 0 && offset < _bufferOffset)
            {
                int remaining = _bufferOffset - offset;
                Buffer.BlockCopy(_receiveBuffer, offset, _receiveBuffer, 0, remaining);
                _bufferOffset = remaining;
            }
            else if (offset >= _bufferOffset)
            {
                _bufferOffset = 0;
            }
        }

        public void Send(byte[] data)
        {
            if (!IsConnected)
            {
                Debug.LogWarning("[TcpProtocol] Cannot send, not connected.");
                return;
            }

            lock (_sendLock)
            {
                var socket = _socket;
                if (socket == null || !socket.Connected)
                {
                    Debug.LogWarning("[TcpProtocol] Cannot send, not connected.");
                    return;
                }

                try
                {
                    socket.BeginSend(data, 0, data.Length, SocketFlags.None, SendCallback, socket);
                }
                catch (Exception e)
                {
                    Debug.LogError($"[TcpProtocol] Send error: {e.Message}");
                    EnqueueEvent(() => OnError?.Invoke($"Send error: {e.Message}"));
                    HandleDisconnect(socket, true);
                }
            }
        }

        private void SendCallback(IAsyncResult ar)
        {
            var socket = ar.AsyncState as Socket;
            if (socket == null || _socket != socket) return;

            try
            {
                socket.EndSend(ar);
            }
            catch (Exception e)
            {
                Debug.LogError($"[TcpProtocol] Send callback error: {e.Message}");
                HandleDisconnect(socket, true);
            }
        }

        public void Close()
        {
            HandleDisconnect(null, false);
        }

        private void HandleDisconnect(Socket expectedSocket, bool isAbnormal)
        {
            Socket socket;
            lock (_sendLock)
            {
                socket = _socket;
                if (socket == null) return;
                if (expectedSocket != null && socket != expectedSocket) return;

                _socket = null;
                _bufferOffset = 0;
            }

            try
            {
                socket.Shutdown(SocketShutdown.Both);
            }
            catch { /* ignore shutdown errors */ }

            try
            {
                socket.Close();
            }
            catch { /* ignore close errors */ }

            Debug.Log($"[TcpProtocol] Disconnected. Abnormal: {isAbnormal}");
            EnqueueEvent(() => OnDisconnected?.Invoke(isAbnormal));
        }
    }
}
