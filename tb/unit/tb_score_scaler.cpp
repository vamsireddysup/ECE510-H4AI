// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
// Unit check for score_scaler's two scale formats against a reference computed
// in double precision.
//
// FP32 (SCALE_FORMAT 0) must reproduce two chained single-precision roundings,
// because that is what the two fp32_mul instances do and what every recorded
// score depends on. E4M3 (SCALE_FORMAT 1) must be exact: a 13-bit accumulator
// times two 4-bit significands needs 20 bits, inside FP32's 24, so there is
// nothing to round. See ADR 0008.
#include "Vscore_scaler.h"
#include "verilated.h"

#include <cmath>
#include <cstdio>
#include <cstring>
#include <random>
#include <vector>

static Vscore_scaler dut;

static void step() {
    dut.clk = 0;
    dut.eval();
    dut.clk = 1;
    dut.eval();
}

static uint32_t bits(float value) {
    uint32_t raw;
    std::memcpy(&raw, &value, 4);
    return raw;
}

static float flt(uint32_t raw) {
    float value;
    std::memcpy(&value, &raw, 4);
    return value;
}

// E4M3: 4-bit exponent with bias 7, 3-bit mantissa. Only normals are used.
static double e4m3(int code) {
    const int exponent = (code >> 3) & 0xF;
    const int mantissa = code & 0x7;
    if (exponent == 0) {
        return (mantissa / 8.0) * std::pow(2.0, -6);
    }
    return (1.0 + mantissa / 8.0) * std::pow(2.0, exponent - 7);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    dut.rst_n = 0;
    dut.launch_valid = 0;
    for (int i = 0; i < 4; i++) step();
    dut.rst_n = 1;
    step();

    std::mt19937 rng(20260930);
    const int accumulator_max = (1 << (ACC_W - 1)) - 1;
    std::vector<int> codes;
    for (int exponent = 1; exponent < 15; exponent++) {
        for (int mantissa = 0; mantissa < 8; mantissa++) {
            codes.push_back((exponent << 3) | mantissa);
        }
    }

    int checks = 0;
    int failures = 0;
    for (int trial = 0; trial < 4000; trial++) {
        const int accumulator =
            static_cast<int>(rng() % (2 * accumulator_max + 1)) - accumulator_max;
        double q_value;
        double k_value;
        if (SCALE_FORMAT == 1) {
            const int q_code = codes[rng() % codes.size()];
            const int k_code = codes[rng() % codes.size()];
            q_value = e4m3(q_code);
            k_value = e4m3(k_code);
            dut.q_scale_in = q_code;
            dut.k_scale_in = k_code;
        } else {
            const float q = static_cast<float>((rng() % 4000 + 1) / 1000.0);
            const float k = static_cast<float>((rng() % 4000 + 1) / 1000.0);
            q_value = q;
            k_value = k;
            dut.q_scale_in = bits(q);
            dut.k_scale_in = bits(k);
        }

        float want;
        if (SCALE_FORMAT == 1) {
            // One exact product, rounded once on the way into FP32.
            want = static_cast<float>(accumulator / 4.0 * q_value * k_value);
        } else {
            // Two roundings, matching the two chained multipliers.
            const float first =
                static_cast<float>(accumulator / 4.0f) * static_cast<float>(q_value);
            want = first * static_cast<float>(k_value);
        }

        dut.acc_in = accumulator & ((1 << ACC_W) - 1);
        dut.launch_valid = 1;
        step();
        dut.launch_valid = 0;
        for (int i = 0; i < 10 && !dut.result_valid; i++) step();
        if (!dut.result_valid) {
            if (failures < 4) printf("no result for acc=%d\n", accumulator);
            failures++;
            continue;
        }
        checks++;
        const uint32_t got = dut.result;
        // Both paths flush subnormal and overflowed results to zero.
        const bool flushed = std::fabs(static_cast<double>(want)) < 1.2e-38;
        if (flushed) {
            if (got != 0) {
                if (failures < 4)
                    printf("expected flush, acc=%d got=%g\n", accumulator, flt(got));
                failures++;
            }
        } else if (got != bits(want)) {
            if (failures < 5) {
                printf("acc=%d q=%.9g k=%.9g got=%.9g want=%.9g\n", accumulator,
                       q_value, k_value, flt(got), want);
            }
            failures++;
        }
        for (int i = 0; i < 4; i++) step();
    }

    printf("%s: %d checks, %d mismatches\n", SCALE_FORMAT == 1 ? "E4M3" : "FP32",
           checks, failures);
    if (checks == 0) {
        printf("FAIL: no checks ran\n");
        return 1;
    }
    if (failures != 0) return 1;
    printf("ALL PASS\n");
    return 0;
}
