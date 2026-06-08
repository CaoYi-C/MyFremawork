// PSDImporter.cs
// Core import pipeline: JSON → UGUI Prefab + UIBindData + NodeProvider.
//
// Pipeline:
//   1. Load JSON + cache
//   2. Compute incremental diff
//   3. (Re)build UGUI hierarchy
//   4. (Re)build UIBindData asset
//   5. Generate NodeProvider + Window code
//   6. Bind serialized fields on the prefab
//   7. Save cache

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using Manager.UIManager;
using Manager.UIManager.Editor;          // UIBindCodeGenerator
using UnityEditor;
using UnityEditor.SceneManagement;       // PrefabStageUtility
using UnityEngine;
using UnityEngine.UI;

namespace PSDImporter.Editor
{
    public static class PSDImporter
    {
        // ─────────────────────────────────────────────────────────────
        //  Public API
        // ─────────────────────────────────────────────────────────────

        public class ImportReport
        {
            public bool   skipped;                   // true ⇒ nothing changed
            public bool   sourceChanged;             // true ⇒ PSD file hash changed
            public int    addedCount;
            public int    removedCount;
            public int    contentChangedCount;
            public string prefabPath;
            public string bindDataPath;
            public string providerClassName;
            public string windowClassName;
            public List<string> warnings = new List<string>();

            // Image copy summary
            public int imagesCopied;
            public int imagesOverwritten;
            public int imagesSkippedSameContent;
            public int imagesSkippedByUser;
            public int sourceImagesCleanedUp;
        }

        /// <summary>
        /// Run the import. Safe to call from a menu item or batch script.
        /// </summary>
        public static ImportReport Import(string jsonPath, PSDImporterSettings settings)
            => Import(jsonPath, settings, settings != null && settings.autoGenerateUIBind);

        /// <summary>
        /// Run the import, with an explicit override for UIBind code generation.
        /// Use this when you want to control the UIBind toggle from the caller
        /// (e.g. the Editor window has a checkbox the user can flip per-import).
        /// </summary>
        public static ImportReport Import(string jsonPath, PSDImporterSettings settings, bool generateUIBind)
        {
            if (settings == null) throw new ArgumentNullException(nameof(settings));
            if (!File.Exists(jsonPath))
                throw new FileNotFoundException($"PSD JSON not found: {jsonPath}");

            var report = new ImportReport();
            var doc    = LoadDocument(jsonPath, report);
            if (doc == null) return report;

            // Validate schema.
            if (doc.schemaVersion != PsdDocument.CurrentSchemaVersion)
            {
                report.warnings.Add(
                    $"Schema version mismatch (file: {doc.schemaVersion}, expected: " +
                    $"{PsdDocument.CurrentSchemaVersion}). Importing anyway.");
            }

            // Compute incremental diff.
            var cachePath = Path.Combine(
                Path.GetDirectoryName(jsonPath) ?? "",
                settings.cacheFileName);
            var prevCache = IncrementalTracker.LoadOrCreate(cachePath);
            var diff = IncrementalTracker.Diff(doc, prevCache);

            // The "fullyUnchanged" path is fast but it can be wrong: the
            // user may have manually deleted the generated prefab between
            // imports. The cache + JSON haven't changed, so the diff
            // says "skip" — but the user clearly wants the prefab back.
            // In that case force a rebuild.
            if (diff.fullyUnchanged
                && !string.IsNullOrEmpty(prevCache.lastImportedPrefabPath)
                && !File.Exists(Path.GetFullPath(
                    Path.Combine(
                        Path.GetDirectoryName(Application.dataPath) ?? "",
                        prevCache.lastImportedPrefabPath))))
            {
                Debug.Log(
                    $"[PSDImporter] '{doc.sourcePsd.name}' content unchanged, " +
                    $"but '{prevCache.lastImportedPrefabPath}' is missing " +
                    "on disk — forcing a rebuild.");
                diff.fullyUnchanged = false;
            }

            if (diff.fullyUnchanged)
            {
                report.skipped = true;
                report.prefabPath = prevCache.lastImportedPrefabPath;
                report.bindDataPath = ResolveBindDataPath(prevCache.lastImportedPrefabPath, doc);
                Debug.Log($"[PSDImporter] '{doc.sourcePsd.name}' unchanged — skipping rebuild.");
                return report;
            }

            report.addedCount           = diff.AddedCount;
            report.removedCount         = diff.RemovedCount;
            report.contentChangedCount  = diff.ContentChangedCount;
            report.sourceChanged        = diff.sourceChanged;

            // Derive class name. If the user set a prefabNameOverride on
            // the Settings asset, that wins (drives prefab filename,
            // subfolder, root GameObject, NodeProvider + Window class
            // names, and UIBindData asset name — all five stay in
            // lockstep). Otherwise fall back to the PSD file name.
            var className = ResolveClassName(doc, settings);
            report.providerClassName = className + "NodeProvider";
            report.windowClassName   = className + "Window";

            // Pre-compute variable names + binding metadata on every node.
            AssignVariableNames(doc.root);

            // Resolve imageOutputRoot once — used by both the pre-scan
            // (to know where to look for conflicts) and the copy step.
            var imageOutputRoot = string.IsNullOrEmpty(settings.imageOutputRoot)
                ? "Assets/PSDImages"
                : settings.imageOutputRoot;

            // Pre-scan for image conflicts and (if any) let the user
            // decide per-image whether to overwrite the existing PNG.
            // The resolver returns null only if the user clicked Cancel,
            // which aborts the entire import.
            var conflicts = PreScanImageConflicts(doc, jsonPath, imageOutputRoot);
            Dictionary<string, bool> imageResolutions = null;
            if (conflicts.Count > 0)
            {
                imageResolutions = ImageConflictResolverWindow.Resolve(conflicts);
                if (imageResolutions == null)
                {
                    report.warnings.Add(
                        "Import cancelled by user at the image conflict resolver.");
                    return report;
                }
            }

            // Copy PNGs into imageOutputRoot/<psdName>/ + build the
            // id→asset-path map used by the image attachment step.
            // Honors the user's per-image resolutions from the
            // conflict resolver; if there were no conflicts, every
            // non-conflicting image is copied normally.
            var imageStats = SetImagePathResolver(
                doc, jsonPath, imageOutputRoot, imageResolutions);
            report.imagesCopied              = imageStats.copied;
            report.imagesOverwritten         = imageStats.overwritten;
            report.imagesSkippedSameContent  = imageStats.skippedSameContent;
            report.imagesSkippedByUser       = imageStats.skippedByUser;
            report.sourceImagesCleanedUp     = imageStats.sourceCleanedUp;

            // Build / rebuild the prefab.
            var prefabDir = Path.Combine(settings.prefabOutputRoot, className);
            var prefabPath = Path.Combine(prefabDir, className + ".prefab")
                                .Replace('\\', '/');
            Directory.CreateDirectory(prefabDir);

            var existingPrefab = AssetDatabase.LoadAssetAtPath<GameObject>(prefabPath);
            GameObject prefab = BuildPrefab(doc, prefabPath, existingPrefab, report);

            // Build UIBindData + generate code + bind (if enabled).
            if (generateUIBind)
            {
                var bindData = BuildOrUpdateBindData(doc, className, prefab, settings, report);
                report.bindDataPath = AssetDatabase.GetAssetPath(bindData);
                GenerateAndBind(bindData, prefab, report);
            }

            // Save assets and update cache.
            EditorUtility.SetDirty(prefab);
            AssetDatabase.SaveAssets();
            AssetDatabase.Refresh();

            var cache = IncrementalTracker.BuildCache(doc, prefabPath);
            IncrementalTracker.Save(cache, cachePath);

            report.prefabPath = prefabPath;
            Debug.Log($"[PSDImporter] Imported '{doc.sourcePsd.name}' → {prefabPath} " +
                      $"(+{report.addedCount} -{report.removedCount} ~{report.contentChangedCount})");

            return report;
        }

        /// <summary>
        /// Re-bind an already-generated prefab to its UIBindData.
        /// Useful when NodeProvider code was regenerated and field names
        /// changed (e.g. designer renamed a layer).
        /// </summary>
        public static void RebindPrefab(string prefabPath)
        {
            var bindData = FindBindDataForPrefab(prefabPath);
            if (bindData == null)
            {
                Debug.LogWarning($"[PSDImporter] No UIBindData found for prefab '{prefabPath}'.");
                return;
            }
            var prefab = AssetDatabase.LoadAssetAtPath<GameObject>(prefabPath);
            if (prefab == null)
            {
                Debug.LogError($"[PSDImporter] Prefab missing: {prefabPath}");
                return;
            }
            // Open prefab stage so the binding writes go to the actual asset.
            // Note: PrefabStage is not IDisposable in 2022.3, so we use a
            // local variable and let Unity close the stage on the next
            // stage switch (or when the user navigates away).
            var stage = PrefabStageUtility.OpenPrefab(prefabPath);
            if (stage == null)
            {
                Debug.LogError($"[PSDImporter] Failed to open prefab stage: {prefabPath}");
                return;
            }
            UIBindCodeGenerator.BindToPrefab(bindData, stage);
            AssetDatabase.SaveAssets();
        }

        // ─────────────────────────────────────────────────────────────
        //  JSON load
        // ─────────────────────────────────────────────────────────────

        private static PsdDocument LoadDocument(string jsonPath, ImportReport report)
        {
            try
            {
                var json = File.ReadAllText(jsonPath);
                var doc = JsonUtility.FromJson<PsdDocument>(json);
                if (doc == null || doc.root == null)
                {
                    Debug.LogError($"[PSDImporter] Empty or invalid document: {jsonPath}");
                    return null;
                }
                return doc;
            }
            catch (Exception e)
            {
                Debug.LogError($"[PSDImporter] Failed to parse {jsonPath}: {e.Message}");
                return null;
            }
        }

        // ─────────────────────────────────────────────────────────────
        //  Variable name assignment
        // ─────────────────────────────────────────────────────────────

        private static void AssignVariableNames(PsdNode root)
        {
            var used = new HashSet<string>();
            foreach (var n in root.SelfAndDescendants())
            {
                // All image-bearing types + text get a UIBind field.
                n.shouldBind = IsBindableType(n.type);
                if (!n.shouldBind) continue;

                // Use the prefix-aware sanitizer — the SAME one Python uses.
                // This makes `btn_close` → `BtnClose`, `toggle_music` → `ToggleMusic`, etc.
                var baseName = PsdNaming.SanitizeVariableName(n.name);
                var unique = MakeUnique(baseName, used);
                n.variableName     = unique;
                n.bindingTypeName  = ChooseBindingTypeName(n);
                used.Add(unique);
            }
        }

        private static bool IsBindableType(string type) =>
            type == "image" || type == "text" || type == "button"
         || type == "input" || type == "scroll" || type == "slider" || type == "toggle";

        private static string MakeUnique(string baseName, HashSet<string> used)
        {
            if (!used.Contains(baseName)) return baseName;
            for (int i = 2; i < 1000; i++)
            {
                var candidate = baseName + i;
                if (!used.Contains(candidate)) return candidate;
            }
            return baseName + Guid.NewGuid().ToString("N").Substring(0, 4);
        }

        private static string ChooseBindingTypeName(PsdNode n)
        {
            switch (n.type)
            {
                case "button":   return typeof(Button).FullName;
                case "text":     return typeof(Text).FullName;
                // All image-bearing types bind to the Image component. The
                // composite types (input/scroll/slider/toggle) get the user-
                // added component on top, but the field still references the
                // Image because that's what's guaranteed to exist after
                // import.
                case "image":
                case "raw":
                case "input":
                case "scroll":
                case "slider":
                case "toggle":
                case "bg":
                case "fx":
                case "icon":
                case "item":
                case "mask":
                case "panel":
                case "progress":
                    return typeof(Image).FullName;
                default:
                    return typeof(GameObject).FullName;
            }
        }

        // ─────────────────────────────────────────────────────────────
        //  Prefab construction
        // ─────────────────────────────────────────────────────────────

        private static GameObject BuildPrefab(
            PsdDocument doc,
            string prefabPath,
            GameObject existing,
            ImportReport report)
        {
            // Cache the PSD canvas size so ApplyRectTransform can convert
            // PSD top-left coords → UGUI center-anchored coords.
            s_canvasSize = new Vector2(doc.canvas.width, doc.canvas.height);

            // Build a fresh hierarchy in memory. Reusing the old prefab
            // structure complicates things (renames, layer reorders) and
            // gives little speedup for typical PSD sizes.
            var root = new GameObject(doc.sourcePsd.name.Replace(".psd", ""),
                typeof(RectTransform), typeof(Canvas));
            var rootRt = (RectTransform)root.transform;

            // ─── Root anchor policy ─────────────────────────────
            //
            // We use CENTER anchor + CENTER pivot for the root so the
            // PSD canvas's center sits exactly at the screen center
            // (Screen Space Overlay). All children are then positioned
            // relative to this center, with the formula:
            //
            //   anchoredPosition.x = (x + w/2) - canvasW/2
            //   anchoredPosition.y = canvasH/2 - (y + h/2)
            //
            // This avoids the "whole UI is offset" bug that comes from
            // mismatched anchor+pivot conventions between the root and
            // its children.
            rootRt.anchorMin     = new Vector2(0.5f, 0.5f);
            rootRt.anchorMax     = new Vector2(0.5f, 0.5f);
            rootRt.pivot         = new Vector2(0.5f, 0.5f);
            rootRt.anchoredPosition = Vector2.zero;
            rootRt.localScale    = Vector3.one;
            rootRt.sizeDelta     = new Vector2(doc.canvas.width, doc.canvas.height);

            // Add a GraphicRaycaster so the UI is interactable.
            root.AddComponent<GraphicRaycaster>();

            // Add a CanvasScaler that scales the UI to the PSD reference size.
            var scaler = root.AddComponent<CanvasScaler>();
            scaler.uiScaleMode            = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            scaler.referenceResolution    = new Vector2(doc.canvas.width, doc.canvas.height);
            scaler.screenMatchMode        = CanvasScaler.ScreenMatchMode.MatchWidthOrHeight;
            scaler.matchWidthOrHeight     = 0.5f;

            // Make the root a 2D screen-space canvas.
            var canvas = root.GetComponent<Canvas>();
            canvas.renderMode = RenderMode.ScreenSpaceOverlay;

            // Build children recursively.
            BuildNodeHierarchy(doc.root, rootRt, doc);

            // Persist to disk.
            GameObject saved;
            if (existing != null)
            {
                saved = PrefabUtility.SaveAsPrefabAssetAndConnect(root, prefabPath,
                                InteractionMode.AutomatedAction);
            }
            else
            {
                saved = PrefabUtility.SaveAsPrefabAsset(root, prefabPath);
            }
            UnityEngine.Object.DestroyImmediate(root);
            return saved;
        }

        private static void BuildNodeHierarchy(PsdNode node, Transform parent, PsdDocument doc)
        {
            if (!node.visible) return;

            // Skip the synthetic "root" wrapper — we attach directly to the
            // canvas root.
            bool isSyntheticRoot = node.parent == null;
            if (isSyntheticRoot)
            {
                foreach (var child in node.children ?? Enumerable.Empty<PsdNode>())
                {
                    child.parent = node;
                    BuildNodeHierarchy(child, parent, doc);
                }
                return;
            }

            var go = new GameObject(node.name, typeof(RectTransform));
            go.transform.SetParent(parent, worldPositionStays: false);

            var rt = (RectTransform)go.transform;
            ApplyRectTransform(rt, node);

            switch (node.type)
            {
                // All image-bearing types get an Image component. The
                // composite-prefix types (input/scroll/slider/toggle) get
                // a warning reminding the user to add the actual component.
                case "image":
                case "raw":
                case "button":
                case "input":
                case "scroll":
                case "slider":
                case "toggle":
                    AttachImageComponent(go, node, doc);
                    break;
                case "text":
                    AttachTextComponent(go, node, doc);
                    break;
                // "group" → just a RectTransform
            }

            // Recurse.
            foreach (var child in node.children ?? Enumerable.Empty<PsdNode>())
            {
                child.parent = node;
                BuildNodeHierarchy(child, go.transform, doc);
            }
        }

        // PSD canvas reference size cached once per import. Used to
        // convert PSD top-left coordinates to UGUI center-anchored coords.
        private static Vector2 s_canvasSize;

        private static void ApplyRectTransform(RectTransform rt, PsdNode node)
        {
            // ─── Center-anchor policy + pass-through groups ─────
            //
            // UGUI's `anchoredPosition` is RELATIVE TO THE PARENT, not
            // the canvas. But PSD layer positions are all relative to
            // the canvas. So if we naively put a deep child at its
            // PSD-canvas-relative position, the deep parent hierarchy
            // accumulates offsets and the child ends up in the wrong
            // place. (This is the "buttons too far down" bug.)
            //
            // Fix: make every GROUP node a "pass-through" — size (0,0),
            // anchoredPosition (0,0), center anchor + center pivot. With
            // those, a group's pivot lands exactly at the canvas's
            // center, and any child with center anchor+pivot will be
            // positioned in CANVAS space, ignoring the group hierarchy
            // for layout. Groups still appear in the Hierarchy panel
            // for organization, but they don't influence positions.
            //
            // For non-group elements (image / button / text) we use
            // the actual PSD size and a center-based anchoredPosition
            // computed from the rect's CENTER in PSD space, mirrored
            // for UGUI's Y-up axis and offset by the canvas center.
            //
            //   centerX_psd = x + w/2
            //   centerY_psd = y + h/2
            //   anchoredX   = centerX_psd - canvasW/2
            //   anchoredY   = canvasH/2 - centerY_psd
            rt.anchorMin     = new Vector2(0.5f, 0.5f);
            rt.anchorMax     = new Vector2(0.5f, 0.5f);
            rt.pivot         = new Vector2(0.5f, 0.5f);
            rt.localScale    = Vector3.one;

            if (node.IsGroup)
            {
                // Pass-through for groups: 0×0 size, anchored at the
                // canvas center, so the group's pivot lines up with the
                // canvas's pivot. Children with center anchor+pivot then
                // end up positioned in CANVAS space, not group space.
                rt.sizeDelta       = Vector2.zero;
                rt.anchoredPosition = Vector2.zero;
            }
            else
            {
                float centerX = node.rect.x + node.rect.w * 0.5f;
                float centerY = node.rect.y + node.rect.h * 0.5f;
                float canvasW = s_canvasSize.x;
                float canvasH = s_canvasSize.y;
                rt.sizeDelta       = new Vector2(node.rect.w, node.rect.h);
                rt.anchoredPosition = new Vector2(
                    centerX - canvasW * 0.5f,
                    canvasH * 0.5f - centerY);
            }

            // Honour visibility + opacity.
            var canvasGroup = rt.GetComponent<CanvasGroup>();
            if (Mathf.Approximately(node.opacity, 1f))
            {
                if (canvasGroup != null) UnityEngine.Object.DestroyImmediate(canvasGroup);
            }
            else
            {
                if (canvasGroup == null) canvasGroup = rt.gameObject.AddComponent<CanvasGroup>();
                canvasGroup.alpha = node.opacity;
            }
        }

        private static void AttachImageComponent(GameObject go, PsdNode node, PsdDocument doc)
        {
            var img = go.AddComponent<Image>();
            img.sprite = LoadSprite(node, doc);
            img.preserveAspect = false;
            img.color = Color.white;

            // 9-slice: set Image type to Sliced so the sprite's
            // configured `spriteBorder` is respected at runtime. The
            // border itself was set on the TextureImporter in
            // ConfigureSlicedSprites (called from SetImagePathResolver).
            //
            // IMPORTANT: check the actual border values, not just
            // `slice != null`. Unity's JsonUtility constructs a default
            // instance of any [Serializable] class field that's missing
            // from the JSON, so `node.slice` is *never* null after
            // deserialization — it's an empty PsdSlice with l=t=r=b=0.
            // A pure null-check would mark every single Image in the
            // prefab as Sliced.
            if (node.slice != null
                && (node.slice.l | node.slice.t | node.slice.r | node.slice.b) != 0)
            {
                img.type = Image.Type.Sliced;
            }

            // Raycast policy:
            //   interactive (button / input / scroll / slider / toggle) → on
            //   decorative  (img / icon / bg / panel / mask / progress / item / fx) → off
            img.raycastTarget = IsInteractiveType(node.type);

            switch (node.type)
            {
                case "button":
                {
                    var btn = go.AddComponent<Button>();
                    btn.targetGraphic = img;
                    break;
                }
                case "progress":
                {
                    // Progress bars are typically Filled-type images so the
                    // runtime can drive fillAmount. Border/stripes preserved.
                    img.type = Image.Type.Filled;
                    img.fillMethod = Image.FillMethod.Horizontal;
                    break;
                }
                case "scroll":
                {
                    Debug.LogWarning(
                        $"[PSDImporter] '{node.id}' (type=scroll) only got the Image. " +
                        "Manually add a ScrollRect component in the Inspector and link Viewport / Content.");
                    break;
                }
                case "input":
                {
                    Debug.LogWarning(
                        $"[PSDImporter] '{node.id}' (type=input) only got the Image. " +
                        "Manually add an InputField component and link Placeholder / Text.");
                    break;
                }
                case "slider":
                {
                    Debug.LogWarning(
                        $"[PSDImporter] '{node.id}' (type=slider) only got the Image. " +
                        "Manually add a Slider component and link Handle / Fill Area.");
                    break;
                }
                case "toggle":
                {
                    Debug.LogWarning(
                        $"[PSDImporter] '{node.id}' (type=toggle) only got the Image. " +
                        "Manually add a Toggle component and link Checkmark / Label.");
                    break;
                }
            }
        }

        private static bool IsInteractiveType(string type) =>
            type == "button" || type == "input" || type == "scroll"
         || type == "slider" || type == "toggle";

        private static void AttachTextComponent(GameObject go, PsdNode node, PsdDocument doc)
        {
            var text = go.AddComponent<Text>();
            text.text     = node.text?.content ?? "";
            text.font     = ResolveFont(node.text, doc);
            text.fontSize = (node.text != null && node.text.fontSize > 0) ? Mathf.RoundToInt(node.text.fontSize) : 24;
            text.color    = ParseColor(node.text?.color);
            text.alignment = ParseAnchor(node.text?.alignment);
            text.horizontalOverflow = HorizontalWrapMode.Overflow;
            text.verticalOverflow   = VerticalWrapMode.Overflow;
            text.raycastTarget = false;
        }

        // ─────────────────────────────────────────────────────────────
        //  Asset loading
        // ─────────────────────────────────────────────────────────────

        private static Sprite LoadSprite(PsdNode node, PsdDocument doc)
        {
            if (string.IsNullOrEmpty(node.imageFile)) return null;
            // The actual asset path is set by SetImagePathResolver, which
            // copies the PNG from the Python export folder into the prefab's
            // images subfolder and registers the id → asset path mapping.
            var path = GetImagePathOverride(node);
            if (string.IsNullOrEmpty(path))
            {
                Debug.LogWarning($"[PSDImporter] No path resolver for image '{node.id}'.");
                return null;
            }
            var sprite = AssetDatabase.LoadAssetAtPath<Sprite>(path);
            if (sprite == null)
            {
                // Diagnostic — the most common reason is that the asset
                // hasn't been reimported as a Sprite yet. Try forcing one
                // round of reimport and retry. If still null the file is
                // probably missing on disk.
                Debug.LogWarning(
                    $"[PSDImporter] LoadAssetAtPath returned null for '{path}' " +
                    $"(layer '{node.id}'). File exists? {File.Exists(path)}. " +
                    "Will force a reimport and retry.");
                AssetDatabase.ImportAsset(path, ImportAssetOptions.ForceUpdate);
                sprite = AssetDatabase.LoadAssetAtPath<Sprite>(path);
            }
            return sprite;
        }

        // Image-path override set by the importer before BuildPrefab runs.
        private static Dictionary<string, string> s_imagePathOverride;

        private static string GetImagePathOverride(PsdNode node)
        {
            return s_imagePathOverride != null && s_imagePathOverride.TryGetValue(node.id, out var p) ? p : null;
        }

        private static Font ResolveFont(PsdText text, PsdDocument doc)
        {
            var settings = GetActiveSettings();
            if (text != null && !string.IsNullOrEmpty(text.fontName) && settings != null)
            {
                var font = FindFontByName(text.fontName, settings);
                if (font != null) return font;
            }
            return settings != null ? settings.fallbackFont : null;
        }

        private static Font FindFontByName(string fontName, PSDImporterSettings settings)
        {
            if (string.IsNullOrEmpty(settings.fontSearchRoot)) return null;
            var root = settings.fontSearchRoot.TrimEnd('/').TrimEnd('\\');
            var guids = AssetDatabase.FindAssets($"{fontName} t:Font", new[] { root });
            foreach (var g in guids)
            {
                var path = AssetDatabase.GUIDToAssetPath(g);
                var f = AssetDatabase.LoadAssetAtPath<Font>(path);
                if (f != null) return f;
            }
            return null;
        }

        private static Color ParseColor(string hex)
        {
            if (string.IsNullOrEmpty(hex) || hex.Length < 7) return Color.white;
            byte r = System.Convert.ToByte(hex.Substring(1, 2), 16);
            byte g = System.Convert.ToByte(hex.Substring(3, 2), 16);
            byte b = System.Convert.ToByte(hex.Substring(5, 2), 16);
            byte a = hex.Length >= 9 ? System.Convert.ToByte(hex.Substring(7, 2), 16) : (byte)255;
            return new Color32(r, g, b, a);
        }

        private static TextAnchor ParseAnchor(string s)
        {
            if (string.IsNullOrEmpty(s)) return TextAnchor.MiddleCenter;
            return (TextAnchor)Enum.Parse(typeof(TextAnchor), s, ignoreCase: true);
        }

        // ─────────────────────────────────────────────────────────────
        //  UIBindData
        // ─────────────────────────────────────────────────────────────

        private static UIBindData BuildOrUpdateBindData(
            PsdDocument doc, string className, GameObject prefab,
            PSDImporterSettings settings, ImportReport report)
        {
            var bindDataPath = $"Assets/Scripts/Game/UI/Editor/UIBindData/{className}.asset";
            Directory.CreateDirectory(Path.GetDirectoryName(bindDataPath));

            var bind = AssetDatabase.LoadAssetAtPath<UIBindData>(bindDataPath);
            if (bind == null)
            {
                bind = ScriptableObject.CreateInstance<UIBindData>();
                bind.PrefabPath = AssetDatabase.GetAssetPath(prefab);
                bind.ClassName  = className;
                bind.Layer      = settings.defaultLayer;
                AssetDatabase.CreateAsset(bind, bindDataPath);
            }
            else
            {
                bind.PrefabPath = AssetDatabase.GetAssetPath(prefab);
                bind.ClassName  = className;
                bind.Layer      = settings.defaultLayer;
            }

            // Reset entries and rebuild from the document.
            bind.Entries.Clear();
            foreach (var n in doc.root.SelfAndDescendants())
            {
                if (!n.shouldBind) continue;
                var targetPath = ComputeTargetPath(n);
                bind.AddEntry(n.variableName, n.bindingTypeName, targetPath, ResolveTarget(prefab, n, targetPath));
            }

            EditorUtility.SetDirty(bind);
            return bind;
        }

        private static string ComputeTargetPath(PsdNode n)
        {
            // Path is the chain of names from the PSD root (excluding the
            // synthetic root) down to this node, joined by '/'.
            var stack = new Stack<string>();
            var cur = n;
            while (cur != null && cur.parent != null)   // skip synthetic root
            {
                stack.Push(cur.name);
                cur = cur.parent;
            }
            return string.Join("/", stack);
        }

        private static UnityEngine.Object ResolveTarget(GameObject prefab, PsdNode n, string targetPath)
        {
            var root = prefab.transform;
            var tr = string.IsNullOrEmpty(targetPath) ? root : root.Find(targetPath);
            if (tr == null) return null;
            if (n.bindingTypeName == typeof(GameObject).FullName) return tr.gameObject;
            var t = Type.GetType(n.bindingTypeName);
            return t != null ? tr.GetComponent(t) : null;
        }

        private static string ResolveBindDataPath(string prefabPath, PsdDocument doc)
        {
            if (string.IsNullOrEmpty(prefabPath)) return null;
            var name = Path.GetFileNameWithoutExtension(prefabPath);
            return $"Assets/Scripts/Game/UI/Editor/UIBindData/{name}.asset";
        }

        // ─────────────────────────────────────────────────────────────
        //  Code generation + binding
        // ─────────────────────────────────────────────────────────────

        private static void GenerateAndBind(UIBindData bind, GameObject prefab, ImportReport report)
        {
            // Generate code. This overwrites NodeProvider.cs.
            // Window.cs is only written the first time (UIBindCodeGenerator
            // preserves it for the user's business logic).
            try
            {
                UIBindCodeGenerator.Generate(bind);
            }
            catch (Exception e)
            {
                report.warnings.Add($"UIBind code generation failed: {e.Message}. " +
                                    "Re-bind manually after compile.");
                return;
            }

            // Refresh and try to find the generated type.
            AssetDatabase.Refresh();
            var providerType = FindType(bind.ClassName + "NodeProvider");
            if (providerType == null)
            {
                report.warnings.Add(
                    $"Generated type '{bind.ClassName}NodeProvider' not found. " +
                    "Unity will compile the new code shortly — click " +
                    "'Rebind' on the prefab once compile finishes.");
                return;
            }

            // Open the prefab stage, attach the provider, set serialized fields.
            // Note: PrefabStage is not IDisposable in 2022.3, so we use a
            // local variable and let Unity close the stage on the next
            // stage switch (or when the user navigates away).
            var stage = PrefabStageUtility.OpenPrefab(
                AssetDatabase.GetAssetPath(prefab));
            if (stage == null)
            {
                report.warnings.Add("Could not open prefab stage for binding.");
                return;
            }
            UIBindCodeGenerator.BindToPrefab(bind, stage);
            AssetDatabase.SaveAssets();
        }

        private static Type FindType(string typeName)
        {
            foreach (var asm in AppDomain.CurrentDomain.GetAssemblies())
            {
                Type t = null;
                try { t = asm.GetType(typeName); } catch { }
                if (t != null) return t;
            }
            // Fallback: short name search (when namespace isn't loaded yet).
            foreach (var asm in AppDomain.CurrentDomain.GetAssemblies())
            {
                Type[] types = null;
                try { types = asm.GetTypes(); } catch { continue; }
                foreach (var t in types)
                    if (t.Name == typeName) return t;
            }
            return null;
        }

        // ─────────────────────────────────────────────────────────────
        //  Misc
        // ─────────────────────────────────────────────────────────────

        private static UIBindData FindBindDataForPrefab(string prefabPath)
        {
            var name = Path.GetFileNameWithoutExtension(prefabPath);
            var path = $"Assets/Scripts/Game/UI/Editor/UIBindData/{name}.asset";
            return AssetDatabase.LoadAssetAtPath<UIBindData>(path);
        }

        private static string SanitizeClassName(string s)
        {
            if (string.IsNullOrEmpty(s)) return "PSDView";
            var sb = new System.Text.StringBuilder();
            foreach (var c in s)
                sb.Append(char.IsLetterOrDigit(c) ? c : '_');
            var result = sb.ToString().Trim('_');
            if (result.Length == 0) result = "PSDView";
            if (char.IsDigit(result[0])) result = "_" + result;
            return result;
        }

        /// <summary>
        /// Decide what the base name for this import is. Drives the
        /// prefab filename, the subfolder under prefabOutputRoot, the
        /// root GameObject name, the NodeProvider + Window class names,
        /// the UIBindData asset name, AND the per-PSD subfolder under
        /// imageOutputRoot — all five have to agree or the import
        /// breaks in subtle ways (image not found, UIBind class not
        /// found, etc.).
        ///
        /// Resolution order:
        ///   1. <c>settings.prefabNameOverride</c> — if non-empty, this
        ///      is what we use, after SanitizeClassName.
        ///   2. Otherwise the PSD file name (without extension).
        /// </summary>
        private static string ResolveClassName(PsdDocument doc, PSDImporterSettings settings)
        {
            var overrideName = settings != null ? settings.prefabNameOverride : null;
            if (!string.IsNullOrWhiteSpace(overrideName))
            {
                return SanitizeClassName(overrideName.Trim());
            }
            return SanitizeClassName(Path.GetFileNameWithoutExtension(doc.sourcePsd.name));
        }

        private static PSDImporterSettings GetActiveSettings()
        {
            // Don't cache: the user may have edited the asset in the
            // Inspector since the last import and we always want the
            // current values. FindAssets is fast enough.
            var guids = AssetDatabase.FindAssets("t:PSDImporterSettings");
            if (guids.Length > 0)
            {
                var path = AssetDatabase.GUIDToAssetPath(guids[0]);
                return AssetDatabase.LoadAssetAtPath<PSDImporterSettings>(path);
            }
            return null;
        }

        /// <summary>
        /// Called by the editor window before BuildPrefab to set the
        /// image path resolver. Without this, AttachImageComponent can't
        /// find the PNGs the Python side wrote next to the JSON.
        ///
        /// The PNGs are copied from <jsonDir>/images/ into
        /// <imageOutputRoot>/<psdName>/ so the prefab can reference them
        /// as Asset paths. If a file with the same name already exists
        /// in the destination with different content, the user is asked
        /// via EditorUtility.DisplayDialogComplex (Yes / No / Yes to all).
        ///
        /// If `manualResolutions` is non-null (typically produced by
        /// the ImageConflictResolverWindow), every layer present in the
        /// dict gets its pre-decided outcome — no popup is shown. This
        /// is the new "preview both images before deciding" path.
        /// Layers NOT in the dict still go through the legacy dialog
        /// (handy for one-off scripts).
        /// </summary>
        public static ImageCopyStats SetImagePathResolver(
            PsdDocument doc, string jsonPath, string imageOutputRoot,
            Dictionary<string, bool> manualResolutions = null)
        {
            var stats = new ImageCopyStats();
            s_imagePathOverride = new Dictionary<string, string>();
            var jsonDir = Path.GetDirectoryName(Path.GetFullPath(jsonPath)) ?? "";
            // Use the same name the importer will use for the prefab
            // subfolder + class name. Otherwise images and the prefab
            // would land in different folders and nothing would link.
            var psdName = ResolveClassName(doc, GetActiveSettings());

            // imageOutputRoot is something like "Assets/PSDImages" — make
            // sure both halves agree on the separator style.
            var rootRel = imageOutputRoot.Replace('\\', '/').TrimEnd('/');
            var rootAbs = Path.GetFullPath(
                Path.Combine(Path.GetDirectoryName(Application.dataPath) ?? "", rootRel));

            bool overwriteAll = false;
            bool noOverwriteAll = false;

            foreach (var n in doc.root.SelfAndDescendants())
            {
                // HasImage covers image / button / input / scroll / slider /
                // toggle / bg / icon / mask / panel / progress / item / fx —
                // every type that the importer attaches a UGUI Image to.
                if (!n.HasImage || string.IsNullOrEmpty(n.imageFile)) continue;

                // Python now writes PNGs as just the layer name, so the
                // source filename is the layer name + ".png".
                var srcPath = Path.Combine(jsonDir, n.imageFile).Replace('\\', '/');
                var fileName = Path.GetFileName(n.imageFile);

                // Destination: <imageOutputRoot>/<psdName>/<fileName>
                // This is the "Root" folder the user asked for, with one
                // subfolder per PSD source file.
                var dstRel = $"{rootRel}/{psdName}/{fileName}";
                var dstAbs = Path.Combine(rootAbs, psdName, fileName)
                                    .Replace('\\', '/');

                if (!File.Exists(srcPath))
                {
                    Debug.LogWarning(
                        $"[PSDImporter] Source PNG missing: '{srcPath}' (for layer '{n.id}'). " +
                        "Skipping — Python tool may not have written it yet.");
                    continue;
                }

                // If the user already decided this layer's fate in the
                // ImageConflictResolverWindow, honor it without a popup.
                if (manualResolutions != null
                    && manualResolutions.TryGetValue(n.id, out var overwrite))
                {
                    var existingExists = File.Exists(dstAbs);
                    if (overwrite)
                    {
                        Directory.CreateDirectory(Path.GetDirectoryName(dstAbs) ?? "");
                        File.Copy(srcPath, dstAbs, overwrite: true);
                        stats.Add(existingExists
                            ? ImageCopyDecision.Overwritten
                            : ImageCopyDecision.Copied);
                    }
                    else
                    {
                        if (existingExists)
                        {
                            stats.Add(ImageCopyDecision.SkippedByUser);
                        }
                        else
                        {
                            // No existing file — we still need the image
                            // for the prefab, so copy it.
                            Directory.CreateDirectory(Path.GetDirectoryName(dstAbs) ?? "");
                            File.Copy(srcPath, dstAbs, overwrite: false);
                            stats.Add(ImageCopyDecision.Copied);
                        }
                    }
                    s_imagePathOverride[n.id] = dstRel;
                    continue;
                }

                // No pre-decision — fall back to the legacy per-file
                // yes/no/yes-to-all dialog.
                var newHash = Sha256OfFile(srcPath);
                if (TryCopyOrPrompt(srcPath, dstAbs, newHash, ref overwriteAll, ref noOverwriteAll, out var decision))
                {
                    s_imagePathOverride[n.id] = dstRel;
                    stats.Add(decision);
                }
                // else: user said "no" — leave existing file in place AND
                //       don't bind this image to the prefab.
            }
            AssetDatabase.Refresh();

            // If the user wants us to clean up the Python tool's working
            // folder, drop the source PNGs (Unity already has its own
            // copies in imageOutputRoot). Keep the JSON and cache so
            // incremental re-imports still work.
            var activeSettings = GetActiveSettings();
            if (activeSettings != null && activeSettings.deleteSourceImagesAfterImport)
            {
                stats.sourceCleanedUp = CleanupPythonOutput(jsonPath, activeSettings);
            }

            // Configure 9-slice borders on any image whose node has
            // `slice` metadata. The PNGs were just imported (or
            // refreshed) above, so TextureImporter is available now.
            ConfigureSlicedSprites(doc);

            return stats;
        }

        /// <summary>
        /// For every image-bearing node with `slice` metadata, set the
        /// Sprite's border on the TextureImporter. This is what makes
        /// the Sprite a 9-slice — the actual `type=Sliced` on the
        /// Image component is set in AttachImageComponent.
        /// </summary>
        private static void ConfigureSlicedSprites(PsdDocument doc)
        {
            int configured = 0;
            foreach (var n in doc.root.SelfAndDescendants())
            {
                // Same fix as in AttachImageComponent: Unity JsonUtility
                // constructs a default PsdSlice for any class-typed field
                // missing from the JSON, so a null-check alone would
                // "configure" every PNG as 9-slice.
                if (n.slice == null) continue;
                if ((n.slice.l | n.slice.t | n.slice.r | n.slice.b) == 0) continue;
                if (!s_imagePathOverride.TryGetValue(n.id, out var dstRel)) continue;
                if (ConfigureSlicedSprite(dstRel, n.slice))
                    configured++;
            }
            if (configured > 0)
            {
                Debug.Log($"[PSDImporter] Configured 9-slice borders on {configured} sprite(s).");
            }
        }

        /// <summary>
        /// Set the spriteBorder on a single TextureImporter. Returns
        /// true if the importer was actually modified and reimported.
        /// </summary>
        private static bool ConfigureSlicedSprite(string assetPath, PsdSlice slice)
        {
            if (string.IsNullOrEmpty(assetPath) || slice == null) return false;
            var importer = AssetImporter.GetAtPath(assetPath) as TextureImporter;
            if (importer == null)
            {
                Debug.LogWarning(
                    $"[PSDImporter] No TextureImporter for '{assetPath}' — " +
                    "could not set 9-slice border.");
                return false;
            }
            // Unity's spriteBorder is Vector4(L, B, R, T) in pixels.
            var border = new Vector4(slice.l, slice.b, slice.r, slice.t);
            // Skip the reimport if nothing actually changed.
            if (importer.textureType == TextureImporterType.Sprite
                && importer.spriteImportMode == SpriteImportMode.Single
                && importer.spriteBorder == border)
            {
                return false;
            }
            importer.textureType      = TextureImporterType.Sprite;
            importer.spriteImportMode = SpriteImportMode.Single;
            importer.spriteBorder     = border;
            importer.SaveAndReimport();
            return true;
        }

        /// <summary>
        /// Walk the document and find every image-bearing layer whose
        /// destination file already exists AND has a different sha256
        /// from the new PNG. Returned list is empty when there are no
        /// conflicts (caller can skip opening the resolver UI in that
        /// case). Used by the conflict resolver window to show the user
        /// a preview of every diff before deciding.
        /// </summary>
        public static List<ImageConflictResolverWindow.ImageConflict> PreScanImageConflicts(
            PsdDocument doc, string jsonPath, string imageOutputRoot)
        {
            var result = new List<ImageConflictResolverWindow.ImageConflict>();
            if (doc == null) return result;
            var jsonDir = Path.GetDirectoryName(Path.GetFullPath(jsonPath)) ?? "";
            // Match the destination folder used by SetImagePathResolver
            // — they have to agree, or the conflict list points at the
            // wrong files.
            var psdName = ResolveClassName(doc, GetActiveSettings());
            var rootRel = imageOutputRoot.Replace('\\', '/').TrimEnd('/');
            var rootAbs = Path.GetFullPath(
                Path.Combine(Path.GetDirectoryName(Application.dataPath) ?? "", rootRel));

            int scanned = 0, srcMissing = 0, dstMissing = 0, identical = 0;

            foreach (var n in doc.root.SelfAndDescendants())
            {
                if (!n.HasImage || string.IsNullOrEmpty(n.imageFile)) continue;
                scanned++;
                var srcPath = Path.Combine(jsonDir, n.imageFile).Replace('\\', '/');
                var fileName = Path.GetFileName(n.imageFile);
                var dstRel = $"{rootRel}/{psdName}/{fileName}";
                var dstAbs = Path.Combine(rootAbs, psdName, fileName)
                                    .Replace('\\', '/');

                if (!File.Exists(srcPath)) { srcMissing++; continue; }
                if (!File.Exists(dstAbs)) { dstMissing++; continue; }

                var newHash = Sha256OfFile(srcPath);
                var existingHash = Sha256OfFile(dstAbs);
                if (newHash == existingHash) { identical++; continue; }  // same content → not a conflict

                result.Add(new ImageConflictResolverWindow.ImageConflict
                {
                    layerId           = n.id,
                    layerName         = n.name,
                    psdName           = psdName,
                    newImagePath      = srcPath,
                    existingImagePath = dstAbs,
                    newSizeBytes      = (int)new FileInfo(srcPath).Length,
                    existingSizeBytes = (int)new FileInfo(dstAbs).Length,
                    // Read pixel dimensions straight from the PNG header —
                    // much cheaper than LoadImage() and good enough for the
                    // "size changed" warning the user wants to see.
                    newWidth          = PngDimensions(srcPath).w,
                    newHeight         = PngDimensions(srcPath).h,
                    existingWidth     = PngDimensions(dstAbs).w,
                    existingHeight    = PngDimensions(dstAbs).h,
                    newHash           = ShortHash(newHash),
                    existingHash      = ShortHash(existingHash),
                });
            }

            Debug.Log(
                $"[PSDImporter] PreScanImageConflicts: scanned={scanned} " +
                $"srcMissing={srcMissing} dstMissing={dstMissing} " +
                $"existingIdentical={identical} → {result.Count} conflict(s) to review");
            return result;
        }

        private static string ShortHash(string full) =>
            full.Length >= 22 ? full.Substring(0, 22) : full;

        /// <summary>
        /// Delete the source PNGs the Python tool wrote under
        /// <psdExportRoot>/<psdName>/images/. The JSON and cache stay
        /// (needed for incremental re-imports).
        /// </summary>
        public static int CleanupPythonOutput(string jsonPath, PSDImporterSettings settings, ImageCopyStats stats = null)
        {
            if (string.IsNullOrEmpty(jsonPath) || settings == null) return 0;
            var jsonDir = Path.GetDirectoryName(Path.GetFullPath(jsonPath));
            if (string.IsNullOrEmpty(jsonDir) || !Directory.Exists(jsonDir)) return 0;

            // The Python tool writes the layout like:
            //   <psdExportRoot>/<psdName>/<psdName>.json
            //   <psdExportRoot>/<psdName>/_psd_cache.json
            //   <psdExportRoot>/<psdName>/images/*.png
            //
            // We only nuke the images/ subdir; the JSON and cache stay.
            var imagesDir = Path.Combine(jsonDir, "images");
            if (!Directory.Exists(imagesDir)) return 0;

            int deleted = 0;
            try
            {
                foreach (var f in Directory.GetFiles(imagesDir))
                {
                    try
                    {
                        File.Delete(f);
                        deleted++;
                    }
                    catch (Exception e)
                    {
                        Debug.LogWarning($"[PSDImporter] Could not delete {f}: {e.Message}");
                    }
                }
                // Remove the (now empty) images/ folder itself.
                if (Directory.Exists(imagesDir)
                    && Directory.GetFileSystemEntries(imagesDir).Length == 0)
                {
                    Directory.Delete(imagesDir);
                }
            }
            catch (Exception e)
            {
                Debug.LogWarning($"[PSDImporter] Cleanup failed for {imagesDir}: {e.Message}");
            }

            if (deleted > 0)
            {
                Debug.Log($"[PSDImporter] Cleaned up {deleted} source PNG(s) from {imagesDir}");
                if (stats != null)
                {
                    // Surface the count in the import report so the user
                    // sees it in the EditorWindow.
                    // (Reusing 'overwritten' as "files cleaned up" is a bit
                    //  of a stretch, but we don't have a dedicated field
                    //  and overwriting count is conceptually adjacent.)
                }
            }
            return deleted;
        }

        // ─────────────────────────────────────────────────────────────
        //  Image copy / duplicate handling
        // ─────────────────────────────────────────────────────────────

        public enum ImageCopyDecision { Copied, Overwritten, SkippedSame, SkippedByUser }

        public class ImageCopyStats
        {
            public int copied;
            public int overwritten;
            public int skippedSameContent;
            public int skippedByUser;
            public int sourceCleanedUp;     // PNGs deleted from psdExportRoot after copy

            public void Add(ImageCopyDecision d)
            {
                switch (d)
                {
                    case ImageCopyDecision.Copied:            copied++;            break;
                    case ImageCopyDecision.Overwritten:       overwritten++;       break;
                    case ImageCopyDecision.SkippedSame:       skippedSameContent++; break;
                    case ImageCopyDecision.SkippedByUser:     skippedByUser++;     break;
                }
            }

            public override string ToString() =>
                $"copied={copied} overwritten={overwritten} " +
                $"skippedSame={skippedSameContent} skippedByUser={skippedByUser} " +
                $"sourceCleaned={sourceCleanedUp}";
        }

        /// <summary>
        /// Copy `src` to `dst` if the destination is missing, identical,
        /// or the user says yes. Returns false if the user said no.
        /// </summary>
        private static bool TryCopyOrPrompt(
            string src, string dst, string newHash,
            ref bool overwriteAll, ref bool noOverwriteAll,
            out ImageCopyDecision decision)
        {
            // Case 1: no existing file → just copy.
            if (!File.Exists(dst))
            {
                Directory.CreateDirectory(Path.GetDirectoryName(dst) ?? "");
                File.Copy(src, dst, overwrite: false);
                decision = ImageCopyDecision.Copied;
                return true;
            }

            // Case 2: existing file has identical content → skip silently.
            var existingHash = Sha256OfFile(dst);
            if (existingHash == newHash)
            {
                decision = ImageCopyDecision.SkippedSame;
                return true;
            }

            // Case 3: existing file has different content. Honor prior
            // "Yes to all" / "No to all" choices for this import.
            if (overwriteAll)
            {
                File.Copy(src, dst, overwrite: true);
                decision = ImageCopyDecision.Overwritten;
                return true;
            }
            if (noOverwriteAll)
            {
                decision = ImageCopyDecision.SkippedByUser;
                return false;
            }

            // Ask the user.
            int choice = EditorUtility.DisplayDialogComplex(
                title:   "Image already exists",
                message: $"'{Path.GetFileName(dst)}' already exists and is different from the new image.\n\n" +
                         $"Existing: {existingHash.Substring(0, 16)}…  ({new FileInfo(dst).Length / 1024} KB)\n" +
                         $"New:      {newHash.Substring(0, 16)}…  ({new FileInfo(src).Length / 1024} KB)\n\n" +
                         "Overwrite?",
                ok:      "Yes",
                cancel:  "No",
                alt:     "Yes to all");

            switch (choice)
            {
                case 0: // Yes
                    File.Copy(src, dst, overwrite: true);
                    decision = ImageCopyDecision.Overwritten;
                    return true;
                case 1: // No
                    decision = ImageCopyDecision.SkippedByUser;
                    return false;
                case 2: // Yes to all
                    overwriteAll = true;
                    File.Copy(src, dst, overwrite: true);
                    decision = ImageCopyDecision.Overwritten;
                    return true;
            }
            decision = ImageCopyDecision.SkippedByUser;
            return false;
        }

        private static string Sha256OfFile(string path)
        {
            using (var sha = SHA256.Create())
            using (var fs = File.OpenRead(path))
            {
                var hash = sha.ComputeHash(fs);
                return "sha256:" + BitConverter.ToString(hash).Replace("-", "").ToLowerInvariant();
            }
        }

        /// <summary>
        /// Read PNG width/height from the file header without decoding
        /// the image. PNG layout: 8-byte magic, then IHDR chunk
        /// (4 bytes length, 4 bytes "IHDR", 4 bytes width, 4 bytes
        /// height — all big-endian). Returns (0, 0) for non-PNG or
        /// truncated files; the caller can decide to fall back to
        /// LoadImage.
        /// </summary>
        private static (int w, int h) PngDimensions(string path)
        {
            try
            {
                using (var fs = File.OpenRead(path))
                {
                    var buf = new byte[24];
                    int read = fs.Read(buf, 0, 24);
                    if (read < 24) return (0, 0);
                    // Magic: 89 50 4E 47 0D 0A 1A 0A
                    if (buf[0] != 0x89 || buf[1] != 0x50 || buf[2] != 0x4E || buf[3] != 0x47)
                        return (0, 0);
                    // IHDR chunk length (bytes 8..11) is irrelevant; the
                    // type "IHDR" is bytes 12..15; width is bytes 16..19
                    // and height is bytes 20..23, both big-endian.
                    int w = (buf[16] << 24) | (buf[17] << 16) | (buf[18] << 8) | buf[19];
                    int h = (buf[20] << 24) | (buf[21] << 16) | (buf[22] << 8) | buf[23];
                    return (w, h);
                }
            }
            catch
            {
                return (0, 0);
            }
        }
    }
}
