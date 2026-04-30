/*
 * tb_pe.cpp -- Verilator testbench for pe.sv
 *
 * Tests one Processing Element in isolation.
 * Feeds Q row elements from the left and K^T column elements
 * from the top, one pair per clock cycle, and verifies the
 * accumulated dot product matches the expected result.
 *
 * Test case: dot([1,2,3,4], [1,0,1,0]) = 4
 * This matches QKT[0][0] from the golden reference.
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

#include "Vpe.h"          // Verilator-generated header for pe.sv
#include "verilated.h"    // Verilator runtime
#include <iostream>
#include <cstdint>

// ---------------------------------------------------------------------------
// Clock helper -- toggle clock and evaluate
// ---------------------------------------------------------------------------
static void tick(Vpe* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

// ---------------------------------------------------------------------------
// Reset helper -- hold reset for 2 cycles
// ---------------------------------------------------------------------------
static void reset(Vpe* dut) {
    dut->rst_n    = 0;
    dut->a_in     = 0;
    dut->b_in     = 0;
    dut->valid_in = 0;
    tick(dut);
    tick(dut);
    dut->rst_n = 1;
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // Instantiate the DUT (Device Under Test)
    Vpe* dut = new Vpe;

    std::cout << "========================================\n";
    std::cout << "PE Testbench -- Dot Product Verification\n";
    std::cout << "========================================\n";

    // Reset the PE
    reset(dut);
    std::cout << "Reset complete.\n\n";

    // -----------------------------------------------------------------------
    // Test 1: dot([1,2,3,4], [1,0,1,0]) = 4
    // This is Q row 0 dotted with K^T col 0 from the golden reference
    // Expected: 1*1 + 2*0 + 3*1 + 4*0 = 4
    // -----------------------------------------------------------------------
    int16_t a_vec[4] = {1, 2, 3, 4};   // Q row 0
    int16_t b_vec[4] = {1, 0, 1, 0};   // K^T col 0 (= K row 0)
    int32_t expected = 4;

    std::cout << "Test 1: dot([1,2,3,4], [1,0,1,0])\n";
    std::cout << "Expected result: " << expected << "\n\n";

    // Feed 4 pairs of elements, one per cycle
    for (int i = 0; i < 4; i++) {
        dut->a_in     = a_vec[i];
        dut->b_in     = b_vec[i];
        dut->valid_in = 1;
        tick(dut);

        std::cout << "Cycle " << (i+1)
                  << ": a=" << a_vec[i]
                  << " b=" << b_vec[i]
                  << " acc=" << dut->result
                  << "\n";
    }

    // Deassert valid after feeding all elements
    dut->valid_in = 0;
    tick(dut);

    // Check result
    int32_t got = dut->result;
    std::cout << "\nFinal result: " << got << "\n";

    if (got == expected) {
        std::cout << "PASS: result matches expected value " 
                  << expected << "\n";
    } else {
        std::cout << "FAIL: got " << got 
                  << " expected " << expected << "\n";
    }

    // -----------------------------------------------------------------------
    // Test 2: dot([5,6,7,8], [1,0,1,0]) = 12
    // This is Q row 1 dotted with K^T col 0
    // Expected: 5*1 + 6*0 + 7*1 + 8*0 = 12
    // -----------------------------------------------------------------------

    // Reset before second test to clear accumulator
    reset(dut);

    int16_t a_vec2[4] = {5, 6, 7, 8};  // Q row 1
    int16_t b_vec2[4] = {1, 0, 1, 0};  // K^T col 0
    int32_t expected2 = 12;

    std::cout << "\n----------------------------------------\n";
    std::cout << "Test 2: dot([5,6,7,8], [1,0,1,0])\n";
    std::cout << "Expected result: " << expected2 << "\n\n";

    for (int i = 0; i < 4; i++) {
        dut->a_in     = a_vec2[i];
        dut->b_in     = b_vec2[i];
        dut->valid_in = 1;
        tick(dut);

        std::cout << "Cycle " << (i+1)
                  << ": a=" << a_vec2[i]
                  << " b=" << b_vec2[i]
                  << " acc=" << dut->result
                  << "\n";
    }

    dut->valid_in = 0;
    tick(dut);

    int32_t got2 = dut->result;
    std::cout << "\nFinal result: " << got2 << "\n";

    if (got2 == expected2) {
        std::cout << "PASS: result matches expected value "
                  << expected2 << "\n";
    } else {
        std::cout << "FAIL: got " << got2
                  << " expected " << expected2 << "\n";
    }

    // -----------------------------------------------------------------------
    // Summary
    // -----------------------------------------------------------------------
    std::cout << "\n========================================\n";
    int pass_count = (got == expected) + (got2 == expected2);
    std::cout << "Results: " << pass_count << "/2 tests passed\n";
    std::cout << "========================================\n";

    dut->final();
    delete dut;
    return (pass_count == 2) ? 0 : 1;
}
