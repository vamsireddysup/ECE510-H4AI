// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsystolic_array.h for the primary calling header

#ifndef VERILATED_VSYSTOLIC_ARRAY_PE_H_
#define VERILATED_VSYSTOLIC_ARRAY_PE_H_  // guard

#include "verilated.h"


class Vsystolic_array__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsystolic_array_pe final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(valid_in,0,0);
    VL_OUT8(valid_out,0,0);
    VL_OUT8(result_valid,0,0);
    CData/*0:0*/ __PVT__all_collected;
    CData/*1:0*/ __PVT__acc_state;
    CData/*0:0*/ __PVT__acc_valid_in;
    CData/*0:0*/ __PVT__add_valid;
    CData/*0:0*/ __PVT__waiting;
    CData/*0:0*/ __PVT__u_mul__DOT__zero_a;
    CData/*0:0*/ __PVT__u_mul__DOT__zero_b;
    CData/*0:0*/ __PVT__u_mul__DOT__inf_a;
    CData/*0:0*/ __PVT__u_mul__DOT__inf_b;
    CData/*0:0*/ __PVT__u_mul__DOT__nan_a;
    CData/*0:0*/ __PVT__u_mul__DOT__nan_b;
    CData/*0:0*/ __PVT__u_mul__DOT__s1_sign;
    CData/*0:0*/ __PVT__u_mul__DOT__s1_is_zero;
    CData/*0:0*/ __PVT__u_mul__DOT__s1_is_inf;
    CData/*0:0*/ __PVT__u_mul__DOT__s1_is_nan;
    CData/*0:0*/ __PVT__u_mul__DOT__s1_valid;
    CData/*0:0*/ __PVT__u_mul__DOT__s2_sign;
    CData/*0:0*/ __PVT__u_mul__DOT__s2_is_zero;
    CData/*0:0*/ __PVT__u_mul__DOT__s2_is_inf;
    CData/*0:0*/ __PVT__u_mul__DOT__s2_is_nan;
    CData/*0:0*/ __PVT__u_mul__DOT__s2_valid;
    CData/*0:0*/ __PVT__u_mul__DOT__s3_valid;
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
    SData/*9:0*/ __PVT__u_mul__DOT__s1_exp;
    SData/*9:0*/ __PVT__u_mul__DOT__s2_exp;
    VL_IN(a_in,31,0);
    VL_IN(b_in,31,0);
    VL_OUT(a_out,31,0);
    VL_OUT(b_out,31,0);
    VL_OUT(result,31,0);
    IData/*31:0*/ __PVT__prod_count;
    IData/*31:0*/ __PVT__add_idx;
    IData/*31:0*/ __PVT__acc;
    IData/*31:0*/ __PVT__add_result;
    IData/*31:0*/ __PVT__unnamedblk1__DOT__i;
    IData/*23:0*/ __PVT__u_mul__DOT__s1_sig_a;
    IData/*23:0*/ __PVT__u_mul__DOT__s1_sig_b;
    IData/*31:0*/ __PVT__u_mul__DOT__s3_result;
    IData/*31:0*/ __PVT__u_add__DOT__b;
    IData/*24:0*/ __PVT__u_add__DOT__sig_l_ext;
    IData/*24:0*/ __PVT__u_add__DOT__sig_s_ext;
    IData/*24:0*/ __PVT__u_add__DOT__sig_s_aligned;
    IData/*24:0*/ __PVT__u_add__DOT__sum;
    IData/*22:0*/ __PVT__u_add__DOT__result_man;
    IData/*24:0*/ __PVT__u_add__DOT__norm_sig;
    IData/*31:0*/ __PVT__u_add__DOT__add_result_comb;
    QData/*47:0*/ __PVT__u_mul__DOT__s2_product;
    VlUnpacked<IData/*31:0*/, 4> __PVT__prod_buf;

    // INTERNAL VARIABLES
    Vsystolic_array__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsystolic_array_pe(Vsystolic_array__Syms* symsp, const char* v__name);
    ~Vsystolic_array_pe();
    VL_UNCOPYABLE(Vsystolic_array_pe);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
