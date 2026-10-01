#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Re-simulate every recorded cycle-model configuration against the current RTL."""
from __future__ import annotations

import os
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from cycle_model import MEASURED  # noqa: E402

REPO = Path(__file__).resolve().parent.parent
LINE = re.compile(r"^T=(\d+) D=(\d+) .* cycles=(\d+) in_beats=(\d+) .* PASS$")


def suite(tile: int, reuse: bool) -> str:
    if tile == 4:
        return "--reuse-large" if reuse else "--large"
    if reuse:
        raise ValueError("no large K-reuse suite for tile sizes above 4")
    return f"--array{tile}-large"


def main() -> int:
    runs: dict[tuple, list] = defaultdict(list)
    for row in MEASURED:
        label, seq, tile, depth, reuse, block, lanes, engines, scale_format, cycles, beats = row
        runs[(tile, reuse, block, lanes, engines, scale_format)].append(row)
    failures = 0
    for (tile, reuse, block, lanes, engines, scale_format), rows in runs.items():
        environment = dict(os.environ, SCALE_BLOCK_SIZE=str(block),
                           SCORE_LANES=str(lanes), ENGINES=str(engines),
                           SCALE_FORMAT=str(scale_format))
        output = subprocess.run(
            [str(REPO / "scripts/run_integration.sh"), suite(tile, reuse)],
            cwd=REPO, env=environment, capture_output=True, text=True,
        ).stdout
        seen = {}
        for line in output.splitlines():
            match = LINE.match(line.strip())
            if match:
                seen[int(match.group(1))] = (int(match.group(3)), int(match.group(4)))
        for label, seq, *_rest, cycles, beats in rows:
            got = seen.get(seq)
            ok = got == (cycles, beats)
            failures += not ok
            print(f"{label:22} recorded {cycles:>9,} {beats:>8,}  "
                  f"simulated {'missing' if got is None else f'{got[0]:>9,} {got[1]:>8,}'}"
                  f"{'' if ok else '   MISMATCH'}", flush=True)
    print(f"\n{len(MEASURED) - failures} of {len(MEASURED)} recorded configurations reproduce.")
    return 1 if failures else 0


if __name__ == "__main__":
    sys.exit(main())
