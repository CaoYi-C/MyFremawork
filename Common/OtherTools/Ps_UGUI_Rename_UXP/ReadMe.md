# UGUI 图层命名工具 — UXP 版

> UXP (Unified Extensibility Platform) 是 Adobe 在 PS 2022+ 取代旧 CEP
> 的新插件架构。**这是旧 CEP 版的迁移版,功能等价,代码用现代 JS**。
>
> 旧 CEP 版在 `../Ps_UGUI_Rename/` 下,保留作为 PS 2021 及更老的回退方案。

Photoshop 2024+ 用的 UXP 扩展,给选中的图层批量加 Unity UGUI 前缀(`btn_` /
`txt_` / `img_` 等)以及 9-slice 后缀。

---

## 文件结构

```
Ps_UGUI_Rename_UXP\
├── manifest.json            扩展元数据(UXP 5,manifestVersion 5)
├── host.js                  后端逻辑(直接 require,不走 evalScript)
├── client\
│   ├── index.html           面板 HTML(删了 CSInterface 引用)
│   ├── index.js             面板逻辑(用 UXP 内置 photoshop 模块)
│   ├── style.css            面板样式(跟旧版一致)
│   └── font_mapping.js      字体 tag 映射表(跟旧版一致)
│
├── install.cmd              同事首次安装入口(双击)
├── install.ps1              部署到 %APPDATA%\Adobe\UXP\Plugins\
│                            + 注册表 com.adobe.ccx.start.allow=1
│
├── rebuild.cmd              本地改源码后入口(双击)
├── rebuild.ps1              镜像同步源码到 UXP 插件目录
│
└── ReadMe.md                本文件
```

---

## 与 CEP 版的差异速查

| 维度 | CEP 旧版 (`Ps_UGUI_Rename/`) | UXP 版 (`Ps_UGUI_Rename_UXP/`) |
|------|-----------------------------|--------------------------------|
| 后端语言 | ExtendScript (ES3) | 现代 JS (ES2022) |
| 跟 PS 通信 | `csInterface.evalScript('fn()')` | `require('photoshop').app` 直接访问 |
| 写文档 | 同步 | 必须包在 `executeAsModal` 里 |
| 命名约定 | `host/UGUI_Rename.jsx` | `host.js`(去掉 JSX 后缀) |
| 参数序列化 | JSON 字符串(evalScript 限制) | 直接传 JS 对象 |
| Manifest | `CSXS/manifest.xml` | `manifest.json` |
| 安装路径 | `Common Files\Adobe\CEP\extensions\` | `%APPDATA%\Adobe\UXP\Plugins\` |
| 签名 | `.p12` + ZXPSignCmd | **不需要**(开发模式由 `com.adobe.ccx.start.allow=1` 豁免) |
| 调试豁免 | `PlayerDebugMode=1` | `com.adobe.ccx.start.allow=1` (UXP 5..7) |
| 字体前缀 | `mime`, `META-INF\signatures.xml` | 不需要 |
| 兼容性 | PS 2015+ | **PS 2022+ (UXP 5+)** |

---

## 修改流程

1. 在 `Ps_UGUI_Rename_UXP\` 里直接改源码
   - 改完记得**先关掉 PS**(避免文件被锁)
2. 双击 `rebuild.cmd`
3. UAC 弹窗点"是" → 看到 `DONE. Restart Photoshop.`
4. 打开 PS,`窗口` → `扩展` → `UGUI 图层命名工具`,改动生效

**脚本做了什么:**
- robocopy 镜像同步源码到 `%APPDATA%\Adobe\UXP\Plugins\`
- (首次) 设注册表 `com.adobe.ccx.start.allow=1` 启用开发模式

---

## 安装流程(首次 / 给同事)

1. 把整个 `Ps_UGUI_Rename_UXP\` 文件夹压缩成 zip / 7z 发给同事
2. 同事解压到任意位置
3. 双击 `install.cmd`
4. UAC 弹"是" → 看到 `DONE`
5. 重启 PS,`窗口` → `扩展` → `UGUI 图层命名工具`

> 因为是开发模式(无 Adobe 签名),首次安装脚本会自动注册表豁免。
> 如果想正式分发走 Creative Cloud 上架,需要去 Adobe Developer Console
> 申请签名证书并打包 `.ccx`,这个流程 PS 23+ 支持但需要 Adobe ID。

---

## 设计师工作流(跟旧版完全一致)

跟 CEP 旧版一模一样的功能:

1. **加 UGUI 前缀** — 选中图层,点 `btn_` / `img_` / `txt_` / `export_` / 自定义前缀按钮
2. **加 9-slice 后缀** — 选中图层,设 L/T/R/B,点 `应用 9-slice`
   - 自动补前缀:对没有 UGUI 前缀的图层,自动拼上 `img_` 或 `btn_`
3. **加字体后缀** — 选中 `txt_` 图层,选字体 tag,点应用
4. **移除** — 每个面板都有对应的 `移除` 按钮

---

## 故障排查

### 启动后找不到面板

- `窗口` → `扩展` 应该能看到 `UGUI 图层命名工具`
- 看不到 → 检查 `manifest.json` 的 `host.minVersion`,确认你 PS 版本 >= 23.0
- 看到但空白 → 重启 PS(UXP 的 host module 加载失败时常表现为空白面板)

### 点了按钮没反应 / 报 `Cannot perform action outside of modal scope`

- 这是 host.js 内部 `executeAsModal` 没包好的症状
- 检查 `host.js` 的 `core.executeAsModal` 包裹范围 — 任何写 `layer.name`
  的操作都必须在 modal 里

### 点了按钮报 `host is undefined`

- `client/index.js` 顶部 `require('../host.js')` 路径不对
- UXP 的 panel base dir 是 manifest.json 所在目录(`Ps_UGUI_Rename_UXP/`)
- 检查 `client/index.html` 跟 `host.js` 的相对位置

### Robocopy 退出码 >= 8

- 检查 PS 是否真的关了(占用了 `%APPDATA%\Adobe\UXP\Plugins\` 里的文件)
- 重跑一次通常就好

### PS 版本太老(< 2022)

- UXP 5 是 PS 2022 引入的,你这版本不支持
- 回退到 `../Ps_UGUI_Rename/` (CEP 版,支持 PS 2015+)

---

## 注意事项

- **改完代码一定要先关 PS** 再跑 `rebuild.cmd`
- 脚本会自动清理 `%TEMP%\ugui_*` 临时目录(如有遗留直接删)
- 整套流程只在 Windows 上验证过;Mac / Linux 下 `AppData` 路径不同,
  需要改 `install.ps1` / `rebuild.ps1` 里的 `$env:APPDATA` 替换逻辑
- `manifest.json` 的 `requiredPermissions.localFileSystem: "plugin"`
  只授权读扩展自身目录,不会让插件读到用户其它文件 —
  如果以后插件需要写用户文件,改成 `"read"` 等级

---

## 迁移历史

| 版本 | 架构 | 后端 | 状态 |
|------|------|------|------|
| 1.0 (CEP) | Common Extensibility Platform | ExtendScript (ES3) | `../Ps_UGUI_Rename/` 维护中 |
| 2.0 (UXP) | Unified Extensibility Platform | ES2022 + Photoshop API | 本目录,新开发在这 |