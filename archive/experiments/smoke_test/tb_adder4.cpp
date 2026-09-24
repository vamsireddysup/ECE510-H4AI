#include "Vadder4.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vadder4* dut = new Vadder4;

    int pass = 0, fail = 0;

    for (int a = 0; a < 16; a++) {
        for (int b = 0; b < 16; b++) {
            dut->a   = a;
            dut->b   = b;
            dut->cin = 0;
            dut->eval();

            int expected     = a + b;
            int got_sum      = dut->sum;
            int got_cout     = dut->cout;
            int got_full     = (got_cout << 4) | got_sum;

            if (got_full == expected) {
                pass++;
            } else {
                std::cout << "FAIL: a=" << a << " b=" << b
                          << " expected=" << expected
                          << " got=" << got_full << std::endl;
                fail++;
            }
        }
    }

    std::cout << "Results: " << pass << " passed, " << fail << " failed" << std::endl;
    if (fail == 0) std::cout << "SMOKE TEST PASSED" << std::endl;

    delete dut;
    return fail != 0;
}
