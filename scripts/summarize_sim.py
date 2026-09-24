#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Summarize accepted AXI beats and simulated QK^T work from integration logs."""
from __future__ import annotations

import csv
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PATTERN = re.compile(
    r"T=(\d+) D=(\d+) scores=(\d+) tiles=(\d+) cycles=(\d+) "
    r"in_beats=(\d+) out_beats=(\d+) stalls=(\d+) PASS"
)
DIR_PATTERN = re.compile(
    r"b(\d+)-t(\d+)-d(\d+)-reuse([01])-sb(\d+)-sl(\d+)"
)
COLUMNS = (
    "tile_size", "t_max", "d_head", "k_reuse", "scale_block_size",
    "score_lanes", "T", "tiles",
    "scores", "cycles", "scores_per_cycle", "array_utilization",
    "input_beats", "output_beats", "output_stalls", "host_bytes",
    "useful_bytes", "flops", "wire_flops_per_byte"
)


def rows() -> list[dict[str, int | float]]:
    data = []
    for log in sorted((ROOT / "build/integration").glob("*/run.log")):
        config = DIR_PATTERN.fullmatch(log.parent.name)
        if not config:
            continue
        tile, t_max, depth, reuse, scale_block, score_lanes = map(
            int, config.groups()
        )
        seen: set[int] = set()
        for match in PATTERN.finditer(log.read_text()):
            t, measured_depth, scores, tiles, cycles, in_beats, out_beats, stalls = map(int, match.groups())
            if t in seen or measured_depth != depth:
                continue
            seen.add(t)
            flops = 2 * t * t * depth
            host_bytes = 8 * (in_beats + out_beats)
            data.append({
                "tile_size": tile, "t_max": t_max, "d_head": depth,
                "k_reuse": reuse, "scale_block_size": scale_block,
                "score_lanes": score_lanes, "T": t, "tiles": tiles,
                "scores": scores,
                "cycles": cycles, "scores_per_cycle": scores / cycles,
                "array_utilization": flops / (cycles * 2 * tile * tile),
                "input_beats": in_beats, "output_beats": out_beats,
                "output_stalls": stalls, "host_bytes": host_bytes,
                "useful_bytes": (
                    t * depth + 8 * t * ((depth + scale_block - 1) // scale_block)
                    + 4 * t * t
                ),
                "flops": flops, "wire_flops_per_byte": flops / host_bytes,
            })
    return data


def main() -> int:
    writer = csv.DictWriter(sys.stdout, fieldnames=COLUMNS)
    writer.writeheader()
    writer.writerows(rows())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
