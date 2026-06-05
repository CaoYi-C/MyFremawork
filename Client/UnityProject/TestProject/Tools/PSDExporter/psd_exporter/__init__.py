"""
psd2ugui - PSD to UGUI exporter.

A Python tool that converts Adobe Photoshop (.psd) files into a JSON
intermediate format + extracted PNG images, which the Unity side
(Assets/Editor/PSDImporter) consumes to build UGUI prefabs.

See SCHEMA.md for the JSON contract.
"""

__version__ = "0.1.0"
