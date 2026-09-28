# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Rank the worst setup endpoints of a synthesized netlist at one corner and name
# the RTL register behind every anonymized start and end instance.
#   env RUN_DIR   OpenLane run directory (…/runs/full)
#   env LIB       Liberty file for the corner
#   env PATHS     number of endpoints to report
source $::env(RUN_DIR)/config.tcl
read_liberty $::env(LIB)
read_verilog $::env(RUN_DIR)/results/synthesis/$::env(DESIGN_NAME).v
link_design $::env(DESIGN_NAME)
read_sdc $::env(BASE_SDC_FILE)

proc q_net {pin} {
    # A port names itself. A flop is named by the net on its Q output, which
    # Yosys keeps as the RTL register name.
    # A top-level port has no instance separator in its name.
    set name [get_full_name $pin]
    set slash [string last "/" $name]
    if {$slash < 0} { return $name }
    set inst [get_cells [string range $name 0 [expr {$slash - 1}]]]
    foreach name {Q Q_N} {
        set q [get_pins -quiet [get_full_name $inst]/$name]
        if {$q ne ""} {
            set net [get_nets -quiet -of_objects $q]
            if {$net ne ""} { return [get_full_name $net] }
        }
    }
    return [get_full_name $inst]
}

set ends [find_timing_paths -path_delay max -group_count $::env(PATHS) \
    -endpoint_count 1 -sort_by_slack]
puts "RANK\tSLACK_NS\tARRIVAL_NS\tSTART_PIN\tSTART_REG\tEND_PIN\tEND_REG"
set rank 0
foreach pe $ends {
    incr rank
    set sp [get_property $pe startpoint]
    set ep [get_property $pe endpoint]
    set points [get_property $pe points]
    set arrival [get_property [lindex $points end] arrival]
    puts [format "%d\t%.4f\t%.4f\t%s\t%s\t%s\t%s" $rank \
        [get_property $pe slack] $arrival \
        [get_full_name $sp] [q_net $sp] [get_full_name $ep] [q_net $ep]]
}
