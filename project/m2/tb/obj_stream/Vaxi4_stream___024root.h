// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaxi4_stream.h for the primary calling header

#ifndef VERILATED_VAXI4_STREAM___024ROOT_H_
#define VERILATED_VAXI4_STREAM___024ROOT_H_  // guard

#include "verilated.h"


class Vaxi4_stream__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaxi4_stream___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(s_tvalid,0,0);
    VL_OUT8(s_tready,0,0);
    VL_IN8(s_tlast,0,0);
    VL_OUT8(m_tvalid,0,0);
    VL_IN8(m_tready,0,0);
    VL_OUT8(m_tlast,0,0);
    VL_IN8(start,0,0);
    VL_OUT8(done,0,0);
    CData/*2:0*/ axi4_stream__DOT__state;
    CData/*0:0*/ axi4_stream__DOT__core_valid;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ axi4_stream__DOT__recv_count;
    IData/*31:0*/ axi4_stream__DOT__send_count;
    IData/*31:0*/ axi4_stream__DOT__unnamedblk3__DOT__i;
    IData/*31:0*/ axi4_stream__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ axi4_stream__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VL_IN64(s_tdata,63,0);
    VL_OUT64(m_tdata,63,0);
    VlUnpacked<IData/*31:0*/, 4> axi4_stream__DOT__q_buf;
    VlUnpacked<IData/*31:0*/, 4> axi4_stream__DOT__k_buf;
    VlUnpacked<IData/*31:0*/, 4> axi4_stream__DOT__a_out;
    VlUnpacked<IData/*31:0*/, 4> axi4_stream__DOT__b_out;
    VlUnpacked<IData/*31:0*/, 16> axi4_stream__DOT__score_buf;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vaxi4_stream__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vaxi4_stream___024root(Vaxi4_stream__Syms* symsp, const char* v__name);
    ~Vaxi4_stream___024root();
    VL_UNCOPYABLE(Vaxi4_stream___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
