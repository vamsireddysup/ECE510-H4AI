# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Re-check setup and hold on an already routed netlist with extracted
# parasitics. This exists so a constraint change can be evaluated in minutes
# against a fixed netlist instead of by re-running the whole physical flow:
# the netlist, placement, and clock tree are frozen, so any slack difference
# comes from the constraints alone.
#   env NETLIST   routed gate-level netlist (…/final/nl/DESIGN.nl.v)
#   env SPEF      extracted parasitics for the corner
#   env LIBERTY   Liberty file for the corner
#   env SDC       constraints
#   env DESIGN    top module name
read_liberty $::env(LIBERTY)
read_verilog $::env(NETLIST)
link_design $::env(DESIGN)
read_sdc $::env(SDC)
if {[info exists ::env(SPEF)] && $::env(SPEF) ne ""} {
    read_spef $::env(SPEF)
}
set_propagated_clock [all_clocks]

puts "=== worst hold slack"
report_worst_slack -min -digits 4
puts "=== worst setup slack"
report_worst_slack -max -digits 4
puts "=== hold tns"
report_tns -min -digits 4
puts "=== hold violator count"
# -slack_max 0 restricts the group to violating endpoints, so the number of
# reported paths is the violating-endpoint count rather than a sample.
set hold_vios [find_timing_paths -path_delay min -slack_max 0 -group_count 100000]
puts "hold_violating_endpoints [llength $hold_vios]"
# Classify each violating path by whether it starts at an input port or a
# register. Register-to-register failures are a design or clock-tree problem;
# input-to-register failures are an interface-budget problem.
set from_input 0
set from_reg 0
foreach path $hold_vios {
    set pin [get_property [get_property $path startpoint] full_name]
    if {[llength [get_ports -quiet $pin]] > 0} {
        incr from_input
    } else {
        incr from_reg
    }
}
puts "hold_violations_from_input_port $from_input"
puts "hold_violations_from_register $from_reg"
