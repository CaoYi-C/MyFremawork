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

        private List<JsonEntry> _entries = new List<JsonEntry>();
        private string _lastReport = "";
        private Vector2 _scroll;

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
                GUILayout.Label("PSD Importer", EditorStyles.boldLabel);
                GUILayout.FlexibleSpace();
                if (GUILayout.Button("Scan", EditorStyles.toolbarButton, GUILayout.Width(60)))
                    Scan();
                if (GUILayout.Button("Help", EditorStyles.toolbarButton, GUILayout.Width(60)))
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
                EditorGUILayout.LabelField("Settings", EditorStyles.boldLabel);

                var newSettings = (PSDImporterSettings)EditorGUILayout.ObjectField(
                    "Settings asset", _settings, typeof(PSDImporterSettings), false);
                if (newSettings != _settings)
                {
                    _settings = newSettings;
                    BindSerializedProperties();
                    _needsImmediateScan = true;
                }

                if (_settings == null)
                {
                    EditorGUILayout.HelpBox(
                        "⚠ No settings asset. Create one via the Project window:\n" +
                        "  Right-click → Create → PSD Importer → Settings.\n" +
                        "Then drag it into the field above.",
                        MessageType.None);
                    if (GUILayout.Button("Create default settings asset"))
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
                        EditorGUILayout.PropertyField(_prefabOutputRootProp,
                            new GUIContent("Prefab output (Assets/)"));
                    if (_imageOutputRootProp != null)
                        EditorGUILayout.PropertyField(_imageOutputRootProp,
                            new GUIContent("Image output root (Assets/)"));
                    EditorGUILayout.LabelField(
                        "  (each PSD → <imageOutputRoot>/<PsdName>/<layerName>.png)",
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
            using (new EditorGUILayout.HorizontalScope())
            {
                GUI.enabled = _settings != null;
                if (GUILayout.Button("📁  选中 PSD 并转换 + 导入", GUILayout.Height(34)))
                    PickAndImportPsd();
                if (GUILayout.Button("🐍 Test", GUILayout.Width(60), GUILayout.Height(34)))
                    TestPython();
                GUI.enabled = true;
            }
        }

        private void DrawEntryList()
        {
            if (_settings == null) return;   // can't list without export root
            var exportRoot = _settings.GetPsdExportRootAbsolute();
            EditorGUILayout.LabelField(
                $"Found {_entries.Count} PSD file(s) in '{_settings.psdExportRoot}'",
                EditorStyles.boldLabel);
            _scroll = EditorGUILayout.BeginScrollView(_scroll, GUILayout.MinHeight(160));
            if (_entries.Count == 0)
            {
                EditorGUILayout.HelpBox(
                    $"ℹ No <name>.json files found under {exportRoot}.\n" +
                    "Click 📁 above to run the Python tool on a PSD, or:\n" +
                    "  python psd_to_json.py path/to/MyUI.psd --out " + _settings.psdExportRoot,
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
                        if (GUILayout.Button("Import", GUILayout.Width(72)))
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
                if (GUILayout.Button("Import All (changed only)"))
                    ImportChanged();
                GUILayout.FlexibleSpace();
                if (GUILayout.Button("Reveal export folder", GUILayout.Width(160)))
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

        private void PickAndImportPsd()
        {
            try
            {
                if (_settings == null)
                {
                    _lastReport = "No settings asset. Drag one into the Settings field above.";
                    return;
                }
                Debug.Log("[PSDImporter] PickAndImportPsd: click received");
                Repaint();

                var scriptPath = _settings.GetPythonScriptPath();
                if (scriptPath == null)
                {
                    _lastReport = "psd_to_json.py not found.\n" +
                                  "Open the Settings asset's Inspector and set 'Python script', or " +
                                  "place it at <ProjectRoot>/Tools/PSDExporter/psd_to_json.py.";
                    return;
                }
                Debug.Log($"[PSDImporter] Using script: {scriptPath}");

                Debug.Log("[PSDImporter] About to show file dialog…");
                var psdPath = EditorUtility.OpenFilePanel("选择 PSD 文件", "", "psd");
                if (string.IsNullOrEmpty(psdPath))
                {
                    Debug.Log("[PSDImporter] File dialog cancelled.");
                    return;
                }
                Debug.Log($"[PSDImporter] Selected PSD: {psdPath}");

                var psdName = Path.GetFileNameWithoutExtension(psdPath);
                _lastReport = $"🔄  Running Python on {psdName}…";
                Repaint();

                var exportRoot = _settings.GetPsdExportRootAbsolute();
                Debug.Log($"[PSDImporter] Export root: {exportRoot}");
                var args = new[] { psdPath, "--out", exportRoot };

                PythonRunner.RunResult result;
                try
                {
                    EditorUtility.DisplayProgressBar(
                        "PSD Importer",
                        $"Converting {psdName}.psd via Python…",
                        0.3f);
                    Debug.Log($"[PSDImporter] Spawning: {_settings.pythonExecutable} {scriptPath} {string.Join(" ", args)}");
                    result = PythonRunner.Run(_settings.pythonExecutable, scriptPath, args);
                    Debug.Log($"[PSDImporter] Python exit={result.exitCode} in {result.duration.TotalSeconds:F1}s");
                }
                finally
                {
                    EditorUtility.ClearProgressBar();
                }

                if (!result.ok)
                {
                    _lastReport = $"❌  Python failed (exit={result.exitCode}, " +
                                  $"{result.duration.TotalSeconds:F1}s):\n{result.stderr}";
                    Debug.LogError($"[PSDImporter] {result.stderr}");
                    Repaint();
                    return;
                }

                var jsonPath = Path.Combine(exportRoot, psdName, psdName + ".json");
                Debug.Log($"[PSDImporter] Looking for JSON: {jsonPath}");
                if (!File.Exists(jsonPath))
                {
                    _lastReport = $"❌  Python succeeded but JSON not found:\n{jsonPath}\n\n" +
                                  $"stdout:\n{result.stdout}\n\nstderr:\n{result.stderr}";
                    Repaint();
                    return;
                }

                PSDImporter.ImportReport report;
                try
                {
                    Debug.Log("[PSDImporter] Calling PSDImporter.Import…");
                    report = PSDImporter.Import(jsonPath, _settings, _settings.autoGenerateUIBind);
                }
                catch (Exception ex)
                {
                    _lastReport = $"❌  Import threw:\n{ex.Message}";
                    Debug.LogException(ex);
                    Repaint();
                    return;
                }

                _lastReport = "✅  " + FormatReport(psdName, report)
                    + $"\n\n(Python {result.duration.TotalSeconds:F1}s, " +
                      $"exit={result.exitCode})";
                EditorApplication.delayCall += () =>
                {
                    _needsImmediateScan = true;
                    Repaint();
                };

                if (!string.IsNullOrEmpty(report.prefabPath))
                {
                    var asset = AssetDatabase.LoadAssetAtPath<UnityEngine.Object>(report.prefabPath);
                    if (asset != null) EditorGUIUtility.PingObject(asset);
                }
            }
            catch (Exception outerEx)
            {
                _lastReport = $"❌  Outer exception:\n{outerEx.GetType().Name}: {outerEx.Message}\n\n" +
                              $"{outerEx.StackTrace}";
                Debug.LogException(outerEx);
                Repaint();
            }
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
                return;
            }
            _settingsSO = new SerializedObject(_settings);
            _prefabOutputRootProp = _settingsSO.FindProperty("prefabOutputRoot");
            _imageOutputRootProp = _settingsSO.FindProperty("imageOutputRoot");
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
