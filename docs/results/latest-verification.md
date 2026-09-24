# Latest verification

I ran the active RTL checks on September 24, 2026, on `master` after revision
`8abc7b9`. The subsequent test and documentation commit contains the exact
regression source used for these results.

## Commands and results

| Command | Result |
| --- | --- |
| `make test` | Markdown, RTL lint, 19 model tests, and small integration pass |
| `make test-integration-large` | T=64/128/512, `D_HEAD=64`, all scores pass |
| `python3 scripts/bench_cpu.py` | Fixed-input, one-thread CPU timings recorded |
| Yosys full-top Sky130 HD mapping | 204,039 um² at D=4; 303,141 um² at D=64, both `T_MAX=16` |

The integration suite checks `D_HEAD=4/64`, T=1/4/7/8/16, original M4
numerical inputs, edge masks, packet counts, output stability under stalls,
malformed scale packets, dimension error, reset, and repeated commands. Large
runs use a continuously ready host. At T=512, the result is 262,144 scores,
16,384 tiles, 1,821,185 simulated cycles, 264,704 input beats, and 131,072
output beats. See [the result record](packed-engine.md) for traffic arithmetic
and scope.

## Tools and limits

Verilator 5.041 development build, GCC 13.3.0, Python 3.12.3, pytest 7.4.4,
NumPy 1.26.4, and Yosys 0.44 were used. The mapped Sky130 Liberty corner was
typical 25 C, 1.80 V. The active top has not completed routing, STA, or power
analysis. The CPU benchmark is a measured NumPy implementation, not a CPU
Roofline peak. Generated logs are under `build/integration/` and
`build/synthesis/`.
