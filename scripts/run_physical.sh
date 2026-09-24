#!/usr/bin/env bash
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
run_name="${1:-t4-d64-max16-v1-50ns}"
build_dir="$repo_root/build/physical/$run_name"
mkdir -p "$build_dir"
cp "$repo_root/config/openlane/qkt_chiplet_top/config.tcl" "$build_dir/config.tcl"
docker run --rm \
    -v "$repo_root:/work" \
    -v "$HOME/.volare:/root/.volare" \
    -e PDK_ROOT=/root/.volare \
    -e PDK=sky130A \
    efabless/openlane:latest \
    bash -lc "flow.tcl -design /work/build/physical/$run_name -tag full -overwrite" \
    > "$build_dir/flow.log" 2>&1
printf 'Physical run: %s\n' "$build_dir/runs/full"
