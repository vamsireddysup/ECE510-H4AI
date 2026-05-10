// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsystolic_array__Syms.h"


void Vsystolic_array___024root__trace_chg_0_sub_0(Vsystolic_array___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsystolic_array___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_chg_0\n"); );
    // Init
    Vsystolic_array___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsystolic_array___024root*>(voidSelf);
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsystolic_array___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsystolic_array___024root__trace_chg_0_sub_0(Vsystolic_array___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_chg_0_sub_0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.systolic_array__DOT__a_in[0]),4);
        bufp->chgCData(oldp+1,(vlSelfRef.systolic_array__DOT__a_in[1]),4);
        bufp->chgCData(oldp+2,(vlSelfRef.systolic_array__DOT__a_in[2]),4);
        bufp->chgCData(oldp+3,(vlSelfRef.systolic_array__DOT__a_in[3]),4);
        bufp->chgCData(oldp+4,(vlSelfRef.systolic_array__DOT__b_in[0]),4);
        bufp->chgCData(oldp+5,(vlSelfRef.systolic_array__DOT__b_in[1]),4);
        bufp->chgCData(oldp+6,(vlSelfRef.systolic_array__DOT__b_in[2]),4);
        bufp->chgCData(oldp+7,(vlSelfRef.systolic_array__DOT__b_in[3]),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+8,(vlSelfRef.systolic_array__DOT__result
                               [0U][0U]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.systolic_array__DOT__result
                               [0U][1U]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.systolic_array__DOT__result
                                [0U][2U]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.systolic_array__DOT__result
                                [0U][3U]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.systolic_array__DOT__result
                                [1U][0U]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.systolic_array__DOT__result
                                [1U][1U]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.systolic_array__DOT__result
                                [1U][2U]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.systolic_array__DOT__result
                                [1U][3U]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.systolic_array__DOT__result
                                [2U][0U]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.systolic_array__DOT__result
                                [2U][1U]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.systolic_array__DOT__result
                                [2U][2U]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.systolic_array__DOT__result
                                [2U][3U]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.systolic_array__DOT__result
                                [3U][0U]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.systolic_array__DOT__result
                                [3U][1U]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.systolic_array__DOT__result
                                [3U][2U]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.systolic_array__DOT__result
                                [3U][3U]),32);
        bufp->chgCData(oldp+24,(vlSelfRef.systolic_array__DOT__a_wire
                                [0U][0U]),4);
        bufp->chgCData(oldp+25,(vlSelfRef.systolic_array__DOT__a_wire
                                [0U][1U]),4);
        bufp->chgCData(oldp+26,(vlSelfRef.systolic_array__DOT__a_wire
                                [0U][2U]),4);
        bufp->chgCData(oldp+27,(vlSelfRef.systolic_array__DOT__a_wire
                                [0U][3U]),4);
        bufp->chgCData(oldp+28,(vlSelfRef.systolic_array__DOT__a_wire
                                [0U][4U]),4);
        bufp->chgCData(oldp+29,(vlSelfRef.systolic_array__DOT__a_wire
                                [1U][0U]),4);
        bufp->chgCData(oldp+30,(vlSelfRef.systolic_array__DOT__a_wire
                                [1U][1U]),4);
        bufp->chgCData(oldp+31,(vlSelfRef.systolic_array__DOT__a_wire
                                [1U][2U]),4);
        bufp->chgCData(oldp+32,(vlSelfRef.systolic_array__DOT__a_wire
                                [1U][3U]),4);
        bufp->chgCData(oldp+33,(vlSelfRef.systolic_array__DOT__a_wire
                                [1U][4U]),4);
        bufp->chgCData(oldp+34,(vlSelfRef.systolic_array__DOT__a_wire
                                [2U][0U]),4);
        bufp->chgCData(oldp+35,(vlSelfRef.systolic_array__DOT__a_wire
                                [2U][1U]),4);
        bufp->chgCData(oldp+36,(vlSelfRef.systolic_array__DOT__a_wire
                                [2U][2U]),4);
        bufp->chgCData(oldp+37,(vlSelfRef.systolic_array__DOT__a_wire
                                [2U][3U]),4);
        bufp->chgCData(oldp+38,(vlSelfRef.systolic_array__DOT__a_wire
                                [2U][4U]),4);
        bufp->chgCData(oldp+39,(vlSelfRef.systolic_array__DOT__a_wire
                                [3U][0U]),4);
        bufp->chgCData(oldp+40,(vlSelfRef.systolic_array__DOT__a_wire
                                [3U][1U]),4);
        bufp->chgCData(oldp+41,(vlSelfRef.systolic_array__DOT__a_wire
                                [3U][2U]),4);
        bufp->chgCData(oldp+42,(vlSelfRef.systolic_array__DOT__a_wire
                                [3U][3U]),4);
        bufp->chgCData(oldp+43,(vlSelfRef.systolic_array__DOT__a_wire
                                [3U][4U]),4);
        bufp->chgCData(oldp+44,(vlSelfRef.systolic_array__DOT__b_wire
                                [0U][0U]),4);
        bufp->chgCData(oldp+45,(vlSelfRef.systolic_array__DOT__b_wire
                                [0U][1U]),4);
        bufp->chgCData(oldp+46,(vlSelfRef.systolic_array__DOT__b_wire
                                [0U][2U]),4);
        bufp->chgCData(oldp+47,(vlSelfRef.systolic_array__DOT__b_wire
                                [0U][3U]),4);
        bufp->chgCData(oldp+48,(vlSelfRef.systolic_array__DOT__b_wire
                                [1U][0U]),4);
        bufp->chgCData(oldp+49,(vlSelfRef.systolic_array__DOT__b_wire
                                [1U][1U]),4);
        bufp->chgCData(oldp+50,(vlSelfRef.systolic_array__DOT__b_wire
                                [1U][2U]),4);
        bufp->chgCData(oldp+51,(vlSelfRef.systolic_array__DOT__b_wire
                                [1U][3U]),4);
        bufp->chgCData(oldp+52,(vlSelfRef.systolic_array__DOT__b_wire
                                [2U][0U]),4);
        bufp->chgCData(oldp+53,(vlSelfRef.systolic_array__DOT__b_wire
                                [2U][1U]),4);
        bufp->chgCData(oldp+54,(vlSelfRef.systolic_array__DOT__b_wire
                                [2U][2U]),4);
        bufp->chgCData(oldp+55,(vlSelfRef.systolic_array__DOT__b_wire
                                [2U][3U]),4);
        bufp->chgCData(oldp+56,(vlSelfRef.systolic_array__DOT__b_wire
                                [3U][0U]),4);
        bufp->chgCData(oldp+57,(vlSelfRef.systolic_array__DOT__b_wire
                                [3U][1U]),4);
        bufp->chgCData(oldp+58,(vlSelfRef.systolic_array__DOT__b_wire
                                [3U][2U]),4);
        bufp->chgCData(oldp+59,(vlSelfRef.systolic_array__DOT__b_wire
                                [3U][3U]),4);
        bufp->chgCData(oldp+60,(vlSelfRef.systolic_array__DOT__b_wire
                                [4U][0U]),4);
        bufp->chgCData(oldp+61,(vlSelfRef.systolic_array__DOT__b_wire
                                [4U][1U]),4);
        bufp->chgCData(oldp+62,(vlSelfRef.systolic_array__DOT__b_wire
                                [4U][2U]),4);
        bufp->chgCData(oldp+63,(vlSelfRef.systolic_array__DOT__b_wire
                                [4U][3U]),4);
        bufp->chgBit(oldp+64,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0U][0U]));
        bufp->chgBit(oldp+65,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0U][1U]));
        bufp->chgBit(oldp+66,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0U][2U]));
        bufp->chgBit(oldp+67,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0U][3U]));
        bufp->chgBit(oldp+68,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [0U][4U]));
        bufp->chgBit(oldp+69,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [1U][0U]));
        bufp->chgBit(oldp+70,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [1U][1U]));
        bufp->chgBit(oldp+71,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [1U][2U]));
        bufp->chgBit(oldp+72,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [1U][3U]));
        bufp->chgBit(oldp+73,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [1U][4U]));
        bufp->chgBit(oldp+74,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [2U][0U]));
        bufp->chgBit(oldp+75,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [2U][1U]));
        bufp->chgBit(oldp+76,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [2U][2U]));
        bufp->chgBit(oldp+77,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [2U][3U]));
        bufp->chgBit(oldp+78,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [2U][4U]));
        bufp->chgBit(oldp+79,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [3U][0U]));
        bufp->chgBit(oldp+80,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [3U][1U]));
        bufp->chgBit(oldp+81,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [3U][2U]));
        bufp->chgBit(oldp+82,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [3U][3U]));
        bufp->chgBit(oldp+83,(vlSelfRef.systolic_array__DOT__v_wire_a
                              [3U][4U]));
        bufp->chgCData(oldp+84,(vlSelfRef.systolic_array__DOT__a_stagger
                                [0U][0U]),4);
        bufp->chgCData(oldp+85,(vlSelfRef.systolic_array__DOT__a_stagger
                                [0U][1U]),4);
        bufp->chgCData(oldp+86,(vlSelfRef.systolic_array__DOT__a_stagger
                                [0U][2U]),4);
        bufp->chgCData(oldp+87,(vlSelfRef.systolic_array__DOT__a_stagger
                                [0U][3U]),4);
        bufp->chgCData(oldp+88,(vlSelfRef.systolic_array__DOT__a_stagger
                                [1U][0U]),4);
        bufp->chgCData(oldp+89,(vlSelfRef.systolic_array__DOT__a_stagger
                                [1U][1U]),4);
        bufp->chgCData(oldp+90,(vlSelfRef.systolic_array__DOT__a_stagger
                                [1U][2U]),4);
        bufp->chgCData(oldp+91,(vlSelfRef.systolic_array__DOT__a_stagger
                                [1U][3U]),4);
        bufp->chgCData(oldp+92,(vlSelfRef.systolic_array__DOT__a_stagger
                                [2U][0U]),4);
        bufp->chgCData(oldp+93,(vlSelfRef.systolic_array__DOT__a_stagger
                                [2U][1U]),4);
        bufp->chgCData(oldp+94,(vlSelfRef.systolic_array__DOT__a_stagger
                                [2U][2U]),4);
        bufp->chgCData(oldp+95,(vlSelfRef.systolic_array__DOT__a_stagger
                                [2U][3U]),4);
        bufp->chgCData(oldp+96,(vlSelfRef.systolic_array__DOT__a_stagger
                                [3U][0U]),4);
        bufp->chgCData(oldp+97,(vlSelfRef.systolic_array__DOT__a_stagger
                                [3U][1U]),4);
        bufp->chgCData(oldp+98,(vlSelfRef.systolic_array__DOT__a_stagger
                                [3U][2U]),4);
        bufp->chgCData(oldp+99,(vlSelfRef.systolic_array__DOT__a_stagger
                                [3U][3U]),4);
        bufp->chgCData(oldp+100,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [0U][0U]),4);
        bufp->chgCData(oldp+101,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [0U][1U]),4);
        bufp->chgCData(oldp+102,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [0U][2U]),4);
        bufp->chgCData(oldp+103,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [0U][3U]),4);
        bufp->chgCData(oldp+104,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [1U][0U]),4);
        bufp->chgCData(oldp+105,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [1U][1U]),4);
        bufp->chgCData(oldp+106,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [1U][2U]),4);
        bufp->chgCData(oldp+107,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [1U][3U]),4);
        bufp->chgCData(oldp+108,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [2U][0U]),4);
        bufp->chgCData(oldp+109,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [2U][1U]),4);
        bufp->chgCData(oldp+110,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [2U][2U]),4);
        bufp->chgCData(oldp+111,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [2U][3U]),4);
        bufp->chgCData(oldp+112,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [3U][0U]),4);
        bufp->chgCData(oldp+113,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [3U][1U]),4);
        bufp->chgCData(oldp+114,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [3U][2U]),4);
        bufp->chgCData(oldp+115,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [3U][3U]),4);
        bufp->chgBit(oldp+116,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [0U][0U]));
        bufp->chgBit(oldp+117,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [0U][1U]));
        bufp->chgBit(oldp+118,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [0U][2U]));
        bufp->chgBit(oldp+119,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [0U][3U]));
        bufp->chgBit(oldp+120,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [1U][0U]));
        bufp->chgBit(oldp+121,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [1U][1U]));
        bufp->chgBit(oldp+122,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [1U][2U]));
        bufp->chgBit(oldp+123,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [1U][3U]));
        bufp->chgBit(oldp+124,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [2U][0U]));
        bufp->chgBit(oldp+125,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [2U][1U]));
        bufp->chgBit(oldp+126,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [2U][2U]));
        bufp->chgBit(oldp+127,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [2U][3U]));
        bufp->chgBit(oldp+128,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [3U][0U]));
        bufp->chgBit(oldp+129,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [3U][1U]));
        bufp->chgBit(oldp+130,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [3U][2U]));
        bufp->chgBit(oldp+131,(vlSelfRef.systolic_array__DOT__v_stagger_a
                               [3U][3U]));
        bufp->chgBit(oldp+132,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [0U][0U]));
        bufp->chgBit(oldp+133,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [0U][1U]));
        bufp->chgBit(oldp+134,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [0U][2U]));
        bufp->chgBit(oldp+135,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [0U][3U]));
        bufp->chgBit(oldp+136,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [1U][0U]));
        bufp->chgBit(oldp+137,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [1U][1U]));
        bufp->chgBit(oldp+138,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [1U][2U]));
        bufp->chgBit(oldp+139,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [1U][3U]));
        bufp->chgBit(oldp+140,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [2U][0U]));
        bufp->chgBit(oldp+141,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [2U][1U]));
        bufp->chgBit(oldp+142,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [2U][2U]));
        bufp->chgBit(oldp+143,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [2U][3U]));
        bufp->chgBit(oldp+144,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [3U][0U]));
        bufp->chgBit(oldp+145,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [3U][1U]));
        bufp->chgBit(oldp+146,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [3U][2U]));
        bufp->chgBit(oldp+147,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [3U][3U]));
        bufp->chgIData(oldp+148,(vlSelfRef.systolic_array__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+149,(vlSelfRef.systolic_array__DOT__unnamedblk1__DOT__unnamedblk2__DOT__d),32);
        bufp->chgIData(oldp+150,(vlSelfRef.systolic_array__DOT__unnamedblk3__DOT__j),32);
        bufp->chgIData(oldp+151,(vlSelfRef.systolic_array__DOT__unnamedblk3__DOT__unnamedblk4__DOT__d),32);
        bufp->chgCData(oldp+152,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0U][0U]),4);
        bufp->chgCData(oldp+153,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0U][0U]),4);
        bufp->chgBit(oldp+154,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0U][0U]));
        bufp->chgCData(oldp+155,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+156,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+157,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+158,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+159,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+160,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+161,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+162,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+163,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+164,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+165,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+166,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+167,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+168,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+169,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+170,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+171,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+172,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+173,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+174,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+175,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+176,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+177,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+178,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+179,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+180,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+181,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+182,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+183,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+184,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+185,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+186,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+187,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+188,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+189,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+190,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+191,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+192,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+193,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+194,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+195,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+196,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+197,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+198,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+199,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+200,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+201,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+202,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+203,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0U][1U]),4);
        bufp->chgCData(oldp+204,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0U][1U]),4);
        bufp->chgBit(oldp+205,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0U][1U]));
        bufp->chgCData(oldp+206,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+207,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+208,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+209,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+210,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+211,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+212,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+213,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+214,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+215,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+216,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+217,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+218,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+219,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+220,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+221,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+222,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+223,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+224,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+225,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+226,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+227,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+228,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+229,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+230,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+231,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+232,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+233,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+234,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+235,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+236,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+237,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+238,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+239,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+240,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+241,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+242,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+243,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+244,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+245,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+246,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+247,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+248,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+249,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+250,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+251,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+252,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+253,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+254,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0U][2U]),4);
        bufp->chgCData(oldp+255,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0U][2U]),4);
        bufp->chgBit(oldp+256,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0U][2U]));
        bufp->chgCData(oldp+257,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+258,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+259,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+260,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+261,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+262,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+263,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+264,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+265,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+266,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+267,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+268,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+269,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+270,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+271,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+272,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+273,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+274,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+275,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+276,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+277,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+278,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+279,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+280,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+281,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+282,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+283,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+284,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+285,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+286,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+287,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+288,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+289,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+290,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+291,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+292,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+293,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+294,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+295,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+296,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+297,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+298,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+299,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+300,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+301,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+302,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+303,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+304,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+305,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0U][3U]),4);
        bufp->chgCData(oldp+306,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0U][3U]),4);
        bufp->chgBit(oldp+307,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [0U][3U]));
        bufp->chgCData(oldp+308,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+309,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+310,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+311,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+312,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+313,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+314,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+315,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+316,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+317,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+318,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+319,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+320,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+321,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+322,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+323,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+324,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+325,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+326,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+327,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+328,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+329,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+330,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+331,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+332,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+333,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+334,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+335,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+336,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+337,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+338,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+339,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+340,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+341,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+342,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+343,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+344,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+345,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+346,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+347,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+348,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+349,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+350,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+351,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+352,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+353,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+354,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+355,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+356,(vlSelfRef.systolic_array__DOT__a_wire
                                 [1U][0U]),4);
        bufp->chgCData(oldp+357,(vlSelfRef.systolic_array__DOT__b_wire
                                 [1U][0U]),4);
        bufp->chgBit(oldp+358,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [1U][0U]));
        bufp->chgCData(oldp+359,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+360,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+361,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+362,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+363,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+364,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+365,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+366,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+367,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+368,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+369,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+370,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+371,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+372,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+373,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+374,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+375,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+376,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+377,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+378,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+379,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+380,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+381,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+382,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+383,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+384,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+385,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+386,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+387,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+388,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+389,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+390,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+391,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+392,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+393,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+394,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+395,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+396,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+397,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+398,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+399,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+400,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+401,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+402,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+403,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+404,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+405,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+406,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+407,(vlSelfRef.systolic_array__DOT__a_wire
                                 [1U][1U]),4);
        bufp->chgCData(oldp+408,(vlSelfRef.systolic_array__DOT__b_wire
                                 [1U][1U]),4);
        bufp->chgBit(oldp+409,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [1U][1U]));
        bufp->chgCData(oldp+410,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+411,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+412,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+413,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+414,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+415,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+416,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+417,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+418,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+419,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+420,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+421,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+422,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+423,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+424,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+425,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+426,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+427,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+428,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+429,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+430,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+431,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+432,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+433,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+434,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+435,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+436,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+437,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+438,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+439,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+440,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+441,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+442,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+443,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+444,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+445,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+446,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+447,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+448,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+449,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+450,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+451,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+452,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+453,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+454,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+455,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+456,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+457,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+458,(vlSelfRef.systolic_array__DOT__a_wire
                                 [1U][2U]),4);
        bufp->chgCData(oldp+459,(vlSelfRef.systolic_array__DOT__b_wire
                                 [1U][2U]),4);
        bufp->chgBit(oldp+460,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [1U][2U]));
        bufp->chgCData(oldp+461,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+462,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+463,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+464,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+465,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+466,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+467,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+468,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+469,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+470,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+471,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+472,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+473,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+474,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+475,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+476,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+477,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+478,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+479,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+480,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+481,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+482,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+483,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+484,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+485,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+486,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+487,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+488,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+489,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+490,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+491,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+492,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+493,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+494,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+495,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+496,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+497,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+498,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+499,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+500,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+501,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+502,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+503,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+504,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+505,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+506,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+507,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+508,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+509,(vlSelfRef.systolic_array__DOT__a_wire
                                 [1U][3U]),4);
        bufp->chgCData(oldp+510,(vlSelfRef.systolic_array__DOT__b_wire
                                 [1U][3U]),4);
        bufp->chgBit(oldp+511,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [1U][3U]));
        bufp->chgCData(oldp+512,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+513,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+514,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+515,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+516,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+517,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+518,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+519,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+520,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+521,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+522,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+523,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+524,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+525,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+526,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+527,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+528,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+529,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+530,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+531,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+532,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+533,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+534,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+535,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+536,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+537,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+538,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+539,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+540,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+541,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+542,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+543,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+544,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+545,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+546,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+547,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+548,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+549,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+550,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+551,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+552,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+553,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+554,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+555,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+556,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+557,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+558,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+559,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+560,(vlSelfRef.systolic_array__DOT__a_wire
                                 [2U][0U]),4);
        bufp->chgCData(oldp+561,(vlSelfRef.systolic_array__DOT__b_wire
                                 [2U][0U]),4);
        bufp->chgBit(oldp+562,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [2U][0U]));
        bufp->chgCData(oldp+563,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+564,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+565,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+566,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+567,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+568,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+569,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+570,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+571,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+572,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+573,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+574,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+575,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+576,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+577,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+578,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+579,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+580,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+581,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+582,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+583,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+584,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+585,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+586,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+587,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+588,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+589,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+590,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+591,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+592,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+593,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+594,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+595,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+596,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+597,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+598,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+599,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+600,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+601,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+602,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+603,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+604,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+605,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+606,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+607,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+608,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+609,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+610,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+611,(vlSelfRef.systolic_array__DOT__a_wire
                                 [2U][1U]),4);
        bufp->chgCData(oldp+612,(vlSelfRef.systolic_array__DOT__b_wire
                                 [2U][1U]),4);
        bufp->chgBit(oldp+613,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [2U][1U]));
        bufp->chgCData(oldp+614,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+615,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+616,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+617,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+618,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+619,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+620,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+621,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+622,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+623,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+624,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+625,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+626,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+627,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+628,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+629,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+630,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+631,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+632,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+633,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+634,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+635,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+636,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+637,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+638,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+639,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+640,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+641,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+642,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+643,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+644,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+645,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+646,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+647,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+648,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+649,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+650,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+651,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+652,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+653,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+654,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+655,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+656,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+657,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+658,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+659,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+660,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+661,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+662,(vlSelfRef.systolic_array__DOT__a_wire
                                 [2U][2U]),4);
        bufp->chgCData(oldp+663,(vlSelfRef.systolic_array__DOT__b_wire
                                 [2U][2U]),4);
        bufp->chgBit(oldp+664,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [2U][2U]));
        bufp->chgCData(oldp+665,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+666,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+667,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+668,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+669,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+670,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+671,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+672,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+673,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+674,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+675,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+676,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+677,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+678,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+679,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+680,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+681,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+682,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+683,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+684,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+685,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+686,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+687,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+688,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+689,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+690,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+691,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+692,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+693,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+694,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+695,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+696,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+697,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+698,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+699,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+700,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+701,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+702,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+703,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+704,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+705,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+706,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+707,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+708,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+709,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+710,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+711,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+712,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+713,(vlSelfRef.systolic_array__DOT__a_wire
                                 [2U][3U]),4);
        bufp->chgCData(oldp+714,(vlSelfRef.systolic_array__DOT__b_wire
                                 [2U][3U]),4);
        bufp->chgBit(oldp+715,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [2U][3U]));
        bufp->chgCData(oldp+716,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+717,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+718,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+719,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+720,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+721,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+722,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+723,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+724,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+725,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+726,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+727,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+728,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+729,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+730,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+731,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+732,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+733,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+734,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+735,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+736,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+737,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+738,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+739,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+740,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+741,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+742,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+743,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+744,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+745,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+746,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+747,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+748,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+749,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+750,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+751,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+752,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+753,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+754,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+755,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+756,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+757,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+758,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+759,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+760,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+761,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+762,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+763,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+764,(vlSelfRef.systolic_array__DOT__a_wire
                                 [3U][0U]),4);
        bufp->chgCData(oldp+765,(vlSelfRef.systolic_array__DOT__b_wire
                                 [3U][0U]),4);
        bufp->chgBit(oldp+766,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [3U][0U]));
        bufp->chgCData(oldp+767,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+768,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+769,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+770,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+771,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+772,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+773,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+774,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+775,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+776,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+777,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+778,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+779,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+780,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+781,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+782,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+783,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+784,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+785,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+786,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+787,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+788,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+789,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+790,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+791,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+792,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+793,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+794,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+795,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+796,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+797,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+798,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+799,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+800,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+801,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+802,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+803,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+804,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+805,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+806,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+807,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+808,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+809,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+810,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+811,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+812,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+813,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+814,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+815,(vlSelfRef.systolic_array__DOT__a_wire
                                 [3U][1U]),4);
        bufp->chgCData(oldp+816,(vlSelfRef.systolic_array__DOT__b_wire
                                 [3U][1U]),4);
        bufp->chgBit(oldp+817,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [3U][1U]));
        bufp->chgCData(oldp+818,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+819,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+820,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+821,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+822,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+823,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+824,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+825,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+826,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+827,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+828,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+829,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+830,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+831,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+832,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+833,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+834,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+835,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+836,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+837,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+838,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+839,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+840,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+841,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+842,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+843,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+844,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+845,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+846,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+847,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+848,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+849,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+850,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+851,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+852,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+853,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+854,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+855,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+856,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+857,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+858,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+859,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+860,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+861,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+862,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+863,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+864,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+865,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+866,(vlSelfRef.systolic_array__DOT__a_wire
                                 [3U][2U]),4);
        bufp->chgCData(oldp+867,(vlSelfRef.systolic_array__DOT__b_wire
                                 [3U][2U]),4);
        bufp->chgBit(oldp+868,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [3U][2U]));
        bufp->chgCData(oldp+869,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+870,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+871,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+872,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+873,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+874,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+875,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+876,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+877,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+878,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+879,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+880,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+881,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+882,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+883,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+884,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+885,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+886,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+887,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+888,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+889,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+890,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+891,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+892,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+893,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+894,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+895,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+896,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+897,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+898,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+899,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+900,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+901,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+902,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+903,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+904,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+905,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+906,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+907,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+908,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+909,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+910,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+911,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+912,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+913,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+914,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+915,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+916,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+917,(vlSelfRef.systolic_array__DOT__a_wire
                                 [3U][3U]),4);
        bufp->chgCData(oldp+918,(vlSelfRef.systolic_array__DOT__b_wire
                                 [3U][3U]),4);
        bufp->chgBit(oldp+919,(vlSelfRef.systolic_array__DOT__v_wire_a
                               [3U][3U]));
        bufp->chgCData(oldp+920,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),4);
        bufp->chgCData(oldp+921,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),4);
        bufp->chgBit(oldp+922,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+923,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+924,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+925,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product),32);
        bufp->chgBit(oldp+926,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product_valid));
        bufp->chgIData(oldp+927,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+928,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+929,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+930,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+931,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+932,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+933,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+934,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+935,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+936,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+937,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+938,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+939,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+940,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+941,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+942,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+943,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+944,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+945,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+946,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+947,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+948,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+949,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+950,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+951,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+952,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+953,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+954,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+955,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+956,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+957,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+958,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+959,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+960,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+961,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+962,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+963,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+964,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+965,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgIData(oldp+966,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
        bufp->chgIData(oldp+967,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+968,(vlSelfRef.clk));
    bufp->chgBit(oldp+969,(vlSelfRef.rst_n));
    bufp->chgCData(oldp+970,(vlSelfRef.a_in[0]),4);
    bufp->chgCData(oldp+971,(vlSelfRef.a_in[1]),4);
    bufp->chgCData(oldp+972,(vlSelfRef.a_in[2]),4);
    bufp->chgCData(oldp+973,(vlSelfRef.a_in[3]),4);
    bufp->chgCData(oldp+974,(vlSelfRef.b_in[0]),4);
    bufp->chgCData(oldp+975,(vlSelfRef.b_in[1]),4);
    bufp->chgCData(oldp+976,(vlSelfRef.b_in[2]),4);
    bufp->chgCData(oldp+977,(vlSelfRef.b_in[3]),4);
    bufp->chgBit(oldp+978,(vlSelfRef.valid_in));
    bufp->chgIData(oldp+979,(vlSelfRef.result[0U][0U]),32);
    bufp->chgIData(oldp+980,(vlSelfRef.result[0U][1U]),32);
    bufp->chgIData(oldp+981,(vlSelfRef.result[0U][2U]),32);
    bufp->chgIData(oldp+982,(vlSelfRef.result[0U][3U]),32);
    bufp->chgIData(oldp+983,(vlSelfRef.result[1U][0U]),32);
    bufp->chgIData(oldp+984,(vlSelfRef.result[1U][1U]),32);
    bufp->chgIData(oldp+985,(vlSelfRef.result[1U][2U]),32);
    bufp->chgIData(oldp+986,(vlSelfRef.result[1U][3U]),32);
    bufp->chgIData(oldp+987,(vlSelfRef.result[2U][0U]),32);
    bufp->chgIData(oldp+988,(vlSelfRef.result[2U][1U]),32);
    bufp->chgIData(oldp+989,(vlSelfRef.result[2U][2U]),32);
    bufp->chgIData(oldp+990,(vlSelfRef.result[2U][3U]),32);
    bufp->chgIData(oldp+991,(vlSelfRef.result[3U][0U]),32);
    bufp->chgIData(oldp+992,(vlSelfRef.result[3U][1U]),32);
    bufp->chgIData(oldp+993,(vlSelfRef.result[3U][2U]),32);
    bufp->chgIData(oldp+994,(vlSelfRef.result[3U][3U]),32);
    bufp->chgBit(oldp+995,(vlSelfRef.result_valid));
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
