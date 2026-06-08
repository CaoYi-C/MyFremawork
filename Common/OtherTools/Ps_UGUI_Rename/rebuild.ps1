#Requires -RunAsAdministrator
# ============================================================
#  UGUI 图层命名工具 - 从源码目录打包 + 签名 + 部署
#  源 = Ps_UGUI_Rename\com.ugui.rename\  (你直接在这里改源码)
#  输出 zxp = Ps_UGUI_Rename\com.ugui.rename.zxp  (覆盖旧的)
#  部署目标 = C:\Program Files (x86)\Common Files\Adobe\CEP\extensions\com.ugui.rename
# ============================================================
$ErrorActionPreference = 'Stop'
$utf8NoBom = New-Object System.Text.UTF8Encoding($false)

# 资源都在 Ps_UGUI_Rename 同目录(脚本同目录)
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Definition
$src       = Join-Path $scriptDir 'com.ugui.rename'         # 源码(你改这里)
$zxpsign   = Join-Path $scriptDir 'ZXPSignCmd.exe'
$p12       = Join-Path $scriptDir 'UGUI_Rename.p12'
$zxpDest   = Join-Path $scriptDir 'com.ugui.rename.zxp'     # 给同事分发的 zxp
$ext       = "C:\Program Files (x86)\Common Files\Adobe\CEP\extensions\com.ugui.rename"

Write-Host ""
Write-Host "=== UGUI 图层命名工具 - 从源码打包签名 ===" -ForegroundColor Cyan
Write-Host "  source : $src" -ForegroundColor Gray
Write-Host "  zxp    : $zxpDest" -ForegroundColor Gray
Write-Host "  deploy : $ext" -ForegroundColor Gray
Write-Host ""

# 前置检查
if (-not (Test-Path $src))     { throw "Missing source folder: $src`n请在 Ps_UGUI_Rename 下放 com.ugui.rename 源码目录" }
if (-not (Test-Path "$src\client\index.html")) { throw "$src 不是有效的扩展目录(缺少 client/index.html)" }
if (-not (Test-Path $zxpsign)) { throw "Missing: $zxpsign" }
if (-not (Test-Path $p12))     { throw "Missing: $p12" }

# ---------- 1) 复制源码到临时位置(干净快照)----------
$work   = Join-Path $env:TEMP ("ugui_build_" + [guid]::NewGuid().ToString("N"))
$stage  = Join-Path $work "stage"
$zxpTmp = Join-Path $work "com.ugui.rename.zxp"
New-Item -ItemType Directory -Path $stage -Force | Out-Null
Copy-Item -Path (Join-Path $src '*') -Destination $stage -Recurse -Force

# 清掉旧 META-INF 签名(让 ZXPSignCmd 重新生成,避免与源码 hash 不一致)
$metaInf = Join-Path $stage 'META-INF'
if (Test-Path $metaInf) {
    Get-ChildItem $metaInf -Recurse -Force -ErrorAction SilentlyContinue |
        Where-Object { $_.Name -match 'signature|ZXP' } |
        Remove-Item -Recurse -Force
}
Write-Host "[1/5] Staged source (META-INF cleaned): $stage" -ForegroundColor Green

# ---------- 2) 询问密码,签名 ----------
$secure = Read-Host "请输入 .p12 证书密码 (UGUI_Rename.p12)" -AsSecureString
$cred   = New-Object PSCredential "u", $secure
$plain  = $cred.GetNetworkCredential().Password
$secure = $null

Write-Host "[2/5] Signing ..." -ForegroundColor Cyan
$proc = Start-Process -FilePath $zxpsign `
    -ArgumentList @('-sign', $stage, $zxpTmp, $p12, $plain) `
    -NoNewWindow -Wait -PassThru
$plain = $null

if ($proc.ExitCode -ne 0) {
    Remove-Item -Path $work -Recurse -Force -ErrorAction SilentlyContinue
    throw "ZXPSignCmd exit = $($proc.ExitCode) (密码错?证书过期?)"
}
$zxpSize = [math]::Round((Get-Item $zxpTmp).Length / 1KB, 1)
Write-Host "  zxp: $zxpTmp ($zxpSize KB)" -ForegroundColor Green

# ---------- 3) 部署签名后的内容到 $ext(robocopy 镜像替换)----------
$robocmd = "robocopy `"$stage`" `"$ext`" /MIR /NFL /NDL /NJH /NJS /NP /R:3 /W:1"
$proc = Start-Process -FilePath 'cmd.exe' -ArgumentList '/c', $robocmd -NoNewWindow -Wait -PassThru
# robocopy 0-3 = 成功(含镜像删除多余文件),>=8 = 错误
if ($proc.ExitCode -ge 8) {
    Write-Host "[WARN] Robocopy exit = $($proc.ExitCode) (检查日志)" -ForegroundColor Yellow
}
Write-Host "[3/5] Deployed signed extension to $ext" -ForegroundColor Green

# ---------- 4) 复制 zxp 到 Ps_UGUI_Rename(覆盖旧的)----------
Copy-Item -Path $zxpTmp -Destination $zxpDest -Force
Write-Host "[4/5] Updated zxp at: $zxpDest" -ForegroundColor Green

# ---------- 5) 验证签名(可选 sanity check)----------
$verify = Start-Process -FilePath $zxpsign -ArgumentList @('-verify', $ext) -NoNewWindow -Wait -PassThru
if ($verify.ExitCode -eq 0) {
    Write-Host "[5/5] Signature verified" -ForegroundColor Green
} else {
    Write-Host "[5/5] Signature verify exit = $($verify.ExitCode) (无 -tsa 警告可忽略)" -ForegroundColor Yellow
}

# 清理
Remove-Item -Path $work -Recurse -Force -ErrorAction SilentlyContinue

Write-Host ""
Write-Host "DONE. Restart Photoshop." -ForegroundColor Cyan
Write-Host "  -> 你 PS 里的扩展已用最新源码部署" -ForegroundColor Gray
Write-Host "  -> com.ugui.rename.zxp 已用最新源码重新签名,可发同事" -ForegroundColor Gray
Write-Host ""
Write-Host "Press any key to exit..." -ForegroundColor DarkGray
$null = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown')
