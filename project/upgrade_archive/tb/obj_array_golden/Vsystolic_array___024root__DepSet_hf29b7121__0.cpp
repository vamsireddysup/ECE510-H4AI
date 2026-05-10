// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array___024root.h"

void Vsystolic_array___024root___ico_sequent__TOP__0(Vsystolic_array___024root* vlSelf);

void Vsystolic_array___024root___eval_ico(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_ico\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vsystolic_array___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vsystolic_array___024root___ico_sequent__TOP__0(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___ico_sequent__TOP__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.systolic_array__DOT__a_in[0U] = vlSelfRef.a_in
        [0U];
    vlSelfRef.systolic_array__DOT__a_in[1U] = vlSelfRef.a_in
        [1U];
    vlSelfRef.systolic_array__DOT__a_in[2U] = vlSelfRef.a_in
        [2U];
    vlSelfRef.systolic_array__DOT__a_in[3U] = vlSelfRef.a_in
        [3U];
    vlSelfRef.systolic_array__DOT__b_in[0U] = vlSelfRef.b_in
        [0U];
    vlSelfRef.systolic_array__DOT__b_in[1U] = vlSelfRef.b_in
        [1U];
    vlSelfRef.systolic_array__DOT__b_in[2U] = vlSelfRef.b_in
        [2U];
    vlSelfRef.systolic_array__DOT__b_in[3U] = vlSelfRef.b_in
        [3U];
}

void Vsystolic_array___024root___eval_triggers__ico(Vsystolic_array___024root* vlSelf);

bool Vsystolic_array___024root___eval_phase__ico(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_phase__ico\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vsystolic_array___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vsystolic_array___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vsystolic_array___024root___eval_act(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_act\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vsystolic_array___024root___eval_triggers__act(Vsystolic_array___024root* vlSelf);

bool Vsystolic_array___024root___eval_phase__act(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_phase__act\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsystolic_array___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsystolic_array___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vsystolic_array___024root___eval_nba(Vsystolic_array___024root* vlSelf);

bool Vsystolic_array___024root___eval_phase__nba(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_phase__nba\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsystolic_array___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__ico(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__nba(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__act(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG

void Vsystolic_array___024root___eval(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vsystolic_array___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../rtl/systolic_array.sv", 37, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vsystolic_array___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsystolic_array___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/systolic_array.sv", 37, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsystolic_array___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/systolic_array.sv", 37, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsystolic_array___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsystolic_array___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsystolic_array___024root___eval_debug_assertions(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_debug_assertions\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.valid_in & 0xfeU)))) {
        Verilated::overWidthError("valid_in");}
}
#endif  // VL_DEBUG
