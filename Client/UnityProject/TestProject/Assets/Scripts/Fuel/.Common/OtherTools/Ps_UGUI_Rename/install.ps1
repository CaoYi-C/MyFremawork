#Requires -RunAsAdministrator
# ============================================================
#  UGUI 图层命名工具 一键安装脚本
#  放在 Ps_UGUI_Rename 文件夹下,与 com.ugui.rename.zxp 同级
#  1) 把 zxp 解压并部署到 CEP extensions 目录
#  2) 给 CSXS.5 ~ CSXS.13 都设 PlayerDebugMode=1
#     (覆盖 PS 2015 ~ PS 2024+,这样不用关心 PS 版本号)
#  3) 用 ZXPSignCmd -verify 自验签名(若有 ZXPSignCmd.exe)
# ============================================================
$ErrorActionPreference = 'Stop'
$utf8NoBom = New-Object System.Text.UTF8Encoding($false)

# 资源定位(默认在脚本同目录,这样 install.ps1 在哪都能跑)
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Definition
$zxp       = Join-Path $scriptDir 'com.ugui.rename.zxp'
$zxpsign   = Join-Path $scriptDir 'ZXPSignCmd.exe'
$ext       = "C:\Program Files (x86)\Common Files\Adobe\CEP\extensions\com.ugui.rename"

Write-Host ""
Write-Host "=== UGUI 图层命名工具 一键安装 ===" -ForegroundColor Cyan
Write-Host ""

# ---------- 1) 前置检查 ----------
if (-not (Test-Path $zxp)) {
    throw "Missing file: $zxp`nPlease put this script in the same folder as com.ugui.rename.zxp"
}

# ---------- 2) 创建目标目录(CEP extensions)----------
New-Item -ItemType Directory -Path $ext -Force | Out-Null

# ---------- 3) 解压 zxp 到临时位置(.zxp 本质是 zip)----------
$tempExtract = Join-Path $env:TEMP ("ugui_install_" + [guid]::NewGuid().ToString("N"))
New-Item -ItemType Directory -Path $tempExtract -Force | Out-Null
Add-Type -AssemblyName System.IO.Compression.FileSystem
[System.IO.Compression.ZipFile]::ExtractToDirectory($zxp, $tempExtract)
Write-Host "[1/4] Extracted zxp to temp" -ForegroundColor Green

# ---------- 4) 镜像替换到 CEP extensions(用 cmd /c 包 robocopy 避开引号坑)----------
$robocmd = "robocopy `"$tempExtract`" `"$ext`" /MIR /NFL /NDL /NJH /NJS /NP /R:3 /W:1"
$proc = Start-Process -FilePath 'cmd.exe' -ArgumentList '/c', $robocmd -NoNewWindow -Wait -PassThru
if ($proc.ExitCode -ge 8) {
    Remove-Item -Path $tempExtract -Recurse -Force -ErrorAction SilentlyContinue
    throw "Robocopy failed (exit code = $($proc.ExitCode))"
}
Write-Host "[2/4] Deployed to $ext" -ForegroundColor Green

# ---------- 5) PlayerDebugMode = 1(覆盖 CSXS.5 ~ CSXS.13)----------
# CSXS.5=PS2015, .6=2015.5, .7=2017, .8=2018, .9=2019, .10=2020/2021, .11=2022/2023/2024, .12=2025, .13=2026
$csxsList = 5..13
foreach ($v in $csxsList) {
    $key = "HKCU:\SOFTWARE\Adobe\CSXS.$v"
    if (-not (Test-Path $key)) { New-Item -Path $key -Force | Out-Null }
    Set-ItemProperty -Path $key -Name 'PlayerDebugMode' -Value 1 -Type DWord
}
Write-Host "[3/4] PlayerDebugMode=1 set on CSXS.5 ~ CSXS.13" -ForegroundColor Green

# ---------- 6) 验证签名(如果 ZXPSignCmd.exe 在同目录)----------
if (Test-Path $zxpsign) {
    $verify = Start-Process -FilePath $zxpsign -ArgumentList @('-verify', $ext) -NoNewWindow -Wait -PassThru
    if ($verify.ExitCode -eq 0) {
        Write-Host "[4/4] Signature verified" -ForegroundColor Green
    } else {
        Write-Host "[4/4] Signature verify exit code = $($verify.ExitCode) (can be normal without -tsa)" -ForegroundColor Yellow
    }
} else {
    Write-Host "[4/4] ZXPSignCmd.exe not found, skipped signature verify" -ForegroundColor Yellow
}

# ---------- 7) 清理临时目录 ----------
Remove-Item -Path $tempExtract -Recurse -Force -ErrorAction SilentlyContinue

Write-Host ""
Write-Host "DONE. Restart Photoshop and open the panel from" -ForegroundColor Cyan
Write-Host "  窗口 -> 扩展 -> UGUI 图层命名工具" -ForegroundColor Gray
Write-Host ""
Write-Host "Press any key to exit..." -ForegroundColor DarkGray
$null = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown')
