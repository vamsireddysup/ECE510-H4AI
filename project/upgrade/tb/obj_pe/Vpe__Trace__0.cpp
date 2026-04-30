// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpe__Syms.h"


void Vpe___024root__trace_chg_0_sub_0(Vpe___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vpe___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root__trace_chg_0\n"); );
    // Init
    Vpe___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpe___024root*>(voidSelf);
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vpe___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vpe___024root__trace_chg_0_sub_0(Vpe___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root__trace_chg_0_sub_0\n"); );
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.pe__DOT__product),32);
        bufp->chgBit(oldp+1,(vlSelfRef.pe__DOT__product_valid));
        bufp->chgIData(oldp+2,(vlSelfRef.pe__DOT__prod_buf[0]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.pe__DOT__prod_buf[1]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.pe__DOT__prod_buf[2]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.pe__DOT__prod_buf[3]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.pe__DOT__prod_count),32);
        bufp->chgBit(oldp+7,((4U == vlSelfRef.pe__DOT__prod_count)));
        bufp->chgCData(oldp+8,(vlSelfRef.pe__DOT__acc_state),2);
        bufp->chgIData(oldp+9,(vlSelfRef.pe__DOT__add_idx),32);
        bufp->chgIData(oldp+10,(vlSelfRef.pe__DOT__acc),32);
        bufp->chgBit(oldp+11,(vlSelfRef.pe__DOT__acc_valid_in));
        bufp->chgIData(oldp+12,(vlSelfRef.pe__DOT__add_result),32);
        bufp->chgBit(oldp+13,(vlSelfRef.pe__DOT__add_valid));
        bufp->chgBit(oldp+14,(vlSelfRef.pe__DOT__waiting));
        bufp->chgIData(oldp+15,(vlSelfRef.pe__DOT____Vcellinp__u_add__b),32);
        bufp->chgBit(oldp+16,((vlSelfRef.pe__DOT__acc 
                               >> 0x1fU)));
        bufp->chgBit(oldp+17,((vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                               >> 0x1fU)));
        bufp->chgCData(oldp+18,((0xffU & (vlSelfRef.pe__DOT__acc 
                                          >> 0x17U))),8);
        bufp->chgCData(oldp+19,((0xffU & (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                                          >> 0x17U))),8);
        bufp->chgIData(oldp+20,(((0U == (0xffU & (vlSelfRef.pe__DOT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSelfRef.pe__DOT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSelfRef.pe__DOT__acc)))),24);
        bufp->chgIData(oldp+21,(((0U == (0xffU & (vlSelfRef.pe__DOT____Vcellinp__u_add__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSelfRef.pe__DOT____Vcellinp__u_add__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSelfRef.pe__DOT____Vcellinp__u_add__b)))),24);
        bufp->chgBit(oldp+22,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.pe__DOT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.pe__DOT__acc))))));
        bufp->chgBit(oldp+23,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.pe__DOT____Vcellinp__u_add__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.pe__DOT____Vcellinp__u_add__b))))));
        bufp->chgBit(oldp+24,(vlSelfRef.pe__DOT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+25,(vlSelfRef.pe__DOT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+26,(vlSelfRef.pe__DOT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+27,(vlSelfRef.pe__DOT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+28,(vlSelfRef.pe__DOT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+29,(vlSelfRef.pe__DOT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+30,(vlSelfRef.pe__DOT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+31,(vlSelfRef.pe__DOT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+32,(vlSelfRef.pe__DOT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+33,(vlSelfRef.pe__DOT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+34,(vlSelfRef.pe__DOT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+35,(vlSelfRef.pe__DOT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+36,(vlSelfRef.pe__DOT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+37,(vlSelfRef.pe__DOT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+38,(vlSelfRef.pe__DOT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+39,(vlSelfRef.pe__DOT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+40,(vlSelfRef.pe__DOT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+41,(vlSelfRef.pe__DOT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+42,(vlSelfRef.pe__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+43,(vlSelfRef.clk));
    bufp->chgBit(oldp+44,(vlSelfRef.rst_n));
    bufp->chgCData(oldp+45,(vlSelfRef.a_in),4);
    bufp->chgCData(oldp+46,(vlSelfRef.b_in),4);
    bufp->chgBit(oldp+47,(vlSelfRef.valid_in));
    bufp->chgCData(oldp+48,(vlSelfRef.a_out),4);
    bufp->chgCData(oldp+49,(vlSelfRef.b_out),4);
    bufp->chgBit(oldp+50,(vlSelfRef.valid_out));
    bufp->chgIData(oldp+51,(vlSelfRef.result),32);
    bufp->chgBit(oldp+52,(vlSelfRef.result_valid));
    bufp->chgIData(oldp+53,(vlSelfRef.pe__DOT__u_mul__DOT__lut_result),32);
}

void Vpe___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe___024root__trace_cleanup\n"); );
    // Init
    Vpe___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpe___024root*>(voidSelf);
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
