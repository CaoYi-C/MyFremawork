// =====================================================================
//  UGUI 图层命名工具 — UXP 后端 (host 逻辑)
//
//  UXP 里 panel 本身就是 JS 运行环境,没有 CEP 那种 evalScript 往返。
//  client/index.html 通过 require('host') 引入本模块的导出函数,
//  直接同步调用 (UXP 的 IPC 已经是同步返回值)。
//
//  关键变化 (相对于旧 CEP / ExtendScript 版本):
//  - 旧 ExtendScript 限制 ES3,本文件用 ES2022+ (箭头函数 / const /
//    解构 / 模板字符串 都 OK)
//  - 所有写 activeDocument 的操作必须包在 photoshop.core.executeAsModal
//    里,否则会抛 "Cannot perform action outside of modal scope"
//  - 选区通过 app.activeDocument.activeLayers 取(只读列表),
//    改名直接 layer.name = "..."
//  - batchPlay 只在直接读 Photoshop DOM 时偶尔用,平时不用
// =====================================================================

const { app, action, core } = require('photoshop');
const { batchPlay } = action;

// =====================================================================
//  UGUI 前缀词表
//  Single source of truth:  <ProjectRoot>/Tools/PSDExporter/PREFIXES.md
//  三边必须一致：Photoshop 插件 / Python exporter / C# PSDImporter
//  - 顺序：替换匹配按数组顺序，先匹配先生效
//  - 大小写：小写
//  - 增删时三边同步
// =====================================================================
const UGUI_PREFIXES = [
    'btn_',      // Image + Button
    'export_',   // PNG only, no node in JSON tree
    'img_',      // UGUI Image (generic decoration)
    'txt_',      // UGUI Text
];

// =====================================================================
//  测试函数:检查前端能否调用 host
// =====================================================================
function ping() {
    return 'pong';
}

function getUguiPrefixes() {
    return UGUI_PREFIXES.slice();
}

// 工具函数
function _isUguiPrefix(p) {
    if (!p) return false;
    const lower = p.toLowerCase();
    return UGUI_PREFIXES.some(x => x.toLowerCase() === lower);
}

function _hasUguiPrefix(name) {
    if (!name) return false;
    const lower = name.toLowerCase();
    return UGUI_PREFIXES.some(p => lower.startsWith(p.toLowerCase()));
}

function _stripUguiPrefix(name) {
    if (!name) return '';
    const lower = name.toLowerCase();
    for (const p of UGUI_PREFIXES) {
        if (lower.startsWith(p.toLowerCase())) {
            return name.substring(p.length);
        }
    }
    return name;
}

// 校验参数并归一化
function _parseSliceParams(params) {
    if (!app.documents.length) return { error: '错误:请先打开一个 PSD 文档。' };
    const num = (v) => Math.max(0, parseInt(v, 10) || 0);
    const l = num(params.l), t = num(params.t),
          r = num(params.r), b = num(params.b);
    const mode = params.mode || 'apply';
    const autoPrefix = params.autoPrefix || '';
    if (autoPrefix !== '' && !_isUguiPrefix(autoPrefix)) {
        return { error: '错误:autoPrefix 必须是 UGUI 前缀之一(或留空):' + autoPrefix };
    }
    return { l, t, r, b, mode, autoPrefix };
}

// =====================================================================
//  mark9SliceSelected
//  给选中的图层重命名,追加 `_9slice_L_T_R_B` 后缀(默认值 10/10/10/10 时
//  简写为 `_9slice`)。Python 端会从图层名解析该后缀,输出到 JSON,
//  Unity 端再据此设置 TextureImporter.spriteBorder 和 Image.Type.Sliced。
//
//  - 已经存在的 9-slice 后缀会被先剥掉,再追加新的(可重复应用覆盖)
//  - mode = "remove" 时只剥后缀,不改名字
//  - autoPrefix 非空且图层无 UGUI 前缀时,自动拼上该前缀(防 marked_only
//    静默丢弃)。有前缀的图层不会被改,避免误伤。
// =====================================================================
async function mark9SliceSelected(params) {
    const parsed = _parseSliceParams(params);
    if (parsed.error) return parsed.error;
    const { l, t, r, b, mode, autoPrefix } = parsed;

    const doc = app.activeDocument;
    const selected = doc.activeLayers;
    if (!selected || selected.length === 0) {
        return '错误:请先选择一个或多个图层。';
    }

    let count = 0, autoPrefixed = 0, skipped = 0;
    try {
        const result = await core.executeAsModal(async (modal) => {
            for (const layer of selected) {
                const r = mark9SliceOneLayer(layer, l, t, r, b, mode, autoPrefix);
                if (r === 'ok') count++;
                else if (r === 'autoprefixed') { count++; autoPrefixed++; }
                else if (r === 'skipped') skipped++;
            }
        }, { commandName: 'UGUI 9-slice mark' });

        if (mode === 'remove') {
            return '完成:已从 ' + count + ' 个图层移除 9-slice 标记。';
        }
        let msg = '完成:已为 ' + count + ' 个图层添加 9-slice 标记 (L=' + l +
                  ' T=' + t + ' R=' + r + ' B=' + b + ')。';
        if (autoPrefixed > 0) {
            msg += '\n其中 ' + autoPrefixed + ' 个原本没有 UGUI 前缀,已自动补上 \'' + autoPrefix + '\'。';
        }
        if (skipped > 0) {
            msg = '提示:有 ' + skipped + ' 个图层没有 UGUI 前缀,且未开启自动补前缀,被跳过(会被 Python 端 marked_only 静默丢弃)。请加前缀后重试。';
        }
        return msg;
    } catch (e) {
        return '重命名失败:\n' + e.message;
    }
}

// 返回值:
//   "ok"           — 已改名
//   "autoprefixed" — 改名了,且本次替换了前缀
//   "skipped"      — 跳过(mode=apply,无前缀,且未开启 autoPrefix)
function mark9SliceOneLayer(layer, l, t, r, b, mode, autoPrefix) {
    // 先剥掉已有 9-slice 后缀(有值 / 无值两种)
    let name = layer.name.replace(/_9slice(_\d+_\d+_\d+_\d+)?$/, '');

    if (mode === 'remove') {
        if (name !== layer.name) layer.name = name;
        return 'ok';
    }

    // 处理 UGUI 前缀:autoPrefix 非空时,统一把图层名前缀"对齐"到
    // autoPrefix 指定的项 —— 无论原来有没有前缀、是什么前缀。
    let autoAdded = false;
    const hasPrefix = _hasUguiPrefix(name);
    if (autoPrefix) {
        const base = _stripUguiPrefix(name);
        name = autoPrefix + base;
        if (!hasPrefix || name.toLowerCase() !== (autoPrefix + base).toLowerCase()) {
            autoAdded = true;
        }
    } else {
        if (!hasPrefix) return 'skipped';
    }

    // Always emit the full L_T_R_B suffix, even when all four are 10.
    const suffix = '_9slice_' + l + '_' + t + '_' + r + '_' + b;
    layer.name = name + suffix;
    return autoAdded ? 'autoprefixed' : 'ok';
}

// =====================================================================
//  renameSelectedLayers — 主入口
//  params = { prefix, replaceOldPrefix, toLowerCase, spaceToUnderline,
//             recursive }
//  直接接 JS 对象(不是 JSON 字符串)。UXP 的 require() 已经是同步传值,
//  不需要再 evalScript + JSON.parse。
// =====================================================================
async function renameSelectedLayers(params) {
    if (!app.documents.length) return '错误:请先打开一个 PSD 文档。';
    if (!params.prefix) return '错误:前缀不能为空。';

    let prefix = (params.prefix || '').trim();
    if (prefix === '') return '错误:前缀不能为空。';
    if (prefix.charAt(prefix.length - 1) !== '_') prefix += '_';

    const options = {
        replaceOldPrefix: !!params.replaceOldPrefix,
        toLowerCase: !!params.toLowerCase,
        spaceToUnderline: !!params.spaceToUnderline,
        recursive: !!params.recursive,
    };

    const doc = app.activeDocument;
    const selected = doc.activeLayers;
    if (!selected || selected.length === 0) {
        return '错误:请先选择一个或多个图层。';
    }

    let count = 0;
    try {
        await core.executeAsModal(async () => {
            for (const layer of selected) {
                if (options.recursive) {
                    count += renameLayerRecursive(layer, prefix, options);
                } else {
                    renameOneLayer(layer, prefix, options);
                    count++;
                }
            }
        }, { commandName: 'UGUI Rename Prefix' });
        return '完成:已处理 ' + count + ' 个图层,前缀为:' + prefix;
    } catch (e) {
        return '重命名失败:\n' + e.message;
    }
}

// 递归处理图层组
function renameLayerRecursive(layer, prefix, options) {
    let count = 0;
    renameOneLayer(layer, prefix, options);
    count++;
    if (layer.layers) {   // LayerSet
        for (const child of layer.layers) {
            count += renameLayerRecursive(child, prefix, options);
        }
    }
    return count;
}

function renameOneLayer(layer, prefix, options) {
    const newBaseName = normalizeName(layer.name, options);
    layer.name = prefix + newBaseName;
}

function normalizeName(name, options) {
    let result = (name || '').trim();
    if (options.replaceOldPrefix) {
        const lower = result.toLowerCase();
        for (const p of UGUI_PREFIXES) {
            if (lower.startsWith(p.toLowerCase())) {
                result = result.substring(p.length);
                break;
            }
        }
    }
    result = result.trim();
    if (options.spaceToUnderline) {
        result = result.replace(/\s+/g, '_');
    }
    result = result.replace(/_+/g, '_').replace(/^_+/, '').replace(/_+$/, '');
    if (options.toLowerCase) result = result.toLowerCase();
    if (result === '') result = 'unnamed';
    return result;
}

// =====================================================================
//  markFontSelected — 给 txt_ 图层追加 / 移除字体后缀
//  params.mode: "apply" | "remove"
//  params.tag:  字体 tag，如 "SansCN-Bold"
//
//  - apply 时先移除已有后缀，再追加新后缀
//  - remove 时只移除后缀
//  - 只处理以 txt_ 开头的图层
// =====================================================================
async function markFontSelected(params) {
    if (!app.documents.length) return '错误:请先打开一个 PSD 文档。';

    const mode = params.mode || 'apply';
    const tag = params.tag || '';

    const doc = app.activeDocument;
    const selected = doc.activeLayers;
    if (!selected || selected.length === 0) {
        return '错误:请先选择一个或多个图层。';
    }

    let count = 0, skipped = 0;
    try {
        await core.executeAsModal(async () => {
            for (const layer of selected) {
                const name = layer.name;
                const lower = (name || '').trim().toLowerCase();
                if (!lower.startsWith('txt_')) {
                    skipped++;
                    continue;
                }
                // 1) 剥离 _9slice 后缀
                let cleanName = name.replace(/_9slice(_\d+_\d+_\d+_\d+)?$/, '');
                // 2) 剥离已有的字体 tag(最后一个 _xxx)
                const lastUnderscore = cleanName.lastIndexOf('_');
                if (lastUnderscore > 4) {
                    const suffix = cleanName.substring(lastUnderscore + 1);
                    if (!/^\d+$/.test(suffix)) {
                        cleanName = cleanName.substring(0, lastUnderscore);
                    }
                }
                if (mode === 'apply' && tag !== '') {
                    layer.name = cleanName + '_' + tag;
                } else {
                    layer.name = cleanName;
                }
                count++;
            }
        }, { commandName: 'UGUI Font Tag' });

        if (skipped > 0) {
            return '完成:已处理 ' + count + ' 个图层 (跳过 ' + skipped + ' 个非 txt_ 图层)';
        }
        return '完成:已处理 ' + count + ' 个图层';
    } catch (e) {
        return '重命名失败:\n' + e.message;
    }
}

// =====================================================================
//  导出接口 — client/index.html 通过 require('host') 拿到这些
// =====================================================================
module.exports = {
    ping,
    getUguiPrefixes,
    mark9SliceSelected,
    renameSelectedLayers,
    markFontSelected,
    UGUI_PREFIXES,
};