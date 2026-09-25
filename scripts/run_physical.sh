#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
run_name="${1:-t4-d64-max16-v3-bs32-l1-50ns}"
period="${2:-50.0}"
tile="${3:-4}"
score_lanes="${4:-1}"
mode="${5:-full}"
depth="${D_HEAD:-64}"
tmax="${T_MAX:-16}"
reuse="${K_REUSE:-0}"
scale_block="${SCALE_BLOCK_SIZE:-32}"
die_area="${DIE_AREA:-0 0 1500 1500}"
core_util="${FP_CORE_UTIL:-40}"
target_density="${PL_TARGET_DENSITY:-0.55}"
openlane_image="${OPENLANE_IMAGE:-efabless/openlane@sha256:26719ced90c315b8b4ad7b9dc3e9a176991cea4c3f3282660d8d60d0f0cae229}"
build_dir="$repo_root/build/physical/$run_name"
mkdir -p "$build_dir"
cp "$repo_root/config/openlane/qkt_chiplet_top/config.tcl" "$build_dir/config.tcl"
cat >> "$build_dir/config.tcl" <<EOF
set ::env(CLOCK_PERIOD) "$period"
set ::env(SYNTH_PARAMETERS) "TILE_SIZE=$tile D_HEAD=$depth T_MAX=$tmax K_REUSE=$reuse SCALE_BLOCK_SIZE=$scale_block SCORE_LANES=$score_lanes"
set ::env(DIE_AREA) "$die_area"
set ::env(FP_CORE_UTIL) "$core_util"
set ::env(PL_TARGET_DENSITY) "$target_density"
EOF
if [[ "$mode" == diagnostic ]]; then
    printf '\nset ::env(PL_RESIZER_TIMING_OPTIMIZATIONS) 0\n' >> "$build_dir/config.tcl"
    printf 'set ::env(GLB_RESIZER_TIMING_OPTIMIZATIONS) 0\n' >> "$build_dir/config.tcl"
elif [[ "$mode" != full ]]; then
    printf 'Unknown physical mode: %s\n' "$mode" >&2
    exit 2
fi
{
    printf 'git_revision=%s\n' "$(git -C "$repo_root" rev-parse HEAD)"
    printf 'run_name=%s\nclock_period_ns=%s\n' "$run_name" "$period"
    printf 'tile_size=%s\nd_head=%s\nt_max=%s\nk_reuse=%s\n' \
        "$tile" "$depth" "$tmax" "$reuse"
    printf 'scale_block_size=%s\nscore_lanes=%s\n' "$scale_block" "$score_lanes"
    printf 'die_area=%s\nfp_core_util=%s\npl_target_density=%s\n' \
        "$die_area" "$core_util" "$target_density"
    printf 'openlane_image=%s\n' "$openlane_image"
    printf 'openlane_image_id=%s\n' "$(docker image inspect "$openlane_image" --format '{{.Id}}')"
    printf 'pdk_revision=%s\n' "$(basename "$(dirname "$(readlink -f "$HOME/.volare/sky130A")")")"
} > "$build_dir/manifest.txt"
docker run --rm \
    -v "$repo_root:/work" \
    -v "$HOME/.volare:/root/.volare" \
    -e PDK_ROOT=/root/.volare \
    -e PDK=sky130A \
    "$openlane_image" \
    bash -lc "flow.tcl -design /work/build/physical/$run_name -tag full -overwrite" \
    > "$build_dir/flow.log" 2>&1
printf 'Physical run: %s\n' "$build_dir/runs/full"
