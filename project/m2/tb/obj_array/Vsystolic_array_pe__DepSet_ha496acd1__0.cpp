// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array__Syms.h"
#include "Vsystolic_array_pe.h"

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [0U][0U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [0U][0U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [0U]
                                                       [0U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [0U]
                                                       [0U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [0U]
                                                    [0U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [0U]
                                                    [0U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [0U][0U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [0U][0U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [0U]
                                                 [0U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [0U]
                                                 [0U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [0U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [0U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [0U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [0U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][0U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [0U][1U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [0U][1U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [0U]
                                                       [1U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [0U]
                                                       [1U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [0U]
                                                    [1U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [0U]
                                                    [1U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [0U][1U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [0U][1U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [0U]
                                                 [1U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [0U]
                                                 [1U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [0U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [0U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [0U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [0U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][1U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [0U][2U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [0U][2U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [0U]
                                                       [2U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [0U]
                                                       [2U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [0U]
                                                    [2U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [0U]
                                                    [2U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [0U][2U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [0U][2U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [0U]
                                                 [2U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [0U]
                                                 [2U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [0U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [0U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [0U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [0U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][2U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [0U][3U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [0U][3U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [0U]
                                                       [3U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [0U]
                                                       [3U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [0U]
                                                    [3U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [0U]
                                                    [3U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [0U][3U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [0U][3U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [0U]
                                                 [3U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [0U]
                                                 [3U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [0U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [0U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [0U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [0U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][3U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [1U][0U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [1U][0U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [1U]
                                                       [0U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [1U]
                                                       [0U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [1U]
                                                    [0U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [1U]
                                                    [0U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [1U][0U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [1U][0U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [1U]
                                                 [0U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [1U]
                                                 [0U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [1U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [1U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [1U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [1U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][0U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [1U][1U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [1U][1U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [1U]
                                                       [1U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [1U]
                                                       [1U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [1U]
                                                    [1U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [1U]
                                                    [1U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [1U][1U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [1U][1U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [1U]
                                                 [1U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [1U]
                                                 [1U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [1U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [1U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [1U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [1U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][1U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [1U][2U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [1U][2U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [1U]
                                                       [2U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [1U]
                                                       [2U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [1U]
                                                    [2U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [1U]
                                                    [2U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [1U][2U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [1U][2U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [1U]
                                                 [2U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [1U]
                                                 [2U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [1U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [1U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [1U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [1U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][2U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [1U][3U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [1U][3U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [1U]
                                                       [3U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [1U]
                                                       [3U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [1U]
                                                    [3U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [1U]
                                                    [3U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [1U][3U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [1U][3U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [1U]
                                                 [3U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [1U]
                                                 [3U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [1U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [1U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [1U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [1U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][3U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [2U][0U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [2U][0U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [2U]
                                                       [0U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [2U]
                                                       [0U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [2U]
                                                    [0U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [2U]
                                                    [0U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [2U][0U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [2U][0U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [2U]
                                                 [0U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [2U]
                                                 [0U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [2U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [2U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [2U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [2U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][0U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [2U][1U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [2U][1U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [2U]
                                                       [1U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [2U]
                                                       [1U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [2U]
                                                    [1U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [2U]
                                                    [1U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [2U][1U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [2U][1U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [2U]
                                                 [1U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [2U]
                                                 [1U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [2U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [2U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [2U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [2U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][1U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [2U][2U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [2U][2U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [2U]
                                                       [2U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [2U]
                                                       [2U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [2U]
                                                    [2U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [2U]
                                                    [2U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [2U][2U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [2U][2U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [2U]
                                                 [2U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [2U]
                                                 [2U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [2U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [2U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [2U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [2U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][2U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [2U][3U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [2U][3U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [2U]
                                                       [3U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [2U]
                                                       [3U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [2U]
                                                    [3U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [2U]
                                                    [3U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [2U][3U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [2U][3U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [2U]
                                                 [3U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [2U]
                                                 [3U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [2U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [2U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [2U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [2U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][3U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [3U][0U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][0U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [3U]
                                                       [0U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [3U]
                                                       [0U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [3U]
                                                    [0U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [3U]
                                                    [0U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [3U][0U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [3U][0U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [3U]
                                                 [0U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [3U]
                                                 [0U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [3U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [3U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [3U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [3U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][0U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [3U][1U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][1U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [3U]
                                                       [1U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [3U]
                                                       [1U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [3U]
                                                    [1U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [3U]
                                                    [1U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [3U][1U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [3U][1U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [3U]
                                                 [1U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [3U]
                                                 [1U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [3U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [3U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [3U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [3U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][1U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [3U][2U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][2U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [3U]
                                                       [2U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [3U]
                                                       [2U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [3U]
                                                    [2U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [3U]
                                                    [2U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [3U][2U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [3U][2U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [3U]
                                                 [2U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [3U]
                                                 [2U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [3U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [3U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [3U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [3U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][2U])));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__prod_count;
    __Vdly__prod_count = 0;
    CData/*0:0*/ __Vdly__acc_valid_in;
    __Vdly__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__acc_state;
    __Vdly__acc_state = 0;
    IData/*31:0*/ __Vdly__add_idx;
    __Vdly__add_idx = 0;
    CData/*0:0*/ __Vdly__waiting;
    __Vdly__waiting = 0;
    IData/*31:0*/ __VdlyVal__prod_buf__v0;
    __VdlyVal__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__prod_buf__v0;
    __VdlyDim0__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v0;
    __VdlySet__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__prod_buf__v1;
    __VdlySet__prod_buf__v1 = 0;
    // Body
    __Vdly__acc_valid_in = vlSelfRef.__PVT__acc_valid_in;
    __Vdly__acc_state = vlSelfRef.__PVT__acc_state;
    __Vdly__waiting = vlSelfRef.__PVT__waiting;
    __Vdly__add_idx = vlSelfRef.__PVT__add_idx;
    __Vdly__prod_count = vlSelfRef.__PVT__prod_count;
    __VdlySet__prod_buf__v0 = 0U;
    __VdlySet__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSymsp->TOP.rst_n) {
        if (((IData)(vlSelfRef.__PVT__u_mul__DOT__s3_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__u_mul__DOT__s3_result;
            __VdlyDim0__prod_buf__v0 = (3U & vlSelfRef.__PVT__prod_count);
            __VdlySet__prod_buf__v0 = 1U;
            __Vdly__prod_count = ((IData)(1U) + vlSelfRef.__PVT__prod_count);
        }
        __Vdly__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((4U == vlSelfRef.__PVT__prod_count)) {
                __Vdly__acc_state = 1U;
                __Vdly__add_idx = 0U;
                vlSelfRef.__PVT__acc = 0U;
                __Vdly__waiting = 0U;
                __Vdly__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__waiting)))) {
                __Vdly__waiting = 1U;
            }
            if (vlSelfRef.__PVT__add_valid) {
                vlSelfRef.__PVT__acc = vlSelfRef.__PVT__add_result;
                __Vdly__waiting = 0U;
                if ((3U == vlSelfRef.__PVT__add_idx)) {
                    __Vdly__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__add_idx = ((IData)(1U) 
                                       + vlSelfRef.__PVT__add_idx);
                    __Vdly__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__acc_state = 0U;
        }
        vlSelfRef.a_out = vlSymsp->TOP.systolic_array__DOT__a_wire
            [3U][3U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][3U];
        vlSelfRef.__PVT__u_mul__DOT__s3_result = ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_nan)
                                                   ? 0x7fc00000U
                                                   : 
                                                  ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_inf)
                                                    ? 
                                                   (0x7f800000U 
                                                    | ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_is_zero)
                                                     ? 
                                                    ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                     << 0x1fU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                 >> 0x2fU)))
                                                      ? 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & (((IData)(1U) 
                                                              + (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp)) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x18U)))))
                                                      : 
                                                     (((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_sign) 
                                                       << 0x1fU) 
                                                      | ((0x7f800000U 
                                                          & ((IData)(vlSelfRef.__PVT__u_mul__DOT__s2_exp) 
                                                             << 0x17U)) 
                                                         | (0x7fffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.__PVT__u_mul__DOT__s2_product 
                                                                       >> 0x17U)))))))));
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = vlSelfRef.__PVT__u_mul__DOT__s1_exp;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = (0xffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_a)) 
                                                      * (QData)((IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sig_b))));
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = (0x3ffU 
                                               & (((0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                       [3U]
                                                       [3U] 
                                                       >> 0x17U)) 
                                                   + 
                                                   (0xffU 
                                                    & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                       [3U]
                                                       [3U] 
                                                       >> 0x17U))) 
                                                  - (IData)(0x7fU)));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__a_wire
                                                    [3U]
                                                    [3U]));
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP.systolic_array__DOT__b_wire
                                                    [3U]
                                                    [3U]));
    } else {
        __Vdly__prod_count = 0U;
        __VdlySet__prod_buf__v1 = 1U;
        __Vdly__acc_state = 0U;
        __Vdly__add_idx = 0U;
        vlSelfRef.__PVT__acc = 0U;
        __Vdly__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__waiting = 0U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s3_result = 0U;
        vlSelfRef.__PVT__add_result = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s2_product = 0ULL;
        vlSelfRef.__PVT__u_mul__DOT__s1_exp = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_a = 0U;
        vlSelfRef.__PVT__u_mul__DOT__s1_sig_b = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire
                           [3U][3U]);
    if (__VdlySet__prod_buf__v0) {
        vlSelfRef.__PVT__prod_buf[__VdlyDim0__prod_buf__v0] 
            = __VdlyVal__prod_buf__v0;
    }
    if (__VdlySet__prod_buf__v1) {
        vlSelfRef.__PVT__prod_buf[0U] = 0U;
        vlSelfRef.__PVT__prod_buf[1U] = 0U;
        vlSelfRef.__PVT__prod_buf[2U] = 0U;
        vlSelfRef.__PVT__prod_buf[3U] = 0U;
    }
    vlSelfRef.__PVT__acc_state = __Vdly__acc_state;
    vlSelfRef.__PVT__waiting = __Vdly__waiting;
    vlSelfRef.__PVT__prod_count = __Vdly__prod_count;
    vlSelfRef.__PVT__add_idx = __Vdly__add_idx;
    vlSelfRef.__PVT__u_mul__DOT__s3_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s2_valid));
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__add_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                  && (IData)(vlSelfRef.__PVT__acc_valid_in));
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__acc_valid_in = __Vdly__acc_valid_in;
    vlSelfRef.__PVT__u_mul__DOT__s2_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_valid));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_zero));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_inf));
    vlSelfRef.__PVT__u_mul__DOT__s2_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_is_nan));
    vlSelfRef.__PVT__u_mul__DOT__s2_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && (IData)(vlSelfRef.__PVT__u_mul__DOT__s1_sign));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
    vlSelfRef.__PVT__u_mul__DOT__s1_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                             && vlSymsp->TOP.systolic_array__DOT__v_wire
                                             [3U][3U]);
    vlSelfRef.__PVT__u_mul__DOT__s1_is_zero = ((IData)(vlSymsp->TOP.rst_n) 
                                               && ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                   | (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b)));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_inf = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a))) 
                                                  & (~ (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_is_nan = ((IData)(vlSymsp->TOP.rst_n) 
                                              && ((((IData)(vlSelfRef.__PVT__u_mul__DOT__nan_a) 
                                                    | (IData)(vlSelfRef.__PVT__u_mul__DOT__nan_b)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_mul__DOT__zero_a) 
                                                      & (IData)(vlSelfRef.__PVT__u_mul__DOT__inf_b))) 
                                                  | ((IData)(vlSelfRef.__PVT__u_mul__DOT__inf_a) 
                                                     & (IData)(vlSelfRef.__PVT__u_mul__DOT__zero_b))));
    vlSelfRef.__PVT__u_mul__DOT__s1_sign = ((IData)(vlSymsp->TOP.rst_n) 
                                            && ((vlSymsp->TOP.systolic_array__DOT__a_wire
                                                 [3U]
                                                 [3U] 
                                                 ^ 
                                                 vlSymsp->TOP.systolic_array__DOT__b_wire
                                                 [3U]
                                                 [3U]) 
                                                >> 0x1fU));
}

VL_INLINE_OPT void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [3U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [3U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [3U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [3U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][3U])));
}
