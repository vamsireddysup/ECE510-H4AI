#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Re-check setup and hold on an existing routed netlist under a chosen input
# minimum delay. The netlist, clock tree, and parasitics are frozen, so this
# isolates the effect of the constraint and takes minutes instead of the hours
# a full physical run needs.
#   ./scripts/run_routed_sta.sh RUN_NAME MIN_DELAY_NS [PERIOD_NS]
# Set LIBRARY_LIMITS=1 to drop the project's design-wide slew and capacitance
# constraints and check against the library's own per-pin limits instead, which
# separates electrical violations from the project's chosen margin.
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
source "$repo_root/config/librelane/versions.env"

run_name="$1"
min_delay="$2"
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

limit_env="MAX_TRANSITION_CONSTRAINT=0.75 MAX_CAPACITANCE_CONSTRAINT=0.2"
suffix=""
if [[ "${LIBRARY_LIMITS:-0}" == 1 ]]; then
    # Unset rather than widened: the SDC applies each limit only when its
    # variable exists, so omitting them leaves the library's per-pin limits.
    limit_env=""
    suffix="-liblimits"
fi

work="$tool_root/build/sta/$run_name/min$min_delay$suffix"
mkdir -p "$work"
printf 'corner,input_min_delay_ns,worst_hold_ns,worst_setup_ns,hold_tns_ns,hold_endpoints,from_input_port,from_register,slew_violations,cap_violations\n' \
    > "$work/hold.csv"
# The slow corners are the only ones that failed hold; the typical and fast
# corners are included so a constraint change cannot quietly break them.
for corner in ss_100C_1v60 tt_025C_1v80 ff_n40C_1v95; do
    for spef in min nom max; do
        log="$work/sta-$corner-$spef.log"
        docker run --rm -v "$HOME:$HOME" -e HOME="$HOME" "$LIBRELANE_IMAGE" bash -lc "
            NETLIST=$netlist \
            LIBERTY=$pdk_root/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__$corner.lib \
            SPEF=$final/spef/$spef/qkt_chiplet_top.$spef.spef \
            SDC=$tool_root/config/librelane/qkt_chiplet_top/constraints.sdc \
            DESIGN=qkt_chiplet_top \
            CLOCK_PORT=clk CLOCK_PERIOD=$period IO_DELAY_CONSTRAINT=20 \
            IO_MIN_DELAY_CONSTRAINT=$min_delay \
            MAX_FANOUT_CONSTRAINT=30 $limit_env \
            SYNTH_DRIVING_CELL=sky130_fd_sc_hd__inv_2/Y OUTPUT_CAP_LOAD=33.442 \
            CLOCK_UNCERTAINTY_CONSTRAINT=0.25 CLOCK_TRANSITION_CONSTRAINT=0.15 \
            TIME_DERATING_CONSTRAINT=5 \
            sta -exit -no_init $tool_root/scripts/sta/routed_hold.tcl" > "$log" 2>&1
        hold="$(awk '/^=== worst hold slack/{getline; print $4}' "$log")"
        setup="$(awk '/^=== worst setup slack/{getline; print $4}' "$log")"
        tns="$(awk '/^=== hold tns/{getline; print $3}' "$log")"
        eps="$(awk '/^hold_violating_endpoints/{print $2}' "$log")"
        inp="$(awk '/^hold_violations_from_input_port/{print $2}' "$log")"
        reg="$(awk '/^hold_violations_from_register/{print $2}' "$log")"
        [[ -n "$hold" ]] || { printf 'STA produced no slack for %s/%s; see %s\n' "$corner" "$spef" "$log" >&2; exit 1; }
        # The violator report lists slew then capacitance then fanout, so the
        # section each VIOLATED line belongs to has to be tracked while reading.
        read -r slew cap <<< "$(awk '/=== check types/{r=1}
            r&&/^max slew/{s="slew";next} r&&/^max capacitance/{s="cap";next}
            r&&/^max fanout/{s="fanout";next}
            s&&/VIOLATED/{n[s]++} END{printf "%d %d", n["slew"]+0, n["cap"]+0}' "$log")"
        printf '%s_%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n' "$corner" "$spef" "$min_delay" \
            "$hold" "$setup" "$tns" "$eps" "$inp" "$reg" "$slew" "$cap" >> "$work/hold.csv"
    done
done
cat "$work/hold.csv"
