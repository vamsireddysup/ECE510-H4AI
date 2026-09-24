# Architecture decision records

One file per decision that is expensive to reverse. Each record states the
decision, what else was considered, the evidence, and the date. I add a record
when a choice would otherwise survive only as an unexplained line of RTL.

A record is not updated when the decision changes. A new record supersedes it, and
the old one gets a line saying which.

| Record | Decision | Status |
| --- | --- | --- |
| [0001](0001-exact-integer-accumulation.md) | Accumulate FP4 products exactly as integers instead of in FP32 | Accepted |
| [0002](0002-k-reload-is-the-default.md) | Ship K reload (active protocol version 3) as the default, not K reuse | Accepted, revisit at P0.5 |
| [0003](0003-fp32-scales-with-32-element-blocks.md) | Use FP32 scales with 32-element reduction blocks | Accepted |

## Naming

Four digits, then a kebab-case summary of the decision, not of the problem.
`0003-e8m0-block-scaling.md`, not `0003-precision-problem.md`.

## Related

- [Repository layout](../repository-layout.md)
- [Documentation index](../README.md)
