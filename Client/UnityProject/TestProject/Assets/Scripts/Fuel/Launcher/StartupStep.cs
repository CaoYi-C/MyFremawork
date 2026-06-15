namespace Fuel.Launcher
{
    public enum StartupStep
    {
        None,
        LoadLocalConfig,
        FetchRemoteVersion,
        CheckAppVersion,
        InitAssets,
        UpdateAssets,
        LoadAotMetadata,
        LoadHotUpdateDll,
        EnterGame,
        Failed
    }

    public enum AppUpdateDecision
    {
        Continue,
        OptionalUpdate,
        ForceUpdate
    }
}
