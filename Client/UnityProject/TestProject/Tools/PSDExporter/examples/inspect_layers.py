import sys
from psd_tools import PSDImage
from pathlib import Path

psd = PSDImage.open(r"C:\Users\WWCY\Downloads\背包.psd")

# Print the top-level first
print(f"PSD document, {psd.width}x{psd.height}, {len(list(psd))} top-level layers")
for tl in psd:
    print(f"  top: kind={getattr(tl, 'kind', '?')} name={tl.name!r}")
print()

# Now recurse
def walk(layer, depth=0):
    name = layer.name
    kind = getattr(layer, "kind", "?")
    print(f"{'  ' * depth}[{kind}] {name!r}")
    if hasattr(layer, "__iter__") and not isinstance(layer, type(psd)):
        for child in layer:
            walk(child, depth + 1)

print("--- All layers ---")
for tl in psd:
    walk(tl, 0)
