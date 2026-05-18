read_liberty /root/.volare/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog /work/reports/synth_out.v
link_design systolic_array_synth

create_clock -name clk -period 4.0 [get_ports clk]
set_input_delay 0.5 -clock clk [all_inputs]
set_output_delay 0.5 -clock clk [all_outputs]

report_checks -path_delay max -fields {slew cap input nets fanout} -format full_clock_expanded
report_worst_slack -max
report_tns
report_wns
report_checks -path_delay min -fields {slew cap input nets fanout} -format full_clock_expanded
