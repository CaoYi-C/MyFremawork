// PSDImagePostprocessor.cs
// Auto-set the Texture Importer for any PNG that lands inside the
// configured `imageOutputRoot` so designers don't have to manually
// flip Texture Type = Sprite for every PSD-imported image.
//
// Runs in two places:
//   1. OnPreprocessTexture — fires for each PNG as Unity is about to
//      import it. We set the TextureImporter settings BEFORE the
//      texture is decoded, so Unity re-imports with the right config.
//   2. OnPostprocessAllAssets — after a batch import completes, we
//      re-import any existing PNGs that have the wrong texture type.
//      (For PNGs that were imported BEFORE this postprocessor existed,
//       Unity won't re-fire OnPreprocessTexture.)
//
// To turn this off entirely, set
//   `PSDImporterSettings.autoSetSpriteImporter = false`.

using System;
using System.IO;
using UnityEditor;
using UnityEngine;

namespace PSDImporter.Editor
{
    public class PSDImagePostprocessor : AssetPostprocessor
    {
        // ─── Pre-import: configure the importer for new PNGs ─────
        //
        // Runs *before* Unity decodes the texture. We modify the
        // TextureImporter so the new import uses Sprite mode.
        private void OnPreprocessTexture()
        {
            if (!ShouldHandle(assetPath)) return;

            var importer = (TextureImporter)assetImporter;
            importer.textureType         = TextureImporterType.Sprite;
            importer.spriteImportMode    = SpriteImportMode.Single;
            importer.spritePixelsPerUnit = 100f;
            importer.mipmapEnabled       = false;
            importer.filterMode          = FilterMode.Bilinear;
            importer.wrapMode            = TextureWrapMode.Clamp;
            importer.alphaIsTransparency = true;     // treat alpha as cutout for clean UI sprites
            importer.alphaSource         = TextureImporterAlphaSource.FromInput;
            importer.sRGBTexture         = true;     // UI textures are color
            importer.textureCompression  = TextureImporterCompression.Compressed;
            importer.isReadable          = false;    // UI doesn't need CPU readback
        }

        // ─── Post-import: catch any existing PNGs in our root that
        //      were imported as Default (e.g. before this postprocessor
        //      was installed, or added manually by the user). Re-import
        //      them with Sprite settings.
        private static void OnPostprocessAllAssets(
            string[] importedAssets,
            string[] deletedAssets,
            string[] movedAssets,
            string[] movedFromAssetPaths)
        {
            var settings = GetActiveSettings();
            if (settings == null || !settings.autoSetSpriteImporter) return;
            if (string.IsNullOrEmpty(settings.imageOutputRoot)) return;

            // Only run the sweep on actual asset-batch events, not on
            // every refresh. importedAssets is non-null when something
            // actually got imported in this batch.
            if (importedAssets == null || importedAssets.Length == 0) return;

            foreach (var path in importedAssets)
            {
                if (!ShouldHandle(path)) continue;
                ReimportIfWrongType(path);
            }
        }

        // ─── One-click sweep for pre-existing files ──────────────
        //
        // User can run this from the Tools menu to fix PNGs that
        // were imported before the postprocessor was installed.
        [MenuItem("Tools/PSD Importer/Convert existing PNGs to Sprite")]
        public static void ConvertAllExisting()
        {
            var settings = GetActiveSettings();
            if (settings == null)
            {
                Debug.LogWarning("[PSDImporter] No settings asset. Create one first.");
                return;
            }
            if (string.IsNullOrEmpty(settings.imageOutputRoot))
            {
                Debug.LogWarning("[PSDImporter] settings.imageOutputRoot is empty.");
                return;
            }

            var root = settings.imageOutputRoot.Replace('\\', '/').TrimEnd('/');
            if (!AssetDatabase.IsValidFolder(root))
            {
                Debug.LogWarning($"[PSDImporter] Image root not found: {root}");
                return;
            }

            int fixed_count = 0;
            var guids = AssetDatabase.FindAssets("t:Texture2D", new[] { root });
            try
            {
                for (int i = 0; i < guids.Length; i++)
                {
                    var path = AssetDatabase.GUIDToAssetPath(guids[i]);
                    EditorUtility.DisplayProgressBar(
                        "PSD Importer",
                        $"Converting {Path.GetFileName(path)}…",
                        (float)i / guids.Length);
                    if (ReimportIfWrongType(path)) fixed_count++;
                }
            }
            finally
            {
                EditorUtility.ClearProgressBar();
            }

            Debug.Log($"[PSDImporter] Converted {fixed_count} textures to Sprite in '{root}'.");
        }

        // ─── Helpers ──────────────────────────────────────────────

        private static bool ShouldHandle(string assetPath)
        {
            if (string.IsNullOrEmpty(assetPath)) return false;
            if (!assetPath.EndsWith(".png", StringComparison.OrdinalIgnoreCase)
                && !assetPath.EndsWith(".jpg", StringComparison.OrdinalIgnoreCase)
                && !assetPath.EndsWith(".tga", StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            var settings = GetActiveSettings();
            if (settings == null) return false;
            if (!settings.autoSetSpriteImporter) return false;
            if (string.IsNullOrEmpty(settings.imageOutputRoot)) return false;

            var root = settings.imageOutputRoot.Replace('\\', '/').TrimEnd('/');
            // Match files directly under <root> or in any subfolder.
            var normalized = assetPath.Replace('\\', '/');
            return normalized == root
                || normalized.StartsWith(root + "/", StringComparison.Ordinal);
        }

        private static bool ReimportIfWrongType(string path)
        {
            var importer = AssetImporter.GetAtPath(path) as TextureImporter;
            if (importer == null) return false;
            if (importer.textureType == TextureImporterType.Sprite) return false; // already correct
            importer.textureType         = TextureImporterType.Sprite;
            importer.spriteImportMode    = SpriteImportMode.Single;
            importer.spritePixelsPerUnit = 100f;
            importer.mipmapEnabled       = false;
            importer.alphaIsTransparency = true;
            importer.textureCompression  = TextureImporterCompression.Compressed;
            importer.SaveAndReimport();
            return true;
        }

        // No cache: settings may be edited at runtime, and FindAssets is
        // cheap enough at import time. We invalidate the implicit cache by
        // recreating the lookup every call.
        private static PSDImporterSettings GetActiveSettings()
        {
            var guids = AssetDatabase.FindAssets("t:PSDImporterSettings");
            if (guids.Length == 0) return null;
            var path = AssetDatabase.GUIDToAssetPath(guids[0]);
            return AssetDatabase.LoadAssetAtPath<PSDImporterSettings>(path);
        }
    }
}
