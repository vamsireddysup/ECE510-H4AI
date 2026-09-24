#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
rtl_dir="$repo_root/archive/coursework/project/m4/src"
build_dir="$repo_root/build/m4-baseline"
work_dir="$(mktemp -d /tmp/ece510-m4-baseline.XXXXXX)"
strict=0

cleanup() {
    rm -rf -- "$work_dir"
}
trap cleanup EXIT

if [[ "${1:-}" == '--strict' ]]; then
    strict=1
elif [[ $# -ne 0 ]]; then
    printf 'Usage: %s [--strict]\n' "$0" >&2
    exit 2
fi

mkdir -p "$build_dir"
cp "$repo_root/archive/coursework/project/m4/tb/tb_top.cpp" "$work_dir/tb_top.cpp"

sources=(
    "$rtl_dir/fp4_mul_lut.sv"
    "$rtl_dir/fp4_mul.sv"
    "$rtl_dir/fp32_add.sv"
    "$rtl_dir/fp32_mul.sv"
    "$rtl_dir/pe.sv"
    "$rtl_dir/systolic_array.sv"
    "$rtl_dir/scale_sram.sv"
    "$rtl_dir/tile_buffer.sv"
    "$rtl_dir/tile_controller.sv"
    "$rtl_dir/axi4_lite_ctrl.sv"
    "$rtl_dir/qkt_chiplet_top.sv"
)

printf '%s\n' 'Building historical M4 baseline...'
(
    cd "$work_dir"
    verilator --cc "${sources[@]}" \
        --exe tb_top.cpp \
        --build \
        -Wall \
        --trace \
        -GTILE_SIZE=4 \
        -GD_HEAD=4 \
        -GT_MAX=16 \
        -o tb_chiplet_top \
        --Mdir obj \
        --top-module qkt_chiplet_top
) 2>&1 | tee "$build_dir/build.log"

printf '%s\n' 'Running historical M4 baseline...'
(
    cd "$work_dir"
    ./obj/tb_chiplet_top
) | tee "$build_dir/run.log"

if [[ -f "$work_dir/chiplet_top_wave.vcd" ]]; then
    cp "$work_dir/chiplet_top_wave.vcd" "$build_dir/chiplet_top_wave.vcd"
fi

grep -q 'Results: 16/16 elements correct' "$build_dir/run.log"
grep -q 'CYCLE_COUNT=498' "$build_dir/run.log"

if grep -q 'DONE=YES' "$build_dir/run.log"; then
    completion='pass'
else
    completion='fail'
fi

{
    printf 'source=archive/coursework/project/m4\n'
    printf 'tile_size=4\n'
    printf 'd_head=4\n'
    printf 't_max=16\n'
    printf 'numeric=pass\n'
    printf 'cycle_count=498\n'
    printf 'completion=%s\n' "$completion"
} > "$build_dir/summary.txt"

if [[ "$completion" == 'fail' ]]; then
    printf '%s\n' \
        'KNOWN BASELINE LIMITATION: numeric output passes but DONE is not observed.'
    if ((strict)); then
        printf '%s\n' 'Strict baseline failed.' >&2
        exit 1
    fi
fi

printf 'Baseline summary: %s\n' "$build_dir/summary.txt"
