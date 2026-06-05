"""
Hashing utilities for incremental PSD export.

We use SHA-256 throughout. Hash inputs are normalized to bytes so
the same logical content always produces the same hash regardless of
the source platform.
"""
from __future__ import annotations

import hashlib
from typing import Iterable


def sha256_bytes(data: bytes) -> str:
    """Return `sha256:<hex>` of raw bytes."""
    return "sha256:" + hashlib.sha256(data).hexdigest()


def sha256_text(text: str) -> str:
    """Return `sha256:<hex>` of a UTF-8 string. Used for text content hashing."""
    return sha256_bytes(text.encode("utf-8"))


def sha256_file(path: str, chunk: int = 65536) -> str:
    """Return `sha256:<hex>` of a file, streamed (PSD files can be huge)."""
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for blk in iter(lambda: f.read(chunk), b""):
            h.update(blk)
    return "sha256:" + h.hexdigest()


def composite_hash(parts: Iterable[str]) -> str:
    """
    Combine several `sha256:...` strings (or any token) into one hash.

    Used to derive `textHash` from (content, fontName, fontSize, color, alignment)
    so that any of those fields changing invalidates the node.
    """
    h = hashlib.sha256()
    for p in parts:
        h.update(p.encode("utf-8"))
        h.update(b"|")
    return "sha256:" + h.hexdigest()
