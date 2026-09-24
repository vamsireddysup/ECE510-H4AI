#!/usr/bin/env python3
"""Check the active Markdown files for simple structural mistakes."""

from __future__ import annotations

import re
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
ACTIVE_FILES = [
    REPO_ROOT / "README.md",
    REPO_ROOT / "CODEX.md",
    REPO_ROOT / "CONTRIBUTING.md",
    REPO_ROOT / "CHANGELOG.md",
    REPO_ROOT / "rtl/README.md",
    REPO_ROOT / "tb/README.md",
    *sorted((REPO_ROOT / "docs").rglob("*.md")),
]
LINK_PATTERN = re.compile(r"\[[^]]+\]\(([^)]+)\)")


def main() -> int:
    errors: list[str] = []
    for path in ACTIVE_FILES:
        text = path.read_text()
        h1_count = sum(line.startswith("# ") for line in text.splitlines())
        if h1_count != 1:
            errors.append(f"{path.relative_to(REPO_ROOT)}: expected one H1, found {h1_count}")
        for target in LINK_PATTERN.findall(text):
            if "://" in target or target.startswith("#"):
                continue
            relative_target = target.split("#", 1)[0]
            if relative_target and not (path.parent / relative_target).exists():
                errors.append(f"{path.relative_to(REPO_ROOT)}: broken link {target}")

    if errors:
        print("\n".join(errors))
        return 1
    print(f"Markdown checks passed: {len(ACTIVE_FILES)} files")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
