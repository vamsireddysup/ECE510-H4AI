# CF08 -- CMAN: AER Bandwidth Analysis for Event-Driven Neuromorphic Communication

## Given parameters

- Number of neurons: N = 1024
- Mean firing rate per neuron: f = 50 Hz
- AER packet: 10-bit neuron address + 6-bit timestamp + 4-bit framing/parity = 20 bits total

---

## Task 1: Mean aggregate spike rate

R = N × f

R = 1024 × 50 = **51,200 spikes/second (51.2 kspikes/s)**

---

## Task 2: Mean required AER bandwidth

B = R × 20

B = 51,200 × 20 = 1,024,000 bits/s

**B = 1.024 Mbit/s**

---

## Task 3: Interface comparison

| Interface | Maximum throughput | Can sustain mean rate (1.024 Mbit/s)? |
|---|---|---|
| I²C | ≤ 3.4 Mbit/s | Yes |
| SPI | ≤ 50 Mbit/s | Yes |
| AXI4-Lite | ≈ 100 Mbit/s | Yes |

All three interfaces can sustain the mean AER traffic rate of 1.024 Mbit/s.

**Lowest-complexity interface that suffices: I²C**

I²C at 3.4 Mbit/s exceeds the 1.024 Mbit/s mean requirement with the simplest protocol (two-wire, no chip select, standard controller support).

---

## Task 4: Burst analysis

**Burst condition:** 25% of 1024 neurons fire within a 1 ms window.

Neurons firing: 0.25 × 1024 = 256 neurons

Total bits in burst: 256 × 20 = 5,120 bits

Peak instantaneous bandwidth:

B_peak = 5,120 bits / 0.001 s = **5.12 Mbit/s**

**Burst-to-mean ratio:** 5.12 / 1.024 = **5:1**

**Buffering decision:**

The chosen interface (I²C, 3.4 Mbit/s) cannot absorb the burst (5.12 Mbit/s > 3.4 Mbit/s). Buffering is required.

Excess data during burst: (5.12 - 3.4) × 10⁶ × 0.001 s = 1,720 bits = **86 packets of buffer depth required**.

SPI and AXI4-Lite can absorb the burst directly without buffering since both exceed 5.12 Mbit/s.

---

## Task 5: Frame-based comparison

**Conventional frame-based readout:**

- 1024 neurons sampled every 1 ms, 1 bit per neuron
- Bits per frame: 1,024 bits
- Frames per second: 1,000
- B_frame = 1,024 × 1,000 = 1,024,000 bits/s = **1.024 Mbit/s**

**AER-to-frame bandwidth ratio at f = 50 Hz:**

B_AER / B_frame = 1.024 / 1.024 = **1:1**

**Crossover firing rate:**

Set B_AER = B_frame:

N × f_crossover × 20 = N × 1000

20 × f_crossover = 1000

**f_crossover = 50 Hz**

**Implication:** AER is the right choice when mean firing rates are below 50 Hz because at sparser activity the event-driven bandwidth is lower than the fixed frame-based cost; above 50 Hz, frame-based readout becomes more bandwidth-efficient.
