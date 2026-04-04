# Transformer self-attention algorithm and project overview

## What the diagram shows

The diagram traces the data flow of the scaled dot-product attention mechanism, which is the core computation inside every transformer model (GPT, BERT, and similar architectures).

The input sequence X is first projected into three separate matrices using learned weight matrices:

- Q (Query) -- represents what each token is looking for
- K (Key) -- represents what each token offers to others
- V (Value) -- represents the actual content each token carries

The Q and K matrices are then multiplied together (QK^T). This matrix multiplication produces a score matrix of shape N x N, where N is the sequence length. Each entry in this matrix is a raw similarity score between two tokens in the sequence. This operation is the computational bottleneck -- its cost scales as O(N^2 x d), where d is the head dimension. For N=512 and d=64, this is approximately 33.5 million multiply-accumulate operations per attention head per layer.

The score matrix is then scaled by 1/sqrt(d) to prevent the dot products from growing too large in magnitude, which would push the softmax into a saturated region with near-zero gradients. The softmax is then applied row-wise, converting raw scores into a probability distribution -- these are the attention weights, representing how much each token should attend to every other token. Finally, the attention weights are multiplied by V to produce the output, which is a weighted sum of value vectors.

## Why QK^T is the accelerator target

The QK^T matrix multiplication dominates inference latency for two reasons. First, its cost grows quadratically with sequence length, unlike the linear V multiplication. Second, it is compute-bound: at N=512 and d=64 with FP32 arithmetic, the arithmetic intensity exceeds 128 FLOP/byte, which places it well above the ridge point of the baseline CPU (Intel i5-1145G7, ridge point ~8.3 FLOP/byte). This means the bottleneck is compute parallelism, not memory bandwidth -- exactly the regime where a custom hardware accelerator with a dedicated systolic array of multipliers provides measurable speedup.

## How the project maps to this diagram

The project accelerates the highlighted QK^T step in hardware. The remaining steps (scaling, softmax, multiply by V) continue to run in software on the host CPU. The chiplet receives Q and K matrices from the host via AXI4-Stream, performs the matrix multiplication in a dedicated compute engine, and returns the result matrix to the host via the same interface. Control signals (matrix dimensions, start/done handshake) are passed through an AXI4-Lite register interface.

The design is described in SystemVerilog, verified in simulation using Verilator and cocotb, and synthesized using OpenLane 2. Performance is measured by comparing end-to-end QK^T execution time against the software baseline established in Milestone 1.

## Project milestones at a glance

- M1 (Apr 12): Software baseline profiling, roofline analysis, arithmetic intensity calculation, interface selection and justification, block diagram.
- M2 (May 3): HDL implementation of the compute core and AXI4 interface modules, functional simulation testbenches.
- M3 (May 24): OpenLane 2 synthesis attempt, timing and area reports, end-to-end co-simulation with data flowing through the full pipeline.
- M4 (Jun 7): Complete package -- synthesis results, benchmark comparison against software baseline, roofline plot with final design placed on it, design justification report.
