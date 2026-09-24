#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
source "$script_dir/read_filelist.sh"
read_rtl_filelist "$repo_root"

build_dir="$repo_root/build/precision-rtl"
capture="$build_dir/t512-bs32.bin"
mkdir -p "$build_dir"
python3 "$script_dir/generate_precision_capture.py" "$capture"

work_dir="$(mktemp -d /tmp/ece510-precision-rtl.XXXXXX)"
trap 'rm -rf -- "$work_dir"' EXIT
cp "$repo_root/tb/integration/tb_qkt_chiplet.cpp" "$work_dir/tb_qkt_chiplet.cpp"
(
    cd "$work_dir"
    verilator --cc "${RTL_SOURCES[@]}" --exe tb_qkt_chiplet.cpp \
        --build -Wall -Wno-fatal \
        -CFLAGS "-DTEST_B=4 -DTEST_D=64 -DTEST_TMAX=512 -DTEST_SCALE_BLOCK=32 -DTEST_LARGE -DTEST_PRECISION" \
        -GTILE_SIZE=4 -GD_HEAD=64 -GT_MAX=512 -GK_REUSE=0 \
        -GSCALE_BLOCK_SIZE=32 -GSCORE_LANES=1 \
        -o tb_qkt_chiplet --Mdir obj --top-module qkt_chiplet_top
) > "$build_dir/build.log" 2>&1
"$work_dir/obj/tb_qkt_chiplet" "$capture" | tee "$build_dir/run.log"
grep -q 'RTL_RELATIVE_FROBENIUS=' "$build_dir/run.log"
