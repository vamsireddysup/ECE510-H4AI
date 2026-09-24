# P2: programmable reconfigurable accelerator

This statement is recorded and shelved. Nothing starts on it without an explicit
decision to do so. Read it to see why it is parked and what would have to be true
to start.

## The question

> Can a programmable accelerator dynamically reconfigure its compute array,
> precision, memory allocation and dataflow to efficiently execute different AI
> models rather than building one accelerator for one workload?

## Why it is shelved

Two reasons, both about scope rather than interest.

The question as written is the thesis of an established sub-field and of every
commercial NPU. MAERI covers reconfigurable interconnect for arbitrary dataflow,
Eyeriss v2 covers a flexible on-chip network across layer shapes and sparsity,
Planaria covers a dynamically fissionable array for multiple tenants, SIGMA covers
flexible sparse GEMM, and Gemmini argues the opposite case, that this belongs at
design time in a configurable generator rather than at run time in silicon. A weak
version of P2, meaning a few configuration registers on a fixed array, would not
be a contribution.

The current engine is one operation at one precision, with softmax and the V
multiply on the host, no on-chip memory hierarchy, and no routed physical result.
"Different AI models" needs a general GEMM engine with a memory hierarchy at
minimum. That gap, not the reconfiguration logic, is the dominant cost.

## What would have to be true to start

P1 complete, so precision reconfiguration has a measured cost and benefit rather
than an assumed one. A routed physical result from P0.7, so area and energy claims
have a basis. And a decision about whether the engine generalizes from `Q * K^T`
to GEMM, which is a larger change than anything in P0 or P1.

P1's precision axis is a strict subset of P2's reconfiguration axes, so P1 work is
reusable here and nothing is redone by waiting.

## Related

- [Problem statements](README.md)
- [P1](p1-format-agile-sparsity.md)
