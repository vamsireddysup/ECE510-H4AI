#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
run_name="${1:-t4-d64-max16-v1-50ns}"
mode="${2:-full}"
build_dir="$repo_root/build/physical/$run_name"
mkdir -p "$build_dir"
cp "$repo_root/config/openlane/qkt_chiplet_top/config.tcl" "$build_dir/config.tcl"
if [[ "$mode" == diagnostic ]]; then
    printf '\nset ::env(PL_RESIZER_TIMING_OPTIMIZATIONS) 0\n' >> "$build_dir/config.tcl"
    printf 'set ::env(GLB_RESIZER_TIMING_OPTIMIZATIONS) 0\n' >> "$build_dir/config.tcl"
elif [[ "$mode" != full ]]; then
    printf 'Unknown physical mode: %s\n' "$mode" >&2
    exit 2
fi
docker run --rm \
    -v "$repo_root:/work" \
    -v "$HOME/.volare:/root/.volare" \
    -e PDK_ROOT=/root/.volare \
    -e PDK=sky130A \
    efabless/openlane:latest \
    bash -lc "flow.tcl -design /work/build/physical/$run_name -tag full -overwrite" \
    > "$build_dir/flow.log" 2>&1
printf 'Physical run: %s\n' "$build_dir/runs/full"
