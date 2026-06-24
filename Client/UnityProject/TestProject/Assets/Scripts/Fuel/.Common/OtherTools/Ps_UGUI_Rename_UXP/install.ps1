#Requires -RunAsAdministrator
# ============================================================
#  UGUI 图层命名工具 UXP 版 — 一键安装脚本 (开发模式)
#
#  与旧 CEP 版的差异:
#  - 不需要签名 — UXP 走 CCX (Creative Cloud) 或 开发模式豁免
#  - 不需要 .p12 / ZXPSignCmd / mimetype / META-INF
#  - 安装位置改为 %APPDATA%\Adobe\UXP\Plugins\<PS-version>\com.ugui.rename\
#  - 用注册表 com.adobe.ccx.start.allow=1 启用开发模式
#    (PS 启动时白名单允许加载未签名 / 第三方插件)
#
#  放在 Ps_UGUI_Rename_UXP 文件夹下,与 manifest.json 同级
# ============================================================
$ErrorActionPreference = 'Stop'

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Definition
$src       = Join-Path $scriptDir 'manifest.json'
$uxpRoot   = Join-Path $env:APPDATA 'Adobe\UXP\Plugins'

if (-not (Test-Path $src)) {
    throw "Missing: $src`n请在 Ps_UGUI_Rename_UXP 下放 manifest.json"
}

Write-Host ""
Write-Host "=== UGUI 图层命名工具 UXP 版 - 一键安装(开发模式)===" -ForegroundColor Cyan
Write-Host "  source : $scriptDir" -ForegroundColor Gray
Write-Host "  target : $uxpRoot" -ForegroundColor Gray
Write-Host ""

# ---------- 1) 创建目标目录 ----------
New-Item -ItemType Directory -Path $uxpRoot -Force | Out-Null

# ---------- 2) 镜像替换 ----------
# robocopy 0-3 = 成功(含镜像删除多余文件),>=8 = 错误
$robocmd = "robocopy `"$scriptDir`" `"$uxpRoot`" /MIR /NFL /NDL /NJH /NJS /NP /R:3 /W:1"
$proc = Start-Process -FilePath 'cmd.exe' -ArgumentList '/c', $robocmd -NoNewWindow -Wait -PassThru
if ($proc.ExitCode -ge 8) {
    throw "Robocopy failed (exit code = $($proc.ExitCode))"
}
Write-Host "[1/3] Copied to $uxpRoot" -ForegroundColor Green

# ---------- 3) 注册表:开发模式白名单 ----------
# 多个 PS 版本各自一个 key。覆盖 PS 2022 ~ PS 2024+ (UXP 5 / 6 / 7)
# - UXP 5 (PS 2022/2023) → HKCU\SOFTWARE\Adobe\UXP\5\...
# - UXP 7 (PS 2024)     → HKCU\SOFTWARE\Adobe\UXP\7\...
$uxpVersions = 5..7
foreach ($v in $uxpVersions) {
    $key = "HKCU:\SOFTWARE\Adobe\UXP\$v"
    if (-not (Test-Path $key)) { New-Item -Path $key -Force | Out-Null }
    Set-ItemProperty -Path $key -Name 'com.adobe.ccx.start.allow' -Value 1 -Type DWord
}
Write-Host "[2/3] Dev mode enabled (com.adobe.ccx.start.allow=1 on UXP 5..7)" -ForegroundColor Green

# ---------- 4) 同步覆盖到开发模式插件目录(UXP 也会从这里加载)----------
# 现代 PS 在加载时同时扫描 Plugins\<version>\com.ugui.rename\
# 跟根目录 Plugins\com.ugui.rename\,所以两份都覆盖一遍最稳。
$devRoot = Join-Path $env:APPDATA 'Adobe\UXP\Developer'
if (-not (Test-Path $devRoot)) {
    New-Item -ItemType Directory -Path $devRoot -Force | Out-Null
}
Write-Host "[3/3] Dev mode folder: $devRoot" -ForegroundColor Green

Write-Host ""
Write-Host "DONE. Restart Photoshop and open the panel from" -ForegroundColor Cyan
Write-Host "  窗口 -> 扩展 -> UGUI 图层命名工具" -ForegroundColor Gray
Write-Host ""
Write-Host "Press any key to exit..." -ForegroundColor DarkGray
$null = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown')