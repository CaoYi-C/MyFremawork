using System;
using System.Linq;
using System.Reflection;
using System.Threading;
using Cysharp.Threading.Tasks;
using Fuel.Launcher.Config;
using UnityEngine;
using YooAsset;

#if !UNITY_EDITOR && HYBRIDCLR
using HybridCLR;
#endif

namespace Fuel.Launcher.HybridCLR
{
    public sealed class HybridCLRLoader : IHybridCLRLoader
    {
        private const string DefaultAotMetadataListPath = "AOTMetadataDllList.bytes";

        public async UniTask LoadAotMetadataAsync(LocalStartupConfig localConfig, CancellationToken cancellationToken)
        {
            var aotMetadataDllPaths = await LoadAotMetadataListAsync(localConfig.packageName, cancellationToken);
            if (aotMetadataDllPaths == null || aotMetadataDllPaths.Length == 0)
                aotMetadataDllPaths = localConfig.aotMetadataDllPaths;

            if (aotMetadataDllPaths == null)
                return;

            for (int i = 0; i < aotMetadataDllPaths.Length; i++)
            {
                var path = aotMetadataDllPaths[i];
                if (string.IsNullOrEmpty(path))
                    continue;

                var fileName = GetFileName(path);
                var bytes = await LoadBytesAsync(localConfig.packageName, fileName, cancellationToken);
#if !UNITY_EDITOR && HYBRIDCLR
                RuntimeApi.LoadMetadataForAOTAssembly(bytes, HomologousImageMode.SuperSet);
#endif
            }
        }

        public async UniTask<Assembly> LoadHotUpdateAssemblyAsync(LocalStartupConfig localConfig, CancellationToken cancellationToken)
        {
            var hotUpdateDllFileName = GetFileName(localConfig.hotUpdateDllPath);
            var bytes = await LoadBytesAsync(localConfig.packageName, hotUpdateDllFileName, cancellationToken);
#if UNITY_EDITOR
            var assemblyName = System.IO.Path.GetFileNameWithoutExtension(hotUpdateDllFileName);
            assemblyName = assemblyName.Replace(".dll", string.Empty).Replace(".bytes", string.Empty);
            foreach (var assembly in AppDomain.CurrentDomain.GetAssemblies())
            {
                if (assembly.GetName().Name == assemblyName)
                    return assembly;
            }
#endif
            return Assembly.Load(bytes);
        }

        private static async UniTask<string[]> LoadAotMetadataListAsync(string packageName, CancellationToken cancellationToken)
        {
            try
            {
                var text = await LoadTextAsync(packageName, DefaultAotMetadataListPath, cancellationToken);
                if (string.IsNullOrWhiteSpace(text))
                    return Array.Empty<string>();

                return text.Split(new[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries)
                    .Select(GetFileName)
                    .ToArray();
            }
            catch
            {
                return Array.Empty<string>();
            }
        }

        private static async UniTask<string> LoadTextAsync(string packageName, string path, CancellationToken cancellationToken)
        {
            var assetFileName = GetFileName(path);
            var package = YooAssets.GetPackage(packageName);
            var handle = package.LoadAssetAsync<TextAsset>(assetFileName);
            try
            {
                await handle.ToUniTask(cancellationToken: cancellationToken);
                var asset = handle.GetAssetObject<TextAsset>();
                if (asset == null)
                    throw new InvalidOperationException($"Load text failed: {assetFileName}");

                return asset.text;
            }
            finally
            {
                handle.Release();
            }
        }

        private static async UniTask<byte[]> LoadBytesAsync(string packageName, string path, CancellationToken cancellationToken)
        {
            var assetFileName = GetFileName(path);
            var package = YooAssets.GetPackage(packageName);
            var handle = package.LoadAssetAsync<TextAsset>(assetFileName);
            try
            {
                await handle.ToUniTask(cancellationToken: cancellationToken);
                var asset = handle.GetAssetObject<TextAsset>();
                if (asset == null)
                    throw new InvalidOperationException($"Load bytes failed: {assetFileName}");

                var bytes = asset.bytes;
                var result = new byte[bytes.Length];
                Buffer.BlockCopy(bytes, 0, result, 0, bytes.Length);
                return result;
            }
            finally
            {
                handle.Release();
            }
        }

        private static string GetFileName(string path)
        {
            return string.IsNullOrEmpty(path) ? path : System.IO.Path.GetFileName(path);
        }
    }
}
