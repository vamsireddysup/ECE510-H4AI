#!/usr/bin/env python3
"""Closed-form core-cycle model for qkt_chiplet_top, checked against measurements.

The model comes from reading the FSM in rtl/top/qkt_chiplet_top.sv. Run this
script to confirm it still reproduces every measured configuration; a mismatch
means either the FSM changed or docs/architecture.md is stale.

Usage, from the repository root:

    python3 scripts/cycle_model.py
"""

from __future__ import annotations

import sys
from math import ceil

# Latency of the two chained three-stage FP32 scale multipliers.
SCALE_PIPELINE_LATENCY = 6


def stage_costs(tile: int, depth: int) -> dict[str, int]:
    """Per-output-tile cost of each FSM phase, in core cycles."""
    return {
        "LOAD_K": ceil(tile * depth / 16),      # 16 FP4 codes per 64-bit beat
        "CALC": depth,                           # one reduction step per cycle
        "SCALING": tile * tile + SCALE_PIPELINE_LATENCY,  # one score launch per cycle
        "OUTPUT": ceil(tile * tile / 2),         # two FP32 scores per 64-bit beat
        "ADVANCE": 1,
    }


def core_cycles(seq: int, tile: int, depth: int, k_reuse: bool = False) -> int:
    """Core cycles for one command with a continuously ready host.

    Assumes seq is a multiple of tile, which is the case for every benchmarked
    configuration. Partial edge tiles cost less, so this is an upper bound.
    """
    beats = ceil(tile * depth / 16)
    rows = seq // tile
    stages = stage_costs(tile, depth)
    per_tile = sum(stages.values())
    scales = seq                                 # two FP32 scales per beat, 2*seq values

    if k_reuse:
        # K is loaded once for the whole command, so no per-tile LOAD_K.
        return scales + rows * beats + rows * beats + rows * rows * (per_tile - stages["LOAD_K"])
    return scales + rows * beats + rows * rows * per_tile


def input_beats(seq: int, tile: int, depth: int, k_reuse: bool = False) -> int:
    beats = ceil(tile * depth / 16)
    rows = seq // tile
    if k_reuse:
        return seq + rows * beats + rows * beats
    return seq + rows * beats + rows * rows * beats


def binding_stage(tile: int, depth: int) -> tuple[str, int]:
    """The stage that would set the rate if every phase overlapped perfectly."""
    stages = stage_costs(tile, depth)
    del stages["ADVANCE"]
    name = max(stages, key=lambda key: stages[key])
    return name, stages[name]


# Measured on master with Verilator 5.020 and 5.042, continuously ready host.
# (label, seq, tile, depth, k_reuse, core cycles, input beats)
MEASURED = [
    ("v1 4x4 T=64", 64, 4, 64, False, 28_736, 4_416),
    ("v1 4x4 T=128", 128, 4, 64, False, 114_304, 17_024),
    ("v1 4x4 T=512", 512, 4, 64, False, 1_821_184, 264_704),
    ("v2 4x4 T=512", 512, 4, 64, True, 1_561_088, 4_608),
    ("v1 8x8 T=512", 512, 8, 64, False, 817_664, None),
    ("v1 16x16 T=512", 512, 16, 64, False, 534_016, None),
]


def main() -> int:
    failures = 0
    print(f"{'configuration':16} {'model':>10} {'measured':>10} {'beats':>9} {'meas':>9}")
    for label, seq, tile, depth, reuse, want_cycles, want_beats in MEASURED:
        got_cycles = core_cycles(seq, tile, depth, reuse)
        got_beats = input_beats(seq, tile, depth, reuse)
        ok = got_cycles == want_cycles and (want_beats is None or got_beats == want_beats)
        failures += not ok
        beats_col = f"{want_beats:,}" if want_beats is not None else "-"
        print(f"{label:16} {got_cycles:>10,} {want_cycles:>10,} "
              f"{got_beats:>9,} {beats_col:>9}{'' if ok else '   MISMATCH'}")

    print("\nPer-tile stage costs at D_HEAD=64, and the ceiling under perfect overlap:")
    for tile in (4, 8, 16):
        stages = stage_costs(tile, 64)
        name, cost = binding_stage(tile, 64)
        tiles = (512 // tile) ** 2
        parts = " ".join(f"{k}={v}" for k, v in stages.items())
        print(f"  {tile:>2}x{tile:<2} {parts}")
        print(f"        binds on {name} at {cost} cycles per tile, "
              f"so T=512 would take {tiles * cost:,} cycles")

    if failures:
        print(f"\n{failures} configuration(s) do not match. "
              "Either the FSM changed or docs/architecture.md is stale.")
        return 1
    print("\nAll measured configurations reproduced.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
