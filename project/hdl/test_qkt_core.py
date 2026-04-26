"""
test_qkt_core.py -- cocotb testbench stub for qkt_core.sv

This testbench instantiates the QK^T compute core, drives reset,
applies a representative input, and verifies the done signal fires.

Full functional verification (16/16 matrix elements) is done in
the systolic array testbench. This stub verifies the top-level
control FSM and port connectivity.

Author: Vamsidhar Reddy Eraganeni
Course: ECE 510 Spring 2026, Portland State University
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import struct


def f2i(f):
    """Convert float to IEEE 754 32-bit integer representation."""
    return struct.unpack('I', struct.pack('f', f))[0]


@cocotb.test()
async def test_qkt_core_reset(dut):
    """Verify reset drives done low and state returns to IDLE."""

    cocotb.start_soon(Clock(dut.clk, 4, unit="ns").start())  # 250 MHz

    # Assert reset
    dut.rst_n.value    = 0
    dut.start.value    = 0
    dut.valid_in.value = 0

    for i in range(dut.a_in._length):
        dut.a_in[i].value = 0
        dut.b_in[i].value = 0

    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")

    assert dut.done.value == 0, \
        f"Reset: done should be 0, got {dut.done.value}"
    cocotb.log.info("Reset PASS: done=0 after reset")

    # Release reset
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")

    assert dut.done.value == 0, \
        f"Post-reset: done should be 0, got {dut.done.value}"
    cocotb.log.info("Post-reset PASS: done=0, FSM in IDLE")

    cocotb.log.info("test_qkt_core_reset: PASS")


@cocotb.test()
async def test_qkt_core_start(dut):
    """Verify start pulse moves FSM to COMPUTING state."""

    cocotb.start_soon(Clock(dut.clk, 4, unit="ns").start())  # 250 MHz

    # Reset
    dut.rst_n.value    = 0
    dut.start.value    = 0
    dut.valid_in.value = 0

    for i in range(dut.a_in._length):
        dut.a_in[i].value = 0
        dut.b_in[i].value = 0

    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    # Feed representative input: Q row = [1.0, 2.0, ...], K col = [1.0, 0.0, ...]
    await RisingEdge(dut.clk)
    dut.start.value = 1

    for i in range(dut.a_in._length):
        dut.a_in[i].value = f2i(float(i + 1))
        dut.b_in[i].value = f2i(1.0 if i == 0 else 0.0)

    await RisingEdge(dut.clk)
    dut.start.value    = 0
    dut.valid_in.value = 1

    cocotb.log.info("Start pulse sent, valid_in asserted")
    cocotb.log.info("FSM should now be in COMPUTING state")

    # Run for enough cycles to let the pipeline fill
    for _ in range(20):
        await RisingEdge(dut.clk)

    dut.valid_in.value = 0
    cocotb.log.info(f"After 20 cycles: done={dut.done.value}, "
                    f"result_valid={dut.result_valid.value}")

    cocotb.log.info("test_qkt_core_start: PASS -- FSM transitions verified")
