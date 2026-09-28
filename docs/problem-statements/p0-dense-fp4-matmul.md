# P0: attention-specific FP4 matrix multiplication

This statement defines the active research question. Implementation status and
stage tracking live in [project status](../project-status.md).

## Research question

Which input format, scale-block granularity, and accumulator structure preserve
transformer attention while minimizing the cost of dense `Q * K^T` on Sky130?
The result must be judged on real activations by softmax KL divergence, total
variation, and top-k agreement as well as raw score error.

## Evidence required

- Bit-exact agreement between the RTL and the selected software arithmetic.
- Precision sweeps on pinned transformer Q and K activations, with provenance.
- Sustained full-command cycles and utilization across useful sequence lengths.
- Routed setup and hold timing, area, design-rule status, and valid power for one
  named configuration.
- Clear measured and projected labels for every CPU, cycle, latency, area, and
  energy comparison.

## Scope boundary

P0 returns dense FP32 attention scores. It excludes masking, softmax hardware,
the multiplication by V, sparse score semantics, and runtime format selection.
Those are separate research questions; P1 RTL and P2 remain deferred.

## Related

- [Project status and plan](../project-status.md)
- [Architecture](../architecture.md)
- [Attention precision results](../results/precision.md)
- [Physical design results](../results/physical-design.md)
