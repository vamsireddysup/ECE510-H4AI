# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Multi-corner power of a routed netlist with switching activity annotated from
# a gate-level VCD, which is what makes the number valid rather than a default
# toggle-rate estimate.
#   env NETLIST   routed gate-level netlist (…/final/nl/DESIGN.nl.v)
#   env SPEF      extracted parasitics for the corner
#   env LIBERTY   Liberty file for the corner
#   env SDC       constraints
#   env VCD       gate-level VCD covering one complete command
#   env SCOPE     VCD scope of the design instance, slash-separated, for
#                 example tb_gate_power/dut. A dotted path annotates nothing.
#   env DESIGN    top module name
read_liberty $::env(LIBERTY)
read_verilog $::env(NETLIST)
link_design $::env(DESIGN)
read_sdc $::env(SDC)
if {[info exists ::env(SPEF)] && $::env(SPEF) ne ""} {
    read_spef $::env(SPEF)
}
set_propagated_clock [all_clocks]

# Without this the report below is a default-activity guess. Every power number
# this project publishes must come from a run that reaches this line.
# OpenSTA separates VCD hierarchy with "/", not "."; a dotted scope silently
# annotates zero pins and the report below becomes a default-activity guess.
read_power_activities -scope $::env(SCOPE) -vcd $::env(VCD)

puts "=== annotated power"
report_power
# read_power_activities prints "Annotated N pin activities"; the caller checks
# that N is greater than zero, because a zero-annotation run still prints a
# complete and plausible default-activity report.
