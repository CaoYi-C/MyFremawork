// 烟测用的本地 TCP Echo 服务器。语义：
//  - 监听指定端口
//  - 每个连接独立处理
//  - 接收到的所有字节（按 [Length][CmdId][Body] 帧格式）解码后回显给客户端
//  - 收到一个特殊的 cmdId=EchoServer.SpecialCmdId 时，回一个长度 = N 的固定 body（用于测大包）
//  - 收到 EchoServer.DisconnectCmdId 时，优雅关闭连接
//
// 这是生产 TcpProtocol 的对端 — 让真实 client 代码端到端跑起来。
using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Threading.Tasks;

namespace Fuel.Smoke.EchoServer
{
    public sealed class EchoTcpServer : IAsyncDisposable
    {
        /// <summary>收到这个 cmdId 时，server 返回一个长度为 <see cref="LargePayloadSize"/> 的 body（用于测大包解码）</summary>
        public const uint LargePayloadCmdId = 0xFFFF_FFFE;
        /// <summary>收到这个 cmdId 时，server 立刻关闭连接（用于测半包重连）</summary>
        public const uint DisconnectCmdId = 0xFFFF_FFFD;
        /// <summary>大包大小</summary>
        public const int LargePayloadSize = 100 * 1024; // 100 KB

        private readonly TcpListener _listener;
        public int Port { get; }
        public CancellationTokenSource Cts { get; } = new();

        public EchoTcpServer(int port = 0)
        {
            _listener = new TcpListener(IPAddress.Loopback, port);
            _listener.Start();
            Port = ((IPEndPoint)_listener.LocalEndpoint).Port;
        }

        public void Start()
        {
            _ = Task.Run(AcceptLoopAsync);
        }

        public Action<uint, ArraySegment<byte>>? OnPacketReceived;     // 测试用 hook
        public Action<string>? OnClientConnected;                       // 测试用 hook
        public Action<string>? OnClientDisconnected;                    // 测试用 hook
        public Func<uint, byte[]?>? SpecialHandler;                     // 自定义 handler 注入

        private async Task AcceptLoopAsync()
        {
            while (!Cts.IsCancellationRequested)
            {
                TcpClient client;
                try
                {
                    client = await _listener.AcceptTcpClientAsync(Cts.Token).ConfigureAwait(false);
                }
                catch (OperationCanceledException) { return; }
                catch (ObjectDisposedException) { return; }

                var remote = client.Client.RemoteEndPoint?.ToString() ?? "?";
                OnClientConnected?.Invoke(remote);
                _ = Task.Run(() => HandleClientAsync(client, remote));
            }
        }

        private async Task HandleClientAsync(TcpClient client, string remote)
        {
            var stream = client.GetStream();
            var receiveBuf = new byte[64 * 1024];
            int bufferOffset = 0;

            try
            {
                while (!Cts.IsCancellationRequested)
                {
                    int bytesRead = await stream.ReadAsync(receiveBuf.AsMemory(bufferOffset, receiveBuf.Length - bufferOffset), Cts.Token).ConfigureAwait(false);
                    if (bytesRead == 0) break; // 远端关闭
                    bufferOffset += bytesRead;

                    // 解码所有完整包
                    int processOffset = 0;
                    while (processOffset < bufferOffset)
                    {
                        int available = bufferOffset - processOffset;
                        int length;
                        if (available < 4)
                        {
                            // 数据不足 4 字节头，等下一次 ReadAsync
                            break;
                        }
                        length = (receiveBuf[processOffset] << 24)
                               | (receiveBuf[processOffset + 1] << 16)
                               | (receiveBuf[processOffset + 2] << 8)
                               | receiveBuf[processOffset + 3];

                        if (length < 4 || length > 1024 * 1024)
                        {
                            // 客户端被强制关掉时可能残留 4 字节 0 的"假包头"；不抛，丢包并断开。
                            Console.Error.WriteLine($"[EchoServer] client {remote} sent garbage length={length}, dropping & closing.");
                            client.Close();
                            OnClientDisconnected?.Invoke(remote);
                            return;
                        }

                        if (available < 4 + length) break; // 包不完整，等下一次 ReadAsync

                        int bodyLen = length - 4;
                        byte[] body = new byte[bodyLen];
                        if (bodyLen > 0)
                            Buffer.BlockCopy(receiveBuf, processOffset + 8, body, 0, bodyLen);

                        uint cmdId = (uint)((receiveBuf[processOffset + 4] << 24)
                                          | (receiveBuf[processOffset + 5] << 16)
                                          | (receiveBuf[processOffset + 6] << 8)
                                          | receiveBuf[processOffset + 7]);

                        OnPacketReceived?.Invoke(cmdId, new ArraySegment<byte>(body));

                        // 决定回包
                        byte[]? specialResp = SpecialHandler?.Invoke(cmdId);
                        byte[] respBody;
                        uint respCmd;
                        if (specialResp != null)
                        {
                            respBody = specialResp;
                            respCmd = cmdId; // echo 同一个 cmdId
                        }
                        else if (cmdId == LargePayloadCmdId)
                        {
                            respBody = new byte[LargePayloadSize];
                            for (int i = 0; i < respBody.Length; i++) respBody[i] = (byte)(i & 0xFF);
                            respCmd = cmdId;
                        }
                        else if (cmdId == DisconnectCmdId)
                        {
                            // 优雅关闭
                            client.Close();
                            OnClientDisconnected?.Invoke(remote);
                            return;
                        }
                        else
                        {
                            // 默认 echo
                            respBody = body;
                            respCmd = cmdId;
                        }

                        // 编码并发送
                        int respLen = 4 + respBody.Length;
                        byte[] respPacket = new byte[4 + respLen];
                        respPacket[0] = (byte)(respLen >> 24);
                        respPacket[1] = (byte)(respLen >> 16);
                        respPacket[2] = (byte)(respLen >> 8);
                        respPacket[3] = (byte)respLen;
                        respPacket[4] = (byte)(respCmd >> 24);
                        respPacket[5] = (byte)(respCmd >> 16);
                        respPacket[6] = (byte)(respCmd >> 8);
                        respPacket[7] = (byte)respCmd;
                        if (respBody.Length > 0)
                            Buffer.BlockCopy(respBody, 0, respPacket, 8, respBody.Length);

                        await stream.WriteAsync(respPacket.AsMemory(0, respPacket.Length), Cts.Token).ConfigureAwait(false);

                        processOffset += 4 + length;
                    }

                    // 残留数据搬到头部
                    if (processOffset > 0 && processOffset < bufferOffset)
                    {
                        int remaining = bufferOffset - processOffset;
                        Buffer.BlockCopy(receiveBuf, processOffset, receiveBuf, 0, remaining);
                        bufferOffset = remaining;
                    }
                    else if (processOffset >= bufferOffset)
                    {
                        bufferOffset = 0;
                    }
                }
            }
            catch (Exception ex) when (ex is not OperationCanceledException)
            {
                Console.Error.WriteLine($"[EchoServer] client {remote} error: {ex.Message}");
                try { client.Close(); } catch { /* ignore */ }
            }
            finally
            {
                OnClientDisconnected?.Invoke(remote);
                client.Dispose();
            }
        }

        public async ValueTask DisposeAsync()
        {
            Cts.Cancel();
            _listener.Stop();
            await Task.Yield();
        }
    }
}
