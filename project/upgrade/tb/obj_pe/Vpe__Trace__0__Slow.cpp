// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpe__Syms.h"


VL_ATTR_COLD void Vpe___024root__trace_init_sub__TOP__0(Vpe___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root__trace_init_sub__TOP__0\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+44,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+47,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+48,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+50,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+51,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+53,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+55,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+44,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+47,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+48,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+50,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+51,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+53,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+2,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+3+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+7,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+10,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+12,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+44,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+12,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+20,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+21,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+22,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+23,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+32,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+33,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+34,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+35,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+36,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+37,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+39,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+40,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+41,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+42,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+44,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+47,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+48,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+2,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+46,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+47,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+54,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+43,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpe___024root__trace_init_top(Vpe___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root__trace_init_top\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vpe___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vpe___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vpe___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpe___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpe___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vpe___024root__trace_register(Vpe___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root__trace_register\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vpe___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vpe___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vpe___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vpe___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vpe___024root__trace_const_0_sub_0(Vpe___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpe___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root__trace_const_0\n"); );
    // Init
    Vpe___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpe___024root*>(voidSelf);
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vpe___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpe___024root__trace_const_0_sub_0(Vpe___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root__trace_const_0_sub_0\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+55,(4U),32);
}

VL_ATTR_COLD void Vpe___024root__trace_full_0_sub_0(Vpe___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpe___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root__trace_full_0\n"); );
    // Init
    Vpe___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpe___024root*>(voidSelf);
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vpe___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpe___024root__trace_full_0_sub_0(Vpe___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root__trace_full_0_sub_0\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.pe__DOT__product),32);
    bufp->fullBit(oldp+2,(vlSelfRef.pe__DOT__product_valid));
    bufp->fullIData(oldp+3,(vlSelfRef.pe__DOT__prod_buf[0]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.pe__DOT__prod_buf[1]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.pe__DOT__prod_buf[2]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.pe__DOT__prod_buf[3]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.pe__DOT__prod_count),32);
    bufp->fullBit(oldp+8,((4U == vlSelfRef.pe__DOT__prod_count)));
    bufp->fullCData(oldp+9,(vlSelfRef.pe__DOT__acc_state),2);
    bufp->fullIData(oldp+10,(vlSelfRef.pe__DOT__add_idx),32);
    bufp->fullIData(oldp+11,(vlSelfRef.pe__DOT__acc),32);
    bufp->fullBit(oldp+12,(vlSelfRef.pe__DOT__acc_valid_in));
    bufp->fullIData(oldp+13,(vlSelfRef.pe__DOT__add_result),32);
    bufp->fullBit(oldp+14,(vlSelfRef.pe__DOT__add_valid));
    bufp->fullBit(oldp+15,(vlSelfRef.pe__DOT__waiting));
    bufp->fullIData(oldp+16,(vlSelfRef.pe__DOT____Vcellinp__u_add__b),32);
    bufp->fullBit(oldp+17,((vlSelfRef.pe__DOT__acc 
                            >> 0x1fU)));
    bufp->fullBit(oldp+18,((vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                            >> 0x1fU)));
    bufp->fullCData(oldp+19,((0xffU & (vlSelfRef.pe__DOT__acc 
                                       >> 0x17U))),8);
    bufp->fullCData(oldp+20,((0xffU & (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                                       >> 0x17U))),8);
    bufp->fullIData(oldp+21,(((0U == (0xffU & (vlSelfRef.pe__DOT__acc 
                                               >> 0x17U)))
                               ? (0x7fffffU & vlSelfRef.pe__DOT__acc)
                               : (0x800000U | (0x7fffffU 
                                               & vlSelfRef.pe__DOT__acc)))),24);
    bufp->fullIData(oldp+22,(((0U == (0xffU & (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                                               >> 0x17U)))
                               ? (0x7fffffU & vlSelfRef.pe__DOT____Vcellinp__u_add__b)
                               : (0x800000U | (0x7fffffU 
                                               & vlSelfRef.pe__DOT____Vcellinp__u_add__b)))),24);
    bufp->fullBit(oldp+23,((IData)(((0x7f800000U == 
                                     (0x7f800000U & vlSelfRef.pe__DOT__acc)) 
                                    & (0U != (0x7fffffU 
                                              & vlSelfRef.pe__DOT__acc))))));
    bufp->fullBit(oldp+24,((IData)(((0x7f800000U == 
                                     (0x7f800000U & vlSelfRef.pe__DOT____Vcellinp__u_add__b)) 
                                    & (0U != (0x7fffffU 
                                              & vlSelfRef.pe__DOT____Vcellinp__u_add__b))))));
    bufp->fullBit(oldp+25,(vlSelfRef.pe__DOT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+26,(vlSelfRef.pe__DOT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+27,(vlSelfRef.pe__DOT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+28,(vlSelfRef.pe__DOT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+29,(vlSelfRef.pe__DOT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+30,(vlSelfRef.pe__DOT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+31,(vlSelfRef.pe__DOT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+32,(vlSelfRef.pe__DOT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+33,(vlSelfRef.pe__DOT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+34,(vlSelfRef.pe__DOT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+35,(vlSelfRef.pe__DOT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+36,(vlSelfRef.pe__DOT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+37,(vlSelfRef.pe__DOT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+38,(vlSelfRef.pe__DOT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+39,(vlSelfRef.pe__DOT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+40,(vlSelfRef.pe__DOT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+41,(vlSelfRef.pe__DOT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+42,(vlSelfRef.pe__DOT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+43,(vlSelfRef.pe__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+44,(vlSelfRef.clk));
    bufp->fullBit(oldp+45,(vlSelfRef.rst_n));
    bufp->fullCData(oldp+46,(vlSelfRef.a_in),4);
    bufp->fullCData(oldp+47,(vlSelfRef.b_in),4);
    bufp->fullBit(oldp+48,(vlSelfRef.valid_in));
    bufp->fullCData(oldp+49,(vlSelfRef.a_out),4);
    bufp->fullCData(oldp+50,(vlSelfRef.b_out),4);
    bufp->fullBit(oldp+51,(vlSelfRef.valid_out));
    bufp->fullIData(oldp+52,(vlSelfRef.result),32);
    bufp->fullBit(oldp+53,(vlSelfRef.result_valid));
    bufp->fullIData(oldp+54,(vlSelfRef.pe__DOT__u_mul__DOT__lut_result),32);
}
