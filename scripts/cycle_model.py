#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Closed-form cycle model for the overlapped tile pipeline."""
from __future__ import annotations

import sys
from math import ceil

SCALE_PIPELINE_LATENCY = 6


def stage_costs(tile: int, depth: int, k_reuse: bool = False) -> dict[str, int]:
    """Sustained per-tile service time of each concurrent stage."""
    stages = {
        "CALC": depth,
        "SCALING": tile * tile + SCALE_PIPELINE_LATENCY,
        "OUTPUT": ceil(tile * tile / 2),
    }
    if not k_reuse:
        stages = {"LOAD_K": ceil(tile * depth / 16), **stages}
    return stages


def core_cycles(seq: int, tile: int, depth: int, k_reuse: bool = False) -> int:
    """Exact no-stall command cycles for benchmark dimensions divisible by tile."""
    tile_beats = ceil(tile * depth / 16)
    tile_rows = seq // tile
    tile_total = tile_rows * tile_rows
    stages = stage_costs(tile, depth, k_reuse)
    pipeline = sum(stages.values()) + (tile_total - 1) * max(stages.values())
    # Scales are command startup. Version 2 then fills the complete K cache.
    # The first Q tile is the final fill stage before the tile pipeline starts;
    # subsequent Q loads fit behind the binding stage with two Q banks.
    startup = seq + tile_beats
    if k_reuse:
        startup += tile_rows * tile_beats
    return startup + pipeline


def input_beats(seq: int, tile: int, depth: int, k_reuse: bool = False) -> int:
    tile_beats = ceil(tile * depth / 16)
    tile_rows = seq // tile
    if k_reuse:
        return seq + tile_rows * tile_beats + tile_rows * tile_beats
    return seq + tile_rows * tile_beats + tile_rows * tile_rows * tile_beats


def binding_stage(tile: int, depth: int, k_reuse: bool = False) -> tuple[str, int]:
    stages = stage_costs(tile, depth, k_reuse)
    name = max(stages, key=lambda key: stages[key])
    return name, stages[name]


# Measured on master with Verilator 5.041 and a continuously ready host.
# (label, seq, tile, depth, k_reuse, core cycles, input beats)
MEASURED = [
    ("v1 4x4 T=64", 64, 4, 64, False, 16_510, 4_416),
    ("v1 4x4 T=128", 128, 4, 64, False, 65_726, 17_024),
    ("v1 4x4 T=512", 512, 4, 64, False, 1_049_150, 264_704),
    ("v2 4x4 T=512", 512, 4, 64, True, 1_051_182, 4_608),
    ("v1 8x8 T=512", 512, 8, 64, False, 287_392, 133_632),
    ("v1 16x16 T=512", 512, 16, 64, False, 269_120, 68_096),
]


def main() -> int:
    failures = 0
    print(f"{'configuration':16} {'model':>10} {'measured':>10} {'beats':>9} {'meas':>9}")
    for label, seq, tile, depth, reuse, want_cycles, want_beats in MEASURED:
        got_cycles = core_cycles(seq, tile, depth, reuse)
        got_beats = input_beats(seq, tile, depth, reuse)
        ok = got_cycles == want_cycles and got_beats == want_beats
        failures += not ok
        print(f"{label:16} {got_cycles:>10,} {want_cycles:>10,} "
              f"{got_beats:>9,} {want_beats:>9,}{'' if ok else '   MISMATCH'}")

    print("\nPer-tile service times at D_HEAD=64:")
    for tile in (4, 8, 16):
        stages = stage_costs(tile, 64)
        name, cost = binding_stage(tile, 64)
        parts = " ".join(f"{key}={value}" for key, value in stages.items())
        print(f"  {tile:>2}x{tile:<2} {parts}; {name} binds at {cost} cycles/tile")

    if failures:
        print(f"\n{failures} configuration(s) do not match. "
              "Either the scheduler changed or docs/architecture.md is stale.")
        return 1
    print("\nAll measured configurations reproduced exactly.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
