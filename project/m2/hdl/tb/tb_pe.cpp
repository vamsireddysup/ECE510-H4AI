/*
 * tb_pe.cpp -- Verilator testbench for FP32 PE module
 *
 * Tests the FP32 processing element with synthesizable fp32_mul + fp32_add.
 *
 * Pipeline timing with D_HEAD=4:
 *   - 4 feed cycles (valid_in=1)
 *   - 3 cycles multiply latency (last product arrives cycle 4+3=7)
 *   - 4 products buffered in prod_buf
 *   - 4 x 2 cycles accumulation (strobe + wait per product) = 8 cycles
 *   - Total drain after last feed: ~12 cycles, use 20 for safety
 *
 * Run with waveform:  ./obj_pe/tb_pe
 * Debug compile:      make pe_debug
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

// ---------------------------------------------------------------------------
// Bit-cast helpers: float <-> uint32_t
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
// Global simulation time for VCD
// ---------------------------------------------------------------------------
static vluint64_t sim_time = 0;

static void tick(Vpe* dut, VerilatedVcdC* vcd) {
    dut->clk = 0;
    dut->eval();
    if (vcd) vcd->dump(sim_time++);

    dut->clk = 1;
    dut->eval();
    if (vcd) vcd->dump(sim_time++);
}

static void reset(Vpe* dut, VerilatedVcdC* vcd) {
    dut->rst_n    = 0;
    dut->a_in     = 0;
    dut->b_in     = 0;
    dut->valid_in = 0;
    tick(dut, vcd);
    tick(dut, vcd);
    tick(dut, vcd);
    dut->rst_n = 1;
    tick(dut, vcd);
}

// ---------------------------------------------------------------------------
// Run one dot product test
// ---------------------------------------------------------------------------
static bool run_test(Vpe* dut, VerilatedVcdC* vcd,
                     const char* name,
                     float* a_vec, float* b_vec,
                     int d_head, float expected,
                     float tolerance = 1e-3f)
{
    std::cout << "\n--- " << name << " ---\n";
    std::cout << "Expected: " << expected << "\n\n";

    // Feed d_head pairs
    for (int i = 0; i < d_head; i++) {
        dut->a_in     = f2b(a_vec[i]);
        dut->b_in     = f2b(b_vec[i]);
        dut->valid_in = 1;
        tick(dut, vcd);
        std::cout << "Feed cycle " << (i+1)
                  << ": a=" << a_vec[i]
                  << " b=" << b_vec[i] << "\n";
    }

    // Deassert valid
    dut->valid_in = 0;
    dut->a_in     = 0;
    dut->b_in     = 0;

    // Drain -- wait for result_valid
    int drain     = 25;
    int found     = -1;
    std::cout << "Draining up to " << drain << " cycles...\n";

    for (int i = 0; i < drain; i++) {
        tick(dut, vcd);
        if (dut->result_valid && found < 0) {
            found = i + 1;
            std::cout << "  result_valid asserted at drain cycle " << found << "\n";
        }
    }

    float got = b2f(dut->result);
    float err = std::fabs(got - expected);
    bool  ok  = (err <= tolerance);

    std::cout << "Result:   " << got << " (0x" << std::hex << dut->result
              << std::dec << ")\n";
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

    // Open VCD waveform
    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd, 99);
    vcd->open("pe_wave.vcd");

    std::cout << "========================================\n";
    std::cout << "FP32 PE Testbench -- Dot Product Verify\n";
    std::cout << "========================================\n";

    int pass  = 0;
    int total = 2;

    // Test 1: dot([1,2,3,4], [1,0,1,0]) = 4.0
    reset(dut, vcd);
    std::cout << "Reset complete.\n";
    float a1[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float b1[] = {1.0f, 0.0f, 1.0f, 0.0f};
    if (run_test(dut, vcd, "Test 1: dot([1,2,3,4],[1,0,1,0])",
                 a1, b1, 4, 4.0f)) pass++;

    // Test 2: dot([5,6,7,8], [1,0,1,0]) = 12.0
    reset(dut, vcd);
    float a2[] = {5.0f, 6.0f, 7.0f, 8.0f};
    float b2[] = {1.0f, 0.0f, 1.0f, 0.0f};
    if (run_test(dut, vcd, "Test 2: dot([5,6,7,8],[1,0,1,0])",
                 a2, b2, 4, 12.0f)) pass++;

    std::cout << "\n========================================\n";
    std::cout << "Results: " << pass << "/" << total << " tests passed\n";
    std::cout << "========================================\n";

    vcd->close();
    dut->final();
    delete vcd;
    delete dut;

    std::cout << "Waveform saved to pe_wave.vcd\n";
    std::cout << "View with: gtkwave obj_pe/pe_wave.vcd\n";

    return (pass == total) ? 0 : 1;
}
