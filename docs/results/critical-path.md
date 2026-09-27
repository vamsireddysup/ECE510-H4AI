# Scale-launch critical-path optimization

This record attributes the P0 timing changes before a new complete-top route.
The results are **measured EDA outputs from mapped, prelayout synthesis**. They
are not routed timing, an achieved clock, or silicon measurements.

## Reproducible setup

Each row uses `qkt_chiplet_top` at 4x4, `D_HEAD=64`, `T_MAX=16`, Bs=32, one
score lane, and a 225 ns constraint. The command is:

```bash
./scripts/run_physical.sh RUN_NAME 225 4 1 synthesis
```

The flow uses OpenLane 1.1.1 image digest
`sha256:26719ced90c315b8b4ad7b9dc3e9a176991cea4c3f3282660d8d60d0f0cae229`,
OpenROAD `b16bda7e82721d10566ff7e2b68f1ff0be9f9e38`, Yosys 0.38
`543faed9c8c`, the Sky130 HD library, and Sky130A PDK revision
`bdc9412b3e468c102d01b7cf6337be06ec6e9c9a`. Generated logs remain under
ignored `build/physical/`; the [CSV](p0-a-critical-path.csv) is the concise
machine-readable record.

## Attribution

| Step | Mapped data arrival | Setup slack at 225 ns | Mapped cells | Mapped cell area |
| --- | ---: | ---: | ---: | ---: |
| Baseline | 95.95 ns | +128.72 ns | 74,491 | 766,267 um² |
| Row/column launch counters | 58.58 ns | +166.09 ns | 68,972 | 729,666 um² |
| Registered scale prefetch | 58.49 ns | +166.18 ns | 69,164 | 732,895 um² |
| Tree-based integer conversion | 58.09 ns | +166.58 ns | 69,400 | 736,351 um² |

Removing variable 32-bit division and modulo produced the material gain: the
mapped path fell by 37.37 ns, or 38.9%, and mapped area fell by 4.8%. The worst
path then moved from the accumulator-to-scaler datapath to synchronous `rst_n`
logic. Scale prefetch and the conversion tree reduced the worst mapped path by a
further 0.49 ns in total because neither was on that new worst path.

The 58.09 ns mapped path is below the 68 ns break-even target. I therefore did
not add the optional accumulator-read pipeline register. A routed result is
still required: the accepted baseline grew from 95.95 ns after mapping to about
196.2 ns after routing, so mapped timing alone cannot establish a frequency.

## Functional and cycle consequences

The coordinate and conversion changes do not alter a score bit. The prefetch
register adds one drain cycle. Bs=32 scaling is now
`ceil(B^2/L) + 7 + 3*(C-1)` cycles per tile, including one prefetch cycle and
six multiplier cycles. CALC still binds at 4x4, so T=512 increases by one command
drain cycle to 1,049,666. All 16 recorded cycle configurations match the updated
closed-form model exactly, and the T=512 RTL precision result remains
14.2346060% relative Frobenius error with every score bit equal to the model.

## Related

- [Results index](README.md)
- [Physical-design result](physical-design.md)
- [Architecture](../architecture.md)
- [Development plan](../roadmap.md)
