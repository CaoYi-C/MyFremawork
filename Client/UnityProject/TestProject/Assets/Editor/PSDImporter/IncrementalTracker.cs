// IncrementalTracker.cs
// Persists per-PSD hash + per-node hash map so re-imports can skip
// unchanged nodes entirely.
//
// Storage layout:
//   <psdExportRoot>/<PsdName>/<cacheFileName>   (JSON, see PsdCache)
//
// The cache is owned by the importer; the user never edits it directly.
// On every import we:
//   1. Load the existing cache (if any).
//   2. Compare sourcePsdHash — if equal, signal "no changes" and exit.
//   3. Compare per-node hashes and produce a Diff the importer acts on.

using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

namespace PSDImporter.Editor
{
    [Serializable]
    public class PsdCache
    {
        public int schemaVersion = 1;
        public string sourcePsdName;
        public string sourcePsdHash;
        public string lastImportedAt;
        public string lastImportedPrefabPath;   // "Assets/PSDImport/Foo/Foo.prefab"
        public List<string> nodeIds = new List<string>();
        public List<string> nodeHashes = new List<string>();
        public List<string> nodeTypes  = new List<string>();

        // ─── dictionary helpers (JsonUtility can't serialize Dictionary) ──
        public Dictionary<string, string> HashMap
        {
            get
            {
                var d = new Dictionary<string, string>(nodeIds.Count);
                for (int i = 0; i < nodeIds.Count; i++)
                    d[nodeIds[i]] = nodeHashes[i];
                return d;
            }
            set
            {
                nodeIds.Clear();
                nodeHashes.Clear();
                if (value == null) return;
                foreach (var kv in value)
                {
                    nodeIds.Add(kv.Key);
                    nodeHashes.Add(kv.Value);
                }
            }
        }

        public Dictionary<string, string> TypeMap
        {
            get
            {
                var d = new Dictionary<string, string>(nodeIds.Count);
                for (int i = 0; i < nodeIds.Count; i++)
                    d[nodeIds[i]] = nodeTypes[i];
                return d;
            }
        }
    }

    public enum NodeChangeKind
    {
        Unchanged,
        Added,
        Removed,
        TypeChanged,
        ContentChanged,    // same id+type, hash differs
    }

    public struct NodeDiff
    {
        public string id;
        public NodeChangeKind kind;
        public string oldHash;   // null for Added
        public string newHash;   // null for Removed
    }

    public class IncrementalDiff
    {
        public List<NodeDiff> changes = new List<NodeDiff>();
        public bool sourceChanged;
        public bool fullyUnchanged;

        public int AddedCount
        {
            get
            {
                int n = 0;
                foreach (var c in changes) if (c.kind == NodeChangeKind.Added) n++;
                return n;
            }
        }
        public int RemovedCount
        {
            get { int n = 0; foreach (var c in changes) if (c.kind == NodeChangeKind.Removed) n++; return n; }
        }
        public int ContentChangedCount
        {
            get { int n = 0; foreach (var c in changes) if (c.kind == NodeChangeKind.ContentChanged || c.kind == NodeChangeKind.TypeChanged) n++; return n; }
        }
    }

    public static class IncrementalTracker
    {
        /// <summary>
        /// Load the cache file from disk, or return a fresh empty one.
        /// </summary>
        public static PsdCache LoadOrCreate(string cachePath)
        {
            if (!File.Exists(cachePath)) return new PsdCache();
            try
            {
                var json = File.ReadAllText(cachePath);
                var c = JsonUtility.FromJson<PsdCache>(json);
                return c ?? new PsdCache();
            }
            catch (Exception e)
            {
                Debug.LogWarning($"[PSDImporter] Failed to read cache {cachePath}: {e.Message}. Starting fresh.");
                return new PsdCache();
            }
        }

        /// <summary>
        /// Save the cache atomically (write to .tmp then rename).
        /// </summary>
        public static void Save(PsdCache cache, string cachePath)
        {
            Directory.CreateDirectory(Path.GetDirectoryName(cachePath) ?? ".");
            var tmp = cachePath + ".tmp";
            File.WriteAllText(tmp, JsonUtility.ToJson(cache, prettyPrint: true));
            if (File.Exists(cachePath)) File.Delete(cachePath);
            File.Move(tmp, cachePath);
        }

        /// <summary>
        /// Compare an incoming PsdDocument against a previous cache and
        /// produce a per-node diff.
        /// </summary>
        public static IncrementalDiff Diff(PsdDocument doc, PsdCache prev)
        {
            var diff = new IncrementalDiff();
            diff.sourceChanged = prev == null
                              || prev.sourcePsdHash != doc.sourcePsd.hash;

            var currentIds = new HashSet<string>();
            var prevIds = prev != null
                ? new HashSet<string>(prev.nodeIds)
                : new HashSet<string>();

            // Build current id → hash/type maps from the new doc.
            var curHashes = new Dictionary<string, string>();
            var curTypes  = new Dictionary<string, string>();
            foreach (var n in doc.root.SelfAndDescendants())
            {
                curHashes[n.id] = GetNodeHash(n);
                curTypes[n.id]  = n.type;
                currentIds.Add(n.id);
            }

            var prevHashMap = prev?.HashMap;
            var prevTypeMap = prev?.TypeMap;

            // Walk the new tree, classifying each node.
            foreach (var id in currentIds)
            {
                if (!prevIds.Contains(id))
                {
                    diff.changes.Add(new NodeDiff
                    {
                        id = id,
                        kind = NodeChangeKind.Added,
                        newHash = curHashes[id],
                    });
                    continue;
                }

                string prevType = prevTypeMap != null && prevTypeMap.ContainsKey(id) ? prevTypeMap[id] : null;
                if (prevType != curTypes[id])
                {
                    diff.changes.Add(new NodeDiff
                    {
                        id = id,
                        kind = NodeChangeKind.TypeChanged,
                        oldHash = prevHashMap != null ? prevHashMap.GetValueOrDefault(id) : null,
                        newHash = curHashes[id],
                    });
                    continue;
                }

                string prevH = prevHashMap != null ? prevHashMap.GetValueOrDefault(id) : null;
                if (prevH != curHashes[id])
                {
                    diff.changes.Add(new NodeDiff
                    {
                        id = id,
                        kind = NodeChangeKind.ContentChanged,
                        oldHash = prevH,
                        newHash = curHashes[id],
                    });
                }
                // else: unchanged — don't bother recording
            }

            // Removed nodes (in prev, not in current).
            foreach (var id in prevIds)
            {
                if (!currentIds.Contains(id))
                {
                    diff.changes.Add(new NodeDiff
                    {
                        id = id,
                        kind = NodeChangeKind.Removed,
                        oldHash = prevHashMap != null ? prevHashMap.GetValueOrDefault(id) : null,
                    });
                }
            }

            diff.fullyUnchanged = !diff.sourceChanged && diff.changes.Count == 0;
            return diff;
        }

        /// <summary>
        /// Build a fresh cache from a freshly-imported document.
        /// </summary>
        public static PsdCache BuildCache(PsdDocument doc, string prefabPath)
        {
            var c = new PsdCache
            {
                schemaVersion = PsdDocument.CurrentSchemaVersion,
                sourcePsdName = doc.sourcePsd.name,
                sourcePsdHash = doc.sourcePsd.hash,
                lastImportedAt = DateTime.Now.ToString("o"),
                lastImportedPrefabPath = prefabPath,
            };
            foreach (var n in doc.root.SelfAndDescendants())
            {
                c.nodeIds.Add(n.id);
                c.nodeHashes.Add(GetNodeHash(n));
                c.nodeTypes.Add(n.type);
            }
            return c;
        }

        // Hash extraction — must mirror what Python emits into the JSON.
        private static string GetNodeHash(PsdNode n)
        {
            if (n.IsImage) return n.imageHash;
            if (n.IsText)  return n.textHash;
            // Groups don't have a content hash, but we still need a stable
            // token for diff. Use id+children-count — same children ⇒ same key.
            return "g:" + n.id + ":" + (n.children?.Count ?? 0);
        }
    }
}
