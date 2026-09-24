#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
source "$script_dir/read_filelist.sh"
read_rtl_filelist "$repo_root"
for params in '4 4 16 0 32 1' '4 64 512 0 32 1' '4 64 512 1 32 1' \
              '8 64 16 0 32 1' '16 64 16 0 32 1' '4 64 512 0 16 1' \
              '8 64 16 0 32 4' '16 64 16 0 32 4'; do
    read -r tile depth tmax reuse scale_block score_lanes <<< "$params"
    verilator --lint-only -Wall \
        -GTILE_SIZE="$tile" -GD_HEAD="$depth" -GT_MAX="$tmax" \
        -GK_REUSE="$reuse" -GSCALE_BLOCK_SIZE="$scale_block" \
        -GSCORE_LANES="$score_lanes" \
        --top-module qkt_chiplet_top "${RTL_SOURCES[@]}"
    printf 'Lint PASS: TILE_SIZE=%s D_HEAD=%s T_MAX=%s K_REUSE=%s SCALE_BLOCK_SIZE=%s SCORE_LANES=%s\n' \
        "$tile" "$depth" "$tmax" "$reuse" "$scale_block" "$score_lanes"
done
