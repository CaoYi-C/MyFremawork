// PSDImporterWindow.cs
// Editor window: scans the PSD export folder, lists every JSON, lets the
// user pick one (or all) and import it.
//
// Menu: Tools > PSD Importer

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Manager.UIManager;
using UnityEditor;
using UnityEngine;

namespace PSDImporter.Editor
{
    public class PSDImporterWindow : EditorWindow
    {
        private const string MenuPath = "Tools/PSD Importer/Open Window";

        private Vector2 _scroll;
        private string  _exportRoot;
        private PSDImporterSettings _settings;
        private List<JsonEntry> _entries = new List<JsonEntry>();
        private string _lastReport = "";
        private bool _autoRefresh = true;

        private class JsonEntry
        {
            public string jsonPath;
            public string psdName;
            public string status;        // 'new' | 'changed' | 'unchanged'
            public DateTime lastImport;  // from cache
        }

        [MenuItem(MenuPath)]
        public static void Open()
        {
            var w = GetWindow<PSDImporterWindow>("PSD Importer");
            w.minSize = new Vector2(520, 320);
            w.Show();
        }

        // ─── lifecycle ──────────────────────────────────────────────

        private void OnEnable()
        {
            _settings = LoadOrCreateSettings();
            _exportRoot = _settings != null ? _settings.psdExportRoot : "PSDExport";
            EditorApplication.update += OnEditorUpdate;
            Scan();
        }

        private void OnDisable()
        {
            EditorApplication.update -= OnEditorUpdate;
        }

        private double _nextRefresh;
        private void OnEditorUpdate()
        {
            if (!_autoRefresh) return;
            if (EditorApplication.timeSinceStartup < _nextRefresh) return;
            _nextRefresh = EditorApplication.timeSinceStartup + 2.0;   // 2s debounce
            Scan();
            Repaint();
        }

        // ─── GUI ────────────────────────────────────────────────────

        private void OnGUI()
        {
            DrawHeader();
            EditorGUILayout.Space(4);
            DrawOneClickImport();
            EditorGUILayout.Space(4);
            DrawSettings();
            EditorGUILayout.Space(4);
            DrawEntryList();
            EditorGUILayout.Space(4);
            DrawFooter();
        }

        // ─── one-click import panel ─────────────────────────────────
        //
        // The fastest path: pick a PSD, we run Python under the hood,
        // then import the resulting JSON. No terminal needed.
        // ────────────────────────────────────────────────────────────

        private bool _generateUIBindThisSession = false;  // window-level override

        private void DrawOneClickImport()
        {
            using (new EditorGUILayout.VerticalScope(EditorStyles.helpBox))
            {
                EditorGUILayout.LabelField("One-click import", EditorStyles.boldLabel);
                EditorGUILayout.LabelField(
                    "Pick a PSD → we run Python under the hood → build the UGUI prefab.",
                    EditorStyles.miniLabel);
                EditorGUILayout.LabelField(
                    "(open Unity Console for detailed logs after each click)",
                    EditorStyles.miniLabel);

                // Show the latest report RIGHT HERE so the user can't miss it.
                if (!string.IsNullOrEmpty(_lastReport))
                {
                    // Icon rules:
                    //   ❌  → Error  (red !)
                    //   ⚠️  → Warning (yellow !)
                    //   ✅ 🔄 🔍 ℹ️ → Info (blue i)
                    //   其它  → Info (treat as log output, not an error)
                    var icon =
                        _lastReport.StartsWith("❌") ? MessageType.Error :
                        _lastReport.StartsWith("⚠")  ? MessageType.Warning :
                        MessageType.Info;
                    EditorGUILayout.HelpBox(_lastReport, icon);
                }

                if (_settings == null)
                {
                    EditorGUILayout.HelpBox(
                        "No settings asset yet. Create one to enable one-click import.",
                        MessageType.Warning);
                    if (GUILayout.Button("Create default settings asset", GUILayout.Height(28)))
                    {
                        _settings = CreateDefaultSettings();
                        Repaint();
                    }
                    return;
                }

                using (new EditorGUILayout.HorizontalScope())
                {
                    if (GUILayout.Button("📁  选中 PSD 并转换 + 导入", GUILayout.Height(34)))
                    {
                        PickAndImportPsd();
                    }
                    if (GUILayout.Button("🐍 Test", GUILayout.Width(60), GUILayout.Height(34)))
                    {
                        TestPython();
                    }
                }
                _generateUIBindThisSession = EditorGUILayout.ToggleLeft(
                    "  同时生成 UIBind 代码（UIBindData + NodeProvider + Window）",
                    _generateUIBindThisSession);
                _settings.autoSetSpriteImporter = EditorGUILayout.ToggleLeft(
                    "  自动把图片 output 设为 Sprite2D 导入",
                    _settings.autoSetSpriteImporter);
                if (!_settings.autoSetSpriteImporter
                    && AssetDatabase.IsValidFolder(_settings.imageOutputRoot))
                {
                    if (GUILayout.Button("  Convert existing PNGs in imageOutputRoot → Sprite"))
                    {
                        PSDImagePostprocessor.ConvertAllExisting();
                    }
                }
            }
        }

        private void DrawHeader()
        {
            EditorGUILayout.BeginHorizontal(EditorStyles.toolbar);
            GUILayout.Label("PSD Importer", EditorStyles.boldLabel);
            GUILayout.FlexibleSpace();
            _autoRefresh = GUILayout.Toggle(_autoRefresh, "Auto-refresh", EditorStyles.toolbarButton, GUILayout.Width(110));
            if (GUILayout.Button("Scan", EditorStyles.toolbarButton, GUILayout.Width(60))) Scan();
            if (GUILayout.Button("Help", EditorStyles.toolbarButton, GUILayout.Width(60))) DrawHelp();
            EditorGUILayout.EndHorizontal();
        }

        private void DrawSettings()
        {
            using (new EditorGUILayout.VerticalScope(EditorStyles.helpBox))
            {
                EditorGUILayout.LabelField("Settings", EditorStyles.boldLabel);
                _settings = (PSDImporterSettings)EditorGUILayout.ObjectField(
                    "Settings asset", _settings, typeof(PSDImporterSettings), false);
                if (_settings == null)
                {
                    EditorGUILayout.HelpBox(
                        "No PSDImporterSettings asset found. Click 'Create' to make one.",
                        MessageType.Warning);
                    if (GUILayout.Button("Create default settings asset"))
                    {
                        _settings = CreateDefaultSettings();
                    }
                    return;
                }

                EditorGUI.BeginChangeCheck();
                _settings.psdExportRoot = EditorGUILayout.TextField(
                    "PSD export root", _settings.psdExportRoot);
                _settings.pythonExecutable = EditorGUILayout.TextField(
                    "Python executable", _settings.pythonExecutable);
                using (new EditorGUILayout.HorizontalScope())
                {
                    _settings.pythonScriptPath = EditorGUILayout.TextField(
                        "Python script", _settings.pythonScriptPath);
                    if (GUILayout.Button("…", GUILayout.Width(28)))
                    {
                        var picked = EditorUtility.OpenFilePanel(
                            "Locate psd_to_json.py", "", "py");
                        if (!string.IsNullOrEmpty(picked))
                            _settings.pythonScriptPath = picked;
                    }
                    if (GUILayout.Button("auto", GUILayout.Width(44)))
                    {
                        _settings.pythonScriptPath = "";
                    }
                }
                EditorGUILayout.LabelField(
                    $"  (auto-detect: {_settings.GetPythonScriptPath() ?? "<not found>"})",
                    EditorStyles.miniLabel);

                _settings.prefabOutputRoot = EditorGUILayout.TextField(
                    "Prefab output (Assets/)", _settings.prefabOutputRoot);
                _settings.imageOutputRoot = EditorGUILayout.TextField(
                    "Image output root (Assets/)", _settings.imageOutputRoot);
                EditorGUILayout.LabelField(
                    "  (each PSD → <imageOutputRoot>/<PsdName>/<layerName>.png)",
                    EditorStyles.miniLabel);
                _settings.autoGenerateUIBind = EditorGUILayout.Toggle(
                    "Auto-generate UIBind (default)", _settings.autoGenerateUIBind);
                _settings.defaultLayer = (UILayer)EditorGUILayout.EnumPopup(
                    "Default UILayer", _settings.defaultLayer);
                _settings.fallbackFont = (Font)EditorGUILayout.ObjectField(
                    "Fallback font", _settings.fallbackFont, typeof(Font), false);
                _settings.fontSearchRoot = EditorGUILayout.TextField(
                    "Font search root", _settings.fontSearchRoot);
                if (EditorGUI.EndChangeCheck())
                {
                    EditorUtility.SetDirty(_settings);
                    _exportRoot = _settings.psdExportRoot;
                    Scan();
                }
            }
        }

        private void DrawEntryList()
        {
            EditorGUILayout.LabelField($"Found {_entries.Count} PSD file(s) in '{_exportRoot}'", EditorStyles.boldLabel);
            _scroll = EditorGUILayout.BeginScrollView(_scroll, GUILayout.MinHeight(160));
            if (_entries.Count == 0)
            {
                EditorGUILayout.HelpBox(
                    $"No <name>.json files found under {_exportRoot}.\n" +
                    "Run the Python tool first:\n" +
                    "  python psd_to_json.py path/to/MyUI.psd --out " + _exportRoot,
                    MessageType.Info);
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
                        EditorGUILayout.LabelField(e.psdName, e.jsonPath);
                        GUILayout.FlexibleSpace();
                        if (GUILayout.Button("Import", GUILayout.Width(72)))
                            ImportOne(e);
                    }
                }
            }
            EditorGUILayout.EndScrollView();
        }

        private void DrawFooter()
        {
            using (new EditorGUILayout.HorizontalScope(EditorStyles.toolbar))
            {
                using (new EditorGUI.DisabledScope(_entries.Count == 0 || _settings == null))
                {
                    if (GUILayout.Button("Import All (changed only)", EditorStyles.toolbarButton))
                        ImportChanged();
                }
                GUILayout.FlexibleSpace();
                if (GUILayout.Button("Reveal export folder", EditorStyles.toolbarButton, GUILayout.Width(160)))
                {
                    var abs = Path.GetFullPath(_exportRoot);
                    Directory.CreateDirectory(abs);
                    EditorUtility.RevealInFinder(abs);
                }
            }
            if (!string.IsNullOrEmpty(_lastReport))
                EditorGUILayout.HelpBox(_lastReport, MessageType.Info);
        }

        private void DrawHelp()
        {
            EditorUtility.DisplayDialog(
                "PSD Importer — Quick help",
                "Two ways to import:\n\n" +
                "1. ONE-CLICK (recommended)\n" +
                "   Click '选中 PSD 并转换 + 导入' at the top, pick a .psd.\n" +
                "   We run Python under the hood, then build the UGUI prefab.\n\n" +
                "2. MANUAL\n" +
                "   From terminal: python psd_to_json.py MyUI.psd --out PSDExport\n" +
                "   Then click 'Import' on the row in the list below.\n\n" +
                "Re-running either path updates only changed layers (incremental).\n\n" +
                "Layer prefixes (full list in Tools/PSDExporter/PREFIXES.md):\n" +
                "  btn_/txt_/img_/icon_/bg_/panel_/progress_/mask_/item_/fx_\n" +
                "  input_/scroll_/toggle_/slider_  (v1 partial — image only)\n" +
                "  group_/anim_/root_  (container, no UGUI component)",
                "OK");
        }

        // ─── scanning ───────────────────────────────────────────────

        private void Scan()
        {
            _entries.Clear();
            if (string.IsNullOrEmpty(_exportRoot) || !Directory.Exists(_exportRoot)) return;

            foreach (var dir in Directory.GetDirectories(_exportRoot))
            {
                foreach (var json in Directory.GetFiles(dir, "*.json"))
                {
                    // Skip our own cache file.
                    if (Path.GetFileName(json).StartsWith("_")) continue;

                    var e = new JsonEntry
                    {
                        jsonPath = json,
                        psdName  = Path.GetFileNameWithoutExtension(json),
                    };

                    // Try to load the cache.
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

            // Compare each entry against the JSON's sourcePsdHash to mark
            // 'unchanged' accurately.
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

        // ─── import actions ─────────────────────────────────────────

        private void ImportOne(JsonEntry e)
        {
            try
            {
                var report = PSDImporter.Import(e.jsonPath, _settings, _generateUIBindThisSession);
                _lastReport = FormatReport(e.psdName, report);
            }
            catch (Exception ex)
            {
                _lastReport = $"Failed: {ex.Message}";
                Debug.LogException(ex);
            }
            // Defer Scan+Repaint to next editor frame. Doing it synchronously
            // would mutate _entries while DrawEntryList is still iterating
            // over it (we're inside a button click handler in OnGUI),
            // causing "Collection was modified" + GUILayout state errors.
            EditorApplication.delayCall += () => { Scan(); Repaint(); };
        }

        private void ImportChanged()
        {
            int imported = 0, skipped = 0;
            foreach (var e in _entries.Where(e => e.status != "unchanged").ToList())
            {
                try
                {
                    var r = PSDImporter.Import(e.jsonPath, _settings, _generateUIBindThisSession);
                    if (r.skipped) skipped++;
                    else imported++;
                }
                catch (Exception ex)
                {
                    Debug.LogException(ex);
                }
            }
            _lastReport = $"Imported {imported}, skipped {skipped}.";
            // Defer Scan+Repaint: see comment in ImportOne.
            EditorApplication.delayCall += () => { Scan(); Repaint(); };
        }

        /// <summary>
        /// One-click path:
        ///   1. Open file dialog → user picks a .psd
        ///   2. Run psd_to_json.py in a subprocess (synchronous)
        ///   3. Locate the generated JSON in <psdExportRoot>/<PsdName>/
        ///   4. Call PSDImporter.Import
        /// </summary>
        private void PickAndImportPsd()
        {
            // Wrap the whole thing — any silent exception becomes a visible message
            // instead of a hung window.
            try
            {
                Debug.Log("[PSDImporter] PickAndImportPsd: click received");
                Repaint();

                if (_settings == null)
                {
                    _lastReport = "No settings asset. Click 'Create default settings asset' above.";
                    Repaint();
                    return;
                }
                var scriptPath = _settings.GetPythonScriptPath();
                if (scriptPath == null)
                {
                    _lastReport = "psd_to_json.py not found.\n" +
                                  "Set 'Python script' in Settings, or place it at " +
                                  "<ProjectRoot>/Tools/PSDExporter/psd_to_json.py.";
                    Repaint();
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

                // ─── 1. Run Python ─────────────────────────────────────
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

                // ─── 2. Locate the JSON ────────────────────────────────
                var jsonPath = Path.Combine(exportRoot, psdName, psdName + ".json");
                Debug.Log($"[PSDImporter] Looking for JSON: {jsonPath}");
                if (!File.Exists(jsonPath))
                {
                    _lastReport = $"❌  Python succeeded but JSON not found:\n{jsonPath}\n\n" +
                                  $"stdout:\n{result.stdout}\n\nstderr:\n{result.stderr}";
                    Repaint();
                    return;
                }

                // ─── 3. Import ─────────────────────────────────────────
                PSDImporter.ImportReport report;
                try
                {
                    Debug.Log("[PSDImporter] Calling PSDImporter.Import…");
                    report = PSDImporter.Import(jsonPath, _settings, _generateUIBindThisSession);
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
                // Defer Scan+Repaint: see comment in ImportOne.
                EditorApplication.delayCall += () => { Scan(); Repaint(); };

                // Select the resulting prefab in the project window so the
                // user can immediately inspect it.
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

        /// <summary>
        /// Quick diagnostic: spawn the configured python with --version
        /// and show the result. Helps users debug PATH / install issues.
        /// </summary>
        private void TestPython()
        {
            var py = _settings != null ? _settings.pythonExecutable : "python";
            var script = _settings != null ? _settings.GetPythonScriptPath() : null;
            _lastReport = $"Running `{py} --version`…";
            Repaint();
            Debug.Log($"[PSDImporter] Testing python: {py}");

            // Pass empty scriptPath so we run `python --version` directly.
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
                              "Fix in Settings → 'Python executable'. " +
                              "Use the full path like\n" +
                              "  C:\\Users\\<you>\\AppData\\Local\\Programs\\Python\\Python313\\python.exe";
            }
            Debug.Log($"[PSDImporter] Test result: exit={result.exitCode}, stdout={result.stdout}, stderr={result.stderr}");
            Repaint();
        }

        private string FormatReport(string psdName, PSDImporter.ImportReport report)
        {
            if (report.skipped)
                return $"'{psdName}' unchanged — no rebuild.";
            var s = $"Imported '{psdName}' → {report.prefabPath}\n" +
                    $"  +{report.addedCount}  -{report.removedCount}  ~{report.contentChangedCount}\n" +
                    $"  images: copied={report.imagesCopied} overwritten={report.imagesOverwritten} " +
                    $"skipped(same)={report.imagesSkippedSameContent} skipped(user)={report.imagesSkippedByUser}";
            if (report.warnings.Count > 0)
                s += "\nWarnings:\n  - " + string.Join("\n  - ", report.warnings);
            return s;
        }

        // ─── settings asset bootstrap ───────────────────────────────

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
            const string folder = "Assets/Editor/PSDImporter";
            const string path = folder + "/PSDImporterSettings.asset";
            Directory.CreateDirectory(folder);
            var s = ScriptableObject.CreateInstance<PSDImporterSettings>();
            AssetDatabase.CreateAsset(s, path);
            AssetDatabase.SaveAssets();
            return s;
        }

        // ─── asset menu: reimport a single PSD by right-clicking its JSON ─

        [MenuItem("Assets/PSD Importer/Import this JSON", true)]
        private static bool ValidateImportJsonAsset()
        {
            var sel = Selection.activeObject;
            return sel != null && AssetDatabase.GetAssetPath(sel).EndsWith(".json");
        }

        [MenuItem("Assets/PSD Importer/Import this JSON", false, 1000)]
        private static void ImportJsonAsset()
        {
            var path = AssetDatabase.GetAssetPath(Selection.activeObject);
            var settings = LoadOrCreateSettings();
            if (settings == null)
            {
                EditorUtility.DisplayDialog("PSD Importer",
                    "No PSDImporterSettings asset — open the window first.", "OK");
                return;
            }
            PSDImporter.Import(path, settings);
        }
    }
}
