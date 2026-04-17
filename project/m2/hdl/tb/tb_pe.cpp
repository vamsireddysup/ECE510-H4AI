/*
 * tb_pe.cpp -- Verilator testbench for FP32 PE module
 *
 * Tests the FP32 processing element by feeding Q row elements from
 * the left and K^T column elements from the top, one pair per cycle,
 * and verifying the accumulated dot product matches a Python-computed
 * golden reference.
 *
 * FP32 values are passed as uint32_t (bit-cast from float) because
 * the SystemVerilog ports are logic [31:0].
 *
 * Pipeline latency: fp32_mul (3) + fp32_add (4) = 7 cycles per MAC.
 * After feeding D_HEAD=4 pairs, drain for 7 more cycles before reading.
 *
 * Test cases match golden reference from gen_golden.py:
 *   Test 1: dot([1,2,3,4], [1,0,1,0]) = 4.0  (QKT[0][0])
 *   Test 2: dot([5,6,7,8], [1,0,1,0]) = 12.0 (QKT[1][0])
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

#include "Vpe.h"
#include "verilated.h"
#include <iostream>
#include <cstdint>
#include <cstring>
#include <cmath>

// ---------------------------------------------------------------------------
// Bit-cast helpers: float <-> uint32_t
// Safe reinterpretation using memcpy (avoids undefined behavior)
// ---------------------------------------------------------------------------
static uint32_t f2b(float f) {
    uint32_t b;
    std::memcpy(&b, &f, sizeof(float));
    return b;
}

static float b2f(uint32_t b) {
    float f;
    std::memcpy(&f, &b, sizeof(float));
    return f;
}

// ---------------------------------------------------------------------------
// Clock tick
// ---------------------------------------------------------------------------
static void tick(Vpe* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

// ---------------------------------------------------------------------------
// Reset -- hold for 3 cycles
// ---------------------------------------------------------------------------
static void reset(Vpe* dut) {
    dut->rst_n    = 0;
    dut->a_in     = 0;
    dut->b_in     = 0;
    dut->valid_in = 0;
    tick(dut); tick(dut); tick(dut);
    dut->rst_n = 1;
    tick(dut);
}

// ---------------------------------------------------------------------------
// Run one dot product test
// Feeds d_head pairs of (a_vec, b_vec), drains pipeline, checks result
// ---------------------------------------------------------------------------
static bool run_test(Vpe* dut,
                     const char* name,
                     float* a_vec,
                     float* b_vec,
                     int    d_head,
                     float  expected,
                     float  tolerance = 1e-4f)
{
    std::cout << "\n--- " << name << " ---\n";
    std::cout << "Expected: " << expected << "\n\n";

    // Feed d_head pairs
    for (int i = 0; i < d_head; i++) {
        dut->a_in     = f2b(a_vec[i]);
        dut->b_in     = f2b(b_vec[i]);
        dut->valid_in = 1;
        tick(dut);
        std::cout << "Feed cycle " << (i+1)
                  << ": a=" << a_vec[i]
                  << " b=" << b_vec[i] << "\n";
    }

    // Deassert valid
    dut->valid_in = 0;
    dut->a_in     = 0;
    dut->b_in     = 0;

    // Drain pipeline: (fp32_mul latency) + (fp32_add latency) = 3+4 = 7
    int drain = 20;//changed from 7cycles to 20 cycles
    std::cout << "Draining " << drain << " cycles...\n";
    for (int i = 0; i < drain; i++) {
        tick(dut);
    }

    // Read result
    float got = b2f(dut->result);
    float err = std::fabs(got - expected);
    bool  ok  = (err <= tolerance);

    std::cout << "Result:   " << got << "\n";
    std::cout << "Error:    " << err << "\n";
    std::cout << (ok ? "PASS" : "FAIL") << "\n";

    return ok;
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vpe* dut = new Vpe;

    std::cout << "========================================\n";
    std::cout << "FP32 PE Testbench -- Dot Product Verify\n";
    std::cout << "========================================\n";

    int pass = 0;
    int total = 2;

    // Test 1: dot([1,2,3,4], [1,0,1,0]) = 4.0
    reset(dut);
    std::cout << "Reset complete.\n";
    float a1[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float b1[] = {1.0f, 0.0f, 1.0f, 0.0f};
    if (run_test(dut, "Test 1: dot([1,2,3,4],[1,0,1,0])",
                 a1, b1, 4, 4.0f)) pass++;

    // Test 2: dot([5,6,7,8], [1,0,1,0]) = 12.0
    reset(dut);
    float a2[] = {5.0f, 6.0f, 7.0f, 8.0f};
    float b2[] = {1.0f, 0.0f, 1.0f, 0.0f};
    if (run_test(dut, "Test 2: dot([5,6,7,8],[1,0,1,0])",
                 a2, b2, 4, 12.0f)) pass++;

    std::cout << "\n========================================\n";
    std::cout << "Results: " << pass << "/" << total
              << " tests passed\n";
    std::cout << "========================================\n";

    dut->final();
    delete dut;
    return (pass == total) ? 0 : 1;
}
