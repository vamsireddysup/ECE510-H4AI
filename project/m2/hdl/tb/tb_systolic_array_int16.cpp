/*
 * tb_systolic_array.cpp -- Verilator testbench for systolic_array.sv
 *
 * Tests a 4x4 systolic array (SIZE=4, D_HEAD=4) using the same Q and K
 * matrices from the golden reference (gen_golden.py).
 *
 * Q matrix:                K matrix:
 * 1 2 3 4                  1 0 1 0
 * 5 6 7 8                  0 1 0 1
 * 1 0 1 0                  1 1 0 0
 * 2 3 2 3                  0 0 1 1
 *
 * Expected QK^T:
 *  4  6  3  7
 * 12 14 11 15
 *  2  0  1  1
 *  4  6  5  5
 *
 * Total cycles needed: (SIZE-1) + (SIZE-1) + D_HEAD = 3+3+4 = 10 cycles
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

#include "Vsystolic_array.h"
#include "verilated.h"
#include <iostream>
#include <cstdint>
#include <cstring>

#define SIZE   4
#define D_HEAD 4

// ---------------------------------------------------------------------------
// Clock tick
// ---------------------------------------------------------------------------
static void tick(Vsystolic_array* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

// ---------------------------------------------------------------------------
// Reset -- hold for 3 cycles
// ---------------------------------------------------------------------------
static void reset(Vsystolic_array* dut) {
    dut->rst_n    = 0;
    dut->valid_in = 0;
    for (int i = 0; i < SIZE; i++) {
        dut->a_in[i] = 0;
        dut->b_in[i] = 0;
    }
    tick(dut); tick(dut); tick(dut);
    dut->rst_n = 1;
    tick(dut);
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vsystolic_array* dut = new Vsystolic_array;

    std::cout << "============================================\n";
    std::cout << "Systolic Array Testbench -- 4x4 QK^T verify\n";
    std::cout << "============================================\n";

    // -----------------------------------------------------------------------
    // Q matrix -- rows fed into left edge
    // -----------------------------------------------------------------------
    int16_t Q[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 0, 1, 0},
        {2, 3, 2, 3}
    };

    // -----------------------------------------------------------------------
    // K matrix -- columns of K^T fed into top edge
    // K^T col j = K row j
    // -----------------------------------------------------------------------
    int16_t K[SIZE][SIZE] = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    };

    // -----------------------------------------------------------------------
    // Expected output from golden reference
    // -----------------------------------------------------------------------
    int32_t expected[SIZE][SIZE] = {
        { 4,  6,  3,  7},
        {12, 14, 11, 15},
        { 2,  0,  1,  1},
        { 4,  6,  5,  5}
    };

    // -----------------------------------------------------------------------
    // Reset
    // -----------------------------------------------------------------------
    reset(dut);
    std::cout << "Reset complete.\n\n";

    // -----------------------------------------------------------------------
    // Feed D_HEAD cycles of data
    // Each cycle: feed one element from each row of Q (a_in[row])
    //             feed one element from each col of K^T (b_in[col] = K[col][cycle])
    // The stagger shift registers inside the array handle the diagonal delay.
    // -----------------------------------------------------------------------
    std::cout << "Feeding " << D_HEAD << " cycles of input data...\n";

    for (int cycle = 0; cycle < D_HEAD; cycle++) {
        // Feed column 'cycle' of Q to each row's a_in
        for (int row = 0; row < SIZE; row++) {
            dut->a_in[row] = Q[row][cycle];
        }
        // Feed row 'cycle' of K to each col's b_in (K row = K^T col)
        for (int col = 0; col < SIZE; col++) {
            dut->b_in[col] = K[col][cycle];
        }
        dut->valid_in = 1;
        tick(dut);

        std::cout << "  Feed cycle " << (cycle+1)
                  << ": a=[";
        for (int r = 0; r < SIZE; r++)
            std::cout << Q[r][cycle] << (r<SIZE-1?",":"");
        std::cout << "] b=[";
        for (int c = 0; c < SIZE; c++)
            std::cout << K[c][cycle] << (c<SIZE-1?",":"");
        std::cout << "]\n";
    }

    // -----------------------------------------------------------------------
    // Deassert valid and wait for wavefront to propagate
    // Need (SIZE-1) + (SIZE-1) = 6 more cycles after last data feed
    // Total wait = 10 cycles from first feed, 6 after last feed
    // -----------------------------------------------------------------------
    dut->valid_in = 0;
    for (int i = 0; i < SIZE; i++) {
        dut->a_in[i] = 0;
        dut->b_in[i] = 0;
    }

    int drain_cycles = (SIZE-1) + (SIZE-1) + (SIZE-1);
    std::cout << "\nDraining " << drain_cycles
              << " cycles for wavefront to complete...\n";
    for (int i = 0; i < drain_cycles; i++) {
        tick(dut);
    }

    // -----------------------------------------------------------------------
    // Read and verify all 16 output elements
    // -----------------------------------------------------------------------
    std::cout << "\n--- Output matrix ---\n";
    int pass = 0;
    int fail = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int32_t got = dut->result[i][j];
            int32_t exp = expected[i][j];
            bool ok = (got == exp);
            if (ok) pass++; else fail++;

            std::cout << "  result[" << i << "][" << j << "] = "
                      << got
                      << " (expected " << exp << ") "
                      << (ok ? "PASS" : "FAIL")
                      << "\n";
        }
    }

    // -----------------------------------------------------------------------
    // Summary
    // -----------------------------------------------------------------------
    std::cout << "\n============================================\n";
    std::cout << "Results: " << pass << "/" << (SIZE*SIZE)
              << " elements correct\n";
    if (fail == 0) {
        std::cout << "ALL PASS -- QK^T output matches golden reference\n";
    } else {
        std::cout << fail << " FAILURES -- check waveform\n";
    }
    std::cout << "============================================\n";

    dut->final();
    delete dut;
    return (fail == 0) ? 0 : 1;
}
