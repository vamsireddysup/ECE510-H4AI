// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfp4_mul.h for the primary calling header

#ifndef VERILATED_VFP4_MUL___024ROOT_H_
#define VERILATED_VFP4_MUL___024ROOT_H_  // guard

#include "verilated.h"


class Vfp4_mul__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfp4_mul___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(a,3,0);
    VL_IN8(b,3,0);
    VL_IN8(valid_in,0,0);
    VL_OUT8(valid_out,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT(result,31,0);
    IData/*31:0*/ fp4_mul__DOT__lut_result;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfp4_mul__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfp4_mul___024root(Vfp4_mul__Syms* symsp, const char* v__name);
    ~Vfp4_mul___024root();
    VL_UNCOPYABLE(Vfp4_mul___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
