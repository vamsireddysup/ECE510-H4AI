# Latest verification

I ran the required checks on September 24, 2026, on `master` at revision
`93e7292`. This run covers the P0.2 software model, precision sweep, and scale-format
decision. No SystemVerilog changed in P0.2, and this run adds no synthesis or
physical evidence, so the Sky130 areas below are carried from the earlier
revisions that produced them.

## Commands and results

| Command | Result |
| --- | --- |
| `make check-docs` | 30 active documents pass: one H1 each, every relative link and anchor resolves, every document has a `## Related` block, none more than two hops from `README.md` |
| `make lint` | All five parameter sets pass under `-Wall`: 4x4 at `D_HEAD=4`; 4x4 at `D_HEAD=64`, `T_MAX=512` for both protocols; 8x8; 16x16 |
| `make test-model` | 27 passed, including NumPy scale matrices, three E8M0 rounding rules, the 14.90% compatibility point, and all 256 FP4 product pairs |
| `make test-integration` | `D_HEAD=4` and `64`, T=1/4/7/8/16, with host stalls injected. All scores pass |
| `python3 scripts/eval_precision.py` | 120 combinations complete: T=4/16/64/128/512, Bs=64/32/16/8/4/2, and four scale types |

The aggregate `make test` target passed. The larger integration, K-reuse, and
8x8/16x16 simulation results below were not rerun because P0.2 changed only
Python and Markdown; their last verified run remains revision `b48c209`.

## Measured core cycles

Continuously ready host at `D_HEAD=64`, unless the row says stalls were injected.

| Configuration | Core cycles | Input beats | Output beats |
| --- | ---: | ---: | ---: |
| 4x4 v1, T=64 | 28,736 | 4,416 | 2,048 |
| 4x4 v1, T=128 | 114,304 | 17,024 | 8,192 |
| 4x4 v1, T=512 | 1,821,184 | 264,704 | 131,072 |
| 4x4 v2, T=512 | 1,561,088 | 4,608 | 131,072 |
| 4x4 v1, T=16, stalls injected | 2,431 | 336 | 128 |
| 4x4 v1, T=4, `D_HEAD=4`, stalls injected | 49 | 6 | 8 |

Every value is identical under Verilator 5.020 and 5.042, so these counts do not
depend on the simulator version. The packed-engine cycle table was corrected in
P0.1 at revision `2b95e3d`; its core-cycle column had been one higher than register
`0x10` returns on all nine rows.

## Tools

| Tool | Version |
| --- | --- |
| Verilator | 5.041 development revision v5.040-196-g63f5f5c32 |
| GCC/G++ | 13.3.0 |
| GNU Make | 4.3 |
| Python | 3.12.3 |
| pytest | 7.4.4 |
| NumPy | 1.26.4 |

These versions satisfy `pyproject.toml`, which requires Python 3.10 or newer,
pytest from 7.4 through 8.x, and NumPy from 1.26 through 2.x.

Yosys was not available in this environment, so no synthesis ran. The mapped
Sky130 areas in [the design-space record](design-space.md) and
[the packed engine record](packed-engine.md) are unchanged and belong to the
revisions named there.

## Scope and limits

This run proves the software block-scale behavior, reproducibility of the old
1x64 precision point, documentation integrity, unchanged RTL lint, and the required
integration cases. It does not prove the selected 1x32 format in RTL because P0.4
has not implemented it. It does not prove routed timing, power, frequency, or
latency in seconds, because no configuration of this top has been routed. It does
not measure error on real transformer activations; the P0.2 precision evidence is
synthetic. See [the verification plan](../verification-plan.md) for the full list
of gaps.

Generated logs are under `build/integration/`, one directory per configuration.

## Related

- [Results index](README.md)
- [Verification plan](../verification-plan.md)
- [Packed engine result](packed-engine.md)
