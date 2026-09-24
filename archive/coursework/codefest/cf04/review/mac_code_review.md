# MAC code review

## LLM versions used

| File | LLM | Model |
|---|---|---|
| mac_llm_A.v | Claude | Claude Sonnet 4.6 |
| mac_llm_B.v | ChatGPT | GPT-4o |

---

## Compilation results

Both files compiled cleanly with Verilator lint:

```
verilator --lint-only mac_llm_A.v --top-module mac   -> no warnings
verilator --lint-only mac_llm_B.v --top-module mac   -> no warnings
```

Both compiled with iverilog using `-g2012` SystemVerilog flag:

```
iverilog -g2012 -o sim_A mac_llm_A.v mac_tb.v       -> compiled
iverilog -g2012 -o sim_B mac_llm_B.v mac_tb.v       -> compiled
```

---

## Simulation results

Test sequence: a=3 b=4 for 3 cycles, assert rst, a=-5 b=2 for 2 cycles.

**mac_llm_A.v:**
```
PASS cycle 1: out = 12
PASS cycle 2: out = 24
PASS cycle 3: out = 36
PASS cycle 4: out = 0
FAIL cycle 5: out = 33554422, expected = -10
FAIL cycle 6: out = 67108844, expected = -20
```

**mac_llm_B.v:**
```
PASS cycle 1: out = 12
PASS cycle 2: out = 24
PASS cycle 3: out = 36
PASS cycle 4: out = 0
PASS cycle 5: out = -10
PASS cycle 6: out = -20
```

---

## Issue 1: Sign extension error in mac_llm_A.v (Claude)

**Offending line:**
```systemverilog
out <= out + ({{16{a[7]}}, a} * {{16{b[7]}}, b});
```

**Why it is wrong:**
Sign-extending both 8-bit inputs to 32 bits before multiplying produces a
64-bit intermediate result. SystemVerilog silently truncates this 64-bit
product to 32 bits when storing into `out`, losing the sign bits for negative
values. For a=-5, b=2 the product should be -10 but the truncated result is
33554422.

**Corrected version:**
```verilog
wire signed [15:0] product;
assign product = a * b;
always @(posedge clk) begin
    if (rst)
        out <= 32'sd0;
    else
        out <= out + {{16{product[15]}}, product};
end
```

Multiplying two 8-bit signed values produces a 16-bit result. Declaring a
16-bit product wire and sign-extending explicitly to 32 bits gives the correct
result for all signed inputs.

---

## Issue 2: Combinational multiply outside always_ff in mac_llm_B.v (ChatGPT)

**Offending lines:**
```systemverilog
logic signed [15:0] product;
assign product = a * b;
```

**Why it is wrong:**
The continuous `assign` statement creates a combinational multiply that
evaluates every time `a` or `b` changes, regardless of the clock edge. This
means the multiplier is active and consuming power continuously, not just on
clock edges. For a synthesizable design the multiply should be gated by the
clock to minimize switching activity and power consumption.

**Corrected version:**
Move the multiply inside the clocked block or use a wire with the same
continuous assign but document the power implication. The corrected mac_correct.v
keeps the wire approach for simplicity but notes this behavior.

---

## Issue 3: Non-synthesizable keywords in mac_llm_A.v

`always_ff` is a SystemVerilog construct not supported by all tools without
explicit SystemVerilog mode flags. iverilog requires `-g2012` to accept it.
The corrected file uses plain `always @(posedge clk)` which is universally
supported.

---

## mac_correct.v simulation results

```
PASS cycle 1: out = 12
PASS cycle 2: out = 24
PASS cycle 3: out = 36
PASS cycle 4: out = 0
PASS cycle 5: out = -10
PASS cycle 6: out = -20
Testbench complete.
```

6/6 tests passing.

---

## Yosys synthesis results for mac_correct.v

```
yosys -p 'read_verilog -sv mac_correct.v; synth; stat'

Number of cells: 696
  $_SDFF_PP0_   32    (32-bit accumulator register)
  $_XOR_       175
  $_AND_        48
  ...
```

Synthesizes cleanly. 32 flip-flops match the 32-bit accumulator output.
No warnings or errors from Yosys 0.33.
