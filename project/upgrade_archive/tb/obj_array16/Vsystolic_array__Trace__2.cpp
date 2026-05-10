// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsystolic_array__Syms.h"


void Vsystolic_array___024root__trace_chg_0_sub_2(Vsystolic_array___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_chg_0_sub_2\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 11872);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+0,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+1,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+2,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+3,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+4,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+5,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+6,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+7,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+8,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+9,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+10,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+11,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+12,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+13,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+14,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+15,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+16,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+17,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+18,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+19,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+20,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
        bufp->chgBit(oldp+21,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
        bufp->chgCData(oldp+22,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
        bufp->chgCData(oldp+23,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
        bufp->chgIData(oldp+24,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+25,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+26,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+27,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+28,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+29,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+30,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+31,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+32,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+33,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+34,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+35,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+36,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+37,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+38,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+39,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+40,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+41,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+42,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+43,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+44,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+45,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+46,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+47,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+48,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xeU][9U]),4);
        bufp->chgCData(oldp+49,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xeU][9U]),4);
        bufp->chgBit(oldp+50,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xeU][9U]));
        bufp->chgCData(oldp+51,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+52,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+53,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+54,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+55,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+56,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+57,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+58,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+59,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+60,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+61,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+62,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+63,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+64,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+65,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+66,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+67,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+68,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+69,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+70,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+71,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
        bufp->chgBit(oldp+72,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
        bufp->chgCData(oldp+73,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
        bufp->chgCData(oldp+74,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
        bufp->chgIData(oldp+75,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+76,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+77,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+78,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+79,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+80,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+81,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+82,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+83,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+84,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+85,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+86,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+87,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+88,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+89,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+90,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+91,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+92,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+93,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+94,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+95,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+96,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+97,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+98,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+99,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xeU][0xaU]),4);
        bufp->chgCData(oldp+100,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xeU][0xaU]),4);
        bufp->chgBit(oldp+101,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xeU][0xaU]));
        bufp->chgCData(oldp+102,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+103,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+104,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+105,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+106,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+107,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+108,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+109,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+110,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+111,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+112,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+113,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+114,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+115,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+116,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+117,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+118,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+119,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+120,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+121,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+122,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+123,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+124,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+125,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+126,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+127,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+128,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+129,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+130,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+131,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+132,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+133,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+134,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+135,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+136,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+137,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+138,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+139,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+140,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+141,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+142,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+143,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+144,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+145,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+146,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+147,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+148,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+149,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+150,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xeU][0xbU]),4);
        bufp->chgCData(oldp+151,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xeU][0xbU]),4);
        bufp->chgBit(oldp+152,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xeU][0xbU]));
        bufp->chgCData(oldp+153,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+154,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+155,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+156,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+157,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+158,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+159,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+160,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+161,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+162,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+163,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+164,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+165,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+166,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+167,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+168,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+169,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+170,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+171,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+172,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+173,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+174,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+175,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+176,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+177,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+178,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+179,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+180,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+181,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+182,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+183,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+184,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+185,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+186,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+187,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+188,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+189,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+190,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+191,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+192,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+193,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+194,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+195,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+196,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+197,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+198,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+199,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+200,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+201,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xeU][0xcU]),4);
        bufp->chgCData(oldp+202,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xeU][0xcU]),4);
        bufp->chgBit(oldp+203,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xeU][0xcU]));
        bufp->chgCData(oldp+204,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+205,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+206,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+207,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+208,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+209,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+210,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+211,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+212,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+213,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+214,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+215,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+216,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+217,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+218,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+219,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+220,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+221,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+222,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+223,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+224,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+225,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+226,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+227,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+228,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+229,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+230,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+231,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+232,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+233,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+234,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+235,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+236,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+237,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+238,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+239,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+240,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+241,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+242,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+243,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+244,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+245,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+246,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+247,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+248,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+249,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+250,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+251,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+252,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xeU][0xdU]),4);
        bufp->chgCData(oldp+253,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xeU][0xdU]),4);
        bufp->chgBit(oldp+254,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xeU][0xdU]));
        bufp->chgCData(oldp+255,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+256,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+257,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+258,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+259,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+260,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+261,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+262,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+263,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+264,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+265,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+266,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+267,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+268,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+269,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+270,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+271,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+272,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+273,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+274,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+275,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+276,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+277,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+278,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+279,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+280,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+281,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+282,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+283,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+284,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+285,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+286,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+287,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+288,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+289,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+290,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+291,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+292,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+293,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+294,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+295,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+296,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+297,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+298,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+299,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+300,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+301,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+302,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+303,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xeU][0xeU]),4);
        bufp->chgCData(oldp+304,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xeU][0xeU]),4);
        bufp->chgBit(oldp+305,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xeU][0xeU]));
        bufp->chgCData(oldp+306,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+307,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+308,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+309,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+310,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+311,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+312,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+313,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+314,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+315,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+316,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+317,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+318,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+319,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+320,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+321,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+322,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+323,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+324,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+325,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+326,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+327,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+328,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+329,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+330,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+331,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+332,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+333,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+334,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+335,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+336,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+337,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+338,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+339,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+340,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+341,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+342,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+343,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+344,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+345,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+346,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+347,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+348,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+349,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+350,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+351,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+352,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+353,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+354,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xeU][0xfU]),4);
        bufp->chgCData(oldp+355,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xeU][0xfU]),4);
        bufp->chgBit(oldp+356,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xeU][0xfU]));
        bufp->chgCData(oldp+357,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+358,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+359,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+360,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+361,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+362,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+363,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+364,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+365,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+366,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+367,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+368,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+369,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+370,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+371,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+372,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+373,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+374,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+375,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+376,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+377,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+378,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+379,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+380,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+381,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+382,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+383,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+384,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+385,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+386,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+387,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+388,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+389,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+390,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+391,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+392,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+393,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+394,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+395,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+396,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+397,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+398,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+399,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+400,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+401,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+402,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+403,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+404,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+405,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][0U]),4);
        bufp->chgCData(oldp+406,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][0U]),4);
        bufp->chgBit(oldp+407,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][0U]));
        bufp->chgCData(oldp+408,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+409,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+410,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+411,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+412,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+413,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+414,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+415,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+416,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+417,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+418,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+419,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+420,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+421,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+422,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+423,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+424,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+425,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+426,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+427,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+428,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+429,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+430,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+431,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+432,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+433,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+434,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+435,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+436,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+437,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+438,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+439,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+440,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+441,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+442,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+443,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+444,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+445,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+446,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+447,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+448,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+449,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+450,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+451,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+452,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+453,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+454,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+455,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+456,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][1U]),4);
        bufp->chgCData(oldp+457,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][1U]),4);
        bufp->chgBit(oldp+458,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][1U]));
        bufp->chgCData(oldp+459,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+460,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+461,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+462,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+463,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+464,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+465,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+466,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+467,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+468,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+469,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+470,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+471,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+472,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+473,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+474,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+475,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+476,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+477,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+478,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+479,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+480,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+481,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+482,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+483,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+484,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+485,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+486,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+487,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+488,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+489,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+490,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+491,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+492,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+493,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+494,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+495,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+496,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+497,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+498,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+499,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+500,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+501,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+502,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+503,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+504,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+505,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+506,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+507,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][2U]),4);
        bufp->chgCData(oldp+508,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][2U]),4);
        bufp->chgBit(oldp+509,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][2U]));
        bufp->chgCData(oldp+510,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+511,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+512,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+513,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+514,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+515,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+516,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+517,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+518,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+519,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+520,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+521,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+522,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+523,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+524,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+525,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+526,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+527,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+528,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+529,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+530,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+531,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+532,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+533,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+534,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+535,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+536,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+537,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+538,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+539,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+540,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+541,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+542,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+543,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+544,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+545,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+546,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+547,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+548,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+549,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+550,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+551,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+552,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+553,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+554,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+555,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+556,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+557,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+558,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][3U]),4);
        bufp->chgCData(oldp+559,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][3U]),4);
        bufp->chgBit(oldp+560,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][3U]));
        bufp->chgCData(oldp+561,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+562,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+563,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+564,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+565,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+566,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+567,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+568,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+569,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+570,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+571,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+572,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+573,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+574,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+575,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+576,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+577,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+578,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+579,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+580,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+581,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+582,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+583,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+584,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+585,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+586,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+587,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+588,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+589,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+590,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+591,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+592,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+593,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+594,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+595,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+596,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+597,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+598,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+599,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+600,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+601,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+602,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+603,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+604,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+605,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+606,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+607,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+608,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+609,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][4U]),4);
        bufp->chgCData(oldp+610,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][4U]),4);
        bufp->chgBit(oldp+611,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][4U]));
        bufp->chgCData(oldp+612,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+613,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+614,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+615,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+616,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+617,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+618,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+619,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+620,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+621,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+622,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+623,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+624,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+625,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+626,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+627,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+628,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+629,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+630,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+631,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+632,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+633,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+634,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+635,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+636,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+637,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+638,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+639,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+640,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+641,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+642,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+643,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+644,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+645,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+646,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+647,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+648,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+649,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+650,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+651,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+652,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+653,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+654,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+655,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+656,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+657,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+658,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+659,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+660,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][5U]),4);
        bufp->chgCData(oldp+661,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][5U]),4);
        bufp->chgBit(oldp+662,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][5U]));
        bufp->chgCData(oldp+663,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+664,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+665,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+666,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+667,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+668,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+669,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+670,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+671,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+672,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+673,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+674,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+675,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+676,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+677,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+678,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+679,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+680,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+681,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+682,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+683,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+684,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+685,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+686,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+687,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+688,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+689,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+690,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+691,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+692,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+693,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+694,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+695,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+696,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+697,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+698,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+699,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+700,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+701,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+702,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+703,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+704,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+705,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+706,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+707,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+708,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+709,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+710,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+711,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][6U]),4);
        bufp->chgCData(oldp+712,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][6U]),4);
        bufp->chgBit(oldp+713,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][6U]));
        bufp->chgCData(oldp+714,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+715,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+716,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+717,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+718,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+719,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+720,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+721,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+722,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+723,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+724,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+725,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+726,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+727,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+728,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+729,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+730,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+731,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+732,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+733,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+734,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+735,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+736,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+737,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+738,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+739,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+740,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+741,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+742,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+743,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+744,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+745,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+746,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+747,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+748,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+749,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+750,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+751,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+752,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+753,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+754,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+755,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+756,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+757,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+758,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+759,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+760,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+761,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+762,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][7U]),4);
        bufp->chgCData(oldp+763,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][7U]),4);
        bufp->chgBit(oldp+764,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][7U]));
        bufp->chgCData(oldp+765,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+766,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+767,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+768,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+769,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+770,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+771,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+772,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+773,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+774,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+775,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+776,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+777,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+778,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+779,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+780,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+781,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+782,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+783,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+784,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+785,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+786,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+787,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+788,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+789,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+790,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+791,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+792,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+793,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+794,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+795,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+796,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+797,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+798,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+799,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+800,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+801,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+802,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+803,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+804,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+805,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+806,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+807,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+808,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+809,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+810,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+811,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+812,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+813,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][8U]),4);
        bufp->chgCData(oldp+814,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][8U]),4);
        bufp->chgBit(oldp+815,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][8U]));
        bufp->chgCData(oldp+816,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+817,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+818,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+819,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+820,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+821,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+822,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+823,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+824,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+825,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+826,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+827,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+828,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+829,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+830,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+831,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+832,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+833,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+834,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+835,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+836,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+837,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+838,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+839,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+840,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+841,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+842,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+843,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+844,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+845,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+846,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+847,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+848,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+849,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+850,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+851,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+852,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+853,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+854,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+855,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+856,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+857,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+858,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+859,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+860,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+861,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+862,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+863,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+864,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][9U]),4);
        bufp->chgCData(oldp+865,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][9U]),4);
        bufp->chgBit(oldp+866,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][9U]));
        bufp->chgCData(oldp+867,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+868,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+869,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+870,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+871,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+872,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+873,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+874,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+875,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+876,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+877,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+878,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+879,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+880,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+881,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+882,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+883,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+884,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+885,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+886,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+887,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+888,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+889,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+890,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+891,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+892,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+893,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+894,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+895,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+896,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+897,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+898,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+899,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+900,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+901,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+902,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+903,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+904,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+905,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+906,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+907,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+908,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+909,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+910,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+911,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+912,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+913,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+914,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+915,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][0xaU]),4);
        bufp->chgCData(oldp+916,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][0xaU]),4);
        bufp->chgBit(oldp+917,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][0xaU]));
        bufp->chgCData(oldp+918,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+919,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+920,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+921,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+922,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+923,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+924,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+925,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+926,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+927,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+928,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+929,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+930,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+931,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+932,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+933,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+934,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+935,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+936,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+937,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+938,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+939,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+940,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+941,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+942,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+943,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+944,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+945,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+946,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+947,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+948,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+949,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+950,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+951,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+952,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+953,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+954,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+955,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+956,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+957,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+958,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+959,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+960,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+961,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+962,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+963,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+964,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+965,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+966,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0xfU][0xbU]),4);
        bufp->chgCData(oldp+967,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0xfU][0xbU]),4);
        bufp->chgBit(oldp+968,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0xfU][0xbU]));
        bufp->chgCData(oldp+969,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+970,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+971,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+972,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+973,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+974,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+975,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+976,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+977,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+978,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+979,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+980,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+981,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+982,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+983,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+984,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+985,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+986,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+987,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+988,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+989,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+990,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+991,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+992,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+993,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+994,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+995,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+996,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+997,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+998,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+999,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+1000,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+1001,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+1002,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+1003,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+1004,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+1005,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+1006,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+1007,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+1008,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+1009,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+1010,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+1011,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+1012,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+1013,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+1014,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+1015,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+1016,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+1017,(vlSelfRef.systolic_array__DOT__a_wire
                                  [0xfU][0xcU]),4);
        bufp->chgCData(oldp+1018,(vlSelfRef.systolic_array__DOT__b_wire
                                  [0xfU][0xcU]),4);
        bufp->chgBit(oldp+1019,(vlSelfRef.systolic_array__DOT__v_wire_a
                                [0xfU][0xcU]));
        bufp->chgCData(oldp+1020,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+1021,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+1022,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+1023,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+1024,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+1025,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+1026,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+1027,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+1028,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+1029,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+1030,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+1031,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+1032,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+1033,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+1034,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+1035,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+1036,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+1037,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+1038,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+1039,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+1040,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                                 >> 0x1fU)));
        bufp->chgBit(oldp+1041,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                 >> 0x1fU)));
        bufp->chgCData(oldp+1042,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1043,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1044,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+1045,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+1046,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+1047,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+1048,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+1049,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+1050,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+1051,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+1052,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+1053,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+1054,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+1055,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+1056,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+1057,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+1058,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+1059,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+1060,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+1061,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+1062,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+1063,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+1064,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+1065,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+1066,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+1067,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+1068,(vlSelfRef.systolic_array__DOT__a_wire
                                  [0xfU][0xdU]),4);
        bufp->chgCData(oldp+1069,(vlSelfRef.systolic_array__DOT__b_wire
                                  [0xfU][0xdU]),4);
        bufp->chgBit(oldp+1070,(vlSelfRef.systolic_array__DOT__v_wire_a
                                [0xfU][0xdU]));
        bufp->chgCData(oldp+1071,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+1072,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+1073,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+1074,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+1075,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+1076,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+1077,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+1078,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+1079,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+1080,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+1081,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+1082,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+1083,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+1084,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+1085,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+1086,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+1087,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+1088,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+1089,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+1090,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+1091,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                                 >> 0x1fU)));
        bufp->chgBit(oldp+1092,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                 >> 0x1fU)));
        bufp->chgCData(oldp+1093,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1094,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1095,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+1096,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+1097,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+1098,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+1099,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+1100,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+1101,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+1102,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+1103,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+1104,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+1105,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+1106,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+1107,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+1108,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+1109,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+1110,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+1111,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+1112,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+1113,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+1114,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+1115,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+1116,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+1117,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+1118,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+1119,(vlSelfRef.systolic_array__DOT__a_wire
                                  [0xfU][0xeU]),4);
        bufp->chgCData(oldp+1120,(vlSelfRef.systolic_array__DOT__b_wire
                                  [0xfU][0xeU]),4);
        bufp->chgBit(oldp+1121,(vlSelfRef.systolic_array__DOT__v_wire_a
                                [0xfU][0xeU]));
        bufp->chgCData(oldp+1122,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+1123,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+1124,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+1125,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+1126,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+1127,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+1128,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+1129,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+1130,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+1131,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+1132,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+1133,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+1134,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+1135,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+1136,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+1137,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+1138,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+1139,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+1140,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+1141,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+1142,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                                 >> 0x1fU)));
        bufp->chgBit(oldp+1143,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                 >> 0x1fU)));
        bufp->chgCData(oldp+1144,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1145,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1146,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+1147,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+1148,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+1149,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+1150,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+1151,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+1152,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+1153,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+1154,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+1155,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+1156,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+1157,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+1158,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+1159,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+1160,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+1161,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+1162,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+1163,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+1164,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+1165,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+1166,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+1167,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+1168,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+1169,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+1170,(vlSelfRef.systolic_array__DOT__a_wire
                                  [0xfU][0xfU]),4);
        bufp->chgCData(oldp+1171,(vlSelfRef.systolic_array__DOT__b_wire
                                  [0xfU][0xfU]),4);
        bufp->chgBit(oldp+1172,(vlSelfRef.systolic_array__DOT__v_wire_a
                                [0xfU][0xfU]));
        bufp->chgCData(oldp+1173,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+1174,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+1175,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+1176,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+1177,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+1178,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+1179,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+1180,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+1181,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+1182,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+1183,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+1184,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+1185,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+1186,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+1187,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+1188,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+1189,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+1190,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+1191,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+1192,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+1193,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                                 >> 0x1fU)));
        bufp->chgBit(oldp+1194,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                 >> 0x1fU)));
        bufp->chgCData(oldp+1195,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1196,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1197,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+1198,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+1199,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+1200,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+1201,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+1202,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+1203,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+1204,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+1205,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+1206,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+1207,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+1208,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+1209,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+1210,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+1211,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+1212,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+1213,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+1214,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+1215,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+1216,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+1217,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+1218,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+1219,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+1220,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+1221,(vlSelfRef.clk));
    bufp->chgBit(oldp+1222,(vlSelfRef.rst_n));
    bufp->chgCData(oldp+1223,(vlSelfRef.a_in[0]),4);
    bufp->chgCData(oldp+1224,(vlSelfRef.a_in[1]),4);
    bufp->chgCData(oldp+1225,(vlSelfRef.a_in[2]),4);
    bufp->chgCData(oldp+1226,(vlSelfRef.a_in[3]),4);
    bufp->chgCData(oldp+1227,(vlSelfRef.a_in[4]),4);
    bufp->chgCData(oldp+1228,(vlSelfRef.a_in[5]),4);
    bufp->chgCData(oldp+1229,(vlSelfRef.a_in[6]),4);
    bufp->chgCData(oldp+1230,(vlSelfRef.a_in[7]),4);
    bufp->chgCData(oldp+1231,(vlSelfRef.a_in[8]),4);
    bufp->chgCData(oldp+1232,(vlSelfRef.a_in[9]),4);
    bufp->chgCData(oldp+1233,(vlSelfRef.a_in[10]),4);
    bufp->chgCData(oldp+1234,(vlSelfRef.a_in[11]),4);
    bufp->chgCData(oldp+1235,(vlSelfRef.a_in[12]),4);
    bufp->chgCData(oldp+1236,(vlSelfRef.a_in[13]),4);
    bufp->chgCData(oldp+1237,(vlSelfRef.a_in[14]),4);
    bufp->chgCData(oldp+1238,(vlSelfRef.a_in[15]),4);
    bufp->chgCData(oldp+1239,(vlSelfRef.b_in[0]),4);
    bufp->chgCData(oldp+1240,(vlSelfRef.b_in[1]),4);
    bufp->chgCData(oldp+1241,(vlSelfRef.b_in[2]),4);
    bufp->chgCData(oldp+1242,(vlSelfRef.b_in[3]),4);
    bufp->chgCData(oldp+1243,(vlSelfRef.b_in[4]),4);
    bufp->chgCData(oldp+1244,(vlSelfRef.b_in[5]),4);
    bufp->chgCData(oldp+1245,(vlSelfRef.b_in[6]),4);
    bufp->chgCData(oldp+1246,(vlSelfRef.b_in[7]),4);
    bufp->chgCData(oldp+1247,(vlSelfRef.b_in[8]),4);
    bufp->chgCData(oldp+1248,(vlSelfRef.b_in[9]),4);
    bufp->chgCData(oldp+1249,(vlSelfRef.b_in[10]),4);
    bufp->chgCData(oldp+1250,(vlSelfRef.b_in[11]),4);
    bufp->chgCData(oldp+1251,(vlSelfRef.b_in[12]),4);
    bufp->chgCData(oldp+1252,(vlSelfRef.b_in[13]),4);
    bufp->chgCData(oldp+1253,(vlSelfRef.b_in[14]),4);
    bufp->chgCData(oldp+1254,(vlSelfRef.b_in[15]),4);
    bufp->chgBit(oldp+1255,(vlSelfRef.valid_in));
    bufp->chgBit(oldp+1256,(vlSelfRef.result_valid));
}

void Vsystolic_array___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_cleanup\n"); );
    // Init
    Vsystolic_array___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsystolic_array___024root*>(voidSelf);
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
