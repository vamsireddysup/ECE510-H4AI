# 0006: use replicated 4x4 engines for the next physical prototype

Accepted, September 2026. This records the direction after the bounded 16x16
synthesis investigation; it does not claim that replicated-engine RTL exists.

## Decision

Stop pursuing the monolithic 16x16 four-lane top in P0.7. Build the next physical
prototype from replicated 4x4 engines with command-level K reuse, shared input
and output ports, and ordered tile retirement.

## Evidence

The original 16x16 run already used `T_MAX=16`, so reducing the compiled sequence
capacity cannot remove its blocker. Its Yosys log names `acc_bank`: dynamic writes
produce 31,654 process signals and thousands of memory ports before the pass
stalls in `OPT_MEM_PRIORITY`. `k_cache`, `sq`, and `sk` are present but are not the
first scaling failure.

Two bounded alternatives were tested from the same RTL behavior:

- Statically addressed accumulator cells removed `OPT_MEM_PRIORITY`, but exposing
  their values through the monolithic selector expanded technology mapping to
  12.4 GB before the process was killed.
- A custom Yosys sequence omitted the optional `opt_mem_priority` optimization.
  It preserved the memory write-priority masks and reached `MEMORY_COLLECT` and
  `MEMORY_MAP`, but produced no mapped netlist within a ten-minute bound.

The verified model projects eight 4x4 engines with K reuse at 134,194 cycles for
T=512, versus 133,392 simulated cycles for the 16x16 L4 top. Both remain
projections in seconds until their own routed setup and hold timing closes.

## Consequences

The replicated top must share scale and K storage rather than cloning eight
complete register files. It also needs an internal tile ordinal and reorder
buffer so protocol version 6 output remains ordered. The 64-bit output port caps
the steady rate at two FP32 scores per cycle.

The first implementation checkpoint is functional RTL and bit-exact simulation;
the second is mapped hierarchy area; the third is a routed result. If shared
storage, arbitration, or reorder area erases the physical advantage, the result
will be recorded rather than replaced with the older monolithic projection.

## Related

- [Decision records](README.md)
- [Performance and replication study](../results/performance.md)
- [Physical-design record](../results/physical-design.md)
- [Project status](../project-status.md)
