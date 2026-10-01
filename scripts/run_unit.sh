#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Unit checks for arithmetic blocks that the full-top suites only cover
# indirectly. Each runs the block against a reference computed independently.
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
acc_w="${ACC_W:-13}"

for format in 0 1; do
    name=$([[ "$format" == 0 ]] && echo FP32 || echo E4M3)
    build_dir="$repo_root/build/unit/score-scaler-$name"
    mkdir -p "$build_dir"
    work="$(mktemp -d)"
    cp "$repo_root/tb/unit/tb_score_scaler.cpp" "$work/tb.cpp"
    (
        cd "$work"
        verilator --cc "$repo_root/rtl/core/fp32_mul.sv" \
            "$repo_root/rtl/core/score_scaler.sv" \
            --top-module score_scaler \
            -GSCALE_FORMAT="$format" -GACC_W="$acc_w" -GLANES=1 \
            --exe tb.cpp --build -Wno-fatal \
            -CFLAGS "-DSCALE_FORMAT=$format -DACC_W=$acc_w" \
            -o scaler --Mdir obj
    ) > "$build_dir/build.log" 2>&1
    "$work/obj/scaler" | tee "$build_dir/run.log"
    rm -rf -- "$work"
    grep -q 'ALL PASS' "$build_dir/run.log"
done
printf 'Unit checks passed.\n'
