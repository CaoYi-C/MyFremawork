// 获取 CSInterface 实例,用于前端与 ExtendScript 通信
var csInterface = new CSInterface();

// 获取 DOM 元素
var cbReplace = document.getElementById('cbReplace');
var cbLower = document.getElementById('cbLower');
var cbSpace = document.getElementById('cbSpace');
var cbRecursive = document.getElementById('cbRecursive');
var customPrefixInput = document.getElementById('customPrefix');
var applyCustomBtn = document.getElementById('applyCustom');

// 9-slice inputs and buttons
var sliceL = document.getElementById('sliceL');
var sliceT = document.getElementById('sliceT');
var sliceR = document.getElementById('sliceR');
var sliceB = document.getElementById('sliceB');
var apply9SliceBtn = document.getElementById('apply9Slice');
var remove9SliceBtn = document.getElementById('remove9Slice');
// Auto-prefix controls: when a layer has no UGUI prefix at all, the
// Python exporter's marked_only filter will silently drop it. So when
// the designer hits "apply 9-slice" on a layer named e.g. "panel" (no
// prefix), we offer to prepend `img_` or `btn_` automatically.
var cbAutoPrefix = document.getElementById('cbAutoPrefix');
var autoPrefixSel = document.getElementById('autoPrefixSel');

// 为所有带 'data-prefix' 属性的按钮添加点击事件
var allBtns = document.querySelectorAll('[data-prefix]');
for (var i = 0; i < allBtns.length; i++) {
  allBtns[i].addEventListener('click', function(e) {
    var btn = e.currentTarget;
    var prefix = btn.getAttribute('data-prefix');
    // 调用后台方法,并传递选项
    callRename(prefix);
  });
}

// 为"应用"按钮添加事件
if (applyCustomBtn) {
  applyCustomBtn.addEventListener('click', function() {
    var prefix = customPrefixInput.value;
    if (prefix && prefix.trim()) {
      callRename(prefix);
    } else {
      alert('请输入自定义前缀');
    }
  });
}

// 9-slice 应用按钮：把当前 L/T/R/B 值发给 ExtendScript
if (apply9SliceBtn) {
  apply9SliceBtn.addEventListener('click', function() {
    var l = parseInt(sliceL.value, 10);
    var t = parseInt(sliceT.value, 10);
    var r = parseInt(sliceR.value, 10);
    var b = parseInt(sliceB.value, 10);
    if (!isFinite(l) || l < 0) l = 0;
    if (!isFinite(t) || t < 0) t = 0;
    if (!isFinite(r) || r < 0) r = 0;
    if (!isFinite(b) || b < 0) b = 0;
    var autoPrefix = cbAutoPrefix && cbAutoPrefix.checked
      ? (autoPrefixSel ? autoPrefixSel.value : '')
      : '';
    call9Slice(l, t, r, b, 'apply', autoPrefix);
  });
}

// 9-slice 移除按钮
if (remove9SliceBtn) {
  remove9SliceBtn.addEventListener('click', function() {
    call9Slice(0, 0, 0, 0, 'remove', '');
  });
}

/**
 * 调用后台 ExtendScript 给选中图层添加/移除 9-slice 后缀。
 * 9-slice 后缀格式：_9slice_L_T_R_B（当 L=T=R=B=10 时简写为 _9slice）。
 *
 * autoPrefix: 当图层完全没有 UGUI 前缀时，自动拼上的前缀。空字符串
 *  表示不自动补（保留原行为）。非空时只有"无前缀"的图层才会被改，
 *  有前缀的图层不动 —— 避免误改。
 */
function call9Slice(l, t, r, b, mode, autoPrefix) {
  var paramStr = '{l:' + l +
    ',t:' + t +
    ',r:' + r +
    ',b:' + b +
    ',mode:' + JSON.stringify(mode) +
    ',autoPrefix:' + JSON.stringify(autoPrefix || '') +
  '}';
  csInterface.evalScript('mark9SliceSelected(' + paramStr + ')', function(result) {
    if (result && /^(错误|重命名失败|提示)/.test(result)) {
      alert(result);
    }
  });
}

/**
 * 调用后台 ExtendScript 进行重命名
 * 直接构造 ExtendScript 兼容的 JS 对象字面量字符串传过去
 * (ExtendScript 没有内置 JSON,且其 eval 解析有兼容问题,走对象字面量最稳)
 */
function callRename(prefix) {
  var replaceOldPrefix = cbReplace.checked;
  var toLowerCase = cbLower.checked;
  var spaceToUnderline = cbSpace.checked;
  var recursive = cbRecursive.checked;
  // 用 JSON.stringify 安全处理 prefix 字符串(转义引号/反斜杠/换行等)
  var paramStr = '{prefix:' + JSON.stringify(prefix) +
    ',replaceOldPrefix:' + replaceOldPrefix +
    ',toLowerCase:' + toLowerCase +
    ',spaceToUnderline:' + spaceToUnderline +
    ',recursive:' + recursive +
  '}';
  // evalScript 会把整个字符串当 ExtendScript 代码执行
  csInterface.evalScript('renameSelectedLayers(' + paramStr + ')', function(result) {
    if (result && /^(错误|重命名失败)/.test(result)) { // 成功静默,只有错误才弹窗
      alert(result);
    }
  });
}

// ──────────────────────────────────────────────────────────────────
//  字体标记面板
//  从 font_mapping.js 的 FONT_MAPPING 数组读取字体列表
// ──────────────────────────────────────────────────────────────────
var fontTagGrid = document.getElementById('fontTagGrid');
var customFontTagInput = document.getElementById('customFontTag');
var applyCustomFontTagBtn = document.getElementById('applyCustomFontTag');
var removeFontTagBtn = document.getElementById('removeFontTag');

(function initFontPanel() {
  var fonts = (typeof FONT_MAPPING !== 'undefined') ? FONT_MAPPING : [];
  if (!fonts || fonts.length === 0) {
    fontTagGrid.innerHTML = '<button disabled>无字体</button>';
    return;
  }
  for (var i = 0; i < fonts.length; i++) {
    var item = fonts[i];
    var btn = document.createElement('button');
    btn.textContent = item.label;
    btn.addEventListener('click', (function(tag) {
      return function() { callFontTag(tag); };
    })(item.tag));
    fontTagGrid.appendChild(btn);
  }
})();

function callFontTag(tag) {
  var paramStr = '{tag:' + JSON.stringify(tag) + ',mode:"apply"}';
  csInterface.evalScript('markFontSelected(' + paramStr + ')', function(result) {
    if (result && /^(错误|重命名失败|提示)/.test(result)) {
      alert(result);
    }
  });
}

if (removeFontTagBtn) {
  removeFontTagBtn.addEventListener('click', function() {
    csInterface.evalScript('markFontSelected({tag:"",mode:"remove"})', function(result) {
      if (result && /^(错误|重命名失败|提示)/.test(result)) {
        alert(result);
      }
    });
  });
}

if (applyCustomFontTagBtn) {
  applyCustomFontTagBtn.addEventListener('click', function() {
    var tag = customFontTagInput.value;
    if (tag && tag.trim()) {
      callFontTag(tag.trim());
    } else {
      alert('请输入字体 Tag');
    }
  });
}