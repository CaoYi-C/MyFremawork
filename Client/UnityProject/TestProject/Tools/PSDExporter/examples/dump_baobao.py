import json, os

p = r"D:\UnityProject\Test\MyFremawork\Client\UnityProject\TestProject\Tools\PSDExporter\PSDExport\背包\背包.json"
with open(p, encoding="utf-8") as f:
    d = json.load(f)

def walk(n, depth=0):
    if n.get("imageFile"):
        print(f"  depth={depth} type={n.get('type')!r} name={n.get('name')!r}  imageFile={n['imageFile']!r}")
    for c in n.get("children") or []:
        walk(c, depth + 1)
walk(d["root"])
