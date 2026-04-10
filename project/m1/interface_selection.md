# Interface selection

## Host platform

I am assuming an FPGA SoC host (Xilinx Zynq-class) with an ARM processor
running the software stack. The chiplet connects as a co-processor.

## Interface chosen

AXI4-Lite for control + AXI4-Stream for data.

AXI4-Lite handles the register map -- I write matrix dimensions and a start
signal, and read a done flag when the chiplet finishes. Low bandwidth, simple
transactions, exactly what this needs.

AXI4-Stream carries Q and K into the chiplet and the score matrix out. It is
a natural fit because data just streams in one end and results come out the
other -- no random access, no handshaking overhead per word. This matches
how a systolic array consumes data.

I ruled out SPI and I2C because they are too slow. PCIe is overkill for this
scale and adds implementation complexity I do not need. UCIe is for multi-die
packaging which is not my target.

## Bandwidth calculation

At 32 GFLOP/s target, one QK^T forward pass at T=512 takes:

```
268,435,456 FLOPs / 32,000,000,000 = 8.39 ms
```

Data moved per pass:
```
Q in  : 1 x 8 x 512 x 64 x 4 = 1 MB
K in  : 1 x 8 x 512 x 64 x 4 = 1 MB
Score out : 1 x 8 x 512 x 512 x 4 = 8 MB
Total : 10 MB
```

Required bandwidth = 10 MB / 8.39 ms = **1.19 GB/s**

AXI4-Stream at 64-bit / 250 MHz = **2 GB/s**

The interface delivers 2 GB/s against a requirement of 1.19 GB/s.
That is 1.68x headroom -- the chiplet is not interface-bound.

## When it would become interface-bound

If I later scale the chiplet beyond ~54 GFLOP/s without widening the bus,
the interface becomes the bottleneck. At that point I would need either a
wider AXI4-Stream bus or a higher clock frequency.
