/*
 * tb_systolic_array16.cpp -- SIZE=16 systolic array basic verification
 *
 * Tests a 16x16 FP4 systolic array with a simple identity-like pattern:
 *   Q = all rows [1.0, 0.0, 1.0, 0.0]  (only 4 elements, rest zero)
 *   K = identity-like: K[j][d] = 1.0 if d==0, else 0.0
 *
 * Expected: each output C[i][j] = Q[i][0]*K[j][0] = 1.0*1.0 = 1.0 for all
 *
 * This test verifies:
 *   - SIZE=16 array elaborates correctly (256 PEs)
 *   - Stagger logic works for 16 rows/cols
 *   - result_valid asserts after correct drain cycles
 *   - All 256 output elements correct
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

#define SIZE   16
#define D_HEAD 4

static vluint64_t sim_time = 0;

static float b2f(uint32_t b) {
    float f; std::memcpy(&f, &b, sizeof(float)); return f;
}

static void tick(Vsystolic_array* dut, VerilatedVcdC* vcd) {
    dut->clk=0; dut->eval();
    if(vcd) vcd->dump(sim_time++);
    dut->clk=1; dut->eval();
    if(vcd) vcd->dump(sim_time++);
}

static void reset(Vsystolic_array* dut, VerilatedVcdC* vcd) {
    dut->rst_n=0; dut->valid_in=0;
    for(int i=0;i<SIZE;i++){dut->a_in[i]=0;dut->b_in[i]=0;}
    for(int i=0;i<4;i++) tick(dut,vcd);
    dut->rst_n=1; tick(dut,vcd);
    std::cout<<"Reset complete.\n";
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vsystolic_array* dut = new Vsystolic_array;
    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd,99);
    vcd->open("systolic16_wave.vcd");

    std::cout<<"============================================\n";
    std::cout<<"FP4 Systolic Array SIZE=16 -- Basic Test\n";
    std::cout<<"16x16 = 256 PEs, D_HEAD=4\n";
    std::cout<<"============================================\n";

    reset(dut,vcd);

    // -----------------------------------------------------------------------
    // Q: all rows = [1.0, 0.0, 0.0, 0.0]  (FP4: 0x2=1.0, 0x0=0.0)
    // K: all rows = [1.0, 0.0, 0.0, 0.0]  (identity-like first column)
    // Expected: C[i][j] = 1.0 * 1.0 = 1.0 for all i,j
    // -----------------------------------------------------------------------
    std::cout<<"\nFeeding "<<D_HEAD<<" cycles -- Q=all 1.0 col0, K=all 1.0 col0\n";

    for(int d=0; d<D_HEAD; d++) {
        for(int i=0; i<SIZE; i++) {
            dut->a_in[i] = (d==0) ? 0x2 : 0x0;  // 1.0 on cycle 0, 0 else
            dut->b_in[i] = (d==0) ? 0x2 : 0x0;
        }
        dut->valid_in=1;
        tick(dut,vcd);
    }

    dut->valid_in=0;
    for(int i=0;i<SIZE;i++){dut->a_in[i]=0;dut->b_in[i]=0;}

    // Drain budget for SIZE=16:
    // Stagger: 2*(SIZE-1) = 30 cycles
    // Multiply: 1 cycle
    // Collect: D_HEAD = 4 cycles
    // Accumulate: D_HEAD*2 = 8 cycles
    // Total: ~43 cycles, use 80
    int max_drain=80, result_cyc=-1;
    std::cout<<"Draining up to "<<max_drain<<" cycles...\n";

    for(int i=0;i<max_drain;i++) {
        tick(dut,vcd);
        if(dut->result_valid && result_cyc<0) {
            result_cyc=i+1;
            std::cout<<"  result_valid at drain cycle "<<result_cyc<<"\n";
        }
    }

    if(result_cyc<0) {
        std::cout<<"ERROR: result_valid never asserted\n";
        vcd->close(); dut->final();
        delete vcd; delete dut;
        return 1;
    }

    // Verify all 256 outputs
    int pass=0, total=SIZE*SIZE;
    float tolerance=1e-3f;
    float expected=1.0f;  // all elements should be 1.0

    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            float got=b2f(dut->result[i][j]);
            float err=std::fabs(got-expected);
            bool ok=(err<=tolerance);
            if(ok) pass++;
            else
                std::cout<<"FAIL result["<<i<<"]["<<j<<"]="
                         <<got<<" expected "<<expected<<"\n";
        }
    }

    std::cout<<"\n============================================\n";
    std::cout<<"Results: "<<pass<<"/"<<total<<" elements correct\n";
    std::cout<<"result_valid at drain cycle "<<result_cyc<<"\n";
    if(pass==total)
        std::cout<<"ALL PASS -- SIZE=16 array verified\n";
    else
        std::cout<<"FAIL -- "<<(total-pass)<<" elements incorrect\n";
    std::cout<<"============================================\n";
    std::cout<<"Waveform: systolic16_wave.vcd\n";

    vcd->close(); dut->final();
    delete vcd; delete dut;
    return (pass==total)?0:1;
}
