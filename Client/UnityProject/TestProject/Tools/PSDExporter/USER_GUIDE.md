# PSD2UGUI 使用说明

> 面向第一次用这个工具的**设计师 + 程序**。如果你只是想跑一次,直接看
> 「十分钟跑通」;如果你想搞清楚底层做了什么,看「完整流程」。

---

## 十分钟跑通

### 步骤 1:安装 Python 依赖(第一次)

```bash
pip install psd-tools pillow
```

确认装好了:

```bash
python -c "import psd_tools, PIL; print('ok')"
```

> Python 3.10+ 推荐。psd-tools 1.17+ 的 API 跟老版本不兼容,见
> `Tools/PSDExporter/psd_exporter/exporter.py` 顶部说明。

### 步骤 2:Unity 端创建 Settings(项目里第一次)

1. Unity 打开项目
2. 菜单:`Tools > PSD Importer > Open Window`(快捷键 Shift+U)
3. 第一次打开没有设置资产,点 **"创建默认设置资产"**,Unity 会自动
   生成 `Assets/PSDImporterSettings.asset`(或类似位置)

### 步骤 3:在 Photoshop 里命名图层

PS 插件(`Ps_UGUI_Rename`)已经把按钮排到了 `窗口 → 扩展 → UGUI 图层命名工具`,
选中图层点按钮就加前缀(项目里装在 `Common/OtherTools/Ps_UGUI_Rename/`)。

或者你手打:

```
LoginUI.psd
├── img_bg              ← 加前缀 img_,创建 UGUI Image
├── btn_login           ← 加前缀 btn_,创建 Image + Button
│   ├── img_normal      ← 按钮底图
│   └── txt_label       ← 按钮文字
├── txt_title           ← 加前缀 txt_,创建 UGUI Text
└── img_panel_9slice_10_10_10_10   ← 9 宫格,无 Sprite,border 由后缀决定
```

前缀规则完整版见 `PREFIXES.md`。

### 步骤 4:导出 PSD → JSON

**方法 A:在 Unity 里一键跑**(推荐)

- Unity 窗口顶部 **"待导入的 PSD 文件"** 列表
- 把 `.psd` 拖进列表(支持多个)
- 点 **"转换 + 导入 N 个 PSD"**,工具会跑 Python → 写 JSON → 调 Importer

**方法 B:命令行手动跑**

```bash
cd Tools/PSDExporter
python psd_to_json.py path/to/LoginUI.psd --out ../../PSDExport
```

跑完 Unity 窗口的列表会自动出现 `LoginUI`,点 **导入** 即可。

### 步骤 5:在 Hierarchy 里看结果

Unity 导入器会打开生成的 Prefab,你能在 Hierarchy 里看到一棵完整的
GameObject 树:

```
LoginUI (Canvas, CanvasScaler)
├── Img_Bg
├── Btn_Login
│   ├── Img_Normal
│   └── Txt_Label
├── Txt_Title
└── Img_Panel           ← 9-slice,Image.type=Sliced,无 Sprite
```

Inspector 里能看到 UIBind 字段(`Nodes.ImgBg` / `Nodes.BtnLogin` 等),
业务代码在 `LoginUIWindow.cs` 里直接拿。

---

## 完整流程

```
设计师改 PSD
   │
   ▼
跑 Python(CLI 或 Unity 一键)
   │   psd_to_json.py LoginUI.psd
   │     → 解析图层 / 拼 9-slice suffix / 分类前缀
   │     → 写 PNG 到 images/(9-slice 节点不导 PNG)
   │     → 写 JSON 树(含 slice 字段)
   ▼
PSDExport/LoginUI/LoginUI.json  ← 中间产物,UTF-8,反斜杠路径
PSDExport/LoginUI/images/*.png
   │
   ▼
Unity Importer 读 JSON
   │   解析 → 计算 hash → 跟 cache 对比
   │     顶层 hash 同 → 秒返回
   │     不同 → 逐节点 diff:
   │       新增/删除/变更 → 重建
   │       不变 → 保留
   ▼
创建 / 更新 Prefab
   │   按 PSD 树建 GameObject 层级
   │   image/button → Image 组件(+ Button / Sliced type)
   │   text → Text 组件(找 font、字号、颜色)
   │   group → 空 RectTransform
   ▼
生成 UIBind(若 Settings.autoGenerateUIBind=true)
   │   NodeProvider.cs / Window.cs / UIBindData.asset
   │   绑定 NodeProvider 字段到 Prefab 的对应 GameObject
   ▼
打开 Prefab Stage 让设计师检查
```

---

## 9-slice(九宫格)节点怎么用

九宫格用来做"可拉伸的背景" — 比如面板背景、按钮底图,四个角不变形,
中间拉伸。

### 命名

```
img_panel_9slice_10_10_10_10
│      │     │
│      │     └─ 边框像素 L T R B(左 上 右 下)
│      └─ 9-slice 后缀标记
└─ UGUI 前缀(可以是 img_ 或 btn_)
```

简写 `img_panel_9slice` 等同于 `img_panel_9slice_10_10_10_10`。

### 导出行为

| 行为 | 普通图 | 9-slice 图 |
|------|------|------|
| 导出 PNG 到 `images/` | ✓ | ✗(不导) |
| 写入 JSON 节点 | ✓ | ✓(`type=image`,带 `slice`) |
| Unity 创建 Image 组件 | ✓ | ✓(Sprite 留空,type=Sliced) |
| 写入 UIBind 字段 | ✓ | ✓ |

### Unity 端拿到 Prefab 后

1. 选中 `Img_Panel` 这个 GameObject
2. 在 Inspector 里**手动**挂 Sprite(从你们的美术资源管线拉过来)
3. 选中的 Sprite 必须是**已切好 9 宫格的**(Sprite Editor 里设了 border)
4. 如果美术资源管线和 PS 端切片不一致,以 PS 端后缀的 L/T/R/B 为准覆盖一次

### 进阶:让 9-slice 节点自动找到 Sprite

如果你有"共用图集"的需求,在 PSD 里再加一个 `export_<name>` 图层(只导出
PNG、不出 JSON 节点),跟 9-slice 节点同名:

```
Panel
├── img_panel_9slice_10_10_10_10   ← 9-slice 节点,Image 无 Sprite
└── export_panel                    ← 同名 export_,导出 PNG 到 images/panel.png
```

Importer 会用 logical name(`panel.png`)去同目录里找匹配的 Sprite,
自动挂上。日志里能看到 `9-slice 'img_panel_9slice_...' auto-matched sprite
'.../panel.png' by logical name 'panel'`。

> ⚠️ **当前版本这个自动匹配是最佳努力**。如果 export_ 节点的 PNG 跟
> 9-slice 节点的 logical name 对不上(Sprite 被你们美术管线另存了路径),
> 仍然要在 Inspector 手动挂。这个机制是给"美术资源管线还没建好"的
> 项目过渡用的。

---

## UIBind 自动生成(可选)

`Settings.autoGenerateUIBind` 控制:

- **关(默认)**:只生成 Prefab,UIBind 字段不会被自动绑定。
  适合"我就想要个 Prefab,业务代码自己写"的场景。
- **开**:跑 Importer 时会同时生成 `NodeProvider.cs` + `Window.cs` +
  `UIBindData.asset`,并在 Prefab 上绑好 `serializedField`。

Window.cs 第一次生成是模板,业务代码写在 `// === Your code here ===`
之间。下次重新 Import 时不会覆盖 Window.cs 里的业务代码(只重写 NodeProvider)。

---

## 常见问题(FAQ)

### Q:跑 Python 报 `psd_tools` 没装

```bash
pip install psd-tools pillow
```

如果还有问题,确认 Python 是 64 位、版本 ≥ 3.10。

### Q:Unity 窗口里列表是空的

- `psdExportRoot` 路径错了?(默认 `<ProjectRoot>/PSDExport`)
- 没跑过 Python?(手动跑一次 `psd_to_json.py`)
- 文件名带下划线开头会被忽略 — 不要把 JSON 命名成 `_xxx.json`

### Q:一键按钮点了报错

**"psd_to_json.py not found"**:脚本不在默认位置,在 Settings 里设
`python script path`。

**"Failed to start Python"**:`python` 不在 PATH。Windows 上推荐用完整路径:

```
C:\Users\WWCY\AppData\Local\Programs\Python\Python313\python.exe
```

填到 Settings 的 `Python executable`。

### Q:Import 完字体变默认(全是宋体或缺字)

设计师在 PS 用的字体没装,或者名字在 `fontSearchRoot` 下找不到。解决:

1. 把字体 TTF/OTF 放进 `Assets/Resources/Fonts/`(或 `fontSearchRoot`)
2. 在 Settings 里设 `Fallback font` 兜底

### Q:UIBind 字段全空 / 缺字段

图层名没遵守前缀。看 PREFIXES.md。Python 端输出 warning 时会列出哪些
图层被跳过了。

### Q:9-slice 节点有 Image 但没 Sprite

**这是预期**。要么:

- 在 Inspector 手动挂 Sprite(挑你们美术资源管线里已切好 border 的)
- 加 `export_<name>` 图层让 Importer 自动匹配(见上文)

### Q:Prefab 整体位置偏

可能是 PSD 画布尺寸跟 Game 里的 `CanvasScaler.referenceResolution` 不一致。
检查 Settings 里的 `prefabOutputRoot` 默认走的 reference 是 JSON 里的
`canvas.width/height`,这俩必须跟你们 Game 期望的分辨率匹配。

### Q:重新导入了,Unity 没反应 / 还显示旧的

- 检查 JSON 里的 `sourcePsd.hash` 是不是真的变了(没变 → Importer 秒返回)
- 检查 `Assets/PSDImport/<name>/_cache.json` 的 `sourcePsdHash`
  — 手动改过 PSD 但 hash 没变通常是因为 PSD 缓存里有别的图层改了

### Q:批量导入时,某个 PSD 命名(类名)我想单独起

每行右侧 **Prefab 名称覆盖** 字段填自定义名。空 = 用 PSD 文件名;
非空 = 该 PSD 的 prefab 名 / 子目录 / 根 GameObject / NodeProvider 类名 /
UIBindData 资产名全都用这个名字。

⚠️ **改了之后不会自动迁移老 Prefab** — 老 prefab 留在原路径,新 prefab
写到新路径。手动删老 prefab 或重新 import。

### Q:列表里某个 PSD 显示 ●(unchanged) 但我改了 PSD

可能 Python 跑过一次了 hash 已经缓存。**重新跑 Python**:

```bash
python psd_to_json.py path/to/MyUI.psd --out ../../PSDExport
```

然后 Unity 里点 `刷新` 按钮。

### Q:怎么跑单测

```bash
cd Tools/PSDExporter
python -m tests.test_exporter
```

应该看到 `All tests passed.` 输出。

---

## 进阶:约束 & 设计

### 命名规范的"单一来源"

任何前缀 / 后缀改动必须三边同步:

1. Python 端:`Tools/PSDExporter/PREFIXES.md`(文档) +
   `psd_exporter/exporter.py` 的 `*_PREFIXES` 常量
2. C# 端:`Assets/Editor/PSDImporter/PSDNode.cs` 的 `PsdNaming` 静态字段
3. PS 插件:`Common/OtherTools/Ps_UGUI_Rename/com.ugui.rename/host/UGUI_Rename.jsx`
   的 `UGUI_PREFIXES`

不一致会出现"PS 端改了前缀,Python 端识别不到,Unity 端 UIBind 字段空"
这种灾难。

### 不进 git 的中间产物

`PSDExport/`(默认在工程根)放的是 Python 写出的 JSON + PNG。建议加进
`.gitignore`:

```gitignore
PSDExport/
Assets/PSDImages/
Assets/PSDImport/
*.psd
```

如果你们用其他工作流(YooAsset CDN 模式等),把 `Assets/PSDImages/`
改成由你们自己管线管理的路径,Importer 只负责生成 PNG + 注册 Sprite 引用。

### 文件夹位置一览

```
<ProjectRoot>/
├── Tools/PSDExporter/                 ← Python 端
│   ├── psd_to_json.py                 ← CLI 入口
│   ├── psd_exporter/
│   │   ├── exporter.py                ← 核心逻辑
│   │   └── hashing.py
│   ├── tests/test_exporter.py
│   ├── README.md                      ← 工具介绍
│   ├── SCHEMA.md                      ← JSON 契约
│   ├── PREFIXES.md                    ← 前缀词表
│   └── USER_GUIDE.md                  ← 本文档
│
├── PSDExport/                          ← Python 输出(不进 git)
│   └── <PsdName>/
│       ├── <PsdName>.json
│       └── images/*.png
│
├── Assets/
│   ├── PSDImport/                      ← Unity 生成 Prefab
│   │   └── <PsdName>/<PsdName>.prefab
│   ├── PSDImages/                      ← Unity 拷贝 PNG
│   │   └── <PsdName>/*.png
│   ├── Editor/PSDImporter/             ← Unity 端代码
│   │   ├── PSDNode.cs
│   │   ├── PSDImporter.cs
│   │   ├── PSDImporterWindow.cs
│   │   ├── PSDImporterSettings.cs
│   │   ├── IncrementalTracker.cs
│   │   └── ...
│   └── Scripts/Game/UI/                ← UIBind 生成代码
│       └── <PsdName>/
│           ├── <PsdName>NodeProvider.cs
│           └── <PsdName>Window.cs
└── PSDImporterSettings.asset           ← Settings(ScriptableObject)
```

---

## 联系 / 反馈

代码里有疑问 → 提 issue 或找 **@Tools 组**。

设计师有流程问题 → 找 **@UI 组** / 看 `Ps_UGUI_Rename` 的 README。