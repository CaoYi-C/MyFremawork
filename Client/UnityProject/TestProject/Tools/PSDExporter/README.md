# PSD2UGUI

PSD → Unity UGUI 导入工具。设计师在 Photoshop 里画好 UI，跑个 Python
脚本，Unity 一键生成 Prefab + UIBind 代码。

## 总体结构

```
┌─────────────┐    ┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│  PSD 文件    │ →  │ Python 工具  │ →  │ JSON + PNG  │ →  │ Unity 导入  │
│  (设计师产出) │    │ psd_to_json │    │  中间产物    │    │  PSDImporter│
└─────────────┘    └─────────────┘    └─────────────┘    └─────────────┘
                                                                ↓
                                                        ┌─────────────┐
                                                        │ UGUI Prefab │
                                                        │ + UIBind    │
                                                        └─────────────┘
```

- **Python 端**：`Tools/PSDExporter/`，独立于 Unity，跑在命令行/CI
- **Unity 端**：`Assets/Editor/PSDImporter/`，Editor 时工具，菜单入口
- **中间产物**：JSON + PNG，写到工程外的 `PSDExport/`，不进 git

## 一次性配置

1. **安装 Python 依赖**：
   ```bash
   pip install psd-tools pillow
   ```
2. **创建 Settings 资源**：
   - Unity 菜单：`Tools > PSD Importer > Open Window`
   - 第一次打开会提示，点击 "Create default settings asset"
   - 设置 `PSD export root`（默认 `PSDExport`，即工程根目录下）
   - 设置 `Fallback font`（设计师在 PS 里指定了不存在的字体时回退到这个）

## 设计师工作流

### 1. 命名规范（决定 UGUI 组件 + UIBind 字段名）

> **详细词表见 `PREFIXES.md`** —— 唯一来源，PS 插件 / Python / C# 三边同步。

设计师可以直接在 PS 里给图层加这些前缀（手打），或者更省事的：
**用项目自带的 `Ps_UGUI_Rename` PS 插件**（`C:\Users\WWCY\Desktop\Ps_UGUI_Rename`）
批量加。安装插件后，PS 菜单 `窗口` → `扩展` → `UGUI 图层命名工具`，选中图层点按钮即可。

完整词表（17 个前缀）：

| 前缀 | UGUI 组件 | 字段名 | 备注 |
|------|----------|--------|------|
| `btn_*` | Image + Button | `Btn<Name>` | 接 onClick 在 Window.cs 写 |
| `txt_*` | Text | `Txt<Name>` | |
| `img_*` | Image | `Img<Name>` | |
| `icon_*` | Image | `Icon<Name>` | 通常嵌在 btn 里 |
| `bg_*` | Image | `Bg<Name>` | 背景 |
| `panel_*` | Image | `Panel<Name>` | 面板 |
| `progress_*` | Image (Filled) | `Progress<Name>` | fillAmount 驱动 |
| `mask_*` | Image + Mask | `Mask<Name>` | |
| `item_*` | Image | `Item<Name>` | 列表项模板 |
| `fx_*` | Image | `Fx<Name>` | 特效贴图 |
| `scroll_*` | Image | `Scroll<Name>` | **v1 部分支持**：ScrollRect 手挂 |
| `input_*` | Image | `Input<Name>` | **v1 部分支持**：InputField 手挂 |
| `toggle_*` | Image | `Toggle<Name>` | **v1 部分支持**：Toggle 手挂 |
| `slider_*` | Image | `Slider<Name>` | **v1 部分支持**：Slider 手挂 |
| `group_*` / `anim_*` / `root_*` | (无) | - | 容器，不生成绑定 |

示例（设计稿）：

```
LoginUI
├── bg_main             ← 背景图
├── btn_login           ← 登录按钮（组）
│   ├── img_normal      ← 按钮底图
│   └── txt_label       ← 按钮文字
├── txt_title           ← 标题文字
├── icon_heart          ← 红心图标
└── group_form
    ├── input_user      ← 用户名输入框
    ├── input_pass      ← 密码输入框
    └── toggle_remember ← 记住我开关
```

未带前缀的图层也会被处理，只是不生成 UIBind 字段。

### 2. 导出

```bash
cd Tools/PSDExporter
python psd_to_json.py path/to/LoginUI.psd --out ../../PSDExport
```

产出：
```
PSDExport/
└── LoginUI/
    ├── LoginUI.json
    ├── _psd_cache.json      ← 增量缓存（不要提交到 git）
    └── images/
        ├── root_Img_Bg.png
        ├── root_Btn_Login_Img_Normal.png
        └── ...
```

### 3. 在 Unity 导入

#### 方式 A：一键（推荐）

- 菜单 `Tools > PSD Importer > Open Window`
- 顶部点 `📁 选中 PSD 并转换 + 导入`
- 选 `.psd` 文件 → 工具自动跑 Python → 完事直接出 Prefab

> Python 路径默认 `python`（环境变量里那个）。如果报错找不到，在 Settings 里
> 把 `Python executable` 改成完整路径，比如
> `C:\Users\WWCY\AppData\Local\Programs\Python\Python313\python.exe`。

#### 方式 B：手动两步

- 终端跑：`python psd_to_json.py MyUI.psd --out PSDExport`
- Unity 窗口里列表自动出现 `MyUI`（带状态徽章：●unchanged / ◐changed / ○new）
- 点 `Import` 按钮，或 `Import All (changed only)`

#### 生成位置（可在 Settings 改）

```
Assets/PSDImport/LoginUI/
├── LoginUI.prefab
└── images/
    ├── root_bg_main.png
    ├── root_btn_login_img_normal.png
    └── ...
```

UIBind 代码：
```
Assets/Scripts/Game/UI/LoginUI/
├── LoginUINodeProvider.cs    ← 自动生成（可重新生成）
└── LoginUIWindow.cs          ← 首次自动生成业务模板
Assets/Scripts/Game/UI/Editor/UIBindData/
└── LoginUI.asset             ← UIBindData SO
```

## 增量更新

重导时**只重建有变化的图层**：

1. 设计师改 PSD → 跑 `psd_to_json.py`（自动跳过未变的 PNG 写出）
2. Unity 里点 Import
3. Importer 对比 `sourcePsdHash`：
   - 相同 → 跳过（秒返回）
   - 不同 → 逐节点对比 hash：
     - 新增节点 → 创建
     - 删除节点 → 删子树
     - 内容变（PNG 像素 / 文本内容 / 颜色 / 字号）→ 重建该节点
     - 不变 → 保留

具体对比什么 hash：
- 整个 PSD 文件 sha256（顶层）
- 每个 image 节点的 PNG 像素 sha256
- 每个 text 节点的 (content + fontName + fontSize + color + alignment) 组合 sha256
- group 节点用 id + 子节点数（结构变才变）

## 设计师的字体问题

PS 里的文字图层在 PSD 里是栅格化的。psd-tools **能**尝试读矢量信息，但
很多字体拿不到。**推荐做法**：

1. PS 里把文字「栅格化」到像素（设计师在 PS 里 Cmd+Shift+Alt+E 即可）
2. 工具会把它当 image 处理，丢给 Image 组件，100% 还原
3. 如果一定要矢量化，命名 `Txt_*`，工具会读 `layer.text` 拿到 vector info，
   但 psd-tools 拿不到字体就 fall back 到 `fallbackFont`

字体名匹配规则：
- PSD 里写了 `SourceHanSansCN-Bold` → Importer 在 `fontSearchRoot` 下搜
  文件名包含 `SourceHanSansCN-Bold` 的 `.ttf`/`.otf`/Font asset
- 没找到 → 用 `fallbackFont`

## 限制

- **不支持 PS 图层样式**（阴影/描边/渐变）。建议在 PS 里把效果烘到像素
- **不支持智能对象**（psd-tools 解出来是个 group）
- **不支持 9-slice**（生成后手工在 prefab 里配置 `Image.type = Sliced`）
- **不支持动画**（psd-tools 拿不到时间轴信息）
- **按钮事件不自动接**（Window.cs 里手写）

## 故障排查

| 现象 | 原因 / 解决 |
|------|------------|
| 列表是空的 | `psdExportRoot` 路径错了？手动建了 `PSDExport/` 后再跑 Python |
| 一键按钮点了没反应 / 报 "psd_to_json.py not found" | 工具默认找 `<ProjectRoot>/Tools/PSDExporter/psd_to_json.py`；不在的话在 Settings 里设 `Python script` |
| 一键按钮点了报 "Failed to start Python" | `python` 不在 PATH。在 Settings 里把 `Python executable` 改成完整路径，如 `C:\Users\WWCY\AppData\Local\Programs\Python\Python313\python.exe` |
| Import 后字体变默认 | PS 字体名没拿到，或 `fontSearchRoot` 下没找到；检查 Settings |
| UIBind 字段全空 | 图层名没遵守 17 个前缀（见 PREFIXES.md）；Python 端会输出 warning |
| "Generated type not found" 警告 | 第一次 Import 触发了代码生成，Unity 正在编译；编译完后点 prefab 的 Inspector "Bind" 按钮，或在窗口里重 Import 一次（**当前 v1 默认不生成 UIBind**，需要时在窗口顶部勾选） |
| Prefab 位置错乱 | 设计师在 PS 里把图层放进不同 group 了，路径变了；检查层级 |
| 按钮点击没反应 | Importer 只挂 Button 组件，不接事件；编辑 `LoginUIWindow.cs` 加 `Nodes.BtnLogin.onClick.AddListener(...)` |

## 文件清单

| 文件 | 作用 |
|------|------|
| `Tools/PSDExporter/psd_to_json.py` | CLI 入口 |
| `Tools/PSDExporter/psd_exporter/exporter.py` | 核心导出逻辑 |
| `Tools/PSDExporter/psd_exporter/hashing.py` | hash 工具 |
| `Tools/PSDExporter/SCHEMA.md` | JSON 契约 |
| `Tools/PSDExporter/PREFIXES.md` | 17 前缀词表（与 PS 插件同步） |
| `Tools/PSDExporter/tests/test_exporter.py` | Python 端单测 |
| `Assets/Editor/PSDImporter/PSDNode.cs` | C# 数据模型 + 17 前缀镜像 |
| `Assets/Editor/PSDImporter/IncrementalTracker.cs` | hash 缓存 + diff |
| `Assets/Editor/PSDImporter/PSDImporter.cs` | 核心导入逻辑（带 generateUIBind 重载） |
| `Assets/Editor/PSDImporter/PSDImporterWindow.cs` | Editor 窗口（带一键按钮） |
| `Assets/Editor/PSDImporter/PSDImporterSettings.cs` | 配置 SO |
| `Assets/Editor/PSDImporter/PythonRunner.cs` | C# 起 Python 子进程工具 |
