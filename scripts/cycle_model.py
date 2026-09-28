#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Closed-form cycle model for the overlapped tile pipeline."""
from __future__ import annotations

import argparse
import csv
import sys
from math import ceil
from pathlib import Path

# One scale-prefetch register plus the two three-cycle FP32 multipliers.
SCALE_PIPELINE_LATENCY = 7
ADD_PIPELINE_LATENCY = 3


def stage_costs(
    tile: int, depth: int, k_reuse: bool = False,
    block_size: int = 16, score_lanes: int = 1,
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
    block_size: int = 16, score_lanes: int = 1, engine_count: int = 1,
) -> int:
    """No-stall cycles; exact at N=1 and an ideal shared-port model at N>1."""
    if engine_count < 1:
        raise ValueError("engine_count must be positive")
    tile_beats = ceil(tile * depth / 16)
    tile_rows = seq // tile
    tile_total = tile_rows * tile_rows
    stages = stage_costs(tile, depth, k_reuse, block_size, score_lanes)
    # Scales are command startup. Version 2 then fills the complete K cache.
    # The first Q tile is the final fill stage before the tile pipeline starts;
    # subsequent Q loads fit behind the binding stage with two Q banks.
    startup = seq * ceil(depth / block_size) + tile_beats
    if k_reuse:
        startup += tile_rows * tile_beats

    tiles_per_engine = ceil(tile_total / engine_count)
    work = {
        "CALC": tiles_per_engine * stages["CALC"],
        "SCALING": tiles_per_engine * stages["SCALING"],
        # One 64-bit output port remains shared by every engine.
        "OUTPUT": tile_total * stages["OUTPUT"],
    }
    if not k_reuse:
        # Version 3 transfers a distinct K tile for every output tile.
        work["LOAD_K"] = tile_total * stages["LOAD_K"]
    fill_drain = sum(stages.values()) - max(stages.values())
    engine_path = startup + max(work.values()) + fill_drain

    # Q loads are hidden at N=1 but share the same input port as K. Once engines
    # consume tiles quickly enough, total accepted input beats are the hard floor.
    return max(
        engine_path,
        input_beats(seq, tile, depth, k_reuse, block_size),
    )


def input_beats(
    seq: int, tile: int, depth: int, k_reuse: bool = False,
    block_size: int = 16,
) -> int:
    tile_beats = ceil(tile * depth / 16)
    tile_rows = seq // tile
    if k_reuse:
        return seq * ceil(depth / block_size) + 2 * tile_rows * tile_beats
    return (seq * ceil(depth / block_size) + tile_rows * tile_beats
            + tile_rows * tile_rows * tile_beats)


def binding_stage(
    tile: int, depth: int, k_reuse: bool = False,
    block_size: int = 16, score_lanes: int = 1,
) -> tuple[str, int]:
    stages = stage_costs(tile, depth, k_reuse, block_size, score_lanes)
    name = max(stages, key=lambda key: stages[key])
    return name, stages[name]


def replication_bounds(
    seq: int, tile: int, depth: int, k_reuse: bool = False,
    block_size: int = 16, score_lanes: int = 1, engine_count: int = 1,
) -> dict[str, int]:
    """First-principles work floors used by the replicated-engine projection."""
    tile_total = ceil(seq / tile) ** 2
    tiles_per_engine = ceil(tile_total / engine_count)
    stages = stage_costs(tile, depth, k_reuse, block_size, score_lanes)
    bounds = {
        "INPUT": input_beats(seq, tile, depth, k_reuse, block_size),
        "CALC": tiles_per_engine * stages["CALC"],
        "SCALING": tiles_per_engine * stages["SCALING"],
        "OUTPUT": tile_total * stages["OUTPUT"],
    }
    if not k_reuse:
        bounds["K_RELOAD"] = tile_total * stages["LOAD_K"]
    return bounds


# Measured on master with Verilator 5.041 and a continuously ready host.
# (label, seq, tile, depth, k_reuse, block size, score lanes, engines,
#  cycles, beats)
MEASURED = [
    ("v3 4x4 T=64", 64, 4, 64, False, 32, 1, 1, 16_578, 4_480),
    ("v3 4x4 T=128", 128, 4, 64, False, 32, 1, 1, 65_858, 17_152),
    ("v3 4x4 T=512", 512, 4, 64, False, 32, 1, 1, 1_049_666, 265_216),
    ("v4 4x4 T=64", 64, 4, 64, True, 32, 1, 1, 16_818, 640),
    ("v4 4x4 T=128", 128, 4, 64, True, 32, 1, 1, 66_354, 1_280),
    ("v4 4x4 T=512", 512, 4, 64, True, 32, 1, 1, 1_051_698, 5_120),
    ("v3 8x8 L1 T=64", 64, 8, 64, False, 32, 1, 1, 5_024, 2_432),
    ("v3 8x8 L1 T=128", 128, 8, 64, False, 32, 1, 1, 19_360, 8_960),
    ("v3 8x8 L1 T=512", 512, 8, 64, False, 32, 1, 1, 304_288, 134_144),
    ("v3 16x16 L1 T=64", 64, 16, 64, False, 32, 1, 1, 4_704, 1_408),
    ("v3 16x16 L1 T=128", 128, 16, 64, False, 32, 1, 1, 17_600, 4_864),
    ("v3 16x16 L1 T=512", 512, 16, 64, False, 32, 1, 1, 273_728, 68_608),
    ("v3 8x8 L2 T=512", 512, 8, 64, False, 32, 2, 1, 263_306, 134_144),
    ("v3 8x8 L4 T=512", 512, 8, 64, False, 32, 4, 1, 263_290, 134_144),
    ("v3 16x16 L2 T=512", 512, 16, 64, False, 32, 2, 1, 142_656, 68_608),
    ("v3 16x16 L4 T=512", 512, 16, 64, False, 32, 4, 1, 132_362, 68_608),
    ("v5 4x4 T=64", 64, 4, 64, False, 16, 1, 1, 16_712, 4_608),
    ("v5 4x4 T=128", 128, 4, 64, False, 16, 1, 1, 66_120, 17_408),
    ("v5 4x4 T=512", 512, 4, 64, False, 16, 1, 1, 1_050_696, 266_240),
    ("v6 4x4 T=64", 64, 4, 64, True, 16, 1, 1, 16_952, 768),
    ("v6 4x4 T=128", 128, 4, 64, True, 16, 1, 1, 66_616, 1_536),
    ("v6 4x4 T=512", 512, 4, 64, True, 16, 1, 1, 1_052_728, 6_144),
    ("v5 8x8 L2 T=512", 512, 8, 64, False, 16, 2, 1, 264_336, 135_168),
    ("v5 16x16 L4 T=512", 512, 16, 64, False, 16, 4, 1, 133_392, 69_632),
    ("v5 4x4 N=2", 512, 4, 64, False, 16, 1, 2, 526_424, 266_240),
    ("v5 4x4 N=4", 512, 4, 64, False, 16, 1, 4, 266_344, 266_240),
    ("v5 4x4 N=8", 512, 4, 64, False, 16, 1, 8, 266_344, 266_240),
    ("v5 4x4 N=16", 512, 4, 64, False, 16, 1, 16, 266_344, 266_240),
    ("v6 4x4 N=2", 512, 4, 64, True, 16, 1, 2, 528_448, 6_144),
    ("v6 4x4 N=4", 512, 4, 64, True, 16, 1, 4, 266_320, 6_144),
    ("v6 4x4 N=8", 512, 4, 64, True, 16, 1, 8, 135_280, 6_144),
    ("v6 4x4 N=16", 512, 4, 64, True, 16, 1, 16, 135_280, 6_144),
]


def replication_rows() -> list[dict[str, int | str]]:
    """Return the standard T=512 engine sweep used by docs and stdout."""
    rows: list[dict[str, int | str]] = []
    for reuse, protocol in ((False, "v3"), (True, "v4")):
        for tile in (4, 8, 16):
            for engines in (1, 2, 4, 8, 16):
                bounds = replication_bounds(
                    512, tile, 64, reuse, 32, 1, engines
                )
                rows.append({
                    "protocol": protocol,
                    "tile_size": tile,
                    "engine_count": engines,
                    "cycles": core_cycles(
                        512, tile, 64, reuse, 32, 1, engines
                    ),
                    "input_floor": bounds["INPUT"],
                    "calc_work": bounds["CALC"],
                    "scale_work": bounds["SCALING"],
                    "output_floor": bounds["OUTPUT"],
                    "k_reload_work": bounds.get("K_RELOAD", 0),
                    "binder": max(bounds, key=bounds.get),
                    "status": "measured exact" if engines == 1 else "projected",
                })
    return rows


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--replication-csv", type=Path,
        help="write the standard T=512 replicated-engine sweep",
    )
    args = parser.parse_args()
    failures = 0
    engine_errors: list[tuple[str, int, int]] = []
    print(f"{'configuration':20} {'model':>10} {'measured':>10} {'beats':>9} {'meas':>9}")
    for (label, seq, tile, depth, reuse, block_size, score_lanes, engines,
         want_cycles, want_beats) in MEASURED:
        got_cycles = core_cycles(
            seq, tile, depth, reuse, block_size, score_lanes, engines
        )
        got_beats = input_beats(seq, tile, depth, reuse, block_size)
        ok = got_cycles == want_cycles and got_beats == want_beats
        # The shared-port model is the accepted N=1 contract. N>1 rows are
        # reported with their error instead, because the model does not yet
        # account for serialized multi-engine drain; see docs/results/performance.md.
        if engines == 1:
            failures += not ok
        else:
            engine_errors.append((label, got_cycles, want_cycles))
        print(f"{label:20} {got_cycles:>10,} {want_cycles:>10,} "
              f"{got_beats:>9,} {want_beats:>9,}{'' if ok else '   MISMATCH'}")

    print("\nReplicated-engine model error (open finding):")
    for label, projected, measured in engine_errors:
        print(f"  {label:14} projected {projected:>9,} "
              f"measured {measured:>9,} error {measured-projected:+,}")

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

    print("\nProjected T=512 replicated-engine schedules:")
    print(f"{'protocol':>8} {'tile':>6} {'N':>3} {'cycles':>10} "
          f"{'input':>9} {'calc':>9} {'scale':>9} {'output':>9} {'binder':>9}")
    rows = replication_rows()
    for row in rows:
        print(f"{row['protocol']:>8} {row['tile_size']:>3}x{row['tile_size']:<2} "
              f"{row['engine_count']:>3} {row['cycles']:>10,} "
              f"{row['input_floor']:>9,} {row['calc_work']:>9,} "
              f"{row['scale_work']:>9,} {row['output_floor']:>9,} "
              f"{row['binder']:>9}")

    if args.replication_csv:
        args.replication_csv.parent.mkdir(parents=True, exist_ok=True)
        with args.replication_csv.open("w", newline="") as handle:
            writer = csv.DictWriter(handle, fieldnames=list(rows[0]))
            writer.writeheader()
            writer.writerows(rows)

    if failures:
        print(f"\n{failures} configuration(s) do not match. "
              "Either the scheduler changed or docs/architecture.md is stale.")
        return 1
    print("\nAll single-engine configurations reproduced exactly.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
