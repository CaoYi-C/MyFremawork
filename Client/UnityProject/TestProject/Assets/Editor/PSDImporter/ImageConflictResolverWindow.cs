// ImageConflictResolverWindow.cs
//
// Modal EditorWindow that shows the user a side-by-side preview of
//   - the PNG already in <imageOutputRoot>/<psdName>/<layerName>.png
//   - the new PNG Python just produced
// for every layer whose existing image has DIFFERENT content from the
// new one. The user picks "keep" (default) or "overwrite" per row, then
// clicks Apply. Cancel aborts the import.
//
// The window is modal via ShowModalUtility() — it blocks the caller
// (PSDImporter.Import) until the user decides, but the rest of the
// Unity Editor remains responsive (the user can still scroll around
// the Project window, etc.).

using System.Collections.Generic;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEngine;

namespace PSDImporter.Editor
{
    public class ImageConflictResolverWindow : EditorWindow
    {
        public class ImageConflict
        {
            public string layerId;            // e.g. "root/使用1/组 126/btn_use"
            public string layerName;          // e.g. "btn_use"
            public string psdName;
            public string newImagePath;       // absolute
            public string existingImagePath;  // absolute
            public int    newSizeBytes;
            public int    existingSizeBytes;
            public int    newWidth;           // PNG pixel dimensions
            public int    newHeight;
            public int    existingWidth;
            public int    existingHeight;
            public string newHash;            // short sha256 prefix
            public string existingHash;
        }

        private List<ImageConflict> _conflicts;
        private Dictionary<string, bool> _overwrites;        // layerId → true=overwrite
        private Dictionary<string, Texture2D> _newTexCache;  // layerId → loaded new PNG
        private Dictionary<string, Texture2D> _existingTexCache;
        private Vector2 _scroll;
        private bool    _resultReady;
        private Dictionary<string, bool> _result;            // null ⇒ user cancelled

        /// <summary>
        /// Show the modal conflict resolver. Returns the user's
        /// per-layer decisions (layerId → overwrite), or null if the
        /// user clicked Cancel. Returns an empty dict if conflicts is
        /// empty (caller should treat that as "nothing to resolve").
        /// </summary>
        public static Dictionary<string, bool> Resolve(List<ImageConflict> conflicts)
        {
            if (conflicts == null || conflicts.Count == 0)
                return new Dictionary<string, bool>();

            var win = CreateInstance<ImageConflictResolverWindow>();
            win._conflicts = conflicts;
            win._overwrites = conflicts.ToDictionary(c => c.layerId, _ => false);
            win._newTexCache = new Dictionary<string, Texture2D>();
            win._existingTexCache = new Dictionary<string, Texture2D>();
            win._resultReady = false;
            win._result = null;
            win.titleContent = new GUIContent(
                $"对比 {conflicts.Count} 张图片");
            win.minSize = new Vector2(560, 380);

            // Center on main editor window.
            var main = EditorGUIUtility.GetMainWindowPosition();
            win.position = new Rect(
                Mathf.Round(main.x + (main.width  - 620) * 0.5f),
                Mathf.Round(main.y + (main.height - 520) * 0.5f),
                620, 520);

            // Modal — this call returns only after the window is closed.
            win.ShowModalUtility();

            // Return null on cancel so the caller can ABORT the import.
            // Previously this coalesced null to an empty dict, which made
            // the cancel button silently fall through to the copy step —
            // a very confusing "I clicked cancel but the import ran
            // anyway" bug. Empty dict is reserved for the
            // "Apply with all keeps" path.
            return win._result;
        }

        private void OnDisable()
        {
            // Free the preview textures so we don't leak memory.
            foreach (var t in _newTexCache.Values)      if (t != null) DestroyImmediate(t);
            foreach (var t in _existingTexCache.Values) if (t != null) DestroyImmediate(t);
            _newTexCache = null;
            _existingTexCache = null;
        }

        private void OnGUI()
        {
            // If the user already decided (Apply or Cancel), this window
            // is on its way to being closed. OnGUI will be invoked one
            // more time during the close cleanup pass — drawing UI on
            // that frame can leave the IMGUI layout stack half-open
            // (the "EndLayoutGroup: BeginLayoutGroup must be called
            // first" crash). Just bail out cleanly.
            if (_resultReady)
            {
                Close();
                return;
            }

            // ─── Header ────────────────────────────────────────────
            EditorGUILayout.LabelField(
                $"{_conflicts.Count} 张图片与项目现有版本内容不同。",
                EditorStyles.boldLabel);
            EditorGUILayout.LabelField(
                "左右对比后选择「保留旧图」或「用新图覆盖」，默认保留。点击「应用」提交，「取消导入」中止整个导入。",
                EditorStyles.wordWrappedMiniLabel);

            // ─── Bulk actions ──────────────────────────────────────
            using (new EditorGUILayout.HorizontalScope())
            {
                if (GUILayout.Button("✓ 全部保留旧图", GUILayout.Height(24)))
                {
                    foreach (var k in _overwrites.Keys.ToList()) _overwrites[k] = false;
                }
                if (GUILayout.Button("⚠ 全部用新图覆盖", GUILayout.Height(24)))
                {
                    foreach (var k in _overwrites.Keys.ToList()) _overwrites[k] = true;
                }
                GUILayout.FlexibleSpace();
                int keepCount      = _overwrites.Values.Count(v => !v);
                int overwriteCount = _overwrites.Values.Count(v =>  v);
                EditorGUILayout.LabelField(
                    $"将覆盖 {overwriteCount} 个，保留 {keepCount} 个",
                    EditorStyles.miniLabel,
                    GUILayout.Width(220));
            }

            EditorGUILayout.Space(4);

            // ─── Conflict rows ─────────────────────────────────────
            _scroll = EditorGUILayout.BeginScrollView(_scroll);
            foreach (var c in _conflicts)
            {
                DrawConflictRow(c);
                EditorGUILayout.Space(6);
            }
            EditorGUILayout.EndScrollView();

            EditorGUILayout.Space(4);

            // ─── Footer: Cancel / Apply ────────────────────────────
            //
            // The button just stores the result and sets _resultReady.
            // Do NOT call Close() here — that tears down the window
            // mid-OnGUI, which leaves the IMGUI layout stack in a bad
            // state and triggers the EndLayoutGroup crash.
            //
            // Instead, OnGUI's top-of-method guard at the start of this
            // file checks _resultReady on the NEXT OnGUI invocation
            // (which Unity always fires at least once after a button
            // click, before the modal ShowModalUtility() loop unwinds)
            // and calls Close() there. By that point the previous
            // OnGUI frame has fully unwound, so the IMGUI state is
            // clean and the close goes through without complaint.
            using (new EditorGUILayout.HorizontalScope())
            {
                if (GUILayout.Button("取消导入", GUILayout.Width(120), GUILayout.Height(30)))
                {
                    _result = null;
                    _resultReady = true;
                }
                GUILayout.FlexibleSpace();
                Color prevBg = GUI.backgroundColor;
                GUI.backgroundColor = new Color(0.6f, 0.85f, 0.6f);
                if (GUILayout.Button("应用", GUILayout.Width(120), GUILayout.Height(30)))
                {
                    _result = new Dictionary<string, bool>(_overwrites);
                    _resultReady = true;
                }
                GUI.backgroundColor = prevBg;
            }
        }

        private void DrawConflictRow(ImageConflict c)
        {
            using (new EditorGUILayout.VerticalScope(EditorStyles.helpBox))
            {
                // Layer identifier + size/hash summary
                EditorGUILayout.LabelField(
                    $"📐 {c.layerName}    ({c.psdName})",
                    EditorStyles.boldLabel);
                EditorGUILayout.LabelField(
                    $"id: {c.layerId}",
                    EditorStyles.miniLabel);
                EditorGUILayout.LabelField(
                    $"旧图: {FormatDims(c.existingWidth, c.existingHeight)}  " +
                    $"{FormatSize(c.existingSizeBytes)}  sha={c.existingHash}    ·    " +
                    $"新图: {FormatDims(c.newWidth, c.newHeight)}  " +
                    $"{FormatSize(c.newSizeBytes)}  sha={c.newHash}",
                    EditorStyles.miniLabel);

                // If the pixel dimensions differ, call it out — the user
                // asked for this because resizing a layer in PS doesn't
                // change the file hash if the cropped pixels happen to
                // look the same, but the new sprite will be a different
                // size and the prefab's sizeDelta will be re-written.
                if (c.existingWidth != c.newWidth || c.existingHeight != c.newHeight)
                {
                    EditorGUILayout.HelpBox(
                        $"⚠ 尺寸不同:旧 {c.existingWidth}×{c.existingHeight}  " +
                        $"→  新 {c.newWidth}×{c.newHeight}",
                        MessageType.Warning);
                }

                // Side-by-side previews. No tinted background — transparent
                // PNGs need to show against the editor's neutral background
                // so the user sees the real pixels (a colored fill would
                // tint every transparent pixel and mislead the comparison).
                using (new EditorGUILayout.HorizontalScope())
                {
                    DrawPreviewPane(
                        "项目现有",
                        c.layerId + "_existing",
                        c.existingImagePath,
                        _existingTexCache);
                    GUILayout.Space(8);
                    DrawPreviewPane(
                        "PSD 新图",
                        c.layerId + "_new",
                        c.newImagePath,
                        _newTexCache);
                }

                // Per-row keep/overwrite — a true single-select pair of
                // Toggles (the two are kept in sync so only one is on
                // at a time). Replacing the previous button-based UI
                // also fixed the EndLayoutGroup crash: the old
                // conditional backgroundColor + two tall GUILayout.
                // Buttons inside a HelpBox + HorizontalScope nesting
                // would occasionally leave the IMGUI layout stack
                // dirty when a button click mutated state mid-frame.
                EditorGUILayout.Space(2);
                using (new EditorGUILayout.HorizontalScope())
                {
                    GUILayout.FlexibleSpace();
                    bool currentOverwrite = _overwrites[c.layerId];
                    bool newKeep = EditorGUILayout.ToggleLeft(
                        "保留旧图", !currentOverwrite, GUILayout.Width(100));
                    bool newOverwrite = EditorGUILayout.ToggleLeft(
                        "用新图覆盖 ⚠", currentOverwrite, GUILayout.Width(140));
                    // Keep and Overwrite are mutually exclusive. If the
                    // user clicks one, force the other off.
                    if (newKeep && currentOverwrite)      _overwrites[c.layerId] = false;
                    else if (newOverwrite && !currentOverwrite) _overwrites[c.layerId] = true;
                }
            }
        }

        private static string FormatDims(int w, int h)
        {
            if (w <= 0 || h <= 0) return "尺寸未知";
            return $"{w}×{h}px";
        }

        private void DrawPreviewPane(
            string title, string cacheKey, string path,
            Dictionary<string, Texture2D> cache)
        {
            using (new EditorGUILayout.VerticalScope(GUILayout.Width(220)))
            {
                EditorGUILayout.LabelField(title, EditorStyles.miniBoldLabel);

                var tex = GetOrLoad(cacheKey, path, cache);
                // Reserve a fixed-size rect for the preview area. No
                // background fill — we want transparent PNGs to show
                // against the editor's neutral background so the user
                // can compare pixels fairly.
                var rect = GUILayoutUtility.GetRect(
                    200, 130, GUILayout.ExpandWidth(false), GUILayout.Height(130));

                if (tex != null)
                {
                    GUI.DrawTexture(rect, tex, ScaleMode.ScaleToFit, true);
                }
                else
                {
                    EditorGUI.DrawRect(rect, new Color(0.2f, 0.2f, 0.2f, 1f));
                    var centered = new GUIStyle(EditorStyles.miniLabel) { alignment = TextAnchor.MiddleCenter };
                    GUI.Label(rect, "(加载失败)", centered);
                }
            }
        }

        private static Texture2D GetOrLoad(
            string key, string path, Dictionary<string, Texture2D> cache)
        {
            if (cache.TryGetValue(key, out var t) && t != null) return t;
            if (string.IsNullOrEmpty(path) || !File.Exists(path)) return null;
            try
            {
                var bytes = File.ReadAllBytes(path);
                var tex = new Texture2D(2, 2, TextureFormat.RGBA32, mipChain: false);
                tex.hideFlags = HideFlags.HideAndDontSave;   // don't leak into assets
                tex.LoadImage(bytes);
                cache[key] = tex;
                return tex;
            }
            catch
            {
                return null;
            }
        }

        private static string FormatSize(int bytes)
        {
            if (bytes < 1024) return $"{bytes} B";
            if (bytes < 1024 * 1024) return $"{bytes / 1024.0f:F1} KB";
            return $"{bytes / 1024.0f / 1024.0f:F2} MB";
        }
    }
}
