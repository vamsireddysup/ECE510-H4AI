// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder4.h for the primary calling header

#include "Vadder4__pch.h"
#include "Vadder4__Syms.h"
#include "Vadder4___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder4___024root___dump_triggers__ico(Vadder4___024root* vlSelf);
#endif  // VL_DEBUG

void Vadder4___024root___eval_triggers__ico(Vadder4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder4___024root___eval_triggers__ico\n"); );
    Vadder4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadder4___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder4___024root___dump_triggers__act(Vadder4___024root* vlSelf);
#endif  // VL_DEBUG

void Vadder4___024root___eval_triggers__act(Vadder4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder4___024root___eval_triggers__act\n"); );
    Vadder4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadder4___024root___dump_triggers__act(vlSelf);
    }
#endif
}
