# Latest verification

I ran the active RTL checks on September 24, 2026, on `master` after revision
`bd28084`. This summary accompanies the AXI4-Lite handshake fix; the reported
Sky130 cell areas belong to the earlier design-space revision.

## Commands and results

| Command | Result |
| --- | --- |
| `make test` | Markdown, RTL lint, 19 model tests, and small integration pass |
| `make test-integration-large` | T=64/128/512, `D_HEAD=64`, all scores pass |
| `make test-integration-reuse` and `make test-integration-reuse-large` | Version 2 K reuse, all scores pass |
| `make test-array8` and `make test-array16` | Both sizes pass small edge and packet tests |
| `make test-array8-large` and `make test-array16-large` | T=64/128/512, all scores pass |
| `python3 scripts/bench_cpu.py` | Fixed-input, one-thread CPU timings recorded |
| `python3 scripts/eval_precision.py` | Fixed-seed synthetic FP4 score error recorded |
| Yosys full-top Sky130 HD mapping | 206,298 um² at 4x4/D=4; see design-space table for D=64 variants, all `T_MAX=16` |

The integration suite checks `D_HEAD=4/64`, T=1/4/7/8/16, original M4
numerical inputs, edge masks, packet counts, output stability under stalls,
random FP4 codes, varied exact scales, worst-case integer sums, malformed
scale and tile packets, dimension error, reset, repeated commands,
AXI4-Lite write-data-first and simultaneous writes, byte strobes, and stable
read data under backpressure. Large runs use a continuously ready host. At
T=512, the result is 262,144 scores,
16,384 tiles, 1,821,184 simulated cycles, 264,704 input beats, and 131,072
output beats. See [the result record](packed-engine.md) for traffic arithmetic
and scope. The [design-space record](design-space.md) gives the optional K
scratchpad and larger-array comparisons.

## Tools and limits

Verilator 5.041 development build, GCC 13.3.0, Python 3.12.3, pytest 7.4.4,
NumPy 1.26.4, and Yosys 0.44 were used. The mapped Sky130 Liberty corner was
typical 25 C, 1.80 V. The active top has not completed routing, STA, or power
analysis. The CPU benchmark is a measured NumPy implementation, not a CPU
Roofline peak. Generated logs are under `build/integration/` and
`build/synthesis/`.
