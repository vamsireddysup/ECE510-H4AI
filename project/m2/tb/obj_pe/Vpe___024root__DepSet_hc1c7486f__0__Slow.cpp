// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpe.h for the primary calling header

#include "Vpe__pch.h"
#include "Vpe___024root.h"

VL_ATTR_COLD void Vpe___024root___eval_static(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_static\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vpe___024root___eval_initial(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_initial\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vpe___024root___eval_final(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_final\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpe___024root___dump_triggers__stl(Vpe___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vpe___024root___eval_phase__stl(Vpe___024root* vlSelf);

VL_ATTR_COLD void Vpe___024root___eval_settle(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_settle\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vpe___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../rtl/pe.sv", 20, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vpe___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpe___024root___dump_triggers__stl(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___dump_triggers__stl\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpe___024root___stl_sequent__TOP__0(Vpe___024root* vlSelf);
VL_ATTR_COLD void Vpe___024root____Vm_traceActivitySetAll(Vpe___024root* vlSelf);

VL_ATTR_COLD void Vpe___024root___eval_stl(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_stl\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vpe___024root___stl_sequent__TOP__0(vlSelf);
        Vpe___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vpe___024root___stl_sequent__TOP__0(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___stl_sequent__TOP__0\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pe__DOT__u_mul__DOT__zero_a = (IData)(
                                                    (0U 
                                                     == 
                                                     (0x7fffffffU 
                                                      & vlSelfRef.a_in)));
    vlSelfRef.pe__DOT__u_mul__DOT__inf_a = (IData)(
                                                   (0x7f800000U 
                                                    == 
                                                    (0x7fffffffU 
                                                     & vlSelfRef.a_in)));
    vlSelfRef.pe__DOT__u_mul__DOT__nan_a = (IData)(
                                                   ((0x7f800000U 
                                                     == 
                                                     (0x7f800000U 
                                                      & vlSelfRef.a_in)) 
                                                    & (0U 
                                                       != 
                                                       (0x7fffffU 
                                                        & vlSelfRef.a_in))));
    vlSelfRef.pe__DOT__u_mul__DOT__zero_b = (IData)(
                                                    (0U 
                                                     == 
                                                     (0x7fffffffU 
                                                      & vlSelfRef.b_in)));
    vlSelfRef.pe__DOT__u_mul__DOT__inf_b = (IData)(
                                                   (0x7f800000U 
                                                    == 
                                                    (0x7fffffffU 
                                                     & vlSelfRef.b_in)));
    vlSelfRef.pe__DOT__u_mul__DOT__nan_b = (IData)(
                                                   ((0x7f800000U 
                                                     == 
                                                     (0x7f800000U 
                                                      & vlSelfRef.b_in)) 
                                                    & (0U 
                                                       != 
                                                       (0x7fffffU 
                                                        & vlSelfRef.b_in))));
    vlSelfRef.result = vlSelfRef.pe__DOT__acc;
    vlSelfRef.pe__DOT__all_collected = (4U == vlSelfRef.pe__DOT__prod_count);
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

VL_ATTR_COLD void Vpe___024root___eval_triggers__stl(Vpe___024root* vlSelf);

VL_ATTR_COLD bool Vpe___024root___eval_phase__stl(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___eval_phase__stl\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vpe___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vpe___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpe___024root___dump_triggers__ico(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___dump_triggers__ico\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpe___024root___dump_triggers__act(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___dump_triggers__act\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpe___024root___dump_triggers__nba(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___dump_triggers__nba\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpe___024root____Vm_traceActivitySetAll(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root____Vm_traceActivitySetAll\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vpe___024root___ctor_var_reset(Vpe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root___ctor_var_reset\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->a_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13389479046651284173ull);
    vlSelf->b_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13248153975629471093ull);
    vlSelf->valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16540271516330450727ull);
    vlSelf->a_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3703527555082827583ull);
    vlSelf->b_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3498339381559185570ull);
    vlSelf->valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8744939437868816662ull);
    vlSelf->result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16664408842984530663ull);
    vlSelf->result_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8916821378957780047ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->pe__DOT__prod_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8746891303271865059ull);
    }
    vlSelf->pe__DOT__prod_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1541230262723476791ull);
    vlSelf->pe__DOT__all_collected = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12090844963232922820ull);
    vlSelf->pe__DOT__acc_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7513301008487875762ull);
    vlSelf->pe__DOT__add_idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2296710696718831815ull);
    vlSelf->pe__DOT__acc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16774350016471185669ull);
    vlSelf->pe__DOT__acc_valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12226012085158259093ull);
    vlSelf->pe__DOT__add_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6240643196400004371ull);
    vlSelf->pe__DOT__add_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13745564118079813167ull);
    vlSelf->pe__DOT__waiting = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17924533955920031183ull);
    vlSelf->pe__DOT____Vcellinp__u_add__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5837083459296207206ull);
    vlSelf->pe__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->pe__DOT__u_mul__DOT__zero_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1693238288993218641ull);
    vlSelf->pe__DOT__u_mul__DOT__zero_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13986445722509997443ull);
    vlSelf->pe__DOT__u_mul__DOT__inf_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7805553847489739558ull);
    vlSelf->pe__DOT__u_mul__DOT__inf_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17987737869600911204ull);
    vlSelf->pe__DOT__u_mul__DOT__nan_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2898502614278279091ull);
    vlSelf->pe__DOT__u_mul__DOT__nan_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4486075681563858657ull);
    vlSelf->pe__DOT__u_mul__DOT__s1_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8160216502552992117ull);
    vlSelf->pe__DOT__u_mul__DOT__s1_exp = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 9346475156608656488ull);
    vlSelf->pe__DOT__u_mul__DOT__s1_sig_a = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4841607484306679111ull);
    vlSelf->pe__DOT__u_mul__DOT__s1_sig_b = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11063210700967269065ull);
    vlSelf->pe__DOT__u_mul__DOT__s1_is_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9651085297251881111ull);
    vlSelf->pe__DOT__u_mul__DOT__s1_is_inf = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12686654957576405762ull);
    vlSelf->pe__DOT__u_mul__DOT__s1_is_nan = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4181524894711729580ull);
    vlSelf->pe__DOT__u_mul__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11330129598637039877ull);
    vlSelf->pe__DOT__u_mul__DOT__s2_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13558002761870611667ull);
    vlSelf->pe__DOT__u_mul__DOT__s2_exp = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 11855169857180177641ull);
    vlSelf->pe__DOT__u_mul__DOT__s2_product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 12786994893087097664ull);
    vlSelf->pe__DOT__u_mul__DOT__s2_is_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2358896986657171763ull);
    vlSelf->pe__DOT__u_mul__DOT__s2_is_inf = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14275562823786894557ull);
    vlSelf->pe__DOT__u_mul__DOT__s2_is_nan = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5682734505801984378ull);
    vlSelf->pe__DOT__u_mul__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2188769761680327452ull);
    vlSelf->pe__DOT__u_mul__DOT__s3_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12875669908497447027ull);
    vlSelf->pe__DOT__u_mul__DOT__s3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6275777860395996029ull);
    vlSelf->pe__DOT__u_add__DOT__inf_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3839461029214434939ull);
    vlSelf->pe__DOT__u_add__DOT__inf_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10113940317306513014ull);
    vlSelf->pe__DOT__u_add__DOT__zero_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16566184420023040298ull);
    vlSelf->pe__DOT__u_add__DOT__zero_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 870998899746511913ull);
    vlSelf->pe__DOT__u_add__DOT__sign_l = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 159664503399606121ull);
    vlSelf->pe__DOT__u_add__DOT__sign_s = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4961154715549371506ull);
    vlSelf->pe__DOT__u_add__DOT__exp_l = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5926638891434838ull);
    vlSelf->pe__DOT__u_add__DOT__exp_diff = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17883562999775713230ull);
    vlSelf->pe__DOT__u_add__DOT__sig_l_ext = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 10375694589817958245ull);
    vlSelf->pe__DOT__u_add__DOT__sig_s_ext = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 9390306242311906297ull);
    vlSelf->pe__DOT__u_add__DOT__sig_s_aligned = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 13427065649620662010ull);
    vlSelf->pe__DOT__u_add__DOT__sum = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 8134540171110060694ull);
    vlSelf->pe__DOT__u_add__DOT__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5847196737890480961ull);
    vlSelf->pe__DOT__u_add__DOT__result_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5374262799375877100ull);
    vlSelf->pe__DOT__u_add__DOT__result_man = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 2145512648373436591ull);
    vlSelf->pe__DOT__u_add__DOT__lz = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10361164768156577027ull);
    vlSelf->pe__DOT__u_add__DOT__norm_sig = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 2118880221752034365ull);
    vlSelf->pe__DOT__u_add__DOT__add_result_comb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15293239280668459603ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
