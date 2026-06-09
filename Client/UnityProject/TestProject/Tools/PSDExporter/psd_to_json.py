#!/usr/bin/env python
"""
psd_to_json.py — CLI entry point for the PSD2UGUI exporter.

Usage:
    python psd_to_json.py <input.psd> [--out <output_dir>] [--log-level INFO]

Exit codes:
    0  success
    1  bad arguments
    2  PSD open / parse error
    3  unexpected error

The tool writes:
    <out>/<PsdName>/<PsdName>.json
    <out>/<PsdName>/images/<layerId>.png
"""
from __future__ import annotations

import argparse
import logging
import sys
from pathlib import Path

# Make `psd_exporter` importable when running from this directory.
sys.path.insert(0, str(Path(__file__).resolve().parent))

from psd_exporter.exporter import PsdExporter  # noqa: E402


def _setup_logging(level: str) -> None:
    logging.basicConfig(
        level=getattr(logging, level.upper(), logging.INFO),
        format="%(asctime)s [%(levelname)s] %(message)s",
        datefmt="%H:%M:%S",
    )


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(
        prog="psd_to_json",
        description="Convert a PSD file to JSON + PNGs for the Unity PSD2UGUI importer.",
    )
    parser.add_argument("psd", help="Path to the input .psd file")
    parser.add_argument(
        "--out",
        default="./PSDExport",
        help="Output root directory (default: ./PSDExport)",
    )
    parser.add_argument(
        "--log-level",
        default="INFO",
        choices=["DEBUG", "INFO", "WARNING", "ERROR"],
        help="Logging verbosity (default: INFO)",
    )
    parser.add_argument(
        "--all-layers",
        action="store_true",
        help=(
            "Export the full layer tree (no filter). "
            "Default is to export only layers whose name starts with one "
            "of the UGUI prefixes — see PREFIXES.md."
        ),
    )
    args = parser.parse_args(argv)

    _setup_logging(args.log_level)
    log = logging.getLogger("psd2ugui.cli")

    psd_path = Path(args.psd)
    if not psd_path.is_file():
        log.error("PSD not found: %s", psd_path)
        return 1

    try:
        exporter = PsdExporter(
            output_root=args.out,
            marked_only=not args.all_layers,
        )
        result = exporter.export(psd_path)
    except Exception as e:
        log.exception("Export failed: %s", e)
        return 2

    log.info("Done. JSON: %s", result.json_path)
    log.info("Images: %s", result.image_root)
    log.info("Nodes:  %d", len(result.node_types))
    if result.warnings:
        log.info("Warnings: %d (see above)", len(result.warnings))

    return 0


if __name__ == "__main__":
    sys.exit(main())
