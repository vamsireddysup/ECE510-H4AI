// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfp4_mul__Syms.h"


void Vfp4_mul___024root__trace_chg_0_sub_0(Vfp4_mul___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfp4_mul___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root__trace_chg_0\n"); );
    // Init
    Vfp4_mul___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfp4_mul___024root*>(voidSelf);
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfp4_mul___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vfp4_mul___024root__trace_chg_0_sub_0(Vfp4_mul___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root__trace_chg_0_sub_0\n"); );
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgCData(oldp+2,(vlSelfRef.a),4);
    bufp->chgCData(oldp+3,(vlSelfRef.b),4);
    bufp->chgBit(oldp+4,(vlSelfRef.valid_in));
    bufp->chgIData(oldp+5,(vlSelfRef.result),32);
    bufp->chgBit(oldp+6,(vlSelfRef.valid_out));
    bufp->chgIData(oldp+7,(vlSelfRef.fp4_mul__DOT__lut_result),32);
}

void Vfp4_mul___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfp4_mul___024root__trace_cleanup\n"); );
    // Init
    Vfp4_mul___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfp4_mul___024root*>(voidSelf);
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
