# Glossary

This glossary defines the numerical and architectural terms used throughout the
project. It is the quickest reference for readers who are new to attention or
low-precision hardware.

| Term | Meaning |
| --- | --- |
| `QK^T` | The matrix product of query vectors Q and transposed key vectors K. Each output score measures how strongly one token attends to another before softmax. |
| E2M1 | A four-bit floating-point code with one sign bit, two exponent bits, and one mantissa bit. This project uses magnitudes 0, 0.5, 1, 1.5, 2, 3, 4, and 6. |
| MX | Microscaling: several low-precision values share a scale. The active format uses the idea of block scales but uses FP32 scales, so it is not OCP MXFP4. |
| `Bs` | Scale block size along the reduction dimension. `Bs=16` gives each consecutive group of 16 Q or K values its own FP32 scale. |
| `TILE_SIZE` | Number of Q rows and K rows computed by one square hardware tile. The routed baseline is 4. |
| `D_HEAD` | Number of elements in each query or key vector, and therefore the dot-product reduction length. The main workload uses 64. |
| `T_MAX` | Largest sequence length compiled into a hardware instance. Runtime sequence length T cannot exceed it. |
| Score lane | One pipeline that converts a block-local integer dot product and applies its Q and K scales. More lanes launch more scores per cycle. |
| Quarter units | Exact integer units used by the accumulator. FP4 inputs decode in half units, so multiplying two decoded values produces an exact result in quarters. |

## Related

- [Project overview](../README.md)
- [Architecture](architecture.md)
- [Stream protocol](stream-protocol.md)
- [Attention precision results](results/precision.md)
