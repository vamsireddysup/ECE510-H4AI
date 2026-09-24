#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Enforce the mechanical parts of the documentation contract.

The contract is in docs/repository-layout.md. This script checks what a machine
can check:

  * exactly one H1 per document;
  * every relative link resolves, including its #anchor;
  * every document has a "## Related" section;
  * every document is reachable from README.md within MAX_HOPS.

Prose accuracy is not checkable here and stays the author's job.

Usage, from the repository root:

    python3 scripts/check_markdown.py
"""

from __future__ import annotations

import re
import sys
from collections import deque
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
ENTRY_POINT = REPO_ROOT / "README.md"
MAX_HOPS = 2

# Documents outside docs/ that are part of the active set. Everything under
# docs/ is included automatically.
EXTRA_ACTIVE = [
    "README.md",
    "CODEX.md",
    "CONTRIBUTING.md",
    "CHANGELOG.md",
    "rtl/README.md",
    "tb/README.md",
    "model/README.md",
    "scripts/README.md",
    "archive/README.md",
    "archive/superseded-rtl/README.md",
]

# Historical coursework keeps its original voice and structure, so it is linkable
# but never checked.
EXEMPT_PREFIXES = ("archive/coursework/", "archive/experiments/")

LINK_PATTERN = re.compile(r"(?<!!)\[[^]]*\]\(([^)\s]+)\)")
FENCE_PATTERN = re.compile(r"^\s*```")


def active_files() -> list[Path]:
    paths = {REPO_ROOT / name for name in EXTRA_ACTIVE}
    paths.update((REPO_ROOT / "docs").rglob("*.md"))
    return sorted(p for p in paths if p.exists())


def strip_fenced_code(text: str) -> str:
    """Drop fenced code blocks so example paths inside them are not link-checked."""
    out, inside = [], False
    for line in text.splitlines():
        if FENCE_PATTERN.match(line):
            inside = not inside
            continue
        out.append("" if inside else line)
    return "\n".join(out)


def anchor_slugs(text: str) -> set[str]:
    """GitHub-style slugs for every heading in a document."""
    slugs = set()
    for line in strip_fenced_code(text).splitlines():
        if not line.startswith("#"):
            continue
        title = line.lstrip("#").strip()
        slug = re.sub(r"[^\w\- ]", "", title.lower()).replace(" ", "-")
        if slug:
            slugs.add(slug)
    return slugs


def is_exempt(path: Path) -> bool:
    rel = path.relative_to(REPO_ROOT).as_posix()
    return rel.startswith(EXEMPT_PREFIXES)


def main() -> int:
    errors: list[str] = []
    files = active_files()
    # Markdown targets each document links to, for the reachability walk.
    links_out: dict[Path, set[Path]] = {}

    for path in files:
        rel = path.relative_to(REPO_ROOT)
        raw = path.read_text()
        body = strip_fenced_code(raw)

        h1s = [line for line in body.splitlines() if line.startswith("# ")]
        if len(h1s) != 1:
            errors.append(f"{rel}: expected one H1, found {len(h1s)}")

        if not re.search(r"^## Related\s*$", body, re.MULTILINE):
            errors.append(f"{rel}: no '## Related' section")

        targets: set[Path] = set()
        for target in LINK_PATTERN.findall(body):
            if "://" in target or target.startswith(("#", "mailto:")):
                if target.startswith("#") and target[1:] not in anchor_slugs(raw):
                    errors.append(f"{rel}: link to missing anchor {target}")
                continue

            file_part, _, anchor = target.partition("#")
            if not file_part:
                continue
            resolved = (path.parent / file_part).resolve()
            if not resolved.exists():
                errors.append(f"{rel}: broken link {target}")
                continue
            if anchor and resolved.suffix == ".md":
                if anchor not in anchor_slugs(resolved.read_text()):
                    errors.append(f"{rel}: link to missing anchor {target}")
            if resolved.suffix == ".md":
                targets.add(resolved)

        links_out[path] = targets

    # Reachability from README.md, breadth first, counting hops.
    depth = {ENTRY_POINT: 0}
    queue = deque([ENTRY_POINT])
    while queue:
        current = queue.popleft()
        for nxt in links_out.get(current, ()):  # unlisted documents are leaves
            if nxt not in depth:
                depth[nxt] = depth[current] + 1
                queue.append(nxt)

    for path in files:
        if is_exempt(path):
            continue
        rel = path.relative_to(REPO_ROOT)
        hops = depth.get(path)
        if hops is None:
            errors.append(f"{rel}: not reachable from README.md")
        elif hops > MAX_HOPS:
            errors.append(f"{rel}: {hops} hops from README.md, limit is {MAX_HOPS}")

    if errors:
        print("\n".join(errors))
        print(f"\n{len(errors)} problem(s). The contract is in docs/repository-layout.md.")
        return 1
    print(f"Markdown checks passed: {len(files)} files, "
          f"all within {MAX_HOPS} hops of README.md")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
