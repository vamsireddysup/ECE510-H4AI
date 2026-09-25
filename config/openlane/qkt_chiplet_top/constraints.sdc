if {[info exists ::env(CLOCK_PORT)] && $::env(CLOCK_PORT) != ""} {
    create_clock [get_ports $::env(CLOCK_PORT)] -name $::env(CLOCK_PORT) \
        -period $::env(CLOCK_PERIOD)
} else {
    create_clock -name __VIRTUAL_CLK__ -period $::env(CLOCK_PERIOD)
    set ::env(CLOCK_PORT) __VIRTUAL_CLK__
}

# Model a host that consumes 20% of the cycle for maximum-delay checks.  Keep
# minimum input and output delay at zero; scaling both minimum delays with the
# clock period creates artificial hold failures when the constraint is relaxed.
set io_max_delay [expr {$::env(CLOCK_PERIOD) * 0.20}]
set io_min_delay 0.0

set_max_fanout $::env(MAX_FANOUT_CONSTRAINT) [current_design]
if {[info exists ::env(MAX_TRANSITION_CONSTRAINT)]} {
    set_max_transition $::env(MAX_TRANSITION_CONSTRAINT) [current_design]
}

set clk_input [get_port $::env(CLOCK_PORT)]
set clk_index [lsearch [all_inputs] $clk_input]
set data_inputs [lreplace [all_inputs] $clk_index $clk_index ""]

set_input_delay -max $io_max_delay -clock [get_clocks $::env(CLOCK_PORT)] $data_inputs
set_input_delay -min $io_min_delay -clock [get_clocks $::env(CLOCK_PORT)] $data_inputs
set_output_delay -max $io_max_delay -clock [get_clocks $::env(CLOCK_PORT)] [all_outputs]
set_output_delay -min $io_min_delay -clock [get_clocks $::env(CLOCK_PORT)] [all_outputs]

if {![info exists ::env(SYNTH_CLK_DRIVING_CELL)]} {
    set ::env(SYNTH_CLK_DRIVING_CELL) $::env(SYNTH_DRIVING_CELL)
}
if {![info exists ::env(SYNTH_CLK_DRIVING_CELL_PIN)]} {
    set ::env(SYNTH_CLK_DRIVING_CELL_PIN) $::env(SYNTH_DRIVING_CELL_PIN)
}

set_driving_cell -lib_cell $::env(SYNTH_DRIVING_CELL) \
    -pin $::env(SYNTH_DRIVING_CELL_PIN) $data_inputs
set_driving_cell -lib_cell $::env(SYNTH_CLK_DRIVING_CELL) \
    -pin $::env(SYNTH_CLK_DRIVING_CELL_PIN) $clk_input

set output_load [expr {$::env(OUTPUT_CAP_LOAD) / 1000.0}]
set_load $output_load [all_outputs]
set_clock_uncertainty $::env(SYNTH_CLOCK_UNCERTAINTY) \
    [get_clocks $::env(CLOCK_PORT)]
set_clock_transition $::env(SYNTH_CLOCK_TRANSITION) \
    [get_clocks $::env(CLOCK_PORT)]
set_timing_derate -early [expr {1.0 - $::env(SYNTH_TIMING_DERATE)}]
set_timing_derate -late [expr {1.0 + $::env(SYNTH_TIMING_DERATE)}]

if {[info exists ::env(_PROPAGATE_ALL_CLOCKS)] && $::env(_PROPAGATE_ALL_CLOCKS)} {
    set_propagated_clock [all_clocks]
}
