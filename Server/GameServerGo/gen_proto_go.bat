@echo off
setlocal EnableExtensions

REM ============================================================
REM  gen_proto_go.bat
REM  把 ../Client/.../ProtoTool/Proto/*.proto 生成 .pb.go 到本目录的 proto/
REM
REM  前置条件:
REM    1. 安装 Go 1.25+
REM    2. go install google.golang.org/protobuf/cmd/protoc-gen-go@latest
REM       (确保 $(go env GOPATH)\bin 在 PATH 里)
REM
REM  用法:
REM    cd Server\GameServerGo
REM    gen_proto_go.bat
REM ============================================================

REM --- 路径配置(必要时手动改) ---
set "PROTO_SRC=D:\UnityProject\Test\MyFremawork\Client\UnityProject\TestProject\Assets\Scripts\Fuel\.Common\ProtoTool\Proto"
set "PROTOC_EXE=D:\UnityProject\Test\MyFremawork\Client\UnityProject\TestProject\Assets\Scripts\Fuel\.Common\ProtoTool\protoc.exe"
set "OUT_DIR=%~dp0proto"

REM --- 校验 ---
if not exist "%PROTO_SRC%" (
    echo [ERROR] PROTO_SRC not found: "%PROTO_SRC%"
    echo         Edit gen_proto_go.bat and fix PROTO_SRC / PROTOC_EXE paths.
    exit /b 1
)
if not exist "%PROTOC_EXE%" (
    echo [ERROR] PROTOC_EXE not found: "%PROTOC_EXE%"
    exit /b 1
)
where protoc-gen-go >nul 2>nul
if errorlevel 1 (
    echo [ERROR] protoc-gen-go not in PATH. Run: go install google.golang.org/protobuf/cmd/protoc-gen-go@latest
    exit /b 1
)

REM --- 清空旧产物 ---
if exist "%OUT_DIR%" (
    echo [INFO] Cleaning "%OUT_DIR%" ...
    rmdir /s /q "%OUT_DIR%"
)
mkdir "%OUT_DIR%"

REM --- 逐个文件生成 ---
set "COUNT=0"
set "ERR=0"
for /r "%PROTO_SRC%" %%F in (*.proto) do (
    set /a COUNT+=1
    set "SRC=%%F"
    setlocal EnableDelayedExpansion
    set "REL=!SRC:%PROTO_SRC%\=!"
    if "!REL:~0,1!"=="\" set "REL=!REL:~1!"
    set "DST_DIR=%OUT_DIR%\!REL!"
    for %%D in ("!DST_DIR!") do set "DST_DIR=%%~dpD"
    endlocal & set "REL=%REL%" & set "DST_DIR=%OUT_DIR%\%REL%"

    for %%D in ("%OUT_DIR%\%REL%") do set "DST_DIR=%%~dpD"
    if not exist "%DST_DIR%" mkdir "%DST_DIR%" >nul 2>nul

    echo [GO ] "!REL!"
    "%PROTOC_EXE%" --proto_path="%PROTO_SRC%" --go_out="%OUT_DIR%" --go_opt=paths=source_relative "%%F"
    if errorlevel 1 (
        echo [ERR] %%F
        set /a ERR+=1
    ) else (
        echo [OK ] %%F
    )
)

echo.
echo ============================================================
echo Done. Total=%COUNT% Errors=%ERR%
echo Generated files under: %OUT_DIR%
echo ============================================================
if %ERR% gtr 0 exit /b 5
exit /b 0