# Remaining tasks before M4 final submission

## Task 1: Fix setup timing violations in fp32_add critical path

The post-route critical path is 5.05 ns through the fp32_add accumulator chain,
giving WNS=-8.49 ns at 250 MHz. Insert a pipeline register after the mantissa
addition stage in fp32_add.sv (currently a 3-stage pipeline) to split the 5.05 ns
path into two sub-2.5 ns stages, targeting timing closure at 250 MHz.

## Task 2: Increase systolic array SIZE from 4 to 16 for full benchmark

The co-simulation and synthesis use SIZE=4 (16 PEs). The M1 design target is SIZE=16
(256 PEs). Run a full co-simulation with TILE_SIZE=16 and D_HEAD=64 to measure actual
end-to-end latency for N=512. This converts the projected benchmark numbers to
measured numbers and validates the tiling controller at full operating scale.

## Task 3: Fix max fanout violations by adding buffer tree in tile_controller reset path

OpenLane reports 404 max fanout violations. The dominant cause is the rst_n net driving
885 fanout loads through a single clkinv_1 cell (identified in critical_path.md). Add
an explicit reset buffer tree in tile_controller.sv using generate blocks to split the
reset distribution into four sub-trees of ~220 fanout each, reducing the single-driver
slew from 15.07 ns to under 2 ns and eliminating the fanout violations.
