// PSDNode.cs
// JSON data model that mirrors Tools/PSDExporter/SCHEMA.md.
//
// Why a separate file: keeps the schema mirror obvious — if SCHEMA.md
// changes, this file changes too. The model is intentionally simple
// (no Unity references) so it can be reused in build-time tooling
// outside the editor.

using System;
using System.Collections.Generic;
using UnityEngine;

namespace PSDImporter.Editor
{
    // ─────────────────────────────────────────────────────────────────
    //  Root document
    // ─────────────────────────────────────────────────────────────────

    [Serializable]
    public class PsdDocument
    {
        public int    schemaVersion;
        public PsdSource sourcePsd;
        public string exportedAt;
        public PsdCanvas canvas;
        public PsdNode root;

        public const int CurrentSchemaVersion = 1;
    }

    [Serializable]
    public class PsdSource
    {
        public string name;
        public string hash;
    }

    [Serializable]
    public class PsdCanvas
    {
        public int width;
        public int height;
    }

    // ─────────────────────────────────────────────────────────────────
    //  Node (recursive)
    // ─────────────────────────────────────────────────────────────────

    [Serializable]
    public class PsdNode
    {
        public string id;
        public string name;
        public string type;          // "group" | "image" | "text"
        public bool   visible;
        public float  opacity;
        public PsdRect rect;
        public PsdPivot pivot;

        // group
        public List<PsdNode> children;

        // image
        public string imageHash;
        public string imageFile;
        public bool   imageTransparent;

        // 9-slice border. Only set when the layer's PSD name had a
        // `_9slice_L_T_R_B` suffix. Used by the importer to set the
        // Sprite's `spriteBorder` and the Image's `type=Sliced`.
        public PsdSlice slice;

        // text
        public string   textHash;
        public PsdText  text;

        // Derived (filled by importer, not in JSON)
        [NonSerialized] public string variableName;
        [NonSerialized] public string bindingTypeName;     // e.g. "UnityEngine.UI.Image"
        [NonSerialized] public bool   shouldBind;
        [NonSerialized] public PsdNode parent;

        public bool IsImage => type == "image";
        public bool IsButton => type == "button";

        /// <summary>
        /// True for any layer that needs a Unity Image component (image /
        /// button). Sliced nodes (with _9slice suffix) have HasImage=true
        /// but empty imageFile — the Image won't reference a Sprite.
        /// </summary>
        public bool HasImage =>
            IsImage
            || type == "button";
        public bool IsText  => type == "text";
        public bool IsGroup => type == "group";

        public IEnumerable<PsdNode> SelfAndDescendants()
        {
            yield return this;
            if (children == null) yield break;
            foreach (var c in children)
            foreach (var d in c.SelfAndDescendants())
                yield return d;
        }
    }

    [Serializable]
    public class PsdRect
    {
        public int x, y, w, h;
    }

    [Serializable]
    public class PsdPivot
    {
        public float x, y;
    }

    [Serializable]
    public class PsdText
    {
        public string content;
        public string fontName;
        public float  fontSize;
        public string color;       // "#RRGGBBAA"
        public string alignment;   // UGUI TextAnchor
        public bool   bold;
        public bool   italic;
    }

    /// <summary>
    /// 9-slice (Sliced sprite) border values in PIXELS, parsed from the
    /// Python exporter. Set on image-bearing layers whose PSD name ends
    /// with `_9slice_L_T_R_B` (or just `_9slice` for 10/10/10/10).
    /// The C# importer sets the Sprite's border on the TextureImporter
    /// and the Image component's `type` to Sliced.
    /// </summary>
    [Serializable]
    public class PsdSlice
    {
        public int l;  // left   border, pixels from left edge
        public int t;  // top    border, pixels from top edge
        public int r;  // right  border, pixels from right edge
        public int b;  // bottom border, pixels from bottom edge
    }

    // ─────────────────────────────────────────────────────────────────
    //  Helpers shared with the Python side (kept identical for sanity)
    // ─────────────────────────────────────────────────────────────────

    public static class PsdNaming
    {
        // ─────────────────────────────────────────────────────────────
        //  Prefix taxonomy — single source of truth:
        //    Tools/PSDExporter/PREFIXES.md
        //
        //  ALL prefixes are LOWER-CASE here. The PS plugin emits lower-case
        //  names too. We match case-insensitively, but the canonical form is
        //  lower-case. Mirrored in psd_exporter.exporter (Python) and
        //  com.ugui.rename/host/UGUI_Rename.jsx (Photoshop plugin).
        // ─────────────────────────────────────────────────────────────

        // group nodes (no UGUI component generated)
        public static readonly string[] GroupPrefixes = { };

        // text nodes (UGUI Text)
        public static readonly string[] TextPrefixes  = { "txt_" };

        // button nodes (Image + Button)
        public static readonly string[] ButtonPrefixes = { "btn_" };

        // image nodes (UGUI Image)
        public static readonly string[] ImagePrefixes = { "img_" };

        // export-only — PNG exported, no node in JSON tree
        public static readonly string[] ExportPrefixes = { "export_" };

        // composite — currently empty; add back when needed.
        public static readonly Dictionary<string, string> CompositePrefixes =
            new Dictionary<string, string>(StringComparer.Ordinal);

        // PascalCase prefix used to build C# field names
        public static readonly Dictionary<string, string> VarPrefixByType =
            new Dictionary<string, string>(StringComparer.Ordinal) {
            { "text",     "Txt"      },
            { "button",   "Btn"      },
            { "img",      "Img"      },
        };

        /// <summary>
        /// Map a layer name to a UGUI component type.
        /// Returns one of: "image", "text", "button", "input", "scroll",
        ///   "slider", "toggle", "group".
        /// Mirrors psd_exporter.exporter.classify_layer_name.
        /// </summary>
        public static string Classify(string name)
        {
            if (string.IsNullOrEmpty(name)) return "group";
            var lower = name.ToLowerInvariant();
            if (StartsWithAny(lower, GroupPrefixes))    return "group";
            if (StartsWithAny(lower, TextPrefixes))     return "text";
            if (StartsWithAny(lower, ButtonPrefixes))   return "button";
            if (StartsWithAny(lower, ImagePrefixes))    return "image";
            if (StartsWithAny(lower, ExportPrefixes))   return "export";
            foreach (var kv in CompositePrefixes)
                if (lower.StartsWith(kv.Key, StringComparison.Ordinal))
                    return kv.Value;
            return "group";
        }

        public static bool IsComposite(string type) => false;

        /// <summary>
        /// Combined list of all recognized prefixes for name parsing.
        /// </summary>
        private static string[] _allPrefixes;
        public static string[] AllPrefixes
        {
            get
            {
                if (_allPrefixes == null)
                {
                    var list = new List<string>();
                    list.AddRange(GroupPrefixes);
                    list.AddRange(TextPrefixes);
                    list.AddRange(ButtonPrefixes);
                    list.AddRange(ImagePrefixes);
                    list.AddRange(ExportPrefixes);
                    list.AddRange(CompositePrefixes.Keys);
                    _allPrefixes = list.ToArray();
                }
                return _allPrefixes;
            }
        }

        /// <summary>
        /// Strip the UGUI prefix AND 9-slice suffix from a layer name,
        /// returning the logical base name. Mirrors Python's
        /// `parse_layer_name_for_image`.
        ///
        /// e.g. "img_bagBg_9slice_10_10_10_10" → "bagBg"
        ///      "btn_common_close"             → "common_close"
        /// </summary>
        public static string LogicalImageName(string layerName)
        {
            if (string.IsNullOrEmpty(layerName)) return "";

            // 1. Strip 9-slice suffix (_9slice or _9slice_L_T_R_B)
            var sliceMatch = System.Text.RegularExpressions.Regex.Match(
                layerName, @"^(.*)_9slice(_\d+_\d+_\d+_\d+)?$");
            string name = sliceMatch.Success ? sliceMatch.Groups[1].Value : layerName;

            // 2. Strip UGUI prefix
            var lower = name.ToLowerInvariant();
            foreach (var p in AllPrefixes)
            {
                if (lower.StartsWith(p, StringComparison.Ordinal))
                {
                    name = name.Substring(p.Length);
                    break;
                }
            }
            return name;
        }

        /// <summary>
        /// Extract the font tag suffix from a layer name.
        /// e.g. "txt_title_SansCN-Bold" → "SansCN-Bold"
        ///      "txt_title"            → null
        /// Strips txt_ prefix and _9slice suffix first, then takes
        /// the last _xxx segment as the font tag (skips numeric segments).
        /// </summary>
        public static string FontTagFor(string layerName)
        {
            if (string.IsNullOrEmpty(layerName)) return null;
            var lower = layerName.ToLowerInvariant();
            if (!lower.StartsWith("txt_", StringComparison.Ordinal)) return null;

            // Strip txt_ prefix
            var rest = layerName.Substring(4);

            // Strip _9slice suffix
            var sliceMatch = System.Text.RegularExpressions.Regex.Match(
                rest, @"^(.*)_9slice(_\d+_\d+_\d+_\d+)?$");
            if (sliceMatch.Success)
                rest = sliceMatch.Groups[1].Value;

            // The last _xxx segment is the font tag (if not numeric)
            var lastUnderscore = rest.LastIndexOf('_');
            if (lastUnderscore < 0) return null;
            var tag = rest.Substring(lastUnderscore + 1);
            // If it's purely numeric (like "01"), it's not a font tag
            if (tag.Length > 0 && !int.TryParse(tag, out _))
                return tag;
            return null;
        }

        /// <summary>
        /// Return the PascalCase prefix used to build a C# field name for the
        /// given layer name. Groups return null.
        /// </summary>
        public static string VariablePrefixFor(string name)
        {
            var t = Classify(name);
            if (t == "group") return null;
            return VarPrefixByType.TryGetValue(t, out var p) ? p : null;
        }

        /// <summary>
        /// Convert `img_bg` to `ImgBg`. If a known prefix is present, we
        /// REPLACE it with the canonical PascalCase prefix.
        /// Mirrors psd_exporter.exporter.sanitize_variable_name.
        /// </summary>
        public static string SanitizeVariableName(string name)
        {
            if (string.IsNullOrEmpty(name)) return "Node";
            var lower = name.ToLowerInvariant();

            // Try replacing each known prefix.
            foreach (var p in ButtonPrefixes)
                if (lower.StartsWith(p, StringComparison.Ordinal))
                    return VarPrefixByType["button"] + PascalizeRest(name, p.Length);
            foreach (var p in TextPrefixes)
                if (lower.StartsWith(p, StringComparison.Ordinal))
                    return VarPrefixByType["text"] + PascalizeRest(name, p.Length);
            foreach (var p in ImagePrefixes)
                if (lower.StartsWith(p, StringComparison.Ordinal))
                {
                    // Map back to canonical PascalCase prefix
                    var canonical = PascalizeBaseType(p.TrimEnd('_'));
                    return canonical + PascalizeRest(name, p.Length);
                }
            foreach (var kv in CompositePrefixes)
                if (lower.StartsWith(kv.Key, StringComparison.Ordinal))
                    return VarPrefixByType[kv.Value] + PascalizeRest(name, kv.Key.Length);

            // Group prefixes — pascalize the whole thing.
            foreach (var p in GroupPrefixes)
                if (lower.StartsWith(p, StringComparison.Ordinal))
                    return Pascalize(name);

            // No recognized prefix — pascalize the whole name.
            return Pascalize(name);
        }

        private static string PascalizeRest(string full, int prefixLen)
        {
            // Skip past the prefix and the underscore, then pascalize.
            var rest = prefixLen < full.Length && full[prefixLen] == '_'
                ? full.Substring(prefixLen + 1)
                : full.Substring(prefixLen);
            return Pascalize(rest);
        }

        private static string PascalizeBaseType(string p)
        {
            // `img_` → `Img`, `progress_` → `Progress` (the PascalCase keys
            // are already in VarPrefixByType, so just look up).
            if (VarPrefixByType.TryGetValue(p, out var v)) return v;
            return char.ToUpperInvariant(p[0]) + p.Substring(1);
        }

        private static string Pascalize(string s)
        {
            if (string.IsNullOrEmpty(s)) return "";
            var parts = s.Replace("-", "_").Replace(" ", "_").Split('_');
            var sb = new System.Text.StringBuilder();
            foreach (var p in parts)
            {
                if (string.IsNullOrEmpty(p)) continue;
                sb.Append(char.ToUpperInvariant(p[0]));
                if (p.Length > 1) sb.Append(p.Substring(1));
            }
            return sb.ToString();
        }

        private static bool StartsWithAny(string s, string[] prefixes)
        {
            foreach (var p in prefixes)
                if (s.StartsWith(p, StringComparison.Ordinal)) return true;
            return false;
        }
    }
}
