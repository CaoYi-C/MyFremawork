using System.Threading;
using Cysharp.Threading.Tasks;
using Fuel.Launcher.Config;
using HotUpdate.Configs;
using UnityEngine;

namespace HotUpdate.GameEntry
{
    public static class HotUpdateEntry
    {
        public static async UniTask StartAsync(LocalStartupConfig localConfig, CancellationToken cancellationToken)
        {
            await TableKitConfigLoader.LoadAsync(localConfig, cancellationToken);
            Debug.Log("HotUpdateEntry.StartAsync invoked by startup pipeline.");
        }
    }
}
