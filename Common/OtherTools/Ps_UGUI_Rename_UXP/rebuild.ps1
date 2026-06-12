#Requires -RunAsAdministrator
# ============================================================
#  UGUI 图层命名工具 UXP 版 — 改完源码 → 快速刷新
#
#  与旧 CEP rebuild.ps1 的关键差异:
#  - 没有打包步骤(UXP 直接吃文件夹,不需要 .zxp)
#  - 没有签名步骤(开发模式由 com.adobe.ccx.start.allow 豁免)
#  - 没有 deploy 到 CEP extensions 那一步(路径不同 — 在用户 AppData)
#  - 流程:robocopy 镜像同步到 %APPDATA%\Adobe\UXP\Plugins\
#    → 提示重启 PS
#
#  用法:改完任意源码后双击 rebuild.cmd → UAC → DONE
# ============================================================
$ErrorActionPreference = 'Stop'

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Definition
$src       = Join-Path $scriptDir 'manifest.json'
$uxpRoot   = Join-Path $env:APPDATA 'Adobe\UXP\Plugins'

if (-not (Test-Path $src)) {
    throw "Missing: $src`n请在 Ps_UGUI_Rename_UXP 下放 manifest.json"
}

Write-Host ""
Write-Host "=== UGUI 图层命名工具 UXP 版 - 刷新已部署的副本 ===" -ForegroundColor Cyan
Write-Host "  source : $scriptDir" -ForegroundColor Gray
Write-Host "  target : $uxpRoot" -ForegroundColor Gray
Write-Host ""

# ---------- 1) 镜像替换到 UXP 插件目录 ----------
# robocopy 0-3 = 成功(含镜像删除多余文件),>=8 = 错误
$robocmd = "robocopy `"$scriptDir`" `"$uxpRoot`" /MIR /NFL /NDL /NJH /NJS /NP /R:3 /W:1"
$proc = Start-Process -FilePath 'cmd.exe' -ArgumentList '/c', $robocmd -NoNewWindow -Wait -PassThru
if ($proc.ExitCode -ge 8) {
    throw "Robocopy failed (exit code = $($proc.ExitCode))"
}
Write-Host "[1/1] Synced to $uxpRoot" -ForegroundColor Green

Write-Host ""
Write-Host "DONE. Restart Photoshop." -ForegroundColor Cyan
Write-Host "  -> 你 PS 里的 UGUI 图层命名工具已用最新源码刷新" -ForegroundColor Gray
Write-Host ""
Write-Host "Press any key to exit..." -ForegroundColor DarkGray
$null = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown')