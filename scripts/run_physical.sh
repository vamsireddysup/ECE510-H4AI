#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
run_name="${1:-t4-d64-max16-v5-bs16-l1-50ns}"
period="${2:-50.0}"
tile="${3:-4}"
score_lanes="${4:-1}"
mode="${5:-full}"
depth="${D_HEAD:-64}"
tmax="${T_MAX:-16}"
reuse="${K_REUSE:-0}"
scale_block="${SCALE_BLOCK_SIZE:-16}"
engines="${ENGINES:-1}"
synth_strategy="${SYNTH_STRATEGY:-AREA 0}"
synth_sizing="${SYNTH_SIZING:-0}"
synth_buffering="${SYNTH_BUFFERING:-1}"
std_cell_library="${STD_CELL_LIBRARY:-sky130_fd_sc_hd}"
max_transition="${MAX_TRANSITION_CONSTRAINT:-0.75}"
die_area="${DIE_AREA:-0 0 1500 1500}"
core_util="${FP_CORE_UTIL:-40}"
target_density="${PL_TARGET_DENSITY:-0.55}"
io_min_delay="${IO_MIN_DELAY:-3.0}"
placement_hold_margin="${PL_HOLD_MARGIN:-0.1}"
global_hold_margin="${GLB_HOLD_MARGIN:-0.05}"
openlane_image="${OPENLANE_IMAGE:-efabless/openlane@sha256:26719ced90c315b8b4ad7b9dc3e9a176991cea4c3f3282660d8d60d0f0cae229}"
build_dir="$repo_root/build/physical/$run_name"

# The OpenLane file list must stay identical to the simulated one.
config_file="$repo_root/config/openlane/qkt_chiplet_top/config.tcl"
config_sources="$(grep -oE '/work/rtl/[^[:space:]"]+' "$config_file" | sed 's|^/work/||' | sort)"
filelist_sources="$(grep -vE '^[[:space:]]*(#|$)' "$repo_root/rtl/filelist.f" | sort)"
if [[ "$config_sources" != "$filelist_sources" ]]; then
    printf 'config.tcl VERILOG_FILES does not match rtl/filelist.f\n' >&2
    diff <(printf '%s\n' "$config_sources") <(printf '%s\n' "$filelist_sources") >&2 || true
    exit 2
fi
mkdir -p "$build_dir"
cp "$repo_root/config/openlane/qkt_chiplet_top/config.tcl" "$build_dir/config.tcl"
cat >> "$build_dir/config.tcl" <<EOF
set ::env(CLOCK_PERIOD) "$period"
set ::env(SYNTH_PARAMETERS) "TILE_SIZE=$tile D_HEAD=$depth T_MAX=$tmax K_REUSE=$reuse SCALE_BLOCK_SIZE=$scale_block SCORE_LANES=$score_lanes ENGINES=$engines"
set ::env(SYNTH_STRATEGY) "$synth_strategy"
set ::env(SYNTH_SIZING) "$synth_sizing"
set ::env(SYNTH_BUFFERING) "$synth_buffering"
set ::env(STD_CELL_LIBRARY) "$std_cell_library"
set ::env(MAX_TRANSITION_CONSTRAINT) "$max_transition"
set ::env(FP_SIZING) "absolute"
set ::env(DIE_AREA) "$die_area"
set ::env(FP_CORE_UTIL) "$core_util"
set ::env(PL_TARGET_DENSITY) "$target_density"
set ::env(IO_MIN_DELAY) "$io_min_delay"
set ::env(PL_RESIZER_HOLD_SLACK_MARGIN) "$placement_hold_margin"
set ::env(GLB_RESIZER_HOLD_SLACK_MARGIN) "$global_hold_margin"
EOF
if [[ "$mode" == synthesis ]]; then
    cat > "$build_dir/synthesis.tcl" <<EOF
package require openlane
prep -design /work/build/physical/$run_name -tag full -overwrite
run_synthesis
EOF
elif [[ "$mode" == diagnostic ]]; then
    printf '\nset ::env(PL_RESIZER_TIMING_OPTIMIZATIONS) 0\n' >> "$build_dir/config.tcl"
    printf 'set ::env(GLB_RESIZER_TIMING_OPTIMIZATIONS) 0\n' >> "$build_dir/config.tcl"
elif [[ "$mode" == route-timing ]]; then
    # Large post-CTS hold sets make the placement repair effectively
    # nonconvergent.  Let routed wire delay settle those paths, then run the
    # global-routing timing repair before extracted signoff.
    printf '\nset ::env(PL_RESIZER_TIMING_OPTIMIZATIONS) 0\n' >> "$build_dir/config.tcl"
elif [[ "$mode" != full ]]; then
    printf 'Unknown physical mode: %s\n' "$mode" >&2
    exit 2
fi
{
    printf 'git_revision=%s\n' "$(git -C "$repo_root" rev-parse HEAD)"
    # Uncommitted flow or RTL edits would make the revision above misleading.
    printf 'git_dirty_paths=%s\n' "$(git -C "$repo_root" status --porcelain -- rtl config scripts | wc -l)"
    printf 'run_name=%s\nmode=%s\nclock_period_ns=%s\n' "$run_name" "$mode" "$period"
    printf 'tile_size=%s\nd_head=%s\nt_max=%s\nk_reuse=%s\n' \
        "$tile" "$depth" "$tmax" "$reuse"
    printf 'scale_block_size=%s\nscore_lanes=%s\nengines=%s\n' \
        "$scale_block" "$score_lanes" "$engines"
    printf 'synth_strategy=%s\nsynth_sizing=%s\nsynth_buffering=%s\n' \
        "$synth_strategy" "$synth_sizing" "$synth_buffering"
    printf 'std_cell_library=%s\nmax_transition_ns=%s\n' \
        "$std_cell_library" "$max_transition"
    printf 'die_area=%s\nfp_core_util=%s\npl_target_density=%s\n' \
        "$die_area" "$core_util" "$target_density"
    printf 'io_min_delay_ns=%s\n' "$io_min_delay"
    printf 'pl_hold_margin_ns=%s\nglb_hold_margin_ns=%s\n' \
        "$placement_hold_margin" "$global_hold_margin"
    printf 'openlane_image=%s\n' "$openlane_image"
    printf 'openlane_image_id=%s\n' "$(docker image inspect "$openlane_image" --format '{{.Id}}')"
    printf 'pdk_revision=%s\n' "$(basename "$(dirname "$(readlink -f "$HOME/.volare/sky130A")")")"
} > "$build_dir/manifest.txt"
if [[ "$mode" == synthesis ]]; then
    flow_command="flow.tcl -interactive -file /work/build/physical/$run_name/synthesis.tcl"
else
    flow_command="flow.tcl -design /work/build/physical/$run_name -tag full -overwrite"
fi
docker run --rm \
    -v "$repo_root:/work" \
    -v "$HOME/.volare:/root/.volare" \
    -e PDK_ROOT=/root/.volare \
    -e PDK=sky130A \
    "$openlane_image" \
    bash -lc "$flow_command" \
    > "$build_dir/flow.log" 2>&1
printf 'Physical run: %s\n' "$build_dir/runs/full"
