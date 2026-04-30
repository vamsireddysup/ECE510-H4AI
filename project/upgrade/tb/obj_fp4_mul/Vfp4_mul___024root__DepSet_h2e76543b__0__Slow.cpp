// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfp4_mul.h for the primary calling header

#include "Vfp4_mul__pch.h"
#include "Vfp4_mul___024root.h"

VL_ATTR_COLD void Vfp4_mul___024root___eval_static(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_static\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vfp4_mul___024root___eval_initial(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_initial\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vfp4_mul___024root___eval_final(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_final\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfp4_mul___024root___dump_triggers__stl(Vfp4_mul___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfp4_mul___024root___eval_phase__stl(Vfp4_mul___024root* vlSelf);

VL_ATTR_COLD void Vfp4_mul___024root___eval_settle(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_settle\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vfp4_mul___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../rtl/fp4_mul.sv", 38, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfp4_mul___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfp4_mul___024root___dump_triggers__stl(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___dump_triggers__stl\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

void Vfp4_mul___024root___ico_sequent__TOP__0(Vfp4_mul___024root* vlSelf);

VL_ATTR_COLD void Vfp4_mul___024root___eval_stl(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_stl\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vfp4_mul___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vfp4_mul___024root___eval_triggers__stl(Vfp4_mul___024root* vlSelf);

VL_ATTR_COLD bool Vfp4_mul___024root___eval_phase__stl(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_phase__stl\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfp4_mul___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vfp4_mul___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfp4_mul___024root___dump_triggers__ico(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___dump_triggers__ico\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void Vfp4_mul___024root___dump_triggers__act(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___dump_triggers__act\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void Vfp4_mul___024root___dump_triggers__nba(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___dump_triggers__nba\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vfp4_mul___024root___ctor_var_reset(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___ctor_var_reset\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->a = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 510903276987443985ull);
    vlSelf->b = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16900879642891266615ull);
    vlSelf->valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16540271516330450727ull);
    vlSelf->result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16664408842984530663ull);
    vlSelf->valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8744939437868816662ull);
    vlSelf->fp4_mul__DOT__lut_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7225346102740301003ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
}
