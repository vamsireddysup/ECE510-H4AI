// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaxi4_stream__Syms.h"


VL_ATTR_COLD void Vaxi4_stream___024root__trace_init_sub__TOP__0(Vaxi4_stream___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root__trace_init_sub__TOP__0\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+40,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"s_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"s_tready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+44,0,"s_tdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+46,0,"s_tlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"m_tvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"m_tready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+49,0,"m_tdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+51,0,"m_tlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("axi4_stream", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+54,0,"SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+54,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+40,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"s_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"s_tready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+44,0,"s_tdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+46,0,"s_tlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"m_tvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"m_tready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+49,0,"m_tdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+51,0,"m_tlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("q_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+2+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("k_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+6+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+10,0,"recv_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_out", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("b_out", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+19,0,"core_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("score_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+20+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+36,0,"send_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"total_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+37,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+38,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+39,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vaxi4_stream___024root__trace_init_top(Vaxi4_stream___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root__trace_init_top\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaxi4_stream___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vaxi4_stream___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vaxi4_stream___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaxi4_stream___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaxi4_stream___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vaxi4_stream___024root__trace_register(Vaxi4_stream___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root__trace_register\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vaxi4_stream___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vaxi4_stream___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vaxi4_stream___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vaxi4_stream___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vaxi4_stream___024root__trace_const_0_sub_0(Vaxi4_stream___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaxi4_stream___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root__trace_const_0\n"); );
    // Init
    Vaxi4_stream___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi4_stream___024root*>(voidSelf);
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vaxi4_stream___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaxi4_stream___024root__trace_const_0_sub_0(Vaxi4_stream___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root__trace_const_0_sub_0\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+54,(4U),32);
    bufp->fullIData(oldp+55,(0x10U),32);
}

VL_ATTR_COLD void Vaxi4_stream___024root__trace_full_0_sub_0(Vaxi4_stream___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaxi4_stream___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root__trace_full_0\n"); );
    // Init
    Vaxi4_stream___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi4_stream___024root*>(voidSelf);
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vaxi4_stream___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaxi4_stream___024root__trace_full_0_sub_0(Vaxi4_stream___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_stream___024root__trace_full_0_sub_0\n"); );
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelfRef.axi4_stream__DOT__state),3);
    bufp->fullIData(oldp+2,(vlSelfRef.axi4_stream__DOT__q_buf[0]),32);
    bufp->fullIData(oldp+3,(vlSelfRef.axi4_stream__DOT__q_buf[1]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.axi4_stream__DOT__q_buf[2]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.axi4_stream__DOT__q_buf[3]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.axi4_stream__DOT__k_buf[0]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.axi4_stream__DOT__k_buf[1]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.axi4_stream__DOT__k_buf[2]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.axi4_stream__DOT__k_buf[3]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.axi4_stream__DOT__recv_count),32);
    bufp->fullIData(oldp+11,(vlSelfRef.axi4_stream__DOT__a_out[0]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.axi4_stream__DOT__a_out[1]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.axi4_stream__DOT__a_out[2]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.axi4_stream__DOT__a_out[3]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.axi4_stream__DOT__b_out[0]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.axi4_stream__DOT__b_out[1]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.axi4_stream__DOT__b_out[2]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.axi4_stream__DOT__b_out[3]),32);
    bufp->fullBit(oldp+19,(vlSelfRef.axi4_stream__DOT__core_valid));
    bufp->fullIData(oldp+20,(vlSelfRef.axi4_stream__DOT__score_buf[0]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.axi4_stream__DOT__score_buf[1]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.axi4_stream__DOT__score_buf[2]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.axi4_stream__DOT__score_buf[3]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.axi4_stream__DOT__score_buf[4]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.axi4_stream__DOT__score_buf[5]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.axi4_stream__DOT__score_buf[6]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.axi4_stream__DOT__score_buf[7]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.axi4_stream__DOT__score_buf[8]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.axi4_stream__DOT__score_buf[9]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.axi4_stream__DOT__score_buf[10]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.axi4_stream__DOT__score_buf[11]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.axi4_stream__DOT__score_buf[12]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.axi4_stream__DOT__score_buf[13]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.axi4_stream__DOT__score_buf[14]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.axi4_stream__DOT__score_buf[15]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.axi4_stream__DOT__send_count),32);
    bufp->fullIData(oldp+37,(vlSelfRef.axi4_stream__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+38,(vlSelfRef.axi4_stream__DOT__unnamedblk2__DOT__i),32);
    bufp->fullIData(oldp+39,(vlSelfRef.axi4_stream__DOT__unnamedblk3__DOT__i),32);
    bufp->fullBit(oldp+40,(vlSelfRef.clk));
    bufp->fullBit(oldp+41,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+42,(vlSelfRef.s_tvalid));
    bufp->fullBit(oldp+43,(vlSelfRef.s_tready));
    bufp->fullQData(oldp+44,(vlSelfRef.s_tdata),64);
    bufp->fullBit(oldp+46,(vlSelfRef.s_tlast));
    bufp->fullBit(oldp+47,(vlSelfRef.m_tvalid));
    bufp->fullBit(oldp+48,(vlSelfRef.m_tready));
    bufp->fullQData(oldp+49,(vlSelfRef.m_tdata),64);
    bufp->fullBit(oldp+51,(vlSelfRef.m_tlast));
    bufp->fullBit(oldp+52,(vlSelfRef.start));
    bufp->fullBit(oldp+53,(vlSelfRef.done));
}
