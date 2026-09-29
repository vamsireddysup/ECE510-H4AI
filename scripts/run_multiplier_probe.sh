#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Map three exact FP4 E2M1 product-generation alternatives to Sky130 HD.
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
liberty="${SKY130_LIB:-}"
if [[ -z "$liberty" ]]; then
    liberty="$(find "$HOME/.volare/volare/sky130/versions" \
        -name 'sky130_fd_sc_hd__tt_025C_1v80.lib' -print -quit 2>/dev/null)"
fi
if [[ ! -f "$liberty" ]]; then
    printf 'Sky130 HD liberty not found; set SKY130_LIB\n' >&2
    exit 1
fi
build_dir="$repo_root/build/multiplier-probe"
mkdir -p "$build_dir"

cd "$repo_root"
yosys -Q -T -p "read_verilog -formal -sv rtl/probe/fp4_multiplier_probe.sv; \
    prep -top fp4_multiplier_equiv -flatten; sat -prove equal 1 -verify" \
    > "$build_dir/equivalence.log" 2>&1

printf 'implementation,output_contract,cells,mapped_area_um2\n' \
    > "$build_dir/multiplier-probe.csv"
for implementation in 0 1 2; do
    case "$implementation" in
        0) name=decode_multiply; contract=signed_half_unit_product ;;
        1) name=e2m1_shift_add; contract=signed_half_unit_product ;;
        2) name=fp32_product_rom; contract=fp32_product ;;
    esac
    log="$build_dir/$name.log"
    yosys -Q -T -p "read_verilog -sv \
        archive/superseded-rtl/fp4_mul_lut.sv \
        rtl/probe/fp4_multiplier_probe.sv; \
        hierarchy -top fp4_multiplier_probe -chparam IMPLEMENTATION $implementation; \
        synth -top fp4_multiplier_probe -flatten -noabc; \
        dfflibmap -liberty $liberty; abc -liberty $liberty; \
        stat -liberty $liberty" > "$log" 2>&1
    area="$(grep 'Chip area for module' "$log" | tail -1 | grep -oE '[0-9.]+$')"
    cells="$(grep -E '^ +Number of cells:' "$log" | tail -1 | grep -oE '[0-9]+')"
    printf '%s,%s,%s,%s\n' "$name" "$contract" "$cells" "$area" \
        >> "$build_dir/multiplier-probe.csv"
done
cat "$build_dir/multiplier-probe.csv"
