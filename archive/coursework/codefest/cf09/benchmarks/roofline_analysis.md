# CF09 -- CLLM: Roofline Analysis

## Accelerator operating point

The accelerator point is **projected** (not measured end-to-end at full N=512, d=64).

Projected throughput at 80.06 MHz, SIZE=4: 0.64 GFLOP/s
Arithmetic intensity (upper bound, full reuse): 31.03 FLOP/byte

The projected point sits far below the compute ceiling of 10.25 GOPS.
The gap has one dominant cause: SIZE=4 covers only 16 PEs, requiring 262,144 tile
iterations to complete the full 512×512 QK^T computation. At 498 cycles per tile and
80 MHz, tiling control overhead dominates execution time, not the systolic array
compute time itself. The PEs are idle during address generation, memory loading, and
FSM state transitions between tiles. Effective PE utilization is therefore well below
1%, not because memory bandwidth is saturated, but because the tile controller spends
most cycles on overhead rather than feeding the array.

The single dominant uncertainty in the projection is the tiling overhead ratio. The
co-simulation measured 498 cycles for a 4×4 tile with D_HEAD=4. Scaling this linearly
to D_HEAD=64 and 16,384 tiles assumes zero pipeline overlap between tiles. A pipelined
tile controller that prefetches the next tile while the array drains would reduce this
overhead significantly. Measuring the actual tile-to-tile pipeline efficiency on an
FPGA or in a full-design co-simulation would convert the projection to a measurement.
