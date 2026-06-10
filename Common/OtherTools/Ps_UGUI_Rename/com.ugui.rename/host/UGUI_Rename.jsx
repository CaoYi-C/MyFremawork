#target photoshop

// =====================================================================
//  UGUI 前缀词表
//  Single source of truth:  <ProjectRoot>/Tools/PSDExporter/PREFIXES.md
//  三边必须一致：Photoshop 插件 / Python exporter / C# PSDImporter
//  - 顺序：替换匹配按数组顺序，先匹配先生效
//  - 大小写：小写
//  - 增删时三边同步
// =====================================================================
var UGUI_PREFIXES = [
    "btn_",      // Image + Button
    "export_",   // PNG only, no node in JSON tree
    "img_",      // UGUI Image (generic decoration)
    "txt_",      // UGUI Text
];

// 测试函数:检查前端能否调用后台
function ping() {
    return "pong";
}

// 把前缀词表返回给前端,避免在前端硬编码第二份。前端需要决定
// "哪些前缀算 UGUI 前缀" 时直接调这个。
function getUguiPrefixes() {
    return UGUI_PREFIXES.slice();   // 拷贝,防前端改
}

// =====================================================================
//  9-slice 标记
//
//  给选中的图层重命名,追加 `_9slice_L_T_R_B` 后缀(默认值 10/10/10/10 时
//  简写为 `_9slice`)。Python 端会从图层名解析该后缀,输出到 JSON,
//  Unity 端再据此设置 TextureImporter.spriteBorder 和 Image.Type.Sliced。
//
//  - 已经存在的 9-slice 后缀会被先剥掉,再追加新的(可重复应用覆盖)
//  - mode = "remove" 时只剥后缀,不改名字
//  - autoPrefix 非空且图层无 UGUI 前缀时,自动拼上该前缀(防 marked_only
//    静默丢弃)。有前缀的图层不会被改,避免误伤。
// =====================================================================
function mark9SliceSelected(params) {
    if (!app.documents.length) {
        return "错误:请先打开一个 PSD 文档。";
    }
    var l = Math.max(0, parseInt(params.l, 10) || 0);
    var t = Math.max(0, parseInt(params.t, 10) || 0);
    var r = Math.max(0, parseInt(params.r, 10) || 0);
    var b = Math.max(0, parseInt(params.b, 10) || 0);
    var mode = params.mode || "apply";
    var autoPrefix = params.autoPrefix || "";

    // 校验 autoPrefix:必须是 UGUI_PREFIXES 里的成员(防前端传错)
    if (autoPrefix !== "" && !_isUguiPrefix(autoPrefix)) {
        return "错误:autoPrefix 必须是 UGUI 前缀之一(或留空):" + autoPrefix;
    }

    var doc = app.activeDocument;
    var selectedIds = getSelectedLayerIds();
    if (!selectedIds || selectedIds.length === 0) {
        return "错误:请先选择一个或多个图层。";
    }

    var count = 0;
    var autoPrefixed = 0;
    var skipped = 0;
    try {
        for (var i = 0; i < selectedIds.length; i++) {
            selectLayerById(selectedIds[i], false);
            var layer = doc.activeLayer;
            var result = mark9SliceOneLayer(layer, l, t, r, b, mode, autoPrefix);
            if (result === "ok") {
                count++;
            } else if (result === "autoprefixed") {
                count++;
                autoPrefixed++;
            } else if (result === "skipped") {
                skipped++;
            }
        }
        restoreSelectionByIds(selectedIds);
        if (mode === "remove") {
            return "完成:已从 " + count + " 个图层移除 9-slice 标记。";
        }
        var msg = "完成:已为 " + count + " 个图层添加 9-slice 标记 (L=" + l +
                  " T=" + t + " R=" + r + " B=" + b + ")。";
        if (autoPrefixed > 0) {
            msg += "\n其中 " + autoPrefixed + " 个原本没有 UGUI 前缀,已自动补上 '" + autoPrefix + "'。";
        }
        if (skipped > 0) {
            msg += "\n提示:" + skipped + " 个图层没有 UGUI 前缀,且未开启自动补前缀,被跳过(会被 Python 端 marked_only 静默丢弃)。请加前缀后重试。";
            msg = "提示:" + msg.substring(msg.indexOf("\n") + 1);
        }
        return msg;
    } catch (e) {
        try { restoreSelectionByIds(selectedIds); } catch (er) {}
        return "重命名失败:\n" + e.message;
    }
}

// 在 UGUI_PREFIXES 里查前缀(忽略大小写)。空串返回 false。
function _isUguiPrefix(p) {
    if (!p) return false;
    var lower = p.toLowerCase();
    for (var i = 0; i < UGUI_PREFIXES.length; i++) {
        if (UGUI_PREFIXES[i].toLowerCase() === lower) return true;
    }
    return false;
}

// 检查 name 是否以任意 UGUI 前缀开头(忽略大小写)
function _hasUguiPrefix(name) {
    if (!name) return false;
    var lower = name.toLowerCase();
    for (var i = 0; i < UGUI_PREFIXES.length; i++) {
        if (lower.indexOf(UGUI_PREFIXES[i].toLowerCase()) === 0) return true;
    }
    return false;
}

// 剥掉 name 任意位置开头的 UGUI 前缀,返回剥完后的 base 名。
// 例如 "_stripUguiPrefix('btn_use')" → 'use'
//     "_stripUguiPrefix('BG_Login')" → 'Login'   (大小写不敏感)
//     "_stripUguiPrefix('panel')"    → 'panel'  (没前缀就不剥)
function _stripUguiPrefix(name) {
    if (!name) return "";
    var lower = name.toLowerCase();
    for (var i = 0; i < UGUI_PREFIXES.length; i++) {
        var p = UGUI_PREFIXES[i].toLowerCase();
        if (lower.indexOf(p) === 0) {
            return name.substring(UGUI_PREFIXES[i].length);
        }
    }
    return name;
}

// 返回值:
//   "ok"           — 已改名(无前缀变动,或 autoPrefix 未启用但有前缀)
//   "autoprefixed" — 改名了,且本次替换了前缀(无论从无→有,还是有→新)
//   "skipped"      — 跳过(mode=apply,无前缀,且未开启 autoPrefix)
function mark9SliceOneLayer(layer, l, t, r, b, mode, autoPrefix) {
    // 先剥掉已有 9-slice 后缀(有值 / 无值两种),用 ECMAScript 3 兼容语法
    var name = layer.name;
    name = name.replace(/_9slice(_\d+_\d+_\d+_\d+)?$/, "");

    if (mode === "remove") {
        if (name !== layer.name) {
            layer.name = name;
        }
        return "ok";
    }

    // 处理 UGUI 前缀:autoPrefix 非空时,统一把图层名前缀"对齐"到
    // autoPrefix 指定的项 —— 无论原来有没有前缀、是什么前缀。这样
    // 设计师在面板上把下拉从 btn_ 切到 img_,再点一次"应用",就把
    // 之前补的 btn_ 替换成 img_,9-slice 后缀保持不变。
    var autoAdded = false;
    var hasPrefix = _hasUguiPrefix(name);
    if (autoPrefix) {
        // 剥掉任意已有 UGUI 前缀,再拼上 autoPrefix
        var base = _stripUguiPrefix(name);
        name = autoPrefix + base;
        // 区分"无→有"和"有→新"两种 autoprefixed 情形
        if (!hasPrefix || name.toLowerCase() !== (autoPrefix + base).toLowerCase()) {
            autoAdded = true;
        }
    } else {
        // 未启用 autoPrefix:有前缀的图层就完全不动前缀,只接 9-slice 后缀
        if (!hasPrefix) {
            return "skipped";
        }
    }

    // Always emit the full L_T_R_B suffix, even when all four are 10.
    // Bare `_9slice` is harder to read in Photoshop's layer panel —
    // seeing the explicit values tells the designer what they set.
    var suffix = "_9slice_" + l + "_" + t + "_" + r + "_" + b;
    layer.name = name + suffix;
    return autoAdded ? "autoprefixed" : "ok";
}

// 主入口函数 - params 是 JS 对象(由前端直接构造对象字面量传过来,不是 JSON 字符串)
// 之前是 renameSelectedLayers(paramsJson) + JSON.parse,因 ExtendScript (ECMAScript 3) 没有
// 内置 JSON 且其 eval 对复杂 JSON 解析有兼容问题("应为: ]" 错误),改为直接接对象最稳
function renameSelectedLayers(params) {
    // 调试输出(可在 ExtendScript Toolkit 中查看)
    $.writeln("renameSelectedLayers called with prefix: " + params.prefix);

    var prefix = params.prefix;
    var options = {
        replaceOldPrefix: params.replaceOldPrefix,
        toLowerCase: params.toLowerCase,
        spaceToUnderline: params.spaceToUnderline,
        recursive: params.recursive
    };

    if (!app.documents.length) {
        return "错误:请先打开一个 PSD 文档。";
    }
    if (!prefix) {
        return "错误:前缀不能为空。";
    }
    prefix = trim(prefix);
    if (prefix === "") {
        return "错误:前缀不能为空。";
    }
    if (prefix.charAt(prefix.length - 1) !== "_") {
        prefix += "_";
    }

    var doc = app.activeDocument;
    var selectedIds = getSelectedLayerIds();
    if (!selectedIds || selectedIds.length === 0) {
        return "错误:请先选择一个或多个图层。";
    }

    var count = 0;
    try {
        for (var i = 0; i < selectedIds.length; i++) {
            selectLayerById(selectedIds[i], false);
            var layer = doc.activeLayer;
            if (options.recursive && layer.typename === "LayerSet") {
                count += renameLayerRecursive(layer, prefix, options);
            } else {
                renameOneLayer(layer, prefix, options);
                count++;
            }
        }
        restoreSelectionByIds(selectedIds);
        return "完成:已处理 " + count + " 个图层,前缀为:" + prefix;
    } catch (e) {
        try { restoreSelectionByIds(selectedIds); } catch (er) {}
        return "重命名失败:\n" + e.message;
    }
}

// 递归处理图层组
function renameLayerRecursive(layer, prefix, options) {
    var count = 0;
    renameOneLayer(layer, prefix, options);
    count++;
    if (layer.typename === "LayerSet") {
        for (var i = 0; i < layer.layers.length; i++) {
            count += renameLayerRecursive(layer.layers[i], prefix, options);
        }
    }
    return count;
}

function renameOneLayer(layer, prefix, options) {
    var oldName = layer.name;
    var newBaseName = normalizeName(oldName, options);
    layer.name = prefix + newBaseName;
}

function normalizeName(name, options) {
    var result = trim(name);
    if (options.replaceOldPrefix) {
        var lowerName = result.toLowerCase();
        for (var i = 0; i < UGUI_PREFIXES.length; i++) {
            var p = UGUI_PREFIXES[i].toLowerCase();
            if (lowerName.indexOf(p) === 0) {
                result = result.substring(p.length);
                break;
            }
        }
    }
    result = trim(result);
    if (options.spaceToUnderline) {
        result = result.replace(/\s+/g, "_");
    }
    result = result.replace(/_+/g, "_");
    result = result.replace(/^_+/, "");
    result = result.replace(/_+$/, "");
    if (options.toLowerCase) {
        result = result.toLowerCase();
    }
    if (result === "") {
        result = "unnamed";
    }
    return result;
}

function trim(str) {
    return String(str).replace(/^\s+|\s+$/g, "");
}

function getSelectedLayerIds() {
    var ids = [];
    var ref = new ActionReference();
    ref.putProperty(charIDToTypeID("Prpr"), stringIDToTypeID("targetLayersIDs"));
    ref.putEnumerated(charIDToTypeID("Dcmn"), charIDToTypeID("Ordn"), charIDToTypeID("Trgt"));
    try {
        var desc = executeActionGet(ref);
        if (desc.hasKey(stringIDToTypeID("targetLayersIDs"))) {
            var list = desc.getList(stringIDToTypeID("targetLayersIDs"));
            for (var i = 0; i < list.count; i++) {
                ids.push(list.getReference(i).getIdentifier());
            }
            return ids;
        }
    } catch (e) {}
    try {
        var ref2 = new ActionReference();
        ref2.putProperty(charIDToTypeID("Prpr"), charIDToTypeID("LyrI"));
        ref2.putEnumerated(charIDToTypeID("Lyr "), charIDToTypeID("Ordn"), charIDToTypeID("Trgt"));
        var desc2 = executeActionGet(ref2);
        ids.push(desc2.getInteger(charIDToTypeID("LyrI")));
    } catch (e2) {}
    return ids;
}

function selectLayerById(id, add) {
    var desc = new ActionDescriptor();
    var ref = new ActionReference();
    ref.putIdentifier(charIDToTypeID("Lyr "), id);
    desc.putReference(charIDToTypeID("null"), ref);
    if (add) {
        desc.putEnumerated(stringIDToTypeID("selectionModifier"),
            stringIDToTypeID("selectionModifierType"),
            stringIDToTypeID("addToSelection"));
    }
    desc.putBoolean(charIDToTypeID("MkVs"), false);
    executeAction(charIDToTypeID("slct"), desc, DialogModes.NO);
}

function restoreSelectionByIds(ids) {
    if (!ids || ids.length === 0) return;
    selectLayerById(ids[0], false);
    for (var i = 1; i < ids.length; i++) {
        selectLayerById(ids[i], true);
    }
}

// =====================================================================
//  字体后缀标记
//  给选中的 txt_ 图层追加/移除字体后缀。
//  格式: txt_basename_FontTag  (例如 txt_title_SansCN-Bold)
//
//  params.mode: "apply" (设置/替换后缀) | "remove" (清除后缀)
//  params.tag:  字体 tag，如 "SansCN-Bold"
//
//  - apply 时先移除已有后缀，再追加新后缀
//  - remove 时只移除后缀
//  - 只处理以 txt_ 开头的图层（忽略其他前缀）
// =====================================================================
function markFontSelected(params) {
    if (!app.documents.length) {
        return "错误:请先打开一个 PSD 文档。";
    }
    var mode = params.mode || "apply";
    var tag = params.tag || "";

    var doc = app.activeDocument;
    var selectedIds = getSelectedLayerIds();
    if (!selectedIds || selectedIds.length === 0) {
        return "错误:请先选择一个或多个图层。";
    }

    var count = 0;
    var skipped = 0;
    try {
        for (var i = 0; i < selectedIds.length; i++) {
            selectLayerById(selectedIds[i], false);
            var layer = doc.activeLayer;
            var name = layer.name;
            var lower = trim(name).toLowerCase();

            // 只处理 txt_ 前缀的图层
            if (lower.indexOf("txt_") !== 0) {
                skipped++;
                continue;
            }

            // 移除已有字体后缀：图层名末尾的 _FontTag
            // 字体后缀格式: 最后一个 _ 后面是 tag（但排除 _9slice 后缀）
            // 策略: 先剥离 _9slice 相关后缀, 然后剥离最后一个 _xxx tag
            var cleanName = name;
            // 1. 剥离 _9slice 及 _9slice_L_T_R_B
            cleanName = cleanName.replace(/_9slice(_\d+_\d+_\d+_\d+)?$/, "");
            // 2. 剥离已有的字体 tag（最后一个 _xxx，不是数字也不是 9slice）
            //    字体 tag 通常包含字母和连字符
            var lastUnderscore = cleanName.lastIndexOf("_");
            if (lastUnderscore > 4) {  // 确保 txt_x 之后还有内容
                var suffix = cleanName.substring(lastUnderscore + 1);
                // 如果是纯数字（如 01）则保留
                if (!/^\d+$/.test(suffix)) {
                    cleanName = cleanName.substring(0, lastUnderscore);
                }
            }

            if (mode === "apply" && tag !== "") {
                layer.name = cleanName + "_" + tag;
            } else {
                layer.name = cleanName;
            }
            count++;
        }
        restoreSelectionByIds(selectedIds);
        if (skipped > 0) {
            return "完成:已处理 " + count + " 个图层 (跳过 " + skipped + " 个非 txt_ 图层)";
        }
        return "完成:已处理 " + count + " 个图层";
    } catch (e) {
        try { restoreSelectionByIds(selectedIds); } catch (er) {}
        return "重命名失败:\n" + e.message;
    }
}