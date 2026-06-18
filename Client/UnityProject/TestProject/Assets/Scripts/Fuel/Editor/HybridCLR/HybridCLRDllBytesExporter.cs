using HybridCLR.Editor;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEngine;

namespace Fuel.Editor.HybridCLR
{
    public static class HybridCLRDllBytesExporter
    {
        private const string HotOutputFolder = "Assets/AssetsPackage/Main/Code/HOT";
        private const string AotOutputFolder = "Assets/AssetsPackage/Main/Code/AOT";
        private const string AotMetadataListFileName = "AOTMetadataDllList.bytes";
        private static readonly string[] DefaultAotMetadataDllFiles =
        {
            "mscorlib.dll",
            "System.dll",
            "System.Core.dll"
        };

        [MenuItem("Tools/Fuel/HybridCLR/Copy HotUpdate DLLs To Bytes")]
        public static void CopyActiveBuildTargetDllsToBytes()
        {
            var hotSourceFolder = SettingsUtil.GetHotUpdateDllsOutputDirByTarget(EditorUserBuildSettings.activeBuildTarget);
            if (!Directory.Exists(hotSourceFolder))
            {
                Debug.LogError($"HybridCLR DLL folder not found: {hotSourceFolder}. Run HybridCLR/CompileDll first.");
                return;
            }

            var aotSourceFolder = SettingsUtil.GetAssembliesPostIl2CppStripDir(EditorUserBuildSettings.activeBuildTarget);
            if (!Directory.Exists(aotSourceFolder))
            {
                Debug.LogError($"HybridCLR stripped AOT DLL folder not found: {aotSourceFolder}. Run HybridCLR/Generate/All first.");
                return;
            }

            Directory.CreateDirectory(HotOutputFolder);
            Directory.CreateDirectory(AotOutputFolder);

            int hotCopiedCount = CopyHotDlls(hotSourceFolder);
            int aotCopiedCount = CopyAotMetadataDlls(aotSourceFolder);

            AssetDatabase.Refresh();
            Debug.Log($"Copied {hotCopiedCount} HybridCLR configured HOT DLL bytes to {HotOutputFolder}; copied {aotCopiedCount} AOT metadata DLL bytes to {AotOutputFolder}");
        }

        private static int CopyHotDlls(string sourceFolder)
        {
            int copiedCount = 0;
            var dllFiles = SettingsUtil.HotUpdateAssemblyFilesExcludePreserved;
            for (int i = 0; i < dllFiles.Count; i++)
            {
                var sourcePath = Path.Combine(sourceFolder, dllFiles[i]);
                if (!File.Exists(sourcePath))
                {
                    Debug.LogError($"HybridCLR hot update DLL not found: {sourcePath}. Run HybridCLR/CompileDll first.");
                    continue;
                }

                var fileName = dllFiles[i] + ".bytes";
                var targetPath = Path.Combine(HotOutputFolder, fileName).Replace('\\', '/');
                File.Copy(sourcePath, targetPath, true);
                copiedCount++;
            }

            DeleteUnconfiguredBytes(HotOutputFolder, dllFiles.Select(file => file + ".bytes").ToArray());
            return copiedCount;
        }

        private static int CopyAotMetadataDlls(string sourceFolder)
        {
            int copiedCount = 0;
            var copiedFileNames = new string[DefaultAotMetadataDllFiles.Length];
            for (int i = 0; i < DefaultAotMetadataDllFiles.Length; i++)
            {
                var dllFile = DefaultAotMetadataDllFiles[i];
                var sourcePath = Path.Combine(sourceFolder, dllFile);
                if (!File.Exists(sourcePath))
                {
                    Debug.LogError($"HybridCLR AOT metadata DLL not found: {sourcePath}. Run HybridCLR/Generate/All first.");
                    continue;
                }

                var fileName = dllFile + ".bytes";
                var targetPath = Path.Combine(AotOutputFolder, fileName).Replace('\\', '/');
                File.Copy(sourcePath, targetPath, true);
                copiedFileNames[copiedCount] = fileName;
                copiedCount++;
            }

            var configuredFiles = DefaultAotMetadataDllFiles.Select(file => file + ".bytes")
                .Concat(new[] { AotMetadataListFileName })
                .ToArray();
            DeleteUnconfiguredBytes(AotOutputFolder, configuredFiles);
            File.WriteAllLines(Path.Combine(AotOutputFolder, AotMetadataListFileName), copiedFileNames.Take(copiedCount));
            return copiedCount;
        }

        private static void DeleteUnconfiguredBytes(string folder, string[] configuredFileNames)
        {
            var existingFiles = Directory.GetFiles(folder, "*.bytes", SearchOption.TopDirectoryOnly);
            for (int i = 0; i < existingFiles.Length; i++)
            {
                var existingFile = existingFiles[i].Replace('\\', '/');
                var fileName = Path.GetFileName(existingFile);
                if (configuredFileNames.Contains(fileName))
                    continue;

                File.Delete(existingFile);
                var metaPath = existingFile + ".meta";
                if (File.Exists(metaPath))
                    File.Delete(metaPath);
            }
        }
    }
}
