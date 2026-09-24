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
the cycle column below is from revision `08a307d` after P0.3 overlap. The area
column predates the extra banks and is not an area measurement of the current
RTL. Cycle and traffic columns are from revision `1311eb0`, Verilator 5.041,
protocol versions 3 and 4, Bs=32, and one score lane.

| Tile | Contract | T=512 tiles | Core cycles | Host bytes | FLOP/byte | Scores/cycle | Array active | Sky130 mapped cell area, T_MAX=16 |
| ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 4x4 | v3, K reload | 16,384 | 1,049,665 | 3,170,304 | 10.58 | 0.250 | 99.90% | 304,468 um² |
| 4x4 | v4, K reuse | 16,384 | 1,051,697 | 1,089,536 | 30.80 | 0.249 | 99.70% | 417,158 um² |
| 8x8 | v3, K reload | 4,096 | 300,192 | 2,121,728 | 15.81 | 0.873 | 87.33% | 571,637 um² |
| 16x16 | v3, K reload | 1,024 | 272,704 | 1,597,440 | 21.01 | 0.961 | 24.03% | 1,446,323 um² |

The version 4 K scratchpad saves 2,080,768 transferred bytes at T=512. After
overlap it takes 2,032 more cycles than version 3 because its complete K-cache
fill is startup, while version 3 hides each 16-cycle K load behind 64-cycle
calculation. At `T_MAX=16`, the historical pre-overlap mapping adds 112,689 um²,
or 37.0%, to the top. At T=512 the scratchpad stores 16 KiB of K FP4 codes. Its
register array has parallel row reads and has not been mapped to a physical
memory macro. The cell-area comparison is a small-capacity, earlier-revision
experiment, not the physical cost of the current scheduler.

I also mapped both complete 4x4 variants at `T_MAX=512` with the corrected
AXI4-Lite slave, Yosys 0.44, and the same Sky130 HD typical Liberty file.
Version 1 occupies **1,596,280 um²** of mapped standard cells. Version 2
occupies **6,672,971 um²**. Command-level K reuse cuts host bytes by about
2.9x, but the current register and mux implementation grows mapped cell area
by about 4.18x at full capacity. These are synthesis areas without clock-tree,
routing, timing, macro, or power results. Version 3 remains the default until
a physical memory organization changes that tradeoff.

The local Sky130 macro set has a 2 KiB 32x512 1RW1R block with a 683.1 by
416.54 um LEF footprint. Eight such macros would provide 16 KiB and occupy
2,276,308 um² before routing, peripherals, and bank spacing. Four banks with
two macros each could supply four independent 32-bit reads per cycle, but the
macro read is clocked and needs address scheduling that the current
combinational register array does not have. The 1 KiB 32x256 macro is 479.78
by 397.5 um; sixteen blocks would occupy 3,051,401 um². These are candidate
capacity and footprint estimates from the locally installed PDK revision
`0fe599b2afb6708d281543108caf8310912f54af`, not an SRAM-integrated top.

Array active is useful FLOPs divided by core cycles times the array's two-FLOP
per-PE ceiling. The 4x4 version reaches 99.90%; 8x8 reaches 87.33% because scaling
binds at 73 cycles against 64 for calculation. The 16x16 version reaches 24.03%
because one score lane takes 265 scaling cycles. It is 3.85x faster in cycles than 4x4,
but its historical mapped area is 4.75x as large at `T_MAX=16`.

### P0.6 score-lane sweep

| Tile | Lanes | Scaling cycles/tile | Binding stage | T=512 cycles | Change from one lane |
| ---: | ---: | ---: | --- | ---: | ---: |
| 8x8 | 1 | 73 | SCALING | 300,192 | baseline |
| 8x8 | 2 | 41 | CALC | 263,305 | 1.140x faster |
| 8x8 | 4 | 25 | CALC | 263,289 | 1.140x faster |
| 16x16 | 1 | 265 | SCALING | 272,704 | baseline |
| 16x16 | 2 | 137 | SCALING | 141,632 | 1.926x faster |
| 16x16 | 4 | 73 | OUTPUT | 132,361 | 2.060x faster |

Two lanes are enough at 8x8; output never binds because its 32-cycle tile time
is below 64-cycle CALC. Four lanes are the first 16x16 point below its 128-cycle
output time. The measured 132,361 cycles are 1,289 above the 131,072-cycle
steady output floor because command startup and final drain remain. P0.6 keeps
the 64-bit port. These lane counts have simulation evidence only; their area,
timing, and power have not been synthesized or routed.

Commands: `make test-integration-large`, `make test-integration-reuse-large`,
`make test-array8-large`, `make test-array16-large`, and
`./scripts/run_synthesis.sh TILE_SIZE 64 16 K_REUSE`. Full generated logs are
under ignored `build/`.

## Related

- [Results index](README.md)
- [ADR 0002: K reload is the default](../adr/0002-k-reload-is-the-default.md)
- [Architecture and the cycle model](../architecture.md)
