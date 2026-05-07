/*
 * tb_systolic_array_fp4.cpp -- FP4 systolic array testbench with microscaling
 *
 * Tests a 4x4 FP4 systolic array computing QK^T using values from the
 * Python golden reference generator (gen_golden.py).
 *
 * Input: FP4 E2M1 encoded Q and K matrices from golden/q_fp4_encoded.txt
 *        and golden/k_fp4_encoded.txt
 *
 * Expected output: dequantized FP32 scores from golden/qkt_expected.txt
 *   C_deq[i][j] = C_raw[i][j] * S_Q[i] * S_K[j]
 *
 * Verification: compare hardware FP32 raw output against expected
 *   with tolerance accounting for FP4 quantization error
 *
 * Scale factors from golden/scale_factors.txt:
 *   S_Q: [0.60095245, 0.58922184, 0.63922065, 0.44325686]
 *   S_K: [0.27836114, 0.48067486, 0.40043497, 0.60473281]
 *
 * Profiling output:
 *   - result_valid assertion cycle
 *   - Per-element error vs expected
 *   - MAE summary
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
    for (int i = 0; i < 4; i++) tick(dut, vcd);
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
    vcd->open("systolic_fp4_golden_wave.vcd");

    std::cout << "============================================\n";
    std::cout << "FP4 Systolic Array -- Golden Reference Test\n";
    std::cout << "FP4 E2M1 inputs + FP32 accumulate\n";
    std::cout << "Microscaling dequantization applied\n";
    std::cout << "============================================\n";

    reset(dut, vcd);

    // -----------------------------------------------------------------------
    // FP4 encoded Q matrix [4x4] from golden/q_fp4_encoded.txt
    // Row 0: 0xB(-1.5) 0x7(6.0) 0x5(3.0) 0x3(1.5)
    // Row 1: 0xE(-4.0) 0xE(-4.0) 0xF(-6.0) 0x6(4.0)
    // Row 2: 0x3(1.5) 0x5(3.0) 0xF(-6.0) 0x7(6.0)
    // Row 3: 0x7(6.0) 0xF(-6.0) 0xF(-6.0) 0xF(-6.0)
    // -----------------------------------------------------------------------
    uint8_t Q_fp4[SIZE][SIZE] = {
        {0xB, 0x7, 0x5, 0x3},
        {0xE, 0xE, 0xF, 0x6},
        {0x3, 0x5, 0xF, 0x7},
        {0x7, 0xF, 0xF, 0xF}
    };

    // -----------------------------------------------------------------------
    // FP4 encoded K matrix [4x4] from golden/k_fp4_encoded.txt
    // Row 0: 0xF(-6.0) 0x1(0.5) 0xC(-2.0) 0xF(-6.0)
    // Row 1: 0x4(2.0) 0xF(-6.0) 0xD(-3.0) 0xC(-2.0)
    // Row 2: 0xA(-1.0) 0x7(6.0) 0xF(-6.0) 0x1(0.5)
    // Row 3: 0x2(1.0) 0xF(-6.0) 0x3(1.5) 0xE(-4.0)
    // -----------------------------------------------------------------------
    uint8_t K_fp4[SIZE][SIZE] = {
        {0xF, 0x1, 0xC, 0xF},
        {0x4, 0xF, 0xD, 0xC},
        {0xA, 0x7, 0xF, 0x1},
        {0x2, 0xF, 0x3, 0xE}
    };

    // -----------------------------------------------------------------------
    // Scale factors from golden/scale_factors.txt
    // -----------------------------------------------------------------------
    float S_Q[SIZE] = {0.60095245f, 0.58922184f, 0.63922065f, 0.44325686f};
    float S_K[SIZE] = {0.27836114f, 0.48067486f, 0.40043497f, 0.60473281f};

    // -----------------------------------------------------------------------
    // Expected dequantized output from golden/qkt_expected.txt
    // -----------------------------------------------------------------------
    float expected[SIZE][SIZE] = {
        {-0.501845f, -14.731999f,  4.873008f, -14.173211f},
        { 1.640165f,   7.363827f,  4.247011f,  -1.781609f},
        {-5.604927f,  -2.765316f, 14.206130f, -19.134606f},
        { 1.110469f,  16.618869f, -1.597460f,  15.278962f}
    };

    // -----------------------------------------------------------------------
    // Feed D_HEAD=4 cycles of FP4 input
    // Systolic array feeds columns of Q and K
    // a_in[i] = Q_fp4[i][d], b_in[j] = K_fp4[j][d]
    // -----------------------------------------------------------------------
    int D_HEAD = SIZE;
    std::cout << "\nFeeding " << D_HEAD << " cycles of FP4 input...\n";

    for (int d = 0; d < D_HEAD; d++) {
        for (int i = 0; i < SIZE; i++)
            dut->a_in[i] = Q_fp4[i][d];
        for (int j = 0; j < SIZE; j++)
            dut->b_in[j] = K_fp4[j][d];
        dut->valid_in = 1;
        tick(dut, vcd);
        std::cout << "  Cycle " << (d+1) << ": a=[";
        for (int i = 0; i < SIZE; i++)
            std::cout << "0x" << std::hex << (int)Q_fp4[i][d]
                      << (i<SIZE-1?",":"");
        std::cout << std::dec << "] b=[";
        for (int j = 0; j < SIZE; j++)
            std::cout << "0x" << std::hex << (int)K_fp4[j][d]
                      << (j<SIZE-1?",":"");
        std::cout << std::dec << "]\n";
    }

    dut->valid_in = 0;
    for (int i = 0; i < SIZE; i++) {
        dut->a_in[i] = 0;
        dut->b_in[i] = 0;
    }

    // -----------------------------------------------------------------------
    // Drain -- wait for result_valid
    // -----------------------------------------------------------------------
    int max_drain  = 40;
    int result_cyc = -1;

    std::cout << "\nDraining up to " << max_drain << " cycles...\n";
    for (int i = 0; i < max_drain; i++) {
        tick(dut, vcd);
        if (dut->result_valid && result_cyc < 0) {
            result_cyc = i + 1;
            std::cout << "  result_valid at drain cycle " << result_cyc << "\n";
        }
    }

    if (result_cyc < 0) {
        std::cout << "ERROR: result_valid never asserted\n";
        vcd->close(); dut->final();
        delete vcd; delete dut;
        return 1;
    }

    // -----------------------------------------------------------------------
    // Read raw FP32 results from hardware
    // Apply dequantization: C_deq[i][j] = C_raw[i][j] * S_Q[i] * S_K[j]
    // Compare against expected
    // -----------------------------------------------------------------------
    std::cout << "\n--- Output verification ---\n";
    std::cout << "Format: [raw_result] -> [dequantized] (expected) error\n\n";

    float tolerance = 1e-3f;  // dequantized values should match exactly
    int   pass = 0, total = SIZE * SIZE;
    float total_abs_err = 0.0f;
    float max_abs_err   = 0.0f;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            float raw  = b2f(dut->result[i][j]);
            float deq  = raw * S_Q[i] * S_K[j];
            float exp  = expected[i][j];
            float err  = std::fabs(deq - exp);
            bool  ok   = (err <= tolerance);

            total_abs_err += err;
            if (err > max_abs_err) max_abs_err = err;

            std::cout << "  [" << i << "][" << j << "] raw="
                      << raw << " deq=" << deq
                      << " exp=" << exp
                      << " err=" << err
                      << " " << (ok ? "PASS" : "FAIL") << "\n";

            if (ok) pass++;
        }
    }

    float mae = total_abs_err / (SIZE * SIZE);

    std::cout << "\n============================================\n";
    std::cout << "Results: " << pass << "/" << total << " elements correct\n";
    std::cout << "MAE (dequantized): " << mae << "\n";
    std::cout << "Max error:         " << max_abs_err << "\n";
    if (pass == total)
        std::cout << "ALL PASS -- FP4 QK^T with microscaling verified\n";
    else
        std::cout << "FAIL -- " << (total-pass) << " elements incorrect\n";
    std::cout << "============================================\n";
    std::cout << "Profiling: result_valid at drain cycle " << result_cyc << "\n";
    std::cout << "Waveform: systolic_fp4_golden_wave.vcd\n";

    vcd->close(); dut->final();
    delete vcd; delete dut;
    return (pass == total) ? 0 : 1;
}
