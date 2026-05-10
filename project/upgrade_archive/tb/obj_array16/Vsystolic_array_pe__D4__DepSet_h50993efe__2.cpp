// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array__Syms.h"
#include "Vsystolic_array_pe__D4.h"

extern const VlUnpacked<IData/*31:0*/, 256> Vsystolic_array__ConstPool__TABLE_h44ff92f3_0;

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx48;
    __Vtableidx48 = 0;
    // Body
    __Vtableidx48 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [2U][0xfU] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [2U][0xfU]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx48];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][0U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx49;
    __Vtableidx49 = 0;
    // Body
    __Vtableidx49 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][0U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][0U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx49];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][1U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx50;
    __Vtableidx50 = 0;
    // Body
    __Vtableidx50 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][1U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][1U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx50];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][2U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx51;
    __Vtableidx51 = 0;
    // Body
    __Vtableidx51 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][2U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][2U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx51];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][3U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx52;
    __Vtableidx52 = 0;
    // Body
    __Vtableidx52 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][3U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][3U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx52];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][4U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][4U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][4U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][4U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx53;
    __Vtableidx53 = 0;
    // Body
    __Vtableidx53 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][4U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][4U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx53];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][5U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][5U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][5U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][5U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx54;
    __Vtableidx54 = 0;
    // Body
    __Vtableidx54 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][5U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][5U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx54];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][6U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][6U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][6U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][6U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx55;
    __Vtableidx55 = 0;
    // Body
    __Vtableidx55 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][6U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][6U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx55];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][7U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][7U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][7U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][7U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx56;
    __Vtableidx56 = 0;
    // Body
    __Vtableidx56 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][7U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][7U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx56];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][8U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][8U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][8U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][8U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx57;
    __Vtableidx57 = 0;
    // Body
    __Vtableidx57 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][8U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][8U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx57];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][9U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][9U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][9U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][9U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx58;
    __Vtableidx58 = 0;
    // Body
    __Vtableidx58 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][9U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][9U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx58];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][0xaU];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][0xaU];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][0xaU]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][0xaU]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx59;
    __Vtableidx59 = 0;
    // Body
    __Vtableidx59 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][0xaU] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][0xaU]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx59];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][0xbU];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][0xbU];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][0xbU]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][0xbU]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx60;
    __Vtableidx60 = 0;
    // Body
    __Vtableidx60 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][0xbU] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][0xbU]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx60];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][0xcU];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][0xcU];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][0xcU]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][0xcU]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx61;
    __Vtableidx61 = 0;
    // Body
    __Vtableidx61 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][0xcU] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][0xcU]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx61];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][0xdU];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][0xdU];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][0xdU]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][0xdU]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx62;
    __Vtableidx62 = 0;
    // Body
    __Vtableidx62 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][0xdU] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][0xdU]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx62];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][0xeU];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][0xeU];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][0xeU]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][0xeU]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx63;
    __Vtableidx63 = 0;
    // Body
    __Vtableidx63 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][0xeU] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][0xeU]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx63];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [3U][0xfU];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [3U][0xfU];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [3U][0xfU]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [3U][0xfU]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx64;
    __Vtableidx64 = 0;
    // Body
    __Vtableidx64 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [3U][0xfU] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [3U][0xfU]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx64];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [4U][0U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [4U][0U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [4U][0U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [4U][0U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx65;
    __Vtableidx65 = 0;
    // Body
    __Vtableidx65 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [4U][0U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [4U][0U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx65];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [4U][1U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [4U][1U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [4U][1U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [4U][1U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx66;
    __Vtableidx66 = 0;
    // Body
    __Vtableidx66 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [4U][1U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [4U][1U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx66];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [4U][2U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [4U][2U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [4U][2U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [4U][2U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx67;
    __Vtableidx67 = 0;
    // Body
    __Vtableidx67 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [4U][2U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [4U][2U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx67];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [4U][3U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [4U][3U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [4U][3U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [4U][3U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx68;
    __Vtableidx68 = 0;
    // Body
    __Vtableidx68 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [4U][3U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [4U][3U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx68];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [4U][4U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [4U][4U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [4U][4U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [4U][4U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx69;
    __Vtableidx69 = 0;
    // Body
    __Vtableidx69 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [4U][4U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [4U][4U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx69];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [4U][5U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [4U][5U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [4U][5U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [4U][5U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx70;
    __Vtableidx70 = 0;
    // Body
    __Vtableidx70 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [4U][5U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [4U][5U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx70];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [4U][6U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [4U][6U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [4U][6U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [4U][6U]);
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
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx71;
    __Vtableidx71 = 0;
    // Body
    __Vtableidx71 = ((vlSymsp->TOP.systolic_array__DOT__b_wire
                      [4U][6U] << 4U) | vlSymsp->TOP.systolic_array__DOT__a_wire
                     [4U][6U]);
    vlSelfRef.__PVT__u_mul__DOT__lut_result = Vsystolic_array__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx71];
}

VL_INLINE_OPT void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__4__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe__0\n"); );
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
        if (((IData)(vlSelfRef.__PVT__product_valid) 
             & (~ (IData)(vlSelfRef.__PVT__all_collected)))) {
            __VdlyVal__prod_buf__v0 = vlSelfRef.__PVT__product;
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
            [4U][7U];
        vlSelfRef.b_out = vlSymsp->TOP.systolic_array__DOT__b_wire
            [4U][7U];
        vlSelfRef.__PVT__product = vlSelfRef.__PVT__u_mul__DOT__lut_result;
        vlSelfRef.__PVT__add_result = vlSelfRef.__PVT__u_add__DOT__add_result_comb;
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
        vlSelfRef.__PVT__product = 0U;
        vlSelfRef.__PVT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSymsp->TOP.rst_n) 
                           && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                           [4U][7U]);
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
    vlSelfRef.__PVT__product_valid = ((IData)(vlSymsp->TOP.rst_n) 
                                      && vlSymsp->TOP.systolic_array__DOT__v_wire_a
                                      [4U][7U]);
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
}
