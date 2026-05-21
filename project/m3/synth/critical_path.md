# Critical Path Analysis -- FP4 QK^T Systolic Array

## Tool and design

Tool: OpenLane 1.1.1 (yosys + openroad, sky130A HD tt_025C_1v80)
Design: systolic_array_flat (TILE_SIZE=4, D_HEAD=4, WIDTH=4, ACC_W=32)
Clock target: 4.0 ns (250 MHz)

## Critical path (post-synthesis STA)

Startpoint: rst_n (input port, clocked by clk)
Endpoint:   _44711_ (sky130_fd_sc_hd__dfxtp_1, rising edge flip-flop)
Path delay: 19.65 ns
WNS:        -15.79 ns (setup violated)
Hold WNS:   +0.31 ns (met)

## Path trace

The critical path runs through the reset distribution network:

1. rst_n input port (external delay 0.5 ns)
2. _23670_ sky130_fd_sc_hd__clkinv_1 -- rst_n inverter, fanout=885, slew=15.07 ns, delay=11.32 ns
3. _24749_ sky130_fd_sc_hd__nor2_1 -- reset gate, delay=6.00 ns
4. _24750_ sky130_fd_sc_hd__clkinv_1 -- delay=0.28 ns
5. _24751_ sky130_fd_sc_hd__nor3b_1 -- delay=0.69 ns
6. _24752_ sky130_fd_sc_hd__nor2_1 -- delay=0.24 ns
7. _24753_ sky130_fd_sc_hd__a22o_1 -- delay=0.63 ns
8. _44711_ flip-flop D input

## Why this is the critical path

The single inverter _23670_ drives 885 fanout nets -- the entire reset tree of the design. At sky130 HD typical drive strength, a single clkinv_1 cell cannot drive 885 loads within one clock period. The resulting slew of 15.07 ns dominates the 19.65 ns total path delay. This is a reset fanout problem, not a datapath depth problem.

## What would shorten it

Clock tree synthesis (CTS) with reset buffering would fix this automatically. OpenLane's full routing stage inserts buffer trees that split the 885-fanout reset into multiple smaller fanout groups, each driven by a properly-sized buffer. In the standalone yosys+OpenSTA run (without CTS), WNS was -17.26 ns at the FP32 accumulator chain -- confirming that after reset buffering, the datapath becomes the bottleneck at approximately 21 ns. Pipelining fp32_add into 3 stages (implemented in Option B) reduces the datapath critical path to approximately 7 ns per stage, enabling 143 MHz operation without further optimization.
