/*
 * tb_pe_fp4.cpp -- Verilator testbench for FP4 PE module
 *
 * Tests the FP4 processing element with fp4_mul (1-cycle) + fp32_add.
 * Inputs are FP4 E2M1 encoded. Output is FP32 accumulated dot product.
 *
 * FP4 E2M1 encoding used:
 *   0x0=0.0, 0x1=0.5, 0x2=1.0, 0x3=1.5
 *   0x4=2.0, 0x5=3.0, 0x6=4.0, 0x7=6.0
 *   0x8=-0.0, 0x9=-0.5, 0xA=-1.0, 0xB=-1.5
 *   0xC=-2.0, 0xD=-3.0, 0xE=-4.0, 0xF=-6.0
 *
 * Pipeline timing with D_HEAD=4:
 *   - 4 feed cycles (valid_in=1)
 *   - 1 cycle multiply latency (fp4_mul)
 *   - 4 products buffered
 *   - 4x2 cycles accumulation = 8 cycles
 *   - Total drain: ~10 cycles, use 20 for safety
 *
 * Debug: make pe_fp4_debug
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

#include "Vpe.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <cstdint>
#include <cstring>
#include <cmath>

static vluint64_t sim_time = 0;

// ---------------------------------------------------------------------------
// FP4 E2M1 decode -- matches gen_fp4_lut.py
// ---------------------------------------------------------------------------
static float fp4_to_float(uint8_t fp4) {
    uint8_t sign = (fp4 >> 3) & 0x1;
    uint8_t exp  = (fp4 >> 1) & 0x3;
    uint8_t mant = (fp4 >> 0) & 0x1;
    float value;
    if (exp == 0)
        value = 0.5f * mant;
    else
        value = (float)(1 << (exp - 1)) * (1.0f + 0.5f * mant);
    if (sign) value = -value;
    return value;
}

// ---------------------------------------------------------------------------
// FP32 bit-cast
// ---------------------------------------------------------------------------
static float b2f(uint32_t b) {
    float f;
    std::memcpy(&f, &b, sizeof(float));
    return f;
}

// ---------------------------------------------------------------------------
// Clock and reset
// ---------------------------------------------------------------------------
static void tick(Vpe* dut, VerilatedVcdC* vcd) {
    dut->clk = 0; dut->eval();
    if (vcd) vcd->dump(sim_time++);
    dut->clk = 1; dut->eval();
    if (vcd) vcd->dump(sim_time++);
}

static void reset(Vpe* dut, VerilatedVcdC* vcd) {
    dut->rst_n    = 0;
    dut->a_in     = 0;
    dut->b_in     = 0;
    dut->valid_in = 0;
    tick(dut, vcd); tick(dut, vcd); tick(dut, vcd);
    dut->rst_n = 1;
    tick(dut, vcd);
}

// ---------------------------------------------------------------------------
// Run one dot product test
// a_fp4 and b_fp4 are arrays of FP4 encoded values
// expected is the FP32 expected dot product
// ---------------------------------------------------------------------------
static bool run_test(Vpe* dut, VerilatedVcdC* vcd,
                     const char* name,
                     uint8_t* a_fp4, uint8_t* b_fp4,
                     int d_head, float expected,
                     float tolerance = 1e-4f)
{
    std::cout << "\n--- " << name << " ---\n";
    std::cout << "Expected: " << expected << "\n";

    // Feed d_head FP4 pairs
    for (int i = 0; i < d_head; i++) {
        dut->a_in     = a_fp4[i];
        dut->b_in     = b_fp4[i];
        dut->valid_in = 1;
        tick(dut, vcd);
        std::cout << "Feed " << (i+1) << ": a=0x" << std::hex
                  << (int)a_fp4[i] << "(" << std::dec
                  << fp4_to_float(a_fp4[i]) << ")"
                  << " b=0x" << std::hex << (int)b_fp4[i]
                  << "(" << std::dec << fp4_to_float(b_fp4[i]) << ")\n";
    }

    dut->valid_in = 0;
    dut->a_in     = 0;
    dut->b_in     = 0;

    // Drain -- wait for result_valid
    int drain = 25;
    int found = -1;
    for (int i = 0; i < drain; i++) {
        tick(dut, vcd);
        if (dut->result_valid && found < 0) {
            found = i + 1;
            std::cout << "result_valid at drain cycle " << found << "\n";
        }
    }

    float got = b2f(dut->result);
    float err = std::fabs(got - expected);
    bool  ok  = (err <= tolerance);

    std::cout << "Result:   " << got
              << " (0x" << std::hex << dut->result << std::dec << ")\n";
    std::cout << "Error:    " << err << "\n";
    std::cout << (ok ? "PASS" : "FAIL") << "\n";

    return ok;
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vpe* dut = new Vpe;
    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd, 99);
    vcd->open("pe_fp4_wave.vcd");

    std::cout << "============================================\n";
    std::cout << "FP4 PE Testbench -- Dot Product Verify\n";
    std::cout << "============================================\n";

    int pass = 0, total = 3;

    // -----------------------------------------------------------------------
    // Test 1: dot([1.0,0.0,1.0,0.0], [1.0,0.0,1.0,0.0]) = 2.0
    // FP4: 1.0=0x2, 0.0=0x0
    // -----------------------------------------------------------------------
    reset(dut, vcd);
    uint8_t a1[] = {0x2, 0x0, 0x2, 0x0};  // 1.0, 0.0, 1.0, 0.0
    uint8_t b1[] = {0x2, 0x0, 0x2, 0x0};  // 1.0, 0.0, 1.0, 0.0
    if (run_test(dut, vcd, "Test 1: dot([1,0,1,0],[1,0,1,0])",
                 a1, b1, 4, 2.0f)) pass++;

    // -----------------------------------------------------------------------
    // Test 2: dot([1.0,1.5,2.0,0.5], [2.0,1.0,0.5,1.5]) = 2+1.5+1+0.75=5.25
    // FP4: 1.0=0x2, 1.5=0x3, 2.0=0x4, 0.5=0x1
    // -----------------------------------------------------------------------
    reset(dut, vcd);
    uint8_t a2[] = {0x2, 0x3, 0x4, 0x1};  // 1.0, 1.5, 2.0, 0.5
    uint8_t b2[] = {0x4, 0x2, 0x1, 0x3};  // 2.0, 1.0, 0.5, 1.5
    if (run_test(dut, vcd, "Test 2: dot([1,1.5,2,0.5],[2,1,0.5,1.5])",
                 a2, b2, 4, 5.25f)) pass++;

    // -----------------------------------------------------------------------
    // Test 3: dot([1.0,-1.0,1.0,-1.0], [1.0,1.0,1.0,1.0]) = 0.0
    // Tests negative FP4 values
    // FP4: 1.0=0x2, -1.0=0xA
    // -----------------------------------------------------------------------
    reset(dut, vcd);
    uint8_t a3[] = {0x2, 0xA, 0x2, 0xA};  // 1.0, -1.0, 1.0, -1.0
    uint8_t b3[] = {0x2, 0x2, 0x2, 0x2};  // 1.0,  1.0, 1.0,  1.0
    if (run_test(dut, vcd, "Test 3: dot([1,-1,1,-1],[1,1,1,1]) negative FP4",
                 a3, b3, 4, 0.0f)) pass++;

    std::cout << "\n============================================\n";
    std::cout << "Results: " << pass << "/" << total << " tests passed\n";
    std::cout << "============================================\n";

    vcd->close();
    dut->final();
    delete vcd;
    delete dut;

    std::cout << "Waveform: pe_fp4_wave.vcd\n";
    return (pass == total) ? 0 : 1;
}
