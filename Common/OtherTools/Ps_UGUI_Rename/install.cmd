@echo off
REM ============================================================
REM  UGUI 图层命名工具 一键安装入口
REM  双击此文件,会自动请求 UAC 提升并调 install.ps1
REM ============================================================
setlocal

REM 切到脚本所在目录(保证 install.ps1 在同目录能找到)
cd /d "%~dp0"

REM 检查是否已是管理员
net session >nul 2>&1
if %errorLevel% neq 0 (
    echo Requesting admin privileges...
    powershell -Command "Start-Process cmd -ArgumentList '/c \"\"%~f0\"\"' -Verb RunAs"
    exit /b
)

REM 已是管理员,跑 install.ps1
echo Running installer as administrator...
echo.
powershell -ExecutionPolicy Bypass -File "%~dp0install.ps1"

endlocal
