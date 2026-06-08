// PSDImporterSettings.cs
// ScriptableObject configuration for the PSD importer.
// Lives at Assets/Editor/PSDImporter/Resources/PSDImporterSettings.asset
// (or any user-chosen path) and is loaded on demand.

using System.IO;
using Manager.UIManager;
using UnityEngine;

namespace PSDImporter.Editor
{
    [CreateAssetMenu(
        fileName = "PSDImporterSettings",
        menuName = "PSD Importer/Settings",
        order    = 0)]
    public class PSDImporterSettings : ScriptableObject
    {
        [Header("Source")]
        [Tooltip("Folder the Python tool writes JSON + images into. " +
                 "Defaults to <ProjectRoot>/PSDExport, but you can redirect " +
                 "to anywhere reachable from disk.")]
        public string psdExportRoot = "PSDExport";

        [Header("Python")]
        [Tooltip("Path to the Python executable used to convert PSD → JSON. " +
                 "Leave as 'python' to use whatever is on PATH. " +
                 "On Windows you may need a full path like " +
                 "'C:\\Python313\\python.exe' if PATH doesn't resolve.")]
        public string pythonExecutable = "python";

        [Tooltip("Path to psd_to_json.py. Leave empty to auto-detect at " +
                 "<ProjectRoot>/Tools/PSDExporter/psd_to_json.py.")]
        public string pythonScriptPath = "";

        [Tooltip("Folder under Assets/ where generated UGUI prefabs go. " +
                 "Each PSD becomes a subfolder named after the PSD file.")]
        public string prefabOutputRoot = "Assets/PSDImport";

        [Tooltip("Override the generated prefab's base name. If empty " +
                 "(default), the PSD file name is used. This is the " +
                 "single-source override that drives the prefab filename, " +
                 "the subfolder under prefabOutputRoot, the root " +
                 "GameObject name, the generated NodeProvider + Window " +
                 "class names, and the UIBindData asset name — keeping " +
                 "all five in lockstep.\n\n" +
                 "Set to 'LoginView' to import a '登录.psd' but produce " +
                 "Assets/PSDImport/LoginView/LoginView.prefab, " +
                 "LoginViewNodeProvider, LoginViewWindow, etc. Useful " +
                 "when a single PSD has several alternative UIs in it " +
                 "(toggle the others' group visibility off) and you want " +
                 "a friendly English name for the code classes.")]
        public string prefabNameOverride = "";

        [Tooltip("Root folder under Assets/ where imported PNGs go. " +
                 "Each PSD gets its own subfolder inside this root, e.g. " +
                 "'Assets/PSDImages/LoginUI/btn_login.png'. " +
                 "If a file with the same name already exists but the " +
                 "content differs, you'll be asked before overwriting.")]
        public string imageOutputRoot = "Assets/PSDImages";

        [Tooltip("Auto-set Texture Type = Sprite (2D/UI) for any PNG that " +
                 "lands in imageOutputRoot. Disable if you want to set " +
                 "texture settings manually.")]
        public bool autoSetSpriteImporter = true;

        [Tooltip("After a successful import, delete the source PNGs the " +
                 "Python tool wrote under <psdExportRoot>/<PsdName>/images/. " +
                 "Unity has its own copy in imageOutputRoot, so the source " +
                 "files are redundant. Keeps the export folder tidy. " +
                 "The JSON + cache stay (needed for incremental re-imports).")]
        public bool deleteSourceImagesAfterImport = true;

        [Tooltip("Auto-generate UIBindData + NodeProvider + Window code " +
                 "using the existing UIBindCodeGenerator. Turn this off " +
                 "if you only want the raw prefab.")]
        public bool autoGenerateUIBind = false;   // disabled by default per current request

        [Tooltip("Default UILayer assigned to generated UIBindData.")]
        public UILayer defaultLayer = UILayer.Normal;

        [Header("Font")]
        [Tooltip("Font used when the PSD text's font name cannot be resolved. " +
                 "Set to a TTF in Assets/Resources/ so it survives YooAsset " +
                 "packaging.")]
        public Font fallbackFont;

        [Tooltip("If the PSD names a font (e.g. 'SourceHanSansCN-Bold'), " +
                 "the importer looks it up under Assets/ by file name (without " +
                 "extension). If not found, fallbackFont is used.")]
        public string fontSearchRoot = "Assets";

        [Header("Incremental")]
        [Tooltip("Per-PSD cache filename. Sits next to the JSON in the export " +
                 "folder. Stores hash + node-hash map for incremental rebuild.")]
        public string cacheFileName = "_psd_cache.json";

        // ─── Helpers ────────────────────────────────────────────────

        public string GetPsdExportRootAbsolute()
        {
            if (Path.IsPathRooted(psdExportRoot))
                return psdExportRoot;
            // Project root is one level above Assets/.
            var projectRoot = Path.GetDirectoryName(Application.dataPath);
            return Path.GetFullPath(Path.Combine(projectRoot ?? "", psdExportRoot));
        }

        /// <summary>
        /// Resolve the path to psd_to_json.py. If `pythonScriptPath` is set
        /// and the file exists, return it. Otherwise look in the conventional
        /// location: <ProjectRoot>/Tools/PSDExporter/psd_to_json.py.
        /// Returns null if not found anywhere.
        /// </summary>
        public string GetPythonScriptPath()
        {
            if (!string.IsNullOrEmpty(pythonScriptPath) && File.Exists(pythonScriptPath))
                return pythonScriptPath;
            var projectRoot = Path.GetDirectoryName(Application.dataPath) ?? "";
            var candidate = Path.Combine(projectRoot, "Tools", "PSDExporter", "psd_to_json.py");
            return File.Exists(candidate) ? candidate : null;
        }
    }
}
