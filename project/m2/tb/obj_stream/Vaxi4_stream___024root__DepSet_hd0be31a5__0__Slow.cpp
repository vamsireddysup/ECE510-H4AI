// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi4_stream.h for the primary calling header

#include "Vaxi4_stream__pch.h"
#include "Vaxi4_stream___024root.h"

VL_ATTR_COLD void Vaxi4_stream___024root___eval_static(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_static\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vaxi4_stream___024root___eval_initial(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_initial\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vaxi4_stream___024root___eval_final(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_final\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi4_stream___024root___dump_triggers__stl(Vaxi4_stream___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vaxi4_stream___024root___eval_phase__stl(Vaxi4_stream___024root* vlSelf);

VL_ATTR_COLD void Vaxi4_stream___024root___eval_settle(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_settle\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vaxi4_stream___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../rtl/axi4_stream.sv", 26, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vaxi4_stream___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi4_stream___024root___dump_triggers__stl(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___dump_triggers__stl\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vaxi4_stream___024root___stl_sequent__TOP__0(Vaxi4_stream___024root* vlSelf);
VL_ATTR_COLD void Vaxi4_stream___024root____Vm_traceActivitySetAll(Vaxi4_stream___024root* vlSelf);

VL_ATTR_COLD void Vaxi4_stream___024root___eval_stl(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_stl\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vaxi4_stream___024root___stl_sequent__TOP__0(vlSelf);
        Vaxi4_stream___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vaxi4_stream___024root___stl_sequent__TOP__0(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___stl_sequent__TOP__0\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.s_tready = (1U == (IData)(vlSelfRef.axi4_stream__DOT__state));
    vlSelfRef.done = (4U == (IData)(vlSelfRef.axi4_stream__DOT__state));
    vlSelfRef.axi4_stream__DOT__a_out[0U] = vlSelfRef.axi4_stream__DOT__q_buf
        [0U];
    vlSelfRef.axi4_stream__DOT__a_out[1U] = vlSelfRef.axi4_stream__DOT__q_buf
        [1U];
    vlSelfRef.axi4_stream__DOT__a_out[2U] = vlSelfRef.axi4_stream__DOT__q_buf
        [2U];
    vlSelfRef.axi4_stream__DOT__a_out[3U] = vlSelfRef.axi4_stream__DOT__q_buf
        [3U];
    vlSelfRef.axi4_stream__DOT__b_out[0U] = vlSelfRef.axi4_stream__DOT__k_buf
        [0U];
    vlSelfRef.axi4_stream__DOT__b_out[1U] = vlSelfRef.axi4_stream__DOT__k_buf
        [1U];
    vlSelfRef.axi4_stream__DOT__b_out[2U] = vlSelfRef.axi4_stream__DOT__k_buf
        [2U];
    vlSelfRef.axi4_stream__DOT__b_out[3U] = vlSelfRef.axi4_stream__DOT__k_buf
        [3U];
    vlSelfRef.m_tvalid = (3U == (IData)(vlSelfRef.axi4_stream__DOT__state));
    if (vlSelfRef.m_tvalid) {
        vlSelfRef.m_tlast = (0xfU == vlSelfRef.axi4_stream__DOT__send_count);
        vlSelfRef.m_tdata = ((QData)((IData)(vlSelfRef.axi4_stream__DOT__score_buf
                                             [(0xfU 
                                               & vlSelfRef.axi4_stream__DOT__send_count)])) 
                             << 0x20U);
    } else {
        vlSelfRef.m_tlast = 0U;
        vlSelfRef.m_tdata = 0ULL;
    }
}

VL_ATTR_COLD void Vaxi4_stream___024root___eval_triggers__stl(Vaxi4_stream___024root* vlSelf);

VL_ATTR_COLD bool Vaxi4_stream___024root___eval_phase__stl(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_phase__stl\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vaxi4_stream___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vaxi4_stream___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi4_stream___024root___dump_triggers__act(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___dump_triggers__act\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void Vaxi4_stream___024root___dump_triggers__nba(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___dump_triggers__nba\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vaxi4_stream___024root____Vm_traceActivitySetAll(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root____Vm_traceActivitySetAll\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vaxi4_stream___024root___ctor_var_reset(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___ctor_var_reset\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->s_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5856568867834129024ull);
    vlSelf->s_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14368903921307703071ull);
    vlSelf->s_tdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7101865465292779667ull);
    vlSelf->s_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17697317467885297558ull);
    vlSelf->m_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6330821876457450032ull);
    vlSelf->m_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15425253223298272161ull);
    vlSelf->m_tdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16534874751520676056ull);
    vlSelf->m_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9494342378649836147ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    vlSelf->axi4_stream__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2707930613770115040ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->axi4_stream__DOT__q_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1966240171165874679ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->axi4_stream__DOT__k_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16242171361566230490ull);
    }
    vlSelf->axi4_stream__DOT__recv_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10277993578115416318ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->axi4_stream__DOT__a_out[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12862936503547224835ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->axi4_stream__DOT__b_out[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6932932676343078867ull);
    }
    vlSelf->axi4_stream__DOT__core_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1512060961964785693ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->axi4_stream__DOT__score_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16662442133931827551ull);
    }
    vlSelf->axi4_stream__DOT__send_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11152129643058162949ull);
    vlSelf->axi4_stream__DOT__unnamedblk3__DOT__i = 0;
    vlSelf->axi4_stream__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->axi4_stream__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
