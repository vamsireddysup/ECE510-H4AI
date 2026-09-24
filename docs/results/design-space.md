# QK^T design-space experiment

I compared integrated-top RTL variants at `D_HEAD=64`. All score checks passed
against the exact integer-dot reference. T=512 cycle and byte counts use a
continuously ready host. Sky130 HD cell area uses Yosys 0.44 mapping at the
typical 25 C, 1.80 V Liberty corner with `T_MAX=16`; these area and T=512
numbers have different `T_MAX` builds and are not a single physical
configuration. No variant has routed timing or power evidence yet.
The mapped areas were produced from revision `4ce83ab` plus the default-depth
change committed as `bd28084`. The AXI4-Lite handshake fix made after that
measurement changes cell counts, so the area column is a prior RTL revision;
the cycle column below is from the corrected control slave.

| Tile | Contract | T=512 tiles | Core cycles | Host bytes | FLOP/byte | Scores/cycle | Sky130 mapped cell area, T_MAX=16 |
| ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| 4x4 | v1, K reload | 16,384 | 1,821,184 | 3,166,208 | 10.60 | 0.144 | 304,468 um² |
| 4x4 | v2, K reuse | 16,384 | 1,561,088 | 1,085,440 | 30.91 | 0.168 | 417,158 um² |
| 8x8 | v1, K reload | 4,096 | 817,664 | 2,117,632 | 15.85 | 0.321 | 571,637 um² |
| 16x16 | v1, K reload | 1,024 | 534,016 | 1,593,344 | 21.06 | 0.491 | 1,446,323 um² |

The version 2 K scratchpad saves 2,080,768 transferred bytes and 260,096
simulated cycles at T=512 compared with 4x4 version 1. At `T_MAX=16`, it adds
112,689 um², or 37.0%, to the mapped top. At T=512 it stores 16 KiB of K FP4
codes. Its implemented register array has parallel row reads and has not been
mapped to a physical memory macro. Thus the cell-area comparison is a small
capacity experiment, not the physical cost of the T=512 scratchpad.

The local Sky130 macro set has a 2 KiB 32x512 1RW1R block with a 683.1 by
416.54 um LEF footprint. Eight such macros would provide 16 KiB and occupy
2,276,308 um² before routing, peripherals, and bank spacing. Four banks with
two macros each could supply four independent 32-bit reads per cycle, but the
macro read is clocked and needs address scheduling that the current
combinational register array does not have. The 1 KiB 32x256 macro is 479.78
by 397.5 um; sixteen blocks would occupy 3,051,401 um². These are candidate
capacity and footprint estimates from the locally installed PDK revision
`0fe599b2afb6708d281543108caf8310912f54af`, not an SRAM-integrated top.

Larger arrays reduce simulated cycles but increase mapped area. The 16x16
variant is 3.41 times faster in core cycles than 4x4 version 1 for T=512, but
its mapped area is 4.75 times as large at T_MAX=16. The output interface has a
hard two-score-per-cycle ceiling. Current 16x16 sustained output is 0.491
scores/cycle, so scale, input, and serial tile phases still dominate. Tile
size and K reuse cannot be selected from these figures alone; full-chip
routing, timing, power, and realistic storage mapping remain required.

Commands: `make test-integration-large`, `make test-integration-reuse-large`,
`make test-array8-large`, `make test-array16-large`, and
`./scripts/run_synthesis.sh TILE_SIZE 64 16 K_REUSE`. Full generated logs are
under ignored `build/`.
