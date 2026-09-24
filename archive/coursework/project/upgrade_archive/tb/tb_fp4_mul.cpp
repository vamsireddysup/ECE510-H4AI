/*
 * tb_fp4_mul.cpp -- Verilator testbench for fp4_mul.sv
 *
 * Verifies all 256 FP4 x FP4 combinations against the Python-generated
 * reference table. Every entry must match exactly (bit-for-bit FP32).
 *
 * Run normal:  make fp4_mul
 * Run debug:   make fp4_mul_debug
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

#include "Vfp4_mul.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <cstdint>
#include <cstring>
#include <cmath>

static vluint64_t sim_time = 0;

// ---------------------------------------------------------------------------
// FP4 E2M1 decode -- matches gen_fp4_lut.py exactly
// ---------------------------------------------------------------------------
static float fp4_to_float(uint8_t fp4) {
    uint8_t sign = (fp4 >> 3) & 0x1;
    uint8_t exp  = (fp4 >> 1) & 0x3;
    uint8_t mant = (fp4 >> 0) & 0x1;

    float value;
    if (exp == 0) {
        // subnormal
        value = 0.5f * mant;
    } else {
        // normal
        value = (float)(1 << (exp - 1)) * (1.0f + 0.5f * mant);
    }
    if (sign) value = -value;
    return value;
}

// ---------------------------------------------------------------------------
// FP32 bit-cast helpers
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
static void tick(Vfp4_mul* dut, VerilatedVcdC* vcd) {
    dut->clk = 0;
    dut->eval();
    if (vcd) vcd->dump(sim_time++);
    dut->clk = 1;
    dut->eval();
    if (vcd) vcd->dump(sim_time++);
}

static void reset(Vfp4_mul* dut, VerilatedVcdC* vcd) {
    dut->rst_n    = 0;
    dut->a        = 0;
    dut->b        = 0;
    dut->valid_in = 0;
    tick(dut, vcd);
    tick(dut, vcd);
    dut->rst_n = 1;
    tick(dut, vcd);
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vfp4_mul* dut = new Vfp4_mul;

    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd, 99);
    vcd->open("fp4_mul_wave.vcd");

    std::cout << "============================================\n";
    std::cout << "FP4 Multiplier Testbench -- 256 entry verify\n";
    std::cout << "============================================\n";

    reset(dut, vcd);

    int pass  = 0;
    int fail  = 0;
    int total = 256;

    // -----------------------------------------------------------------------
    // Test all 256 combinations
    // Feed a and b, wait 1 cycle for registered output
    // Compare against software-computed reference
    // -----------------------------------------------------------------------
    for (int a = 0; a < 16; a++) {
        for (int b = 0; b < 16; b++) {
            // Drive inputs
            dut->a        = (uint8_t)a;
            dut->b        = (uint8_t)b;
            dut->valid_in = 1;
            tick(dut, vcd);

            // Result appears one cycle later
            // valid_out should be high now
            float fa       = fp4_to_float((uint8_t)a);
            float fb       = fp4_to_float((uint8_t)b);
            float expected = fa * fb;
            uint32_t exp_bits = f2b(expected);
            uint32_t got_bits = dut->result;
            float got         = b2f(got_bits);

            bool ok = (got_bits == exp_bits);

            if (!ok) {
                std::cout << "FAIL: FP4[0x" << std::hex << a << "]("
                          << std::dec << fa << ") x FP4[0x"
                          << std::hex << b << "](" << std::dec << fb
                          << ") = " << got
                          << " (expected " << expected << ")"
                          << " got=0x" << std::hex << got_bits
                          << " exp=0x" << exp_bits << std::dec << "\n";
                fail++;
            } else {
                pass++;
            }
        }
    }

    dut->valid_in = 0;
    tick(dut, vcd);

    // -----------------------------------------------------------------------
    // Summary
    // -----------------------------------------------------------------------
    std::cout << "\n============================================\n";
    std::cout << "Results: " << pass << "/" << total << " entries correct\n";
    if (fail == 0)
        std::cout << "ALL PASS -- FP4 multiplier LUT verified\n";
    else
        std::cout << "FAIL -- " << fail << " entries incorrect\n";
    std::cout << "============================================\n";
    std::cout << "Waveform saved to fp4_mul_wave.vcd\n";

    vcd->close();
    dut->final();
    delete vcd;
    delete dut;

    return (fail == 0) ? 0 : 1;
}
