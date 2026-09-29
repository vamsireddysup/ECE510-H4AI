#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Run the complete top through LibreLane in two phases: synthesis at
# SYNTH_CLOCK_PERIOD, then placement and routing at PERIOD. ABC only restructures
# for speed when asked, and the resizer cannot repair a constraint the mapped
# netlist is far from meeting, so the two periods may differ.
#   ./scripts/run_librelane.sh RUN_NAME PERIOD [MODE]
#   MODE: synthesis | global-route | full (default)
# Overrides: TILE_SIZE D_HEAD T_MAX K_REUSE SCALE_BLOCK_SIZE SCORE_LANES ENGINES,
# SYNTH_CLOCK_PERIOD, DIE_EDGE, and the names in scripts/librelane_config.py.
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
source "$repo_root/config/librelane/versions.env"

run_name="$1"
period="$2"
mode="${3:-full}"
synth_period="${SYNTH_CLOCK_PERIOD:-$period}"
venv="${LIBRELANE_VENV:-$HOME/.local/share/fp4-accel/librelane-venv}"
pdk_root="${PDK_ROOT_LIBRELANE:-$HOME/.ciel}"
# ABC splits the scripts Yosys gives it on whitespace, and this repository's
# path contains spaces. LibreLane mounts $HOME at the same path and keeps
# symlinked paths as given, so the tools see the repository through a
# space-free link.
tool_root="$repo_root"
if [[ "$repo_root" == *" "* ]]; then
    tool_root="${LIBRELANE_REPO_LINK:-$HOME/.local/share/fp4-accel/repo}"
    mkdir -p "$(dirname "$tool_root")"
    ln -sfn "$repo_root" "$tool_root"
fi
build_dir="$tool_root/build/librelane/$run_name"

case "$mode" in
    synthesis|global-route|full) ;;
    *) printf 'Unknown mode: %s\n' "$mode" >&2; exit 2 ;;
esac

librelane() {
    "$venv/bin/python" -m librelane --docker-no-tty --dockerized \
        --pdk-root "$pdk_root" "$@"
}

mkdir -p "$build_dir"
python3 "$script_dir/librelane_config.py" "$build_dir/synth.json" \
    --period "$synth_period" --root "$tool_root"
python3 "$script_dir/librelane_config.py" "$build_dir/config.json" \
    --period "$period" --root "$tool_root"
if [[ "$mode" == global-route ]]; then
    # Floorplan study: stop after antenna repair, without timing repair.
    python3 - "$build_dir/config.json" <<'PY'
import json, sys
path = sys.argv[1]
config = json.load(open(path))
config["RUN_POST_CTS_RESIZER_TIMING"] = False
config["RUN_POST_GRT_RESIZER_TIMING"] = False
open(path, "w").write(json.dumps(config, indent=4) + "\n")
PY
fi

{
    printf 'git_revision=%s\n' "$(git -C "$repo_root" rev-parse HEAD)"
    printf 'git_dirty_paths=%s\n' \
        "$(git -C "$repo_root" status --porcelain -- rtl config scripts | wc -l)"
    printf 'run_name=%s\nmode=%s\nclock_period_ns=%s\nsynth_clock_period_ns=%s\n' \
        "$run_name" "$mode" "$period" "$synth_period"
    printf 'librelane=%s\nciel=%s\nsky130_pdk=%s\nimage=%s\n' \
        "$LIBRELANE_VERSION" "$CIEL_VERSION" "$SKY130_PDK_REVISION" "$LIBRELANE_IMAGE"
    printf 'image_id=%s\n' "$(docker image inspect "$LIBRELANE_IMAGE" --format '{{.Id}}' 2>/dev/null)"
    for key in TILE_SIZE D_HEAD T_MAX K_REUSE SCALE_BLOCK_SIZE SCORE_LANES ENGINES \
               SYNTH_STRATEGY SYNTH_SIZING SYNTH_BUFFERING STD_CELL_LIBRARY \
               DIE_EDGE PL_TARGET_DENSITY_PCT MAX_TRANSITION_CONSTRAINT; do
        printf '%s=%s\n' "$(printf '%s' "$key" | tr 'A-Z' 'a-z')" "${!key:-default}"
    done
} > "$build_dir/manifest.txt"

# Phase 1: synthesis and its netlist checks at the synthesis clock.
librelane --run-tag synth --overwrite --to Checker.NetlistAssignStatements \
    "$build_dir/synth.json" > "$build_dir/synth.log" 2>&1
if [[ "$mode" == synthesis ]]; then
    printf 'LibreLane synthesis: %s\n' "$build_dir/runs/synth"
    exit 0
fi

# Phase 2: everything after synthesis at the placement-and-route clock,
# starting from the state phase 1 ended with.
state="$(ls -d "$build_dir"/runs/synth/[0-9]*-*/ | sort -V | tail -1)state_out.json"
to_args=()
if [[ "$mode" == global-route ]]; then
    to_args=(--to OpenROAD.RepairAntennas)
fi
librelane --run-tag pnr --overwrite --from OpenROAD.CheckSDCFiles \
    --with-initial-state "$state" "${to_args[@]}" \
    "$build_dir/config.json" > "$build_dir/pnr.log" 2>&1
printf 'LibreLane run: %s\n' "$build_dir/runs/pnr"
