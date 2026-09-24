#include <verilated.h>
#include "Vqkt_chiplet_top.h"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <vector>

#ifndef TEST_D
#define TEST_D 4
#endif
#ifndef TEST_TMAX
#define TEST_TMAX 16
#endif
static constexpr int B=4, D=TEST_D, TMAX=TEST_TMAX;
#ifdef TEST_LARGE
static constexpr bool STRESS_STALLS=false;
#else
static constexpr bool STRESS_STALLS=true;
#endif
static Vqkt_chiplet_top dut;
static uint64_t cycles=0;
static bool legacy_mode=false;
static void step() { dut.clk=0; dut.eval(); dut.clk=1; dut.eval(); ++cycles; }
static void check(bool ok, const char* msg) { if (!ok) throw std::runtime_error(msg); }
static uint32_t bits(float x) { uint32_t v; std::memcpy(&v,&x,4); return v; }
static float flt(uint32_t x) { float v; std::memcpy(&v,&x,4); return v; }
static int half(int c) { static const int m[]={0,1,2,3,4,6,8,12}; return (c&8) ? -m[c&7] : m[c&7]; }
static void reset() {
    dut.rst_n=0; dut.awvalid=0; dut.wvalid=0; dut.bready=0;
    dut.arvalid=0; dut.rready=0; dut.s_tvalid=0; dut.m_tready=0;
    for(int i=0;i<4;i++) step(); dut.rst_n=1; step();
}
static void write_reg(uint32_t addr,uint32_t data) {
    dut.awaddr=addr; dut.awvalid=1;
    bool accepted=false;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); accepted=dut.awready; step(); if(accepted) break; }
    check(accepted,"AXI address timeout"); dut.awvalid=0;
    dut.wdata=data; dut.wstrb=15; dut.wvalid=1;
    accepted=false;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); accepted=dut.wready; step(); if(accepted) break; }
    check(accepted,"AXI data timeout"); dut.wvalid=0;
    accepted=false;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); accepted=dut.bvalid; if(accepted) break; step(); }
    check(accepted,"AXI response timeout"); dut.bready=1; step(); dut.bready=0;
}
static uint32_t read_reg(uint32_t addr) {
    dut.araddr=addr; dut.arvalid=1; bool accepted=false;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); accepted=dut.arready; step(); if(accepted) break; }
    check(accepted,"AXI read address timeout"); dut.arvalid=0;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); if(dut.rvalid) { uint32_t x=dut.rdata; dut.rready=1; step(); dut.rready=0; return x; } step(); }
    throw std::runtime_error("AXI read data timeout");
}
static void send_beat(uint64_t data,bool last,int gap=0) {
    dut.s_tvalid=0; for(int i=0;i<gap;i++) step();
    dut.s_tdata=data; dut.s_tlast=last; dut.s_tvalid=1;
    for(int i=0;i<100000;i++) { dut.clk=0; dut.eval(); bool accepted=dut.s_tready; step(); if(accepted) { dut.s_tvalid=0; dut.s_tlast=0; return; } }
    throw std::runtime_error("input stream timeout");
}
static int code(int row,int depth,int salt) {
    if(legacy_mode) {
        static const int pattern[4][4]={{2,0,2,0},{0,2,0,2},{2,2,0,0},{0,0,2,2}};
        return pattern[row][depth];
    }
    return (row*7+depth*3+salt)%16;
}
static void send_scales(int t, int malformed=0) {
    for(int b=0;b<t;b++) {
        // Scale order is Q[0..T-1], then K[0..T-1].
        auto value=[&](int idx)->uint32_t { return bits(legacy_mode ? 1.0f :
            (idx<t ? (idx%2 ? 2.0f:1.0f) : ((idx-t)%2 ? 0.5f:1.0f))); };
        uint32_t lo=value(2*b), hi=value(2*b+1);
        send_beat((uint64_t(hi)<<32)|lo,
                  malformed==1 ? b==0 : (malformed==2 ? false : b==t-1), STRESS_STALLS ? b%3 : 0);
        if(malformed==1) return;
    }
}
static void send_tile(int start,int t,int salt) {
    constexpr int N=B*D;
    for(int b=0;b<(N+15)/16;b++) {
        uint64_t beat=0;
        for(int l=0;l<16;l++) { int e=b*16+l; if(e<N && start+e/D<t) beat |= uint64_t(code(start+e/D,e%D,salt)) << (4*l); }
        send_beat(beat,b==(N+15)/16-1,STRESS_STALLS ? b%4 : 0);
    }
}
static float expected(int row,int col) {
    int sum=0;
    for(int d=0;d<D;d++) sum+=half(code(row,d,1))*half(code(col,d,5));
    return (sum*0.25f)*(legacy_mode ? 1.0f : (row%2?2.0f:1.0f)) *
        (legacy_mode ? 1.0f : (col%2?0.5f:1.0f));
}
static void receive_tile(int qr,int kc,int t,int& checked) {
    int rows=std::min(B,t-qr), cols=std::min(B,t-kc), count=rows*cols, got=0;
    uint64_t held=0; bool held_last=false, stalled=false;
    for(int timeout=0;timeout<200000 && got<count;timeout++) {
        dut.m_tready=!STRESS_STALLS || (timeout%5>=2);
        dut.clk=0; dut.eval();
        if(stalled) check(dut.m_tvalid && dut.m_tdata==held && bool(dut.m_tlast)==held_last,"output changed under backpressure");
        bool transfer=dut.m_tvalid && dut.m_tready;
        if(dut.m_tvalid) {
            held=dut.m_tdata; held_last=dut.m_tlast;
            check(bool(dut.m_tlast)==(got+2>=count),"TLAST wrong");
        }
        stalled=dut.m_tvalid && !dut.m_tready;
        if(transfer) {
            if(got+1==count) check(uint32_t(held>>32)==0,"final output padding");
            for(int lane=0;lane<2 && got<count;lane++,got++) {
                int row=qr+got/cols, col=kc+got%cols;
                float actual=flt(uint32_t(held>>(32*lane)));
                float want=expected(row,col);
                if(std::fabs(actual-want)>0.0001f) {
                    std::fprintf(stderr,"score (%d,%d): got %f want %f\n",row,col,actual,want);
                    throw std::runtime_error("score mismatch");
                }
                checked++;
            }
        }
        step();
    }
    check(got==count,"output timeout"); dut.m_tready=0;
}
static void run_case(int t) {
    write_reg(0x08,t); write_reg(0x00,1);
    send_scales(t);
    int checked=0, tiles=0;
    for(int qr=0;qr<t;qr+=B) {
        send_tile(qr,t,1);
        for(int kc=0;kc<t;kc+=B) { send_tile(kc,t,5); receive_tile(qr,kc,t,checked); tiles++; }
    }
    for(int i=0;i<100 && !(read_reg(0x04)&1);i++) step();
    check(read_reg(0x04)==1,"completion or error status");
    check(read_reg(0x0C)==uint32_t(tiles),"tile count");
    check(read_reg(0x20)==uint32_t(t+((t+B-1)/B)*(1+(t+B-1)/B)*((B*D+15)/16)),"input beat count");
    int output_beats=0;
    for(int qr=0;qr<t;qr+=B)
        for(int kc=0;kc<t;kc+=B)
            output_beats+=(std::min(B,t-qr)*std::min(B,t-kc)+1)/2;
    check(read_reg(0x24)==uint32_t(output_beats),"output beat count");
    check(read_reg(0x28)>0,"input stalls absent");
    if(STRESS_STALLS) check(read_reg(0x2C)>0,"output stalls absent");
    check(read_reg(0x30)==uint32_t(tiles*D),"compute cycles");
    std::printf("T=%d D=%d scores=%d tiles=%d cycles=%u in_beats=%u out_beats=%u stalls=%u PASS\n",
        t,D,checked,tiles,read_reg(0x10),read_reg(0x20),read_reg(0x24),read_reg(0x2C));
    check(checked==t*t,"score count");
}
int main(int argc,char** argv) {
    Verilated::commandArgs(argc,argv);
    try {
        reset(); check(read_reg(0x1C)==1,"stream version");
#ifdef TEST_LARGE
        run_case(64); run_case(128); run_case(512);
#else
        run_case(1); run_case(4); run_case(7); run_case(8); run_case(16);
        if(D==4) { legacy_mode=true; run_case(4); legacy_mode=false; }
        write_reg(0x08,4); write_reg(0x00,1); send_scales(4,1);
        check(read_reg(0x04)==0x21,"early TLAST status");
        write_reg(0x08,4); write_reg(0x00,1); send_scales(4,2);
        check(read_reg(0x04)==0x31,"missing TLAST status");
        write_reg(0x08,4); write_reg(0x00,1);
        send_beat(uint64_t(bits(1.0f)),false);
        reset(); run_case(4);
        write_reg(0x08,TMAX+1); write_reg(0x00,1);
        check(read_reg(0x04)==0x11,"dimension error status");
#endif
        std::puts("ALL PASS"); return 0;
    } catch(const std::exception& e) { std::fprintf(stderr,"FAIL: %s at cycle %llu\n",e.what(),(unsigned long long)cycles); return 1; }
}
