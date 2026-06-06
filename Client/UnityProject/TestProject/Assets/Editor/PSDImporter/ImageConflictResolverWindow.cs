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

            return win._result ?? new Dictionary<string, bool>();
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
            using (new EditorGUILayout.HorizontalScope())
            {
                if (GUILayout.Button("取消导入", GUILayout.Width(120), GUILayout.Height(30)))
                {
                    _result = null;
                    _resultReady = true;
                    Close();
                    return;
                }
                GUILayout.FlexibleSpace();
                GUI.backgroundColor = new Color(0.6f, 0.85f, 0.6f);
                if (GUILayout.Button("应用", GUILayout.Width(120), GUILayout.Height(30)))
                {
                    _result = new Dictionary<string, bool>(_overwrites);
                    _resultReady = true;
                    Close();
                    return;
                }
                GUI.backgroundColor = Color.white;
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
                    $"旧图: {FormatSize(c.existingSizeBytes)}  sha={c.existingHash}    ·    " +
                    $"新图: {FormatSize(c.newSizeBytes)}  sha={c.newHash}",
                    EditorStyles.miniLabel);

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

                // Per-row keep/overwrite toggle (default: keep).
                bool current = _overwrites[c.layerId];
                using (new EditorGUILayout.HorizontalScope())
                {
                    GUILayout.FlexibleSpace();
                    GUI.backgroundColor = current ? Color.white : new Color(0.6f, 0.85f, 0.6f);
                    if (GUILayout.Button(
                        current ? "  ✓  保留旧图" : "  保留旧图",
                        GUILayout.Width(160), GUILayout.Height(26)))
                    {
                        if (current) _overwrites[c.layerId] = false;
                    }
                    GUI.backgroundColor = !current ? Color.white : new Color(0.95f, 0.65f, 0.55f);
                    if (GUILayout.Button(
                        !current ? "  用新图覆盖  ⚠" : "  用新图覆盖",
                        GUILayout.Width(160), GUILayout.Height(26)))
                    {
                        if (!current) _overwrites[c.layerId] = true;
                    }
                    GUI.backgroundColor = Color.white;
                }
            }
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
