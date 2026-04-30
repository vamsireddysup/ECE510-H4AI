/*
 * tb_systolic_array_fp4.cpp -- Verilator testbench for FP4 systolic array
 *
 * Tests a 4x4 FP4 systolic array computing QK^T against Python golden ref.
 * All input values are chosen from the FP4 E2M1 representable set:
 *   {0.0, 0.5, 1.0, 1.5, 2.0, 3.0, 4.0, 6.0} and negatives
 *
 * Q matrix [4x4] -- FP4 representable values:
 *   Row 0: [1.0, 0.5, 1.5, 0.0]
 *   Row 1: [2.0, 1.0, 0.5, 1.0]
 *   Row 2: [1.0, 0.0, 1.0, 0.0]
 *   Row 3: [0.5, 1.5, 0.5, 1.5]
 *
 * K matrix [4x4] -- FP4 representable values:
 *   Row 0: [1.0, 0.0, 1.0, 0.0]
 *   Row 1: [0.0, 1.0, 0.0, 1.0]
 *   Row 2: [1.0, 1.0, 0.0, 0.0]
 *   Row 3: [0.0, 0.0, 1.0, 1.0]
 *
 * Expected QK^T computed in Python with FP4 exact arithmetic:
 *   C[i][j] = sum_k Q[i][k] * K[k][j]
 *
 * Systolic array feeding (weight-stationary style with stagger):
 *   Cycle d: a_in[i] = Q_fp4[i][d], b_in[j] = K_fp4[j][d]
 *   Staggering handled inside systolic_array.sv
 *
 * Debug: make array_debug
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

static vluint64_t sim_time = 0;

// ---------------------------------------------------------------------------
// FP4 E2M1 encode: float -> 4-bit FP4
// Only works for values in {0,0.5,1.0,1.5,2.0,3.0,4.0,6.0} and negatives
// ---------------------------------------------------------------------------
static uint8_t float_to_fp4(float f) {
    if (f == 0.0f)  return 0x0;
    if (f == 0.5f)  return 0x1;
    if (f == 1.0f)  return 0x2;
    if (f == 1.5f)  return 0x3;
    if (f == 2.0f)  return 0x4;
    if (f == 3.0f)  return 0x5;
    if (f == 4.0f)  return 0x6;
    if (f == 6.0f)  return 0x7;
    if (f == -0.5f) return 0x9;
    if (f == -1.0f) return 0xA;
    if (f == -1.5f) return 0xB;
    if (f == -2.0f) return 0xC;
    if (f == -3.0f) return 0xD;
    if (f == -4.0f) return 0xE;
    if (f == -6.0f) return 0xF;
    return 0x0; // default to 0
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
static void tick(Vsystolic_array* dut, VerilatedVcdC* vcd) {
    dut->clk = 0; dut->eval();
    if (vcd) vcd->dump(sim_time++);
    dut->clk = 1; dut->eval();
    if (vcd) vcd->dump(sim_time++);
}

static void reset(Vsystolic_array* dut, VerilatedVcdC* vcd) {
    dut->rst_n    = 0;
    dut->valid_in = 0;
    for (int i = 0; i < SIZE; i++) {
        dut->a_in[i] = 0;
        dut->b_in[i] = 0;
    }
    tick(dut, vcd); tick(dut, vcd);
    tick(dut, vcd); tick(dut, vcd);
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
    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd, 99);
    vcd->open("systolic_fp4_wave.vcd");

    std::cout << "============================================\n";
    std::cout << "FP4 Systolic Array -- 4x4 QK^T verify\n";
    std::cout << "============================================\n";

    reset(dut, vcd);

    // -----------------------------------------------------------------------
    // Q matrix [4x4] -- FP4 representable values
    // -----------------------------------------------------------------------
    float Q[SIZE][SIZE] = {
        {1.0f, 0.5f, 1.5f, 0.0f},
        {2.0f, 1.0f, 0.5f, 1.0f},
        {1.0f, 0.0f, 1.0f, 0.0f},
        {0.5f, 1.5f, 0.5f, 1.5f}
    };

    // -----------------------------------------------------------------------
    // K matrix [4x4] -- FP4 representable values
    // K^T col j = K row j
    // -----------------------------------------------------------------------
    float K[SIZE][SIZE] = {
        {1.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 1.0f},
        {1.0f, 1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 1.0f}
    };

    // -----------------------------------------------------------------------
    // Expected QK^T -- computed analytically
    // C[i][j] = sum_k Q[i][k] * K[k][j]
    // -----------------------------------------------------------------------
    float expected[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            expected[i][j] = 0.0f;
            for (int k = 0; k < SIZE; k++)
    expected[i][j] += Q[i][k] * K[j][k];  // K[j][k] = K^T[k][j]
        }

    std::cout << "\nExpected QK^T:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << "  [";
        for (int j = 0; j < SIZE; j++)
            std::cout << expected[i][j] << (j<SIZE-1?", ":"");
        std::cout << "]\n";
    }

    // -----------------------------------------------------------------------
    // Feed D_HEAD=4 cycles of FP4 encoded input
    // Cycle d: a_in[i] = Q_fp4[i][d], b_in[j] = K_fp4[j][d]
    // -----------------------------------------------------------------------
    int D_HEAD = SIZE;
    std::cout << "\nFeeding " << D_HEAD << " cycles of FP4 input...\n";

    for (int d = 0; d < D_HEAD; d++) {
        for (int i = 0; i < SIZE; i++)
            dut->a_in[i] = float_to_fp4(Q[i][d]);
        for (int j = 0; j < SIZE; j++)
            dut->b_in[j] = float_to_fp4(K[j][d]);
        dut->valid_in = 1;
        tick(dut, vcd);

        std::cout << "  Cycle " << (d+1) << ": a=[";
        for (int i = 0; i < SIZE; i++)
            std::cout << Q[i][d] << (i<SIZE-1?",":"");
        std::cout << "] b=[";
        for (int j = 0; j < SIZE; j++)
            std::cout << K[j][d] << (j<SIZE-1?",":"");
        std::cout << "]\n";
    }

    dut->valid_in = 0;
    for (int i = 0; i < SIZE; i++) {
        dut->a_in[i] = 0;
        dut->b_in[i] = 0;
    }

    // -----------------------------------------------------------------------
    // Drain -- wait for result_valid
    // FP4 PE latency: 1 (mul) + D_HEAD*2 (acc) cycles
    // Stagger: SIZE-1 extra cycles for last PE
    // Budget: SIZE + 1 + D_HEAD*2 + SIZE = 4+1+8+4 = 17, use 40
    // -----------------------------------------------------------------------
    int max_drain = 40;
    int result_cycle = -1;

    std::cout << "\nDraining up to " << max_drain << " cycles...\n";
    for (int i = 0; i < max_drain; i++) {
        tick(dut, vcd);
        if (dut->result_valid && result_cycle < 0) {
            result_cycle = i + 1;
            std::cout << "  result_valid at drain cycle " << result_cycle << "\n";
        }
    }

    if (result_cycle < 0) {
        std::cout << "ERROR: result_valid never asserted\n";
        vcd->close(); dut->final();
        delete vcd; delete dut;
        return 1;
    }

    // -----------------------------------------------------------------------
    // Verify output matrix
    // -----------------------------------------------------------------------
    std::cout << "\n--- Output matrix ---\n";
    int pass = 0, total = SIZE * SIZE;
    float tolerance = 1e-4f;

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
                std::cout << " [err=" << err << "]";
            std::cout << "\n";
            if (ok) pass++;
        }
    }

    std::cout << "\n============================================\n";
    std::cout << "Results: " << pass << "/" << total << " elements correct\n";
    if (pass == total)
        std::cout << "ALL PASS -- FP4 QK^T matches golden reference\n";
    else
        std::cout << "FAIL -- " << (total-pass) << " elements incorrect\n";
    std::cout << "============================================\n";
    std::cout << "Waveform: systolic_fp4_wave.vcd\n";

    vcd->close(); dut->final();
    delete vcd; delete dut;
    return (pass == total) ? 0 : 1;
}
