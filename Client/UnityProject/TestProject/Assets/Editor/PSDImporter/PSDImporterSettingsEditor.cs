// PSDImporterSettingsEditor.cs
//
// Custom Inspector for PSDImporterSettings. Hosts the configuration UI
// that used to live in the PSDImporterWindow — Python config, font
// config, UIBind generation toggle, sprite-importer toggle, etc.
//
// The window itself is intentionally minimal (just the Settings asset
// reference + 2 output paths + the import buttons). Everything
// configurable lives on the Settings asset and is edited here.

using System.IO;
using UnityEditor;
using UnityEngine;

namespace PSDImporter.Editor
{
    [CustomEditor(typeof(PSDImporterSettings))]
    public class PSDImporterSettingsEditor : UnityEditor.Editor
    {
        // Cached state for the diagnostic blocks at the bottom.
        private string _pythonTestResult = "";
        private double _pythonTestAt;

        public override void OnInspectorGUI()
        {
            // Show every serialized public field on the asset, with
            // the [Header] / [Tooltip] decorations we put on the
            // fields in PSDImporterSettings.cs. The window's two
            // path TextFields also touch the same underlying
            // properties (prefabOutputRoot / imageOutputRoot) so
            // edits stay in sync between the two UIs.
            DrawDefaultInspector();

            var settings = (PSDImporterSettings)target;

            EditorGUILayout.Space(10);
            EditorGUILayout.LabelField("Diagnostics", EditorStyles.boldLabel);

            DrawPythonTestBlock(settings);

            EditorGUILayout.Space(6);
            DrawQuickActions(settings);
        }

        // ─── Python diagnostic ─────────────────────────────────────

        private void DrawPythonTestBlock(PSDImporterSettings settings)
        {
            using (new EditorGUILayout.VerticalScope(EditorStyles.helpBox))
            {
                EditorGUILayout.LabelField("Python", EditorStyles.boldLabel);

                using (new EditorGUILayout.HorizontalScope())
                {
                    if (GUILayout.Button("🐍 Test Python (--version)", GUILayout.Height(24)))
                    {
                        var py = settings.pythonExecutable;
                        var script = settings.GetPythonScriptPath();
                        var result = PythonRunner.Run(py, "", new[] { "--version" });
                        if (result.ok)
                        {
                            _pythonTestResult =
                                $"✅  Python OK ({result.duration.TotalSeconds:F1}s)\n" +
                                $"  exe: {py}\n" +
                                $"  script: {script ?? "<not set>"}\n" +
                                $"  stdout: {result.stdout.Trim()}";
                        }
                        else
                        {
                            _pythonTestResult =
                                $"❌  Python unreachable:\n{result.stderr}\n\n" +
                                $"Tried exe: `{py}`\n" +
                                "Use the full path like\n" +
                                "  C:\\Users\\<you>\\AppData\\Local\\Programs\\Python\\Python313\\python.exe";
                        }
                        _pythonTestAt = EditorApplication.timeSinceStartup;
                        Debug.Log($"[PSDImporter] Test result: exit={result.exitCode}, " +
                                  $"stdout={result.stdout}, stderr={result.stderr}");
                    }
                    GUILayout.FlexibleSpace();
                    if (GUILayout.Button("Clear", GUILayout.Width(60)))
                    {
                        _pythonTestResult = "";
                    }
                }

                if (!string.IsNullOrEmpty(_pythonTestResult))
                {
                    // Show without icon — the message itself signals
                    // success / failure via the emoji prefix.
                    EditorGUILayout.HelpBox(_pythonTestResult, MessageType.None);
                }

                // Status: script auto-detection
                var scriptPath = settings.GetPythonScriptPath();
                if (string.IsNullOrEmpty(settings.pythonScriptPath))
                {
                    if (scriptPath == null)
                    {
                        EditorGUILayout.LabelField(
                            "  ⚠ psd_to_json.py not found at the auto-detect location.\n" +
                            "  Put it at <ProjectRoot>/Tools/PSDExporter/psd_to_json.py\n" +
                            "  or set 'Python script' above to a full path.",
                            EditorStyles.wordWrappedMiniLabel);
                    }
                    else
                    {
                        EditorGUILayout.LabelField(
                            $"  ✓ auto-detected: {scriptPath}",
                            EditorStyles.miniLabel);
                    }
                }
            }
        }

        // ─── Quick action buttons ──────────────────────────────────

        private void DrawQuickActions(PSDImporterSettings settings)
        {
            using (new EditorGUILayout.VerticalScope(EditorStyles.helpBox))
            {
                EditorGUILayout.LabelField("Quick actions", EditorStyles.boldLabel);

                if (GUILayout.Button("Convert existing PNGs in imageOutputRoot → Sprite"))
                {
                    PSDImagePostprocessor.ConvertAllExisting();
                }

                if (GUILayout.Button("Reveal PSD export folder in OS file browser"))
                {
                    var abs = settings.GetPsdExportRootAbsolute();
                    Directory.CreateDirectory(abs);
                    EditorUtility.RevealInFinder(abs);
                }

                if (GUILayout.Button("Reveal image output root in OS file browser"))
                {
                    if (string.IsNullOrEmpty(settings.imageOutputRoot)) return;
                    var projectRoot = Path.GetDirectoryName(Application.dataPath) ?? "";
                    var abs = Path.GetFullPath(Path.Combine(projectRoot, settings.imageOutputRoot));
                    Directory.CreateDirectory(abs);
                    EditorUtility.RevealInFinder(abs);
                }
            }
        }
    }
}
