// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpe.h for the primary calling header

#include "Vpe__pch.h"
#include "Vpe___024root.h"

void Vpe___024root___ico_sequent__TOP__0(Vpe___024root* vlSelf);

void Vpe___024root___eval_ico(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_ico\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vpe___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<IData/*31:0*/, 256> Vpe__ConstPool__TABLE_h44ff92f3_0;

VL_INLINE_OPT void Vpe___024root___ico_sequent__TOP__0(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___ico_sequent__TOP__0\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.b_in) << 4U) 
                    | (IData)(vlSelfRef.a_in));
    vlSelfRef.pe__DOT__u_mul__DOT__lut_result = Vpe__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx1];
}

void Vpe___024root___eval_triggers__ico(Vpe___024root* vlSelf);

bool Vpe___024root___eval_phase__ico(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_phase__ico\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vpe___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vpe___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vpe___024root___eval_act(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_act\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vpe___024root___nba_sequent__TOP__0(Vpe___024root* vlSelf);

void Vpe___024root___eval_nba(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_nba\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vpe___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vpe___024root___nba_sequent__TOP__0(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___nba_sequent__TOP__0\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__pe__DOT__prod_count;
    __Vdly__pe__DOT__prod_count = 0;
    CData/*0:0*/ __Vdly__pe__DOT__acc_valid_in;
    __Vdly__pe__DOT__acc_valid_in = 0;
    CData/*1:0*/ __Vdly__pe__DOT__acc_state;
    __Vdly__pe__DOT__acc_state = 0;
    IData/*31:0*/ __Vdly__pe__DOT__add_idx;
    __Vdly__pe__DOT__add_idx = 0;
    CData/*0:0*/ __Vdly__pe__DOT__waiting;
    __Vdly__pe__DOT__waiting = 0;
    IData/*31:0*/ __VdlyVal__pe__DOT__prod_buf__v0;
    __VdlyVal__pe__DOT__prod_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__pe__DOT__prod_buf__v0;
    __VdlyDim0__pe__DOT__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__pe__DOT__prod_buf__v0;
    __VdlySet__pe__DOT__prod_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__pe__DOT__prod_buf__v1;
    __VdlySet__pe__DOT__prod_buf__v1 = 0;
    // Body
    __Vdly__pe__DOT__acc_valid_in = vlSelfRef.pe__DOT__acc_valid_in;
    __Vdly__pe__DOT__acc_state = vlSelfRef.pe__DOT__acc_state;
    __Vdly__pe__DOT__waiting = vlSelfRef.pe__DOT__waiting;
    __Vdly__pe__DOT__prod_count = vlSelfRef.pe__DOT__prod_count;
    __Vdly__pe__DOT__add_idx = vlSelfRef.pe__DOT__add_idx;
    __VdlySet__pe__DOT__prod_buf__v0 = 0U;
    __VdlySet__pe__DOT__prod_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        vlSelfRef.pe__DOT__unnamedblk1__DOT__i = 4U;
    }
    if (vlSelfRef.rst_n) {
        if (((IData)(vlSelfRef.pe__DOT__product_valid) 
             & (~ (IData)(vlSelfRef.pe__DOT__all_collected)))) {
            __VdlyVal__pe__DOT__prod_buf__v0 = vlSelfRef.pe__DOT__product;
            __VdlyDim0__pe__DOT__prod_buf__v0 = (3U 
                                                 & vlSelfRef.pe__DOT__prod_count);
            __VdlySet__pe__DOT__prod_buf__v0 = 1U;
            __Vdly__pe__DOT__prod_count = ((IData)(1U) 
                                           + vlSelfRef.pe__DOT__prod_count);
        }
        vlSelfRef.a_out = vlSelfRef.a_in;
        vlSelfRef.b_out = vlSelfRef.b_in;
        __Vdly__pe__DOT__acc_valid_in = 0U;
        if ((0U == (IData)(vlSelfRef.pe__DOT__acc_state))) {
            if ((4U == vlSelfRef.pe__DOT__prod_count)) {
                __Vdly__pe__DOT__acc_state = 1U;
                __Vdly__pe__DOT__add_idx = 0U;
                vlSelfRef.pe__DOT__acc = 0U;
                __Vdly__pe__DOT__waiting = 0U;
                __Vdly__pe__DOT__acc_valid_in = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.pe__DOT__acc_state))) {
            if ((1U & (~ (IData)(vlSelfRef.pe__DOT__waiting)))) {
                __Vdly__pe__DOT__waiting = 1U;
            }
            if (vlSelfRef.pe__DOT__add_valid) {
                vlSelfRef.pe__DOT__acc = vlSelfRef.pe__DOT__add_result;
                __Vdly__pe__DOT__waiting = 0U;
                if ((3U == vlSelfRef.pe__DOT__add_idx)) {
                    __Vdly__pe__DOT__acc_state = 2U;
                    vlSelfRef.result_valid = 1U;
                } else {
                    __Vdly__pe__DOT__add_idx = ((IData)(1U) 
                                                + vlSelfRef.pe__DOT__add_idx);
                    __Vdly__pe__DOT__acc_valid_in = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.pe__DOT__acc_state))) {
            vlSelfRef.result_valid = 1U;
        } else {
            __Vdly__pe__DOT__acc_state = 0U;
        }
        vlSelfRef.pe__DOT__product = vlSelfRef.pe__DOT__u_mul__DOT__lut_result;
        vlSelfRef.pe__DOT__add_result = vlSelfRef.pe__DOT__u_add__DOT__add_result_comb;
    } else {
        __Vdly__pe__DOT__prod_count = 0U;
        __VdlySet__pe__DOT__prod_buf__v1 = 1U;
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        __Vdly__pe__DOT__acc_state = 0U;
        __Vdly__pe__DOT__add_idx = 0U;
        vlSelfRef.pe__DOT__acc = 0U;
        __Vdly__pe__DOT__acc_valid_in = 0U;
        vlSelfRef.result_valid = 0U;
        __Vdly__pe__DOT__waiting = 0U;
        vlSelfRef.pe__DOT__product = 0U;
        vlSelfRef.pe__DOT__add_result = 0U;
    }
    vlSelfRef.valid_out = ((IData)(vlSelfRef.rst_n) 
                           && (IData)(vlSelfRef.valid_in));
    if (__VdlySet__pe__DOT__prod_buf__v0) {
        vlSelfRef.pe__DOT__prod_buf[__VdlyDim0__pe__DOT__prod_buf__v0] 
            = __VdlyVal__pe__DOT__prod_buf__v0;
    }
    if (__VdlySet__pe__DOT__prod_buf__v1) {
        vlSelfRef.pe__DOT__prod_buf[0U] = 0U;
        vlSelfRef.pe__DOT__prod_buf[1U] = 0U;
        vlSelfRef.pe__DOT__prod_buf[2U] = 0U;
        vlSelfRef.pe__DOT__prod_buf[3U] = 0U;
    }
    vlSelfRef.pe__DOT__acc_state = __Vdly__pe__DOT__acc_state;
    vlSelfRef.pe__DOT__waiting = __Vdly__pe__DOT__waiting;
    vlSelfRef.pe__DOT__prod_count = __Vdly__pe__DOT__prod_count;
    vlSelfRef.pe__DOT__add_idx = __Vdly__pe__DOT__add_idx;
    vlSelfRef.pe__DOT__product_valid = ((IData)(vlSelfRef.rst_n) 
                                        && (IData)(vlSelfRef.valid_in));
    vlSelfRef.pe__DOT__all_collected = (4U == vlSelfRef.pe__DOT__prod_count);
    vlSelfRef.pe__DOT__add_valid = ((IData)(vlSelfRef.rst_n) 
                                    && (IData)(vlSelfRef.pe__DOT__acc_valid_in));
    vlSelfRef.result = vlSelfRef.pe__DOT__acc;
    vlSelfRef.pe__DOT__u_add__DOT__inf_a = (IData)(
                                                   (0x7f800000U 
                                                    == 
                                                    (0x7fffffffU 
                                                     & vlSelfRef.pe__DOT__acc)));
    vlSelfRef.pe__DOT__u_add__DOT__zero_a = (IData)(
                                                    (0U 
                                                     == 
                                                     (0x7fffffffU 
                                                      & vlSelfRef.pe__DOT__acc)));
    vlSelfRef.pe__DOT____Vcellinp__u_add__b = vlSelfRef.pe__DOT__prod_buf
        [(3U & vlSelfRef.pe__DOT__add_idx)];
    vlSelfRef.pe__DOT__acc_valid_in = __Vdly__pe__DOT__acc_valid_in;
    vlSelfRef.pe__DOT__u_add__DOT__inf_b = (IData)(
                                                   (0x7f800000U 
                                                    == 
                                                    (0x7fffffffU 
                                                     & vlSelfRef.pe__DOT____Vcellinp__u_add__b)));
    vlSelfRef.pe__DOT__u_add__DOT__zero_b = (IData)(
                                                    (0U 
                                                     == 
                                                     (0x7fffffffU 
                                                      & vlSelfRef.pe__DOT____Vcellinp__u_add__b)));
    vlSelfRef.pe__DOT__u_add__DOT__sign_l = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__sign_s = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__exp_l = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__sum = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__result_sign = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__result_exp = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__result_man = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__lz = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.pe__DOT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.pe__DOT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.pe__DOT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.pe__DOT____Vcellinp__u_add__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.pe__DOT____Vcellinp__u_add__b)))) 
            | ((IData)(vlSelfRef.pe__DOT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.pe__DOT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.pe__DOT__acc >> 0x1fU) 
                     != (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                         >> 0x1fU))))))) {
        vlSelfRef.pe__DOT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.pe__DOT__u_add__DOT__inf_a) {
        vlSelfRef.pe__DOT__u_add__DOT__add_result_comb 
            = vlSelfRef.pe__DOT__acc;
    } else if (vlSelfRef.pe__DOT__u_add__DOT__inf_b) {
        vlSelfRef.pe__DOT__u_add__DOT__add_result_comb 
            = vlSelfRef.pe__DOT____Vcellinp__u_add__b;
    } else if (((IData)(vlSelfRef.pe__DOT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.pe__DOT__u_add__DOT__zero_b))) {
        vlSelfRef.pe__DOT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.pe__DOT__u_add__DOT__zero_a) {
        vlSelfRef.pe__DOT__u_add__DOT__add_result_comb 
            = vlSelfRef.pe__DOT____Vcellinp__u_add__b;
    } else if (vlSelfRef.pe__DOT__u_add__DOT__zero_b) {
        vlSelfRef.pe__DOT__u_add__DOT__add_result_comb 
            = vlSelfRef.pe__DOT__acc;
    } else {
        if (((0xffU & (vlSelfRef.pe__DOT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                          >> 0x17U)))) {
            vlSelfRef.pe__DOT__u_add__DOT__sign_l = 
                (vlSelfRef.pe__DOT__acc >> 0x1fU);
            vlSelfRef.pe__DOT__u_add__DOT__sign_s = 
                (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                 >> 0x1fU);
            vlSelfRef.pe__DOT__u_add__DOT__exp_l = 
                (0xffU & (vlSelfRef.pe__DOT__acc >> 0x17U));
            vlSelfRef.pe__DOT__u_add__DOT__exp_diff 
                = (0xffU & ((vlSelfRef.pe__DOT__acc 
                             >> 0x17U) - (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                                          >> 0x17U)));
            vlSelfRef.pe__DOT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.pe__DOT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.pe__DOT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.pe__DOT__acc)));
            vlSelfRef.pe__DOT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.pe__DOT____Vcellinp__u_add__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.pe__DOT____Vcellinp__u_add__b)));
        } else {
            vlSelfRef.pe__DOT__u_add__DOT__sign_l = 
                (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                 >> 0x1fU);
            vlSelfRef.pe__DOT__u_add__DOT__sign_s = 
                (vlSelfRef.pe__DOT__acc >> 0x1fU);
            vlSelfRef.pe__DOT__u_add__DOT__exp_l = 
                (0xffU & (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                          >> 0x17U));
            vlSelfRef.pe__DOT__u_add__DOT__exp_diff 
                = (0xffU & ((vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                             >> 0x17U) - (vlSelfRef.pe__DOT__acc 
                                          >> 0x17U)));
            vlSelfRef.pe__DOT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.pe__DOT____Vcellinp__u_add__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.pe__DOT____Vcellinp__u_add__b)));
            vlSelfRef.pe__DOT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.pe__DOT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.pe__DOT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.pe__DOT__acc)));
        }
        vlSelfRef.pe__DOT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.pe__DOT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.pe__DOT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.pe__DOT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.pe__DOT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.pe__DOT__u_add__DOT__sign_s))) {
            vlSelfRef.pe__DOT__u_add__DOT__result_sign 
                = vlSelfRef.pe__DOT__u_add__DOT__sign_l;
            vlSelfRef.pe__DOT__u_add__DOT__sum = (0x1ffffffU 
                                                  & (vlSelfRef.pe__DOT__u_add__DOT__sig_l_ext 
                                                     + vlSelfRef.pe__DOT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.pe__DOT__u_add__DOT__result_sign 
                = vlSelfRef.pe__DOT__u_add__DOT__sign_l;
            vlSelfRef.pe__DOT__u_add__DOT__sum = (0x1ffffffU 
                                                  & ((vlSelfRef.pe__DOT__u_add__DOT__sig_l_ext 
                                                      >= vlSelfRef.pe__DOT__u_add__DOT__sig_s_aligned)
                                                      ? 
                                                     (vlSelfRef.pe__DOT__u_add__DOT__sig_l_ext 
                                                      - vlSelfRef.pe__DOT__u_add__DOT__sig_s_aligned)
                                                      : 
                                                     (vlSelfRef.pe__DOT__u_add__DOT__sig_s_aligned 
                                                      - vlSelfRef.pe__DOT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.pe__DOT__u_add__DOT__sum)) {
            vlSelfRef.pe__DOT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.pe__DOT__u_add__DOT__sum)) {
            vlSelfRef.pe__DOT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.pe__DOT__u_add__DOT__exp_l)));
            vlSelfRef.pe__DOT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.pe__DOT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.pe__DOT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.pe__DOT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.pe__DOT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.pe__DOT__u_add__DOT__result_man));
        } else {
            vlSelfRef.pe__DOT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.pe__DOT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.pe__DOT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.pe__DOT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.pe__DOT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.pe__DOT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.pe__DOT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.pe__DOT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.pe__DOT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.pe__DOT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.pe__DOT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.pe__DOT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.pe__DOT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.pe__DOT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.pe__DOT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.pe__DOT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.pe__DOT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.pe__DOT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.pe__DOT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.pe__DOT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.pe__DOT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.pe__DOT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.pe__DOT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.pe__DOT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.pe__DOT__u_add__DOT__norm_sig 
                = (0x1ffffffU & (vlSelfRef.pe__DOT__u_add__DOT__sum 
                                 << (IData)(vlSelfRef.pe__DOT__u_add__DOT__lz)));
            vlSelfRef.pe__DOT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.pe__DOT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.pe__DOT__u_add__DOT__lz)));
            vlSelfRef.pe__DOT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.pe__DOT__u_add__DOT__norm_sig);
            vlSelfRef.pe__DOT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.pe__DOT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.pe__DOT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.pe__DOT__u_add__DOT__result_man));
        }
    }
}

void Vpe___024root___eval_triggers__act(Vpe___024root* vlSelf);

bool Vpe___024root___eval_phase__act(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_phase__act\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vpe___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vpe___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vpe___024root___eval_phase__nba(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_phase__nba\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vpe___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpe___024root___dump_triggers__ico(Vpe___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpe___024root___dump_triggers__nba(Vpe___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpe___024root___dump_triggers__act(Vpe___024root* vlSelf);
#endif  // VL_DEBUG

void Vpe___024root___eval(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vpe___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../rtl/pe.sv", 37, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vpe___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vpe___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/pe.sv", 37, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vpe___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/pe.sv", 37, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vpe___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vpe___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vpe___024root___eval_debug_assertions(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_debug_assertions\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.a_in & 0xf0U)))) {
        Verilated::overWidthError("a_in");}
    if (VL_UNLIKELY(((vlSelfRef.b_in & 0xf0U)))) {
        Verilated::overWidthError("b_in");}
    if (VL_UNLIKELY(((vlSelfRef.valid_in & 0xfeU)))) {
        Verilated::overWidthError("valid_in");}
}
#endif  // VL_DEBUG
