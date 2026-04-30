// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array__Syms.h"
#include "Vsystolic_array_pe.h"

void Vsystolic_array_pe___ctor_var_reset(Vsystolic_array_pe* vlSelf);

Vsystolic_array_pe::Vsystolic_array_pe(Vsystolic_array__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsystolic_array_pe___ctor_var_reset(this);
}

void Vsystolic_array_pe::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsystolic_array_pe::~Vsystolic_array_pe() {
}
