#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
build_dir="$repo_root/build/integration"
work_dir="$(mktemp -d /tmp/ece510-integration.XXXXXX)"

cleanup() {
    rm -rf -- "$work_dir"
}
trap cleanup EXIT

# shellcheck source=read_filelist.sh
source "$script_dir/read_filelist.sh"
read_rtl_filelist "$repo_root"

mkdir -p "$build_dir"
cp "$repo_root/tb/integration/tb_qkt_chiplet.cpp" "$work_dir/tb_qkt_chiplet.cpp"

printf '%s\n' 'Building active 4x4 integration test...'
(
    cd "$work_dir"
    verilator --cc "${RTL_SOURCES[@]}" \
        --exe tb_qkt_chiplet.cpp \
        --build \
        -Wall \
        --trace \
        -GTILE_SIZE=4 \
        -GD_HEAD=4 \
        -GT_MAX=16 \
        -o tb_qkt_chiplet \
        --Mdir obj \
        --top-module qkt_chiplet_top
) 2>&1 | tee "$build_dir/build.log"

printf '%s\n' 'Running active 4x4 integration test...'
(
    cd "$work_dir"
    ./obj/tb_qkt_chiplet
) | tee "$build_dir/run.log"

grep -q 'Results: 16/16 elements correct' "$build_dir/run.log"
grep -q 'TILE_COUNT=1 CYCLE_COUNT=498' "$build_dir/run.log"
grep -q 'DONE=YES' "$build_dir/run.log"

completion='pass'

{
    printf 'source=rtl\n'
    printf 'tile_size=4\n'
    printf 'd_head=4\n'
    printf 't_max=16\n'
    printf 'numeric=pass\n'
    printf 'cycle_count=498\n'
    printf 'completion=%s\n' "$completion"
} > "$build_dir/summary.txt"

printf 'Integration summary: %s\n' "$build_dir/summary.txt"
