#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Closed-form cycle model for the overlapped tile pipeline."""
from __future__ import annotations

import sys
from math import ceil

SCALE_PIPELINE_LATENCY = 6
ADD_PIPELINE_LATENCY = 3


def stage_costs(
    tile: int, depth: int, k_reuse: bool = False,
    block_size: int = 32, score_lanes: int = 1,
) -> dict[str, int]:
    """Sustained per-tile service time of each concurrent stage."""
    stages = {
        "CALC": depth,
        "SCALING": ceil(tile * tile / score_lanes) + SCALE_PIPELINE_LATENCY
        + ADD_PIPELINE_LATENCY * (ceil(depth / block_size) - 1),
        "OUTPUT": ceil(tile * tile / 2),
    }
    if not k_reuse:
        stages = {"LOAD_K": ceil(tile * depth / 16), **stages}
    return stages


def core_cycles(
    seq: int, tile: int, depth: int, k_reuse: bool = False,
    block_size: int = 32, score_lanes: int = 1,
) -> int:
    """Exact no-stall command cycles for benchmark dimensions divisible by tile."""
    tile_beats = ceil(tile * depth / 16)
    tile_rows = seq // tile
    tile_total = tile_rows * tile_rows
    stages = stage_costs(tile, depth, k_reuse, block_size, score_lanes)
    pipeline = sum(stages.values()) + (tile_total - 1) * max(stages.values())
    # Scales are command startup. Version 2 then fills the complete K cache.
    # The first Q tile is the final fill stage before the tile pipeline starts;
    # subsequent Q loads fit behind the binding stage with two Q banks.
    startup = seq * ceil(depth / block_size) + tile_beats
    if k_reuse:
        startup += tile_rows * tile_beats
    return startup + pipeline


def input_beats(
    seq: int, tile: int, depth: int, k_reuse: bool = False,
    block_size: int = 32,
) -> int:
    tile_beats = ceil(tile * depth / 16)
    tile_rows = seq // tile
    if k_reuse:
        return seq * ceil(depth / block_size) + 2 * tile_rows * tile_beats
    return (seq * ceil(depth / block_size) + tile_rows * tile_beats
            + tile_rows * tile_rows * tile_beats)


def binding_stage(
    tile: int, depth: int, k_reuse: bool = False,
    block_size: int = 32, score_lanes: int = 1,
) -> tuple[str, int]:
    stages = stage_costs(tile, depth, k_reuse, block_size, score_lanes)
    name = max(stages, key=lambda key: stages[key])
    return name, stages[name]


# Measured on master with Verilator 5.041 and a continuously ready host.
# (label, seq, tile, depth, k_reuse, block size, score lanes, cycles, beats)
MEASURED = [
    ("v3 4x4 T=64", 64, 4, 64, False, 32, 1, 16_577, 4_480),
    ("v3 4x4 T=128", 128, 4, 64, False, 32, 1, 65_857, 17_152),
    ("v3 4x4 T=512", 512, 4, 64, False, 32, 1, 1_049_665, 265_216),
    ("v4 4x4 T=64", 64, 4, 64, True, 32, 1, 16_817, 640),
    ("v4 4x4 T=128", 128, 4, 64, True, 32, 1, 66_353, 1_280),
    ("v4 4x4 T=512", 512, 4, 64, True, 32, 1, 1_051_697, 5_120),
    ("v3 8x8 L1 T=64", 64, 8, 64, False, 32, 1, 4_960, 2_432),
    ("v3 8x8 L1 T=128", 128, 8, 64, False, 32, 1, 19_104, 8_960),
    ("v3 8x8 L1 T=512", 512, 8, 64, False, 32, 1, 300_192, 134_144),
    ("v3 16x16 L1 T=64", 64, 16, 64, False, 32, 1, 4_688, 1_408),
    ("v3 16x16 L1 T=128", 128, 16, 64, False, 32, 1, 17_536, 4_864),
    ("v3 16x16 L1 T=512", 512, 16, 64, False, 32, 1, 272_704, 68_608),
    ("v3 8x8 L2 T=512", 512, 8, 64, False, 32, 2, 263_305, 134_144),
    ("v3 8x8 L4 T=512", 512, 8, 64, False, 32, 4, 263_289, 134_144),
    ("v3 16x16 L2 T=512", 512, 16, 64, False, 32, 2, 141_632, 68_608),
    ("v3 16x16 L4 T=512", 512, 16, 64, False, 32, 4, 132_361, 68_608),
]


def main() -> int:
    failures = 0
    print(f"{'configuration':16} {'model':>10} {'measured':>10} {'beats':>9} {'meas':>9}")
    for (label, seq, tile, depth, reuse, block_size, score_lanes,
         want_cycles, want_beats) in MEASURED:
        got_cycles = core_cycles(
            seq, tile, depth, reuse, block_size, score_lanes
        )
        got_beats = input_beats(seq, tile, depth, reuse, block_size)
        ok = got_cycles == want_cycles and got_beats == want_beats
        failures += not ok
        print(f"{label:16} {got_cycles:>10,} {want_cycles:>10,} "
              f"{got_beats:>9,} {want_beats:>9,}{'' if ok else '   MISMATCH'}")

    print("\nPer-tile service times at D_HEAD=64:")
    for tile in (4, 8, 16):
        for lanes in (1, 2, 4):
            stages = stage_costs(tile, 64, block_size=32, score_lanes=lanes)
            name, cost = binding_stage(
                tile, 64, block_size=32, score_lanes=lanes
            )
            parts = " ".join(f"{key}={value}" for key, value in stages.items())
            print(f"  {tile:>2}x{tile:<2} L={lanes} {parts}; "
                  f"{name} binds at {cost} cycles/tile")

    if failures:
        print(f"\n{failures} configuration(s) do not match. "
              "Either the scheduler changed or docs/architecture.md is stale.")
        return 1
    print("\nAll measured configurations reproduced exactly.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
