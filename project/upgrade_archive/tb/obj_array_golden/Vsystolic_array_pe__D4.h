// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsystolic_array.h for the primary calling header

#ifndef VERILATED_VSYSTOLIC_ARRAY_PE__D4_H_
#define VERILATED_VSYSTOLIC_ARRAY_PE__D4_H_  // guard

#include "verilated.h"


class Vsystolic_array__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsystolic_array_pe__D4 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(a_in,3,0);
    VL_IN8(b_in,3,0);
    VL_IN8(valid_in,0,0);
    VL_OUT8(a_out,3,0);
    VL_OUT8(b_out,3,0);
    VL_OUT8(valid_out,0,0);
    VL_OUT8(result_valid,0,0);
    CData/*0:0*/ __PVT__product_valid;
    CData/*0:0*/ __PVT__all_collected;
    CData/*1:0*/ __PVT__acc_state;
    CData/*0:0*/ __PVT__acc_valid_in;
    CData/*0:0*/ __PVT__add_valid;
    CData/*0:0*/ __PVT__waiting;
    CData/*0:0*/ __PVT__u_add__DOT__inf_a;
    CData/*0:0*/ __PVT__u_add__DOT__inf_b;
    CData/*0:0*/ __PVT__u_add__DOT__zero_a;
    CData/*0:0*/ __PVT__u_add__DOT__zero_b;
    CData/*0:0*/ __PVT__u_add__DOT__sign_l;
    CData/*0:0*/ __PVT__u_add__DOT__sign_s;
    CData/*7:0*/ __PVT__u_add__DOT__exp_l;
    CData/*7:0*/ __PVT__u_add__DOT__exp_diff;
    CData/*0:0*/ __PVT__u_add__DOT__result_sign;
    CData/*7:0*/ __PVT__u_add__DOT__result_exp;
    CData/*4:0*/ __PVT__u_add__DOT__lz;
    VL_OUT(result,31,0);
    IData/*31:0*/ __PVT__product;
    IData/*31:0*/ __PVT__prod_count;
    IData/*31:0*/ __PVT__add_idx;
    IData/*31:0*/ __PVT__acc;
    IData/*31:0*/ __PVT__add_result;
    IData/*31:0*/ __PVT__unnamedblk1__DOT__i;
    IData/*31:0*/ __PVT__u_mul__DOT__lut_result;
    IData/*31:0*/ __PVT__u_add__DOT__b;
    IData/*24:0*/ __PVT__u_add__DOT__sig_l_ext;
    IData/*24:0*/ __PVT__u_add__DOT__sig_s_ext;
    IData/*24:0*/ __PVT__u_add__DOT__sig_s_aligned;
    IData/*24:0*/ __PVT__u_add__DOT__sum;
    IData/*22:0*/ __PVT__u_add__DOT__result_man;
    IData/*24:0*/ __PVT__u_add__DOT__norm_sig;
    IData/*31:0*/ __PVT__u_add__DOT__add_result_comb;
    VlUnpacked<IData/*31:0*/, 4> __PVT__prod_buf;

    // INTERNAL VARIABLES
    Vsystolic_array__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsystolic_array_pe__D4(Vsystolic_array__Syms* symsp, const char* v__name);
    ~Vsystolic_array_pe__D4();
    VL_UNCOPYABLE(Vsystolic_array_pe__D4);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
