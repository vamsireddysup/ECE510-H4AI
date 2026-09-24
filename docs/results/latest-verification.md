# Latest verification

I ran this check on September 24, 2026, from `master` at RTL revision
`c326d55`.

## Commands

```bash
make doctor
make test
```

## Results

| Check | Result |
| --- | --- |
| Active Markdown links and structure | Pass |
| Verilator RTL lint | Pass |
| Python reference-model tests | 19 passed |
| FP4 LUT comparison | All 256 input pairs matched |
| 4x4 integration output | 16/16 correct |
| Completion status | `DONE=YES` |
| Completed tiles | `TILE_COUNT=1` |
| Compatibility cycle count | 498 |

## Tool versions

| Tool | Version |
| --- | --- |
| Verilator | 5.041 development build |
| GCC/G++ | 13.3.0 |
| GNU Make | 4.3 |
| Python | 3.12.3 |
| pytest | 7.4.4 |
| Yosys | 0.44 |
| Icarus Verilog | 12.0 |
| Docker | 29.8.1 |

The optional `sby` command is installed but currently cannot find its Python
modules. Formal verification is not part of this test run yet. GTKWave is
installed, but waveform viewing needs a graphical display.

## Scope

This run verifies one 4x4 tile with `D_HEAD=4` and `T_MAX=16`. It does not prove
multi-tile execution, `D_HEAD=64`, larger arrays, or the full-chip physical
design. I will update this file when those tests are added.
