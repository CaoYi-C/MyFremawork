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
        /// Per-PSD prefab-name override must be passed explicitly via
        /// the four-arg Import(...) overload.
        /// </summary>
        public static ImportReport Import(string jsonPath, PSDImporterSettings settings)
            => Import(jsonPath, settings, settings != null && settings.autoGenerateUIBind, null);

        /// <summary>
        /// Backwards-compatible three-arg overload: no per-PSD override
        /// supplied, falls through to the PSD file name.
        /// </summary>
        public static ImportReport Import(string jsonPath, PSDImporterSettings settings, bool generateUIBind)
            => Import(jsonPath, settings, generateUIBind, null);

        /// <summary>
        /// Run the import, with explicit overrides for UIBind code
        /// generation AND the prefab name. Use this when the caller
        /// (e.g. the Editor window) collects per-import inputs from the
        /// user — a UIBind checkbox, and a prefab-name override field
        /// on each PSD row.
        /// </summary>
        public static ImportReport Import(
            string jsonPath, PSDImporterSettings settings,
            bool generateUIBind, string prefabNameOverride)
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

            // The "fullyUnchanged" path is fast but it can be wrong in
            // two ways. Force a rebuild when:
            //   (a) the user manually deleted the generated prefab
            //       between imports — cache + JSON are unchanged so the
            //       diff says "skip" but the user clearly wants the
            //       prefab back; OR
            //   (b) the per-PSD prefab-name override changed since
            //       last import — the JSON/PSD hash hasn't moved
            //       (diff.fullyUnchanged is true), but the new name
            //       points at a different prefab path that has never
            //       been written. The old prefab at the old path is
            //       left alone; the new path is created fresh.
            // In both cases the existing lastImportedPrefabPath is now
            // stale — we still want to compare against it for the
            // "file missing" check.
            var stalePathMissing = !string.IsNullOrEmpty(prevCache.lastImportedPrefabPath)
                && !File.Exists(Path.GetFullPath(
                    Path.Combine(
                        Path.GetDirectoryName(Application.dataPath) ?? "",
                        prevCache.lastImportedPrefabPath)));
            if (diff.fullyUnchanged && stalePathMissing)
            {
                Debug.Log(
                    $"[PSDImporter] '{doc.sourcePsd.name}' content unchanged, " +
                    $"but '{prevCache.lastImportedPrefabPath}' is missing " +
                    "on disk — forcing a rebuild.");
                diff.fullyUnchanged = false;
            }

            // Derive class name early — the override-change detection
            // below needs it, and the rest of the import (prefab path,
            // NodeProvider / Window class names, UIBindData asset,
            // image subfolder) all use the same value. The per-PSD
            // override (set on each row of the importer window) wins,
            // so two PSDs in one batch can land as different prefab
            // names. When no override is supplied, the PSD file name
            // is used.
            var className = ResolveClassName(doc, settings, prefabNameOverride);
            report.providerClassName = className + "NodeProvider";
            report.windowClassName   = className + "Window";

            // Per-PSD prefab-name override change. The cache's
            // lastImportedPrefabPath encodes its OWN class name as
            // <root>/<oldName>/<oldName>.prefab — extracting <oldName>
            // from that path lets us detect a name change cheaply
            // (avoids re-running SanitizeClassName on the path).
            if (diff.fullyUnchanged
                && !string.IsNullOrEmpty(prefabNameOverride)
                && !string.IsNullOrEmpty(prevCache.lastImportedPrefabPath))
            {
                var oldName = ExtractClassNameFromPrefabPath(
                    prevCache.lastImportedPrefabPath);
                if (!string.IsNullOrEmpty(oldName)
                    && oldName != className)
                {
                    Debug.Log(
                        $"[PSDImporter] '{doc.sourcePsd.name}' content unchanged, " +
                        $"but per-PSD prefab-name override changed " +
                        $"'{oldName}' → '{className}' — forcing a rebuild " +
                        $"so the new prefab is written to " +
                        $"<prefabOutputRoot>/{className}/{className}.prefab.");
                    diff.fullyUnchanged = false;
                }
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
            // which aborts the entire import. The same className is
            // threaded through so the resolver looks at the right
            // subfolder.
            var conflicts = PreScanImageConflicts(
                doc, jsonPath, imageOutputRoot, className);
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
            // non-conflicting image is copied normally. The className
            // is threaded through so the image goes to the right
            // subfolder (same name as the prefab + UIBind classes).
            var imageStats = SetImagePathResolver(
                doc, jsonPath, imageOutputRoot, imageResolutions, className);
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

            // Open the prefab in the editor so the user can see it immediately.
            OpenPrefab(prefabPath);

            return report;
        }

        /// <summary>
        /// Open a prefab asset in the Prefab Stage. Safe to call multiple
        /// times — only the first valid prefab will be opened.
        /// </summary>
        private static void OpenPrefab(string prefabPath)
        {
            if (string.IsNullOrEmpty(prefabPath)) return;
            var prefab = AssetDatabase.LoadAssetAtPath<GameObject>(prefabPath);
            if (prefab == null)
            {
                Debug.LogWarning($"[PSDImporter] Prefab not found for opening: {prefabPath}");
                return;
            }
            PrefabStageUtility.OpenPrefab(prefabPath);
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

            // Strip 9-slice suffix from the GameObject name so the prefab
            // shows a clean name (e.g. "img_bagBg" instead of
            // "img_bagBg_9slice_10_10_10_10").
            var displayName = node.name;
            var sliceMatch = System.Text.RegularExpressions.Regex.Match(
                displayName, @"^(.*)_9slice(_\d+_\d+_\d+_\d+)?$");
            if (sliceMatch.Success)
                displayName = sliceMatch.Groups[1].Value;

            var go = new GameObject(displayName, typeof(RectTransform));
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
            type == "button";

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
            if (string.IsNullOrEmpty(node.imageFile))
            {
                // 9-slice nodes have empty imageFile — try to find a
                // matching sprite by logical name (e.g. "img_bagBg_9slice"
                // → "bagBg.png" exported by an "export_bagBg" layer).
                if (node.slice != null && (node.slice.l | node.slice.t | node.slice.r | node.slice.b) != 0)
                {
                    return LoadSpriteByLogicalName(node, doc);
                }
                return null;
            }
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

        /// <summary>
        /// For 9-slice nodes that have no imageFile, search for a
        /// matching sprite by logical name (prefix + 9-slice suffix
        /// stripped).  e.g. "img_bagBg_9slice_10_10_10_10" → looks for
        /// "bagBg.png" in the image output root.
        /// </summary>
        private static Sprite LoadSpriteByLogicalName(PsdNode node, PsdDocument doc)
        {
            var logical = PsdNaming.LogicalImageName(node.name);
            if (string.IsNullOrEmpty(logical)) return null;

            var settings = GetActiveSettings();
            if (settings == null) return null;
            var imageRoot = settings.imageOutputRoot;
            if (string.IsNullOrEmpty(imageRoot)) return null;

            // Derive subfolder from PSD filename (same as SetImagePathResolver).
            var psdName = ResolveClassName(doc, settings);
            var searchDir = Path.Combine(imageRoot, psdName).Replace('\\', '/');

            // Convert Assets-relative to absolute for Directory.GetFiles.
            var absDir = Path.GetFullPath(Path.Combine(
                Path.GetDirectoryName(Application.dataPath) ?? "", searchDir));
            if (!Directory.Exists(absDir))
            {
                Debug.LogWarning($"[PSDImporter] 9-slice '{node.id}': " +
                     $"image dir not found: {searchDir}");
                return null;
            }

            var dataPath = Application.dataPath.Replace('\\', '/');
            foreach (var file in Directory.GetFiles(absDir, "*.png"))
            {
                var fileBase = Path.GetFileNameWithoutExtension(file);
                if (!string.Equals(fileBase, logical, StringComparison.OrdinalIgnoreCase))
                    continue;

                // Convert absolute path back to Assets-relative.
                var assetPath = file.Replace('\\', '/');
                if (assetPath.StartsWith(dataPath, StringComparison.OrdinalIgnoreCase))
                    assetPath = "Assets" + assetPath.Substring(dataPath.Length);

                var sprite = AssetDatabase.LoadAssetAtPath<Sprite>(assetPath);
                if (sprite != null)
                {
                    Debug.Log($"[PSDImporter] 9-slice '{node.id}' auto-matched " +
                  $"sprite '{assetPath}' by logical name '{logical}'");
                    return sprite;
                }
            }

            Debug.LogWarning($"[PSDImporter] 9-slice '{node.id}': no matching " +
                 $"sprite for '{logical}' in {searchDir}. " +
                 $"Add an 'export_{logical}' layer to the PSD.");
            return null;
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

        // Public so the importer window can compute the predicted
        // prefab name for display ("→ 将生成: Assets/.../LoginView/..."),
        // matching exactly what the import path will produce. Window
        // doesn't write prefabs — it just shows the user what to
        // expect before they click Import.
        public static string SanitizeClassName(string s)
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

        // Pull the <className> out of a stored prefab path
        // "<prefabOutputRoot>/<className>/<className>.prefab". Used
        // by the importer itself to detect a per-PSD prefab-name
        // override change without re-running SanitizeClassName
        // (which would mask differences — "My View" and "MyView"
        // sanitize to the same string). Also used by the Window to
        // pre-fill the per-PSD override input from the last import's
        // prefab path — making it public lets the Window reuse the
        // exact same parser, so the two views can never disagree on
        // what the "current class name" is. The parent folder name
        // is what we trust, because the importer always writes
        // <name>/<name>.prefab.
        public static string ExtractClassNameFromPrefabPath(string prefabPath)
        {
            if (string.IsNullOrEmpty(prefabPath)) return "";
            // Normalize separators so this works whether the cache
            // was written on Windows or macOS.
            var norm = prefabPath.Replace('\\', '/');
            var file = Path.GetFileNameWithoutExtension(norm);
            if (string.IsNullOrEmpty(file)) return "";
            var dir = Path.GetDirectoryName(norm);
            if (string.IsNullOrEmpty(dir)) return "";
            var parent = Path.GetFileName(dir);
            if (string.IsNullOrEmpty(parent)) return "";
            // Convention is <name>/<name>.prefab — if the filename
            // doesn't match the parent folder, the path was written
            // by an older tool version or hand-edited; fall back to
            // the parent (subfolder name) since that's what the new
            // build will use anyway.
            return file == parent ? file : parent;
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
        ///   1. <c>prefabNameOverride</c> argument — supplied per-call
        ///      from the importer window (each PSD row carries its own
        ///      override, so two PSDs in one batch can land as
        ///      different prefab names).
        ///   2. Otherwise the PSD file name (without extension).
        /// </summary>
        private static string ResolveClassName(
            PsdDocument doc, PSDImporterSettings settings,
            string prefabNameOverride = null)
        {
            if (!string.IsNullOrWhiteSpace(prefabNameOverride))
            {
                return SanitizeClassName(prefabNameOverride.Trim());
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
            Dictionary<string, bool> manualResolutions = null,
            string className = null)
        {
            var stats = new ImageCopyStats();
            s_imagePathOverride = new Dictionary<string, string>();
            var jsonDir = Path.GetDirectoryName(Path.GetFullPath(jsonPath)) ?? "";
            // Use the same name the importer will use for the prefab
            // subfolder + class name. Callers should pass the already-
            // resolved className; the fallback re-resolves from
            // settings so batch callers that go straight to this
            // helper (e.g. legacy menu items) still get a stable name.
            var psdName = !string.IsNullOrEmpty(className)
                ? className
                : ResolveClassName(doc, GetActiveSettings());

            // imageOutputRoot is something like "Assets/PSDImages" — make
            // sure both halves agree on the separator style.
            var rootRel = imageOutputRoot.Replace('\\', '/').TrimEnd('/');
            var rootAbs = Path.GetFullPath(
                Path.Combine(Path.GetDirectoryName(Application.dataPath) ?? "", rootRel));

            bool overwriteAll = false;
            bool noOverwriteAll = false;

            // Index of every existing PNG under imageOutputRoot, keyed
            // by filename. We need it because the user might decide to
            // "keep" an existing image, but the existing copy could
            // live in another subfolder (e.g. <root>/<SomeOtherPsd>/close.png)
            // — we have to point the prefab's image reference at THAT
            // file, otherwise the prefab ends up with a blank Image.
            var existingIndex = BuildExistingPngIndex(rootAbs, false, 0f, 0f);

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
                    // Source PNG is missing — usually because Python
                    // wrote the export to a different folder than
                    // psdExportRoot (the user might have pointed
                    // imageOutputRoot at the same place they configured
                    // the Python tool, or the PSD was hand-edited).
                    // Fall back to: is there a same-named PNG anywhere
                    // in imageOutputRoot that we can use as the
                    // prefab's image source?
                    if (existingIndex.TryGetValue(fileName, out var fallbackHits)
                        && fallbackHits.Count > 0)
                    {
                        var fallbackAbs = fallbackHits[0].path;
                        var fallbackRel = MakeProjectRelative(
                            fallbackAbs, rootAbs, rootRel);
                        s_imagePathOverride[n.id] = fallbackRel;
                        stats.Add(ImageCopyDecision.SkippedByUser);
                        Debug.LogWarning(
                            $"[PSDImporter] Source PNG missing for layer '{n.id}' " +
                            $"('{srcPath}'). Binding prefab to existing " +
                            $"image at '{fallbackRel}' instead.");
                        continue;
                    }
                    Debug.LogWarning(
                        $"[PSDImporter] Source PNG missing: '{srcPath}' (for layer '{n.id}'). " +
                        "Skipping — Python tool may not have written it yet, " +
                        "and no fallback copy exists under imageOutputRoot.");
                    continue;
                }

                // Compute the new PNG's hash once, then find any existing
                // same-named file in the whole imageOutputRoot tree. The
                // "any same-content sibling" path is the one we'll bind
                // the prefab to if the destination subfolder doesn't
                // already have a usable file.
                var newHash = Sha256OfFile(srcPath);
                string sameContentSiblingAbs = null;  // absolute path of a
                                                     // PNG elsewhere in the
                                                     // tree with identical
                                                     // content (sha match)
                List<(string path, string hash)> sameNameHits = null;
                if (existingIndex.TryGetValue(fileName, out sameNameHits))
                {
                    foreach (var (p, h) in sameNameHits)
                    {
                        if (h == newHash && p != dstAbs)
                        {
                            sameContentSiblingAbs = p;
                            break;
                        }
                    }
                }

                // Fast path: if a same-content copy already exists
                // anywhere under imageOutputRoot (typically a sibling
                // subfolder from a previous PSD import), bind the
                // prefab to it directly and skip both the resolver
                // window and the legacy yes/no prompt. The point of
                // imageOutputRoot is "deduped image set" — re-copying
                // a byte-identical PNG into this PSD's own subfolder
                // just bloats Assets/ and breaks the dedup contract.
                // (We still let the resolver / prompt run when the
                // sibling's content actually differs from the new
                // export, because that's a real conflict the user
                // should see.)
                if (sameContentSiblingAbs != null)
                {
                    var siblingRel = MakeProjectRelative(
                        sameContentSiblingAbs, rootAbs, rootRel);
                    s_imagePathOverride[n.id] = siblingRel;
                    stats.Add(ImageCopyDecision.SkippedByUser);
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
                        s_imagePathOverride[n.id] = dstRel;
                    }
                    else
                    {
                        // User wants to keep whatever was there. Three
                        // sub-cases:
                        //   1) Destination already has identical content
                        //      → no copy, dstRel points at the existing
                        //        dst file (the prefab will reuse it).
                        //   2) Destination has a different file (or no
                        //      file) but a sibling under another PSD
                        //      folder has identical content → bind the
                        //        prefab to that sibling. The new PSD
                        //        subfolder doesn't get a copy; the
                        //        existing sibling does the job.
                        //   3) Nothing matches anywhere → we still need
                        //      the image, so copy it.
                        if (existingExists && Sha256OfFile(dstAbs) == newHash)
                        {
                            stats.Add(ImageCopyDecision.SkippedByUser);
                            s_imagePathOverride[n.id] = dstRel;
                        }
                        else if (sameContentSiblingAbs != null)
                        {
                            stats.Add(ImageCopyDecision.SkippedByUser);
                            // Translate the absolute path back to a
                            // project-relative Asset path so Unity's
                            // AssetDatabase can find it.
                            var siblingRel = MakeProjectRelative(
                                sameContentSiblingAbs, rootAbs, rootRel);
                            s_imagePathOverride[n.id] = siblingRel;
                        }
                        else
                        {
                            Directory.CreateDirectory(Path.GetDirectoryName(dstAbs) ?? "");
                            File.Copy(srcPath, dstAbs, overwrite: false);
                            stats.Add(ImageCopyDecision.Copied);
                            s_imagePathOverride[n.id] = dstRel;
                        }
                    }
                    continue;
                }

                // No pre-decision — fall back to the legacy per-file
                // yes/no/yes-to-all dialog.
                if (TryCopyOrPrompt(srcPath, dstAbs, newHash, ref overwriteAll, ref noOverwriteAll, out var decision))
                {
                    s_imagePathOverride[n.id] = dstRel;
                    stats.Add(decision);
                }
                else
                {
                    // User said "no" via the legacy dialog — same
                    // "find a sibling to bind to" treatment as the
                    // resolver-window "keep" path, so the prefab
                    // doesn't end up with a blank image.
                    if (sameContentSiblingAbs != null)
                    {
                        var siblingRel = MakeProjectRelative(
                            sameContentSiblingAbs, rootAbs, rootRel);
                        s_imagePathOverride[n.id] = siblingRel;
                    }
                    // else: no sibling — fall through with no entry;
                    // BuildPrefab will see a missing id and emit a
                    // null Image sprite (still logged as a warning).
                }
            }

            // Copy orphan PNGs: images written by the Python tool that
            // aren't referenced by any JSON node (e.g. export_ prefix).
            // These sprites are meant to be used directly by other UI.
            CopyOrphanExportImages(jsonDir, rootAbs, rootRel, psdName, doc,
                ref overwriteAll, ref noOverwriteAll, stats);

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
                if (n.slice == null) continue;
                if ((n.slice.l | n.slice.t | n.slice.r | n.slice.b) == 0) continue;

                // Try the normal override path first (node has imageFile).
                if (s_imagePathOverride.TryGetValue(n.id, out var dstRel)
                    && !string.IsNullOrEmpty(dstRel))
                {
                    if (ConfigureSlicedSprite(dstRel, n.slice))
                        configured++;
                    continue;
                }

                // 9-slice node with no imageFile — find the matching
                // sprite by logical name (same as LoadSpriteByLogicalName).
                var logical = PsdNaming.LogicalImageName(n.name);
                if (string.IsNullOrEmpty(logical)) continue;

                var settings = GetActiveSettings();
                if (settings == null) continue;
                var imageRoot = settings.imageOutputRoot;
                var psdName = ResolveClassName(doc, settings);
                var searchDir = Path.Combine(imageRoot, psdName).Replace('\\', '/');

                var absDir = Path.GetFullPath(Path.Combine(
                    Path.GetDirectoryName(Application.dataPath) ?? "", searchDir));
                if (!Directory.Exists(absDir)) continue;

                var dataPath = Application.dataPath.Replace('\\', '/');
                foreach (var file in Directory.GetFiles(absDir, "*.png"))
                {
                    var fileBase = Path.GetFileNameWithoutExtension(file);
                    if (!string.Equals(fileBase, logical, StringComparison.OrdinalIgnoreCase))
                        continue;

                    var assetPath = file.Replace('\\', '/');
                    if (assetPath.StartsWith(dataPath, StringComparison.OrdinalIgnoreCase))
                        assetPath = "Assets" + assetPath.Substring(dataPath.Length);

                    if (ConfigureSlicedSprite(assetPath, n.slice))
                        configured++;
                    break;
                }
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
        /// PNG would overwrite an EXISTING file in the image output root
        /// with different content.
        ///
        /// Important: the scan covers the ENTIRE <imageOutputRoot>/ tree,
        /// not just the destination subfolder for this PSD. The reason:
        /// a PNG named "close.png" might already live in
        /// <root>/<SomeOtherPsd>/close.png from a previous import of a
        /// different PSD, and the user would reasonably want to know
        /// "you're about to write a file that already exists" even if
        /// the target subfolder is empty.
        ///
        /// The list is empty when there are no conflicts (caller should
        /// skip opening the resolver UI in that case). Used by the
        /// conflict resolver window to show the user a preview of every
        /// diff before deciding.
        /// </summary>
        public static List<ImageConflictResolverWindow.ImageConflict> PreScanImageConflicts(
            PsdDocument doc, string jsonPath, string imageOutputRoot,
            string className = null)
        {
            var result = new List<ImageConflictResolverWindow.ImageConflict>();
            if (doc == null) return result;
            var jsonDir = Path.GetDirectoryName(Path.GetFullPath(jsonPath)) ?? "";
            // Same convention as SetImagePathResolver: prefer the
            // caller-supplied className, fall back to resolving from
            // global settings.
            var psdName = !string.IsNullOrEmpty(className)
                ? className
                : ResolveClassName(doc, GetActiveSettings());
            var rootRel = imageOutputRoot.Replace('\\', '/').TrimEnd('/');
            var rootAbs = Path.GetFullPath(
                Path.Combine(Path.GetDirectoryName(Application.dataPath) ?? "", rootRel));

            // First pass: collect every new image's content hash. The
            // count drives a progress bar so the user isn't staring at
            // a frozen dialog when the PSD has hundreds of layers.
            var newImages = new List<(string fileName, string srcPath, string hash)>();
            int scanned = 0, srcMissing = 0;
            foreach (var n in doc.root.SelfAndDescendants())
            {
                if (!n.HasImage || string.IsNullOrEmpty(n.imageFile)) continue;
                scanned++;
                var srcPath = Path.Combine(jsonDir, n.imageFile).Replace('\\', '/');
                if (!File.Exists(srcPath)) { srcMissing++; continue; }
                var hash = Sha256OfFile(srcPath);
                var fileName = Path.GetFileName(n.imageFile);
                newImages.Add((fileName, srcPath, hash));
            }

            // Build the existing-PNG index once. key = filename,
            // value = list of (fullPath, hash) under <imageOutputRoot>/.
            // A file can appear under multiple subfolders (one per
            // PSD that imported it), so we keep all hits.
            // We also build a per-(filename,hash) set so a same-content
            // file (already imported by this same PSD last time, or by
            // another PSD that produced the same bytes) doesn't show up
            // as a conflict.
            const int PROGRESS_THRESHOLD = 50;
            var useProgressBar = scanned >= PROGRESS_THRESHOLD;
            try
            {
                if (useProgressBar)
                    EditorUtility.DisplayProgressBar("PSD Importer",
                        "扫描现有图片…", 0f);

                var existingIndex = BuildExistingPngIndex(rootAbs, useProgressBar,
                    0.0f, 0.5f);

                if (useProgressBar)
                    EditorUtility.DisplayProgressBar("PSD Importer",
                        "比对图片…", 0.5f);

                int identical = 0, compareIndex = 0;
                foreach (var (fileName, srcPath, newHash) in newImages)
                {
                    compareIndex++;
                    if (useProgressBar)
                    {
                        EditorUtility.DisplayProgressBar("PSD Importer",
                            $"比对图片 ({compareIndex}/{newImages.Count})…",
                            0.5f + 0.5f * (compareIndex / (float)newImages.Count));
                    }

                    if (!existingIndex.TryGetValue(fileName, out var hits))
                        continue;   // no existing PNG with this name → safe to write

                    // Find any existing file with the SAME content → no
                    // conflict. Otherwise, the FIRST existing file with
                    // DIFFERENT content is the one we'd be overwriting.
                    // (If multiple PSDs share the same filename with
                    // different content we still only need one entry —
                    // the user gets to decide once and the file ends up
                    // either overwritten with the new content or left
                    // alone in place; in the latter case the OTHER
                    // PSD's copy stays intact because it lives in a
                    // different subfolder.)
                    string overwritePath = null, overwriteHash = null;
                    foreach (var (path, hash) in hits)
                    {
                        if (hash == newHash) { identical++; overwritePath = null; break; }
                        if (overwritePath == null)
                        {
                            overwritePath = path;
                            overwriteHash = hash;
                        }
                    }
                    if (overwritePath == null) continue;

                    // Skip if the "overwrite" target is in the same
                    // destination subfolder AND has same content as
                    // before — that's the "re-imported identical" case.
                    // Already filtered by the hash==newHash check above.

                    result.Add(new ImageConflictResolverWindow.ImageConflict
                    {
                        layerId           = $"{fileName} → {psdName}",
                        // The layer id is unique within the doc; using
                        // the file name + target subfolder makes the
                        // conflict entry self-describing in the
                        // resolver UI even when several PSDs share a
                        // layer name.
                        layerName         = fileName,
                        psdName           = psdName,
                        newImagePath      = srcPath,
                        existingImagePath = overwritePath,
                        newSizeBytes      = (int)new FileInfo(srcPath).Length,
                        existingSizeBytes = (int)new FileInfo(overwritePath).Length,
                        newWidth          = PngDimensions(srcPath).w,
                        newHeight         = PngDimensions(srcPath).h,
                        existingWidth     = PngDimensions(overwritePath).w,
                        existingHeight    = PngDimensions(overwritePath).h,
                        newHash           = ShortHash(newHash),
                        existingHash      = ShortHash(overwriteHash),
                    });
                }

                Debug.Log(
                    $"[PSDImporter] PreScanImageConflicts: scanned={scanned} " +
                    $"srcMissing={srcMissing} identical={identical} " +
                    $"existingFiles={existingIndex.Sum(kv => kv.Value.Count)} " +
                    $"→ {result.Count} conflict(s) to review");
            }
            finally
            {
                if (useProgressBar) EditorUtility.ClearProgressBar();
            }
            return result;
        }

        // Walk the whole <imageOutputRoot>/ tree once, building a map
        // from filename → list of (fullPath, sha256). Capped at the
        // project's actual export root — we don't recurse into
        // Library/, Temp/, etc. unless they happen to live under
        // <imageOutputRoot> (which they shouldn't).
        //
        // `progressFrom` / `progressTo` let the caller report sub-steps
        // in a multi-stage scan.
        private static Dictionary<string, List<(string path, string hash)>>
            BuildExistingPngIndex(string rootAbs, bool showProgress,
            float progressFrom, float progressTo)
        {
            var index = new Dictionary<string, List<(string, string)>>(
                StringComparer.OrdinalIgnoreCase);
            if (!Directory.Exists(rootAbs)) return index;

            var files = Directory.GetFiles(rootAbs, "*.png",
                SearchOption.AllDirectories);
            for (int i = 0; i < files.Length; i++)
            {
                if (showProgress)
                {
                    EditorUtility.DisplayProgressBar("PSD Importer",
                        $"扫描现有图片 ({i + 1}/{files.Length})…",
                        progressFrom + (progressTo - progressFrom) *
                            ((i + 1) / (float)files.Length));
                }
                var path = files[i];
                string hash;
                try { hash = Sha256OfFile(path); }
                catch { continue; }   // file locked, deleted between scan and hash — skip
                var key = Path.GetFileName(path);
                if (!index.TryGetValue(key, out var list))
                    index[key] = list = new List<(string, string)>();
                list.Add((path, hash));
            }
            return index;
        }

        private static string ShortHash(string full) =>
            full.Length >= 22 ? full.Substring(0, 22) : full;

        // Translate an absolute PNG path (e.g. C:\project\Assets\PSDImages\
        // SomeOtherPSD\close.png) into a project-relative Asset path
        // ("Assets/PSDImages/SomeOtherPSD/close.png") so the entry
        // matches what AssetDatabase.LoadAssetAtPath expects and is
        // what the prefab's image reference is written against.
        //
        // rootAbs / rootRel are the imageOutputRoot in absolute and
        // relative form (we already have them in the caller).
        private static string MakeProjectRelative(
            string absolute, string rootAbs, string rootRel)
        {
            var normAbs = absolute.Replace('\\', '/').TrimEnd('/');
            var normRoot = rootAbs.Replace('\\', '/').TrimEnd('/');
            if (normAbs.StartsWith(normRoot + "/", System.StringComparison.OrdinalIgnoreCase))
                return rootRel + "/" + normAbs.Substring(normRoot.Length + 1);
            // Defensive fallback — should not happen because
            // BuildExistingPngIndex only ever returns paths under
            // rootAbs.
            return normAbs;
        }

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

        /// <summary>
        /// Copy PNGs from the Python tool's images/ directory that aren't
        /// referenced by any node in the JSON tree. These are export-only
        /// images (export_ prefix) — sprites meant for direct use by
        /// other UI, without a corresponding prefab GameObject.
        /// </summary>
        private static void CopyOrphanExportImages(
            string jsonDir, string rootAbs, string rootRel,
            string psdName, PsdDocument doc,
            ref bool overwriteAll, ref bool noOverwriteAll,
            ImageCopyStats stats)
        {
            var imagesDir = Path.Combine(jsonDir, "images");
            if (!Directory.Exists(imagesDir)) return;

            // Build set of filenames already processed by the main
            // node loop (so we don't copy them twice).
            var handled = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (var n in doc.root.SelfAndDescendants())
            {
                if (!n.HasImage || string.IsNullOrEmpty(n.imageFile)) continue;
                handled.Add(Path.GetFileName(n.imageFile));
            }

            foreach (var srcPath in Directory.GetFiles(imagesDir, "*.png"))
            {
                var fileName = Path.GetFileName(srcPath);
                if (handled.Contains(fileName)) continue;

                var dstAbs = Path.Combine(rootAbs, psdName, fileName)
                                    .Replace('\\', '/');
                var newHash = Sha256OfFile(srcPath);

                if (TryCopyOrPrompt(srcPath, dstAbs, newHash,
                    ref overwriteAll, ref noOverwriteAll, out var decision))
                {
                    Debug.Log($"[PSDImporter] Copied orphan image '{fileName}' " +
                              $"→ {rootRel}/{psdName}/");
                }
                stats.Add(decision);
            }
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
