"""
test_mac.py -- cocotb testbench for mac_correct.v

MAC behavior: on each rising edge, if rst: out=0, else out=out+(a*b)
Inputs must be stable BEFORE the rising edge to be captured.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


@cocotb.test()
async def test_mac_basic(dut):
    """Basic MAC test: positive values, reset, negative values."""

    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Reset for 2 cycles
    dut.rst.value = 1
    dut.a.value   = 0
    dut.b.value   = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)

    # Release reset, set inputs BEFORE next edge
    dut.rst.value = 0
    dut.a.value   = 3
    dut.b.value   = 4

    # Now each rising edge accumulates a*b=12
    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")   # small delay to let output settle after edge
    assert dut.out.value.to_signed() == 12, \
        f"Cycle 1: got {dut.out.value.to_signed()}, expected 12"
    cocotb.log.info(f"Cycle 1 PASS: out={dut.out.value.to_signed()}")

    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")
    assert dut.out.value.to_signed() == 24, \
        f"Cycle 2: got {dut.out.value.to_signed()}, expected 24"
    cocotb.log.info(f"Cycle 2 PASS: out={dut.out.value.to_signed()}")

    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")
    assert dut.out.value.to_signed() == 36, \
        f"Cycle 3: got {dut.out.value.to_signed()}, expected 36"
    cocotb.log.info(f"Cycle 3 PASS: out={dut.out.value.to_signed()}")

    # Assert reset
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")
    assert dut.out.value.to_signed() == 0, \
        f"Reset: got {dut.out.value.to_signed()}, expected 0"
    cocotb.log.info(f"Reset PASS: out={dut.out.value.to_signed()}")

    # Release reset, set negative inputs
    dut.rst.value = 0
    dut.a.value   = -5
    dut.b.value   = 2

    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")
    assert dut.out.value.to_signed() == -10, \
        f"Cycle 5: got {dut.out.value.to_signed()}, expected -10"
    cocotb.log.info(f"Cycle 5 PASS: out={dut.out.value.to_signed()}")

    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")
    assert dut.out.value.to_signed() == -20, \
        f"Cycle 6: got {dut.out.value.to_signed()}, expected -20"
    cocotb.log.info(f"Cycle 6 PASS: out={dut.out.value.to_signed()}")

    cocotb.log.info("test_mac_basic: ALL PASS")


@cocotb.test()
async def test_mac_overflow(dut):
    """
    Overflow test: accumulate until accumulator exceeds 2^31-1.
    With a=127 b=127, each cycle adds 16129.
    Design wraps (two's complement) -- no saturation logic present.
    """

    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Reset
    dut.rst.value = 1
    dut.a.value   = 0
    dut.b.value   = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)

    dut.rst.value = 0
    dut.a.value   = 127
    dut.b.value   = 127

    cycles = 133149
    for _ in range(cycles):
        await RisingEdge(dut.clk)

    await Timer(1, unit="ns")
    final = dut.out.value.to_signed()
    cocotb.log.info(f"After {cycles} cycles a=127 b=127: out={final}")

    if final < 0:
        cocotb.log.info("Overflow: WRAPS (two's complement rollover, no saturation)")
    else:
        cocotb.log.info("Overflow: did not wrap in this run")

    cocotb.log.info("test_mac_overflow: complete")
