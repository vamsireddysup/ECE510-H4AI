/*
 * tb_chiplet_top.cpp -- End-to-end co-simulation testbench v2
 *
 * Fixed: wait for m_tvalid before capturing output scores.
 * Fixed: poll STATUS after receiving all data.
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vqkt_chiplet_top.h"
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>

static const int TILE_SIZE   = 4;
static const int D_HEAD      = 4;
static const int MATRIX_SIZE = 4;
static const int MAX_CYCLES  = 10000;

static Vqkt_chiplet_top *dut;
static VerilatedVcdC    *vcd;
static uint64_t          sim_time = 0;

void tick() {
    dut->clk = 0; dut->eval();
    vcd->dump(sim_time++);
    dut->clk = 1; dut->eval();
    vcd->dump(sim_time++);
}

void reset() {
    dut->rst_n   = 0;
    dut->awvalid = 0; dut->wvalid  = 0; dut->bready  = 0;
    dut->arvalid = 0; dut->rready  = 0;
    dut->s_tvalid = 0; dut->s_tdata = 0; dut->s_tlast = 0;
    dut->m_tready = 0;
    for (int i = 0; i < 5; i++) tick();
    dut->rst_n = 1;
    tick();
}

void axi_write(uint32_t addr, uint32_t data) {
    dut->awvalid = 1; dut->awaddr = addr;
    dut->wvalid  = 1; dut->wdata  = data; dut->wstrb = 0xF;
    dut->bready  = 1;
    bool aw_done = false, w_done = false;
    for (int i = 0; i < 100; i++) {
        tick();
        if (dut->awready) { dut->awvalid = 0; aw_done = true; }
        if (dut->wready)  { dut->wvalid  = 0; w_done  = true; }
        if (aw_done && w_done) break;
    }
    for (int i = 0; i < 100 && !dut->bvalid; i++) tick();
    tick();
    dut->bready = 0;
}

uint32_t axi_read(uint32_t addr) {
    dut->arvalid = 1; dut->araddr = addr;
    dut->rready  = 1;
    for (int i = 0; i < 100; i++) {
        tick();
        if (dut->arready) { dut->arvalid = 0; break; }
    }
    for (int i = 0; i < 100 && !dut->rvalid; i++) tick();
    uint32_t val = dut->rdata;
    tick();
    dut->rready = 0;
    return val;
}

void stream_send(uint64_t data, bool last) {
    dut->s_tvalid = 1;
    dut->s_tdata  = data;
    dut->s_tlast  = last ? 1 : 0;
    for (int i = 0; i < 500; i++) {
        tick();
        if (dut->s_tready) break;
    }
    dut->s_tvalid = 0;
    dut->s_tlast  = 0;
    // Extra ticks to allow FSM to advance to next state
    for (int i = 0; i < 5; i++) tick();
}

float bits_to_float(uint32_t b) {
    float f; memcpy(&f, &b, 4); return f;
}
uint32_t float_to_bits(float f) {
    uint32_t b; memcpy(&b, &f, 4); return b;
}

uint8_t fp4_encode(float v) {
    static const float lut[8] = {0.0f,0.5f,1.0f,1.5f,2.0f,3.0f,4.0f,6.0f};
    bool neg = v < 0; float av = fabsf(v);
    int best = 0; float bd = 1e9f;
    for (int i = 0; i < 8; i++) {
        float d = fabsf(av - lut[i]);
        if (d < bd) { bd = d; best = i; }
    }
    return neg ? (0x8 | best) : best;
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    dut = new Vqkt_chiplet_top;
    vcd = new VerilatedVcdC;
    dut->trace(vcd, 99);
    vcd->open("chiplet_top_wave.vcd");

    printf("============================================\n");
    printf("QK^T Chiplet End-to-End Co-Simulation\n");
    printf("TILE_SIZE=%d D_HEAD=%d T=%d\n", TILE_SIZE, D_HEAD, MATRIX_SIZE);
    printf("============================================\n\n");

    reset();

    // Step 1: configure
    printf("Step 1: AXI4-Lite MATRIX_SIZE=%d\n", MATRIX_SIZE);
    axi_write(0x08, MATRIX_SIZE);
    uint32_t ms = axi_read(0x08);
    printf("        Read back=0x%08X (%s)\n", ms,
           ms == (uint32_t)MATRIX_SIZE ? "OK" : "FAIL");

    // Step 2: START
    printf("Step 2: AXI4-Lite START\n");
    axi_write(0x00, 0x1);

    // Step 3: scale factors (2*T FP32 values, all 1.0)
    printf("Step 3: Stream scale factors\n");
    uint32_t one = float_to_bits(1.0f);
    for (int i = 0; i < 2 * MATRIX_SIZE; i++) {
        uint64_t word = ((uint64_t)one << 32) | one;
        stream_send(word, i == 2*MATRIX_SIZE-1);
    }
    printf("        Done\n");

    // Step 4: Q tile
    float Q[TILE_SIZE][D_HEAD] = {
        {1.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 1.0f},
        {1.0f, 1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 1.0f}
    };
    printf("Step 4: Stream Q tile\n");
    for (int i = 0; i < TILE_SIZE; i++)
        for (int d = 0; d < D_HEAD; d++) {
            uint8_t enc = fp4_encode(Q[i][d]);
            stream_send(enc, i==TILE_SIZE-1 && d==D_HEAD-1);
        }
    printf("        Done\n");

    // Step 5: K tile
    float K[TILE_SIZE][D_HEAD] = {
        {1.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 1.0f},
        {1.0f, 1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 1.0f}
    };
    printf("Step 5: Stream K tile\n");
    for (int i = 0; i < TILE_SIZE; i++)
        for (int d = 0; d < D_HEAD; d++) {
            uint8_t enc = fp4_encode(K[i][d]);
            stream_send(enc, i==TILE_SIZE-1 && d==D_HEAD-1);
        }
    printf("        Done\n");

    // Step 6: wait for m_tvalid then receive scores
    printf("Step 6: Waiting for output scores...\n");
    dut->m_tready = 1;

    float expected[TILE_SIZE][TILE_SIZE] = {};
    for (int i = 0; i < TILE_SIZE; i++)
        for (int j = 0; j < TILE_SIZE; j++)
            for (int d = 0; d < D_HEAD; d++)
                expected[i][j] += Q[i][d] * K[j][d];

    printf("Expected QK^T:\n");
    for (int i = 0; i < TILE_SIZE; i++) {
        printf("  [");
        for (int j = 0; j < TILE_SIZE; j++)
            printf("%5.1f%s", expected[i][j], j<TILE_SIZE-1?", ":"");
        printf("]\n");
    }

    // Wait until m_tvalid goes high (computation complete)
    int wait_cycles = 0;
    for (wait_cycles = 0; wait_cycles < MAX_CYCLES; wait_cycles++) {
        tick();
        if (dut->m_tvalid) break;
    }
    printf("        m_tvalid high after %d cycles\n", wait_cycles);

    // Wait one more cycle for m_tdata to be registered with valid data
    tick();

    // Capture output
    int received = 0, pass_count = 0;
    float results[TILE_SIZE][TILE_SIZE] = {};

    for (int timeout = 0; received < TILE_SIZE*TILE_SIZE && timeout < MAX_CYCLES; timeout++) {
        // Sample before tick so we don't miss the current beat
        if (dut->m_tvalid && dut->m_tready) {
            uint32_t hi = (uint32_t)(dut->m_tdata >> 32);
            uint32_t lo = (uint32_t)(dut->m_tdata & 0xFFFFFFFF);
            float val_hi = bits_to_float(hi);
            float val_lo = bits_to_float(lo);
            printf("  [TB] recv[%d] m_tdata=0x%016llX hi=%.2f lo=%.2f\n",
                   received, (unsigned long long)dut->m_tdata, val_hi, val_lo);
            int row = received / TILE_SIZE;
            int col = received % TILE_SIZE;
            results[row][col] = val_hi;
            received++;
            if (received >= TILE_SIZE*TILE_SIZE) break;
        }
        tick();
    }
    dut->m_tready = 0;

    printf("\nReceived QK^T:\n");
    for (int i = 0; i < TILE_SIZE; i++) {
        printf("  [");
        for (int j = 0; j < TILE_SIZE; j++) {
            float err = fabsf(results[i][j] - expected[i][j]);
            if (err < 0.01f) pass_count++;
            printf("%5.1f%s", results[i][j], j<TILE_SIZE-1?", ":"");
        }
        printf("]\n");
    }

    // Step 7: poll STATUS
    printf("\nStep 7: Poll STATUS\n");
    uint32_t status     = axi_read(0x04);
    uint32_t tile_cnt   = axi_read(0x0C);
    uint32_t cycle_cnt  = axi_read(0x10);
    printf("        STATUS=0x%08X DONE=%s\n", status, (status&1)?"YES":"NO");
    printf("        TILE_COUNT=%d CYCLE_COUNT=%d\n", tile_cnt, cycle_cnt);

    printf("\n============================================\n");
    printf("Results: %d/%d elements correct\n", pass_count, TILE_SIZE*TILE_SIZE);
    if (pass_count == TILE_SIZE*TILE_SIZE)
        printf("ALL PASS -- End-to-end AXI co-simulation verified\n");
    else
        printf("FAIL -- check chiplet_top_wave.vcd\n");
    printf("============================================\n");

    vcd->close();
    delete dut; delete vcd;
    return (pass_count == TILE_SIZE*TILE_SIZE) ? 0 : 1;
}
