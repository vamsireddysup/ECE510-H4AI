#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Group ranked STA endpoints by the RTL block that owns each register."""
from __future__ import annotations

import argparse
import csv
import re
import sys
from collections import Counter, OrderedDict

# First matching rule wins, so narrower names come before broader ones.
BLOCKS = [
    (r"^rst_n$", "reset input"),
    (r"\.flush$", "command flush"),
    (r"^s_t(valid|ready|data|last)", "input stream port"),
    (r"^m_t(ready|valid|data|last)", "output stream port"),
    (r"^(aw|w|ar|r|b)(valid|ready|addr|data|strb|resp)", "AXI port"),
    (r"matrix_size", "AXI matrix_size register"),
    (r"u_ctrl", "AXI block"),
    (r"u_reducer|score_reducer", "reducer"),
    (r"u_scaler|score_scaler|scaler_", "scaler"),
    (r"acc_bank|acc_valid", "accumulator banks"),
    (r"score_bank|score_valid|score_count", "score banks"),
    (r"send_index|rd_index|retire_|tile_count|tile_start|tile_cycles|tiles_per_row|output_",
     "output sequencer"),
    (r"q_bank|q_row|q_valid|q_release", "Q storage"),
    (r"k_bank|k_valid|k_cache|fill_|load_k", "K storage"),
    (r"sq\b|sk\b|sq\[|sk\[", "scale storage"),
    (r"calc_|acc_scores|acc_row|acc_col|row_skip", "compute sequencer"),
    (r"scale_", "scaling sequencer"),
    (r"frontend|load_beat|k_wr_beat|q_wr_bank|input_|cache_tile|load_q|command_active",
     "frontend"),
    (r"cycle_count|input_beats|output_beats|input_stalls|output_stalls|"
     r"compute_cycles|scale_cycles|done|error_code", "profiling counters"),
]


def block_of(name: str) -> str:
    if re.fullmatch(r"_\d+_", name):
        # Yosys kept no RTL name for this flop's output.
        return "anonymous net"
    for pattern, block in BLOCKS:
        if re.search(pattern, name):
            return block
    return "unclassified"


def base(name: str) -> str:
    """Strip bit and array indices so one register's bits group together."""
    name = name.replace("\\", "")
    return re.sub(r"\[\d+\]", "[*]", name)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("sta_output")
    parser.add_argument("--csv", help="write the ranked rows")
    parser.add_argument("--top", type=int, default=50,
                        help="endpoints in the grouped top-N table")
    args = parser.parse_args()
    rows = []
    with open(args.sta_output) as handle:
        started = False
        for line in handle:
            if line.startswith("RANK\t"):
                started = True
                continue
            if started and re.match(r"^\d+\t", line):
                rank, slack, arrival, sp, sreg, ep, ereg = line.rstrip("\n").split("\t")
                rows.append({
                    "rank": int(rank), "slack_ns": float(slack),
                    "arrival_ns": float(arrival),
                    "start_block": block_of(sreg), "start_register": base(sreg),
                    "end_block": block_of(ereg), "end_register": base(ereg),
                    "start_pin": sp, "end_pin": ep,
                })
    if not rows:
        print("no ranked paths found", file=sys.stderr)
        return 1
    if args.csv:
        with open(args.csv, "w", newline="") as handle:
            writer = csv.DictWriter(handle, fieldnames=list(rows[0]))
            writer.writeheader()
            writer.writerows(rows)

    everything = rows
    rows = rows[:args.top]
    print(f"{len(rows)} endpoints, worst slack {rows[0]['slack_ns']:.3f} ns, "
          f"arrival {rows[0]['arrival_ns']:.3f} ns")
    print("\nBy start block -> end block:")
    pairs: "OrderedDict[tuple[str, str], list[dict]]" = OrderedDict()
    for row in rows:
        pairs.setdefault((row["start_block"], row["end_block"]), []).append(row)
    for (start, end), group in pairs.items():
        print(f"  {len(group):>3}  {start} -> {end}  "
              f"worst {group[0]['slack_ns']:.3f} ns (rank {group[0]['rank']})")
    print("\nBy start register -> end register:")
    registers = Counter((r["start_register"], r["end_register"]) for r in rows)
    worst = {}
    for row in rows:
        worst.setdefault((row["start_register"], row["end_register"]), row)
    for key, count in sorted(registers.items(), key=lambda kv: worst[kv[0]]["rank"]):
        print(f"  {count:>3}  {key[0]} -> {key[1]}  "
              f"worst {worst[key]['slack_ns']:.3f} ns")
    if len(everything) > len(rows):
        # One wide register can fill the whole top-N, so also rank each block
        # pair by its own worst endpoint across the deeper set.
        print(f"\nWorst endpoint per block pair across {len(everything)} endpoints:")
        best: "OrderedDict[tuple[str, str], tuple[dict, int]]" = OrderedDict()
        for row in everything:
            key = (row["start_block"], row["end_block"])
            if key in best:
                best[key] = (best[key][0], best[key][1] + 1)
            else:
                best[key] = (row, 1)
        for (start, end), (row, count) in best.items():
            print(f"  {row['slack_ns']:>8.3f} ns  rank {row['rank']:>5}  "
                  f"{count:>5} endpoints  {start} -> {end}  "
                  f"({row['start_register']} -> {row['end_register']})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
