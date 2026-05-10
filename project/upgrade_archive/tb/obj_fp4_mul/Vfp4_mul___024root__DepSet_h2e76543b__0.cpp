// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfp4_mul.h for the primary calling header

#include "Vfp4_mul__pch.h"
#include "Vfp4_mul___024root.h"

void Vfp4_mul___024root___ico_sequent__TOP__0(Vfp4_mul___024root* vlSelf);

void Vfp4_mul___024root___eval_ico(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_ico\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vfp4_mul___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<IData/*31:0*/, 256> Vfp4_mul__ConstPool__TABLE_h44ff92f3_0;

VL_INLINE_OPT void Vfp4_mul___024root___ico_sequent__TOP__0(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___ico_sequent__TOP__0\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.b) << 4U) | (IData)(vlSelfRef.a));
    vlSelfRef.fp4_mul__DOT__lut_result = Vfp4_mul__ConstPool__TABLE_h44ff92f3_0
        [__Vtableidx1];
}

void Vfp4_mul___024root___eval_triggers__ico(Vfp4_mul___024root* vlSelf);

bool Vfp4_mul___024root___eval_phase__ico(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_phase__ico\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vfp4_mul___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vfp4_mul___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vfp4_mul___024root___eval_act(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_act\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vfp4_mul___024root___nba_sequent__TOP__0(Vfp4_mul___024root* vlSelf);

void Vfp4_mul___024root___eval_nba(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_nba\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vfp4_mul___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vfp4_mul___024root___nba_sequent__TOP__0(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___nba_sequent__TOP__0\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.valid_out = ((IData)(vlSelfRef.rst_n) 
                           && (IData)(vlSelfRef.valid_in));
    vlSelfRef.result = ((IData)(vlSelfRef.rst_n) ? vlSelfRef.fp4_mul__DOT__lut_result
                         : 0U);
}

void Vfp4_mul___024root___eval_triggers__act(Vfp4_mul___024root* vlSelf);

bool Vfp4_mul___024root___eval_phase__act(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_phase__act\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfp4_mul___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vfp4_mul___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfp4_mul___024root___eval_phase__nba(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_phase__nba\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfp4_mul___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfp4_mul___024root___dump_triggers__ico(Vfp4_mul___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfp4_mul___024root___dump_triggers__nba(Vfp4_mul___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfp4_mul___024root___dump_triggers__act(Vfp4_mul___024root* vlSelf);
#endif  // VL_DEBUG

void Vfp4_mul___024root___eval(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vfp4_mul___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../rtl/fp4_mul.sv", 38, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vfp4_mul___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vfp4_mul___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/fp4_mul.sv", 38, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vfp4_mul___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/fp4_mul.sv", 38, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vfp4_mul___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vfp4_mul___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfp4_mul___024root___eval_debug_assertions(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_debug_assertions\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.a & 0xf0U)))) {
        Verilated::overWidthError("a");}
    if (VL_UNLIKELY(((vlSelfRef.b & 0xf0U)))) {
        Verilated::overWidthError("b");}
    if (VL_UNLIKELY(((vlSelfRef.valid_in & 0xfeU)))) {
        Verilated::overWidthError("valid_in");}
}
#endif  // VL_DEBUG
