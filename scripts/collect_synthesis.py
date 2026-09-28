#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Collect mapped area, cells, and per-corner worst setup path from synthesis runs."""
from __future__ import annotations

import argparse
import csv
import glob
import os
import re
import subprocess
import sys
from pathlib import Path

IMAGE = ("efabless/openlane@sha256:"
         "26719ced90c315b8b4ad7b9dc3e9a176991cea4c3f3282660d8d60d0f0cae229")
LIB = "/root/.volare/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__{}.lib"
CORNERS = {"tt": "tt_025C_1v80", "ss": "ss_100C_1v60"}


def manifest(run: Path) -> dict[str, str]:
    values = {}
    for line in (run / "manifest.txt").read_text().splitlines():
        key, _, value = line.partition("=")
        values[key] = value
    return values


def area_and_cells(run: Path) -> tuple[float, int]:
    reports = sorted((run / "runs/full/reports/synthesis").glob("1-synthesis.*.stat.rpt"))
    text = reports[-1].read_text()
    area = float(re.findall(r"Chip area for module .*?: ([\d.]+)", text)[-1])
    cells = int(re.findall(r"Number of cells:\s+(\d+)", text)[-1])
    return area, cells


def worst_path(repo: Path, run: Path, corner: str) -> tuple[float, float]:
    """Worst setup slack and data arrival at one corner, from our STA script."""
    relative = run.relative_to(repo)
    command = [
        "docker", "run", "--rm", "-v", f"{repo}:/work",
        "-v", f"{Path.home()}/.volare:/root/.volare",
        "-e", "PDK_ROOT=/root/.volare", "-e", "PDK=sky130A",
        "-e", f"RUN_DIR=/work/{relative}/runs/full",
        "-e", f"LIB={LIB.format(corner)}", "-e", "PATHS=1",
        IMAGE, "bash", "-lc", "sta -exit -no_init /work/scripts/sta/endpoint_paths.tcl",
    ]
    output = subprocess.run(command, capture_output=True, text=True, check=True).stdout
    for line in output.splitlines():
        if line.startswith("1\t"):
            fields = line.split("\t")
            return float(fields[1]), float(fields[2])
    raise RuntimeError(f"no path reported for {run} at {corner}")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("pattern", help="glob of build/physical run directories")
    parser.add_argument("--csv", type=Path, required=True)
    args = parser.parse_args()
    repo = Path(__file__).resolve().parent.parent
    rows = []
    for run in sorted(Path(p).resolve() for p in glob.glob(args.pattern)):
        if not (run / "runs/full/results/synthesis").exists():
            print(f"skip {run}: no netlist", file=sys.stderr)
            continue
        meta = manifest(run)
        area, cells = area_and_cells(run)
        row = {
            "run": run.name,
            "git_revision": meta["git_revision"][:7],
            "period_ns": float(meta["clock_period_ns"]),
            "synth_strategy": meta["synth_strategy"],
            "synth_sizing": meta["synth_sizing"],
            "synth_buffering": meta["synth_buffering"],
            "cells": cells,
            "mapped_area_um2": round(area, 1),
        }
        for short, corner in CORNERS.items():
            slack, arrival = worst_path(repo, run, corner)
            row[f"{short}_worst_slack_ns"] = slack
            row[f"{short}_worst_arrival_ns"] = arrival
        row["status"] = "measured; mapped netlist; ideal clock; no wire parasitics"
        rows.append(row)
        print(f"{run.name}: {cells} cells {area:.0f} um2 "
              f"tt {row['tt_worst_arrival_ns']:.3f} ss {row['ss_worst_arrival_ns']:.3f}")
    rows.sort(key=lambda r: (r["synth_strategy"], -r["period_ns"]))
    args.csv.parent.mkdir(parents=True, exist_ok=True)
    with args.csv.open("w", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    return 0


if __name__ == "__main__":
    sys.exit(main())
