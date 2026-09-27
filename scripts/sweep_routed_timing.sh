#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
run_name="${1:?usage: sweep_routed_timing.sh RUN_NAME PERIOD_NS...}"
shift
if [[ "$run_name" == *[!A-Za-z0-9._-]* || $# -eq 0 ]]; then
    printf 'Run name must be a simple build directory and periods are required\n' >&2
    exit 2
fi
run_dir="$repo_root/build/physical/$run_name/runs/full"
netlist="$run_dir/results/routing/qkt_chiplet_top.nl.v"
sdc="$run_dir/results/cts/qkt_chiplet_top.sdc"
spef="$run_dir/results/routing/mca/process_corner_max/qkt_chiplet_top.spef"
for path in "$netlist" "$sdc" "$spef"; do
    [[ -f "$path" ]] || { printf 'Missing routed artifact: %s\n' "$path" >&2; exit 1; }
done
periods="$*"
tcl="$repo_root/build/physical/$run_name/timing-sweep.tcl"
cat > "$tcl" <<EOF
define_corners Slowest Typical Fastest
read_liberty -corner Slowest /root/.volare/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__ss_100C_1v60.lib
read_liberty -corner Typical /root/.volare/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_liberty -corner Fastest /root/.volare/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib
read_verilog /work/build/physical/$run_name/runs/full/results/routing/qkt_chiplet_top.nl.v
link_design qkt_chiplet_top
read_sdc /work/build/physical/$run_name/runs/full/results/cts/qkt_chiplet_top.sdc
foreach corner [sta::corners] {
    read_spef -corner [\$corner name] /work/build/physical/$run_name/runs/full/results/routing/mca/process_corner_max/qkt_chiplet_top.spef
}
set data_inputs [all_inputs]
foreach period {$periods} {
    create_clock -name clk -period \$period [get_ports clk]
    set input_max [expr {0.2 * \$period}]
    set_input_delay \$input_max -clock [get_clocks clk] -max \$data_inputs
    set_output_delay \$input_max -clock [get_clocks clk] -max [all_outputs]
    puts "SWEEP_PERIOD \$period"
    foreach corner [sta::corners] {
        set setup [sta::format_time [sta::worst_slack_corner \$corner "max"] 4]
        set hold [sta::format_time [sta::worst_slack_corner \$corner "min"] 4]
        puts "SWEEP_CORNER [\$corner name] SETUP \$setup HOLD \$hold"
    }
}
EOF
image="${OPENLANE_IMAGE:-efabless/openlane@sha256:26719ced90c315b8b4ad7b9dc3e9a176991cea4c3f3282660d8d60d0f0cae229}"
docker run --rm \
    -v "$repo_root:/work" \
    -v "$HOME/.volare:/root/.volare" \
    -e PDK_ROOT=/root/.volare -e PDK=sky130A \
    "$image" sta -exit -no_init "/work/build/physical/$run_name/timing-sweep.tcl" \
    > "$repo_root/build/physical/$run_name/timing-sweep.log" 2>&1
grep '^SWEEP_' "$repo_root/build/physical/$run_name/timing-sweep.log"
