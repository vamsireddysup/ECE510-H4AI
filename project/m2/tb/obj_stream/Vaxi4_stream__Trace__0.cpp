// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaxi4_stream__Syms.h"


void Vaxi4_stream___024root__trace_chg_0_sub_0(Vaxi4_stream___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vaxi4_stream___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root__trace_chg_0\n"); );
    // Init
    Vaxi4_stream___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi4_stream___024root*>(voidSelf);
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vaxi4_stream___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vaxi4_stream___024root__trace_chg_0_sub_0(Vaxi4_stream___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root__trace_chg_0_sub_0\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.axi4_stream__DOT__state),3);
        bufp->chgIData(oldp+1,(vlSelfRef.axi4_stream__DOT__q_buf[0]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.axi4_stream__DOT__q_buf[1]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.axi4_stream__DOT__q_buf[2]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.axi4_stream__DOT__q_buf[3]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.axi4_stream__DOT__k_buf[0]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.axi4_stream__DOT__k_buf[1]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.axi4_stream__DOT__k_buf[2]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.axi4_stream__DOT__k_buf[3]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.axi4_stream__DOT__recv_count),32);
        bufp->chgIData(oldp+10,(vlSelfRef.axi4_stream__DOT__a_out[0]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.axi4_stream__DOT__a_out[1]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.axi4_stream__DOT__a_out[2]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.axi4_stream__DOT__a_out[3]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.axi4_stream__DOT__b_out[0]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.axi4_stream__DOT__b_out[1]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.axi4_stream__DOT__b_out[2]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.axi4_stream__DOT__b_out[3]),32);
        bufp->chgBit(oldp+18,(vlSelfRef.axi4_stream__DOT__core_valid));
        bufp->chgIData(oldp+19,(vlSelfRef.axi4_stream__DOT__score_buf[0]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.axi4_stream__DOT__score_buf[1]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.axi4_stream__DOT__score_buf[2]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.axi4_stream__DOT__score_buf[3]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.axi4_stream__DOT__score_buf[4]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.axi4_stream__DOT__score_buf[5]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.axi4_stream__DOT__score_buf[6]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.axi4_stream__DOT__score_buf[7]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.axi4_stream__DOT__score_buf[8]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.axi4_stream__DOT__score_buf[9]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.axi4_stream__DOT__score_buf[10]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.axi4_stream__DOT__score_buf[11]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.axi4_stream__DOT__score_buf[12]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.axi4_stream__DOT__score_buf[13]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.axi4_stream__DOT__score_buf[14]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.axi4_stream__DOT__score_buf[15]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.axi4_stream__DOT__send_count),32);
        bufp->chgIData(oldp+36,(vlSelfRef.axi4_stream__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+37,(vlSelfRef.axi4_stream__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+38,(vlSelfRef.axi4_stream__DOT__unnamedblk3__DOT__i),32);
    }
    bufp->chgBit(oldp+39,(vlSelfRef.clk));
    bufp->chgBit(oldp+40,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+41,(vlSelfRef.s_tvalid));
    bufp->chgBit(oldp+42,(vlSelfRef.s_tready));
    bufp->chgQData(oldp+43,(vlSelfRef.s_tdata),64);
    bufp->chgBit(oldp+45,(vlSelfRef.s_tlast));
    bufp->chgBit(oldp+46,(vlSelfRef.m_tvalid));
    bufp->chgBit(oldp+47,(vlSelfRef.m_tready));
    bufp->chgQData(oldp+48,(vlSelfRef.m_tdata),64);
    bufp->chgBit(oldp+50,(vlSelfRef.m_tlast));
    bufp->chgBit(oldp+51,(vlSelfRef.start));
    bufp->chgBit(oldp+52,(vlSelfRef.done));
}

void Vaxi4_stream___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root__trace_cleanup\n"); );
    // Init
    Vaxi4_stream___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi4_stream___024root*>(voidSelf);
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
