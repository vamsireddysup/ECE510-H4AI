// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsystolic_array.h for the primary calling header

#ifndef VERILATED_VSYSTOLIC_ARRAY___024ROOT_H_
#define VERILATED_VSYSTOLIC_ARRAY___024ROOT_H_  // guard

#include "verilated.h"
class Vsystolic_array_pe;


class Vsystolic_array__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsystolic_array___024root final : public VerilatedModule {
  public:
    // CELLS
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe;
    Vsystolic_array_pe* __PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(valid_in,0,0);
    VL_OUT8(result_valid,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ systolic_array__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ systolic_array__DOT__unnamedblk1__DOT__unnamedblk2__DOT__d;
    IData/*31:0*/ systolic_array__DOT__unnamedblk3__DOT__j;
    IData/*31:0*/ systolic_array__DOT__unnamedblk3__DOT__unnamedblk4__DOT__d;
    IData/*31:0*/ __VactIterCount;
    VL_IN(a_in[4],31,0);
    VL_IN(b_in[4],31,0);
    VL_OUT(result[4][4],31,0);
    VlUnpacked<IData/*31:0*/, 4> systolic_array__DOT__a_in;
    VlUnpacked<IData/*31:0*/, 4> systolic_array__DOT__b_in;
    VlUnpacked<VlUnpacked<IData/*31:0*/, 4>, 4> systolic_array__DOT__result;
    VlUnpacked<VlUnpacked<IData/*31:0*/, 5>, 4> systolic_array__DOT__a_wire;
    VlUnpacked<VlUnpacked<IData/*31:0*/, 4>, 5> systolic_array__DOT__b_wire;
    VlUnpacked<VlUnpacked<CData/*0:0*/, 5>, 4> systolic_array__DOT__v_wire;
    VlUnpacked<VlUnpacked<IData/*31:0*/, 4>, 4> systolic_array__DOT__a_stagger;
    VlUnpacked<VlUnpacked<IData/*31:0*/, 4>, 4> systolic_array__DOT__b_stagger;
    VlUnpacked<VlUnpacked<CData/*0:0*/, 4>, 4> systolic_array__DOT__v_stagger_a;
    VlUnpacked<VlUnpacked<CData/*0:0*/, 4>, 4> systolic_array__DOT__v_stagger_b;
    VlUnpacked<VlUnpacked<CData/*0:0*/, 4>, 4> systolic_array__DOT__pe_result_valid;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsystolic_array__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsystolic_array___024root(Vsystolic_array__Syms* symsp, const char* v__name);
    ~Vsystolic_array___024root();
    VL_UNCOPYABLE(Vsystolic_array___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
