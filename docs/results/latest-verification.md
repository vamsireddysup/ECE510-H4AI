# Latest verification

I ran the complete P0.4 and P0.6 verification matrix on September 24, 2026, on
`master` at revision `1311eb0`. The target was the complete
`qkt_chiplet_top` with `D_HEAD=64`, FP32 scales, default
`SCALE_BLOCK_SIZE=32`, and protocol version 3 unless a row says otherwise.
These are RTL simulation results; no clock constraint or PDK applies.

## Commands and results

| Command | Result |
| --- | --- |
| `make test` | Documentation checks, eight lint configurations, 28 model tests, and the 4x4 small integration suite pass |
| `make test-integration-large` | Version 3 passes T=64/128/512; T=512 is 1,049,665 cycles |
| `make test-integration-reuse`, `make test-integration-reuse-large` | Version 4 passes D=4/64 and T through 512 |
| `make test-array8`, `make test-array16`, and both `-large` forms | Both arrays pass edge, stall, packet, and T=64/128/512 checks |
| `SCALE_BLOCK_SIZE=16 make test-integration` | The nondefault four-block configuration passes D=4/64 and all small cases |
| `make test-precision-rtl` | All 262,144 T=512 scores match the software 1x32 FP32 model bit-exactly |
| `SCORE_LANES=2/4 make test-array8-large` | T=512 takes 263,305/263,289 cycles |
| `SCORE_LANES=2/4 make test-array16-large` | T=512 takes 141,632/132,361 cycles |
| `python3 scripts/cycle_model.py` | All 16 measured cycle and input-beat configurations reproduce exactly |
| `make report-sim` | Regenerates `build/integration/summary.csv` from accepted-beat logs |
| Isolated `uv run` with NumPy 2.4.6 and pytest 8.4.2 | All 28 tests pass, including precision provenance at `rel=1e-6` |
| GitHub Actions at `f9ab75d` | Passes on Ubuntu 24.04 with its packaged Verilator 5.020 after reproducing and fixing the older lint limitation |

The 4x4 T=512 test has an explicit regression ceiling of 1,049,665 core cycles.
The machine-readable reviewed subset is
[`p0-4-p0-6-simulation.csv`](p0-4-p0-6-simulation.csv).

## Default block-scale measurements

Continuously ready streams at `D_HEAD=64`, Bs=32, and one score lane:

| Configuration | Core cycles | Input beats | Output beats | Array active | Binding stage |
| --- | ---: | ---: | ---: | ---: | --- |
| 4x4 v3, T=64 | 16,577 | 4,480 | 2,048 | 98.84% | CALC |
| 4x4 v3, T=128 | 65,857 | 17,152 | 8,192 | 99.51% | CALC |
| 4x4 v3, T=512 | 1,049,665 | 265,216 | 131,072 | 99.896% | CALC |
| 4x4 v4, T=512 | 1,051,697 | 5,120 | 131,072 | 99.70% | CALC |
| 8x8 v3, T=512 | 300,192 | 134,144 | 131,072 | 87.33% | SCALING |
| 16x16 v3, T=512 | 272,704 | 68,608 | 131,072 | 24.03% | SCALING |

The extra block scales add 512 input beats over P0.3 at T=512. Parallel block
scaling keeps 4x4 compute-bound; the three-cycle cross-block add appears only in
pipeline drain. Relative Frobenius error against the pinned FP32 QK^T reference
is **14.2346060%**, and mean absolute score error is **0.903700367**. These match
the software model's 1x32 FP32 path.

## P0.6 score-lane sweep

| Tile | Score lanes | Scaling cycles/tile | Binding stage | T=512 cycles | Array active |
| ---: | ---: | ---: | --- | ---: | ---: |
| 8x8 | 1 | 73 | SCALING, 73 | 300,192 | 87.33% |
| 8x8 | 2 | 41 | CALC, 64 | 263,305 | 99.56% |
| 8x8 | 4 | 25 | CALC, 64 | 263,289 | 99.57% |
| 16x16 | 1 | 265 | SCALING, 265 | 272,704 | 24.03% |
| 16x16 | 2 | 137 | SCALING, 137 | 141,632 | 46.27% |
| 16x16 | 4 | 73 | OUTPUT, 128 | 132,361 | 49.51% |

The 8x8 crossover is two lanes and moves to CALC, because its 32-cycle output
stage is always shorter than the 64-cycle dot product. The 16x16 crossover is
four lanes and moves to the 64-bit output. Its 132,361 measured cycles equal the
131,072-cycle two-score-per-cycle steady floor plus 1,289 fill and drain cycles.
Widening the output before scaling would buy no cycles, so P0.6 keeps 64 bits.

## Tools

| Tool | Version |
| --- | --- |
| Verilator | 5.041 development revision v5.040-196-g63f5f5c32 locally; 5.020 in passing GitHub CI |
| GCC/G++ | 13.3.0 |
| GNU Make | 4.3 |
| Python | 3.12.3 |
| pytest | 7.4.4 |
| NumPy | 1.26.4 generated the committed precision record; the extras accept 1.26.4 through 2.x |

Yosys was not available, so P0.4 and the lane variants have no synthesis or
physical evidence. The mapped Sky130 areas in the older result records belong
to their named revisions. This run proves functional correctness, protocol
behavior, the cycle model, and synthetic precision for finite normal scales. It
does not prove subnormal IEEE behavior, routed timing, power, frequency,
latency in seconds, or accuracy on real transformer activations.

Generated logs remain under ignored `build/`; the concise CSV above is the
committed result.

## P0.7 physical update

On September 25, 2026, revision `98e5623` completed the first full GDS flow for
the 4x4, `D_HEAD=64`, `T_MAX=16`, Bs=32, one-lane top. The 2200 um die has zero
detailed-route, Magic DRC, KLayout DRC, and LVS errors. It has 262 pin and 225
net antenna violations. Extracted worst-corner setup WNS is -71.08 ns and worst
hold slack is -0.04 ns at 125 ns, so this is a routed failure, not timing
closure. The power report is rejected because 13,148 slew and 471 fanout checks
remain. Full provenance and the sweep are in
[the physical-design record](physical-design.md).

## Related

- [Results index](README.md)
- [Architecture and cycle model](../architecture.md)
- [Stream protocol](../stream-protocol.md)
- [Verification plan](../verification-plan.md)
