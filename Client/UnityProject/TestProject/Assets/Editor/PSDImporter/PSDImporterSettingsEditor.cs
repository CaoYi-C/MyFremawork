// PSDImporterSettingsEditor.cs
//
// Custom Inspector for PSDImporterSettings. Hosts the configuration UI
// that used to live in the PSDImporterWindow — Python config, font
// config, UIBind generation toggle, sprite-importer toggle, etc.
//
// The window itself is intentionally minimal (just the Settings asset
// reference + 2 output paths + the import buttons). Everything
// configurable lives on the Settings asset and is edited here.
//
// All labels and tooltips are localized to Simplified Chinese.
//
// Path fields (psdExportRoot / pythonScriptPath / prefabOutputRoot /
// imageOutputRoot / fontSearchRoot) get a "📁 浏览…" button that opens
// a system folder picker so the user can click a directory rather
// than typing paths by hand.

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

        // SerializedProperties — bound once per enable for clean ApplyModifiedProperties.
        private SerializedProperty _psdExportRoot;
        private SerializedProperty _pythonExecutable;
        private SerializedProperty _pythonScriptPath;
        private SerializedProperty _prefabOutputRoot;
        private SerializedProperty _prefabNameOverride;
        private SerializedProperty _imageOutputRoot;
        private SerializedProperty _autoSetSpriteImporter;
        private SerializedProperty _deleteSourceImagesAfterImport;
        private SerializedProperty _autoGenerateUIBind;
        private SerializedProperty _defaultLayer;
        private SerializedProperty _fallbackFont;
        private SerializedProperty _fontSearchRoot;
        private SerializedProperty _cacheFileName;

        private void OnEnable()
        {
            _psdExportRoot              = serializedObject.FindProperty("psdExportRoot");
            _pythonExecutable           = serializedObject.FindProperty("pythonExecutable");
            _pythonScriptPath           = serializedObject.FindProperty("pythonScriptPath");
            _prefabOutputRoot           = serializedObject.FindProperty("prefabOutputRoot");
            _prefabNameOverride         = serializedObject.FindProperty("prefabNameOverride");
            _imageOutputRoot            = serializedObject.FindProperty("imageOutputRoot");
            _autoSetSpriteImporter      = serializedObject.FindProperty("autoSetSpriteImporter");
            _deleteSourceImagesAfterImport = serializedObject.FindProperty("deleteSourceImagesAfterImport");
            _autoGenerateUIBind         = serializedObject.FindProperty("autoGenerateUIBind");
            _defaultLayer               = serializedObject.FindProperty("defaultLayer");
            _fallbackFont               = serializedObject.FindProperty("fallbackFont");
            _fontSearchRoot             = serializedObject.FindProperty("fontSearchRoot");
            _cacheFileName              = serializedObject.FindProperty("cacheFileName");
        }

        public override void OnInspectorGUI()
        {
            serializedObject.Update();
            var settings = (PSDImporterSettings)target;

            DrawSourceSection();
            EditorGUILayout.Space(6);
            DrawPythonSection(settings);
            EditorGUILayout.Space(6);
            DrawOutputSection();
            EditorGUILayout.Space(6);
            DrawUIBindSection();
            EditorGUILayout.Space(6);
            DrawFontSection();
            EditorGUILayout.Space(6);
            DrawIncrementalSection();

            if (serializedObject.ApplyModifiedProperties())
            {
                EditorUtility.SetDirty(settings);
            }

            EditorGUILayout.Space(10);
            EditorGUILayout.LabelField("诊断 / Diagnostics", EditorStyles.boldLabel);
            DrawPythonTestBlock(settings);
            EditorGUILayout.Space(6);
            DrawQuickActions(settings);
        }

        // ─── 分组绘制 ─────────────────────────────────────────────

        private void DrawSourceSection()
        {
            EditorGUILayout.LabelField("源 PSD 路径", EditorStyles.boldLabel);
            DrawFolderField(_psdExportRoot,
                "PSD 导出根目录",
                "Python 工具写入 JSON + PNG 的目录。" +
                "默认 <ProjectRoot>/PSDExport,可改为磁盘上任何可达位置。",
                absoluteStart: null,   // 任意位置,不一定在工程内
                projectRelative: false);
        }

        private void DrawPythonSection(PSDImporterSettings settings)
        {
            EditorGUILayout.LabelField("Python", EditorStyles.boldLabel);
            EditorGUILayout.PropertyField(_pythonExecutable,
                new GUIContent("Python 可执行文件",
                    "调用 PSD→JSON 转换的 Python。留 'python' 用 PATH 里那个。" +
                    "Windows 上如果 PATH 解析不到,可能要写完整路径如\n" +
                    "  C:\\Users\\<you>\\AppData\\Local\\Programs\\Python\\Python313\\python.exe"));
            DrawFileField(_pythonScriptPath,
                "psd_to_json.py 路径",
                "留空则自动在 <ProjectRoot>/Tools/PSDExporter/psd_to_json.py 找。",
                settings.GetPythonScriptPath());
        }

        private void DrawOutputSection()
        {
            EditorGUILayout.LabelField("输出路径", EditorStyles.boldLabel);
            DrawFolderField(_prefabOutputRoot,
                "Prefab 输出根 (Assets/)",
                "生成的 UGUI Prefab 放在这里,每个 PSD 一个子目录。",
                absoluteStart: "Assets", projectRelative: true);
            EditorGUILayout.PropertyField(_prefabNameOverride,
                new GUIContent("Prefab 名称覆盖",
                    "空 = 用 PSD 文件名。\n" +
                    "非空 = 整个产物(预制体文件名、子目录、根 GameObject 名、" +
                    "NodeProvider/Window 类名、UIBindData 资产名)都用这个名字。\n" +
                    "适用于一个 PSD 里装多个备选 UI(切换其他组可见性),需要" +
                    "为代码类起一个干净的英文名。\n" +
                    "改名后不会自动迁移旧 Prefab —— 需要手动移或重新导入。"));
            DrawFolderField(_imageOutputRoot,
                "图片输出根 (Assets/)",
                "导入的 PNG 放在这里,每个 PSD 一个子目录 " +
                "(<imageOutputRoot>/<PsdName>/<layerName>.png)。" +
                "如目标已有同名但内容不同的 PNG,会让你逐张决定是否覆盖。",
                absoluteStart: "Assets", projectRelative: true);
            EditorGUILayout.PropertyField(_autoSetSpriteImporter,
                new GUIContent("自动设 Texture Type = Sprite",
                    "自动给 imageOutputRoot 里的 PNG 设 TextureImporter = Sprite。" +
                    "不想自动设就关掉(手动在 Inspector 里设)。"));
            EditorGUILayout.PropertyField(_deleteSourceImagesAfterImport,
                new GUIContent("导入后删除源 PNG",
                    "成功导入后,删除 Python 工具在 <psdExportRoot>/<PsdName>/images/ " +
                    "下写的源 PNG(Unity 已经在 imageOutputRoot 留了副本)。" +
                    "JSON 和缓存保留(增量重导需要)。"));
        }

        private void DrawUIBindSection()
        {
            EditorGUILayout.LabelField("UIBind 自动生成", EditorStyles.boldLabel);
            EditorGUILayout.PropertyField(_autoGenerateUIBind,
                new GUIContent("自动生成 UIBindData + NodeProvider + Window",
                    "用 UIBindCodeGenerator 自动生成绑定代码 + 资产。" +
                    "只想看原始 prefab 就关掉。"));
            EditorGUILayout.PropertyField(_defaultLayer,
                new GUIContent("默认 UILayer",
                    "生成的 UIBindData 资源上的默认 UILayer。"));
        }

        private void DrawFontSection()
        {
            EditorGUILayout.LabelField("字体", EditorStyles.boldLabel);
            EditorGUILayout.PropertyField(_fallbackFont,
                new GUIContent("备用字体",
                    "PSD 文本里的字体名解析不到时,就用这个。" +
                    "放到 Assets/Resources/ 下,让 YooAsset 打包能找到。"));
            DrawFolderField(_fontSearchRoot,
                "字体搜索根 (Assets/)",
                "PSD 文本里的字体名按文件名(无后缀)在 Assets/ 下找。",
                absoluteStart: "Assets", projectRelative: true);
        }

        private void DrawIncrementalSection()
        {
            EditorGUILayout.LabelField("增量", EditorStyles.boldLabel);
            EditorGUILayout.PropertyField(_cacheFileName,
                new GUIContent("缓存文件名",
                    "每个 PSD 的缓存文件,跟 JSON 放一起。存哈希 + 节点哈希映射" +
                    "用于增量重建。"));
        }

        // ─── 路径字段带"浏览…"按钮 ─────────────────────────────────

        // 通用文件夹字段:支持工程相对(限制在 Assets/ 下)或绝对路径。
        // absoluteStart / projectRelative 控制可选起始目录。
        private void DrawFolderField(SerializedProperty prop, string label, string tooltip,
            string absoluteStart, bool projectRelative)
        {
            using (new EditorGUILayout.HorizontalScope())
            {
                EditorGUILayout.PropertyField(prop, new GUIContent(label, tooltip));
                if (GUILayout.Button("📁…", GUILayout.Width(36)))
                {
                    var current = ResolvePath(prop.stringValue, absoluteStart, projectRelative);
                    var picked = projectRelative
                        ? EditorUtility.OpenFolderPanel("选择 " + label + " 文件夹", current, "")
                        : EditorUtility.OpenFolderPanel("选择 " + label + " 文件夹", current, "");
                    if (!string.IsNullOrEmpty(picked))
                    {
                        prop.stringValue = projectRelative
                            ? MakeProjectRelative(picked)
                            : picked;
                    }
                }
            }
        }

        private void DrawFileField(SerializedProperty prop, string label, string tooltip,
            string currentAbsolute)
        {
            using (new EditorGUILayout.HorizontalScope())
            {
                EditorGUILayout.PropertyField(prop, new GUIContent(label, tooltip));
                if (GUILayout.Button("📄…", GUILayout.Width(36)))
                {
                    var startDir = !string.IsNullOrEmpty(currentAbsolute)
                        ? Path.GetDirectoryName(currentAbsolute)
                        : "";
                    var picked = EditorUtility.OpenFilePanel("选择 " + label, startDir, "");
                    if (!string.IsNullOrEmpty(picked))
                    {
                        prop.stringValue = picked;
                    }
                }
            }
        }

        // 把绝对路径转成相对工程根(Assets/...)的格式。
        private static string MakeProjectRelative(string absolute)
        {
            var projectRoot = Path.GetDirectoryName(Application.dataPath) ?? "";
            var norm = absolute.Replace('\\', '/').TrimEnd('/');
            var pr = projectRoot.Replace('\\', '/').TrimEnd('/');
            if (norm.StartsWith(pr + "/", System.StringComparison.OrdinalIgnoreCase))
                return norm.Substring(pr.Length + 1);
            return norm;
        }

        // 把当前字段值解析成"浏览…"对话框用的初始目录。
        private static string ResolvePath(string fieldValue, string absoluteStart, bool projectRelative)
        {
            if (string.IsNullOrEmpty(fieldValue)) return absoluteStart ?? "";
            if (Path.IsPathRooted(fieldValue)) return fieldValue;
            // 相对路径 → 拼工程根
            if (projectRelative)
            {
                var projectRoot = Path.GetDirectoryName(Application.dataPath) ?? "";
                return Path.GetFullPath(Path.Combine(projectRoot, fieldValue));
            }
            return fieldValue;
        }

        // ─── Python 诊断 ─────────────────────────────────────────

        private void DrawPythonTestBlock(PSDImporterSettings settings)
        {
            using (new EditorGUILayout.VerticalScope(EditorStyles.helpBox))
            {
                EditorGUILayout.LabelField("Python", EditorStyles.boldLabel);

                using (new EditorGUILayout.HorizontalScope())
                {
                    if (GUILayout.Button("🐍 测试 Python (--version)", GUILayout.Height(24)))
                    {
                        var py = settings.pythonExecutable;
                        var script = settings.GetPythonScriptPath();
                        var result = PythonRunner.Run(py, "", new[] { "--version" });
                        if (result.ok)
                        {
                            _pythonTestResult =
                                $"✅  Python 可用 ({result.duration.TotalSeconds:F1}s)\n" +
                                $"  可执行: {py}\n" +
                                $"  脚本:   {script ?? "<未设置>"}\n" +
                                $"  stdout: {result.stdout.Trim()}";
                        }
                        else
                        {
                            _pythonTestResult =
                                $"❌  Python 不可用:\n{result.stderr}\n\n" +
                                $"已尝试: `{py}`\n" +
                                "在 Settings Inspector 的「Python 可执行文件」里改成完整路径,如\n" +
                                "  C:\\Users\\<你>\\AppData\\Local\\Programs\\Python\\Python313\\python.exe";
                        }
                        _pythonTestAt = EditorApplication.timeSinceStartup;
                        Debug.Log($"[PSDImporter] Test result: exit={result.exitCode}, " +
                                  $"stdout={result.stdout}, stderr={result.stderr}");
                    }
                    GUILayout.FlexibleSpace();
                    if (GUILayout.Button("清空", GUILayout.Width(60)))
                    {
                        _pythonTestResult = "";
                    }
                }

                if (!string.IsNullOrEmpty(_pythonTestResult))
                {
                    EditorGUILayout.HelpBox(_pythonTestResult, MessageType.None);
                }

                // psd_to_json.py 自动检测状态
                var scriptPath = settings.GetPythonScriptPath();
                if (string.IsNullOrEmpty(settings.pythonScriptPath))
                {
                    if (scriptPath == null)
                    {
                        EditorGUILayout.LabelField(
                            "  ⚠ 没在自动检测位置找到 psd_to_json.py。\n" +
                            "  把它放到 <ProjectRoot>/Tools/PSDExporter/psd_to_json.py," +
                            "或在上面「psd_to_json.py 路径」里写完整路径。",
                            EditorStyles.wordWrappedMiniLabel);
                    }
                    else
                    {
                        EditorGUILayout.LabelField(
                            $"  ✓ 自动检测到: {scriptPath}",
                            EditorStyles.miniLabel);
                    }
                }
            }
        }

        // ─── 快捷操作 ────────────────────────────────────────────

        private void DrawQuickActions(PSDImporterSettings settings)
        {
            using (new EditorGUILayout.VerticalScope(EditorStyles.helpBox))
            {
                EditorGUILayout.LabelField("快捷操作", EditorStyles.boldLabel);

                if (GUILayout.Button("把 imageOutputRoot 下的现有 PNG 转为 Sprite"))
                {
                    PSDImagePostprocessor.ConvertAllExisting();
                }

                if (GUILayout.Button("在系统文件管理器里打开 PSD 导出根目录"))
                {
                    var abs = settings.GetPsdExportRootAbsolute();
                    Directory.CreateDirectory(abs);
                    EditorUtility.RevealInFinder(abs);
                }

                if (GUILayout.Button("在系统文件管理器里打开图片输出根目录"))
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
