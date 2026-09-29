# 0009: use exact E2M1 shift-add products

Accepted, September 2026.

## Decision

Replace the generic signed multiply in each FP4 product lane with exact E2M1
shift/add logic. Keep the signed
half-unit product and exact integer block accumulator defined by ADR 0001.

Do not restore the archived FP32 product ROM to the active datapath.

## Evidence

E2M1 half-unit magnitudes are `0, 1, 2, 3, 4, 6, 8, 12`. Every nonzero value
is `1 * 2^e` or `3 * 2^e`, so a product needs only an exponent shift and a
coefficient of 1, 3, or 9. Yosys SAT proves the probe's structured result equals
the current decode-and-multiply result for all 256 FP4 input pairs.

The following are **measured mapped, wire-free results** from revision
`4b2caf5`, Yosys 0.44 (`80ba43d26`), and the Sky130 HD typical library from PDK
revision `0fe599b2afb6708d281543108caf8310912f54af`:

| Product structure | Output contract | Cells | Mapped area |
| --- | --- | ---: | ---: |
| Current decode and generic multiply | Signed half-unit integer | 127 | 872.09 um2 |
| **Exact E2M1 shift/add** | Signed half-unit integer | **59** | **381.62 um2** |
| Archived 256-entry product ROM | FP32 product | 40 | 228.97 um2 |

Shift/add reduces the like-for-like product area by 56.24%, or 2.29 times. A
4x4 engine has 16 product lanes, so applying the standalone delta to all lanes
would save 7,848 um2 before routing. That is a **projection**, not a full-top
area result. The M2 route decides its physical value.

The ROM appears smallest only because its output contract is different. It
emits one FP32 value per product. Using it would require FP32 reduction or a
new FP32-to-quarter-unit conversion on every lane, neither of which is included
in the 228.97 um2 figure. FP32 reduction would undo the exact block accumulator
that removed serial additions and product buffering in ADR 0001.

## Consequences

The numerical contract does not change. Product values remain exact signed
half units, block accumulators remain exact quarter units, and score conversion
still happens once per block. Existing bit-exact integration references remain
valid.

The active engine now uses the shift/add expression. All small and T=64/128/512
integration suites retain identical scores, cycles, and counters, and the T=512
RTL precision run remains bit-exact with the software model. A separate
complete-top route for this small substitution would not resolve the current
accumulator-net congestion blocker, so its physical effect is measured with M2.

The probe establishes mapped area only. It does not establish routed timing,
dynamic power, or energy. M2 must report those properties on the integrated
top.

## Alternatives considered

**Keep the generic multiply.** It is correct and concise, but maps to 2.29 times
the area of the exact structured expression under the same flow.

**Use the archived FP32 product ROM.** Its isolated logic is smallest. Its FP32
output is incompatible with the selected exact integer reduction, so its area
is not a full-path alternative.

**Use a 256-entry integer product table.** This would preserve the accumulator
contract, but it encodes the same 64 symmetric magnitude combinations that the
shift/add form expresses directly. The structured form is formally tied to the
E2M1 number system and is easier to extend into P1's format-selectable datapath.

## Related

- [Decision records](README.md)
- [ADR 0001: exact integer accumulation](0001-exact-integer-accumulation.md)
- [Performance and design-space results](../results/performance.md)
- [P1 problem statement](../problem-statements/p1-format-agile-sparsity.md)
