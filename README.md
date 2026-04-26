# ECE 510 — Hardware for Artificial Intelligence and Machine Learning

**Portland State University | Spring 2026 | Prof. Christof Teuscher**

Myself: Vamsidhar Reddy Eraganeni

**Tentative project topic:** QK^T matrix multiplication accelerator for transformer self-attention
This repository contains coursework for ECE 510: Hardware for AI/ML at Portland State University. Content will be updated progressively as the course advances through each milestone.

## References

- Hyunwoong Ko, "Transformer: PyTorch Implementation of Attention Is All You Need," 
  GitHub, 2019. https://github.com/hyunwoongko/transformer
  (Used as reference implementation for understanding transformer attention structure 
  and profiling QK^T kernel behavior)

## Project compute core (M2)

### Module: qkt_core.sv

Top-level wrapper for the QK^T matrix multiply accelerator chiplet.
Instantiates an 8x8 systolic array of FP32 processing elements.
Exposes a simple start/done control interface and FP32 data ports
for connection to the AXI4-Stream data interface.

**Interface:** AXI4-Lite for control (start/done registers) +
AXI4-Stream for data (Q and K matrices in, score matrix out).

**Precision:** FP32 (IEEE 754 32-bit). No quantization -- output
matches PyTorch CPU baseline bit-for-bit for verification.

**Interface bandwidth justification:**
From M1 roofline analysis, QK^T at T=512 has arithmetic intensity
of 25.60 FLOP/byte and achieves 11.36 GFLOP/s on the CPU baseline.
At the chiplet target of 32 GFLOP/s, one forward pass takes 8.39 ms
and requires transferring 10 MB (Q: 1 MB, K: 1 MB, score: 8 MB).
Required bandwidth = 10 MB / 8.39 ms = 1.19 GB/s. AXI4-Stream at
64-bit / 250 MHz delivers 2 GB/s, providing 1.68x headroom. The
interface is not the bottleneck -- the chiplet compute ceiling
(32 GFLOP/s) is always the performance limit.
