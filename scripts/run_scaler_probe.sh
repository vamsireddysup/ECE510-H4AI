#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Map one score lane's scaling path to Sky130 for each block-scale format, so
# the accuracy comparison in docs/results/precision.md has a cost beside it.
#   ./scripts/run_scaler_probe.sh [ACC_W]
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
acc_w="${1:-13}"
liberty="${SKY130_LIB:-}"
if [[ -z "$liberty" ]]; then
    liberty="$(find "$HOME/.volare/volare/sky130/versions" \
        -name 'sky130_fd_sc_hd__tt_025C_1v80.lib' -print -quit 2>/dev/null)"
fi
if [[ ! -f "$liberty" ]]; then
    printf 'Sky130 HD liberty not found; set SKY130_LIB\n' >&2
    exit 1
fi
build_dir="$repo_root/build/scaler-probe"
mkdir -p "$build_dir"
printf 'format,scale_bits,cells,mapped_area_um2,sequential_cells\n' \
    > "$build_dir/scaler-probe.csv"
for format in 0 1 2; do
    case "$format" in
        0) name=FP32; bits=32 ;;
        1) name=E4M3; bits=8 ;;
        2) name=E8M0; bits=8 ;;
    esac
    log="$build_dir/$name.log"
    (
        cd "$repo_root"
        yosys -Q -T -p "read_verilog -sv rtl/core/fp32_mul.sv rtl/probe/scaler_probe.sv; hierarchy -top scaler_probe -chparam ACC_W $acc_w -chparam SCALE_FORMAT $format; synth -top scaler_probe -flatten -noabc; dfflibmap -liberty $liberty; abc -liberty $liberty; stat -liberty $liberty"
    ) > "$log" 2>&1
    area="$(grep "Chip area for module" "$log" | tail -1 | grep -oE '[0-9.]+$')"
    cells="$(grep -E "^ +Number of cells:" "$log" | tail -1 | grep -oE '[0-9]+')"
    flops="$(grep -cE "sky130_fd_sc_hd__df" "$log" || true)"
    printf '%s,%s,%s,%s,%s\n' "$name" "$bits" "$cells" "$area" "$flops" \
        >> "$build_dir/scaler-probe.csv"
done
cat "$build_dir/scaler-probe.csv"
