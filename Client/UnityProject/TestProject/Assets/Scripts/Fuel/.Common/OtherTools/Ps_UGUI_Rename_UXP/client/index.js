// =====================================================================
//  UGUI 图层命名工具 — UXP 前端
//
//  与 CEP 版的关键区别:
//  - 没有 CSInterface — 所有 PS 操作走 `require('photoshop')`
//  - 没有 evalScript — 直接 require('../host.js') 拿到 host 函数同步调用
//  - 写 activeDocument 的操作(改名)必须在 executeAsModal 上下文里;
//    host 模块内部已经包好了,前端只是 await 即可
//  - 没有 JSON 字符串 — host 函数接 JS 对象,直接传
// =====================================================================

// Photoshop 23.0+ 提供这个 UXP 内置模块。
// 在更老的 PS 上不存在 — 我们的 manifest 要求 >= 23.0 所以 OK。
const { app } = require('photoshop');

// host.js 跟 client/ 同级(都在扩展根目录)。UXP 的 require 跟 Node 一样
// 走 CommonJS,所以可以同步拿到导出对象。
const host = require('../host.js');

// 获取 DOM 元素
const cbReplace   = document.getElementById('cbReplace');
const cbLower     = document.getElementById('cbLower');
const cbSpace     = document.getElementById('cbSpace');
const cbRecursive = document.getElementById('cbRecursive');
const customPrefixInput = document.getElementById('customPrefix');
const applyCustomBtn    = document.getElementById('applyCustom');

// 9-slice inputs and buttons
const sliceL = document.getElementById('sliceL');
const sliceT = document.getElementById('sliceT');
const sliceR = document.getElementById('sliceR');
const sliceB = document.getElementById('sliceB');
const apply9SliceBtn   = document.getElementById('apply9Slice');
const remove9SliceBtn  = document.getElementById('remove9Slice');
// Auto-prefix controls: when a layer has no UGUI prefix at all, the
// Python exporter's marked_only filter will silently drop it. So when
// the designer hits "apply 9-slice" on a layer named e.g. "panel" (no
// prefix), we offer to prepend `img_` or `btn_` automatically.
const cbAutoPrefix = document.getElementById('cbAutoPrefix');
const autoPrefixSel = document.getElementById('autoPrefixSel');

// 为所有带 'data-prefix' 属性的按钮添加点击事件
const allBtns = document.querySelectorAll('[data-prefix]');
for (const btn of allBtns) {
  btn.addEventListener('click', (e) => {
    const prefix = e.currentTarget.getAttribute('data-prefix');
    callRename(prefix);
  });
}

// "应用"自定义前缀按钮
if (applyCustomBtn) {
  applyCustomBtn.addEventListener('click', () => {
    const prefix = customPrefixInput.value;
    if (prefix && prefix.trim()) {
      callRename(prefix);
    } else {
      alert('请输入自定义前缀');
    }
  });
}

// 9-slice 应用按钮
if (apply9SliceBtn) {
  apply9SliceBtn.addEventListener('click', () => {
    const num = (v, d) => {
      const n = parseInt(v, 10);
      return isFinite(n) && n >= 0 ? n : d;
    };
    const l = num(sliceL.value, 0);
    const t = num(sliceT.value, 0);
    const r = num(sliceR.value, 0);
    const b = num(sliceB.value, 0);
    const autoPrefix = cbAutoPrefix && cbAutoPrefix.checked
      ? (autoPrefixSel ? autoPrefixSel.value : '')
      : '';
    call9Slice(l, t, r, b, 'apply', autoPrefix);
  });
}

// 9-slice 移除按钮
if (remove9SliceBtn) {
  remove9SliceBtn.addEventListener('click', () => {
    call9Slice(0, 0, 0, 0, 'remove', '');
  });
}

/**
 * 调用 host.mark9SliceSelected
 * host 是同步返回字符串(UXP 的 promise resolve 后是 string)。
 */
async function call9Slice(l, t, r, b, mode, autoPrefix) {
  try {
    const result = await host.mark9SliceSelected({
      l, t, r, b, mode,
      autoPrefix: autoPrefix || '',
    });
    if (result && /^(错误|重命名失败|提示)/.test(result)) {
      alert(result);
    }
  } catch (e) {
    alert('调用失败: ' + (e.message || e));
  }
}

/**
 * 调用 host.renameSelectedLayers
 * 走的是 host 内部包好的 executeAsModal — 前端只是 await。
 */
async function callRename(prefix) {
  try {
    const result = await host.renameSelectedLayers({
      prefix,
      replaceOldPrefix: !!cbReplace.checked,
      toLowerCase: !!cbLower.checked,
      spaceToUnderline: !!cbSpace.checked,
      recursive: !!cbRecursive.checked,
    });
    if (result && /^(错误|重命名失败)/.test(result)) {
      alert(result);
    }
  } catch (e) {
    alert('调用失败: ' + (e.message || e));
  }
}

// ──────────────────────────────────────────────────────────────────
//  字体标记面板 — 从 font_mapping.js 的 FONT_MAPPING 数组读取
// ──────────────────────────────────────────────────────────────────
const fontTagGrid         = document.getElementById('fontTagGrid');
const customFontTagInput  = document.getElementById('customFontTag');
const applyCustomFontTagBtn = document.getElementById('applyCustomFontTag');
const removeFontTagBtn    = document.getElementById('removeFontTag');

(function initFontPanel() {
  const fonts = (typeof FONT_MAPPING !== 'undefined') ? FONT_MAPPING : [];
  if (!fonts || fonts.length === 0) {
    fontTagGrid.innerHTML = '<button disabled>无字体</button>';
    return;
  }
  for (const item of fonts) {
    const btn = document.createElement('button');
    btn.textContent = item.label;
    btn.addEventListener('click', () => callFontTag(item.tag));
    fontTagGrid.appendChild(btn);
  }
})();

async function callFontTag(tag) {
  try {
    const result = await host.markFontSelected({ tag, mode: 'apply' });
    if (result && /^(错误|重命名失败|提示)/.test(result)) {
      alert(result);
    }
  } catch (e) {
    alert('调用失败: ' + (e.message || e));
  }
}

if (removeFontTagBtn) {
  removeFontTagBtn.addEventListener('click', async () => {
    try {
      const result = await host.markFontSelected({ tag: '', mode: 'remove' });
      if (result && /^(错误|重命名失败|提示)/.test(result)) {
        alert(result);
      }
    } catch (e) {
      alert('调用失败: ' + (e.message || e));
    }
  });
}

if (applyCustomFontTagBtn) {
  applyCustomFontTagBtn.addEventListener('click', () => {
    const tag = customFontTagInput.value;
    if (tag && tag.trim()) {
      callFontTag(tag.trim());
    } else {
      alert('请输入字体 Tag');
    }
  });
}

// ──────────────────────────────────────────────────────────────────
//  startup ping — 验证 host require 链路通了
// ──────────────────────────────────────────────────────────────────
(async () => {
  try {
    const p = host.ping();
    if (p === 'pong') {
      console.log('[UGUI Rename UXP] host module loaded OK');
    } else {
      console.warn('[UGUI Rename UXP] unexpected ping response:', p);
    }
  } catch (e) {
    console.error('[UGUI Rename UXP] host.ping failed:', e);
  }
})();