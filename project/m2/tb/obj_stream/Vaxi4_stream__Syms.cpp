// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vaxi4_stream__pch.h"
#include "Vaxi4_stream.h"
#include "Vaxi4_stream___024root.h"

// FUNCTIONS
Vaxi4_stream__Syms::~Vaxi4_stream__Syms()
{
}

Vaxi4_stream__Syms::Vaxi4_stream__Syms(VerilatedContext* contextp, const char* namep, Vaxi4_stream* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(56);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
