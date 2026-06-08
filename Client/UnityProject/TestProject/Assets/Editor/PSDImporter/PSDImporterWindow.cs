// PSDImporterWindow.cs
// Editor window for one-click PSD → UGUI import.
//
// This window is intentionally minimal. It shows:
//   1. The active Settings asset reference
//   2. Two key paths: where prefabs go, where images go
//   3. The one-click import action + a quick Python diagnostic
//   4. The list of PSDs already in the export folder, with per-row
//      Import buttons and a bulk "Import All changed"
//
// Everything else (Python config, font config, UILayer, UIBind
// generation toggle, sprite importer, cache file name, etc.) lives on
// the PSDImporterSettings asset itself and is edited in its custom
// Inspector. Keeping the window minimal means the user has one place
// to look for config (the Settings asset) and one place to act (this
// window).
//
// Menu: Tools > PSD Importer

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEditorInternal;
using UnityEngine;

namespace PSDImporter.Editor
{
    public class PSDImporterWindow : EditorWindow
    {
        private const string MenuPath = "Tools/PSD Importer/Open Window";

        // ─── state ─────────────────────────────────────────────────

        private PSDImporterSettings _settings;
        private SerializedObject     _settingsSO;   // null until a settings asset is assigned
        private SerializedProperty   _prefabOutputRootProp;
        private SerializedProperty   _imageOutputRootProp;
        private SerializedProperty   _prefabNameOverrideProp;

        private List<JsonEntry> _entries = new List<JsonEntry>();
        private string _lastReport = "";
        private Vector2 _scroll;

        // PSD files the user has dragged into the window (or picked via
        // the file dialog). Drives the "选中 PSD 并转换 + 导入" button.
        // Absolute paths (not Assets/-relative) because psd_to_json.py
        // reads them off disk. Empty list ⇒ button is disabled.
        private List<string> _droppedPsdPaths = new List<string>();

        // debounce for auto-scan
        private double _nextRefresh;
        private bool   _needsImmediateScan;

        // Lazy-initialized style for the entry-list path.
        private static GUIStyle s_pathStyle;
        private static GUIStyle PathStyle =>
            s_pathStyle ?? (s_pathStyle = new GUIStyle(EditorStyles.miniLabel));

        /// <summary>
        /// Middle-elide `text` so it fits within `maxWidth` pixels
        /// when rendered with `style`. Returns the original text if
        /// it already fits. Used for long PSD file paths in the
        /// entry list — we want a single-line path (row stays a
        /// fixed height) but still preserve the most informative
        /// parts (drive + filename).
        ///
        /// Result format: "D:\long\path\…\filename.json"
        /// </summary>
        private static string ElideMiddle(string text, GUIStyle style, float maxWidth)
        {
            if (string.IsNullOrEmpty(text) || maxWidth <= 0) return text;
            if (style.CalcSize(new GUIContent(text)).x <= maxWidth) return text;

            const string ellipsis = "…";
            int totalLen = text.Length;
            string best = ellipsis;   // worst case: just the ellipsis

            // Binary search for the max number of chars we can keep
            // on EACH side (start and end) while still fitting.
            int lo = 0, hi = totalLen / 2;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                string candidate =
                    text.Substring(0, mid) + ellipsis + text.Substring(totalLen - mid);
                if (style.CalcSize(new GUIContent(candidate)).x <= maxWidth)
                {
                    best = candidate;
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            return best;
        }

        private class JsonEntry
        {
            public string jsonPath;
            public string psdName;
            public string status;        // 'new' | 'changed' | 'unchanged'
            public DateTime lastImport;
        }

        // ─── menu ──────────────────────────────────────────────────

        [MenuItem(MenuPath)]
        public static void Open()
        {
            var w = GetWindow<PSDImporterWindow>("PSD Importer");
            w.minSize = new Vector2(520, 360);
            w.Show();
        }

        // ─── lifecycle ─────────────────────────────────────────────

        private void OnEnable()
        {
            _settings = LoadOrCreateSettings();
            BindSerializedProperties();
            EditorApplication.update += OnEditorUpdate;
            Scan();
        }

        private void OnDisable()
        {
            EditorApplication.update -= OnEditorUpdate;
        }

        private void OnEditorUpdate()
        {
            if (EditorApplication.timeSinceStartup < _nextRefresh) return;
            _nextRefresh = EditorApplication.timeSinceStartup + 2.0;
            if (_needsImmediateScan)
            {
                _needsImmediateScan = false;
                Scan();
                Repaint();
            }
        }

        // ─── GUI ───────────────────────────────────────────────────

        private void OnGUI()
        {
            DrawHeader();
            EditorGUILayout.Space(4);
            DrawSettingsSection();
            EditorGUILayout.Space(4);
            DrawReport();
            EditorGUILayout.Space(4);
            DrawActions();
            EditorGUILayout.Space(4);
            DrawEntryList();
            EditorGUILayout.Space(4);
            DrawFooter();
        }

        private void DrawHeader()
        {
            using (new EditorGUILayout.HorizontalScope(EditorStyles.toolbar))
            {
                GUILayout.Label("PSD 导入器", EditorStyles.boldLabel);
                GUILayout.FlexibleSpace();
                if (GUILayout.Button("刷新", EditorStyles.toolbarButton, GUILayout.Width(60)))
                    Scan();
                if (GUILayout.Button("帮助", EditorStyles.toolbarButton, GUILayout.Width(60)))
                    DrawHelp();
            }
        }

        // The whole point of this window, per the latest refactor:
        // the Settings asset reference, and the two output paths the
        // user cares about most (prefab + images). Everything else is
        // on the Settings asset's Inspector.
        private void DrawSettingsSection()
        {
            using (new EditorGUILayout.VerticalScope(EditorStyles.helpBox))
            {
                EditorGUILayout.LabelField("设置", EditorStyles.boldLabel);

                var newSettings = (PSDImporterSettings)EditorGUILayout.ObjectField(
                    "设置资产", _settings, typeof(PSDImporterSettings), false);
                if (newSettings != _settings)
                {
                    _settings = newSettings;
                    BindSerializedProperties();
                    _needsImmediateScan = true;
                }

                if (_settings == null)
                {
                    EditorGUILayout.HelpBox(
                        "⚠ 没有设置资产。在 Project 窗口里创建一个:\n" +
                        "  右键 → Create → PSD Importer → Settings。\n" +
                        "然后拖到上面的字段里。",
                        MessageType.None);
                    if (GUILayout.Button("创建默认设置资产"))
                    {
                        _settings = CreateDefaultSettings();
                        BindSerializedProperties();
                        _needsImmediateScan = true;
                    }
                    return;
                }

                // Two key paths — edited directly on the asset via
                // SerializedObject so changes persist without extra code.
                if (_settingsSO == null) BindSerializedProperties();
                if (_settingsSO != null && _settingsSO.targetObject != null)
                {
                    _settingsSO.Update();
                    if (_prefabOutputRootProp != null)
                        DrawAssetsFolderField(_prefabOutputRootProp, "Prefab 输出 (Assets/)");
                    if (_imageOutputRootProp != null)
                        DrawAssetsFolderField(_imageOutputRootProp, "图片输出根 (Assets/)");
                    // Prefab name override. Empty = use the PSD file's
                    // name as-is. Set to a custom value (e.g.
                    // "LoginView") to drive the prefab filename, the
                    // subfolder under prefabOutputRoot, the root
                    // GameObject name, the generated NodeProvider +
                    // Window class names, and the UIBindData asset
                    // name — all five in lockstep. Useful when one
                    // PSD holds several alternative UIs (toggle the
                    // others' group visibility off) and you want a
                    // friendly English name for the generated code.
                    if (_prefabNameOverrideProp != null)
                    {
                        EditorGUILayout.PropertyField(_prefabNameOverrideProp,
                            new GUIContent("Prefab 名称覆盖"));
                        EditorGUILayout.LabelField(
                            "  (空 = 用 PSD 文件名;非空会同时驱动预制体文件名、子目录、" +
                            "类名、UIBindData 资产名,五个保持一致)",
                            EditorStyles.miniLabel);
                    }
                    EditorGUILayout.LabelField(
                        "  (每个 PSD → <imageOutputRoot>/<PsdName>/<layerName>.png)",
                        EditorStyles.miniLabel);
                    if (_settingsSO.ApplyModifiedProperties())
                    {
                        _needsImmediateScan = true;
                    }
                }
            }
        }

        private void DrawReport()
        {
            if (string.IsNullOrEmpty(_lastReport)) return;
            // No MessageType arg → no icon. Some Unity 2022 themes
            // render every HelpBox with a red "!" regardless of type.
            EditorGUILayout.HelpBox(_lastReport, MessageType.None);
        }

        private void DrawActions()
        {
            using (new EditorGUILayout.VerticalScope(EditorStyles.helpBox))
            {
                EditorGUILayout.LabelField("从 PSD 一键导入", EditorStyles.boldLabel);

                // Visual list of staged files (ReorderableList — drag to
                // reorder, +/- buttons to add/remove, full file path
                // visible on hover). Plus a "添加…" button + drop zone
                // The list's footer "+" / "-" buttons (drawn by
                // ReorderableList) plus the toolbar "+" / "🗑" in
                // DrawPsdListHeader give the user all the add/remove
                // affordances they need. The import button at the
                // bottom runs Python + build for everything in the list.
                DrawPsdStagingList();
                EditorGUILayout.Space(4);
                DrawPsdImportButton();
            }

            using (new EditorGUILayout.HorizontalScope())
            {
                if (GUILayout.Button("🐍 测试 Python", GUILayout.Height(24)))
                    TestPython();
            }
        }

        // Cached ReorderableList for the staged-PSDs table. Built lazily
        // on first draw so we don't fight the window's enable/disable
        // lifecycle.
        private ReorderableList _psdList;
        private ReorderableList PsdList
        {
            get
            {
                if (_psdList == null)
                {
                    _psdList = new ReorderableList(
                        _droppedPsdPaths, typeof(string),
                        draggable: true,
                        // Hide Unity's default header so the empty-state
                        // doesn't render the English "List is Empty"
                        // placeholder. We draw our own Chinese header
                        // (with the same "+" / "-" affordances in the
                        // footer) right before DoLayoutList in
                        // DrawPsdStagingList.
                        displayHeader: false,
                        displayAddButton: true,     // built-in "+" button (footer left of "-")
                        displayRemoveButton: true); // built-in "-" button (footer right of "+")
                    _psdList.onAddDropdownCallback = (Rect buttonRect, ReorderableList list) =>
                    {
                        // The built-in "+" button's default behaviour just
                        // appends a default(string) entry — useless for
                        // us. Replace it with the OS file picker so the
                        // footer "+" is a real "add PSD" action.
                        var picked = EditorUtility.OpenFilePanel("选择 PSD 文件", "", "psd");
                        if (!string.IsNullOrEmpty(picked)) AddPsdPaths(new[] { picked }, null);
                    };
                    _psdList.drawElementCallback = (rect, index, active, focused) =>
                    {
                        if (index < 0 || index >= _droppedPsdPaths.Count) return;
                        var path = _droppedPsdPaths[index];
                        var name = Path.GetFileName(path);
                        // First column: filename (bold), truncated with
                        // middle ellipsis if it doesn't fit.
                        var nameRect = new Rect(rect.x, rect.y + 2, rect.width * 0.55f - 4,
                                                rect.height - 4);
                        GUI.Label(nameRect, new GUIContent(name,
                            path), EditorStyles.boldLabel);
                        // Second column: directory (greyed, tooltip = full path).
                        var dirRect = new Rect(nameRect.xMax + 8, rect.y + 2,
                                               rect.width * 0.45f - 8, rect.height - 4);
                        var dir = Path.GetDirectoryName(path) ?? "";
                        GUI.Label(dirRect, new GUIContent(dir, path),
                            EditorStyles.miniLabel);
                    };
                    _psdList.onChangedCallback = list =>
                    {
                        // ReorderableList already mutates the underlying
                        // list when the user drags a row. Nothing to do,
                        // but we keep the hook so future logic (e.g. a
                        // "remember order" cache) has a place to land.
                    };
                }
                return _psdList;
            }
        }

        private void DrawPsdStagingList()
        {
            // Empty state: a tall drop zone so dragging .psd files onto
            // the window still works. Non-empty state: a single thin
            // "drag here to add" strip below the list (drawn in
            // DrawPsdStagingDrop).
            if (_droppedPsdPaths.Count == 0) DrawEmptyDropZone();

            // Always render the ReorderableList so the footer "+"/"-" buttons
            // are visible — even when the list is empty, the user can hit
            // "+" to open the file picker. We hide ReorderableList's
            // default English header (see PsdList ctor) and draw our own
            // Chinese label here, with the same row of "添加…/清空" buttons
            // on the right for symmetry.
            DrawPsdListHeader();
            PsdList.DoLayoutList();
            DrawPsdStagingDrop();
        }

        // Custom header for the PSD staging list. Drawn right before
        // ReorderableList.DoLayoutList() and acts as the "title" of the
        // table. Right-aligned action buttons (添加 / 清空) keep the
        // visual link to the list, even though the real "+" / "-" lives
        // in the ReorderableList footer.
        private void DrawPsdListHeader()
        {
            using (new EditorGUILayout.HorizontalScope(EditorStyles.toolbar))
            {
                GUILayout.Label(
                    _droppedPsdPaths.Count == 0
                        ? "待导入的 PSD 文件(空)"
                        : $"待导入的 PSD 文件 ({_droppedPsdPaths.Count})",
                    EditorStyles.boldLabel);
                GUILayout.FlexibleSpace();
                GUI.enabled = true;
            }
        }

        // Full-row drop area that lives underneath the ReorderableList.
        // Lets the user add more files without having to click "添加".
        // We rely on a Rect we get from the last visible row of the
        // ReorderableList — if the list is empty this isn't called.
        private void DrawPsdStagingDrop()
        {
            // Reserve a thin strip below the list for "drag here to add".
            var rect = GUILayoutUtility.GetRect(0, 18, GUILayout.ExpandWidth(true));
            var isHovering = rect.Contains(Event.current.mousePosition)
                             && DragAndDrop.paths != null
                             && DragAndDrop.paths.Length > 0;
            var prevColor = GUI.color;
            if (isHovering) GUI.color = new Color(0.6f, 0.85f, 1f, 0.4f);
            GUI.Box(rect, "  ⬇  拖入 .psd 文件到此处可继续添加", EditorStyles.helpBox);
            GUI.color = prevColor;

            switch (Event.current.type)
            {
                case EventType.DragUpdated:
                    if (rect.Contains(Event.current.mousePosition))
                    {
                        DragAndDrop.visualMode = HasAnyPsd(DragAndDrop.paths, DragAndDrop.objectReferences)
                            ? DragAndDropVisualMode.Copy
                            : DragAndDropVisualMode.Rejected;
                        Event.current.Use();
                    }
                    break;
                case EventType.DragPerform:
                    if (rect.Contains(Event.current.mousePosition))
                    {
                        DragAndDrop.AcceptDrag();
                        AddPsdPaths(DragAndDrop.paths, DragAndDrop.objectReferences);
                        Event.current.Use();
                    }
                    break;
            }
        }

        private void DrawEmptyDropZone()
        {
            var rect = GUILayoutUtility.GetRect(0, 70, GUILayout.ExpandWidth(true));
            var isHovering = rect.Contains(Event.current.mousePosition)
                             && DragAndDrop.paths != null
                             && DragAndDrop.paths.Length > 0;
            var prevColor = GUI.color;
            if (isHovering) GUI.color = new Color(0.6f, 0.85f, 1f, 0.4f);
            GUI.Box(rect,
                "📂  把 .psd 文件拖到这里或点下方“+”选文件",
                EditorStyles.helpBox);
            GUI.color = prevColor;

            switch (Event.current.type)
            {
                case EventType.DragUpdated:
                    if (rect.Contains(Event.current.mousePosition))
                    {
                        DragAndDrop.visualMode = HasAnyPsd(DragAndDrop.paths, DragAndDrop.objectReferences)
                            ? DragAndDropVisualMode.Copy
                            : DragAndDropVisualMode.Rejected;
                        Event.current.Use();
                    }
                    break;
                case EventType.DragPerform:
                    if (rect.Contains(Event.current.mousePosition))
                    {
                        DragAndDrop.AcceptDrag();
                        AddPsdPaths(DragAndDrop.paths, DragAndDrop.objectReferences);
                        Event.current.Use();
                    }
                    break;
            }
        }

        private void DrawPsdImportButton()
        {
            var ready = _settings != null && _droppedPsdPaths.Count > 0;
            using (new EditorGUILayout.HorizontalScope())
            {
                GUI.enabled = ready;
                var label = _droppedPsdPaths.Count == 1
                    ? "✅  转换 + 导入选中的 PSD"
                    : $"✅  转换 + 导入 {_droppedPsdPaths.Count} 个 PSD";
                if (GUILayout.Button(label, GUILayout.Height(32)))
                {
                    ImportDroppedPsds();
                }
                GUI.enabled = true;
            }
        }

        // Filter the dropped paths down to ones that look like PSD
        // files. Returns true if at least one is kept — used to set
        // DragAndDrop.visualMode.
        private static bool HasAnyPsd(string[] paths, UnityEngine.Object[] objects)
        {
            if (objects != null)
            {
                foreach (var o in objects)
                {
                    var p = AssetDatabase.GetAssetPath(o);
                    if (p.EndsWith(".psd", System.StringComparison.OrdinalIgnoreCase))
                        return true;
                }
            }
            if (paths != null)
            {
                foreach (var p in paths)
                {
                    if (p.EndsWith(".psd", System.StringComparison.OrdinalIgnoreCase))
                        return true;
                }
            }
            return false;
        }

        // Merge new PSD paths into the list, deduped, keeping existing
        // order. We accept both raw OS paths (from Finder) and Unity
        // project asset references (drag from Project window).
        private void AddPsdPaths(string[] paths, UnityEngine.Object[] objects)
        {
            var added = 0;
            if (objects != null)
            {
                foreach (var o in objects)
                {
                    var ap = AssetDatabase.GetAssetPath(o);
                    if (string.IsNullOrEmpty(ap)) continue;
                    if (!ap.EndsWith(".psd", System.StringComparison.OrdinalIgnoreCase)) continue;
                    var abs = Path.GetFullPath(ap).Replace('\\', '/');
                    if (_droppedPsdPaths.Contains(abs)) continue;
                    _droppedPsdPaths.Add(abs);
                    added++;
                }
            }
            if (paths != null)
            {
                foreach (var p in paths)
                {
                    if (string.IsNullOrEmpty(p)) continue;
                    if (!p.EndsWith(".psd", System.StringComparison.OrdinalIgnoreCase)) continue;
                    if (Directory.Exists(p))
                    {
                        // User dropped a folder — pick up every PSD inside.
                        foreach (var f in Directory.GetFiles(p, "*.psd",
                                     SearchOption.TopDirectoryOnly))
                        {
                            var abs = Path.GetFullPath(f).Replace('\\', '/');
                            if (_droppedPsdPaths.Contains(abs)) continue;
                            _droppedPsdPaths.Add(abs);
                            added++;
                        }
                    }
                    else if (File.Exists(p))
                    {
                        var abs = Path.GetFullPath(p).Replace('\\', '/');
                        if (_droppedPsdPaths.Contains(abs)) continue;
                        _droppedPsdPaths.Add(abs);
                        added++;
                    }
                }
            }
            if (added > 0)
            {
                Debug.Log($"[PSDImporter] Added {added} PSD path(s) to drop list (now {_droppedPsdPaths.Count} total).");
                // Adding files means the staging list is now non-empty.
                // Whatever stale "no files found" message might have been
                // sitting in _lastReport is no longer relevant — clear
                // it so it doesn't get rendered above the new list.
                if (_droppedPsdPaths.Count > 0) _lastReport = "";
            }
        }

        // Run the same per-file flow as the old "📁" button, but iterate
        // over every staged path instead of prompting for a single one.
        private void ImportDroppedPsds()
        {
            if (_droppedPsdPaths.Count == 0) return;
            if (_settings == null)
            {
                _lastReport = "没有设置资产。拖一个到上面的「设置资产」字段里。";
                return;
            }
            var scriptPath = _settings.GetPythonScriptPath();
            if (scriptPath == null)
            {
                _lastReport = "psd_to_json.py 没找到。\n" +
                              "在 Settings 资产的 Inspector 里设「psd_to_json.py 路径」," +
                              "或放到 <ProjectRoot>/Tools/PSDExporter/psd_to_json.py。";
                return;
            }

            int success = 0, failed = 0;
            var failedNames = new List<string>();
            // Snapshot — the user could conceivably drag more in
            // mid-import and we don't want to pick those up here.
            var snapshot = _droppedPsdPaths.ToList();
            foreach (var psdPath in snapshot)
            {
                if (!File.Exists(psdPath))
                {
                    failed++;
                    failedNames.Add($"{Path.GetFileName(psdPath)} (文件不存在)");
                    continue;
                }
                _lastReport = $"🔄  正在处理 {Path.GetFileName(psdPath)} ({success + failed + 1}/{snapshot.Count})…";
                Repaint();
                try
                {
                    var ok = RunOnePsd(psdPath);
                    if (ok) success++;
                    else
                    {
                        failed++;
                        failedNames.Add(Path.GetFileName(psdPath));
                    }
                }
                catch (Exception ex)
                {
                    failed++;
                    failedNames.Add($"{Path.GetFileName(psdPath)} ({ex.GetType().Name})");
                    Debug.LogException(ex);
                }
            }

            _lastReport = failed == 0
                ? $"✅  全部 {success} 个 PSD 处理完成。"
                : $"⚠ 完成 {success},失败 {failed}。\n失败的文件:\n  - " +
                  string.Join("\n  - ", failedNames);

            _droppedPsdPaths.Clear();

            EditorApplication.delayCall += () =>
            {
                _needsImmediateScan = true;
                Repaint();
            };
        }

        // Runs Python + PSDImporter.Import for one PSD file. Returns
        // true on full success, false on any failure (Python non-zero
        // exit, missing JSON, or Import threw).
        private bool RunOnePsd(string psdPath)
        {
            var exportRoot = _settings.GetPsdExportRootAbsolute();
            var args = new[] { psdPath, "--out", exportRoot };
            var psdName = Path.GetFileNameWithoutExtension(psdPath);

            PythonRunner.RunResult result;
            try
            {
                EditorUtility.DisplayProgressBar(
                    "PSD Importer",
                    $"Converting {psdName}.psd via Python…",
                    0.3f);
                result = PythonRunner.Run(_settings.pythonExecutable, scriptPath: _settings.GetPythonScriptPath(), args);
            }
            finally
            {
                EditorUtility.ClearProgressBar();
            }

            if (!result.ok)
            {
                _lastReport = $"❌  Python failed for {psdName} " +
                              $"(exit={result.exitCode}):\n{result.stderr}";
                Debug.LogError($"[PSDImporter] {result.stderr}");
                return false;
            }

            var jsonPath = Path.Combine(exportRoot, psdName, psdName + ".json");
            if (!File.Exists(jsonPath))
            {
                _lastReport = $"❌  Python succeeded for {psdName} " +
                              $"but JSON not found:\n{jsonPath}";
                return false;
            }

            try
            {
                var report = PSDImporter.Import(
                    jsonPath, _settings, _settings.autoGenerateUIBind);
                // Stash the report on the global _lastReport only for the
                // last one — partial results get logged but don't
                // clobber the running "next file" message.
                Debug.Log($"[PSDImporter] {psdName} done: " +
                          $"+{report.addedCount} -{report.removedCount} " +
                          $"~{report.contentChangedCount} (prefab={report.prefabPath})");
                return true;
            }
            catch (Exception ex)
            {
                _lastReport = $"❌  Import threw for {psdName}:\n{ex.Message}";
                Debug.LogException(ex);
                return false;
            }
        }

        private void DrawEntryList()
        {
            if (_settings == null) return;   // can't list without export root
            var exportRoot = _settings.GetPsdExportRootAbsolute();
            EditorGUILayout.LabelField(
                $"在 '{_settings.psdExportRoot}' 里找到 {_entries.Count} 个 PSD",
                EditorStyles.boldLabel);
            _scroll = EditorGUILayout.BeginScrollView(_scroll, GUILayout.MinHeight(160));
            if (_entries.Count == 0)
            {
                EditorGUILayout.HelpBox(
                    $"ℹ 在 {exportRoot} 下没找到 <名称>.json 文件。\n" +
                    "点上面的 📁 让插件帮你跑 Python,或者手动跑:\n" +
                    "  python psd_to_json.py 路径/到/MyUI.psd --out " + _settings.psdExportRoot,
                    MessageType.None);
            }
            else
            {
                foreach (var e in _entries)
                {
                    using (new EditorGUILayout.HorizontalScope(EditorStyles.helpBox))
                    {
                        var badge = e.status == "unchanged" ? "●"
                                  : e.status == "changed"   ? "◐"
                                  : "○";
                        GUILayout.Label(badge, GUILayout.Width(18));
                        // Name and path on the SAME line. The path
                        // middle-elides to fit whatever space is
                        // left after the name + Import button.
                        EditorGUILayout.LabelField(e.psdName, EditorStyles.boldLabel);
                        GUILayout.Space(8);
                        var pathRect = GUILayoutUtility.GetRect(
                            0, 16, GUILayout.ExpandWidth(true), GUILayout.Height(16));
                        var elided = ElideMiddle(e.jsonPath, PathStyle, pathRect.width);
                        GUI.Label(pathRect, new GUIContent(elided, e.jsonPath), PathStyle);
                        if (GUILayout.Button("导入", GUILayout.Width(72)))
                            ImportOne(e);
                    }
                }
            }
            EditorGUILayout.EndScrollView();
        }

        private void DrawFooter()
        {
            using (new EditorGUILayout.HorizontalScope())
            {
                GUI.enabled = _settings != null;
                if (GUILayout.Button("全部导入(仅变更)"))
                    ImportChanged();
                GUILayout.FlexibleSpace();
                if (GUILayout.Button("打开导出目录", GUILayout.Width(160)))
                {
                    if (_settings == null) return;
                    var abs = _settings.GetPsdExportRootAbsolute();
                    Directory.CreateDirectory(abs);
                    EditorUtility.RevealInFinder(abs);
                }
                GUI.enabled = true;
            }
        }

        // ─── help dialog ──────────────────────────────────────────

        private void DrawHelp()
        {
            EditorUtility.DisplayDialog(
                "PSD Importer — Quick help",
                "Window has 3 things: Settings asset + 2 paths.\n" +
                "Everything else is on the Settings asset's Inspector.\n\n" +
                "Two ways to import:\n\n" +
                "1. ONE-CLICK (recommended)\n" +
                "   Click '选中 PSD 并转换 + 导入', pick a .psd.\n" +
                "   We run Python under the hood, then build the UGUI prefab.\n\n" +
                "2. MANUAL\n" +
                "   From terminal: python psd_to_json.py MyUI.psd --out PSDExport\n" +
                "   Then click 'Import' on the row in the list below.\n\n" +
                "Re-running either path updates only changed layers (incremental).\n\n" +
                "If the new image conflicts with an existing one, a preview\n" +
                "window appears so you can compare before deciding.\n\n" +
                "Prefab name override:\n" +
                "  Empty (default) → prefab named after the PSD file.\n" +
                "  Set a value (e.g. 'LoginView') → that name drives\n" +
                "  the prefab file, its subfolder, the root GameObject,\n" +
                "  the generated NodeProvider + Window classes, and the\n" +
                "  UIBindData asset. Useful when one PSD holds multiple\n" +
                "  alternative UIs (toggle the others' group visibility off).\n" +
                "  Changing the override does NOT auto-migrate a previous\n" +
                "  import — the old prefab stays where it was. Move it\n" +
                "  manually or re-import the PSD fresh.\n\n" +
                "Layer prefixes (full list in Tools/PSDExporter/PREFIXES.md):\n" +
                "  btn_/txt_/img_/icon_/bg_/panel_/progress_/mask_/item_/fx_\n" +
                "  input_/scroll_/toggle_/slider_  (v1 partial — image only)\n" +
                "  group_/anim_/root_  (container, no UGUI component)",
                "OK");
        }

        // ─── scanning ──────────────────────────────────────────────

        private void Scan()
        {
            _entries.Clear();
            if (_settings == null) return;
            var root = _settings.GetPsdExportRootAbsolute();
            if (!Directory.Exists(root)) return;

            foreach (var dir in Directory.GetDirectories(root))
            {
                foreach (var json in Directory.GetFiles(dir, "*.json"))
                {
                    if (Path.GetFileName(json).StartsWith("_")) continue;
                    var e = new JsonEntry
                    {
                        jsonPath = json,
                        psdName  = Path.GetFileNameWithoutExtension(json),
                    };
                    var cachePath = Path.Combine(dir, "_psd_cache.json");
                    if (File.Exists(cachePath))
                    {
                        try
                        {
                            var cache = JsonUtility.FromJson<PsdCache>(File.ReadAllText(cachePath));
                            if (cache != null && !string.IsNullOrEmpty(cache.sourcePsdHash))
                            {
                                e.lastImport = DateTime.TryParse(cache.lastImportedAt, out var dt)
                                    ? dt : default;
                            }
                        }
                        catch { /* ignore */ }
                    }
                    e.status = File.Exists(cachePath) ? "changed" : "new";
                    _entries.Add(e);
                }
            }

            foreach (var e in _entries)
            {
                try
                {
                    var doc = JsonUtility.FromJson<PsdDocument>(File.ReadAllText(e.jsonPath));
                    var cachePath = Path.Combine(Path.GetDirectoryName(e.jsonPath) ?? "", "_psd_cache.json");
                    if (doc != null && File.Exists(cachePath))
                    {
                        var cache = JsonUtility.FromJson<PsdCache>(File.ReadAllText(cachePath));
                        if (cache != null && cache.sourcePsdHash == doc.sourcePsd.hash)
                            e.status = "unchanged";
                    }
                }
                catch { /* ignore */ }
            }
        }

        // ─── import actions ────────────────────────────────────────

        private void ImportOne(JsonEntry e)
        {
            try
            {
                if (_settings == null) return;
                var report = PSDImporter.Import(
                    e.jsonPath, _settings, _settings.autoGenerateUIBind);
                _lastReport = FormatReport(e.psdName, report);
            }
            catch (Exception ex)
            {
                _lastReport = $"❌  Failed: {ex.Message}";
                Debug.LogException(ex);
            }
            // Defer Scan+Repaint to next editor frame. Doing it synchronously
            // would mutate _entries while DrawEntryList is still iterating
            // over it (we're inside a button click handler in OnGUI),
            // causing "Collection was modified" + GUILayout state errors.
            EditorApplication.delayCall += () =>
            {
                _needsImmediateScan = true;
                Repaint();
            };
        }

        private void ImportChanged()
        {
            int imported = 0, skipped = 0;
            foreach (var e in _entries.Where(e => e.status != "unchanged").ToList())
            {
                try
                {
                    if (_settings == null) return;
                    var r = PSDImporter.Import(
                        e.jsonPath, _settings, _settings.autoGenerateUIBind);
                    if (r.skipped) skipped++;
                    else imported++;
                }
                catch (Exception ex)
                {
                    Debug.LogException(ex);
                }
            }
            _lastReport = $"Imported {imported}, skipped {skipped}.";
            EditorApplication.delayCall += () =>
            {
                _needsImmediateScan = true;
                Repaint();
            };
        }

        private void TestPython()
        {
            if (_settings == null)
            {
                _lastReport = "⚠ No settings asset. Drag one into the Settings field above first.";
                return;
            }
            var py = _settings.pythonExecutable;
            var script = _settings.GetPythonScriptPath();
            _lastReport = $"Running `{py} --version`…";
            Repaint();
            Debug.Log($"[PSDImporter] Testing python: {py}");

            var result = PythonRunner.Run(py, "", new[] { "--version" });
            if (result.ok)
            {
                _lastReport = $"✅  Python OK ({result.duration.TotalSeconds:F1}s)\n" +
                              $"  exe: {py}\n" +
                              $"  script: {script ?? "<not set>"}\n" +
                              $"  stdout: {result.stdout.Trim()}";
            }
            else
            {
                _lastReport = $"❌  Python unreachable:\n{result.stderr}\n\n" +
                              $"Tried exe: `{py}`\n" +
                              "Fix in the Settings asset's Inspector → 'Python executable'. " +
                              "Use the full path like\n" +
                              "  C:\\Users\\<you>\\AppData\\Local\\Programs\\Python\\Python313\\python.exe";
            }
            Debug.Log($"[PSDImporter] Test result: exit={result.exitCode}, stdout={result.stdout}, stderr={result.stderr}");
            Repaint();
        }

        // ─── report formatting ─────────────────────────────────────

        private string FormatReport(string psdName, PSDImporter.ImportReport report)
        {
            if (report.skipped)
                return $"'{psdName}' unchanged — no rebuild.";
            var s = $"Imported '{psdName}' → {report.prefabPath}\n" +
                    $"  +{report.addedCount}  -{report.removedCount}  ~{report.contentChangedCount}\n" +
                    $"  images: copied={report.imagesCopied} overwritten={report.imagesOverwritten} " +
                    $"skipped(same)={report.imagesSkippedSameContent} skipped(user)={report.imagesSkippedByUser}\n" +
                    $"  source cleaned up: {report.sourceImagesCleanedUp} PNG(s) in PSDExport";
            if (report.warnings.Count > 0)
                s += "\nWarnings:\n  - " + string.Join("\n  - ", report.warnings);
            return s;
        }

        // ─── SerializedObject plumbing ─────────────────────────────

        private void BindSerializedProperties()
        {
            if (_settings == null)
            {
                _settingsSO = null;
                _prefabOutputRootProp = null;
                _imageOutputRootProp = null;
                _prefabNameOverrideProp = null;
                return;
            }
            _settingsSO = new SerializedObject(_settings);
            _prefabOutputRootProp = _settingsSO.FindProperty("prefabOutputRoot");
            _imageOutputRootProp = _settingsSO.FindProperty("imageOutputRoot");
            _prefabNameOverrideProp = _settingsSO.FindProperty("prefabNameOverride");
        }

        // A path field with a "📁…" browse button. Always constrained to
        // Assets/ (project-relative). Mirrors the same control on the
        // Settings asset's Inspector so the two UIs feel consistent.
        private static void DrawAssetsFolderField(SerializedProperty prop, string label)
        {
            using (new EditorGUILayout.HorizontalScope())
            {
                EditorGUILayout.PropertyField(prop, new GUIContent(label));
                if (GUILayout.Button("📁…", GUILayout.Width(36)))
                {
                    var current = ResolveAssetsRelative(prop.stringValue);
                    var picked = EditorUtility.OpenFolderPanel("选择 " + label, current, "");
                    if (!string.IsNullOrEmpty(picked))
                    {
                        prop.stringValue = MakeProjectRelative(picked);
                    }
                }
            }
        }

        // Resolve a (possibly Assets/-relative) path to an absolute path
        // rooted under the project. Used as the initial directory of the
        // OpenFolderPanel dialog so the user lands somewhere sensible.
        private static string ResolveAssetsRelative(string value)
        {
            if (string.IsNullOrEmpty(value)) return Application.dataPath;
            if (Path.IsPathRooted(value)) return value;
            var projectRoot = Path.GetDirectoryName(Application.dataPath) ?? "";
            return Path.GetFullPath(Path.Combine(projectRoot, value));
        }

        // Convert an absolute path picked by the dialog back to the
        // Assets/-relative form the field stores (so it survives
        // project moves / re-clones cleanly).
        private static string MakeProjectRelative(string absolute)
        {
            var projectRoot = Path.GetDirectoryName(Application.dataPath) ?? "";
            var norm = absolute.Replace('\\', '/').TrimEnd('/');
            var pr = projectRoot.Replace('\\', '/').TrimEnd('/');
            if (norm.StartsWith(pr + "/", System.StringComparison.OrdinalIgnoreCase))
                return norm.Substring(pr.Length + 1);
            return norm;
        }

        // ─── settings asset bootstrap ──────────────────────────────

        private static PSDImporterSettings LoadOrCreateSettings()
        {
            var guids = AssetDatabase.FindAssets("t:PSDImporterSettings");
            if (guids.Length > 0)
            {
                var path = AssetDatabase.GUIDToAssetPath(guids[0]);
                return AssetDatabase.LoadAssetAtPath<PSDImporterSettings>(path);
            }
            return null;
        }

        private static PSDImporterSettings CreateDefaultSettings()
        {
            const string dir = "Assets/Editor/PSDImporter";
            Directory.CreateDirectory(dir);
            var asset = ScriptableObject.CreateInstance<PSDImporterSettings>();
            var path = $"{dir}/PSDImporterSettings.asset";
            AssetDatabase.CreateAsset(asset, path);
            AssetDatabase.SaveAssets();
            Debug.Log($"[PSDImporter] Created settings asset at {path}");
            return asset;
        }
    }
}
