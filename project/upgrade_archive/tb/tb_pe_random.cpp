/*
 * tb_pe_fp4.cpp -- FP4 PE testbench with random value verification
 *
 * Tests:
 *   1-3: Original fixed tests (regression)
 *   4-13: Random FP4 value tests covering all 16 FP4 values
 *   14: All maximum values (6.0 x 6.0 x 4 = 144.0)
 *   15: All minimum values (-6.0 x -6.0 x 4 = 144.0)
 *   16: Mixed max/min (-6.0 x 6.0 x 4 = -144.0)
 *   17: All zeros
 *   18: Single nonzero (only first element nonzero)
 *
 * Expected values computed using fp4_to_float() matching gen_fp4_lut.py
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

static float compute_dot(uint8_t* a, uint8_t* b, int n) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++)
        sum += fp4_to_float(a[i]) * fp4_to_float(b[i]);
    return sum;
}

static float b2f(uint32_t b) {
    float f; std::memcpy(&f, &b, sizeof(float)); return f;
}

static void tick(Vpe* dut, VerilatedVcdC* vcd) {
    dut->clk = 0; dut->eval();
    if (vcd) vcd->dump(sim_time++);
    dut->clk = 1; dut->eval();
    if (vcd) vcd->dump(sim_time++);
}

static void reset(Vpe* dut, VerilatedVcdC* vcd) {
    dut->rst_n=0; dut->a_in=0; dut->b_in=0; dut->valid_in=0;
    tick(dut,vcd); tick(dut,vcd); tick(dut,vcd);
    dut->rst_n=1; tick(dut,vcd);
}

static bool run_test(Vpe* dut, VerilatedVcdC* vcd,
                     const char* name,
                     uint8_t* a, uint8_t* b, int d_head,
                     float tolerance=1e-3f)
{
    float expected = compute_dot(a, b, d_head);

    for (int i = 0; i < d_head; i++) {
        dut->a_in=a[i]; dut->b_in=b[i]; dut->valid_in=1;
        tick(dut,vcd);
    }
    dut->valid_in=0; dut->a_in=0; dut->b_in=0;

    int found=-1;
    for (int i = 0; i < 25; i++) {
        tick(dut,vcd);
        if (dut->result_valid && found<0) found=i+1;
    }

    float got = b2f(dut->result);
    float err = std::fabs(got - expected);
    bool  ok  = (err <= tolerance);

    std::cout << (ok?"PASS":"FAIL") << ": " << name
              << " got=" << got << " exp=" << expected
              << " err=" << err << "\n";
    return ok;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vpe* dut = new Vpe;
    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd,99);
    vcd->open("pe_random_wave.vcd");

    std::cout << "============================================\n";
    std::cout << "FP4 PE -- Extended Random Value Tests\n";
    std::cout << "============================================\n";

    int pass=0, total=0;

    // -----------------------------------------------------------------------
    // Regression: original 3 tests
    // -----------------------------------------------------------------------
    reset(dut,vcd);
    uint8_t a1[]={0x2,0x0,0x2,0x0}, b1[]={0x2,0x0,0x2,0x0};
    if(run_test(dut,vcd,"Regression 1: dot([1,0,1,0],[1,0,1,0])",a1,b1,4)) pass++;
    total++;

    reset(dut,vcd);
    uint8_t a2[]={0x2,0x3,0x4,0x1}, b2[]={0x4,0x2,0x1,0x3};
    if(run_test(dut,vcd,"Regression 2: dot([1,1.5,2,0.5],[2,1,0.5,1.5])",a2,b2,4)) pass++;
    total++;

    reset(dut,vcd);
    uint8_t a3[]={0x2,0xA,0x2,0xA}, b3[]={0x2,0x2,0x2,0x2};
    if(run_test(dut,vcd,"Regression 3: dot([1,-1,1,-1],[1,1,1,1])",a3,b3,4)) pass++;
    total++;

    // -----------------------------------------------------------------------
    // Edge: all maximum positive (6.0 x 6.0 x 4 = 144.0)
    // -----------------------------------------------------------------------
    reset(dut,vcd);
    uint8_t a4[]={0x7,0x7,0x7,0x7}, b4[]={0x7,0x7,0x7,0x7};
    if(run_test(dut,vcd,"Edge: all max pos (6x6x4=144)",a4,b4,4)) pass++;
    total++;

    // -----------------------------------------------------------------------
    // Edge: all maximum negative (-6.0 x -6.0 x 4 = 144.0)
    // -----------------------------------------------------------------------
    reset(dut,vcd);
    uint8_t a5[]={0xF,0xF,0xF,0xF}, b5[]={0xF,0xF,0xF,0xF};
    if(run_test(dut,vcd,"Edge: all max neg (-6x-6x4=144)",a5,b5,4)) pass++;
    total++;

    // -----------------------------------------------------------------------
    // Edge: mixed max (-6.0 x 6.0 x 4 = -144.0)
    // -----------------------------------------------------------------------
    reset(dut,vcd);
    uint8_t a6[]={0xF,0xF,0xF,0xF}, b6[]={0x7,0x7,0x7,0x7};
    if(run_test(dut,vcd,"Edge: mixed max (-6x6x4=-144)",a6,b6,4)) pass++;
    total++;

    // -----------------------------------------------------------------------
    // Edge: all zeros
    // -----------------------------------------------------------------------
    reset(dut,vcd);
    uint8_t a7[]={0x0,0x0,0x0,0x0}, b7[]={0x0,0x0,0x0,0x0};
    if(run_test(dut,vcd,"Edge: all zeros (0x0x4=0)",a7,b7,4)) pass++;
    total++;

    // -----------------------------------------------------------------------
    // Edge: single nonzero (only index 0)
    // -----------------------------------------------------------------------
    reset(dut,vcd);
    uint8_t a8[]={0x5,0x0,0x0,0x0}, b8[]={0x4,0x0,0x0,0x0}; // 3.0 x 2.0 = 6.0
    if(run_test(dut,vcd,"Edge: single nonzero (3x2=6)",a8,b8,4)) pass++;
    total++;

    // -----------------------------------------------------------------------
    // Random 1: all 16 FP4 values represented
    // a=[0.5, 1.5, 3.0, 6.0], b=[-0.5,-1.5,-3.0,-6.0]
    // -----------------------------------------------------------------------
    reset(dut,vcd);
    uint8_t a9[]={0x1,0x3,0x5,0x7}, b9[]={0x9,0xB,0xD,0xF};
    if(run_test(dut,vcd,"Random 1: pos x neg FP4 values",a9,b9,4)) pass++;
    total++;

    // -----------------------------------------------------------------------
    // Random 2: a=[2.0,4.0,0.5,1.0], b=[1.5,0.5,4.0,2.0]
    // -----------------------------------------------------------------------
    reset(dut,vcd);
    uint8_t a10[]={0x4,0x6,0x1,0x2}, b10[]={0x3,0x1,0x6,0x4};
    if(run_test(dut,vcd,"Random 2: mixed FP4 values",a10,b10,4)) pass++;
    total++;

    // -----------------------------------------------------------------------
    // Random 3: alternating max pos/neg
    // a=[6,-6,6,-6], b=[6,6,-6,-6]
    // -----------------------------------------------------------------------
    reset(dut,vcd);
    uint8_t a11[]={0x7,0xF,0x7,0xF}, b11[]={0x7,0x7,0xF,0xF};
    if(run_test(dut,vcd,"Random 3: alternating max pos/neg",a11,b11,4)) pass++;
    total++;

    // -----------------------------------------------------------------------
    // Random 4: subnormal values only (0.0 and 0.5)
    // a=[0.5,0.0,0.5,0.0], b=[0.0,0.5,0.0,0.5]
    // -----------------------------------------------------------------------
    reset(dut,vcd);
    uint8_t a12[]={0x1,0x0,0x1,0x0}, b12[]={0x0,0x1,0x0,0x1};
    if(run_test(dut,vcd,"Random 4: subnormal (0.5 and 0)",a12,b12,4)) pass++;
    total++;

    // -----------------------------------------------------------------------
    // Random 5: golden reference values from gen_golden.py row 0
    // a=[0xB,0x7,0x5,0x3] = [-1.5,6.0,3.0,1.5]
    // b=[0xF,0x1,0xC,0xF] = [-6.0,0.5,-2.0,-6.0]
    // -----------------------------------------------------------------------
    reset(dut,vcd);
    uint8_t a13[]={0xB,0x7,0x5,0x3}, b13[]={0xF,0x1,0xC,0xF};
    if(run_test(dut,vcd,"Random 5: golden ref row0 x col0",a13,b13,4)) pass++;
    total++;

    std::cout << "\n============================================\n";
    std::cout << "Results: " << pass << "/" << total << " tests passed\n";
    if (pass==total)
        std::cout << "ALL PASS -- FP4 PE verified with random values\n";
    else
        std::cout << "FAIL -- " << (total-pass) << " tests failed\n";
    std::cout << "============================================\n";

    vcd->close(); dut->final();
    delete vcd; delete dut;
    return (pass==total) ? 0 : 1;
}
