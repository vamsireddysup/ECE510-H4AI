// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi4_stream.h for the primary calling header

#include "Vaxi4_stream__pch.h"
#include "Vaxi4_stream___024root.h"

void Vaxi4_stream___024root___eval_act(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_act\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vaxi4_stream___024root___nba_sequent__TOP__0(Vaxi4_stream___024root* vlSelf);

void Vaxi4_stream___024root___eval_nba(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_nba\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaxi4_stream___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vaxi4_stream___024root___nba_sequent__TOP__0(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___nba_sequent__TOP__0\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vdly__axi4_stream__DOT__state;
    __Vdly__axi4_stream__DOT__state = 0;
    IData/*31:0*/ __Vdly__axi4_stream__DOT__recv_count;
    __Vdly__axi4_stream__DOT__recv_count = 0;
    CData/*0:0*/ __VdlySet__axi4_stream__DOT__score_buf__v0;
    __VdlySet__axi4_stream__DOT__score_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__axi4_stream__DOT__score_buf__v1;
    __VdlySet__axi4_stream__DOT__score_buf__v1 = 0;
    IData/*31:0*/ __VdlyVal__axi4_stream__DOT__q_buf__v0;
    __VdlyVal__axi4_stream__DOT__q_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__axi4_stream__DOT__q_buf__v0;
    __VdlyDim0__axi4_stream__DOT__q_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__axi4_stream__DOT__q_buf__v0;
    __VdlySet__axi4_stream__DOT__q_buf__v0 = 0;
    IData/*31:0*/ __VdlyVal__axi4_stream__DOT__k_buf__v0;
    __VdlyVal__axi4_stream__DOT__k_buf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__axi4_stream__DOT__k_buf__v0;
    __VdlyDim0__axi4_stream__DOT__k_buf__v0 = 0;
    CData/*0:0*/ __VdlySet__axi4_stream__DOT__q_buf__v1;
    __VdlySet__axi4_stream__DOT__q_buf__v1 = 0;
    // Body
    __Vdly__axi4_stream__DOT__recv_count = vlSelfRef.axi4_stream__DOT__recv_count;
    __VdlySet__axi4_stream__DOT__score_buf__v0 = 0U;
    __VdlySet__axi4_stream__DOT__score_buf__v1 = 0U;
    __Vdly__axi4_stream__DOT__state = vlSelfRef.axi4_stream__DOT__state;
    __VdlySet__axi4_stream__DOT__q_buf__v0 = 0U;
    __VdlySet__axi4_stream__DOT__q_buf__v1 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        vlSelfRef.axi4_stream__DOT__unnamedblk1__DOT__i = 4U;
        vlSelfRef.axi4_stream__DOT__unnamedblk2__DOT__i = 0x10U;
    }
    if (vlSelfRef.rst_n) {
        vlSelfRef.axi4_stream__DOT__core_valid = 0U;
        if ((4U & (IData)(vlSelfRef.axi4_stream__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.axi4_stream__DOT__state))) {
                __Vdly__axi4_stream__DOT__state = 0U;
            } else if ((1U & (IData)(vlSelfRef.axi4_stream__DOT__state))) {
                __Vdly__axi4_stream__DOT__state = 0U;
            }
        } else if ((2U & (IData)(vlSelfRef.axi4_stream__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.axi4_stream__DOT__state))) {
                if (((IData)(vlSelfRef.m_tvalid) & (IData)(vlSelfRef.m_tready))) {
                    if ((0xfU == vlSelfRef.axi4_stream__DOT__send_count)) {
                        __Vdly__axi4_stream__DOT__state = 4U;
                    } else {
                        vlSelfRef.axi4_stream__DOT__send_count 
                            = ((IData)(1U) + vlSelfRef.axi4_stream__DOT__send_count);
                    }
                }
            } else {
                __Vdly__axi4_stream__DOT__recv_count 
                    = ((IData)(1U) + vlSelfRef.axi4_stream__DOT__recv_count);
                if ((5U == vlSelfRef.axi4_stream__DOT__recv_count)) {
                    vlSelfRef.axi4_stream__DOT__unnamedblk3__DOT__i = 0x10U;
                    __VdlySet__axi4_stream__DOT__score_buf__v0 = 1U;
                    __Vdly__axi4_stream__DOT__state = 3U;
                    vlSelfRef.axi4_stream__DOT__send_count = 0U;
                    __VdlySet__axi4_stream__DOT__score_buf__v1 = 1U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.axi4_stream__DOT__state))) {
            if (((IData)(vlSelfRef.s_tvalid) & (IData)(vlSelfRef.s_tready))) {
                __VdlyVal__axi4_stream__DOT__q_buf__v0 
                    = (IData)((vlSelfRef.s_tdata >> 0x20U));
                __VdlyDim0__axi4_stream__DOT__q_buf__v0 
                    = (3U & vlSelfRef.axi4_stream__DOT__recv_count);
                __VdlySet__axi4_stream__DOT__q_buf__v0 = 1U;
                __VdlyVal__axi4_stream__DOT__k_buf__v0 
                    = (IData)(vlSelfRef.s_tdata);
                __VdlyDim0__axi4_stream__DOT__k_buf__v0 
                    = (3U & vlSelfRef.axi4_stream__DOT__recv_count);
                if (((3U == vlSelfRef.axi4_stream__DOT__recv_count) 
                     | (IData)(vlSelfRef.s_tlast))) {
                    __Vdly__axi4_stream__DOT__recv_count = 0U;
                    __Vdly__axi4_stream__DOT__state = 2U;
                    vlSelfRef.axi4_stream__DOT__core_valid = 1U;
                } else {
                    __Vdly__axi4_stream__DOT__recv_count 
                        = ((IData)(1U) + vlSelfRef.axi4_stream__DOT__recv_count);
                }
            }
        } else {
            __Vdly__axi4_stream__DOT__recv_count = 0U;
            vlSelfRef.axi4_stream__DOT__send_count = 0U;
            if (vlSelfRef.start) {
                __Vdly__axi4_stream__DOT__state = 1U;
            }
        }
    } else {
        __Vdly__axi4_stream__DOT__state = 0U;
        __Vdly__axi4_stream__DOT__recv_count = 0U;
        vlSelfRef.axi4_stream__DOT__send_count = 0U;
        vlSelfRef.axi4_stream__DOT__core_valid = 0U;
        __VdlySet__axi4_stream__DOT__q_buf__v1 = 1U;
    }
    vlSelfRef.axi4_stream__DOT__recv_count = __Vdly__axi4_stream__DOT__recv_count;
    vlSelfRef.axi4_stream__DOT__state = __Vdly__axi4_stream__DOT__state;
    if (__VdlySet__axi4_stream__DOT__score_buf__v0) {
        vlSelfRef.axi4_stream__DOT__score_buf[0U] = 1U;
    }
    if (__VdlySet__axi4_stream__DOT__score_buf__v1) {
        vlSelfRef.axi4_stream__DOT__score_buf[1U] = 2U;
        vlSelfRef.axi4_stream__DOT__score_buf[2U] = 3U;
        vlSelfRef.axi4_stream__DOT__score_buf[3U] = 4U;
        vlSelfRef.axi4_stream__DOT__score_buf[4U] = 5U;
        vlSelfRef.axi4_stream__DOT__score_buf[5U] = 6U;
        vlSelfRef.axi4_stream__DOT__score_buf[6U] = 7U;
        vlSelfRef.axi4_stream__DOT__score_buf[7U] = 8U;
        vlSelfRef.axi4_stream__DOT__score_buf[8U] = 9U;
        vlSelfRef.axi4_stream__DOT__score_buf[9U] = 0xaU;
        vlSelfRef.axi4_stream__DOT__score_buf[0xaU] = 0xbU;
        vlSelfRef.axi4_stream__DOT__score_buf[0xbU] = 0xcU;
        vlSelfRef.axi4_stream__DOT__score_buf[0xcU] = 0xdU;
        vlSelfRef.axi4_stream__DOT__score_buf[0xdU] = 0xeU;
        vlSelfRef.axi4_stream__DOT__score_buf[0xeU] = 0xfU;
        vlSelfRef.axi4_stream__DOT__score_buf[0xfU] = 0x10U;
    }
    if (__VdlySet__axi4_stream__DOT__q_buf__v0) {
        vlSelfRef.axi4_stream__DOT__q_buf[__VdlyDim0__axi4_stream__DOT__q_buf__v0] 
            = __VdlyVal__axi4_stream__DOT__q_buf__v0;
        vlSelfRef.axi4_stream__DOT__k_buf[__VdlyDim0__axi4_stream__DOT__k_buf__v0] 
            = __VdlyVal__axi4_stream__DOT__k_buf__v0;
    }
    if (__VdlySet__axi4_stream__DOT__q_buf__v1) {
        vlSelfRef.axi4_stream__DOT__score_buf[0U] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[1U] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[2U] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[3U] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[4U] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[5U] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[6U] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[7U] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[8U] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[9U] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[0xaU] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[0xbU] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[0xcU] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[0xdU] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[0xeU] = 0U;
        vlSelfRef.axi4_stream__DOT__score_buf[0xfU] = 0U;
        vlSelfRef.axi4_stream__DOT__q_buf[0U] = 0U;
        vlSelfRef.axi4_stream__DOT__q_buf[1U] = 0U;
        vlSelfRef.axi4_stream__DOT__q_buf[2U] = 0U;
        vlSelfRef.axi4_stream__DOT__q_buf[3U] = 0U;
        vlSelfRef.axi4_stream__DOT__k_buf[0U] = 0U;
        vlSelfRef.axi4_stream__DOT__k_buf[1U] = 0U;
        vlSelfRef.axi4_stream__DOT__k_buf[2U] = 0U;
        vlSelfRef.axi4_stream__DOT__k_buf[3U] = 0U;
    }
    vlSelfRef.s_tready = (1U == (IData)(vlSelfRef.axi4_stream__DOT__state));
    vlSelfRef.done = (4U == (IData)(vlSelfRef.axi4_stream__DOT__state));
    vlSelfRef.m_tvalid = (3U == (IData)(vlSelfRef.axi4_stream__DOT__state));
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

void Vaxi4_stream___024root___eval_triggers__act(Vaxi4_stream___024root* vlSelf);

bool Vaxi4_stream___024root___eval_phase__act(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_phase__act\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vaxi4_stream___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vaxi4_stream___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vaxi4_stream___024root___eval_phase__nba(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_phase__nba\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vaxi4_stream___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi4_stream___024root___dump_triggers__nba(Vaxi4_stream___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi4_stream___024root___dump_triggers__act(Vaxi4_stream___024root* vlSelf);
#endif  // VL_DEBUG

void Vaxi4_stream___024root___eval(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vaxi4_stream___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/axi4_stream.sv", 26, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vaxi4_stream___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/axi4_stream.sv", 26, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vaxi4_stream___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vaxi4_stream___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vaxi4_stream___024root___eval_debug_assertions(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_debug_assertions\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.s_tvalid & 0xfeU)))) {
        Verilated::overWidthError("s_tvalid");}
    if (VL_UNLIKELY(((vlSelfRef.s_tlast & 0xfeU)))) {
        Verilated::overWidthError("s_tlast");}
    if (VL_UNLIKELY(((vlSelfRef.m_tready & 0xfeU)))) {
        Verilated::overWidthError("m_tready");}
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");}
}
#endif  // VL_DEBUG
