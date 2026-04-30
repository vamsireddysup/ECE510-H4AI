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
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+70,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+73,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+75,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+70,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+73,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+75,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+9+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+13,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+16,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+18,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+20,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+17,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+18,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+20,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+26,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+27,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+28,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+29,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+38,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+39,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+40,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+41,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+42,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+43,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+46,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+47,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+48,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+70,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+79,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+80,0,"man_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+81,0,"man_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+1,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"s1_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"s1_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+51,0,"s1_sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+52,0,"s1_sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+53,0,"s1_is_zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"s1_is_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"s1_is_nan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"s1_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"s2_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"s2_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declQuad(c+59,0,"s2_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBit(c+61,0,"s2_is_zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"s2_is_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"s2_is_nan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+64,0,"s2_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"s3_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"s3_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+65,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
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
    bufp->fullIData(oldp+82,(4U),32);
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
    bufp->fullBit(oldp+1,(vlSelfRef.pe__DOT__u_mul__DOT__zero_a));
    bufp->fullBit(oldp+2,(vlSelfRef.pe__DOT__u_mul__DOT__zero_b));
    bufp->fullBit(oldp+3,(vlSelfRef.pe__DOT__u_mul__DOT__inf_a));
    bufp->fullBit(oldp+4,(vlSelfRef.pe__DOT__u_mul__DOT__inf_b));
    bufp->fullBit(oldp+5,(vlSelfRef.pe__DOT__u_mul__DOT__nan_a));
    bufp->fullBit(oldp+6,(vlSelfRef.pe__DOT__u_mul__DOT__nan_b));
    bufp->fullIData(oldp+7,(vlSelfRef.pe__DOT__u_mul__DOT__s3_result),32);
    bufp->fullBit(oldp+8,(vlSelfRef.pe__DOT__u_mul__DOT__s3_valid));
    bufp->fullIData(oldp+9,(vlSelfRef.pe__DOT__prod_buf[0]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.pe__DOT__prod_buf[1]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.pe__DOT__prod_buf[2]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.pe__DOT__prod_buf[3]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.pe__DOT__prod_count),32);
    bufp->fullBit(oldp+14,((4U == vlSelfRef.pe__DOT__prod_count)));
    bufp->fullCData(oldp+15,(vlSelfRef.pe__DOT__acc_state),2);
    bufp->fullIData(oldp+16,(vlSelfRef.pe__DOT__add_idx),32);
    bufp->fullIData(oldp+17,(vlSelfRef.pe__DOT__acc),32);
    bufp->fullBit(oldp+18,(vlSelfRef.pe__DOT__acc_valid_in));
    bufp->fullIData(oldp+19,(vlSelfRef.pe__DOT__add_result),32);
    bufp->fullBit(oldp+20,(vlSelfRef.pe__DOT__add_valid));
    bufp->fullBit(oldp+21,(vlSelfRef.pe__DOT__waiting));
    bufp->fullIData(oldp+22,(vlSelfRef.pe__DOT____Vcellinp__u_add__b),32);
    bufp->fullBit(oldp+23,((vlSelfRef.pe__DOT__acc 
                            >> 0x1fU)));
    bufp->fullBit(oldp+24,((vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                            >> 0x1fU)));
    bufp->fullCData(oldp+25,((0xffU & (vlSelfRef.pe__DOT__acc 
                                       >> 0x17U))),8);
    bufp->fullCData(oldp+26,((0xffU & (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                                       >> 0x17U))),8);
    bufp->fullIData(oldp+27,(((0U == (0xffU & (vlSelfRef.pe__DOT__acc 
                                               >> 0x17U)))
                               ? (0x7fffffU & vlSelfRef.pe__DOT__acc)
                               : (0x800000U | (0x7fffffU 
                                               & vlSelfRef.pe__DOT__acc)))),24);
    bufp->fullIData(oldp+28,(((0U == (0xffU & (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                                               >> 0x17U)))
                               ? (0x7fffffU & vlSelfRef.pe__DOT____Vcellinp__u_add__b)
                               : (0x800000U | (0x7fffffU 
                                               & vlSelfRef.pe__DOT____Vcellinp__u_add__b)))),24);
    bufp->fullBit(oldp+29,((IData)(((0x7f800000U == 
                                     (0x7f800000U & vlSelfRef.pe__DOT__acc)) 
                                    & (0U != (0x7fffffU 
                                              & vlSelfRef.pe__DOT__acc))))));
    bufp->fullBit(oldp+30,((IData)(((0x7f800000U == 
                                     (0x7f800000U & vlSelfRef.pe__DOT____Vcellinp__u_add__b)) 
                                    & (0U != (0x7fffffU 
                                              & vlSelfRef.pe__DOT____Vcellinp__u_add__b))))));
    bufp->fullBit(oldp+31,(vlSelfRef.pe__DOT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+32,(vlSelfRef.pe__DOT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+33,(vlSelfRef.pe__DOT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+34,(vlSelfRef.pe__DOT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+35,(vlSelfRef.pe__DOT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+36,(vlSelfRef.pe__DOT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+37,(vlSelfRef.pe__DOT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+38,(vlSelfRef.pe__DOT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+39,(vlSelfRef.pe__DOT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+40,(vlSelfRef.pe__DOT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+41,(vlSelfRef.pe__DOT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+42,(vlSelfRef.pe__DOT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+43,(vlSelfRef.pe__DOT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+44,(vlSelfRef.pe__DOT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+45,(vlSelfRef.pe__DOT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+46,(vlSelfRef.pe__DOT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+47,(vlSelfRef.pe__DOT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+48,(vlSelfRef.pe__DOT__u_add__DOT__add_result_comb),32);
    bufp->fullBit(oldp+49,(vlSelfRef.pe__DOT__u_mul__DOT__s1_sign));
    bufp->fullSData(oldp+50,(vlSelfRef.pe__DOT__u_mul__DOT__s1_exp),10);
    bufp->fullIData(oldp+51,(vlSelfRef.pe__DOT__u_mul__DOT__s1_sig_a),24);
    bufp->fullIData(oldp+52,(vlSelfRef.pe__DOT__u_mul__DOT__s1_sig_b),24);
    bufp->fullBit(oldp+53,(vlSelfRef.pe__DOT__u_mul__DOT__s1_is_zero));
    bufp->fullBit(oldp+54,(vlSelfRef.pe__DOT__u_mul__DOT__s1_is_inf));
    bufp->fullBit(oldp+55,(vlSelfRef.pe__DOT__u_mul__DOT__s1_is_nan));
    bufp->fullBit(oldp+56,(vlSelfRef.pe__DOT__u_mul__DOT__s1_valid));
    bufp->fullBit(oldp+57,(vlSelfRef.pe__DOT__u_mul__DOT__s2_sign));
    bufp->fullSData(oldp+58,(vlSelfRef.pe__DOT__u_mul__DOT__s2_exp),10);
    bufp->fullQData(oldp+59,(vlSelfRef.pe__DOT__u_mul__DOT__s2_product),48);
    bufp->fullBit(oldp+61,(vlSelfRef.pe__DOT__u_mul__DOT__s2_is_zero));
    bufp->fullBit(oldp+62,(vlSelfRef.pe__DOT__u_mul__DOT__s2_is_inf));
    bufp->fullBit(oldp+63,(vlSelfRef.pe__DOT__u_mul__DOT__s2_is_nan));
    bufp->fullBit(oldp+64,(vlSelfRef.pe__DOT__u_mul__DOT__s2_valid));
    bufp->fullIData(oldp+65,(vlSelfRef.pe__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+66,(vlSelfRef.clk));
    bufp->fullBit(oldp+67,(vlSelfRef.rst_n));
    bufp->fullIData(oldp+68,(vlSelfRef.a_in),32);
    bufp->fullIData(oldp+69,(vlSelfRef.b_in),32);
    bufp->fullBit(oldp+70,(vlSelfRef.valid_in));
    bufp->fullIData(oldp+71,(vlSelfRef.a_out),32);
    bufp->fullIData(oldp+72,(vlSelfRef.b_out),32);
    bufp->fullBit(oldp+73,(vlSelfRef.valid_out));
    bufp->fullIData(oldp+74,(vlSelfRef.result),32);
    bufp->fullBit(oldp+75,(vlSelfRef.result_valid));
    bufp->fullBit(oldp+76,((vlSelfRef.a_in >> 0x1fU)));
    bufp->fullBit(oldp+77,((vlSelfRef.b_in >> 0x1fU)));
    bufp->fullCData(oldp+78,((0xffU & (vlSelfRef.a_in 
                                       >> 0x17U))),8);
    bufp->fullCData(oldp+79,((0xffU & (vlSelfRef.b_in 
                                       >> 0x17U))),8);
    bufp->fullIData(oldp+80,((0x7fffffU & vlSelfRef.a_in)),23);
    bufp->fullIData(oldp+81,((0x7fffffU & vlSelfRef.b_in)),23);
}
