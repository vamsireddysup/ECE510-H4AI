# Latest verification

I ran the active checks on September 24, 2026, on `master` at revision
`b48c209`. This run covers the P0.1 repository and documentation work. It adds no
new synthesis or physical evidence, so the Sky130 areas below are carried from the
earlier revisions that produced them.

## Commands and results

| Command | Result |
| --- | --- |
| `make check-docs` | 29 active documents pass: one H1 each, every relative link and anchor resolves, every document has a `## Related` block, none more than two hops from `README.md` |
| `make lint` | All five parameter sets pass under `-Wall`: 4x4 at `D_HEAD=4`; 4x4 at `D_HEAD=64`, `T_MAX=512` for both protocols; 8x8; 16x16 |
| `make test-model` | 19 passed, including all 256 FP4 product pairs against the checked-in ROM |
| `make test-integration` | `D_HEAD=4` and `64`, T=1/4/7/8/16, with host stalls injected. All scores pass |
| `make test-integration-large` | T=64/128/512 at `D_HEAD=64`. All scores pass |
| `make test-integration-reuse`, `make test-integration-reuse-large` | Protocol version 2 at both scales. All scores pass |
| `make test-array8`, `make test-array16` | Both tile sizes pass edge and packet tests |
| `python3 scripts/cycle_model.py` | The closed-form cycle model reproduces all six measured configurations exactly |

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
depend on the simulator version. This run corrected
[the packed engine record](packed-engine.md), whose core-cycle column had been one
higher than register `0x10` returns on all nine of its rows.

## Tools

| Tool | Version |
| --- | --- |
| Verilator | 5.042, and 5.020 for the cross-check |
| GCC/G++ | 13.3.0 |
| GNU Make | 4.3 |
| Python | 3.11.15 |
| pytest | 9.1.1 |
| NumPy | 2.4.6 |

These differ from the earlier recorded run, which used Verilator 5.041, Python
3.12.3, pytest 7.4.4, and NumPy 1.26.4. `pyproject.toml` pins `pytest>=7.4,<9`,
so the 9.1.1 used here is outside that pin; the model tests pass under both, and
CI installs from `pyproject.toml` and therefore still resolves below 9.

Yosys was not available in this environment, so no synthesis ran. The mapped
Sky130 areas in [the design-space record](design-space.md) and
[the packed engine record](packed-engine.md) are unchanged and belong to the
revisions named there.

## Scope and limits

This run proves functional correctness, protocol behavior, and cycle counts for
the configurations listed. It does not prove routed timing, power, frequency, or
latency in seconds, because no configuration of this top has been routed. It does
not measure error on real transformer activations; the only precision figure is
synthetic. See [the verification plan](../verification-plan.md) for the full list
of gaps.

Generated logs are under `build/integration/`, one directory per configuration.

## Related

- [Results index](README.md)
- [Verification plan](../verification-plan.md)
- [Packed engine result](packed-engine.md)
