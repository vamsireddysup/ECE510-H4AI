/*
 * tb_systolic_array.cpp -- Verilator testbench for FP32 4x4 systolic array
 *
 * Computes QK^T for 4x4 matrices using the systolic array.
 * Compares output against Python golden reference.
 *
 * Q matrix [4x4]:
 *   Row 0: [1, 2, 3, 4]
 *   Row 1: [5, 6, 7, 8]
 *   Row 2: [1, 0, 1, 0]
 *   Row 3: [2, 3, 2, 3]
 *
 * K^T matrix [4x4] (K transposed -- K rows become K^T columns):
 *   Col 0 (K row 0): [1, 0, 1, 0]
 *   Col 1 (K row 1): [0, 1, 1, 0]
 *   Col 2 (K row 2): [1, 0, 0, 1]
 *   Col 3 (K row 3): [0, 1, 0, 1]
 *
 * Expected QK^T [4x4]:
 *   [ 4,  6,  3,  7]
 *   [12, 14, 11, 15]
 *   [ 2,  0,  1,  1]
 *   [ 4,  6,  5,  5]
 *
 * Systolic array feeding:
 *   Each cycle: feed one element from each Q row (left edge)
 *               and one element from each K^T col (top edge)
 *   Staggering handled inside systolic_array.sv
 *
 * Debug: compile with -DDEBUG_PE for internal PE traces
 *   make array_debug
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

#include "Vsystolic_array.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <cstdint>
#include <cstring>
#include <cmath>

#define SIZE 4

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
// Global simulation time
// ---------------------------------------------------------------------------
static vluint64_t sim_time = 0;

static void tick(Vsystolic_array* dut, VerilatedVcdC* vcd) {
    dut->clk = 0;
    dut->eval();
    if (vcd) vcd->dump(sim_time++);

    dut->clk = 1;
    dut->eval();
    if (vcd) vcd->dump(sim_time++);
}

static void reset(Vsystolic_array* dut, VerilatedVcdC* vcd) {
    dut->rst_n    = 0;
    dut->valid_in = 0;
    for (int i = 0; i < SIZE; i++) {
        dut->a_in[i] = 0;
        dut->b_in[i] = 0;
    }
    // Hold reset for 4 cycles
    tick(dut, vcd);
    tick(dut, vcd);
    tick(dut, vcd);
    tick(dut, vcd);
    dut->rst_n = 1;
    tick(dut, vcd);
    std::cout << "Reset complete.\n";
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vsystolic_array* dut = new Vsystolic_array;

    // Open VCD waveform
    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd, 99);
    vcd->open("systolic_wave.vcd");

    std::cout << "============================================\n";
    std::cout << "Systolic Array Testbench -- 4x4 QK^T verify\n";
    std::cout << "============================================\n";

    reset(dut, vcd);

    // -----------------------------------------------------------------------
    // Q matrix -- rows fed to left edge
    // Each cycle: a_in[i] = Q[i][d] for d = 0..D_HEAD-1
    // -----------------------------------------------------------------------
    float Q[SIZE][SIZE] = {
        {1.0f, 2.0f, 3.0f, 4.0f},
        {5.0f, 6.0f, 7.0f, 8.0f},
        {1.0f, 0.0f, 1.0f, 0.0f},
        {2.0f, 3.0f, 2.0f, 3.0f}
    };

    // -----------------------------------------------------------------------
    // K^T matrix -- columns fed to top edge
    // K^T col j = K row j
    // Each cycle: b_in[j] = K^T[d][j] = K[j][d]
    // -----------------------------------------------------------------------
    float K[SIZE][SIZE] = {
        {1.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 1.0f},
        {1.0f, 1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 1.0f}
    };

    // -----------------------------------------------------------------------
    // Expected QK^T output
    // -----------------------------------------------------------------------
    float expected[SIZE][SIZE] = {
        { 4.0f,  6.0f,  3.0f,  7.0f},
        {12.0f, 14.0f, 11.0f, 15.0f},
        { 2.0f,  0.0f,  1.0f,  1.0f},
        { 4.0f,  6.0f,  5.0f,  5.0f}
    };

    // -----------------------------------------------------------------------
    // Feed D_HEAD=4 cycles of input data
    // Cycle d: a_in[i] = Q[i][d], b_in[j] = K[j][d]
    // Staggering is handled inside systolic_array.sv
    // -----------------------------------------------------------------------
    int D_HEAD = SIZE;  // for 4x4 test, D_HEAD = 4

    std::cout << "\nFeeding " << D_HEAD << " cycles of input data...\n";

    for (int d = 0; d < D_HEAD; d++) {
        for (int i = 0; i < SIZE; i++)
            dut->a_in[i] = f2b(Q[i][d]);
        for (int j = 0; j < SIZE; j++)
            dut->b_in[j] = f2b(K[j][d]);
        dut->valid_in = 1;
        tick(dut, vcd);

        std::cout << "  Feed cycle " << (d+1) << ": ";
        std::cout << "a=[";
        for (int i = 0; i < SIZE; i++)
            std::cout << Q[i][d] << (i<SIZE-1?",":"");
        std::cout << "] b=[";
        for (int j = 0; j < SIZE; j++)
            std::cout << K[j][d] << (j<SIZE-1?",":"");
        std::cout << "]\n";
    }

    // Deassert valid
    dut->valid_in = 0;
    for (int i = 0; i < SIZE; i++) {
        dut->a_in[i] = 0;
        dut->b_in[i] = 0;
    }

    // -----------------------------------------------------------------------
    // Drain -- wait for result_valid
    // PE[3][3] is the last to finish (most stagger delay + full pipeline)
    // Drain budget:
    //   Stagger delay for PE[3][3]: 3+3 = 6 cycles
    //   fp32_mul latency: 3 cycles
    //   Product collection: D_HEAD = 4 cycles
    //   Accumulation: D_HEAD x 2 = 8 cycles
    //   Total: 6+3+4+8 = 21 cycles, use 60 for safety
    // -----------------------------------------------------------------------
    int max_drain = 60;
    int result_cycle = -1;

    std::cout << "\nDraining up to " << max_drain << " cycles...\n";

    for (int i = 0; i < max_drain; i++) {
        tick(dut, vcd);
        if (dut->result_valid && result_cycle < 0) {
            result_cycle = i + 1;
            std::cout << "  result_valid asserted at drain cycle "
                      << result_cycle << "\n";
        }
    }

    if (result_cycle < 0) {
        std::cout << "ERROR: result_valid never asserted within "
                  << max_drain << " drain cycles\n";
        vcd->close();
        dut->final();
        delete vcd;
        delete dut;
        return 1;
    }

    // -----------------------------------------------------------------------
    // Read and verify output matrix
    // -----------------------------------------------------------------------
    std::cout << "\n--- Output matrix ---\n";

    int pass  = 0;
    int total = SIZE * SIZE;
    float tolerance = 1e-3f;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            float got = b2f(dut->result[i][j]);
            float exp = expected[i][j];
            float err = std::fabs(got - exp);
            bool  ok  = (err <= tolerance);

            std::cout << "  result[" << i << "][" << j << "] = "
                      << got << " (expected " << exp << ") "
                      << (ok ? "PASS" : "FAIL");

            if (!ok)
                std::cout << " [err=" << err
                          << " got=0x" << std::hex << dut->result[i][j]
                          << std::dec << "]";

            std::cout << "\n";
            if (ok) pass++;
        }
    }

    std::cout << "\n============================================\n";
    std::cout << "Results: " << pass << "/" << total
              << " elements correct\n";

    if (pass == total)
        std::cout << "ALL PASS -- QK^T output matches golden reference\n";
    else
        std::cout << "FAIL -- " << (total-pass)
                  << " elements incorrect\n";

    std::cout << "============================================\n";

    vcd->close();
    dut->final();
    delete vcd;
    delete dut;

    std::cout << "Waveform saved to systolic_wave.vcd\n";
    std::cout << "View with: gtkwave systolic_wave.vcd\n";

    return (pass == total) ? 0 : 1;
}
