#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Measure power with switching activity annotated from a gate-level simulation
# of a routed netlist. This is the only power path this project trusts: an
# unannotated report is a default toggle-rate guess.
#   ./scripts/run_gate_power.sh RUN_NAME [SEQ] [PERIOD_NS]
# RUN_NAME is a directory under build/librelane containing runs/pnr/final.
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
source "$repo_root/config/librelane/versions.env"

run_name="$1"
seq="${2:-8}"
period="${3:-40}"
pdk_root="${PDK_ROOT_LIBRELANE:-$HOME/.ciel}"
# The tools see the repository through a space-free path; see run_librelane.sh.
tool_root="$repo_root"
if [[ "$repo_root" == *" "* ]]; then
    tool_root="${LIBRELANE_REPO_LINK:-$HOME/.local/share/fp4-accel/repo}"
    mkdir -p "$(dirname "$tool_root")"
    ln -sfn "$repo_root" "$tool_root"
fi

final="$tool_root/build/librelane/$run_name/runs/pnr/final"
netlist="$final/nl/qkt_chiplet_top.nl.v"
[[ -f "$netlist" ]] || { printf 'No routed netlist: %s\n' "$netlist" >&2; exit 1; }
spef="$(find "$final/spef" -type f -name '*nom*.spef' -print -quit 2>/dev/null || true)"

work="$tool_root/build/gate/$run_name"
models="$pdk_root/sky130A/libs.ref/sky130_fd_sc_hd/verilog"
mkdir -p "$work"
python3 "$script_dir/gen_gate_stimulus.py" --seq "$seq" --out "$work/stimulus.vh"

( cd "$work" && iverilog -g2012 -DFUNCTIONAL -DUNIT_DELAY= -I. -o sim.vvp \
    -s tb_gate_power "$tool_root/tb/gate/tb_gate_power.v" \
    "$models/primitives.v" "$models/sky130_fd_sc_hd.v" "$netlist" \
    2>&1 | grep -viE "UNIT_DELAY undefined" || true )
( cd "$work" && vvp sim.vvp | tee sim.log )
grep -q "^PASS" "$work/sim.log" || { printf 'Gate simulation did not pass.\n' >&2; exit 1; }

printf 'corner,total_power_w,switching_power_w,leakage_power_w,annotated_pins,spef\n' \
    > "$work/power.csv"
for corner in ss_100C_1v60 tt_025C_1v80 ff_n40C_1v95; do
    log="$work/power-$corner.log"
    docker run --rm -v "$HOME:$HOME" -e HOME="$HOME" "$LIBRELANE_IMAGE" bash -lc "
        NETLIST=$netlist \
        LIBERTY=$pdk_root/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__$corner.lib \
        SPEF='$spef' \
        SDC=$tool_root/config/librelane/qkt_chiplet_top/constraints.sdc \
        VCD=$work/power.vcd SCOPE=tb_gate_power/dut DESIGN=qkt_chiplet_top \
        CLOCK_PORT=clk CLOCK_PERIOD=$period IO_DELAY_CONSTRAINT=20 \
        MAX_FANOUT_CONSTRAINT=30 MAX_TRANSITION_CONSTRAINT=0.75 \
        SYNTH_DRIVING_CELL=sky130_fd_sc_hd__inv_2/Y OUTPUT_CAP_LOAD=33.442 \
        CLOCK_UNCERTAINTY_CONSTRAINT=0.25 CLOCK_TRANSITION_CONSTRAINT=0.15 \
        TIME_DERATING_CONSTRAINT=5 \
        sta -exit -no_init $tool_root/scripts/sta/annotated_power.tcl" > "$log" 2>&1
    pins="$(grep -aoE 'Annotated [0-9]+ pin' "$log" | grep -oE '[0-9]+' | head -1)"
    [[ "${pins:-0}" -gt 0 ]] || { printf 'No activity annotated for %s; see %s\n' "$corner" "$log" >&2; exit 1; }
    read -r total switching leakage <<< "$(awk '/^Total /{print $5, $3, $4}' "$log" | tail -1)"
    printf '%s,%s,%s,%s,%s,%s\n' "$corner" "$total" "$switching" "$leakage" \
        "$pins" "${spef:+yes}" >> "$work/power.csv"
done
cat "$work/power.csv"
