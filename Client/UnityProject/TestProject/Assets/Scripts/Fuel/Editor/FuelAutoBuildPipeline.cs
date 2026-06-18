using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Fuel.Editor.HybridCLR;
using HybridCLR.Editor.Commands;
using UnityEditor;
using UnityEditor.Build.Reporting;
using UnityEngine;
using YooAsset;
using YooAsset.Editor;

namespace Fuel.Editor.BuildPipeline
{
    public static class FuelAutoBuildPipeline
    {
        private enum BuildContent
        {
            FullHotUpdateResources,
            IncrementalHotUpdateResources,
            FullPackage
        }

        private const string BuildOutputRoot = "AssetsBuild";
        private const string ArchiveFolderName = "ArchivingArtifacts";

        [MenuItem("Tools/Fuel/Build/Build Full HotUpdate Resources")]
        public static void BuildFullHotUpdateResourcesMenu()
        {
            var options = CreateOptions(BuildContent.FullHotUpdateResources);
            Execute(options, false);
        }

        [MenuItem("Tools/Fuel/Build/Build Incremental HotUpdate Resources")]
        public static void BuildIncrementalHotUpdateResourcesMenu()
        {
            var options = CreateOptions(BuildContent.IncrementalHotUpdateResources);
            Execute(options, false);
        }

        [MenuItem("Tools/Fuel/Build/Build Full Package")]
        public static void BuildFullPackageMenu()
        {
            var options = CreateOptions(BuildContent.FullPackage);
            Execute(options, false);
        }

        public static void AutoBuild()
        {
            var options = CreateOptions(BuildContent.FullPackage);
            ApplyCommandLineArgs(options);
            bool success = Execute(options, true);
            EditorApplication.Exit(success ? 0 : 1);
        }

        public static void AutoBuildFullHotUpdateResources()
        {
            var options = CreateOptions(BuildContent.FullHotUpdateResources);
            ApplyCommandLineArgs(options);
            bool success = Execute(options, true);
            EditorApplication.Exit(success ? 0 : 1);
        }

        public static void AutoBuildIncrementalHotUpdateResources()
        {
            var options = CreateOptions(BuildContent.IncrementalHotUpdateResources);
            ApplyCommandLineArgs(options);
            bool success = Execute(options, true);
            EditorApplication.Exit(success ? 0 : 1);
        }

        private static BuildOptionsData CreateOptions(BuildContent content)
        {
            return new BuildOptionsData
            {
                Content = content,
                BuildTarget = EditorUserBuildSettings.activeBuildTarget,
                PackageName = GetDefaultPackageName(),
                AssetsVersion = CreateDefaultAssetsVersion(),
                AppVersion = PlayerSettings.bundleVersion,
                AndroidVersionCode = PlayerSettings.Android.bundleVersionCode,
                BuildAppBundle = EditorUserBuildSettings.buildAppBundle,
                DevelopmentBuild = EditorUserBuildSettings.development,
                GenerateHybridCLRAll = true
            };
        }

        private static bool Execute(BuildOptionsData options, bool batchMode)
        {
            try
            {
                Debug.Log($"Fuel auto build started. content:{options.Content}, target:{options.BuildTarget}, package:{options.PackageName}, assetsVersion:{options.AssetsVersion}");
                SwitchActiveBuildTarget(options.BuildTarget);
                EditorUserBuildSettings.development = options.DevelopmentBuild;

                if (options.Content == BuildContent.FullHotUpdateResources || options.Content == BuildContent.FullPackage)
                {
                    if (!BuildHotUpdateResources(options, true))
                        return false;
                }
                else if (options.Content == BuildContent.IncrementalHotUpdateResources)
                {
                    if (!BuildHotUpdateResources(options, false))
                        return false;
                }

                if (options.Content == BuildContent.FullPackage)
                {
                    if (!BuildPlayerPackage(options))
                        return false;
                }

                Debug.Log("Fuel auto build completed.");
                return true;
            }
            catch (Exception e)
            {
                Debug.LogException(e);
                return false;
            }
            finally
            {
                if (!batchMode)
                    AssetDatabase.Refresh();
            }
        }

        private static bool BuildHotUpdateResources(BuildOptionsData options, bool clearBuildCacheFiles)
        {
            if (options.GenerateHybridCLRAll)
            {
                PrebuildCommand.GenerateAll();
                Debug.Log("HybridCLR GenerateAll completed.");
            }
            else
            {
                CompileDllCommand.CompileDll(options.BuildTarget, options.DevelopmentBuild);
                Debug.Log("HybridCLR CompileDll completed.");
            }

            AssetDatabase.Refresh();
            HybridCLRDllBytesExporter.CopyActiveBuildTargetDllsToBytes();
            AssetDatabase.SaveAssets();
            AssetDatabase.Refresh();

            var buildResult = BuildYooAssetPackage(options, clearBuildCacheFiles);
            if (!buildResult.Success)
            {
                Debug.LogError($"YooAsset build failed. task:{buildResult.FailedTask}, error:{buildResult.ErrorInfo}\n{buildResult.ErrorStack}");
                return false;
            }

            Debug.Log($"YooAsset build completed: {buildResult.OutputPackageDirectory}");
            CopyDirectory(buildResult.OutputPackageDirectory, Path.Combine(GetArtifactsRoot(), options.BuildTarget.ToString(), options.PackageName, options.AssetsVersion));
            return true;
        }

        private static YooAsset.Editor.BuildResult BuildYooAssetPackage(BuildOptionsData options, bool clearBuildCacheFiles)
        {
            var buildPipeline = BundleBuilderSetting.GetPackageBuildPipeline(options.PackageName);
            var buildParameters = CreateYooAssetBuildParameters(options, buildPipeline, clearBuildCacheFiles);
            var pipelineType = (EBuildPipeline)Enum.Parse(typeof(EBuildPipeline), buildPipeline);

            switch (pipelineType)
            {
                case EBuildPipeline.LegacyBuildPipeline:
                    return new LegacyBuildPipeline().Run(buildParameters, true);
                case EBuildPipeline.ScriptableBuildPipeline:
                    return new ScriptableBuildPipeline().Run(buildParameters, true);
                case EBuildPipeline.RawFileBuildPipeline:
                    return new RawFileBuildPipeline().Run(buildParameters, true);
                default:
                    throw new NotSupportedException($"Fuel auto build does not support YooAsset pipeline: {buildPipeline}");
            }
        }

        private static BuildParameters CreateYooAssetBuildParameters(BuildOptionsData options, string buildPipeline, bool clearBuildCacheFiles)
        {
            var pipelineType = (EBuildPipeline)Enum.Parse(typeof(EBuildPipeline), buildPipeline);
            var fileNameStyle = BundleBuilderSetting.GetPackageFileNameStyle(options.PackageName, buildPipeline);
            var bundledCopyOption = BundleBuilderSetting.GetPackageBundledCopyOption(options.PackageName, buildPipeline);
            var bundledCopyParams = BundleBuilderSetting.GetPackageBundledCopyParams(options.PackageName, buildPipeline);
            var bundleEncryptor = CreateInstance<IBundleEncryptor>(BundleBuilderSetting.GetPackageBundleEncryptorClassName(options.PackageName, buildPipeline));
            var manifestEncryptor = CreateInstance<IManifestEncryptor>(BundleBuilderSetting.GetPackageManifestEncryptorClassName(options.PackageName, buildPipeline));
            var manifestDecryptor = CreateInstance<IManifestDecryptor>(BundleBuilderSetting.GetPackageManifestDecryptorClassName(options.PackageName, buildPipeline));

            BuildParameters buildParameters;
            switch (pipelineType)
            {
                case EBuildPipeline.LegacyBuildPipeline:
                    buildParameters = new LegacyBuildParameters
                    {
                        CompressOption = BundleBuilderSetting.GetPackageCompressOption(options.PackageName, buildPipeline)
                    };
                    break;
                case EBuildPipeline.ScriptableBuildPipeline:
                    buildParameters = new ScriptableBuildParameters
                    {
                        CompressOption = BundleBuilderSetting.GetPackageCompressOption(options.PackageName, buildPipeline)
                    };
                    break;
                case EBuildPipeline.RawFileBuildPipeline:
                    buildParameters = new RawFileBuildParameters();
                    break;
                default:
                    throw new NotSupportedException($"Fuel auto build does not support YooAsset pipeline: {buildPipeline}");
            }

            buildParameters.BuildOutputRoot = BundleBuilderHelper.GetDefaultBuildOutputRoot();
            buildParameters.BundledFileRoot = BundleBuilderHelper.GetStreamingAssetsRoot();
            buildParameters.BuildPipeline = buildPipeline;
            buildParameters.BuildTarget = options.BuildTarget;
            buildParameters.ClearBuildCacheFiles = clearBuildCacheFiles;
            buildParameters.PackageName = options.PackageName;
            buildParameters.PackageVersion = options.AssetsVersion;
            buildParameters.VerifyBuildingResult = true;
            buildParameters.EnableSharePackRule = true;
            buildParameters.FileNameStyle = fileNameStyle;
            buildParameters.BundledCopyOption = bundledCopyOption;
            buildParameters.BundledCopyParams = bundledCopyParams;
            buildParameters.BundleEncryptor = bundleEncryptor;
            buildParameters.ManifestEncryptor = manifestEncryptor;
            buildParameters.ManifestDecryptor = manifestDecryptor;
            buildParameters.BuildBundleType = pipelineType == EBuildPipeline.RawFileBuildPipeline ? (int)EBundleType.RawBundle : (int)EBundleType.AssetBundle;
            return buildParameters;
        }

        private static bool BuildPlayerPackage(BuildOptionsData options)
        {
            PlayerSettings.bundleVersion = options.AppVersion;
            if (options.BuildTarget == BuildTarget.Android)
            {
                EditorUserBuildSettings.buildAppBundle = options.BuildAppBundle;
                PlayerSettings.Android.bundleVersionCode = options.AndroidVersionCode;
            }

            var scenes = EditorBuildSettings.scenes.Where(scene => scene.enabled).Select(scene => scene.path).ToArray();
            if (scenes.Length == 0)
            {
                Debug.LogError("No enabled scenes in Build Settings.");
                return false;
            }

            var outPath = GetPlayerOutputPath(options);
            var directory = Path.GetDirectoryName(outPath);
            if (!string.IsNullOrEmpty(directory))
                Directory.CreateDirectory(directory);
            var buildPlayerOptions = new BuildPlayerOptions
            {
                scenes = scenes,
                locationPathName = outPath,
                target = options.BuildTarget,
                targetGroup = UnityEditor.BuildPipeline.GetBuildTargetGroup(options.BuildTarget),
                options = options.DevelopmentBuild ? UnityEditor.BuildOptions.Development : UnityEditor.BuildOptions.None
            };

            var report = UnityEditor.BuildPipeline.BuildPlayer(buildPlayerOptions);
            if (report.summary.result != UnityEditor.Build.Reporting.BuildResult.Succeeded)
            {
                Debug.LogError($"Player build failed: {report.summary.result}");
                return false;
            }

            var archivePath = Path.Combine(GetArtifactsRoot(), ArchiveFolderName, Path.GetFileName(outPath));
            var archiveDirectory = Path.GetDirectoryName(archivePath);
            if (!string.IsNullOrEmpty(archiveDirectory))
                Directory.CreateDirectory(archiveDirectory);
            if (File.Exists(outPath))
                File.Copy(outPath, archivePath, true);
            Debug.Log($"Player build completed: {outPath}");
            return true;
        }

        private static void ApplyCommandLineArgs(BuildOptionsData options)
        {
            var args = Environment.GetCommandLineArgs();
            for (int i = 0; i < args.Length; i++)
            {
                switch (args[i])
                {
                    case "-buildContent" when i + 1 < args.Length:
                        options.Content = (BuildContent)Enum.Parse(typeof(BuildContent), args[++i]);
                        break;
                    case "-buildTarget" when i + 1 < args.Length:
                        options.BuildTarget = (BuildTarget)Enum.Parse(typeof(BuildTarget), args[++i]);
                        break;
                    case "-packageName" when i + 1 < args.Length:
                        options.PackageName = args[++i];
                        break;
                    case "-assetsVersion" when i + 1 < args.Length:
                        options.AssetsVersion = args[++i];
                        break;
                    case "-appVersion" when i + 1 < args.Length:
                    case "-bundleVersion" when i + 1 < args.Length:
                        options.AppVersion = args[++i];
                        break;
                    case "-androidVersionCode" when i + 1 < args.Length:
                    case "-bundleVersionCode" when i + 1 < args.Length:
                        options.AndroidVersionCode = int.Parse(args[++i]);
                        break;
                    case "-buildAppBundle" when i + 1 < args.Length:
                    case "-isbundleAbb" when i + 1 < args.Length:
                        options.BuildAppBundle = IsTrue(args[++i]);
                        break;
                    case "-developmentBuild" when i + 1 < args.Length:
                    case "-useDevelopmentBuild" when i + 1 < args.Length:
                        options.DevelopmentBuild = IsTrue(args[++i]);
                        break;
                    case "-generateHybridCLRAll" when i + 1 < args.Length:
                    case "-genAllAot" when i + 1 < args.Length:
                        options.GenerateHybridCLRAll = IsTrue(args[++i]);
                        break;
                }
            }
        }

        private static T CreateInstance<T>(string className) where T : class
        {
            if (string.IsNullOrEmpty(className))
                return null;

            var type = Type.GetType(className);
            if (type == null)
            {
                type = AppDomain.CurrentDomain.GetAssemblies()
                    .Select(assembly => assembly.GetType(className))
                    .FirstOrDefault(foundType => foundType != null);
            }

            return type == null ? null : Activator.CreateInstance(type) as T;
        }

        private static string GetPlayerOutputPath(BuildOptionsData options)
        {
            var root = Path.Combine(GetArtifactsRoot(), "Packages", options.BuildTarget.ToString(), options.AppVersion + "." + options.AssetsVersion);
            var time = DateTime.Now.ToString("yyyy-MM-dd_HH-mm-ss");
            switch (options.BuildTarget)
            {
                case BuildTarget.Android:
                    return Path.Combine(root, $"{PlayerSettings.productName}_{time}_V_{options.AppVersion}_{options.AssetsVersion}.{(options.BuildAppBundle ? "aab" : "apk")}").Replace('\\', '/');
                case BuildTarget.StandaloneWindows:
                case BuildTarget.StandaloneWindows64:
                    return Path.Combine(root, PlayerSettings.productName + ".exe").Replace('\\', '/');
                case BuildTarget.WebGL:
                    return root.Replace('\\', '/');
                case BuildTarget.iOS:
                    return Path.Combine(root, PlayerSettings.productName).Replace('\\', '/');
                default:
                    return Path.Combine(root, PlayerSettings.productName).Replace('\\', '/');
            }
        }

        private static void SwitchActiveBuildTarget(BuildTarget target)
        {
            if (EditorUserBuildSettings.activeBuildTarget == target)
                return;

            var group = UnityEditor.BuildPipeline.GetBuildTargetGroup(target);
            if (!EditorUserBuildSettings.SwitchActiveBuildTarget(group, target))
                throw new InvalidOperationException($"Switch active build target failed: {target}");
        }

        private static string GetDefaultPackageName()
        {
            var packages = BundleCollectorSettingData.Setting.Packages;
            if (packages.Count == 0)
                throw new InvalidOperationException("YooAsset BundleCollectorSetting has no package.");

            return packages[0].PackageName;
        }

        private static string CreateDefaultAssetsVersion()
        {
            int totalMinutes = DateTime.Now.Hour * 60 + DateTime.Now.Minute;
            return DateTime.Now.ToString("yyyy-MM-dd") + "-" + totalMinutes;
        }

        private static string GetArtifactsRoot()
        {
            return Path.GetFullPath(Path.Combine(Application.dataPath, "..", "..", BuildOutputRoot)).Replace('\\', '/');
        }

        private static bool IsTrue(string value)
        {
            return string.Equals(value, "true", StringComparison.OrdinalIgnoreCase) || value == "1";
        }

        private static void CopyDirectory(string sourceDir, string destinationDir)
        {
            if (string.IsNullOrEmpty(sourceDir) || !Directory.Exists(sourceDir))
                return;

            if (Directory.Exists(destinationDir))
                Directory.Delete(destinationDir, true);

            Directory.CreateDirectory(destinationDir);
            foreach (var directory in Directory.GetDirectories(sourceDir, "*", SearchOption.AllDirectories))
                Directory.CreateDirectory(directory.Replace(sourceDir, destinationDir));

            foreach (var file in Directory.GetFiles(sourceDir, "*", SearchOption.AllDirectories))
                File.Copy(file, file.Replace(sourceDir, destinationDir), true);
        }

        private sealed class BuildOptionsData
        {
            public BuildContent Content;
            public BuildTarget BuildTarget;
            public string PackageName;
            public string AssetsVersion;
            public string AppVersion;
            public int AndroidVersionCode;
            public bool BuildAppBundle;
            public bool DevelopmentBuild;
            public bool GenerateHybridCLRAll;
        }
    }
}
