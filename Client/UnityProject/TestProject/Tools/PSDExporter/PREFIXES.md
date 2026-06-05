# UGUI 图层前缀词表（唯一来源）

> **这条文档是 Photoshop 插件、Python 导出器、C# 导入器三者共用的契约。**
> 任何一边改前缀都必须同步另外两边，否则设计师的 PSD 在某一边识别不到就会出问题。

## 设计原则

1. **小写**：`img_`、`btn_` 全小写。因为 Photoshop 插件在 PS 里生成的就是小写，
   我们跟着走最省事。Python/C# 端会负责驼峰化。
2. **下划线结尾**：所有前缀都以 `_` 结尾，方便和图层名分隔（`btn_close_btn`）
   也能解析。
3. **出现顺序敏感**：匹配是**前缀**匹配，从最长前缀往下试（虽然 17 个前缀都
   是 4 字符以上，互相不会冲突，但加新前缀时要小心）。

## 词表

按字母序排列，便于搜索。

| 前缀 | 类型 | UGUI 组件 | Raycast | 字段名前缀 | 备注 |
|------|------|----------|---------|-----------|------|
| `anim_` | group | (无) | - | - | 动画根，普通组容器 |
| `bg_` | image | Image | no | `Bg` | 背景，通常撑满父节点 |
| `btn_` | button | Image + Button | yes | `Btn` | 按钮，业务代码自己接 onClick |
| `fx_` | image | Image | no | `Fx` | 特效/特效贴图 |
| `group_` | group | (无) | - | - | 显式标注的分组容器 |
| `icon_` | image | Image | no | `Icon` | 图标，常嵌在按钮里 |
| `img_` | image | Image | no | `Img` | 普通装饰图 |
| `input_` | input | Image + InputField | yes | `Input` | **v1 部分支持**：只建 Image，InputField 手挂 |
| `item_` | image | Image | no | `Item` | 列表项模板（通常运行时克隆） |
| `mask_` | image | Image + Mask | no | `Mask` | 遮罩 |
| `panel_` | image | Image | no | `Panel` | 面板背景 |
| `progress_` | progress | Image (Filled) | no | `Progress` | 进度条，imageType=Filled |
| `root_` | group | (无) | - | - | 根节点（不导出绑定） |
| `scroll_` | scroll | Image + ScrollRect | yes | `Scroll` | **v1 部分支持**：只建 Image，ScrollRect 手挂 |
| `slider_` | slider | Image + Slider | yes | `Slider` | **v1 部分支持**：只建 Image，Slider 手挂 |
| `toggle_` | toggle | Image + Toggle | yes | `Toggle` | **v1 部分支持**：只建 Image，Toggle 手挂 |
| `txt_` | text | Text | no | `Txt` | UGUI Text 重建文字 |

## 复合组件（`v1 部分支持`）的现状

`input_/toggle_/slider_/scroll_` 都需要：
- 一个 Image 当背景
- 子节点（Text 框 / Check / Handle / Viewport 等）

工具**只**会创建背景 Image 并按字段名挂上。设计师在 Unity Inspector 里手动加
对应的复合组件（InputField / Toggle / Slider / ScrollRect），把 Background
字段拖到工具生成的 Image 上，再把子节点挂到对应字段（Placeholder / Checkmark /
Handle / Viewport）。

工具会在 Console 输出一条 warning 提示这件事，UIBindData 也会打 tag。

## 维护规则

1. **加新前缀**：三边都要改
   - `psd_exporter/exporter.py` 的 `IMG_PREFIXES` / `BTN_PREFIXES` / 复合列表
   - `Assets/Editor/PSDImporter/PSDNode.cs` 的 `PsdNaming` 静态字段
   - `Ps_UGUI_Rename/com.ugui.rename/host/UGUI_Rename.jsx` 的 `UGUI_PREFIXES`
   - `Ps_UGUI_Rename/com.ugui.rename/client/index.html` 的按钮网格
2. **删除前缀**：先在 PSD 端全量替换成别的，再三边删。否则旧 PSD 进 Unity
   会落到 group。
3. **大小写**：**永远小写**。设计师被 PascalCase 整过，Camel/Pascal 都是转换
   层的责任。

## 字段命名转换规则

PSD 图层名 → C# 变量名的转换逻辑（在 Python 和 C# 两边都有，**逻辑必须一致**）：

```
prefix     + "_"     + baseName
"btn_"     + "_"     + "Close"  → "btn_Close" → field: BtnClose
"img_"     + "_"     + "bg"     → "img_bg"    → field: ImgBg
"toggle_"  + "_"     + "music"  → "toggle_music" → field: ToggleMusic
"scroll_"  + "_"     + "main"   → "scroll_main"  → field: ScrollMain
```

去下划线 + 每段首字母大写 + 去掉空段。同名处理：`Btn` / `Btn2` / `Btn3` 递增后缀。

## 三边的同步检查（CI/手动）

- Python 端：单测覆盖每个前缀的 classify 输出
- C# 端：PsdNaming.Classify 和 Python 端返回值完全一致
- PS 插件：UGUI_PREFIXES 数组长度 == 词表条数 == index.html 按钮数
