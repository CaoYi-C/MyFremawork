# PSD2UGUI

PSD → Unity UGUI 导入工具。设计师在 Photoshop 里画好 UI,跑个 Python
脚本,Unity 一键生成 Prefab + UIBind 代码。

> **本目录的代码分两块**:
> - `psd_exporter/` — Python 端,跑在命令行 / CI,生成 `*.json + images/*.png`
> - `tests/` — Python 端单测 (`python -m tests.test_exporter`)
>
> **Unity 端代码不在本目录**,它在 `Assets/Editor/PSDImporter/` 下。两侧靠
> `SCHEMA.md` 协调 — 任何字段改动必须三边同步(Python、Unity、文档)。

---

## 流水线一览

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

- **Python 端**:`Tools/PSDExporter/`,独立于 Unity,跑在命令行 / CI
- **Unity 端**:`Assets/Editor/PSDImporter/`,Editor 时工具,菜单入口
- **中间产物**:JSON + PNG,默认写到工程根的 `PSDExport/`(可在 Settings 改),
  **不进 git**(加进 `.gitignore`)

---

## 一次性配置

### 1. 安装 Python 依赖

```bash
pip install psd-tools pillow
```

> 推荐 Python 3.10+(psd-tools 1.17 的 API 跟老版本不兼容,见 `exporter.py`
> 顶部的注释)。

### 2. 创建 Settings 资源

- Unity 菜单:`Tools > PSD Importer > Open Window`(快捷键 Shift+U)
- 第一次打开没设置资产,点 **"创建默认设置资产"**
- 关键路径(在 Settings 的 Inspector 里):
  - `PSD export root` — Python 写出的中间产物落点,默认 `PSDExport`(工程根)
  - `Prefab 输出 (Assets/)` — 生成的 UGUI Prefab 落点,默认 `Assets/PSDImport`
  - `图片输出根 (Assets/)` — 拷贝进 Assets/ 的 PNG 落点,默认 `Assets/PSDImages`
  - `Python executable` — 留 `python` 表示走 PATH;Windows 上如果失败改成完整路径
  - `Fallback font` — 设计师在 PS 里指定了不存在的字体时回退到这个

---

## 设计师工作流

### 1. 图层命名规范(决定 UGUI 组件 + UIBind 字段名)

> **完整词表见 `PREFIXES.md`** — 唯一来源,PS 插件 / Python / C# 三边同步。

| 前缀 | UGUI 组件 | UIBind 字段名 | 备注 |
|------|----------|--------|------|
| `btn_*` | Image + Button | `Btn<Name>` | 接 onClick 在 Window.cs 写 |
| `img_*` | Image | `Img<Name>` | |
| `txt_*` | Text | `Txt<Name>` | |
| `export_*` | (无) | - | **仅导出 PNG,不产生 JSON 节点** |

**9-slice 后缀**:图层名后加 `_9slice_L_T_R_B`(L T R B 是边框像素)。

举例:

- `img_panel_9slice_10_10_10_10` — 创建一个 Image 组件(无 Sprite,
  Inspector 里 type=Sliced、border 由 exporter 自动设置),写入 JSON 树
- `btn_use_9slice` — 同上,边框取默认 10/10/10/10
- `btn_close` — 普通按钮,Image + Button + Sprite

不带前缀的图层会被处理但**不生成 UIBind 字段**(工具会输出 warning)。

### 2. 导出

```bash
cd Tools/PSDExporter
python psd_to_json.py path/to/LoginUI.psd --out ../../PSDExport
```

> 加 `--all-layers` 导出全图层树(默认只导出带前缀的 + 它们的祖先 group)。

产出:

```
PSDExport/
└── LoginUI/
    ├── LoginUI.json           ← 树结构(Unity 端读这个)
    ├── _psd_cache.json        ← 增量缓存(Unity 端写入;不要提交)
    └── images/
        ├── bg.png
        ├── login.png          ← 注意:UGUI 前缀 + 9-slice 后缀都剥掉了
        └── ...
```

### 3. 在 Unity 导入

#### 方式 A:一键(推荐)

- 菜单 `Tools > PSD Importer > Open Window`(Shift+U)
- 顶部 **"待导入的 PSD 文件"** 列表,把 `.psd` 拖进去(支持批量)
- 每行可以填 **Prefab 名称覆盖** — 留空 = 用 PSD 文件名;非空 = 该 PSD
  的 prefab 名/子目录/根 GameObject/NodeProvider 类名/UIBindData 资产名全
  都用这个名字(批量导入时不同 PSD 可以各自起名互不干扰)
- 点 **"转换 + 导入 N 个 PSD"** — 工具自动跑 Python → 出 Prefab

#### 方式 B:手动两步

- 终端跑 Python(同上)
- Unity 窗口里列表自动出现 PSD 列表(带状态徽章:●unchanged / ◐changed / ○new)
- 点 `导入` 按钮单条导入,或 `全部导入(仅变更)`

#### 生成位置(可在 Settings 改)

```
Assets/PSDImport/LoginUI/
├── LoginUI.prefab
└── (NodeProvider.cs / Window.cs / UIBindData.asset 由生成器写出)

Assets/PSDImages/LoginUI/
├── bg.png
├── login.png
└── ...
```

---

## 增量更新

重导时**只重建有变化的图层** — PSD 没动就秒返回。

1. 设计师改 PSD → 跑 `psd_to_json.py`(自动跳过未变的 PNG 写出)
2. Unity 里点 Import
3. Importer 对比 `sourcePsdHash`:
   - 相同 → 跳过
   - 不同 → 逐节点对比 hash:
     - **新增节点** → 创建
     - **删除节点** → 删子树
     - **内容变**(PNG 像素 / 文本 / 颜色 / 字号 / 9-slice 边框)→ 重建该节点
     - **不变** → 保留

具体对比什么 hash:

- 整个 PSD 文件 sha256(顶层)
- 每个 image 节点的 PNG 像素 sha256(9-slice 节点用 `slice{L,T,R,B}` + rect 合成)
- 每个 text 节点的 (content + fontName + fontSize + color + alignment + 栅格化像素)组合 sha256
- group 节点用 id + 子节点数(结构变才变)

---

## 9-slice marker 入 Json 树

带 `_9slice_L_T_R_B` 后缀的图层(`btn_xxx_9slice_10_10_10_10` / `img_xxx_9slice`
)的行为:

- **不导出 PNG**
- **会**在 JSON 树里写入一个 `image` 类型节点,带 `slice: { l, t, r, b }` 字段,
  `imageFile` 为空字符串
- Unity 端 `PSDImporter`:
  1. 创建 GameObject + Image 组件
  2. 把 `Image.type` 设成 `Sliced`
  3. `Sprite` 字段**留空** — 在 Inspector 里手动挂(后续可接美术资源管线)
  4. **GameObject 名**剥掉 `_9slice_...` 后缀,方便看 Hierarchy(`img_panel`
     而不是 `img_panel_9slice_10_10_10_10`)

> 设计师如果想为 9-slice 节点指定 Sprite 来源,可以在 PSD 里再放一个
> `export_<name>` 图层(只导出 PNG,不出节点),跟 9-slice 节点同名即可。
> 详见 `SCHEMA.md` 里关于 `export_*` 前缀的段落。

---

## 设计师的字体问题

PS 里的文字图层在 PSD 里是栅格化的。psd-tools **能**尝试读矢量信息,但
很多字体拿不到。**推荐做法**:

1. PS 里把文字「栅格化」到像素(设计师在 PS 里 Cmd+Shift+Alt+E 即可)
2. 工具会把它当 image 处理,丢给 Image 组件,100% 还原
3. 如果一定要矢量化,命名 `txt_*`,工具会读 `layer.text` 拿到 vector info,
   但 psd-tools 拿不到字体就 fall back 到 `fallbackFont`

字体名匹配规则:

- PSD 里写了 `SourceHanSansCN-Bold` → Importer 在 `fontSearchRoot` 下搜
  文件名包含 `SourceHanSansCN-Bold` 的 `.ttf`/`.otf`/Font asset
- 没找到 → 用 `fallbackFont`

`txt_title_H1` 这种带 font tag 后缀的图层,会先在 `Settings.fontTagMappings`
里查 `H1`,命中就用对应的 Font asset;不命中再走上面的 fallback。

---

## 限制

- **不支持 PS 图层样式**(阴影/描边/渐变)。建议在 PS 里把效果烘到像素
- **不支持智能对象**(psd-tools 解出来是个 group)
- **不支持动画**(psd-tools 拿不到时间轴信息)
- **按钮事件不自动接**(Window.cs 里手写)
- **9-slice 节点 Sprite 留空**(Inspector 里手动挂,后续接美术管线自动挂)

---

## 故障排查

| 现象 | 原因 / 解决 |
|------|------------|
| 列表是空的 | `psdExportRoot` 路径错了?手动建了 `PSDExport/` 后再跑 Python |
| 一键按钮点了没反应 / 报 "psd_to_json.py not found" | 工具默认找 `<ProjectRoot>/Tools/PSDExporter/psd_to_json.py`;不在的话在 Settings 里设 `Python script path` |
| 一键按钮点了报 "Failed to start Python" | `python` 不在 PATH。在 Settings 里把 `Python executable` 改成完整路径,如 `C:\Users\WWCY\AppData\Local\Programs\Python\Python313\python.exe` |
| Import 后字体变默认 | PS 字体名没拿到,或 `fontSearchRoot` 下没找到;检查 Settings |
| UIBind 字段全空 | 图层名没遵守前缀(见 PREFIXES.md);Python 端会输出 warning |
| "Generated type not found" 警告 | 第一次 Import 触发了代码生成,Unity 正在编译;编译完后点 prefab 的 Inspector "Bind" 按钮,或在窗口里重 Import 一次(**当前默认不生成 UIBind**,需要时在 Settings 勾选 `autoGenerateUIBind`) |
| Prefab 位置错乱 | 设计师在 PS 里把图层放进不同 group 了,路径变了;检查层级 |
| 按钮点击没反应 | Importer 只挂 Button 组件,不接事件;编辑 `LoginUIWindow.cs` 加 `Nodes.BtnLogin.onClick.AddListener(...)` |
| 9-slice 节点创建出来没 Sprite | 这是预期行为 — 在 Inspector 里挂 Sprite 并调 border;或加 `export_<name>` 图层提供 PNG |

---

## 文件清单

| 文件 | 作用 |
|------|------|
| `Tools/PSDExporter/psd_to_json.py` | CLI 入口 |
| `Tools/PSDExporter/psd_exporter/exporter.py` | 核心导出逻辑 |
| `Tools/PSDExporter/psd_exporter/hashing.py` | hash 工具 |
| `Tools/PSDExporter/SCHEMA.md` | JSON 契约(Python ↔ Unity) |
| `Tools/PSDExporter/PREFIXES.md` | 前缀词表(与 PS 插件同步) |
| `Tools/PSDExporter/USER_GUIDE.md` | **使用说明**(给设计师 / 新人) |
| `Tools/PSDExporter/tests/test_exporter.py` | Python 端单测 |
| `Assets/Editor/PSDImporter/PSDNode.cs` | C# 数据模型 + 前缀镜像 |
| `Assets/Editor/PSDImporter/IncrementalTracker.cs` | hash 缓存 + diff |
| `Assets/Editor/PSDImporter/PSDImporter.cs` | 核心导入逻辑 |
| `Assets/Editor/PSDImporter/PSDImporterWindow.cs` | Editor 窗口(带一键按钮) |
| `Assets/Editor/PSDImporter/PSDImporterSettings.cs` | 配置 SO |
| `Assets/Editor/PSDImporter/PythonRunner.cs` | C# 起 Python 子进程工具 |