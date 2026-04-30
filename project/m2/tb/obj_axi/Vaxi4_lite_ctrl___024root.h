// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaxi4_lite_ctrl.h for the primary calling header

#ifndef VERILATED_VAXI4_LITE_CTRL___024ROOT_H_
#define VERILATED_VAXI4_LITE_CTRL___024ROOT_H_  // guard

#include "verilated.h"


class Vaxi4_lite_ctrl__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaxi4_lite_ctrl___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(awvalid,0,0);
    VL_OUT8(awready,0,0);
    VL_IN8(wvalid,0,0);
    VL_OUT8(wready,0,0);
    VL_IN8(wstrb,3,0);
    VL_OUT8(bvalid,0,0);
    VL_IN8(bready,0,0);
    VL_OUT8(bresp,1,0);
    VL_IN8(arvalid,0,0);
    VL_OUT8(arready,0,0);
    VL_OUT8(rvalid,0,0);
    VL_IN8(rready,0,0);
    VL_OUT8(rresp,1,0);
    VL_OUT8(start,0,0);
    VL_IN8(done,0,0);
    CData/*1:0*/ axi4_lite_ctrl__DOT__wstate;
    CData/*1:0*/ axi4_lite_ctrl__DOT__rstate;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(awaddr,31,0);
    VL_IN(wdata,31,0);
    VL_IN(araddr,31,0);
    VL_OUT(rdata,31,0);
    IData/*31:0*/ axi4_lite_ctrl__DOT__ctrl_reg;
    IData/*31:0*/ axi4_lite_ctrl__DOT__waddr_lat;
    IData/*31:0*/ axi4_lite_ctrl__DOT__raddr_lat;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vaxi4_lite_ctrl__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vaxi4_lite_ctrl___024root(Vaxi4_lite_ctrl__Syms* symsp, const char* v__name);
    ~Vaxi4_lite_ctrl___024root();
    VL_UNCOPYABLE(Vaxi4_lite_ctrl___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
