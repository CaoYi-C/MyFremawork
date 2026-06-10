<#
.SYNOPSIS
  打包 MiniMax Code (Mavis) 配置目录,方便迁移到新设备。

.DESCRIPTION
  把 ~/.mavis/ 下的关键内容(skills、agents、memory、hooks 等)打成 zip,
  并自动生成一份还原说明。

  三种模式:
    all    - 打包整个 mavis 数据目录(推荐,首次迁移用)
    skills - 只打包技能(全局 + agent 专属)
    agents - 只打包 agent 配置(含其专属技能)

.PARAMETER Mode
  打包模式: all / skills / agents,默认 all

.PARAMETER OutputPath
  压缩包输出目录,默认桌面

.EXAMPLE
  # 默认:打包整个 mavis 目录到桌面
  .\mavis-migrate.ps1

  # 只打包技能
  .\mavis-migrate.ps1 -Mode skills

  # 打包到指定位置
  .\mavis-migrate.ps1 -OutputPath D:\backup

.NOTES
  兼容 PowerShell 5.1 (Windows 10/11 自带版本)。
  模板内容 base64 内嵌,单文件即可运行。
#>

param(
    [ValidateSet("all", "skills", "agents")]
    [string]$Mode = "all",
    [string]$OutputPath = "$env:USERPROFILE\Desktop"
)

$ErrorActionPreference = "Stop"

# ---------- helpers ----------
function Say {
    param([string]$msg = "", [string]$color = "White")
    if ([string]::IsNullOrEmpty($msg)) { Write-Host "" } else { Write-Host $msg -ForegroundColor $color }
}

function Get-DirSizeMB ($p) {
    if (-not (Test-Path $p)) { return 0 }
    $bytes = (Get-ChildItem -Path $p -Recurse -File -ErrorAction SilentlyContinue |
              Measure-Object -Property Length -Sum).Sum
    if ($null -eq $bytes) { return 0 }
    return [math]::Round($bytes / 1048576, 2)
}

# ---------- 模板 (base64 内嵌) ----------
$TemplateB64 = "TWluaU1heCBDb2RlIOmFjee9rui/mOWOn+ivtOaYjgo9PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PQoK5omT5YyF5pe26Ze0OiAgIF9fVElNRVNUQU1QX18K5omT5YyF5qih5byPOiAgIF9fTU9ERV9fCuWOi+e8qeWMhTogICAgIF9fWklQTkFNRV9fCgpb6L+Y5Y6f5q2l6aqkXQoKMS4g5oqK5Y6L57yp5YyFIF9fWklQTkFNRV9fIOaLt+WIsOaWsOiuvuWkh+eahOS7u+aEj+S9jee9rijmr5TlpoLmoYzpnaIp44CCCjIuIOehruiupOaWsOiuvuWkh+W3sue7j+WuieijhSBNaW5pTWF4IENvZGUg5bm26Iez5bCR5ZCv5Yqo6L+H5LiA5qyhKOWIm+W7uuWHuiBtYXZpcyDnm67lvZUp44CCCjMuIOaJk+W8gCBQb3dlclNoZWxsLOaJp+ihjDoKCiAgICAgICBFeHBhbmQtQXJjaGl2ZSAtUGF0aCAiX19aSVBOQU1FX18iIC1EZXN0aW5hdGlvblBhdGggIiRlbnY6VVNFUlBST0ZJTEVcLm1hdmlzIiAtRm9yY2UKCiAgIC0g5YqgIC1Gb3JjZSDkvJropobnm5bnjrDmnIkgbWF2aXMg55uu5b2V6YeM55qE5ZCM5ZCN5paH5Lu244CCCiAgIC0g5aaC5p6c5paw6K6+5aSH6Lev5b6E5LiN5ZCMLOaKiiAkZW52OlVTRVJQUk9GSUxFIOaUueaIkOWunumZheeahOeUqOaIt+ebruW9lSjkvovlpoIgQzpcVXNlcnNcT3RoZXJVc2VyKeOAggoKNC4g5a6M5YWo5YWz6Zet5bm26YeN5ZCvIE1pbmlNYXggQ29kZSxkYWVtb24g5Lya6Ieq5Yqo6YeN5paw5Yqg6L296YWN572u5ZKM5oqA6IO944CCCgpb5pys5qyh5YyF5ZCr55qE5YaF5a65XQpfXNPVVJDRVNfXwoKW+azqOaEj+S6i+mhuV0KCi0g5aaC5p6c5paw6K6+5aSH5pyJ6Ieq5bex5bey57uP6LCD5aW955qEIHNraWxscy9hZ2VudHMs5YWI5Y2V54us5aSH5Lu95YaN6KaG55uW44CCCi0g6aOe5LmmIC8gVGVsZWdyYW0g562JIElNIOWHreaNruWmguaenOS4jemcgOimgeWcqOaWsOiuvuWkh+eUqCzlj6/ku6Xku44gemlwIOmHjOWIoOaOieWGjei/mOWOn+OAggotIHNlc3Npb25zIOebruW9leaYr+WvueivneWOhuWPsizlj6/mjInpnIDkv53nlZnmiJbliKDpmaTjgIIK"

# ---------- 路径 ----------
$MavisDir = Join-Path $env:USERPROFILE ".mavis"

$bannerLine = "==> MiniMax Code 配置打包工具"
Say $bannerLine Cyan
Say ""

# ---------- 预检查 ----------
$missingMavis = "找不到 mavis 目录: " + $MavisDir
$noContent    = "没有可打包的内容 (Mode=" + $Mode + ")"
$canceled     = "已取消。"
$packFail     = "打包失败: "
$notFoundHint = "    请确认你在这台设备上跑过 MiniMax Code。"

if (-not (Test-Path $MavisDir)) {
    Say $missingMavis Red
    Say $notFoundHint
    exit 1
}

if (-not (Test-Path $OutputPath)) {
    New-Item -ItemType Directory -Path $OutputPath -Force | Out-Null
}

# ---------- 选择要打包的内容 ----------
$sources = @()
$includeAll = $false
$globalSkills = Join-Path $MavisDir "skills"
$agentsDir    = Join-Path $MavisDir "agents"

switch ($Mode) {
    "all" {
        $sources += $MavisDir
        $includeAll = $true
    }
    "skills" {
        if (Test-Path $globalSkills) { $sources += $globalSkills }
        if (Test-Path $agentsDir)    { $sources += $agentsDir }
    }
    "agents" {
        if (Test-Path $agentsDir)    { $sources += $agentsDir }
    }
}

if ($sources.Count -eq 0) {
    Say $noContent Red
    exit 1
}

# ---------- 显示打包计划 ----------
$modeLine = "  模式:     " + $Mode
$outLine  = "  输出:     " + $OutputPath
$includesLine = "  包含:"
Say $modeLine
Say $outLine
Say $includesLine
foreach ($s in $sources) {
    $size = Get-DirSizeMB $s
    $rel = $s.Replace($MavisDir, "~/.mavis")
    $entry = "    - " + $rel + "  (" + $size + " MB)"
    Say $entry
}
Say ""

# ---------- 确认 ----------
$confirmPrompt = "  确认开始打包? (y/N)"
$confirm = Read-Host $confirmPrompt
if ($confirm -ne "y" -and $confirm -ne "Y") {
    Say $canceled Yellow
    exit 0
}

# ---------- 打包 ----------
$timestamp = Get-Date -Format "yyyyMMdd-HHmmss"
$zipName = "mavis-backup-" + $Mode + "-" + $timestamp + ".zip"
$zipPath = Join-Path $OutputPath $zipName
$readmePath = Join-Path $OutputPath "mavis-restore-README.txt"

$packingLine = "==> 正在打包..."
Say $packingLine Cyan
try {
    if ($includeAll) {
        Compress-Archive -Path (Join-Path $MavisDir "*") -DestinationPath $zipPath -CompressionLevel Optimal
    } else {
        Compress-Archive -Path $sources -DestinationPath $zipPath -CompressionLevel Optimal
    }
}
catch {
    $errMsg = $packFail + $_.Exception.Message
    Say $errMsg Red
    exit 1
}

$zipSize = [math]::Round((Get-Item $zipPath).Length / 1048576, 2)
$zipLine = " [OK] 压缩包: " + $zipPath + " (" + $zipSize + " MB)"
Say $zipLine Green

# ---------- 生成还原说明 ----------
$sourcesList = ""
foreach ($s in $sources) {
    $sourcesList += "  - " + $s + [Environment]::NewLine
}
$sourcesList = $sourcesList.TrimEnd([Environment]::NewLine.ToCharArray())

$nowStr  = Get-Date -Format 'yyyy-MM-dd HH:mm:ss'
$tplBytes = [Convert]::FromBase64String($TemplateB64)
$readme = ([System.Text.Encoding]::UTF8.GetString($tplBytes)) `
    -replace '__TIMESTAMP__', $nowStr `
    -replace '__MODE__', $Mode `
    -replace '__ZIPNAME__', $zipName `
    -replace '__SOURCES__', $sourcesList

$readme | Out-File -FilePath $readmePath -Encoding UTF8

$readmeLine = " [OK] 还原说明: " + $readmePath
Say $readmeLine Green

$doneLine = "==> 完成。把以下两个文件拷到新设备即可:"
Say $doneLine Cyan
Say ("  - " + $zipPath) -color White
Say ("  - " + $readmePath) -color White
Say ""
