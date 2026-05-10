// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfp4_mul.h for the primary calling header

#include "Vfp4_mul__pch.h"
#include "Vfp4_mul__Syms.h"
#include "Vfp4_mul___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfp4_mul___024root___dump_triggers__stl(Vfp4_mul___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfp4_mul___024root___eval_triggers__stl(Vfp4_mul___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root___eval_triggers__stl\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfp4_mul___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
