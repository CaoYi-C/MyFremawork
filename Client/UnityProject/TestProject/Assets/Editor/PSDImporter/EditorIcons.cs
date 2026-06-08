// EditorIcons.cs
//
// Tiny helper around EditorGUIUtility.IconContent — caches the
// commonly-used built-in Unity editor icons in a static dict so we can
// reference them by name throughout the importer's UI code without
// hitting IconContent() (which does a string lookup) every OnGUI frame.
//
// Usage:
//     EditorIcons.Get("FolderEmpty")   // GUIContent, or null
//     EditorIcons.IconLabel("TestPassed")  // draws a 16x16 icon

using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

namespace PSDImporter.Editor
{
    public static class EditorIcons
    {
        // Cached lookups. Key = icon name as it appears in
        // EditorGUIUtility.IconContent(name). Value = the GUIContent
        // (or null if Unity doesn't recognize the name in this version).
        private static readonly Dictionary<string, GUIContent> s_cache
            = new Dictionary<string, GUIContent>();

        // Return a cached GUIContent for the given icon name, or null
        // if Unity doesn't ship that icon. Lookups are O(1) after the
        // first call; unknown names are cached as null so we don't
        // repeatedly hammer IconContent() on missing entries.
        public static GUIContent Get(string name)
        {
            if (string.IsNullOrEmpty(name)) return null;
            if (s_cache.TryGetValue(name, out var cached)) return cached;
            GUIContent content;
            try
            {
                content = EditorGUIUtility.IconContent(name);
            }
            catch
            {
                content = null;
            }
            // Some Unity versions return a non-null GUIContent with a
            // null image for unknown names. Normalize that to null.
            if (content != null && content.image == null) content = null;
            s_cache[name] = content;
            return content;
        }

        // Convenience: get just the Texture2D (slightly faster if you
        // only need the image).
        public static Texture2D GetTexture(string name)
        {
            return Get(name)?.image as Texture2D;
        }

        // Draw a square icon button using a built-in Unity icon.
        // Returns true if the user clicked it.
        public static bool IconButton(string iconName, float size, string tooltip = null)
        {
            var content = Get(iconName);
            if (content == null)
            {
                // Fall back to a blank button so the layout still reserves
                // space — better than nothing if the icon is missing.
                return GUILayout.Button(string.Empty, GUILayout.Width(size), GUILayout.Height(size));
            }
            var buttonContent = tooltip != null
                ? new GUIContent(content.image, tooltip)
                : content;
            return GUILayout.Button(buttonContent,
                EditorStyles.toolbarButton,
                GUILayout.Width(size), GUILayout.Height(size));
        }

        // Draw a non-interactive icon label (sized in square pixels).
        public static void IconLabel(string iconName, float size, string tooltip = null)
        {
            var content = Get(iconName);
            if (content == null) return;
            var label = tooltip != null
                ? new GUIContent(content.image, tooltip)
                : content;
            GUILayout.Label(label, GUILayout.Width(size), GUILayout.Height(size));
        }
    }
}
