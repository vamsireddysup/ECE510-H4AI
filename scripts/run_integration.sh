#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
source "$script_dir/read_filelist.sh"
read_rtl_filelist "$repo_root"
reuse=0
tile=4
scale_block="${SCALE_BLOCK_SIZE:-32}"
score_lanes="${SCORE_LANES:-1}"
if [[ "${1:-}" == '--reuse' ]]; then
    depths=(4 64)
    tmax=16
    extra_flags='-DTEST_K_REUSE'
    reuse=1
elif [[ "${1:-}" == '--reuse-large' ]]; then
    depths=(64)
    tmax=512
    extra_flags='-DTEST_LARGE -DTEST_K_REUSE'
    reuse=1
elif [[ "${1:-}" == '--large' ]]; then
    depths=(64)
    tmax=512
    extra_flags='-DTEST_LARGE'
elif [[ "${1:-}" == '--array8' || "${1:-}" == '--array16' ||
        "${1:-}" == '--array8-large' || "${1:-}" == '--array16-large' ]]; then
    tile="${1#--array}"
    tile="${tile%-large}"
    depths=(64)
    if [[ "${1:-}" == *-large ]]; then
        tmax=512
        extra_flags='-DTEST_LARGE'
    else
        tmax=16
        extra_flags=''
    fi
else
    depths=(4 64)
    tmax=16
    extra_flags=''
fi
for depth in "${depths[@]}"; do
    build_dir="$repo_root/build/integration/b${tile}-t${tmax}-d${depth}-reuse${reuse}-sb${scale_block}-sl${score_lanes}"
    mkdir -p "$build_dir"
    work_dir="$(mktemp -d /tmp/ece510-integration.XXXXXX)"
    cp "$repo_root/tb/integration/tb_qkt_chiplet.cpp" "$work_dir/tb_qkt_chiplet.cpp"
    (
        cd "$work_dir"
        verilator --cc "${RTL_SOURCES[@]}" --exe tb_qkt_chiplet.cpp \
            --build -Wall -Wno-fatal -CFLAGS "-DTEST_B=${tile} -DTEST_D=${depth} -DTEST_TMAX=${tmax} -DTEST_SCALE_BLOCK=${scale_block} ${extra_flags}" \
            -GTILE_SIZE="$tile" -GD_HEAD="$depth" -GT_MAX="$tmax" -GK_REUSE="$reuse" \
            -GSCALE_BLOCK_SIZE="$scale_block" \
            -GSCORE_LANES="$score_lanes" \
            -o tb_qkt_chiplet --Mdir obj --top-module qkt_chiplet_top
    ) > "$build_dir/build.log" 2>&1
    "$work_dir/obj/tb_qkt_chiplet" | tee "$build_dir/run.log"
    rm -rf -- "$work_dir"
    grep -q 'ALL PASS' "$build_dir/run.log"
done
