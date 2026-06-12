using System.Threading;
using Cysharp.Threading.Tasks;
using UnityEngine;

namespace HotUpdate.GameEntry
{
    public static class HotUpdateEntry
    {
        public static UniTask StartAsync(CancellationToken cancellationToken)
        {
            Debug.Log("HotUpdateEntry.StartAsync invoked by startup pipeline.");
            return UniTask.CompletedTask;
        }
    }
}
