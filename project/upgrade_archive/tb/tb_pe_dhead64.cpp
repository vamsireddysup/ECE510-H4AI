/*
 * tb_pe_dhead64.cpp -- FP4 PE testbench with D_HEAD=64
 *
 * Verifies the PE accumulator correctly handles 64 products.
 *
 * Test 1: dot([1.0 x64], [1.0 x64]) = 64.0
 * Test 2: dot([1.0,-1.0 x32], [1.0,1.0 x32]) = 0.0 (alternating cancel)
 * Test 3: dot([0.5 x64], [0.5 x64]) = 64*0.25 = 16.0
 * Test 4: dot([6.0 x64], [6.0 x64]) = 64*36 = 2304.0 (max FP4)
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

#define D_HEAD 64

static vluint64_t sim_time = 0;

static float fp4_to_float(uint8_t fp4) {
    uint8_t sign=(fp4>>3)&1, exp=(fp4>>1)&3, mant=fp4&1;
    float v = (exp==0) ? 0.5f*mant : (float)(1<<(exp-1))*(1.0f+0.5f*mant);
    return sign ? -v : v;
}

static float compute_dot(uint8_t* a, uint8_t* b, int n) {
    float s=0; for(int i=0;i<n;i++) s+=fp4_to_float(a[i])*fp4_to_float(b[i]);
    return s;
}

static float b2f(uint32_t b){float f;std::memcpy(&f,&b,sizeof(f));return f;}

static void tick(Vpe* dut, VerilatedVcdC* vcd) {
    dut->clk=0;dut->eval();if(vcd)vcd->dump(sim_time++);
    dut->clk=1;dut->eval();if(vcd)vcd->dump(sim_time++);
}

static void reset(Vpe* dut, VerilatedVcdC* vcd) {
    dut->rst_n=0;dut->a_in=0;dut->b_in=0;dut->valid_in=0;
    for(int i=0;i<4;i++)tick(dut,vcd);
    dut->rst_n=1;tick(dut,vcd);
}

static bool run_test(Vpe* dut, VerilatedVcdC* vcd,
                     const char* name, uint8_t* a, uint8_t* b) {
    float expected = compute_dot(a, b, D_HEAD);

    for(int i=0;i<D_HEAD;i++){
        dut->a_in=a[i];dut->b_in=b[i];dut->valid_in=1;
        tick(dut,vcd);
    }
    dut->valid_in=0;dut->a_in=0;dut->b_in=0;

    // Drain budget: 1 (mul) + D_HEAD (collect) + D_HEAD*2 (acc) + margin
    int drain=200, found=-1;
    for(int i=0;i<drain;i++){
        tick(dut,vcd);
        if(dut->result_valid&&found<0) found=i+1;
    }

    float got=b2f(dut->result);
    float err=std::fabs(got-expected);
    bool ok=(err<=0.01f);

    std::cout<<(ok?"PASS":"FAIL")<<": "<<name
             <<" got="<<got<<" exp="<<expected
             <<" err="<<err<<" (result_valid at drain "<<found<<")\n";
    return ok;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vpe* dut=new Vpe;
    VerilatedVcdC* vcd=new VerilatedVcdC;
    dut->trace(vcd,99);
    vcd->open("pe_dhead64_wave.vcd");

    std::cout<<"============================================\n";
    std::cout<<"FP4 PE D_HEAD=64 Testbench\n";
    std::cout<<"============================================\n";

    int pass=0, total=4;

    // Test 1: all 1.0 x 1.0 = 64.0
    reset(dut,vcd);
    uint8_t a1[D_HEAD], b1[D_HEAD];
    for(int i=0;i<D_HEAD;i++){a1[i]=0x2;b1[i]=0x2;}
    if(run_test(dut,vcd,"All 1.0 x 1.0 (64 terms = 64.0)",a1,b1)) pass++;

    // Test 2: alternating 1.0/-1.0 x 1.0 = 0.0
    reset(dut,vcd);
    uint8_t a2[D_HEAD], b2[D_HEAD];
    for(int i=0;i<D_HEAD;i++){a2[i]=(i%2==0)?0x2:0xA;b2[i]=0x2;}
    if(run_test(dut,vcd,"Alternating +1/-1 x 1 (sum=0)",a2,b2)) pass++;

    // Test 3: all 0.5 x 0.5 = 64*0.25 = 16.0
    reset(dut,vcd);
    uint8_t a3[D_HEAD], b3[D_HEAD];
    for(int i=0;i<D_HEAD;i++){a3[i]=0x1;b3[i]=0x1;}
    if(run_test(dut,vcd,"All 0.5 x 0.5 (64 terms = 16.0)",a3,b3)) pass++;

    // Test 4: all 6.0 x 6.0 = 64*36 = 2304.0 (max FP4)
    reset(dut,vcd);
    uint8_t a4[D_HEAD], b4[D_HEAD];
    for(int i=0;i<D_HEAD;i++){a4[i]=0x7;b4[i]=0x7;}
    if(run_test(dut,vcd,"All 6.0 x 6.0 (64 terms = 2304.0)",a4,b4)) pass++;

    std::cout<<"\n============================================\n";
    std::cout<<"Results: "<<pass<<"/"<<total<<" tests passed\n";
    if(pass==total) std::cout<<"ALL PASS -- D_HEAD=64 accumulator verified\n";
    else            std::cout<<"FAIL\n";
    std::cout<<"============================================\n";

    vcd->close();dut->final();
    delete vcd;delete dut;
    return (pass==total)?0:1;
}
