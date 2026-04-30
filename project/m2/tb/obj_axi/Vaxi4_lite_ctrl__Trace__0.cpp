// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaxi4_lite_ctrl__Syms.h"


void Vaxi4_lite_ctrl___024root__trace_chg_0_sub_0(Vaxi4_lite_ctrl___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vaxi4_lite_ctrl___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_lite_ctrl___024root__trace_chg_0\n"); );
    // Init
    Vaxi4_lite_ctrl___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi4_lite_ctrl___024root*>(voidSelf);
    Vaxi4_lite_ctrl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vaxi4_lite_ctrl___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vaxi4_lite_ctrl___024root__trace_chg_0_sub_0(Vaxi4_lite_ctrl___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_lite_ctrl___024root__trace_chg_0_sub_0\n"); );
    Vaxi4_lite_ctrl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.axi4_lite_ctrl__DOT__ctrl_reg),32);
        bufp->chgCData(oldp+1,(vlSelfRef.axi4_lite_ctrl__DOT__wstate),2);
        bufp->chgIData(oldp+2,(vlSelfRef.axi4_lite_ctrl__DOT__waddr_lat),32);
        bufp->chgCData(oldp+3,(vlSelfRef.axi4_lite_ctrl__DOT__rstate),2);
        bufp->chgIData(oldp+4,(vlSelfRef.axi4_lite_ctrl__DOT__raddr_lat),32);
    }
    bufp->chgBit(oldp+5,(vlSelfRef.clk));
    bufp->chgBit(oldp+6,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+7,(vlSelfRef.awvalid));
    bufp->chgBit(oldp+8,(vlSelfRef.awready));
    bufp->chgIData(oldp+9,(vlSelfRef.awaddr),32);
    bufp->chgBit(oldp+10,(vlSelfRef.wvalid));
    bufp->chgBit(oldp+11,(vlSelfRef.wready));
    bufp->chgIData(oldp+12,(vlSelfRef.wdata),32);
    bufp->chgCData(oldp+13,(vlSelfRef.wstrb),4);
    bufp->chgBit(oldp+14,(vlSelfRef.bvalid));
    bufp->chgBit(oldp+15,(vlSelfRef.bready));
    bufp->chgCData(oldp+16,(vlSelfRef.bresp),2);
    bufp->chgBit(oldp+17,(vlSelfRef.arvalid));
    bufp->chgBit(oldp+18,(vlSelfRef.arready));
    bufp->chgIData(oldp+19,(vlSelfRef.araddr),32);
    bufp->chgBit(oldp+20,(vlSelfRef.rvalid));
    bufp->chgBit(oldp+21,(vlSelfRef.rready));
    bufp->chgIData(oldp+22,(vlSelfRef.rdata),32);
    bufp->chgCData(oldp+23,(vlSelfRef.rresp),2);
    bufp->chgBit(oldp+24,(vlSelfRef.start));
    bufp->chgBit(oldp+25,(vlSelfRef.done));
    bufp->chgIData(oldp+26,(vlSelfRef.done),32);
}

void Vaxi4_lite_ctrl___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_lite_ctrl___024root__trace_cleanup\n"); );
    // Init
    Vaxi4_lite_ctrl___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi4_lite_ctrl___024root*>(voidSelf);
    Vaxi4_lite_ctrl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
