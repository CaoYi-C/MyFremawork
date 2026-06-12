using System;
using System.Collections.Generic;
using System.Threading;
using Cysharp.Threading.Tasks;
using Fuel.Launcher;
using Fuel.Launcher.Config;
using Fuel.Launcher.HybridCLR;
using Fuel.Launcher.Resources;
using Fuel.Launcher.Table;
using Fuel.Launcher.Version;
using UnityEngine;

public sealed class StartupPipelinePlayerSmokeTest : MonoBehaviour
{
    private readonly List<string> _logs = new List<string>();
    private bool _finished;

    private void Start()
    {
        DontDestroyOnLoad(gameObject);
        RunAsync().Forget();
    }

    private void OnGUI()
    {
        GUI.Box(new Rect(10, 590, 760, 220), string.Join("\n", _logs));
    }

    private async UniTaskVoid RunAsync()
    {
        using var cts = new CancellationTokenSource(TimeSpan.FromSeconds(60));
        try
        {
            Log("STARTUP_PIPELINE_PLAYER_TEST_BEGIN");
            var pipeline = new GameUpdatePipeline(
                new ResourcesJsonStartupConfigProvider(),
                new HttpJsonVersionService(),
                new SemanticAppVersionChecker(),
                new DefaultAppUpdateHandler(),
                new YooAssetResourceUpdateService(),
                new HybridCLRLoader(),
                new TableKitConfigLoader());

            pipeline.StepChanged += step => Log("STEP " + step);
            pipeline.DownloadProgressChanged += progress => Log("DOWNLOAD " + progress.ToString("P1"));
            await pipeline.RunAsync(cts.Token);
            Log("STARTUP_PIPELINE_PLAYER_TEST_PASS");
        }
        catch (Exception e)
        {
            Log("STARTUP_PIPELINE_PLAYER_TEST_FAIL " + e);
        }
        finally
        {
            _finished = true;
        }
    }

    private void Log(string message)
    {
        _logs.Add(message);
        if (_logs.Count > 12)
            _logs.RemoveAt(0);
        Debug.Log(message);
    }
}
