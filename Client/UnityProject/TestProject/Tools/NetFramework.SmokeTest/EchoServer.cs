using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using Fuel.NetFramework.Codec;
using Fuel.NetFramework.Core;

namespace Fuel.NetFramework.SmokeTest
{
    /// <summary>
    /// 测试用 echo 服务器：监听 127.0.0.1:0（系统分配端口），accept 一个 client 后循环回包。
    /// 回包内容 = cmdId + body（自己造 echo 时使用）或原样回送（默认）。
    /// </summary>
    public sealed class EchoServer : IDisposable
    {
        private readonly TcpListener _listener;
        private readonly Thread _thread;
        private readonly CancellationTokenSource _cts = new CancellationTokenSource();
        private TcpClient _client;
        public int Port { get; }
        public IPEndPoint LocalEndPoint => (IPEndPoint)_listener.LocalEndpoint;

        // 配置
        public bool Verbose { get; set; }

        public EchoServer()
        {
            _listener = new TcpListener(IPAddress.Loopback, 0);
            _listener.Start();
            Port = ((IPEndPoint)_listener.LocalEndpoint).Port;
            _thread = new Thread(Loop) { IsBackground = true, Name = "EchoServer" };
            _thread.Start();
        }

        private void Loop()
        {
            try
            {
                _listener.Start();
                _client = _listener.AcceptTcpClient();
                if (Verbose) Console.WriteLine($"[EchoServer] Client connected on {LocalEndPoint}");

                var stream = _client.GetStream();
                byte[] buf = new byte[64 * 1024];
                var pending = new List<byte>();

                while (!_cts.IsCancellationRequested)
                {
                    int read;
                    try
                    {
                        read = stream.Read(buf, 0, buf.Length);
                    }
                    catch (Exception e)
                    {
                        if (Verbose) Console.WriteLine($"[EchoServer] Read end: {e.Message}");
                        break;
                    }
                    if (read == 0) break; // 客户端关闭

                    for (int i = 0; i < read; i++) pending.Add(buf[i]);

                    // 循环解包并 echo
                    int offset = 0;
                    while (offset < pending.Count)
                    {
                        int consumed;
                        Packet packet;
                        try
                        {
                            consumed = PacketCodec.Decode(pending.ToArray(), offset, pending.Count - offset, out packet);
                        }
                        catch (Exception e)
                        {
                            if (Verbose) Console.WriteLine($"[EchoServer] Decode error: {e.Message}");
                            goto done;
                        }
                        if (consumed == 0) break;

                        offset += consumed;

                        // 拼回包头 + body 并写回
                        byte[] header = new byte[PacketCodec.TotalHeaderSize];
                        PacketCodec.WriteInt32BigEndian(header, 0, PacketCodec.CmdIdSize + packet.Body.Count);
                        uint cmdId = packet.CmdId;
                        header[4] = (byte)(cmdId >> 24);
                        header[5] = (byte)(cmdId >> 16);
                        header[6] = (byte)(cmdId >> 8);
                        header[7] = (byte)cmdId;

                        try
                        {
                            stream.Write(header, 0, header.Length);
                            if (packet.Body.Count > 0)
                            {
                                stream.Write(packet.Body.Array, packet.Body.Offset, packet.Body.Count);
                            }
                            stream.Flush();
                        }
                        catch (Exception e)
                        {
                            if (Verbose) Console.WriteLine($"[EchoServer] Write error: {e.Message}");
                            goto done;
                        }
                    }
                    // 把未消费的数据留着
                    if (offset > 0) pending.RemoveRange(0, offset);
                }
            done: ;
            }
            catch (Exception e)
            {
                Console.Error.WriteLine($"[EchoServer] Loop error: {e}");
            }
        }

        public void Dispose()
        {
            try { _cts.Cancel(); } catch { }
            try { _client?.Close(); } catch { }
            try { _listener.Stop(); } catch { }
            try { _thread.Join(2000); } catch { }
        }
    }
}
