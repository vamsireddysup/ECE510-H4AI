# Synthesis Notes and Scope Status -- M3

## What was attempted

The M3 synthesis target was the FP4 QK^T systolic array accelerator with SIZE=4
and D_HEAD=4. Two synthesis approaches were used: standalone yosys 0.44 with ABC
and sky130 HD standard cells, and OpenLane 1.1.1 running inside Docker with the
full floorplan, placement, and CTS flow.

The intended tool was OpenLane 2.3.10. OpenLane 2 was installed via pip into a
Python virtual environment but failed at the synthesis step because it calls
yosys with the -y flag to run Python scripts inside yosys (pyosys). This requires
yosys compiled with ENABLE_PYOSYS=1 which links libyosys as a Python extension
module. Multiple build attempts over several sessions failed because the
boost_python detection in the yosys 0.44 Makefile silently skipped Python support
even when all dependencies were present. The root cause was the library being
named libboost_python312.so.1.83.0 on Ubuntu 24.04 while the Makefile probed for
libboost_python3 and libboost_python-py312 which do not exist at that path.

## What worked

After exhausting OpenLane 2 approaches, two working synthesis paths were found.

Yosys 0.44 standalone with ABC successfully synthesized systolic_array_flat
(the synthesis wrapper with flattened port declarations) against the sky130 HD
liberty file at tt_025C_1v80. This produced 25,378 mapped cells with a chip area
of 188,961 um2. OpenSTA 2.5.0 (from the efabless Docker image) ran STA on the
mapped netlist and reported WNS=-17.26 ns, TNS=-26,731 ns at 250 MHz, with hold
MET at +0.31 ns. The critical path at this stage was the FP32 accumulator chain
at 21.13 ns.

OpenLane 1.1.1 inside the efabless/openlane Docker container completed the full
synthesis, floorplan, and placement flow. It produced area=328,554 um2,
WNS=-2.30 ns after CTS buffered the reset tree, TNS=-1429.82 ns, and a power
estimate of 60.2 mW for SIZE=4. The power report broke down as sequential
95.5% (57.5 mW) and combinational 4.5% (2.71 mW), consistent with a design
dominated by flip-flops in the product buffers and accumulator pipeline.

## What did not work and why

The systolic_array.sv module uses unpacked array ports (a_in [SIZE]) which yosys
0.38 inside the Docker container does not parse. A synthesis wrapper
systolic_array_flat.sv was written to flatten these ports to bit vectors before
instantiating the original module. This added a generate block but did not change
the logic.

The design could not achieve timing closure at 250 MHz in either synthesis flow.
The yosys standalone run showed the FP32 accumulator chain as the critical path
at 21.13 ns. The OpenLane run showed WNS=-2.30 ns after CTS but routing was not
completed because the power report generator crashed looking for a post-route
power file. The synthesis and floorplan stages completed but the routing log was
empty, indicating the flow stopped at global placement.

## RTL changes made during M3

fp32_add.sv was pipelined from 1 cycle to 3 pipeline stages to reduce the
datapath critical path from 21 ns to approximately 7 ns per stage. This is
designated Option B. pe.sv was updated to use a 2-bit wait_count instead of a
single waiting bit to accommodate the 3-cycle fp32_add latency. All testbenches
were updated with increased drain cycle budgets. The 3-stage fp32_add reduced
the standalone STA critical path from 21.13 ns to 19.65 ns -- the remaining
violation is the reset fanout path at 885 fanout on a single clkinv_1 cell,
which requires CTS to fix and cannot be addressed in RTL.

tile_controller.sv required three bug fixes discovered during co-simulation:
the dequantization FSM did not account for the 3-cycle fp32_mul latency, the
STREAM_OUT state read the wrong address from the output tile buffer, and the
tile_buffer module had a single read port that could not supply all TILE_SIZE
row inputs to the systolic array simultaneously. tile_buffer.sv was rewritten
to expose TILE_SIZE parallel read ports sharing a column address.

## Scope status

The original M1 scope of a 16x16 FP4 systolic array computing QK^T for N=512,
d_head=64 remains the design target. The M3 synthesis used SIZE=4, D_HEAD=4 as
the first synthesis target to establish area and timing baselines before
attempting the full-size design. The SIZE=4 result of 328,554 um2 extrapolates
to approximately 5.26 mm2 for SIZE=16, which fits within the Sky130 reticle
limit of 9 mm2.

Timing closure at 250 MHz was not achieved. The achievable frequency from the
OpenLane synthesis STA is approximately 159 MHz (1/(4.0+2.30) ns after CTS
reset buffering). At 159 MHz with SIZE=16, the projected effective throughput is
24.89 GOPS compared to the CPU baseline of 11.36 GFLOP/s, giving a speedup of
2.19x. At the target 250 MHz after full timing closure the projected speedup is
3.45x. Both operating points are reported in M4.

The AXI4-Lite and AXI4-Stream interfaces were integrated and verified end-to-end
in co-simulation showing 16/16 elements correct through the complete pipeline:
host write through AXI4-Lite start register, FP4 tile streaming through
AXI4-Stream, systolic array computation, dequantization via fp32_mul, and result
streaming back through AXI4-Stream to the host.
