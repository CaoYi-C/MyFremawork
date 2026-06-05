"""
Self-test for the exporter.

We can't easily create a real PSD in pure Python (psd-tools is read-only),
so we mock the small surface we need and verify the exporter produces the
right JSON + on-disk PNGs.

Run from the Tools/PSDExporter/ directory:
    python -m tests.test_exporter
"""
from __future__ import annotations

import json
import shutil
import sys
import tempfile
from pathlib import Path
from types import SimpleNamespace
from typing import Iterable

# Make sibling package importable when running this file directly.
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))

from PIL import Image
from psd_exporter.exporter import (  # noqa: E402
    ExportNode,
    PsdExporter,
    classify_layer_name,
    sanitize_variable_name,
)
from psd_exporter.hashing import (  # noqa: E402
    composite_hash,
    sha256_bytes,
    sha256_file,
    sha256_text,
)


# 鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€
#  Pure-Python unit tests (no PSD needed)
# 鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€

def test_hashing_is_deterministic() -> None:
    assert sha256_text("hello") == sha256_text("hello")
    assert sha256_text("hello") != sha256_text("world")
    assert sha256_bytes(b"abc") == sha256_bytes(b"abc")
    print("  鉁?hashing is deterministic")


def test_composite_hash_changes_with_parts() -> None:
    h1 = composite_hash(["a", "b"])
    h2 = composite_hash(["a", "c"])
    h3 = composite_hash(["b", "a"])
    assert h1 != h2 and h1 != h3
    print("  鉁?composite_hash is order- and content-sensitive")


def test_sha256_file_matches_bytes() -> None:
    with tempfile.NamedTemporaryFile(delete=False, suffix=".bin") as f:
        f.write(b"the quick brown fox")
        tmp = f.name
    try:
        assert sha256_file(tmp) == sha256_bytes(b"the quick brown fox")
    finally:
        Path(tmp).unlink()
    print("  鉁?sha256_file matches sha256_bytes")


def test_classify_layer_name() -> None:
    """The full 17-prefix taxonomy. See PREFIXES.md."""
    # text
    assert classify_layer_name("txt_title") == "text"
    # button
    assert classify_layer_name("btn_login") == "button"
    # image (six flavours 鈥?they all collapse to 'image' for v1)
    for p in ("img_", "icon_", "bg_", "panel_", "mask_", "progress_", "fx_", "item_"):
        assert classify_layer_name(f"{p}foo") == "image", \
            f"{p} should classify as image"
    # composite (v1 partial support 鈥?each maps to its own type)
    assert classify_layer_name("input_username") == "input"
    assert classify_layer_name("scroll_main")    == "scroll"
    assert classify_layer_name("slider_volume")  == "slider"
    assert classify_layer_name("toggle_music")   == "toggle"
    # group
    for p in ("group_", "anim_", "root_"):
        assert classify_layer_name(f"{p}container") == "group", \
            f"{p} should classify as group"
    # no prefix 鈫?group
    assert classify_layer_name("Background") == "group"
    # case-insensitive (PS plugin emits lowercase, but be safe)
    assert classify_layer_name("BTN_Login") == "button"
    assert classify_layer_name("Txt_Title") == "text"
    print("  鉁?classify_layer_name covers the full 17-prefix taxonomy")


def test_sanitize_variable_name() -> None:
    """Prefix-aware pascalization. See PREFIXES.md."""
    # Known prefix 鈫?canonical PascalCase prefix + pascalized base.
    assert sanitize_variable_name("btn_close")     == "BtnClose"
    assert sanitize_variable_name("img_bg")        == "ImgBg"
    assert sanitize_variable_name("txt_title")     == "TxtTitle"
    assert sanitize_variable_name("icon_heart")    == "IconHeart"
    assert sanitize_variable_name("bg_login")      == "BgLogin"
    assert sanitize_variable_name("panel_main")    == "PanelMain"
    assert sanitize_variable_name("scroll_main")   == "ScrollMain"
    assert sanitize_variable_name("toggle_music")  == "ToggleMusic"
    assert sanitize_variable_name("input_user")    == "InputUser"
    assert sanitize_variable_name("slider_vol")    == "SliderVol"
    assert sanitize_variable_name("progress_bar")  == "ProgressBar"
    assert sanitize_variable_name("mask_overlay")  == "MaskOverlay"
    assert sanitize_variable_name("item_template") == "ItemTemplate"
    assert sanitize_variable_name("fx_glow")       == "FxGlow"
    # Group prefix 鈫?just pascalize the whole thing
    assert sanitize_variable_name("group_login")   == "GroupLogin"
    assert sanitize_variable_name("anim_intro")    == "AnimIntro"
    assert sanitize_variable_name("root_main")     == "RootMain"
    # Multi-word base
    assert sanitize_variable_name("btn_login_01")  == "BtnLogin01"
    # Mixed separators
    assert sanitize_variable_name("btn-login-main") == "BtnLoginMain"
    # Empty / weird
    assert sanitize_variable_name("")              == "Node"
    assert sanitize_variable_name("btn_")          == "Btn"
    # No prefix 鈫?pascalize the whole thing
    assert sanitize_variable_name("myLayer")       == "MyLayer"
    print("  鉁?sanitize_variable_name is prefix-aware across all 17 types")


# 鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€
#  End-to-end test with mocked PSD
# 鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€

class _MockBbox:
    """A `bbox` object that supports the (x0, y0, x1, y1) tuple protocol."""
    def __init__(self, x: int, y: int, w: int, h: int) -> None:
        self._t = (x, y, x + w, y + h)
    def __iter__(self):
        return iter(self._t)
    def __getitem__(self, i):
        return self._t[i]


class _MockLayer:
    """
    Stand-in for a psd-tools layer. Implements only what we use.

    The exporter dispatches by duck-typing (`_detect_kind`), so we just
    set the `kind` attribute (psd-tools convention) and that's enough.
    """
    def __init__(
        self,
        name: str,
        *,
        bbox=(0, 0, 100, 100),
        visible: bool = True,
        opacity: int = 255,
        kind: str = "pixel",
        text_payload: dict | None = None,
        children: Iterable["_MockLayer"] = (),
        pil: Image.Image | None = None,
    ) -> None:
        self.name = name
        self.bbox = _MockBbox(*bbox)
        self.visible = visible
        self.opacity = opacity
        self.kind = kind   # psd-tools convention: 'pixel' | 'type' | 'group' | 'shape'
        self._text_payload = text_payload
        self._children = list(children)
        self._pil = pil
        # `psd-tools` TypeLayer exposes `.text`; we mirror that.
        if kind == "type":
            self.text = text_payload
        else:
            self.text = None

    def __iter__(self):
        return iter(self._children)


def _make_pil(w: int, h: int, color: tuple[int, int, int, int]) -> Image.Image:
    return Image.new("RGBA", (w, h), color)


def test_exporter_export_path() -> None:
    """
    Regression test for the `export()` entry point. The bug we hit: when
    `export()` passed the `PSDImage` document to `_walk_layer`, the walker
    didn't know what to do with it and dropped all children. This test
    exercises the real `export()` flow with a mocked PSDImage that has
    top-level layers.

    The mock PSDImage:
      - is iterable (yields its top-level layers)
      - has .width, .height
    """
    # Build top-level layers (the same ones the e2e test uses).
    bg = _MockLayer("btn_login", kind="pixel", bbox=(100, 200, 300, 260),
                    pil=_make_pil(4, 4, (255, 0, 0, 255)))
    txt = _MockLayer("txt_title", kind="type", bbox=(0, 0, 600, 80),
                     pil=_make_pil(4, 4, (255, 255, 255, 255)))
    icon = _MockLayer("icon_heart", kind="pixel", bbox=(0, 0, 32, 32),
                      pil=_make_pil(4, 4, (255, 100, 100, 255)))

    class _FakePsd:
        width = 1920
        height = 1080
        name = "Root"
        def __iter__(self):
            return iter([bg, txt, icon])

    fake_psd = _FakePsd()

    # Patch PSDImage.open + convert_layer_to_pil
    from psd_exporter import exporter as exp_mod
    original_open = exp_mod.PSDImage.open
    original_convert = exp_mod._composite_layer
    exp_mod.PSDImage.open = staticmethod(lambda p: fake_psd)

    def _fake_convert(layer):
        if getattr(layer, "_pil", None) is not None:
            return layer._pil
        raise RuntimeError(f"unexpected convert on {layer.name}")
    exp_mod._composite_layer = _fake_convert

    try:
        with tempfile.TemporaryDirectory() as tmp:
            # Create a fake "input" PSD file just so the exporter can hash it.
            fake_psd_path = Path(tmp) / "Test.psd"
            fake_psd_path.write_bytes(b"fake psd bytes for hashing")

            exporter = PsdExporter(tmp)
            result = exporter.export(fake_psd_path)

            # Read the JSON back.
            json_path = Path(tmp) / "Test" / "Test.json"
            assert json_path.exists(), f"JSON not written: {json_path}"
            payload = json.loads(json_path.read_text(encoding="utf-8"))

            # 鈹€鈹€鈹€ Assertions 鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€
            assert payload["canvas"] == {"width": 1920, "height": 1080}
            assert payload["root"]["type"] == "group"
            # The bug: root had 0 children because export() was passing
            # the PSDImage to _walk_layer, which doesn't know how to walk
            # a document root. After the fix we expect all 3 children.
            kids = payload["root"]["children"]
            assert len(kids) == 3, (
                f"BUG REGRESSION: root has {len(kids)} children, expected 3. "
                f"Names: {[k['name'] for k in kids]}"
            )

            # Check the actual layer names came through.
            names = {k["name"] for k in kids}
            assert names == {"btn_login", "txt_title", "icon_heart"}, (
                f"Names mismatch: {names}"
            )

            # And the types are right.
            by_name = {k["name"]: k for k in kids}
            assert by_name["btn_login"]["type"] == "button"
            assert by_name["txt_title"]["type"] == "text"
            assert by_name["icon_heart"]["type"] == "image"

            # Hashes were recorded for incremental.
            actual = len(result.node_hashes)
            assert actual == 3, f"expected 3 hashes, got {actual}: {list(result.node_hashes.keys())}"

            print("  鉁?export() walks PSDImage top-level layers correctly")
    finally:
        exp_mod.PSDImage.open = original_open
        exp_mod._composite_layer = original_convert


def test_exporter_end_to_end() -> None:
    # Build a small "PSD" tree:
    #   Root (group)
    #   鈹溾攢鈹€ Img_Bg         (pixel, 1920x1080, solid blue)
    #   鈹溾攢鈹€ Btn_Login      (group)
    #   鈹?  鈹溾攢鈹€ Img_Normal (pixel, 200x60, red)
    #   鈹?  鈹斺攢鈹€ Txt_Label  (type, 200x60, "Click me")
    #   鈹斺攢鈹€ Txt_Title      (type, 600x80, "Welcome")
    root = _MockLayer(
        "Root",
        kind="group",
        bbox=(0, 0, 1920, 1080),
        children=[
            _MockLayer("Img_Bg", kind="pixel", bbox=(0, 0, 1920, 1080),
                       pil=_make_pil(8, 8, (40, 80, 200, 255))),  # small thumbnail
            _MockLayer(
                "Btn_Login", kind="group", bbox=(100, 200, 300, 260),
                children=[
                    _MockLayer("Img_Normal", kind="pixel", bbox=(100, 200, 300, 260),
                               pil=_make_pil(4, 4, (255, 0, 0, 255))),
                    _MockLayer("Txt_Label", kind="type", bbox=(100, 200, 300, 260),
                               pil=_make_pil(4, 4, (255, 255, 255, 255))),
                ],
            ),
            _MockLayer("Txt_Title", kind="type", bbox=(100, 50, 700, 130),
                       pil=_make_pil(4, 4, (255, 255, 255, 200))),
        ],
    )

    # Patch convert_layer_to_pil so it returns our pre-built PIL.
    from psd_exporter import exporter as exp_mod
    original = exp_mod._composite_layer

    def _fake_convert(layer):
        if getattr(layer, "_pil", None) is not None:
            return layer._pil
        # For groups we shouldn't be called.
        raise RuntimeError(f"unexpected convert on {layer.name}")

    exp_mod._composite_layer = _fake_convert
    try:
        # Patch PSDImage.open to return our mock root.
        original_open = exp_mod.PSDImage.open
        exp_mod.PSDImage.open = staticmethod(lambda p: SimpleNamespace(
            width=1920, height=1080, __iter__=lambda self: iter([]),  # psd root isn't iterated
        ))

        with tempfile.TemporaryDirectory() as tmp:
            out_dir = Path(tmp) / "out"
            img_root = out_dir / "Welcome" / "images"
            img_root.mkdir(parents=True, exist_ok=True)
            exporter = PsdExporter(out_dir)
            from psd_exporter.exporter import _WalkContext  # noqa: E402
            ctx = _WalkContext(image_root=img_root,
                               image_subdir="images")
            tree = exporter._walk_layer(root, "root", ctx)

            assert tree.type == "group"
            assert len(tree.children) == 3, f"expected 3 children, got {len(tree.children)}"
            bg, btn, title = tree.children
            assert bg.type == "image", f"Img_Bg should be image, got {bg.type}"
            assert bg.image_hash and bg.image_file
            assert btn.type == "group", "Btn_Login should be a group"
            assert len(btn.children) == 2
            assert btn.children[0].type == "image"
            assert btn.children[1].type == "text"
            assert title.type == "text"
            assert title.text and "content" in title.text

            # Check JSON serialization round-trip.
            d = tree.to_dict()
            assert d["id"] == "root/Root"
            assert d["children"][0]["imageHash"].startswith("sha256:")
            assert d["children"][1]["children"][1]["text"]["alignment"] in {
                "MiddleCenter", "UpperCenter", "UpperLeft",  # whatever the fallback gave
            }

            print("  ✓ exporter end-to-end produces correct tree shape")
            print(f"    bg.imageHash  = {bg.image_hash[:24]}...")
            print(f"    title.textHash= {title.text_hash[:24]}...")
            print(f"    node count    = {len(ctx.node_hashes)}")

    finally:
        exp_mod._composite_layer = original
        exp_mod.PSDImage.open = original_open


# 鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€
#  Runner
# 鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€鈹€

def run_all() -> int:
    print("[unit] hashing & helpers")
    test_hashing_is_deterministic()
    test_composite_hash_changes_with_parts()
    test_sha256_file_matches_bytes()
    test_classify_layer_name()
    test_sanitize_variable_name()
    print("[e2e ] exporter")
    test_exporter_export_path()
    test_exporter_end_to_end()
    print("\nAll tests passed.")
    return 0


if __name__ == "__main__":
    sys.exit(run_all())

