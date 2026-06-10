"""
Core exporter: walks a PSD file, builds the JSON tree and writes PNGs.

This is the heart of the tool. It is intentionally written as a class so
it can be unit-tested without touching the CLI. The CLI (`psd_to_json.py`)
is a thin wrapper around `PsdExporter.export`.

Design notes:
- We use `psd-tools` (https://psd-tools.readthedocs.io/) to read PSDs.
- psd-tools cannot read modern Photoshop layer styles (shadow / stroke /
  gradient overlay). We document this and recommend designers bake the
  effects into the layer pixels before exporting.
- For text layers, psd-tools may only return the rasterized form. We try
  to extract vector text via `layer.text` first; if that fails we fall
  back to "text" mode but warn the user.
"""
from __future__ import annotations

import io
import json
import logging
import os
import re
from dataclasses import dataclass, field
from datetime import datetime, timezone, timedelta
from pathlib import Path
from typing import Any

from PIL import Image

from psd_tools import PSDImage
# psd-tools 1.17 changed the signature: channel + apply_icc are now
# required positional args. We pass None (composite all channels) and
# False (no ICC) — same behavior as the old implicit defaults.
from psd_tools.api.pil_io import convert_layer_to_pil as _convert_layer_to_pil_unsafe


def _composite_layer(layer):
    """Wrap convert_layer_to_pil with the post-1.17 required args."""
    return _convert_layer_to_pil_unsafe(layer, None, False)
# NOTE: we deliberately do NOT use isinstance() dispatch on the concrete
# layer types. The exporter walks via duck-typed "kind" detection
# (`_detect_kind`) so it stays testable with mock layers that don't
# carry the full psd-tools object layout.

from .hashing import composite_hash, sha256_bytes, sha256_file, sha256_text


LOG = logging.getLogger("psd2ugui")

# PSD uses top-left origin with Y going down — same as image canvases.
# Unity UGUI uses bottom-left origin with Y going up. We carry PSD
# coordinates through the JSON and let the C# side flip Y when building
# RectTransform.anchoredPosition.
SCHEMA_VERSION = 1


# ─────────────────────────────────────────────────────────────────────
#  Naming conventions
#
#  Single source of truth: Tools/PSDExporter/PREFIXES.md
#  Mirrored in:
#    - C# Assets/Editor/PSDImporter/PSDNode.cs  (PsdNaming class)
#    - PS plugin com.ugui.rename/host/UGUI_Rename.jsx  (UGUI_PREFIXES)
#    - PS plugin com.ugui.rename/client/index.html     (button grid)
#
#  All prefixes are LOWER-CASE per PREFIXES.md.
# ─────────────────────────────────────────────────────────────────────

# Group nodes (no UGUI component generated)
GROUP_PREFIXES = ()

# Text nodes (UGUI Text)
TEXT_PREFIXES = ("txt_",)

# Button nodes (Image + Button)
BUTTON_PREFIXES = ("btn_",)

# Image nodes (UGUI Image)
IMAGE_PREFIXES = ("img_",)

# Export-only — write PNG but create NO node in the JSON tree.
# Used when other UI elements reference the sprite directly.
EXPORT_ONLY_PREFIXES = ("export_",)

# v1 partial-support composites — currently empty; add back when needed.
COMPOSITE_PREFIXES = {}

# All prefixes in one place for fast lookup
ALL_PREFIXES = (
    GROUP_PREFIXES
    + TEXT_PREFIXES
    + BUTTON_PREFIXES
    + IMAGE_PREFIXES
    + EXPORT_ONLY_PREFIXES
    + tuple(COMPOSITE_PREFIXES.keys())
)

# Variable-name prefixes (PascalCase) for each kind
# What the C# field name starts with — used to generate `BtnXxx` / `ImgXxx` etc.
VAR_PREFIX_BY_TYPE = {
    "text":     "Txt",
    "button":   "Btn",
    "img":      "Img",
    "export":   None,   # export-only: no field generated
}


def classify_layer_name(name: str) -> str:
    """
    Map a PSD layer name to a UGUI component type.

    Returns one of:
      'group'     — no component
      'text'      — UGUI Text
      'button'    — Image + Button
      'image'     — UGUI Image (most common)
      'export'    — PNG only, no node in tree

    The C# side mirrors this list (see `PSDImporter.PsdNaming`).
    """
    lower = name.lower()
    if any(lower.startswith(p) for p in GROUP_PREFIXES):
        return "group"
    if any(lower.startswith(p) for p in TEXT_PREFIXES):
        return "text"
    if any(lower.startswith(p) for p in BUTTON_PREFIXES):
        return "button"
    if any(lower.startswith(p) for p in IMAGE_PREFIXES):
        return "image"
    if any(lower.startswith(p) for p in EXPORT_ONLY_PREFIXES):
        return "export"
    if any(lower.startswith(p) for p in COMPOSITE_PREFIXES):
        for p, t in COMPOSITE_PREFIXES.items():
            if lower.startswith(p):
                return t
    return "group"


def variable_prefix(name: str) -> str | None:
    """
    Return the PascalCase prefix for the C# field name, or None for groups.

    `btn_close`     → 'Btn'
    `img_bg`        → 'Img'
    `toggle_music`  → 'Toggle'
    `group_login`   → None
    """
    return VAR_PREFIX_BY_TYPE.get(classify_layer_name(name))


def sanitize_variable_name(name: str) -> str:
    """
    Convert a PSD layer name to a C#-friendly variable name.

    `btn_close`     → `BtnClose`     (prefix + PascalCase rest)
    `img_bg`        → `ImgBg`
    `toggle_music`  → `ToggleMusic`
    `group_login`   → `GroupLogin`   (group prefix is also pascalized)
    `MyLayer`       → `MyLayer`      (no recognized prefix → just pascalize)

    Strategy: if there's a known prefix, REPLACE it with the canonical
    PascalCase prefix. Otherwise pascalize the whole name.
    """
    # First: try the known-prefix replacement. We match lowercase prefixes.
    lower = name.lower()
    for p, canonical in VAR_PREFIX_BY_TYPE.items():
        if canonical is None:
            continue   # export_ type has no field name
        if lower.startswith(p + "_"):
            base = name[len(p) + 1:]   # strip "btn_" → "close"
            return canonical + _pascalize(base)
    if any(lower.startswith(p) for p in GROUP_PREFIXES):
        for p in GROUP_PREFIXES:
            if lower.startswith(p):
                base = name[len(p):]
                return _pascalize(p.rstrip("_")) + _pascalize(base)
    # Unknown prefix (or none): just pascalize the whole thing.
    return _pascalize(name) or "Node"


def _pascalize(s: str) -> str:
    """`my_layer` / `my-layer` / `My Layer` → `MyLayer`."""
    parts = s.replace("-", "_").replace(" ", "_").split("_")
    out: list[str] = []
    for p in parts:
        if not p:
            continue
        out.append(p[0].upper() + p[1:])
    return "".join(out)


# ─────────────────────────────────────────────────────────────────────
#  Filename + 9-slice parsing
#
#  The exported PNG filename is the LAYER NAME WITH THE PREFIX AND
#  9-slice SUFFIX STRIPPED:
#    btn_close                         → close.png
#    icon_settings                     → settings.png
#    btn_use_9slice_10_20_10_20        → use.png     (with slice {l:10,t:20,r:10,b:20})
#    toggle_music_9slice               → music.png   (default 10/10/10/10)
#
#  This keeps filenames short and meaningful. Collisions (two layers
#  with the same stripped name) follow the existing "last writer wins"
#  policy — the C# side detects via hash and prompts the user.
# ─────────────────────────────────────────────────────────────────────

_SLICE_RE_FULL = re.compile(
    r'^(.*)_9slice_(-?\d+)_(-?\d+)_(-?\d+)_(-?\d+)$')
_SLICE_RE_DEFAULT = re.compile(r'^(.*)_9slice$')


def parse_layer_name_for_image(name: str) -> tuple[str, str, dict | None]:
    """
    Split a layer name into (logical_png_name, original_name, slice_meta).

    The logical name is what we use for the PNG filename — the UGUI
    prefix (e.g. 'btn_') and any 9-slice suffix are stripped. The
    original name is preserved unchanged in the JSON's `name` field so
    the C# prefab hierarchy keeps the designer's layer names.

    Returns slice_meta as {l, t, r, b} in pixels, or None if no
    9-slice metadata is present.

    Examples:
      btn_close                        → ('close',    'btn_close',                        None)
      btn_use_9slice_10_20_10_20       → ('use',      'btn_use_9slice_10_20_10_20',       {l:10,t:20,r:10,b:20})
      toggle_music_9slice              → ('music',    'toggle_music_9slice',              {l:10,t:10,r:10,b:10})
      关闭                              → ('关闭',      '关闭',                              None)
    """
    original = name
    slice_meta: dict | None = None

    m = _SLICE_RE_FULL.match(name)
    if m:
        name = m.group(1)
        slice_meta = {
            "l": int(m.group(2)),
            "t": int(m.group(3)),
            "r": int(m.group(4)),
            "b": int(m.group(5)),
        }
    elif _SLICE_RE_DEFAULT.match(name):
        name = name[: -len("_9slice")]
        # Default 9-slice borders — common middle-of-the-road value
        # that works for typical button / panel art.
        slice_meta = {"l": 10, "t": 10, "r": 10, "b": 10}

    # Strip the UGUI prefix to get the logical PNG name. We do NOT
    # strip the prefix from `original` — the JSON's name field keeps
    # it for the C# prefab hierarchy.
    lower = name.lower()
    logical = name
    for p in ALL_PREFIXES:
        if lower.startswith(p):
            logical = name[len(p):]
            break

    return logical, original, slice_meta


# ─────────────────────────────────────────────────────────────────────
#  Export data classes (also used to build the JSON dict)
# ─────────────────────────────────────────────────────────────────────

@dataclass
class ExportNode:
    id: str
    name: str
    type: str           # 'group' | 'image' | 'text' | 'button' |
                        # 'input' | 'scroll' | 'slider' | 'toggle'
    visible: bool
    opacity: float
    rect: dict          # { x, y, w, h }
    pivot: dict         # { x, y } 0..1
    children: list["ExportNode"] = field(default_factory=list)

    # image-bearing nodes: image / button / input / scroll / slider / toggle
    image_hash: str | None = None
    image_file: str | None = None
    image_transparent: bool = False

    # 9-slice (Sliced sprite) borders in pixels. None ⇒ not sliced.
    # Schema: { l, t, r, b } — the same layout Unity's TextureImporter
    # `spriteBorder` Vector4(L, B, R, T) uses, except we keep top-first
    # here for readability.
    slice: dict | None = None

    # text-only
    text_hash: str | None = None
    text: dict | None = None

    # Set when a layer was tagged with a composite prefix (input/scroll/
    # slider/toggle) — the importer creates just the Image and warns the
    # user to wire the actual component in the Inspector.
    is_composite: bool = False

    def to_dict(self) -> dict[str, Any]:
        d: dict[str, Any] = {
            "id": self.id,
            "name": self.name,
            "type": self.type,
            "visible": self.visible,
            "opacity": round(self.opacity, 4),
            "rect": self.rect,
            "pivot": self.pivot,
        }
        if self.type == "group":
            d["children"] = [c.to_dict() for c in self.children]
        elif self.type == "text":
            d["textHash"] = self.text_hash
            d["text"] = self.text
        else:
            # Everything else (image / button / input / scroll / slider / toggle)
            # carries image data because they all need an Image component.
            d["imageHash"] = self.image_hash
            d["imageFile"] = self.image_file
            d["imageTransparent"] = self.image_transparent
            if self.slice is not None:
                d["slice"] = self.slice
        if self.is_composite:
            d["isComposite"] = True
        return d


@dataclass
class ExportResult:
    """Bundles everything the C# side needs: the JSON tree + side files."""
    json_path: Path
    image_root: Path
    node_hashes: dict[str, str]      # id → hash (used to build cache)
    node_types: dict[str, str]       # id → type
    source_psd_hash: str
    warnings: list[str] = field(default_factory=list)


# ─────────────────────────────────────────────────────────────────────
#  Core exporter
# ─────────────────────────────────────────────────────────────────────

class PsdExporter:
    """
    Walks a PSD and produces:
      <outputRoot>/<psdName>.json          — the tree
      <outputRoot>/images/<layerId>.png    — per-image-layer PNG

    The output root is a single folder that the Unity side scans for
    `<name>.json` files. Each PSD exports to its own subfolder so that
    multiple PSDs can coexist.

    The exporter is incremental: it skips writing a PNG if the same hash
    already exists on disk (i.e. image content unchanged). The JSON is
    always rewritten because it's small.
    """

    def __init__(
        self,
        output_root: str | os.PathLike,
        *,
        image_subdir: str = "images",
        overwrite_json: bool = True,
        marked_only: bool = True,
    ) -> None:
        """
        :param marked_only: If True (default), only layers whose name starts
            with one of the UGUI prefixes (see PREFIXES.md) are exported.
            Their ancestor groups are kept as containers. Unmarked layers
            (decoration, guides, layout helpers) are dropped. Set False to
            export the whole tree.
        """
        self.output_root = Path(output_root).resolve()
        self.image_subdir = image_subdir
        self.overwrite_json = overwrite_json
        self.marked_only = marked_only

    # ─── public entry ──────────────────────────────────────────────
    def export(self, psd_path: str | os.PathLike) -> ExportResult:
        psd_path = Path(psd_path).resolve()
        if not psd_path.is_file():
            raise FileNotFoundError(f"PSD not found: {psd_path}")

        psd_name = psd_path.stem
        out_dir = self.output_root / psd_name
        img_dir = out_dir / self.image_subdir
        out_dir.mkdir(parents=True, exist_ok=True)
        img_dir.mkdir(parents=True, exist_ok=True)

        LOG.info("Exporting %s → %s", psd_path, out_dir)

        psd_hash = sha256_file(psd_path)
        psd = PSDImage.open(psd_path)
        warnings: list[str] = []

        ctx = _WalkContext(
            image_root=img_dir,
            image_subdir=self.image_subdir,
            warnings=warnings,
        )

        # IMPORTANT: PSDImage is the document root, NOT a layer. Treating it
        # as a layer breaks: convert_layer_to_pil returns None, _walk_layer
        # falls into the "empty layer → group placeholder" branch, and all
        # children are dropped (they're never iterated).
        #
        # Correct flow: build a synthetic root group, then walk the
        # top-level layers (psd itself is iterable).
        root = ExportNode(
            id="root",
            name="Root",
            type="group",
            visible=True,
            opacity=1.0,
            rect={"x": 0, "y": 0, "w": psd.width, "h": psd.height},
            pivot={"x": 0.0, "y": 0.0},
            children=[
                n for n in (
                    self._walk_layer(
                        child, parent_id="root", ctx=ctx,
                        marked_only=self.marked_only,
                        parent_visible=True)
                    for child in psd
                )
                if n is not None
            ],
        )

        json_path = out_dir / f"{psd_name}.json"
        payload = {
            "schemaVersion": SCHEMA_VERSION,
            "sourcePsd": {
                "name": psd_path.name,
                "hash": psd_hash,
            },
            # Use Beijing time so the timestamp matches the user's locale.
            "exportedAt": datetime.now(timezone(timedelta(hours=8))).isoformat(timespec="seconds"),
            "canvas": {
                "width": psd.width,
                "height": psd.height,
            },
            "root": root.to_dict(),
        }

        if self.overwrite_json or not json_path.exists():
            with open(json_path, "w", encoding="utf-8") as f:
                json.dump(payload, f, ensure_ascii=False, indent=2)
            LOG.info("Wrote %s", json_path)

        if warnings:
            LOG.warning("%d warning(s):", len(warnings))
            for w in warnings:
                LOG.warning("  - %s", w)

        return ExportResult(
            json_path=json_path,
            image_root=img_dir,
            node_hashes=ctx.node_hashes,
            node_types=ctx.node_types,
            source_psd_hash=psd_hash,
            warnings=warnings,
        )

    # ─── tree walk ─────────────────────────────────────────────────
    def _walk_layer(
        self, layer, parent_id: str, ctx: "_WalkContext",
        marked_only: bool = False,
        parent_visible: bool = True,
    ) -> "ExportNode | None":
        """
        Walk one PSD layer into an ExportNode.

        Returns None when `marked_only` is True and this layer (and its
        subtree) does not contain anything we'd want to export. The parent
        is responsible for filtering out Nones from its children list.

        `marked_only` mode rules:
          - A layer is "marked" iff its name starts with one of the
            UGUI prefixes (see PREFIXES.md / ALL_PREFIXES in this file).
          - Keep a layer if it is itself marked.
          - Keep a group if any of its descendants is marked (so we
            preserve the hierarchy down to the marked leaves).
          - Drop everything else.

        Visibility rules (Photoshop "eye" toggle):
          - A layer is considered hidden if EITHER its own .visible flag
            is False OR any ancestor group's .visible is False. The
            psd-tools `layer.visible` attribute is per-layer, so we have
            to propagate parent visibility ourselves.
          - Use case: a designer hides a whole UI panel by clicking the
            "eye" on its parent group. They expect the whole subtree to
            be dropped from the export (it's how a single PSD can hold
            several alternative layouts and the user picks which to
            ship by toggling visibility).
        """
        # Visibility gate: if either this layer or any ancestor is
        # hidden, drop the whole subtree. We check this BEFORE doing any
        # further work — no need to classify / composite / hash images
        # we're going to throw away.
        self_visible = bool(getattr(layer, "visible", True))
        effective_visible = parent_visible and self_visible
        if not effective_visible:
            return None

        node_id = f"{parent_id}/{layer.name}"
        kind = classify_layer_name(layer.name)
        visible = self_visible
        opacity = float(getattr(layer, "opacity", 1.0) or 1.0) / 255.0

        bbox = layer.bbox  # (x0, y0, x1, y1) in PSD coords
        x0, y0, x1, y1 = bbox
        w, h = max(0, x1 - x0), max(0, y1 - y0)
        rect = {"x": int(x0), "y": int(y0), "w": int(w), "h": int(h)}

        # Pivot: psd-tools doesn't expose per-layer pivot directly.
        # Default to top-left (0, 0) which matches how PSD positions layers.
        # Designers can re-arrange in Unity after import.
        pivot = {"x": 0.0, "y": 0.0}

        layer_kind = _detect_kind(layer)
        is_marked = kind != "group"   # anything that classifies as image/text/button/etc.

        # export-only: write PNG, no node in JSON tree.
        # Must be checked BEFORE group/text branches — export_ layers
        # can be any layer kind (group, pixel, text).
        if kind == "export":
            pil = self._try_composite_with_fallback(layer, ctx, node_id)
            if pil is not None and pil.size != (0, 0):
                logical_name, _, _ = parse_layer_name_for_image(layer.name)
                png_bytes = self._encode_png(pil)
                img_hash = sha256_bytes(png_bytes)
                png_path = ctx.write_image(logical_name, png_bytes, img_hash)
                LOG.info("export-only '%s' → %s (%dx%d, %.1f KB)",
                    node_id, png_path.name, pil.width, pil.height,
                    len(png_bytes) / 1024)
            else:
                LOG.warning("export-only '%s': composite returned empty image", node_id)
            return None

        if layer_kind == "group":
            # Recurse into children first so we know which to keep.
            # We no longer pre-filter with _is_visible_layer — the
            # parent_visible argument now handles inheritance.
            raw_children = [
                self._walk_layer(
                    child, node_id, ctx,
                    marked_only=marked_only,
                    parent_visible=parent_visible and self_visible)
                for child in layer
            ]
            kept_children = [c for c in raw_children if c is not None]

            if marked_only and not is_marked and not kept_children:
                return None   # drop this group entirely

            if is_marked and not kept_children:
                # A marked group with no surviving children — treat as
                # image. Render the group composite so the user gets a
                # real sprite for their button.
                pil = self._try_composite_with_fallback(layer, ctx, node_id)
                if pil is not None and pil.size != (0, 0):
                    return self._build_image_node(
                        layer, node_id, kind, visible, opacity, rect, pivot, pil, ctx)
                # No image available — keep the group anyway, even if empty.
                # The Unity side can decide what to do.

            node = ExportNode(
                id=node_id,
                name=layer.name,
                type="group",
                visible=visible,
                opacity=opacity,
                rect=rect,
                pivot=pivot,
                children=kept_children,
            )
            ctx.record(node)
            return node

        if marked_only and not is_marked:
            return None

        if layer_kind == "text":
            text_dict, text_h = self._extract_text(layer, ctx)
            node = ExportNode(
                id=node_id,
                name=layer.name,
                type="text",
                visible=visible,
                opacity=opacity,
                rect=rect,
                pivot=pivot,
                text_hash=text_h,
                text=text_dict,
            )
            ctx.record(node)
            return node

        # image / button path
        pil = self._try_composite_with_fallback(layer, ctx, node_id)
        if pil is None or pil.size == (0, 0):
            # Couldn't get an image. In marked_only mode, drop it — the
            # user didn't mark a "transparent" or unrenderable layer.
            if marked_only:
                return None
            # Otherwise fall back to an empty group placeholder (old behaviour).
            node = ExportNode(
                id=node_id,
                name=layer.name,
                type="group",
                visible=visible,
                opacity=opacity,
                rect=rect,
                pivot=pivot,
            )
            ctx.record(node)
            return node

        return self._build_image_node(
            layer, node_id, kind, visible, opacity, rect, pivot, pil, ctx)

    def _try_composite_with_fallback(self, layer, ctx, node_id):
        """
        Render a layer to a PIL image, with fallbacks for smart objects
        and groups. Returns None if every approach fails.
        """
        # Approach 1: standard pixel layer composite.
        try:
            pil = _composite_layer(layer)
            if pil is not None and pil.size != (0, 0):
                return pil
        except Exception as e:
            ctx.warn(f"composite_layer failed for '{node_id}': {e}")

        # Approach 2: layer.composite() (works for smart objects and
        # groups in newer psd-tools).
        try:
            pil = layer.composite()
            if pil is not None and pil.size != (0, 0):
                return pil
        except Exception as e:
            ctx.warn(f"layer.composite() failed for '{node_id}': {e}")

        ctx.warn(f"All composite approaches failed for '{node_id}' — "
                 f"layer will be dropped or kept as empty group placeholder.")
        return None

    def _build_image_node(
        self, layer, node_id, kind, visible, opacity, rect, pivot, pil, ctx,
    ) -> ExportNode:
        # Parse the layer name once: extract 9-slice metadata (if any)
        # and the logical PNG name (prefix + slice suffix stripped). The
        # original layer name is kept in the JSON's `name` field so the
        # C# prefab hierarchy preserves the designer's naming.
        logical_name, original_name, slice_meta = parse_layer_name_for_image(
            layer.name)

        if slice_meta is not None:
            # 9-slice node: NO image export. The Unity side creates an
            # Image component WITHOUT a sprite reference — the designer
            # sets the 9-slice borders in the Inspector.  Use a stable
            # hash derived from slice values + rect for incremental tracking.
            img_hash = composite_hash([
                f"s:{slice_meta['l']}_{slice_meta['t']}_{slice_meta['r']}_{slice_meta['b']}",
                f"r:{rect['x']}_{rect['y']}_{rect['w']}_{rect['h']}",
            ])
            img_file = ""
            img_transparent = False
            LOG.info(
                "9-slice '%s' → no PNG (structure-only, borders L=%d T=%d R=%d B=%d)",
                node_id,
                slice_meta["l"], slice_meta["t"],
                slice_meta["r"], slice_meta["b"],
            )
        else:
            png_bytes = self._encode_png(pil)
            img_hash = sha256_bytes(png_bytes)
            img_file_obj = ctx.write_image(logical_name, png_bytes, img_hash)
            img_file = str(Path(self.image_subdir) / img_file_obj.name)
            img_transparent = _has_alpha(pil)

        is_composite = kind in COMPOSITE_PREFIXES.values()
        node = ExportNode(
            id=node_id,
            # Preserve the FULL layer name (including prefix and any
            # 9-slice suffix) so the C# side's GameObject names match
            # what the designer sees in Photoshop.
            name=original_name,
            type=kind,
            visible=visible,
            opacity=opacity,
            rect=rect,
            pivot=pivot,
            image_hash=img_hash,
            image_file=img_file,
            image_transparent=img_transparent,
            slice=slice_meta,
            is_composite=is_composite,
        )
        if is_composite:
            ctx.warn(
                f"Composite '{node_id}': tool only creates the Image. "
                f"Manually add the {kind.title()} component in Unity Inspector."
            )
        ctx.record(node)
        return node

    # ─── text extraction ───────────────────────────────────────────
    def _extract_text(self, layer, ctx: "_WalkContext") -> tuple[dict, str]:
        """
        Pull text data from a TypeLayer.

        psd-tools `layer.text` returns only the string content; font
        metadata lives in `layer.engine_dict` (StyleRun → RunArray →
        StyleSheetData) and `layer.font_names`.  We parse those to get
        font size, color, and font name.
        """
        content = ""
        font_name = ""
        font_size: float = 0.0
        color_hex = "#FFFFFFFF"
        alignment = "MiddleCenter"

        try:
            # --- content ---
            text_obj = layer.text
            if text_obj is not None:
                content = str(text_obj)

            # --- font name ---
            names = getattr(layer, "font_names", None) or []
            if names:
                font_name = _safe_str(names[0])

            # --- font size, color from engine_dict ---
            eng = getattr(layer, "engine_dict", None) or {}
            style_run = eng.get("StyleRun", {})
            run_array = style_run.get("RunArray", [])
            if run_array:
                sheet_data = (
                    run_array[0]
                    .get("StyleSheet", {})
                    .get("StyleSheetData", {})
                )
                if "FontSize" in sheet_data:
                    font_size = float(sheet_data["FontSize"])
                    # Engine font size is in unscaled design units; the
                    # displayed size is engine_size × layer transform
                    # scale.  e.g. 71.23 × 0.6458 ≈ 46.0 pt.
                    xform = getattr(layer, "transform", None)
                    if xform and len(xform) >= 4 and xform[3] != 0:
                        font_size *= abs(xform[3])
                if "FillColor" in sheet_data:
                    fc = sheet_data["FillColor"]
                    if fc.get("Type") == 1:  # RGB
                        vals = fc.get("Values", [1, 1, 1, 1])
                        color_hex = "#{:02X}{:02X}{:02X}{:02X}".format(
                            int(vals[0] * 255),
                            int(vals[1] * 255),
                            int(vals[2] * 255),
                            int(vals[3] * 255),
                        )
        except Exception as e:
            ctx.warn(f"Text parse failed for '{layer.name}': {e}")

        # Fallback: rasterize the layer for a pixel hash so Unity can
        # still show SOMETHING even if the vector text is off.
        try:
            pil = _composite_layer(layer)
            raster_hash = sha256_bytes(self._encode_png(pil)) if pil else ""
        except Exception:
            raster_hash = ""

        text_dict = {
            "content": content,
            "fontName": font_name,
            "fontSize": font_size,
            "color": color_hex,
            "alignment": alignment,
            "bold": False,
            "italic": False,
            "_rasterHash": raster_hash,
        }

        text_hash = composite_hash([
            content,
            font_name,
            f"{font_size:.3f}",
            color_hex,
            alignment,
            raster_hash,
        ])
        return text_dict, text_hash

    # ─── PNG encoding ──────────────────────────────────────────────
    @staticmethod
    def _encode_png(pil: Image.Image) -> bytes:
        """Encode a PIL image as PNG bytes. RGBA is preserved when present."""
        if pil.mode not in ("RGBA", "RGB"):
            pil = pil.convert("RGBA" if "A" in pil.mode else "RGB")
        buf = io.BytesIO()
        pil.save(buf, format="PNG", optimize=True)
        return buf.getvalue()


# ─────────────────────────────────────────────────────────────────────
#  Internal helpers
# ─────────────────────────────────────────────────────────────────────

@dataclass
class _WalkContext:
    image_root: Path
    image_subdir: str
    warnings: list[str] = field(default_factory=list)
    node_hashes: dict[str, str] = field(default_factory=dict)
    node_types: dict[str, str] = field(default_factory=dict)

    def record(self, node: ExportNode) -> None:
        self.node_types[node.id] = node.type
        # Any image-bearing type (image / button / input / scroll /
        # slider / toggle) carries an image_hash; text nodes carry a
        # text_hash. Groups have no hash (we synthesize a structural one
        # in the C# side).
        if node.image_hash and node.type in (
            "image", "button", "input", "scroll", "slider", "toggle",
            "bg", "icon", "item", "mask", "panel", "progress", "fx",
        ):
            self.node_hashes[node.id] = node.image_hash
        elif node.text_hash and node.type == "text":
            self.node_hashes[node.id] = node.text_hash

    def warn(self, msg: str) -> None:
        self.warnings.append(msg)
        LOG.warning(msg)

    def write_image(self, logical_name: str, png_bytes: bytes, img_hash: str) -> Path:
        """
        Write a PNG to disk, but only if the same content doesn't already
        exist on disk with the same hash. The filename is the LOGICAL
        name (UGUI prefix + 9-slice suffix already stripped) so e.g.
        `btn_use_9slice_10_20_10_20` ends up as `use.png`, not
        `btn_use_9slice_10_20_10_20.png`. If two layers in the same
        PSD produce the same logical name, the second overwrites the
        first on disk; the C# side detects the hash mismatch and
        prompts the user.
        """
        safe = _safe_filename(logical_name)
        target = self.image_root / f"{safe}.png"
        if target.exists():
            # Re-export only if content actually changed.
            try:
                existing = target.read_bytes()
                if sha256_bytes(existing) == img_hash:
                    return target
            except OSError:
                pass
        target.write_bytes(png_bytes)
        return target


def _is_visible_layer(layer) -> bool:
    """
    Per-layer visibility check ONLY. Does NOT consider parent groups.

    Historically used to skip hidden children, but that approach misses
    the common case where a parent GROUP is hidden — its children still
    report `.visible = True` in psd-tools, but Photoshop's renderer
    treats them as invisible.

    The proper way to handle this is to thread `parent_visible` down the
    walk (see `_walk_layer`); callers should no longer pre-filter with
    this helper. Kept for any external test mocks that might still
    import it.
    """
    return bool(getattr(layer, "visible", True))


def _detect_kind(layer) -> str:
    """
    Classify a PSD layer as 'group', 'text', or 'image'.

    We use duck-typing instead of isinstance() so test mocks (and any
    future layer kind we add) can plug in via attributes.

    Detection rules, in order:
      1. If the layer has a `kind` attribute (psd-tools uses this), use it.
      2. Else if it has a non-None `.text` attribute → 'text'.
      3. Else if it's iterable with children → 'group'.
      4. Else → 'image'.
    """
    # psd-tools sets `layer.kind` to 'pixel', 'type', 'group', etc.
    explicit = getattr(layer, "kind", None)
    if explicit is not None:
        if explicit == "group":
            return "group"
        if explicit == "type":
            return "text"
        return "image"  # 'pixel', 'shape', etc.

    # Test mocks: just look for the marker attributes.
    if getattr(layer, "_is_group", False):
        return "group"
    if getattr(layer, "_is_text", False):
        return "text"
    if getattr(layer, "_is_image", False):
        return "image"

    # Last-ditch fallback: try to detect by attribute presence.
    if hasattr(layer, "text") and getattr(layer, "text", None) is not None:
        return "text"
    return "image"


def _has_alpha(pil: Image.Image) -> bool:
    if pil.mode in ("RGBA", "LA"):
        # Quick scan: any alpha < 255?
        alpha = pil.split()[-1]
        return alpha.getextrema()[0] < 255
    return False


def _safe_str(v) -> str:
    try:
        return str(v) if v is not None else ""
    except Exception:
        return ""


def _safe_filename(node_id: str) -> str:
    """Sanitize a node id into a cross-platform filename."""
    keep = "".join(c if c.isalnum() or c in "-_." else "_" for c in node_id)
    return keep or "node"


def _color_to_hex(color) -> str:
    """Convert a psd-tools Color to #RRGGBBAA."""
    try:
        r, g, b, a = color
        return "#{:02X}{:02X}{:02X}{:02X}".format(
            int(r * 255), int(g * 255), int(b * 255), int(a * 255)
        )
    except Exception:
        return "#FFFFFFFF"


def _psd_alignment_to_unity(s: str) -> str:
    """
    Map PSD alignment strings to UGUI TextAnchor values.

    psd-tools returns alignment as something like 'CENTER' or
    'LEFT_JUSTIFIED' — we normalize to UGUI's PascalCase names.
    """
    s = (s or "").upper()
    mapping = {
        "LEFT": "UpperLeft",
        "CENTER": "UpperCenter",
        "RIGHT": "UpperRight",
        "LEFT_JUSTIFIED": "UpperLeft",
        "CENTER_JUSTIFIED": "UpperCenter",
        "RIGHT_JUSTIFIED": "UpperRight",
        "JUSTIFIED": "UpperLeft",
    }
    return mapping.get(s, "MiddleCenter")
