// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
#include <verilated.h>
#include "Vqkt_chiplet_top.h"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

#ifndef TEST_D
#define TEST_D 4
#endif
#ifndef TEST_TMAX
#define TEST_TMAX 16
#endif
#ifndef TEST_B
#define TEST_B 4
#endif
#ifndef TEST_SCALE_BLOCK
#define TEST_SCALE_BLOCK 32
#endif
static constexpr int B=TEST_B, D=TEST_D, TMAX=TEST_TMAX;
static constexpr int BS=TEST_SCALE_BLOCK, BLOCKS=(D+BS-1)/BS;
#ifdef TEST_LARGE
static constexpr bool STRESS_STALLS=false;
#else
static constexpr bool STRESS_STALLS=true;
#endif
#ifdef TEST_K_REUSE
static constexpr bool REUSE=true;
#else
static constexpr bool REUSE=false;
#endif
static Vqkt_chiplet_top dut;
static uint64_t cycles=0;
static bool legacy_mode=false;
static uint32_t pattern_seed=0;
static bool varied_scales=false;
static int extreme_mode=0;
static bool precision_mode=false;
static std::vector<uint8_t> precision_q,precision_k;
static std::vector<float> precision_qscale,precision_kscale;
static std::vector<uint32_t> precision_scores,precision_reference;
static double precision_diff_sq=0.0,precision_ref_sq=0.0,precision_abs=0.0;
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
static void write_reg(uint32_t addr,uint32_t data,uint8_t strobes=15) {
    dut.awaddr=addr; dut.awvalid=1;
    bool accepted=false;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); accepted=dut.awready; step(); if(accepted) break; }
    check(accepted,"AXI address timeout"); dut.awvalid=0;
    dut.wdata=data; dut.wstrb=strobes; dut.wvalid=1;
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
static void write_data_first(uint32_t addr,uint32_t data) {
    dut.wdata=data; dut.wstrb=15; dut.wvalid=1;
    bool accepted=false;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); accepted=dut.wready; step(); if(accepted) break; }
    check(accepted,"AXI W-before-AW timeout"); dut.wvalid=0;
    dut.awaddr=addr; dut.awvalid=1; accepted=false;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); accepted=dut.awready; step(); if(accepted) break; }
    check(accepted,"AXI delayed AW timeout"); dut.awvalid=0;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); if(dut.bvalid) { dut.bready=1; step(); dut.bready=0; return; } step(); }
    throw std::runtime_error("AXI W-before-AW response timeout");
}
static void write_together(uint32_t addr,uint32_t data) {
    dut.awaddr=addr; dut.awvalid=1;
    dut.wdata=data; dut.wstrb=15; dut.wvalid=1;
    dut.clk=0; dut.eval();
    check(dut.awready && dut.wready,"AXI simultaneous channels not ready");
    step(); dut.awvalid=0; dut.wvalid=0;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); if(dut.bvalid) { dut.bready=1; step(); dut.bready=0; return; } step(); }
    throw std::runtime_error("AXI simultaneous response timeout");
}
static void check_read_stall() {
    write_reg(0x08,4); write_reg(0x00,1);
    dut.araddr=0x10; dut.arvalid=1;
    bool accepted=false;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); accepted=dut.arready; step(); if(accepted) break; }
    check(accepted,"AXI stalled read address timeout"); dut.arvalid=0;
    for(int i=0;i<100;i++) { dut.clk=0; dut.eval(); if(dut.rvalid) break; step(); }
    check(dut.rvalid,"AXI stalled read data timeout");
    uint32_t held=dut.rdata;
    for(int i=0;i<8;i++) { step(); check(dut.rvalid && dut.rdata==held,"AXI read changed under stall"); }
    dut.rready=1; step(); dut.rready=0;
    reset();
}
static void send_beat(uint64_t data,bool last,int gap=0) {
    dut.s_tvalid=0; for(int i=0;i<gap;i++) step();
    dut.s_tdata=data; dut.s_tlast=last; dut.s_tvalid=1;
    for(int i=0;i<100000;i++) { dut.clk=0; dut.eval(); bool accepted=dut.s_tready; step(); if(accepted) { dut.s_tvalid=0; dut.s_tlast=0; return; } }
    throw std::runtime_error("input stream timeout");
}
static int code(int row,int depth,int salt) {
    if(precision_mode) return salt==1 ? precision_q[row*D+depth] : precision_k[row*D+depth];
    if(legacy_mode) {
        static const int pattern[4][4]={{2,0,2,0},{0,2,0,2},{2,2,0,0},{0,0,2,2}};
        return pattern[row][depth];
    }
    if(extreme_mode) return (salt==5 && extreme_mode==2) ? 15 : 7;
    if(pattern_seed) {
        uint32_t x=pattern_seed ^ uint32_t(row*0x9e3779b9u) ^
                   uint32_t(depth*0x85ebca6bu) ^ uint32_t(salt*0xc2b2ae35u);
        x^=x>>16; x*=0x7feb352du; x^=x>>15;
        return int(x&15);
    }
    return (row*7+depth*3+salt)%16;
}
static float qscale(int row,int block=0) {
    if(precision_mode) return precision_qscale[row*BLOCKS+block];
    if(legacy_mode) return 1.0f;
    if(varied_scales) { static const float v[]={.25f,1.25f,-1.0f,0.0f}; return v[(row+block)%4]; }
    return (row+block)%2 ? 2.0f:1.0f;
}
static float kscale(int row,int block=0) {
    if(precision_mode) return precision_kscale[row*BLOCKS+block];
    if(legacy_mode) return 1.0f;
    if(varied_scales) { static const float v[]={1.5f,-.5f,2.0f,.75f}; return v[(row+block)%4]; }
    return (row+block)%2 ? .5f:1.0f;
}
static void send_scales(int t, int malformed=0) {
    for(int b=0;b<t*BLOCKS;b++) {
        // Scale order is Q[0..T-1], then K[0..T-1].
        auto value=[&](int idx)->uint32_t {
            return bits(idx<t*BLOCKS ? qscale(idx/BLOCKS,idx%BLOCKS) :
                kscale((idx-t*BLOCKS)/BLOCKS,(idx-t*BLOCKS)%BLOCKS));
        };
        uint32_t lo=value(2*b), hi=value(2*b+1);
        send_beat((uint64_t(hi)<<32)|lo,
                  malformed==1 ? b==0 : (malformed==2 ? false : b==t*BLOCKS-1), STRESS_STALLS ? b%3 : 0);
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
static void send_bad_tile(bool early) {
    int beats=(B*D+15)/16;
    for(int b=0;b<beats;b++) {
        send_beat(0,early && b==0);
        if(early) return;
    }
}
static float expected(int row,int col) {
    if(precision_mode) return flt(precision_scores[row*TMAX+col]);
    float score=0.0f;
    for(int block=0;block<BLOCKS;block++) {
        int sum=0, stop=std::min(D,(block+1)*BS);
        for(int d=block*BS;d<stop;d++)
            sum+=half(code(row,d,1))*half(code(col,d,5));
        score+=(sum*0.25f)*qscale(row,block)*kscale(col,block);
    }
    return score;
}
struct StreamBeat { uint64_t data; bool last; int gap; };
static void append_scales(std::vector<StreamBeat>& stream,int t) {
    for(int b=0;b<t*BLOCKS;b++) {
        auto value=[&](int idx)->uint32_t {
            return bits(idx<t*BLOCKS ? qscale(idx/BLOCKS,idx%BLOCKS) :
                kscale((idx-t*BLOCKS)/BLOCKS,(idx-t*BLOCKS)%BLOCKS));
        };
        stream.push_back({(uint64_t(value(2*b+1))<<32)|value(2*b),b==t*BLOCKS-1,
                          STRESS_STALLS ? b%3 : 0});
    }
}
static void append_tile(std::vector<StreamBeat>& stream,int start,int t,int salt) {
    constexpr int N=B*D;
    for(int b=0;b<(N+15)/16;b++) {
        uint64_t beat=0;
        for(int lane=0;lane<16;lane++) {
            int element=b*16+lane;
            if(element<N && start+element/D<t)
                beat|=uint64_t(code(start+element/D,element%D,salt))<<(4*lane);
        }
        stream.push_back({beat,b==(N+15)/16-1,STRESS_STALLS ? b%4 : 0});
    }
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
                if(bits(actual)!=bits(want)) {
                    std::fprintf(stderr,"score (%d,%d): got %f [%08x] want %f [%08x]\n",
                                 row,col,actual,bits(actual),want,bits(want));
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
    std::vector<StreamBeat> stream;
    append_scales(stream,t);
    if(REUSE) for(int kc=0;kc<t;kc+=B) append_tile(stream,kc,t,5);
    for(int qr=0;qr<t;qr+=B) {
        append_tile(stream,qr,t,1);
        if(!REUSE) for(int kc=0;kc<t;kc+=B) append_tile(stream,kc,t,5);
    }

    size_t input_index=0; int input_gap=stream.empty()?0:stream[0].gap;
    int checked=0, tiles=0, qr=0, kc=0, tile_got=0;
    bool stalled=false, forced_output_stall=!STRESS_STALLS;
    uint64_t held=0; bool held_last=false;
    for(int timeout=0;timeout<100000000 && checked<t*t;timeout++) {
        if(input_index<stream.size() && input_gap==0) {
            dut.s_tvalid=1; dut.s_tdata=stream[input_index].data;
            dut.s_tlast=stream[input_index].last;
        } else dut.s_tvalid=0;
        dut.m_tready=forced_output_stall && (!STRESS_STALLS || (timeout%5>=2));
        dut.clk=0; dut.eval();
        bool input_transfer=dut.s_tvalid && dut.s_tready;
        if(stalled)
            check(dut.m_tvalid && dut.m_tdata==held && bool(dut.m_tlast)==held_last,
                  "output changed under backpressure");
        int rows=std::min(B,t-qr), cols=std::min(B,t-kc), count=rows*cols;
        bool output_transfer=dut.m_tvalid && dut.m_tready;
        if(dut.m_tvalid) {
            held=dut.m_tdata; held_last=dut.m_tlast;
            check(bool(dut.m_tlast)==(tile_got+2>=count),"TLAST wrong");
        }
        stalled=dut.m_tvalid && !dut.m_tready;
        step();
        if(stalled) forced_output_stall=true;
        if(input_transfer) {
            input_index++;
            if(input_index<stream.size()) input_gap=stream[input_index].gap;
            dut.s_tvalid=0; dut.s_tlast=0;
        } else if(input_gap>0) input_gap--;
        if(output_transfer) {
            if(tile_got+1==count) check(uint32_t(held>>32)==0,"final output padding");
            for(int lane=0;lane<2 && tile_got<count;lane++,tile_got++) {
                int row=qr+tile_got/cols, col=kc+tile_got%cols;
                float actual=flt(uint32_t(held>>(32*lane))), want=expected(row,col);
                if(bits(actual)!=bits(want)) {
                    std::fprintf(stderr,"score (%d,%d): got %f [%08x] want %f [%08x]\n",
                                 row,col,actual,bits(actual),want,bits(want));
                    throw std::runtime_error("score mismatch");
                }
                if(precision_mode) {
                    double reference=flt(precision_reference[row*TMAX+col]);
                    double difference=double(actual)-reference;
                    precision_diff_sq+=difference*difference;
                    precision_ref_sq+=reference*reference;
                    precision_abs+=std::fabs(difference);
                }
                checked++;
            }
            if(tile_got==count) {
                tiles++; tile_got=0; kc+=B;
                if(kc>=t) { kc=0; qr+=B; }
            }
        }
    }
    dut.s_tvalid=0; dut.m_tready=0;
    check(input_index==stream.size(),"input stream incomplete");
    check(checked==t*t,"score count");
    for(int i=0;i<100 && !(read_reg(0x04)&1);i++) step();
    check(read_reg(0x04)==1,"completion or error status");
    check(read_reg(0x0C)==uint32_t(tiles),"tile count");
    int n=(t+B-1)/B;
    int input_beats=t*BLOCKS+(REUSE ? 2*n : n+n*n)*((B*D+15)/16);
    check(read_reg(0x20)==uint32_t(input_beats),"input beat count");
    int output_beats=0;
    for(int qr=0;qr<t;qr+=B)
        for(int kc=0;kc<t;kc+=B)
            output_beats+=(std::min(B,t-qr)*std::min(B,t-kc)+1)/2;
    check(read_reg(0x24)==uint32_t(output_beats),"output beat count");
    if(STRESS_STALLS && t>1) check(read_reg(0x28)>0,"input stalls absent");
    if(STRESS_STALLS) check(read_reg(0x2C)>0,"output stalls absent");
    check(read_reg(0x30)==uint32_t(tiles*D),"compute cycles");
    uint32_t core_cycles=read_reg(0x10);
    if(!STRESS_STALLS && !REUSE && B==4 && D==64 && t==512)
        check(core_cycles<=1049665,"4x4 T=512 cycle regression");
    std::printf("T=%d D=%d scores=%d tiles=%d cycles=%u in_beats=%u out_beats=%u stalls=%u PASS\n",
        t,D,checked,tiles,core_cycles,read_reg(0x20),read_reg(0x24),read_reg(0x2C));
}
int main(int argc,char** argv) {
    Verilated::commandArgs(argc,argv);
    try {
#ifdef TEST_PRECISION
        check(argc>=2,"precision capture path missing");
        std::FILE* capture=std::fopen(argv[1],"rb");
        check(capture!=nullptr,"precision capture open failed");
        uint32_t header[3];
        check(std::fread(header,sizeof(uint32_t),3,capture)==3,"precision header");
        check(header[0]==uint32_t(TMAX) && header[1]==uint32_t(D) &&
              header[2]==uint32_t(BLOCKS),"precision capture shape");
        precision_qscale.resize(TMAX*BLOCKS); precision_kscale.resize(TMAX*BLOCKS);
        precision_q.resize(TMAX*D); precision_k.resize(TMAX*D);
        precision_scores.resize(TMAX*TMAX); precision_reference.resize(TMAX*TMAX);
        check(std::fread(precision_qscale.data(),sizeof(float),precision_qscale.size(),capture)==precision_qscale.size(),"Q scales");
        check(std::fread(precision_kscale.data(),sizeof(float),precision_kscale.size(),capture)==precision_kscale.size(),"K scales");
        check(std::fread(precision_q.data(),1,precision_q.size(),capture)==precision_q.size(),"Q codes");
        check(std::fread(precision_k.data(),1,precision_k.size(),capture)==precision_k.size(),"K codes");
        check(std::fread(precision_scores.data(),sizeof(uint32_t),precision_scores.size(),capture)==precision_scores.size(),"model scores");
        check(std::fread(precision_reference.data(),sizeof(uint32_t),precision_reference.size(),capture)==precision_reference.size(),"reference scores");
        std::fclose(capture); precision_mode=true;
        reset(); check(read_reg(0x1C)==3,"stream version"); run_case(TMAX);
        std::printf("RTL_RELATIVE_FROBENIUS=%.9f RTL_MEAN_ABS_ERROR=%.9f\n",
            std::sqrt(precision_diff_sq/precision_ref_sq),precision_abs/(TMAX*TMAX));
        return 0;
#endif
        reset(); check(read_reg(0x1C)==(REUSE?4:3),"stream version");
        write_data_first(0x08,4);
        check(read_reg(0x08)==4,"AXI W-before-AW value");
        write_reg(0x08,0x00000100,0x2);
        check(read_reg(0x08)==0x104,"AXI write strobes");
        write_together(0x08,4);
        check(read_reg(0x08)==4,"AXI simultaneous channels");
        check_read_stall();
#ifdef TEST_LARGE
        run_case(64); run_case(128); run_case(512);
#else
        run_case(1); run_case(4); run_case(7); run_case(8); run_case(16);
        varied_scales=true;
        for(uint32_t seed=1;seed<=3;seed++) { pattern_seed=seed; run_case(7); }
        pattern_seed=0; varied_scales=false;
        if(D==64) {
            extreme_mode=1; run_case(4);
            extreme_mode=2; run_case(4);
            extreme_mode=0;
        }
        if(D==4 && B==4) { legacy_mode=true; run_case(4); legacy_mode=false; }
        write_reg(0x08,4); write_reg(0x00,1); send_scales(4,1);
        check(read_reg(0x04)==0x21,"early TLAST status");
        write_reg(0x08,4); write_reg(0x00,1); send_scales(4,2);
        check(read_reg(0x04)==0x31,"missing TLAST status");
        write_reg(0x08,4); write_reg(0x00,1); send_scales(4);
        if(B*D>16) {
            send_bad_tile(true);
            check(read_reg(0x04)==0x21,"early tile TLAST status");
            write_reg(0x08,4); write_reg(0x00,1); send_scales(4);
        }
        send_bad_tile(false);
        check(read_reg(0x04)==0x31,"missing tile TLAST status");
        write_reg(0x08,4); write_reg(0x00,1); send_scales(4);
        send_tile(0,4,REUSE?5:1);
        send_bad_tile(false);
        check(read_reg(0x04)==0x31,"missing second tile TLAST status");
        write_reg(0x08,4); write_reg(0x00,1);
        send_beat(uint64_t(bits(1.0f)),false);
        reset(); run_case(4);
        write_reg(0x08,TMAX+1); write_reg(0x00,1);
        check(read_reg(0x04)==0x11,"dimension error status");
#endif
        std::puts("ALL PASS"); return 0;
    } catch(const std::exception& e) { std::fprintf(stderr,"FAIL: %s at cycle %llu\n",e.what(),(unsigned long long)cycles); return 1; }
}
