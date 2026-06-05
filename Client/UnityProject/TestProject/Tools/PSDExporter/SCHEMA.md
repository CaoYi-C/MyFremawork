# JSON Schema (v1) - PSD2UGUI

> Python 端 `psd_to_json.py` 与 Unity 端 `PSDImporter` 之间的契约。
> 任何一方修改字段都必须同步更新对方。

## 顶层结构

```json
{
  "schemaVersion": 1,
  "sourcePsd": { "name": "LoginUI.psd", "hash": "sha256:<hex>" },
  "exportedAt": "2026-06-05T10:00:00+08:00",
  "canvas": { "width": 1920, "height": 1080 },
  "root": { /* 见 Node */ }
}
```

| 字段 | 类型 | 说明 |
|------|------|------|
| `schemaVersion` | int | 协议版本。Unity 端检测到不匹配会拒绝导入。 |
| `sourcePsd.name` | string | 原始 PSD 文件名（不带路径） |
| `sourcePsd.hash` | string | 整个 PSD 文件的 sha256。前缀 `sha256:`，用于顶层缓存命中。 |
| `exportedAt` | string | ISO 8601 时间戳 |
| `canvas.width` / `height` | int | PSD 画布尺寸（像素）。UGUI Canvas Scaler 用此值作为参考分辨率。 |

## Node 节点

每个节点都是 `object`，字段根据 `type` 不同而不同。

### 通用字段（所有节点都有）

| 字段 | 类型 | 说明 |
|------|------|------|
| `id` | string | 稳定 ID，路径派生（`root/Btn_Login/Txt_Label`）。用于增量追踪。 |
| `name` | string | PSD 中的图层名（保留原始命名） |
| `type` | enum | `group` \| `image` \| `text` |
| `visible` | bool | PSD 中的可见性。不可见图层会被跳过（不会出现在 JSON 里）。 |
| `opacity` | float | 0.0 ~ 1.0 |
| `rect` | object | `{ x, y, w, h }`，**PSD 坐标系**：左上原点，Y 向下。Unity 端负责翻转 Y。 |
| `pivot` | object | `{ x, y }`，PSD 内的 pivot 归一化坐标 (0~1)，Unity 端直传。 |
| `children` | array\<Node\> | 仅 `type=group` 才有。 |

### image 节点（`type: "image"`）

| 字段 | 类型 | 说明 |
|------|------|------|
| `imageHash` | string | 像素数据 sha256（用于增量判断：变了才重导出 PNG） |
| `imageFile` | string | 相对 `outputRoot` 的 PNG 路径，如 `images/Img_Bg.png` |
| `imageTransparent` | bool | 是否含 alpha 通道，影响 Unity 端 Sprite 创建参数 |

### text 节点（`type: "text"`）

| 字段 | 类型 | 说明 |
|------|------|------|
| `textHash` | string | 文本 + 字体 + 字号 + 颜色 的组合 hash |
| `text.content` | string | 实际文字内容 |
| `text.fontName` | string | PSD 中的字体名（如 `SourceHanSansCN-Bold`），可能拿不到，缺失时为空 |
| `text.fontSize` | float | 字号（pt） |
| `text.color` | string | `#RRGGBBAA` 8 位十六进制 |
| `text.alignment` | enum | UGUI `TextAnchor` 枚举字符串：`UpperLeft` \| `UpperCenter` \| ... \| `LowerRight` |
| `text.bold` | bool | 加粗（psd-tools 拿不到，恒为 false，留作扩展） |
| `text.italic` | bool | 斜体（同上） |

### group 节点（`type: "group"`）

| 字段 | 类型 | 说明 |
|------|------|------|
| `children` | array\<Node\> | 嵌套子节点 |

### 图像类节点（`type` ∈ `image` / `button` / `input` / `scroll` / `slider` / `toggle` / `bg` / `icon` / `mask` / `panel` / `progress` / `item` / `fx` / `raw`）

| 字段 | 类型 | 说明 |
|------|------|------|
| `imageHash` | string | 像素数据 sha256（增量判断用） |
| `imageFile` | string | 相对 `outputRoot` 的 PNG 路径 |
| `imageTransparent` | bool | 是否含 alpha 通道 |
| `isComposite` | bool | v1 复合组件（`input`/`scroll`/`slider`/`toggle`）为 true。导入器只创建 Image，业务组件需手动挂 |

## 前缀词表（与 PS 插件/Python/C# 三边同步）

| 前缀 | `type` | UGUI 组件 | 字段名 |
|------|--------|----------|--------|
| `txt_` | `text` | Text | `TxtXxx` |
| `btn_` | `button` | Image + Button | `BtnXxx` |
| `img_` | `image` | Image | `ImgXxx` |
| `icon_` | `image` | Image | `IconXxx` |
| `bg_` | `image` | Image (背景) | `BgXxx` |
| `panel_` | `image` | Image (面板) | `PanelXxx` |
| `progress_` | `image` | Image (Filled) | `ProgressXxx` |
| `mask_` | `image` | Image + Mask | `MaskXxx` |
| `item_` | `image` | Image (列表项模板) | `ItemXxx` |
| `fx_` | `image` | Image (特效) | `FxXxx` |
| `scroll_` | `scroll` | Image + ScrollRect (v1 部分支持) | `ScrollXxx` |
| `input_` | `input` | Image + InputField (v1 部分支持) | `InputXxx` |
| `slider_` | `slider` | Image + Slider (v1 部分支持) | `SliderXxx` |
| `toggle_` | `toggle` | Image + Toggle (v1 部分支持) | `ToggleXxx` |
| `group_` | `group` | (无) | - |
| `anim_` | `group` | (无) | - |
| `root_` | `group` | (无) | - |

**v1 部分支持** 的类型（`input` / `scroll` / `slider` / `toggle`）：Python 端会把
节点标 `isComposite: true`，C# 端创建 Image 组件并输出 warning，业务组件
（InputField / ScrollRect / Slider / Toggle）需在 Unity Inspector 手动挂上。

## 增量更新协议

Unity 端在 `Assets/PSDImport/<PsdName>/_cache.json` 维护上一轮的状态：

```json
{
  "sourcePsdHash": "sha256:...",
  "nodeHashes": {
    "root/Img_Bg": "sha256:...",
    "root/Btn_Login/Txt_Label": "sha256:...",
    ...
  },
  "nodeTypes": {
    "root/Img_Bg": "image",
    "root/Btn_Login/Txt_Label": "text"
  }
}
```

**判定流程**：

1. `sourcePsdHash` 相同 → 秒返回，提示"无变化"
2. 比对 `nodeHashes`，找出新增/删除/变更
3. 节点类型变了（image→text）→ 当作删除+新增处理
4. 删除节点 → 删除对应 UGUI 子树
5. 新增/变更节点 → 重建该节点

## 设计师命名约定

> **详细词表见 `PREFIXES.md`**（唯一来源，与 PS 插件、Python、C# 三边同步）。
> 这里只列常用前缀的速查：

| 图层名前缀 | UGUI 组件 | UIBind 字段名 |
|------|------|------|
| `btn_*` | Image + Button | `Btn<Name>` |
| `txt_*` | Text | `Txt<Name>` |
| `img_*` | Image | `Img<Name>` |
| `icon_*` | Image | `Icon<Name>` |
| `bg_*` | Image | `Bg<Name>` |
| `panel_*` | Image | `Panel<Name>` |
| `progress_*` | Image (Filled) | `Progress<Name>` |
| `scroll_*` | Image (v1 部分支持) | `Scroll<Name>` |
| `input_*` | Image (v1 部分支持) | `Input<Name>` |
| `toggle_*` | Image (v1 部分支持) | `Toggle<Name>` |
| `slider_*` | Image (v1 部分支持) | `Slider<Name>` |
| `group_*` / `anim_*` / `root_*` | (无) | - |

> 所有前缀**小写**。PS 插件 (`com.ugui.rename`) 自动给图层加这些前缀。

示例 PSD 图层名：
- `btn_login` → 字段 `BtnLogin`（同时创建 Image + Button）
- `txt_title` → 字段 `TxtTitle`
- `toggle_music` → 字段 `ToggleMusic`（仅 Image，业务 Toggle 手挂）
- `group_login` → 容器，不生成绑定

未带前缀的图层（设计师没遵守）也会被处理，只是不生成 UIBind 字段。工具会输出警告。
