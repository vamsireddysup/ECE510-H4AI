#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Compose one LibreLane run configuration from the base config and overrides.

The Verilog file list always comes from rtl/filelist.f, so the physical flow can
never drift from the simulated sources. Environment overrides follow the names
used by scripts/run_physical.sh.
"""
from __future__ import annotations

import argparse
import json
import os
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
BASE = REPO / "config/librelane/qkt_chiplet_top/config.json"

# Environment variable -> (config key, type). Unset variables keep the base value.
OVERRIDES = {
    "SYNTH_STRATEGY": ("SYNTH_STRATEGY", str),
    "SYNTH_SIZING": ("SYNTH_SIZING", "bool"),
    "SYNTH_BUFFERING": ("SYNTH_BUFFERING", "bool"),
    "STD_CELL_LIBRARY": ("STD_CELL_LIBRARY", str),
    "MAX_TRANSITION_CONSTRAINT": ("MAX_TRANSITION_CONSTRAINT", float),
    "MAX_FANOUT_CONSTRAINT": ("MAX_FANOUT_CONSTRAINT", int),
    "PL_TARGET_DENSITY_PCT": ("PL_TARGET_DENSITY_PCT", float),
    "PL_RESIZER_SETUP_SLACK_MARGIN": ("PL_RESIZER_SETUP_SLACK_MARGIN", float),
    "PL_RESIZER_HOLD_SLACK_MARGIN": ("PL_RESIZER_HOLD_SLACK_MARGIN", float),
    "GRT_RESIZER_SETUP_SLACK_MARGIN": ("GRT_RESIZER_SETUP_SLACK_MARGIN", float),
    "GRT_RESIZER_HOLD_SLACK_MARGIN": ("GRT_RESIZER_HOLD_SLACK_MARGIN", float),
    "RUN_POST_CTS_RESIZER_TIMING": ("RUN_POST_CTS_RESIZER_TIMING", "bool"),
    "RUN_POST_GRT_RESIZER_TIMING": ("RUN_POST_GRT_RESIZER_TIMING", "bool"),
}
PARAMETERS = {
    "TILE_SIZE": "4", "D_HEAD": "64", "T_MAX": "16", "K_REUSE": "0",
    "SCALE_BLOCK_SIZE": "16", "SCORE_LANES": "1", "ENGINES": "1",
    "SCALE_FORMAT": "0",
}


def as_type(value: str, kind):
    if kind == "bool":
        return value.strip().lower() in ("1", "true", "yes", "on")
    return kind(value)


def filelist(root: Path) -> list[str]:
    sources = []
    for line in (REPO / "rtl/filelist.f").read_text().splitlines():
        line = line.strip()
        if line and not line.startswith("#"):
            sources.append(str(root / line))
    return sources


def compose(period: float, root: Path) -> dict:
    """root is the path the tools should see; it must contain no spaces,
    because ABC splits the scripts Yosys hands it on whitespace."""
    config = json.loads(BASE.read_text())
    sdc = str(root / BASE.relative_to(REPO).parent / "constraints.sdc")
    config["PNR_SDC_FILE"] = sdc
    config["SIGNOFF_SDC_FILE"] = sdc
    config["VERILOG_FILES"] = filelist(root)
    config["CLOCK_PERIOD"] = period
    parameters = {key: os.environ.get(key, value) for key, value in PARAMETERS.items()}
    config["SYNTH_PARAMETERS"] = [f"{key}={value}" for key, value in parameters.items()]
    for variable, (key, kind) in OVERRIDES.items():
        if os.environ.get(variable):
            config[key] = as_type(os.environ[variable], kind)
    if os.environ.get("DIE_EDGE"):
        edge = float(os.environ["DIE_EDGE"])
        config["DIE_AREA"] = [0, 0, edge, edge]
    return config


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("output", type=Path)
    parser.add_argument("--period", type=float, required=True)
    parser.add_argument("--root", type=Path, default=REPO,
                        help="repository path as the tools should see it")
    args = parser.parse_args()
    if " " in str(args.root):
        parser.error(f"--root must not contain spaces: {args.root}")
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(compose(args.period, args.root), indent=4) + "\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
