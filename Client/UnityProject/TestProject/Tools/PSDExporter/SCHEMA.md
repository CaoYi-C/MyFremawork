# JSON Schema (v1) - PSD2UGUI

> Python 端 `psd_to_json.py` 与 Unity 端 `PSDImporter` 之间的契约。
> 任何一方修改字段都必须**同步更新**本文件 + 对方代码,否则导入会坏。

---

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
| `sourcePsd.name` | string | 原始 PSD 文件名(不带路径) |
| `sourcePsd.hash` | string | 整个 PSD 文件的 sha256,前缀 `sha256:`。Unity 端用它做顶层缓存命中。 |
| `exportedAt` | string | ISO 8601 时间戳 |
| `canvas.width` / `height` | int | PSD 画布尺寸(像素)。UGUI Canvas Scaler 用此值作为参考分辨率。 |

---

## Node 节点

每个节点都是 `object`,字段根据 `type` 不同而不同。

### 通用字段(所有节点都有)

| 字段 | 类型 | 说明 |
|------|------|------|
| `id` | string | 稳定 ID,路径派生(`root/Btn_Login/Txt_Label`)。用于增量追踪。 |
| `name` | string | PSD 中的图层名(**保留原始命名**,包括 UGUI 前缀和 9-slice 后缀) |
| `type` | enum | `group` \| `image` \| `text` \| `button` |
| `visible` | bool | PSD 中的可见性。不可见图层会被跳过(不会出现在 JSON 里)。 |
| `opacity` | float | 0.0 ~ 1.0 |
| `rect` | object | `{ x, y, w, h }`,**PSD 坐标系**:左上原点,Y 向下。Unity 端负责翻转 Y。 |
| `pivot` | object | `{ x, y }`,PSD 内的 pivot 归一化坐标 (0~1)。Unity 端直传。 |
| `children` | array\<Node\> | 仅 `type=group` 才有。 |

---

### `image` 节点(`type: "image"`)

最常用的节点 — 一个有 Sprite 的 UGUI Image。带 9-slice 后缀的图层也归
这一类(用 `slice` 字段标记),所以**不是**"9-slice 才有 slice 字段",
**所有 image 节点都可能带 `slice`,没带就不是 9-slice**。

| 字段 | 类型 | 说明 |
|------|------|------|
| `imageHash` | string | 像素数据 sha256。9-slice 节点用 `slice{L,T,R,B}` + rect 合成(因为没导 PNG) |
| `imageFile` | string | 相对 `<outputRoot>/images/` 的 PNG 路径(用 `\` 分隔,跨平台兼容)。**9-slice 节点此字段为空字符串** |
| `imageTransparent` | bool | 是否含 alpha 通道,影响 Unity 端 Sprite 创建参数 |
| `slice` | object \| 缺席 | 9-slice 边框 `{ l, t, r, b }`(像素)。**没带 9-slice 后缀的图层此字段不存在**(注意:Unity JsonUtility 反序列化时缺失字段会变成空实例,见下方"陷阱") |

---

### `text` 节点(`type: "text"`)

| 字段 | 类型 | 说明 |
|------|------|------|
| `textHash` | string | (content + fontName + fontSize + color + alignment + rasterHash) 组合 sha256 |
| `text.content` | string | 实际文字内容 |
| `text.fontName` | string | PSD 中的字体名(如 `SourceHanSansCN-Bold`),可能拿不到,缺失时为空 |
| `text.fontSize` | float | 字号(像素)。注意 PSD 字号是 pt,exporter 会乘 `layer.transform[3]` 转成像素 |
| `text.color` | string | `#RRGGBBAA` 8 位十六进制 |
| `text.alignment` | enum | UGUI `TextAnchor` 枚举字符串:`UpperLeft` \| `UpperCenter` \| ... \| `LowerRight` |
| `text.bold` | bool | 加粗(psd-tools 拿不到,恒为 false,留作扩展) |
| `text.italic` | bool | 斜体(同上) |
| `text._rasterHash` | string | 文字栅格化的 PNG sha256,作为字体解析失败时的兜底 hash |

---

### `button` 节点(`type: "button"`)

Unity 端创建 Image + Button(target = Image)。其它字段跟 `image` 完全一致
(`imageHash` / `imageFile` / `imageTransparent` / 可选 `slice`)。

---

### `group` 节点(`type: "group"`)

| 字段 | 类型 | 说明 |
|------|------|------|
| `children` | array\<Node\> | 嵌套子节点 |

---

## 前缀词表(与 PS 插件/Python/C# 三边同步)

| 前缀 | `type` | UGUI 组件 | 字段名 | 备注 |
|------|--------|----------|--------|------|
| `btn_` | `button` | Image + Button | `BtnXxx` | |
| `img_` | `image` | Image | `ImgXxx` | |
| `txt_` | `text` | Text | `TxtXxx` | |
| `export_` | (无) | (无) | - | **仅导出 PNG,不产生 JSON 节点** |

> 不带前缀的图层被分类为 `group`,**会被处理但不出 UIBind 字段**(Python 端会 warning)。

---

## 增量更新协议

Unity 端在 `Assets/PSDImport/<PsdName>/_cache.json` 维护上一轮的状态
(Python 端在导出目录写 `_psd_cache.json`,由 Unity 读完后写入自己的
`_cache.json`)。

```json
{
  "sourcePsdHash": "sha256:...",
  "nodeHashes": {
    "root/Img_Bg": "sha256:...",
    "root/Btn_Login/Txt_Label": "sha256:...",
    "root/Panel/img_bagBg_9slice_10_10_10_10": "sha256:...",
    ...
  },
  "nodeTypes": {
    "root/Img_Bg": "image",
    "root/Btn_Login/Txt_Label": "text"
  },
  "lastImportedPrefabPath": "Assets/PSDImport/LoginUI/LoginUI.prefab",
  "lastImportedAt": "2026-06-10T09:07:08+08:00"
}
```

**判定流程**:

1. `sourcePsdHash` 相同 → 秒返回,提示"无变化"
2. 比对 `nodeHashes`,找出新增 / 删除 / 变更
3. 节点类型变了(`image → text`) → 当作删除+新增处理
4. 删除节点 → 删除对应 UGUI 子树
5. 新增 / 变更节点 → 重建该节点

---

## 已知陷阱(给改 Python/C# 的人)

### 9-slice 节点是 image 类型,不是新类型

带 `_9slice_L_T_R_B` 后缀的图层**仍然是 `type: "image"`**,只是多了
`slice` 字段。Unity 端判定 9-slice 用 `slice != null && (l|t|r|b) != 0`
(`!= null` 不够 — JsonUtility 给缺失字段创建默认实例,详见下文)。

### C# JsonUtility 给 `[Serializable]` 字段填默认实例

Unity 的 `JsonUtility.FromJson` 在 JSON 里**缺失** `[Serializable]` 字段时
会构造一个默认实例,而不是 `null`。所以:

```csharp
// WRONG — 所有 image 节点都会被当成 9-slice
if (node.slice != null) { ... }

// RIGHT — 同时检查四个边框值
if (node.slice != null
    && (node.slice.l | node.slice.t | node.slice.r | node.slice.b) != 0)
{ ... }
```

Python 端不要"为了 C# 方便"额外往 JSON 里写 `slice: {l:0,t:0,r:0,b:0}`
来表示"非 9-slice" — 让字段缺席,别污染契约。

### 9-slice hash 用 slice 值 + rect 合成,不用 PNG 像素

带 9-slice 后缀的图层**不导 PNG**(因为 9-slice 节点 Unity 端不会创建
Sprite 引用,留着 PNG 是浪费)。所以 `imageHash` 不能用 PNG sha256,改成
`s:{L}_{T}_{R}_{B} | r:{x}_{y}_{w}_{h}` 的组合 hash。改 rect / 改边框都
会触发重建,跟 PNG 节点语义一致。

### PNG 路径用反斜杠

`imageFile` 写 `"images\\bg_bg.png"`(Windows 反斜杠)。这是 Unity 端早期
为兼容 PowerShell 路径解析做的妥协,C# 端用 `Replace('\\', '/')` 统一
处理。改这个之前先确认 `PSDImporter.SetImagePathResolver` 和 `LoadSprite`
的逻辑不会爆。

---

## 设计师命名约定

> **详细词表见 `PREFIXES.md`**(唯一来源,与 PS 插件、Python、C# 三边同步)。
> 这里只列常用前缀的速查:

| 图层名前缀 | UGUI 组件 | UIBind 字段名 |
|------|------|------|
| `btn_*` | Image + Button | `Btn<Name>` |
| `img_*` | Image | `Img<Name>` |
| `txt_*` | Text | `Txt<Name>` |

> 所有前缀**小写**。PS 插件 (`com.ugui.rename`) 自动给图层加这些前缀。

示例 PSD 图层名:

- `btn_close` → 字段 `BtnClose`(同时创建 Image + Button)
- `txt_title` → 字段 `TxtTitle`
- `img_bg` → 字段 `ImgBg`
- `img_panel_9slice_10_10_10_10` → 字段 `ImgPanel`,创建无 Sprite 的
  Image(`Image.type = Sliced`,border 由 `slice` 提供),GameObject 命名
  `img_panel`(剥掉 `_9slice_...` 后缀)
- `export_icon` → **不创建节点**,只把 `icon.png` 写到 `images/`,
  供其他 UI 引用

未带前缀的图层(设计师没遵守)也会被处理,只是不生成 UIBind 字段。
工具会输出 warning。