// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi4_stream.h for the primary calling header

#include "Vaxi4_stream__pch.h"
#include "Vaxi4_stream__Syms.h"
#include "Vaxi4_stream___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi4_stream___024root___dump_triggers__act(Vaxi4_stream___024root* vlSelf);
#endif  // VL_DEBUG

void Vaxi4_stream___024root___eval_triggers__act(Vaxi4_stream___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root___eval_triggers__act\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vaxi4_stream___024root___dump_triggers__act(vlSelf);
    }
#endif
}
