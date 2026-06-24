@echo off
REM ============================================================
REM  UGUI 图层命名工具 - 重建 + 重签名入口
REM  双击此文件,会自动请求 UAC 提升并调 rebuild.ps1
REM ============================================================
setlocal

cd /d "%~dp0"

net session >nul 2>&1
if %errorLevel% neq 0 (
    echo Requesting admin privileges...
    powershell -Command "Start-Process cmd -ArgumentList '/c \"\"%~f0\"\"' -Verb RunAs"
    exit /b
)

echo Running rebuild as administrator...
echo.
powershell -ExecutionPolicy Bypass -File "%~dp0rebuild.ps1"

endlocal
