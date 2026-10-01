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
scale_block="${5:-16}"
score_lanes="${6:-1}"
engines="${ENGINES:-1}"
scale_format="${SCALE_FORMAT:-0}"
# The source list comes from rtl/filelist.f so this cannot drift from the
# simulated and physical flows.
source "$script_dir/read_filelist.sh"
read_rtl_filelist "$repo_root"
sources=""
for source_path in "${RTL_SOURCES[@]}"; do
    sources+=" \"$source_path\""
done
liberty="${SKY130_LIB:-}"
if [[ -z "$liberty" ]]; then
    liberty="$(find "$HOME/.volare/volare/sky130/versions" -name 'sky130_fd_sc_hd__tt_025C_1v80.lib' -print -quit 2>/dev/null)"
fi
if [[ ! -f "$liberty" ]]; then
    printf 'Sky130 HD liberty not found; set SKY130_LIB\n' >&2
    exit 1
fi
build_dir="$repo_root/build/synthesis/t${tile}-d${depth}-max${tmax}-reuse${reuse}-sb${scale_block}-sl${score_lanes}-e${engines}-sf${scale_format}"
mkdir -p "$build_dir"
(
    cd "$repo_root"
    yosys -Q -T -p "read_verilog -sv $sources; hierarchy -top qkt_chiplet_top -chparam TILE_SIZE $tile -chparam D_HEAD $depth -chparam T_MAX $tmax -chparam K_REUSE $reuse -chparam SCALE_BLOCK_SIZE $scale_block -chparam SCORE_LANES $score_lanes -chparam ENGINES $engines -chparam SCALE_FORMAT $scale_format; synth -top qkt_chiplet_top -noabc; dfflibmap -liberty $liberty; abc -liberty $liberty; stat -liberty $liberty"
) > "$build_dir/yosys.log" 2>&1
grep "Chip area for module"  "$build_dir/yosys.log" | tail -1
printf 'Full synthesis log: %s\n' "$build_dir/yosys.log"
