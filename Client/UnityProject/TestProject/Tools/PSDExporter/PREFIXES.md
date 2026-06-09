# UGUI 图层前缀词表（唯一来源）

> **这条文档是 Photoshop 插件、Python 导出器、C# 导入器三者共用的契约。**
> 任何一边改前缀都必须同步另外两边，否则设计师的 PSD 在某一边识别不到就会出问题。

## 设计原则

1. **小写**：`img_`、`btn_` 全小写。因为 Photoshop 插件在 PS 里生成的就是小写，
   我们跟着走最省事。Python/C# 端会负责驼峰化。
2. **下划线结尾**：所有前缀都以 `_` 结尾，方便和图层名分隔（`btn_close_btn`）
   也能解析。
3. **出现顺序敏感**：匹配是**前缀**匹配（4 个前缀都是 4 字符以上，互相不会冲突）。

## 词表

| 前缀 | 类型 | UGUI 组件 | Raycast | 字段名前缀 | 备注 |
|------|------|----------|---------|-----------|------|
| `btn_` | button | Image + Button | yes | `Btn` | 按钮，业务代码自己接 onClick |
| `export_` | export | (无) | - | - | **仅导出PNG，不产生JSON节点** |
| `img_` | image | Image | no | `Img` | 普通装饰图 |
| `txt_` | text | Text | no | `Txt` | UGUI Text 重建文字 |

## export_ 前缀说明

`export_` 前缀只做一件事：把图层渲染成 PNG 写到 images 目录。它**不会**在
JSON 树中产生任何节点，Unity 端也不会为它创建 GameObject。主要用于：
- 其他 UI 的 Image 组件直接引用这个 Sprite
- 作为共享图集的一部分

## 九宫格（9-slice）后缀

图层名可以附加 `_9slice_L_T_R_B` 后缀来标记九宫格，例如：
- `btn_panel_9slice_10_20_10_20`
- `img_border_9slice`（等同于 `_9slice_10_10_10_10`）

**行为**：带 9-slice 后缀的图层**不会导出 PNG**，仅将结构（位置/大小/slice
数据）写入 JSON。Unity 端会创建一个 UGUI Image 组件，但不挂任何 Sprite ——
设计师在 Unity Inspector 中手动设置 9-slice 切图和 Image.type=Sliced。

**自动前缀**：PS 插件在应用 9-slice 后缀时，如果图层没有 UGUI 前缀会自动
补 `img_`（或用户选择的 `btn_`），防止被 `marked_only` 模式静默丢弃。

## 维护规则

1. **加新前缀**：三边都要改
   - `psd_exporter/exporter.py` 的前缀常量 + `classify_layer_name`
   - `Assets/Editor/PSDImporter/PSDNode.cs` 的 `PsdNaming` 静态字段
   - `Ps_UGUI_Rename/com.ugui.rename/host/UGUI_Rename.jsx` 的 `UGUI_PREFIXES`
   - `Ps_UGUI_Rename/com.ugui.rename/client/index.html` 的按钮网格
2. **删除前缀**：先在 PSD 端全量替换成别的，再三边删。
3. **大小写**：**永远小写**。设计稿用 PascalCase 会被忽略，Camel/Pascal 都是
   转换层的责任。

## 字段命名转换规则

PSD 图层名 → C# 变量名的转换逻辑（在 Python 和 C# 两边都有，**逻辑必须一致**）：

```
prefix     + "_"     + baseName
"btn_"     + "_"     + "Close"  → "btn_Close" → field: BtnClose
"img_"     + "_"     + "bg"     → "img_bg"    → field: ImgBg
"txt_"     + "_"     + "title"  → "txt_title" → field: TxtTitle
```

去下划线 + 每段首字母大写 + 去掉空段。同名处理：`Btn` / `Btn2` / `Btn3` 递增后缀。

## 三边的同步检查（CI/手动）

- Python 端：单测覆盖每个前缀的 classify 输出
- C# 端：PsdNaming.Classify 和 Python 端返回值完全一致
- PS 插件：UGUI_PREFIXES 数组长度 == 词表条数 == index.html 按钮数
