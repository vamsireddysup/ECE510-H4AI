# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Area, utilization, and three-corner worst setup and hold slack of a placed or
# globally routed OpenLane database, with placement-estimated wire parasitics.
#   env RUN_DIR  OpenLane run directory (…/runs/full)
#   env ODB      database to analyze
source $::env(RUN_DIR)/config.tcl
set ::env(CURRENT_ODB) $::env(ODB)
source $::env(SCRIPTS_DIR)/openroad/common/io.tcl
read -lib_slowest $::env(LIB_SLOWEST) -lib_fastest $::env(LIB_FASTEST) -no_spefs
set_propagated_clock [all_clocks]
source $::env(SCRIPTS_DIR)/openroad/common/set_rc.tcl
estimate_parasitics -placement
report_design_area
# io.tcl names the corners Slowest, Typical, and Fastest.
foreach corner {Slowest Typical Fastest} {
    puts "CORNER $corner setup"
    report_worst_slack -max -corner $corner -digits 4
    puts "CORNER $corner hold"
    report_worst_slack -min -corner $corner -digits 4
}
report_check_types -max_slew -max_capacitance -max_fanout -violators -format end
