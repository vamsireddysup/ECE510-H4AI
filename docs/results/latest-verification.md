# Latest verification

I ran the complete P0.3 verification matrix on September 24, 2026, on `master`
at revision `08a307d`. P0.3 changes scheduling and storage banks while holding
every score equal to the existing exact integer-dot reference. It adds no new
synthesis or physical evidence.

## Commands and results

| Command | Result |
| --- | --- |
| `make check-docs` | 30 active documents pass all structure, link, orphan, and two-hop reachability checks |
| `make lint` | All five parameter sets pass under `-Wall` |
| `make test-model` | 28 passed, including the committed precision-JSON and Markdown-table regeneration check |
| `make test-integration`, `make test-integration-large` | Version 1 passes D=4/64, T=1/4/7/8/16/64/128/512, stalls, malformed packets, reset, and repeated commands |
| `make test-integration-reuse`, `make test-integration-reuse-large` | Version 2 passes the same small cases and T=64/128/512 |
| `make test-array8`, `make test-array16` | Both larger arrays pass edge, stall, and packet tests |
| `make test-array8-large`, `make test-array16-large` | Both pass T=64/128/512 with continuously ready streams |
| `python3 scripts/cycle_model.py` | All six measured cycle and input-beat configurations reproduced exactly |
| `make report-sim` | Regenerated `build/integration/summary.csv` from the verified logs |

The 4x4 T=512 test contains an explicit regression ceiling of 1,049,150 core
cycles.

## Measured core cycles

Continuously ready streams at `D_HEAD=64`:

| Configuration | Core cycles | Input beats | Output beats | Array active |
| --- | ---: | ---: | ---: | ---: |
| 4x4 v1, T=64 | 16,510 | 4,416 | 2,048 | 99.24% |
| 4x4 v1, T=128 | 65,726 | 17,024 | 8,192 | 99.71% |
| 4x4 v1, T=512 | 1,049,150 | 264,704 | 131,072 | 99.945% |
| 4x4 v2, T=512 | 1,051,182 | 4,608 | 131,072 | 99.75% |
| 8x8 v1, T=512 | 287,392 | 133,632 | 131,072 | 91.21% |
| 16x16 v1, T=512 | 269,120 | 68,096 | 131,072 | 24.35% |

The previous serial 4x4 v1 run took 1,821,184 cycles, so P0.3 measures 1.736x
speedup. `CALC` binds at 4x4; the one-lane `SCALING` stage binds at 8x8 and
16x16. The exact fill, drain, and steady-state derivation is in
[architecture](../architecture.md).

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

This run proves score equivalence, protocol behavior, stage overlap, cycle counts,
and the closed-form model for the listed configurations. It does not prove the
selected 1x32 format in RTL because P0.4 has not implemented it. It does not prove routed timing, power, frequency, or
latency in seconds, because no configuration of this top has been routed. It does
not measure error on real transformer activations; the P0.2 precision evidence is
synthetic. See [the verification plan](../verification-plan.md) for the full list
of gaps.

Generated logs are under `build/integration/`, one directory per configuration.

## Related

- [Results index](README.md)
- [Verification plan](../verification-plan.md)
- [Packed engine result](packed-engine.md)
