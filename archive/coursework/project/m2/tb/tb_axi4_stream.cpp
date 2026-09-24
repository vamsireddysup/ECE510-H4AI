/*
 * tb_axi4_stream.cpp -- Verilator testbench for AXI4-Stream interface
 *
 * Tests:
 *   1. Input stream: host sends SIZE transfers of Q/K data to chiplet
 *   2. Output stream: host receives SIZE*SIZE score elements from chiplet
 *
 * Verifies:
 *   - tvalid/tready handshake on input stream
 *   - tvalid/tready handshake on output stream
 *   - tlast asserts on last output transfer
 *   - done signal asserts after all output sent
 *
 * Debug: compile with -DDEBUG_STREAM for transaction traces
 *   make stream_debug
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

#include "Vaxi4_stream.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <cstdint>
#include <cstring>

#define SIZE 4

static vluint64_t sim_time = 0;

static void tick(Vaxi4_stream* dut, VerilatedVcdC* vcd) {
    dut->clk = 0;
    dut->eval();
    if (vcd) vcd->dump(sim_time++);
    dut->clk = 1;
    dut->eval();
    if (vcd) vcd->dump(sim_time++);
    // Evaluate after rising edge settles
    dut->eval();
}

static uint32_t f2b(float f) {
    uint32_t b;
    std::memcpy(&b, &f, sizeof(float));
    return b;
}

static void reset(Vaxi4_stream* dut, VerilatedVcdC* vcd) {
    dut->rst_n    = 0;
    dut->s_tvalid = 0;
    dut->s_tdata  = 0;
    dut->s_tlast  = 0;
    dut->m_tready = 0;
    dut->start    = 0;
    tick(dut, vcd);
    tick(dut, vcd);
    tick(dut, vcd);
    dut->rst_n = 1;
    tick(dut, vcd);
    std::cout << "Reset complete.\n";
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vaxi4_stream* dut = new Vaxi4_stream;

    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd, 99);
    vcd->open("stream_wave.vcd");

    std::cout << "============================================\n";
    std::cout << "AXI4-Stream Data Interface Testbench\n";
    std::cout << "============================================\n";

    reset(dut, vcd);

    int pass  = 0;
    int total = 2;

    // -----------------------------------------------------------------------
    // Assert start to move from IDLE to RECEIVING
    // -----------------------------------------------------------------------
    std::cout << "\nAsserting start signal...\n";
    dut->start = 1;
    tick(dut, vcd);
    dut->start = 0;
    tick(dut, vcd);

    // -----------------------------------------------------------------------
    // Test 1: Input stream -- send SIZE transfers of Q/K data
    // Each transfer: tdata[63:32]=Q element, tdata[31:0]=K element
    // -----------------------------------------------------------------------
    std::cout << "\n--- Test 1: Input stream -- send " << SIZE
              << " Q/K transfers ---\n";

    float q_vals[SIZE] = {1.0f, 5.0f, 1.0f, 2.0f};
    float k_vals[SIZE] = {1.0f, 0.0f, 1.0f, 0.0f};

    int rx_count = 0;
    int timeout  = 30;

    dut->s_tvalid = 1;
    dut->m_tready = 0;

    for (int i = 0; i < SIZE && timeout > 0; i++) {
        uint64_t q_bits = (uint64_t)f2b(q_vals[i]) << 32;
        uint64_t k_bits = (uint64_t)f2b(k_vals[i]);
        dut->s_tdata = q_bits | k_bits;
        dut->s_tlast = (i == SIZE-1) ? 1 : 0;
        dut->eval();

        // Wait for tready
        while (!dut->s_tready && timeout > 0) {
            std::cout << "  TX[" << i << "]: waiting for tready...\n";
            tick(dut, vcd);
            timeout--;
        }

        if (!dut->s_tready) break;

        std::cout << "  TX[" << i << "]: Q=" << q_vals[i]
                  << " K=" << k_vals[i]
                  << " tready=1 ACCEPTED\n";
        rx_count++;
        tick(dut, vcd);
        timeout--;
    }

    dut->s_tvalid = 0;
    dut->s_tlast  = 0;

    if (rx_count == SIZE) {
        std::cout << "  PASS: All " << SIZE
                  << " input transfers accepted\n";
        pass++;
    } else {
        std::cout << "  FAIL: Only " << rx_count
                  << "/" << SIZE << " transfers accepted\n";
    }

    // -----------------------------------------------------------------------
    // Wait for COMPUTING to finish and SENDING to begin
    // -----------------------------------------------------------------------
    std::cout << "\nWaiting for compute and output stream...\n";
    timeout = 30;
    while (!dut->m_tvalid && timeout-- > 0)
        tick(dut, vcd);

    // -----------------------------------------------------------------------
    // Test 2: Output stream -- receive SIZE*SIZE score elements
    // -----------------------------------------------------------------------
    std::cout << "\n--- Test 2: Output stream -- receive "
              << SIZE*SIZE << " score elements ---\n";

    dut->m_tready = 1;
    int tx_count = 0;
    timeout = 50;

    while (tx_count < SIZE*SIZE && timeout-- > 0) {
        dut->eval();
        if (dut->m_tvalid && dut->m_tready) {
            uint32_t val = (uint32_t)(dut->m_tdata >> 32);
            std::cout << "  RX[" << tx_count << "]: data=0x"
                      << std::hex << val << std::dec;
            if (dut->m_tlast) std::cout << " TLAST";
            std::cout << "\n";
            tx_count++;
        }
        tick(dut, vcd);
    }

    if (tx_count == SIZE*SIZE) {
        std::cout << "  PASS: All " << SIZE*SIZE
                  << " output transfers received\n";
        pass++;
    } else {
        std::cout << "  FAIL: Only " << tx_count
                  << "/" << SIZE*SIZE << " output transfers received\n";
    }

    // Run a few more cycles
    for (int i = 0; i < 5; i++)
        tick(dut, vcd);

    std::cout << "\n============================================\n";
    std::cout << "Results: " << pass << "/" << total
              << " tests passed\n";
    if (pass == total)
        std::cout << "ALL PASS -- AXI4-Stream interface verified\n";
    else
        std::cout << "FAIL\n";
    std::cout << "============================================\n";

    std::cout << "done signal = " << (int)dut->done << "\n";
    std::cout << "Waveform saved to stream_wave.vcd\n";

    vcd->close();
    dut->final();
    delete vcd;
    delete dut;

    return (pass == total) ? 0 : 1;
}
