#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
tile="${1:-4}"
depth="${2:-64}"
tmax="${3:-16}"
reuse="${4:-0}"
liberty="${SKY130_LIB:-}"
if [[ -z "$liberty" ]]; then
    liberty="$(find "$HOME/.volare/volare/sky130/versions" -name 'sky130_fd_sc_hd__tt_025C_1v80.lib' -print -quit 2>/dev/null)"
fi
if [[ ! -f "$liberty" ]]; then
    printf 'Sky130 HD liberty not found; set SKY130_LIB\n' >&2
    exit 1
fi
build_dir="$repo_root/build/synthesis/t${tile}-d${depth}-max${tmax}-reuse${reuse}"
mkdir -p "$build_dir"
(
    cd "$repo_root"
    yosys -Q -T -p "read_verilog -sv rtl/core/fp32_mul.sv rtl/interfaces/axi4_lite_ctrl.sv rtl/top/qkt_chiplet_top.sv; hierarchy -top qkt_chiplet_top -chparam TILE_SIZE $tile -chparam D_HEAD $depth -chparam T_MAX $tmax -chparam K_REUSE $reuse; synth -top qkt_chiplet_top -noabc; dfflibmap -liberty $liberty; abc -liberty $liberty; stat -liberty $liberty"
) > "$build_dir/yosys.log" 2>&1
rg "Chip area for top module" "$build_dir/yosys.log" | tail -1
printf 'Full synthesis log: %s\n' "$build_dir/yosys.log"
