#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"

# shellcheck source=read_filelist.sh
source "$script_dir/read_filelist.sh"
read_rtl_filelist "$repo_root"

verilator --lint-only \
    -Wall \
    -Wno-fatal \
    -GTILE_SIZE=4 \
    -GD_HEAD=4 \
    -GT_MAX=16 \
    --top-module qkt_chiplet_top \
    "${RTL_SOURCES[@]}"
