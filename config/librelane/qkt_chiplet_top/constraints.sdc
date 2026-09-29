# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Project SDC for LibreLane. It keeps the OpenLane 1.1.1 project SDC's timing
# model, translated to LibreLane's variable names.

set clock_port [lindex $::env(CLOCK_PORT) 0]
create_clock [get_ports $clock_port] -name $clock_port -period $::env(CLOCK_PERIOD)
set clocks [get_clocks $clock_port]

# A host that consumes IO_DELAY_CONSTRAINT percent of the cycle sets the
# maximum input and output delays. The minimum input delay is a fixed 3 ns of
# host clock-to-output and interconnect: scaling it with the period creates
# artificial hold failures when the constraint is relaxed. LibreLane only
# exports declared variables here, so the fixed value is written literally.
set io_max_delay [expr {$::env(CLOCK_PERIOD) * $::env(IO_DELAY_CONSTRAINT) / 100.0}]
set input_min_delay 3.0
set output_min_delay 0.0

set_max_fanout $::env(MAX_FANOUT_CONSTRAINT) [current_design]
if {[info exists ::env(MAX_TRANSITION_CONSTRAINT)]} {
    set_max_transition $::env(MAX_TRANSITION_CONSTRAINT) [current_design]
}
if {[info exists ::env(MAX_CAPACITANCE_CONSTRAINT)]} {
    set_max_capacitance $::env(MAX_CAPACITANCE_CONSTRAINT) [current_design]
}

set clk_input [get_port $clock_port]
set clk_index [lsearch [all_inputs] $clk_input]
set data_inputs [lreplace [all_inputs] $clk_index $clk_index]

set_input_delay -max $io_max_delay -clock $clocks $data_inputs
set_input_delay -min $input_min_delay -clock $clocks $data_inputs
set_output_delay -max $io_max_delay -clock $clocks [all_outputs]
set_output_delay -min $output_min_delay -clock $clocks [all_outputs]

if {![info exists ::env(SYNTH_CLK_DRIVING_CELL)]} {
    set ::env(SYNTH_CLK_DRIVING_CELL) $::env(SYNTH_DRIVING_CELL)
}
set_driving_cell \
    -lib_cell [lindex [split $::env(SYNTH_DRIVING_CELL) "/"] 0] \
    -pin [lindex [split $::env(SYNTH_DRIVING_CELL) "/"] 1] \
    $data_inputs
set_driving_cell \
    -lib_cell [lindex [split $::env(SYNTH_CLK_DRIVING_CELL) "/"] 0] \
    -pin [lindex [split $::env(SYNTH_CLK_DRIVING_CELL) "/"] 1] \
    $clk_input

set_load [expr {$::env(OUTPUT_CAP_LOAD) / 1000.0}] [all_outputs]
set_clock_uncertainty $::env(CLOCK_UNCERTAINTY_CONSTRAINT) $clocks
set_clock_transition $::env(CLOCK_TRANSITION_CONSTRAINT) $clocks
set_timing_derate -early [expr {1.0 - $::env(TIME_DERATING_CONSTRAINT) / 100.0}]
set_timing_derate -late [expr {1.0 + $::env(TIME_DERATING_CONSTRAINT) / 100.0}]

if {[info exists ::env(OPENLANE_SDC_IDEAL_CLOCKS)] && $::env(OPENLANE_SDC_IDEAL_CLOCKS)} {
    unset_propagated_clock [all_clocks]
} else {
    set_propagated_clock [all_clocks]
}
