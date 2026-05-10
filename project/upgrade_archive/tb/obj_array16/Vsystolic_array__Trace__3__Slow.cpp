// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsystolic_array__Syms.h"


VL_ATTR_COLD void Vsystolic_array___024root__trace_full_0_sub_2(Vsystolic_array___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_full_0_sub_2\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+11872,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+11873,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+11874,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+11875,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+11876,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+11877,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+11878,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+11879,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+11880,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+11881,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+11882,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+11883,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+11884,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+11885,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+11886,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+11887,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+11888,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+11889,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+11890,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+11891,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+11892,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+11893,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+11894,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+11895,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+11896,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+11897,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+11898,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+11899,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+11900,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+11901,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+11902,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+11903,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+11904,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+11905,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+11906,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+11907,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+11908,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+11909,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+11910,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+11911,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+11912,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+11913,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+11914,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+11915,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+11916,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+11917,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+11918,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+11919,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+11920,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xeU][9U]),4);
    bufp->fullCData(oldp+11921,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xeU][9U]),4);
    bufp->fullBit(oldp+11922,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xeU][9U]));
    bufp->fullCData(oldp+11923,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+11924,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+11925,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+11926,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+11927,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+11928,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+11929,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+11930,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+11931,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+11932,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+11933,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+11934,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+11935,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+11936,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+11937,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+11938,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+11939,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+11940,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+11941,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+11942,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+11943,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+11944,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+11945,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+11946,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+11947,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+11948,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+11949,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+11950,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+11951,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+11952,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+11953,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+11954,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+11955,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+11956,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+11957,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+11958,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+11959,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+11960,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+11961,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+11962,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+11963,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+11964,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+11965,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+11966,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+11967,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+11968,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+11969,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+11970,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+11971,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xeU][0xaU]),4);
    bufp->fullCData(oldp+11972,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xeU][0xaU]),4);
    bufp->fullBit(oldp+11973,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xeU][0xaU]));
    bufp->fullCData(oldp+11974,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+11975,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+11976,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+11977,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+11978,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+11979,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+11980,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+11981,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+11982,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+11983,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+11984,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+11985,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+11986,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+11987,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+11988,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+11989,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+11990,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+11991,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+11992,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+11993,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+11994,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+11995,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+11996,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+11997,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+11998,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+11999,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12000,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12001,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12002,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12003,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12004,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12005,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12006,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12007,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12008,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12009,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12010,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12011,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12012,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12013,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12014,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12015,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12016,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12017,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12018,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12019,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12020,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12021,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12022,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xeU][0xbU]),4);
    bufp->fullCData(oldp+12023,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xeU][0xbU]),4);
    bufp->fullBit(oldp+12024,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xeU][0xbU]));
    bufp->fullCData(oldp+12025,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12026,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12027,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12028,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12029,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12030,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12031,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12032,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12033,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12034,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12035,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12036,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12037,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12038,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12039,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12040,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12041,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12042,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12043,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12044,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12045,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12046,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12047,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12048,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12049,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12050,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12051,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12052,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12053,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12054,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12055,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12056,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12057,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12058,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12059,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12060,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12061,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12062,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12063,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12064,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12065,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12066,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12067,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12068,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12069,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12070,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12071,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12072,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12073,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xeU][0xcU]),4);
    bufp->fullCData(oldp+12074,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xeU][0xcU]),4);
    bufp->fullBit(oldp+12075,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xeU][0xcU]));
    bufp->fullCData(oldp+12076,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12077,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12078,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12079,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12080,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12081,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12082,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12083,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12084,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12085,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12086,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12087,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12088,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12089,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12090,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12091,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12092,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12093,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12094,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12095,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12096,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12097,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12098,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12099,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12100,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12101,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12102,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12103,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12104,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12105,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12106,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12107,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12108,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12109,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12110,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12111,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12112,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12113,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12114,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12115,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12116,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12117,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12118,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12119,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12120,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12121,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12122,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12123,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12124,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xeU][0xdU]),4);
    bufp->fullCData(oldp+12125,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xeU][0xdU]),4);
    bufp->fullBit(oldp+12126,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xeU][0xdU]));
    bufp->fullCData(oldp+12127,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12128,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12129,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12130,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12131,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12132,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12133,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12134,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12135,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12136,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12137,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12138,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12139,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12140,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12141,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12142,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12143,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12144,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12145,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12146,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12147,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12148,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12149,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12150,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12151,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12152,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12153,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12154,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12155,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12156,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12157,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12158,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12159,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12160,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12161,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12162,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12163,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12164,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12165,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12166,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12167,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12168,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12169,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12170,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12171,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12172,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12173,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12174,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12175,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xeU][0xeU]),4);
    bufp->fullCData(oldp+12176,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xeU][0xeU]),4);
    bufp->fullBit(oldp+12177,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xeU][0xeU]));
    bufp->fullCData(oldp+12178,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12179,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12180,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12181,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12182,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12183,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12184,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12185,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12186,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12187,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12188,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12189,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12190,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12191,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12192,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12193,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12194,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12195,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12196,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12197,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12198,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12199,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12200,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12201,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12202,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12203,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12204,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12205,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12206,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12207,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12208,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12209,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12210,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12211,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12212,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12213,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12214,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12215,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12216,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12217,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12218,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12219,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12220,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12221,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12222,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12223,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12224,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12225,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12226,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xeU][0xfU]),4);
    bufp->fullCData(oldp+12227,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xeU][0xfU]),4);
    bufp->fullBit(oldp+12228,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xeU][0xfU]));
    bufp->fullCData(oldp+12229,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12230,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12231,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12232,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12233,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12234,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12235,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12236,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12237,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12238,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12239,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12240,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12241,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12242,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12243,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12244,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12245,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12246,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12247,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12248,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12249,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12250,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12251,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12252,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12253,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12254,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12255,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12256,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12257,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12258,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12259,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12260,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12261,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12262,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12263,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12264,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12265,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12266,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12267,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12268,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12269,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12270,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12271,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12272,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12273,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12274,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12275,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12276,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__14__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12277,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][0U]),4);
    bufp->fullCData(oldp+12278,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][0U]),4);
    bufp->fullBit(oldp+12279,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][0U]));
    bufp->fullCData(oldp+12280,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12281,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12282,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12283,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12284,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12285,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12286,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12287,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12288,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12289,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12290,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12291,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12292,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12293,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12294,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12295,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12296,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12297,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12298,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12299,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12300,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12301,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12302,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12303,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12304,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12305,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12306,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12307,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12308,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12309,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12310,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12311,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12312,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12313,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12314,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12315,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12316,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12317,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12318,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12319,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12320,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12321,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12322,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12323,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12324,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12325,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12326,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12327,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12328,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][1U]),4);
    bufp->fullCData(oldp+12329,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][1U]),4);
    bufp->fullBit(oldp+12330,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][1U]));
    bufp->fullCData(oldp+12331,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12332,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12333,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12334,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12335,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12336,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12337,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12338,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12339,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12340,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12341,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12342,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12343,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12344,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12345,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12346,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12347,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12348,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12349,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12350,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12351,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12352,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12353,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12354,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12355,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12356,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12357,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12358,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12359,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12360,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12361,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12362,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12363,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12364,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12365,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12366,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12367,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12368,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12369,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12370,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12371,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12372,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12373,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12374,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12375,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12376,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12377,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12378,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12379,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][2U]),4);
    bufp->fullCData(oldp+12380,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][2U]),4);
    bufp->fullBit(oldp+12381,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][2U]));
    bufp->fullCData(oldp+12382,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12383,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12384,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12385,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12386,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12387,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12388,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12389,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12390,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12391,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12392,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12393,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12394,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12395,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12396,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12397,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12398,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12399,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12400,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12401,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12402,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12403,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12404,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12405,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12406,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12407,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12408,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12409,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12410,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12411,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12412,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12413,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12414,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12415,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12416,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12417,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12418,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12419,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12420,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12421,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12422,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12423,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12424,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12425,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12426,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12427,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12428,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12429,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12430,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][3U]),4);
    bufp->fullCData(oldp+12431,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][3U]),4);
    bufp->fullBit(oldp+12432,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][3U]));
    bufp->fullCData(oldp+12433,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12434,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12435,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12436,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12437,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12438,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12439,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12440,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12441,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12442,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12443,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12444,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12445,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12446,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12447,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12448,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12449,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12450,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12451,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12452,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12453,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12454,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12455,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12456,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12457,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12458,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12459,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12460,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12461,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12462,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12463,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12464,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12465,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12466,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12467,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12468,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12469,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12470,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12471,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12472,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12473,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12474,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12475,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12476,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12477,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12478,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12479,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12480,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12481,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][4U]),4);
    bufp->fullCData(oldp+12482,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][4U]),4);
    bufp->fullBit(oldp+12483,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][4U]));
    bufp->fullCData(oldp+12484,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12485,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12486,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12487,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12488,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12489,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12490,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12491,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12492,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12493,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12494,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12495,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12496,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12497,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12498,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12499,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12500,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12501,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12502,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12503,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12504,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12505,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12506,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12507,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12508,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12509,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12510,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12511,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12512,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12513,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12514,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12515,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12516,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12517,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12518,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12519,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12520,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12521,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12522,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12523,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12524,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12525,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12526,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12527,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12528,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12529,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12530,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12531,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__4__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12532,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][5U]),4);
    bufp->fullCData(oldp+12533,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][5U]),4);
    bufp->fullBit(oldp+12534,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][5U]));
    bufp->fullCData(oldp+12535,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12536,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12537,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12538,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12539,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12540,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12541,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12542,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12543,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12544,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12545,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12546,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12547,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12548,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12549,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12550,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12551,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12552,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12553,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12554,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12555,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12556,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12557,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12558,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12559,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12560,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12561,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12562,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12563,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12564,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12565,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12566,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12567,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12568,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12569,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12570,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12571,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12572,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12573,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12574,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12575,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12576,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12577,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12578,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12579,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12580,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12581,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12582,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__5__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12583,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][6U]),4);
    bufp->fullCData(oldp+12584,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][6U]),4);
    bufp->fullBit(oldp+12585,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][6U]));
    bufp->fullCData(oldp+12586,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12587,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12588,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12589,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12590,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12591,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12592,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12593,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12594,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12595,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12596,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12597,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12598,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12599,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12600,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12601,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12602,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12603,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12604,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12605,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12606,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12607,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12608,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12609,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12610,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12611,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12612,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12613,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12614,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12615,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12616,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12617,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12618,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12619,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12620,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12621,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12622,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12623,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12624,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12625,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12626,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12627,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12628,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12629,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12630,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12631,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12632,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12633,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__6__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12634,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][7U]),4);
    bufp->fullCData(oldp+12635,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][7U]),4);
    bufp->fullBit(oldp+12636,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][7U]));
    bufp->fullCData(oldp+12637,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12638,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12639,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12640,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12641,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12642,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12643,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12644,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12645,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12646,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12647,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12648,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12649,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12650,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12651,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12652,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12653,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12654,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12655,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12656,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12657,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12658,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12659,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12660,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12661,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12662,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12663,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12664,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12665,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12666,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12667,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12668,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12669,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12670,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12671,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12672,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12673,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12674,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12675,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12676,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12677,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12678,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12679,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12680,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12681,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12682,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12683,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12684,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__7__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12685,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][8U]),4);
    bufp->fullCData(oldp+12686,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][8U]),4);
    bufp->fullBit(oldp+12687,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][8U]));
    bufp->fullCData(oldp+12688,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12689,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12690,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12691,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12692,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12693,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12694,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12695,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12696,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12697,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12698,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12699,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12700,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12701,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12702,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12703,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12704,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12705,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12706,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12707,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12708,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12709,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12710,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12711,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12712,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12713,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12714,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12715,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12716,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12717,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12718,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12719,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12720,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12721,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12722,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12723,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12724,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12725,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12726,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12727,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12728,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12729,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12730,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12731,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12732,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12733,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12734,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12735,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__8__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12736,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][9U]),4);
    bufp->fullCData(oldp+12737,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][9U]),4);
    bufp->fullBit(oldp+12738,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][9U]));
    bufp->fullCData(oldp+12739,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12740,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12741,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12742,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12743,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12744,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12745,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12746,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12747,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12748,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12749,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12750,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12751,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12752,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12753,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12754,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12755,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12756,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12757,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12758,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12759,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12760,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12761,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12762,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12763,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12764,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12765,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12766,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12767,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12768,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12769,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12770,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12771,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12772,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12773,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12774,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12775,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12776,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12777,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12778,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12779,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12780,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12781,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12782,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12783,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12784,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12785,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12786,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__9__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12787,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][0xaU]),4);
    bufp->fullCData(oldp+12788,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][0xaU]),4);
    bufp->fullBit(oldp+12789,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][0xaU]));
    bufp->fullCData(oldp+12790,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12791,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12792,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12793,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12794,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12795,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12796,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12797,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12798,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12799,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12800,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12801,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12802,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12803,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12804,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12805,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12806,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12807,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12808,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12809,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12810,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12811,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12812,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12813,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12814,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12815,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12816,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12817,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12818,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12819,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12820,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12821,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12822,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12823,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12824,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12825,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12826,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12827,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12828,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12829,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12830,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12831,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12832,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12833,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12834,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12835,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12836,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12837,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__10__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12838,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][0xbU]),4);
    bufp->fullCData(oldp+12839,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][0xbU]),4);
    bufp->fullBit(oldp+12840,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][0xbU]));
    bufp->fullCData(oldp+12841,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12842,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12843,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12844,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12845,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12846,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12847,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12848,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12849,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12850,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12851,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12852,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12853,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12854,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12855,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12856,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12857,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12858,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12859,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12860,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12861,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12862,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12863,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12864,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12865,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12866,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12867,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12868,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12869,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12870,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12871,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12872,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12873,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12874,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12875,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12876,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12877,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12878,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12879,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12880,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12881,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12882,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12883,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12884,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12885,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12886,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12887,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12888,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__11__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12889,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][0xcU]),4);
    bufp->fullCData(oldp+12890,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][0xcU]),4);
    bufp->fullBit(oldp+12891,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][0xcU]));
    bufp->fullCData(oldp+12892,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12893,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12894,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12895,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12896,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12897,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12898,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12899,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12900,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12901,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12902,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12903,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12904,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12905,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12906,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12907,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12908,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12909,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12910,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12911,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12912,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12913,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12914,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12915,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12916,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12917,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12918,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12919,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12920,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12921,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12922,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12923,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12924,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12925,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12926,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12927,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12928,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12929,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12930,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12931,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12932,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12933,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12934,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12935,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12936,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12937,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12938,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12939,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__12__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12940,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][0xdU]),4);
    bufp->fullCData(oldp+12941,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][0xdU]),4);
    bufp->fullBit(oldp+12942,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][0xdU]));
    bufp->fullCData(oldp+12943,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12944,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12945,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12946,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12947,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12948,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+12949,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+12950,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+12951,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+12952,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+12953,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+12954,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+12955,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+12956,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+12957,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+12958,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+12959,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+12960,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+12961,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+12962,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+12963,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+12964,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+12965,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+12966,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+12967,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+12968,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+12969,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+12970,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+12971,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+12972,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+12973,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+12974,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+12975,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+12976,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+12977,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+12978,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+12979,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+12980,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+12981,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+12982,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+12983,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+12984,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+12985,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+12986,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+12987,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+12988,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+12989,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+12990,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__13__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+12991,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][0xeU]),4);
    bufp->fullCData(oldp+12992,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][0xeU]),4);
    bufp->fullBit(oldp+12993,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][0xeU]));
    bufp->fullCData(oldp+12994,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+12995,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+12996,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+12997,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+12998,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+12999,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+13000,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+13001,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+13002,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+13003,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+13004,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+13005,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+13006,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+13007,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+13008,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+13009,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+13010,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+13011,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+13012,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+13013,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+13014,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+13015,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+13016,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+13017,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+13018,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+13019,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+13020,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+13021,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+13022,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+13023,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+13024,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+13025,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+13026,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+13027,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+13028,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+13029,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+13030,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+13031,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+13032,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+13033,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+13034,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+13035,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+13036,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+13037,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+13038,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+13039,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+13040,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+13041,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__14__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+13042,(vlSelfRef.systolic_array__DOT__a_wire
                                [0xfU][0xfU]),4);
    bufp->fullCData(oldp+13043,(vlSelfRef.systolic_array__DOT__b_wire
                                [0xfU][0xfU]),4);
    bufp->fullBit(oldp+13044,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0xfU][0xfU]));
    bufp->fullCData(oldp+13045,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+13046,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+13047,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+13048,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+13049,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+13050,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+13051,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+13052,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+13053,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+13054,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+13055,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+13056,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+13057,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+13058,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+13059,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+13060,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+13061,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+13062,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+13063,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+13064,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+13065,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                               >> 0x1fU)));
    bufp->fullBit(oldp+13066,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                               >> 0x1fU)));
    bufp->fullCData(oldp+13067,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                                          >> 0x17U))),8);
    bufp->fullCData(oldp+13068,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                          >> 0x17U))),8);
    bufp->fullIData(oldp+13069,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+13070,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                  >> 0x17U)))
                                  ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                  : (0x800000U | (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+13071,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+13072,((IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+13073,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+13074,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+13075,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+13076,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+13077,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+13078,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+13079,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+13080,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+13081,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+13082,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+13083,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+13084,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+13085,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+13086,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+13087,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+13088,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+13089,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+13090,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+13091,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+13092,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__15__KET____DOT__gen_col__BRA__15__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+13093,(vlSelfRef.clk));
    bufp->fullBit(oldp+13094,(vlSelfRef.rst_n));
    bufp->fullCData(oldp+13095,(vlSelfRef.a_in[0]),4);
    bufp->fullCData(oldp+13096,(vlSelfRef.a_in[1]),4);
    bufp->fullCData(oldp+13097,(vlSelfRef.a_in[2]),4);
    bufp->fullCData(oldp+13098,(vlSelfRef.a_in[3]),4);
    bufp->fullCData(oldp+13099,(vlSelfRef.a_in[4]),4);
    bufp->fullCData(oldp+13100,(vlSelfRef.a_in[5]),4);
    bufp->fullCData(oldp+13101,(vlSelfRef.a_in[6]),4);
    bufp->fullCData(oldp+13102,(vlSelfRef.a_in[7]),4);
    bufp->fullCData(oldp+13103,(vlSelfRef.a_in[8]),4);
    bufp->fullCData(oldp+13104,(vlSelfRef.a_in[9]),4);
    bufp->fullCData(oldp+13105,(vlSelfRef.a_in[10]),4);
    bufp->fullCData(oldp+13106,(vlSelfRef.a_in[11]),4);
    bufp->fullCData(oldp+13107,(vlSelfRef.a_in[12]),4);
    bufp->fullCData(oldp+13108,(vlSelfRef.a_in[13]),4);
    bufp->fullCData(oldp+13109,(vlSelfRef.a_in[14]),4);
    bufp->fullCData(oldp+13110,(vlSelfRef.a_in[15]),4);
    bufp->fullCData(oldp+13111,(vlSelfRef.b_in[0]),4);
    bufp->fullCData(oldp+13112,(vlSelfRef.b_in[1]),4);
    bufp->fullCData(oldp+13113,(vlSelfRef.b_in[2]),4);
    bufp->fullCData(oldp+13114,(vlSelfRef.b_in[3]),4);
    bufp->fullCData(oldp+13115,(vlSelfRef.b_in[4]),4);
    bufp->fullCData(oldp+13116,(vlSelfRef.b_in[5]),4);
    bufp->fullCData(oldp+13117,(vlSelfRef.b_in[6]),4);
    bufp->fullCData(oldp+13118,(vlSelfRef.b_in[7]),4);
    bufp->fullCData(oldp+13119,(vlSelfRef.b_in[8]),4);
    bufp->fullCData(oldp+13120,(vlSelfRef.b_in[9]),4);
    bufp->fullCData(oldp+13121,(vlSelfRef.b_in[10]),4);
    bufp->fullCData(oldp+13122,(vlSelfRef.b_in[11]),4);
    bufp->fullCData(oldp+13123,(vlSelfRef.b_in[12]),4);
    bufp->fullCData(oldp+13124,(vlSelfRef.b_in[13]),4);
    bufp->fullCData(oldp+13125,(vlSelfRef.b_in[14]),4);
    bufp->fullCData(oldp+13126,(vlSelfRef.b_in[15]),4);
    bufp->fullBit(oldp+13127,(vlSelfRef.valid_in));
    bufp->fullBit(oldp+13128,(vlSelfRef.result_valid));
}
