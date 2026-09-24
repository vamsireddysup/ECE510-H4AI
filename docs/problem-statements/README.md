# Problem statements

I work on one problem statement at a time. This page says which one is active,
what each one has to prove, and where its evidence lives. Each statement has its
own page with the stages and their exit conditions.

| Statement | Question | Status |
| --- | --- | --- |
| [P0](p0-dense-fp4-matmul.md) | Dense FP4 `Q * K^T` that is accurate, efficient, and physically closed | Active |
| [P1](p1-format-agile-sparsity.md) | Runtime FP4/INT4/FP8 selection and sparsity, on P0's datapath | Next, starts no earlier than P0.4 |
| [P2](p2-programmable-accelerator.md) | A programmable accelerator that reconfigures array, precision, memory, and dataflow | Shelved, recorded only |

## Why this order

P1's precision axis is a strict subset of P2's reconfiguration axes, so P1 work
is reusable in P2 and nothing is redone. P1 needs a settled baseline format and a
settled accumulator before it can measure the cost of changing them, which is why
it waits on P0.

P0 is not finished when the engine is fast. It is finished when the scores are
accurate enough to use, the array sustains a defensible fraction of its
arithmetic peak, and one named configuration has routed Sky130 timing and power.

## Related

- [Development plan](../roadmap.md)
- [Architecture](../architecture.md)
- [Documentation index](../README.md)
