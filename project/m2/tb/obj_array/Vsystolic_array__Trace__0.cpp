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
        bufp->chgIData(oldp+0,(vlSelfRef.systolic_array__DOT__a_in[0]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.systolic_array__DOT__a_in[1]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.systolic_array__DOT__a_in[2]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.systolic_array__DOT__a_in[3]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.systolic_array__DOT__b_in[0]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.systolic_array__DOT__b_in[1]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.systolic_array__DOT__b_in[2]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.systolic_array__DOT__b_in[3]),32);
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
        bufp->chgIData(oldp+24,(vlSelfRef.systolic_array__DOT__a_wire
                                [0U][0U]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.systolic_array__DOT__a_wire
                                [0U][1U]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.systolic_array__DOT__a_wire
                                [0U][2U]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.systolic_array__DOT__a_wire
                                [0U][3U]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.systolic_array__DOT__a_wire
                                [0U][4U]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.systolic_array__DOT__a_wire
                                [1U][0U]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.systolic_array__DOT__a_wire
                                [1U][1U]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.systolic_array__DOT__a_wire
                                [1U][2U]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.systolic_array__DOT__a_wire
                                [1U][3U]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.systolic_array__DOT__a_wire
                                [1U][4U]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.systolic_array__DOT__a_wire
                                [2U][0U]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.systolic_array__DOT__a_wire
                                [2U][1U]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.systolic_array__DOT__a_wire
                                [2U][2U]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.systolic_array__DOT__a_wire
                                [2U][3U]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.systolic_array__DOT__a_wire
                                [2U][4U]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.systolic_array__DOT__a_wire
                                [3U][0U]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.systolic_array__DOT__a_wire
                                [3U][1U]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.systolic_array__DOT__a_wire
                                [3U][2U]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.systolic_array__DOT__a_wire
                                [3U][3U]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.systolic_array__DOT__a_wire
                                [3U][4U]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.systolic_array__DOT__b_wire
                                [0U][0U]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.systolic_array__DOT__b_wire
                                [0U][1U]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.systolic_array__DOT__b_wire
                                [0U][2U]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.systolic_array__DOT__b_wire
                                [0U][3U]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.systolic_array__DOT__b_wire
                                [1U][0U]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.systolic_array__DOT__b_wire
                                [1U][1U]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.systolic_array__DOT__b_wire
                                [1U][2U]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.systolic_array__DOT__b_wire
                                [1U][3U]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.systolic_array__DOT__b_wire
                                [2U][0U]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.systolic_array__DOT__b_wire
                                [2U][1U]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.systolic_array__DOT__b_wire
                                [2U][2U]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.systolic_array__DOT__b_wire
                                [2U][3U]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.systolic_array__DOT__b_wire
                                [3U][0U]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.systolic_array__DOT__b_wire
                                [3U][1U]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.systolic_array__DOT__b_wire
                                [3U][2U]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.systolic_array__DOT__b_wire
                                [3U][3U]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.systolic_array__DOT__b_wire
                                [4U][0U]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.systolic_array__DOT__b_wire
                                [4U][1U]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.systolic_array__DOT__b_wire
                                [4U][2U]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.systolic_array__DOT__b_wire
                                [4U][3U]),32);
        bufp->chgBit(oldp+64,(vlSelfRef.systolic_array__DOT__v_wire
                              [0U][0U]));
        bufp->chgBit(oldp+65,(vlSelfRef.systolic_array__DOT__v_wire
                              [0U][1U]));
        bufp->chgBit(oldp+66,(vlSelfRef.systolic_array__DOT__v_wire
                              [0U][2U]));
        bufp->chgBit(oldp+67,(vlSelfRef.systolic_array__DOT__v_wire
                              [0U][3U]));
        bufp->chgBit(oldp+68,(vlSelfRef.systolic_array__DOT__v_wire
                              [0U][4U]));
        bufp->chgBit(oldp+69,(vlSelfRef.systolic_array__DOT__v_wire
                              [1U][0U]));
        bufp->chgBit(oldp+70,(vlSelfRef.systolic_array__DOT__v_wire
                              [1U][1U]));
        bufp->chgBit(oldp+71,(vlSelfRef.systolic_array__DOT__v_wire
                              [1U][2U]));
        bufp->chgBit(oldp+72,(vlSelfRef.systolic_array__DOT__v_wire
                              [1U][3U]));
        bufp->chgBit(oldp+73,(vlSelfRef.systolic_array__DOT__v_wire
                              [1U][4U]));
        bufp->chgBit(oldp+74,(vlSelfRef.systolic_array__DOT__v_wire
                              [2U][0U]));
        bufp->chgBit(oldp+75,(vlSelfRef.systolic_array__DOT__v_wire
                              [2U][1U]));
        bufp->chgBit(oldp+76,(vlSelfRef.systolic_array__DOT__v_wire
                              [2U][2U]));
        bufp->chgBit(oldp+77,(vlSelfRef.systolic_array__DOT__v_wire
                              [2U][3U]));
        bufp->chgBit(oldp+78,(vlSelfRef.systolic_array__DOT__v_wire
                              [2U][4U]));
        bufp->chgBit(oldp+79,(vlSelfRef.systolic_array__DOT__v_wire
                              [3U][0U]));
        bufp->chgBit(oldp+80,(vlSelfRef.systolic_array__DOT__v_wire
                              [3U][1U]));
        bufp->chgBit(oldp+81,(vlSelfRef.systolic_array__DOT__v_wire
                              [3U][2U]));
        bufp->chgBit(oldp+82,(vlSelfRef.systolic_array__DOT__v_wire
                              [3U][3U]));
        bufp->chgBit(oldp+83,(vlSelfRef.systolic_array__DOT__v_wire
                              [3U][4U]));
        bufp->chgIData(oldp+84,(vlSelfRef.systolic_array__DOT__a_stagger
                                [0U][0U]),32);
        bufp->chgIData(oldp+85,(vlSelfRef.systolic_array__DOT__a_stagger
                                [0U][1U]),32);
        bufp->chgIData(oldp+86,(vlSelfRef.systolic_array__DOT__a_stagger
                                [0U][2U]),32);
        bufp->chgIData(oldp+87,(vlSelfRef.systolic_array__DOT__a_stagger
                                [0U][3U]),32);
        bufp->chgIData(oldp+88,(vlSelfRef.systolic_array__DOT__a_stagger
                                [1U][0U]),32);
        bufp->chgIData(oldp+89,(vlSelfRef.systolic_array__DOT__a_stagger
                                [1U][1U]),32);
        bufp->chgIData(oldp+90,(vlSelfRef.systolic_array__DOT__a_stagger
                                [1U][2U]),32);
        bufp->chgIData(oldp+91,(vlSelfRef.systolic_array__DOT__a_stagger
                                [1U][3U]),32);
        bufp->chgIData(oldp+92,(vlSelfRef.systolic_array__DOT__a_stagger
                                [2U][0U]),32);
        bufp->chgIData(oldp+93,(vlSelfRef.systolic_array__DOT__a_stagger
                                [2U][1U]),32);
        bufp->chgIData(oldp+94,(vlSelfRef.systolic_array__DOT__a_stagger
                                [2U][2U]),32);
        bufp->chgIData(oldp+95,(vlSelfRef.systolic_array__DOT__a_stagger
                                [2U][3U]),32);
        bufp->chgIData(oldp+96,(vlSelfRef.systolic_array__DOT__a_stagger
                                [3U][0U]),32);
        bufp->chgIData(oldp+97,(vlSelfRef.systolic_array__DOT__a_stagger
                                [3U][1U]),32);
        bufp->chgIData(oldp+98,(vlSelfRef.systolic_array__DOT__a_stagger
                                [3U][2U]),32);
        bufp->chgIData(oldp+99,(vlSelfRef.systolic_array__DOT__a_stagger
                                [3U][3U]),32);
        bufp->chgIData(oldp+100,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [0U][0U]),32);
        bufp->chgIData(oldp+101,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [0U][1U]),32);
        bufp->chgIData(oldp+102,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [0U][2U]),32);
        bufp->chgIData(oldp+103,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [0U][3U]),32);
        bufp->chgIData(oldp+104,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [1U][0U]),32);
        bufp->chgIData(oldp+105,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [1U][1U]),32);
        bufp->chgIData(oldp+106,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [1U][2U]),32);
        bufp->chgIData(oldp+107,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [1U][3U]),32);
        bufp->chgIData(oldp+108,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [2U][0U]),32);
        bufp->chgIData(oldp+109,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [2U][1U]),32);
        bufp->chgIData(oldp+110,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [2U][2U]),32);
        bufp->chgIData(oldp+111,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [2U][3U]),32);
        bufp->chgIData(oldp+112,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [3U][0U]),32);
        bufp->chgIData(oldp+113,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [3U][1U]),32);
        bufp->chgIData(oldp+114,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [3U][2U]),32);
        bufp->chgIData(oldp+115,(vlSelfRef.systolic_array__DOT__b_stagger
                                 [3U][3U]),32);
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
        bufp->chgBit(oldp+132,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [0U][0U]));
        bufp->chgBit(oldp+133,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [0U][1U]));
        bufp->chgBit(oldp+134,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [0U][2U]));
        bufp->chgBit(oldp+135,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [0U][3U]));
        bufp->chgBit(oldp+136,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [1U][0U]));
        bufp->chgBit(oldp+137,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [1U][1U]));
        bufp->chgBit(oldp+138,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [1U][2U]));
        bufp->chgBit(oldp+139,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [1U][3U]));
        bufp->chgBit(oldp+140,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [2U][0U]));
        bufp->chgBit(oldp+141,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [2U][1U]));
        bufp->chgBit(oldp+142,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [2U][2U]));
        bufp->chgBit(oldp+143,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [2U][3U]));
        bufp->chgBit(oldp+144,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [3U][0U]));
        bufp->chgBit(oldp+145,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [3U][1U]));
        bufp->chgBit(oldp+146,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [3U][2U]));
        bufp->chgBit(oldp+147,(vlSelfRef.systolic_array__DOT__v_stagger_b
                               [3U][3U]));
        bufp->chgBit(oldp+148,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [0U][0U]));
        bufp->chgBit(oldp+149,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [0U][1U]));
        bufp->chgBit(oldp+150,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [0U][2U]));
        bufp->chgBit(oldp+151,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [0U][3U]));
        bufp->chgBit(oldp+152,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [1U][0U]));
        bufp->chgBit(oldp+153,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [1U][1U]));
        bufp->chgBit(oldp+154,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [1U][2U]));
        bufp->chgBit(oldp+155,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [1U][3U]));
        bufp->chgBit(oldp+156,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [2U][0U]));
        bufp->chgBit(oldp+157,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [2U][1U]));
        bufp->chgBit(oldp+158,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [2U][2U]));
        bufp->chgBit(oldp+159,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [2U][3U]));
        bufp->chgBit(oldp+160,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [3U][0U]));
        bufp->chgBit(oldp+161,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [3U][1U]));
        bufp->chgBit(oldp+162,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [3U][2U]));
        bufp->chgBit(oldp+163,(vlSelfRef.systolic_array__DOT__pe_result_valid
                               [3U][3U]));
        bufp->chgIData(oldp+164,(vlSelfRef.systolic_array__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+165,(vlSelfRef.systolic_array__DOT__unnamedblk1__DOT__unnamedblk2__DOT__d),32);
        bufp->chgIData(oldp+166,(vlSelfRef.systolic_array__DOT__unnamedblk3__DOT__j),32);
        bufp->chgIData(oldp+167,(vlSelfRef.systolic_array__DOT__unnamedblk3__DOT__unnamedblk4__DOT__d),32);
        bufp->chgIData(oldp+168,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0U][0U]),32);
        bufp->chgIData(oldp+169,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0U][0U]),32);
        bufp->chgBit(oldp+170,(vlSelfRef.systolic_array__DOT__v_wire
                               [0U][0U]));
        bufp->chgIData(oldp+171,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+172,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+173,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+174,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+175,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+176,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+177,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+178,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+179,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+180,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+181,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+182,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+183,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+184,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+185,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+186,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+187,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+188,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+189,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+190,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+191,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+192,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+193,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+194,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+195,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+196,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+197,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+198,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+199,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+200,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+201,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+202,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+203,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+204,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+205,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+206,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+207,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+208,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+209,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+210,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+211,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+212,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+213,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+214,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+215,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+216,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+217,((vlSelfRef.systolic_array__DOT__a_wire
                                [0U][0U] >> 0x1fU)));
        bufp->chgBit(oldp+218,((vlSelfRef.systolic_array__DOT__b_wire
                                [0U][0U] >> 0x1fU)));
        bufp->chgCData(oldp+219,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                           [0U][0U] 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+220,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                           [0U][0U] 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+221,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                  [0U][0U])),23);
        bufp->chgIData(oldp+222,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                  [0U][0U])),23);
        bufp->chgBit(oldp+223,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+224,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+225,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+226,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+227,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+228,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+229,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+230,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+231,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+232,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+233,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+234,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+235,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+236,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+237,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+238,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+239,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+241,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+242,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+243,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+244,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+245,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+246,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0U][1U]),32);
        bufp->chgIData(oldp+247,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0U][1U]),32);
        bufp->chgBit(oldp+248,(vlSelfRef.systolic_array__DOT__v_wire
                               [0U][1U]));
        bufp->chgIData(oldp+249,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+250,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+251,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+252,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+253,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+254,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+255,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+256,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+257,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+258,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+259,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+260,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+261,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+262,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+263,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+264,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+265,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+266,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+267,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+268,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+269,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+270,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+271,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+272,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+273,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+274,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+275,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+276,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+277,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+278,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+279,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+280,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+281,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+282,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+283,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+284,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+285,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+286,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+287,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+288,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+289,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+290,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+291,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+292,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+293,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+294,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+295,((vlSelfRef.systolic_array__DOT__a_wire
                                [0U][1U] >> 0x1fU)));
        bufp->chgBit(oldp+296,((vlSelfRef.systolic_array__DOT__b_wire
                                [0U][1U] >> 0x1fU)));
        bufp->chgCData(oldp+297,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                           [0U][1U] 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+298,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                           [0U][1U] 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+299,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                  [0U][1U])),23);
        bufp->chgIData(oldp+300,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                  [0U][1U])),23);
        bufp->chgBit(oldp+301,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+302,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+303,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+304,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+305,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+306,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+307,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+308,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+309,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+310,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+311,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+312,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+313,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+314,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+315,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+316,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+317,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+319,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+320,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+321,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+322,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+323,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+324,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0U][2U]),32);
        bufp->chgIData(oldp+325,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0U][2U]),32);
        bufp->chgBit(oldp+326,(vlSelfRef.systolic_array__DOT__v_wire
                               [0U][2U]));
        bufp->chgIData(oldp+327,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+328,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+329,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+330,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+331,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+332,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+333,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+334,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+335,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+336,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+337,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+338,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+339,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+340,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+341,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+342,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+343,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+344,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+345,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+346,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+347,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+348,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+349,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+350,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+351,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+352,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+353,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+354,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+355,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+356,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+357,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+358,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+359,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+360,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+361,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+362,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+363,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+364,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+365,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+366,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+367,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+368,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+369,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+370,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+371,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+372,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+373,((vlSelfRef.systolic_array__DOT__a_wire
                                [0U][2U] >> 0x1fU)));
        bufp->chgBit(oldp+374,((vlSelfRef.systolic_array__DOT__b_wire
                                [0U][2U] >> 0x1fU)));
        bufp->chgCData(oldp+375,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                           [0U][2U] 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+376,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                           [0U][2U] 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+377,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                  [0U][2U])),23);
        bufp->chgIData(oldp+378,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                  [0U][2U])),23);
        bufp->chgBit(oldp+379,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+380,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+381,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+382,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+383,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+384,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+385,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+386,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+387,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+388,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+389,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+390,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+391,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+392,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+393,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+394,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+395,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+397,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+398,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+399,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+400,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+401,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+402,(vlSelfRef.systolic_array__DOT__a_wire
                                 [0U][3U]),32);
        bufp->chgIData(oldp+403,(vlSelfRef.systolic_array__DOT__b_wire
                                 [0U][3U]),32);
        bufp->chgBit(oldp+404,(vlSelfRef.systolic_array__DOT__v_wire
                               [0U][3U]));
        bufp->chgIData(oldp+405,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+406,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+407,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+408,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+409,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+410,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+411,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+412,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+413,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+414,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+415,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+416,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+417,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+418,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+419,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+420,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+421,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+422,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+423,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+424,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+425,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+426,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+427,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+428,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+429,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+430,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+431,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+432,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+433,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+434,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+435,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+436,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+437,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+438,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+439,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+440,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+441,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+442,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+443,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+444,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+445,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+446,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+447,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+448,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+449,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+450,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+451,((vlSelfRef.systolic_array__DOT__a_wire
                                [0U][3U] >> 0x1fU)));
        bufp->chgBit(oldp+452,((vlSelfRef.systolic_array__DOT__b_wire
                                [0U][3U] >> 0x1fU)));
        bufp->chgCData(oldp+453,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                           [0U][3U] 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+454,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                           [0U][3U] 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+455,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                  [0U][3U])),23);
        bufp->chgIData(oldp+456,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                  [0U][3U])),23);
        bufp->chgBit(oldp+457,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+458,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+459,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+460,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+461,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+462,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+463,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+464,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+465,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+466,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+467,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+468,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+469,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+470,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+471,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+472,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+473,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+475,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+476,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+477,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+478,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+479,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+480,(vlSelfRef.systolic_array__DOT__a_wire
                                 [1U][0U]),32);
        bufp->chgIData(oldp+481,(vlSelfRef.systolic_array__DOT__b_wire
                                 [1U][0U]),32);
        bufp->chgBit(oldp+482,(vlSelfRef.systolic_array__DOT__v_wire
                               [1U][0U]));
        bufp->chgIData(oldp+483,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+484,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+485,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+486,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+487,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+488,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+489,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+490,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+491,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+492,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+493,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+494,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+495,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+496,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+497,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+498,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+499,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+500,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+501,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+502,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+503,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+504,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+505,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+506,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+507,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+508,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+509,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+510,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+511,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+512,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+513,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+514,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+515,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+516,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+517,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+518,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+519,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+520,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+521,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+522,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+523,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+524,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+525,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+526,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+527,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+528,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+529,((vlSelfRef.systolic_array__DOT__a_wire
                                [1U][0U] >> 0x1fU)));
        bufp->chgBit(oldp+530,((vlSelfRef.systolic_array__DOT__b_wire
                                [1U][0U] >> 0x1fU)));
        bufp->chgCData(oldp+531,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                           [1U][0U] 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+532,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                           [1U][0U] 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+533,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                  [1U][0U])),23);
        bufp->chgIData(oldp+534,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                  [1U][0U])),23);
        bufp->chgBit(oldp+535,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+536,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+537,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+538,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+539,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+540,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+541,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+542,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+543,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+544,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+545,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+546,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+547,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+548,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+549,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+550,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+551,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+553,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+554,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+555,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+556,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+557,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+558,(vlSelfRef.systolic_array__DOT__a_wire
                                 [1U][1U]),32);
        bufp->chgIData(oldp+559,(vlSelfRef.systolic_array__DOT__b_wire
                                 [1U][1U]),32);
        bufp->chgBit(oldp+560,(vlSelfRef.systolic_array__DOT__v_wire
                               [1U][1U]));
        bufp->chgIData(oldp+561,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+562,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+563,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+564,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+565,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+566,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+567,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+568,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+569,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+570,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+571,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+572,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+573,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+574,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+575,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+576,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+577,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+578,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+579,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+580,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+581,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+582,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+583,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+584,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+585,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+586,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+587,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+588,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+589,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+590,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+591,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+592,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+593,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+594,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+595,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+596,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+597,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+598,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+599,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+600,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+601,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+602,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+603,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+604,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+605,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+606,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+607,((vlSelfRef.systolic_array__DOT__a_wire
                                [1U][1U] >> 0x1fU)));
        bufp->chgBit(oldp+608,((vlSelfRef.systolic_array__DOT__b_wire
                                [1U][1U] >> 0x1fU)));
        bufp->chgCData(oldp+609,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                           [1U][1U] 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+610,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                           [1U][1U] 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+611,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                  [1U][1U])),23);
        bufp->chgIData(oldp+612,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                  [1U][1U])),23);
        bufp->chgBit(oldp+613,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+614,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+615,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+616,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+617,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+618,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+619,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+620,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+621,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+622,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+623,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+624,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+625,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+626,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+627,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+628,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+629,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+631,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+632,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+633,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+634,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+635,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+636,(vlSelfRef.systolic_array__DOT__a_wire
                                 [1U][2U]),32);
        bufp->chgIData(oldp+637,(vlSelfRef.systolic_array__DOT__b_wire
                                 [1U][2U]),32);
        bufp->chgBit(oldp+638,(vlSelfRef.systolic_array__DOT__v_wire
                               [1U][2U]));
        bufp->chgIData(oldp+639,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+640,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+641,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+642,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+643,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+644,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+645,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+646,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+647,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+648,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+649,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+650,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+651,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+652,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+653,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+654,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+655,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+656,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+657,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+658,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+659,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+660,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+661,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+662,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+663,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+664,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+665,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+666,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+667,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+668,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+669,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+670,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+671,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+672,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+673,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+674,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+675,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+676,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+677,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+678,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+679,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+680,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+681,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+682,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+683,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+684,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+685,((vlSelfRef.systolic_array__DOT__a_wire
                                [1U][2U] >> 0x1fU)));
        bufp->chgBit(oldp+686,((vlSelfRef.systolic_array__DOT__b_wire
                                [1U][2U] >> 0x1fU)));
        bufp->chgCData(oldp+687,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                           [1U][2U] 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+688,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                           [1U][2U] 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+689,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                  [1U][2U])),23);
        bufp->chgIData(oldp+690,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                  [1U][2U])),23);
        bufp->chgBit(oldp+691,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+692,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+693,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+694,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+695,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+696,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+697,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+698,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+699,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+700,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+701,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+702,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+703,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+704,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+705,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+706,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+707,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+709,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+710,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+711,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+712,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+713,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+714,(vlSelfRef.systolic_array__DOT__a_wire
                                 [1U][3U]),32);
        bufp->chgIData(oldp+715,(vlSelfRef.systolic_array__DOT__b_wire
                                 [1U][3U]),32);
        bufp->chgBit(oldp+716,(vlSelfRef.systolic_array__DOT__v_wire
                               [1U][3U]));
        bufp->chgIData(oldp+717,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+718,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+719,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+720,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+721,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+722,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+723,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+724,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+725,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+726,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+727,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+728,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+729,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+730,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+731,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+732,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+733,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+734,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+735,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+736,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+737,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+738,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+739,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+740,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+741,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+742,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+743,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+744,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+745,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+746,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+747,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+748,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+749,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+750,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+751,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+752,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+753,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+754,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+755,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+756,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+757,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+758,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+759,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+760,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+761,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+762,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+763,((vlSelfRef.systolic_array__DOT__a_wire
                                [1U][3U] >> 0x1fU)));
        bufp->chgBit(oldp+764,((vlSelfRef.systolic_array__DOT__b_wire
                                [1U][3U] >> 0x1fU)));
        bufp->chgCData(oldp+765,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                           [1U][3U] 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+766,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                           [1U][3U] 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+767,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                  [1U][3U])),23);
        bufp->chgIData(oldp+768,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                  [1U][3U])),23);
        bufp->chgBit(oldp+769,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+770,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+771,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+772,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+773,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+774,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+775,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+776,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+777,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+778,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+779,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+780,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+781,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+782,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+783,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+784,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+785,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+787,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+788,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+789,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+790,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+791,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+792,(vlSelfRef.systolic_array__DOT__a_wire
                                 [2U][0U]),32);
        bufp->chgIData(oldp+793,(vlSelfRef.systolic_array__DOT__b_wire
                                 [2U][0U]),32);
        bufp->chgBit(oldp+794,(vlSelfRef.systolic_array__DOT__v_wire
                               [2U][0U]));
        bufp->chgIData(oldp+795,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+796,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+797,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+798,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+799,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+800,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+801,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+802,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+803,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+804,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+805,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+806,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+807,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+808,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+809,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+810,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+811,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+812,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+813,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+814,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+815,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+816,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+817,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+818,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+819,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+820,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+821,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+822,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+823,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+824,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+825,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+826,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+827,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+828,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+829,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+830,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+831,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+832,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+833,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+834,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+835,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+836,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+837,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+838,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+839,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+840,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+841,((vlSelfRef.systolic_array__DOT__a_wire
                                [2U][0U] >> 0x1fU)));
        bufp->chgBit(oldp+842,((vlSelfRef.systolic_array__DOT__b_wire
                                [2U][0U] >> 0x1fU)));
        bufp->chgCData(oldp+843,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                           [2U][0U] 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+844,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                           [2U][0U] 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+845,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                  [2U][0U])),23);
        bufp->chgIData(oldp+846,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                  [2U][0U])),23);
        bufp->chgBit(oldp+847,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+848,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+849,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+850,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+851,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+852,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+853,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+854,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+855,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+856,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+857,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+858,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+859,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+860,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+861,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+862,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+863,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+865,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+866,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+867,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+868,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+869,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+870,(vlSelfRef.systolic_array__DOT__a_wire
                                 [2U][1U]),32);
        bufp->chgIData(oldp+871,(vlSelfRef.systolic_array__DOT__b_wire
                                 [2U][1U]),32);
        bufp->chgBit(oldp+872,(vlSelfRef.systolic_array__DOT__v_wire
                               [2U][1U]));
        bufp->chgIData(oldp+873,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+874,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+875,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+876,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+877,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+878,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+879,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+880,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+881,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+882,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+883,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+884,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+885,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+886,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+887,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+888,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+889,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+890,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+891,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+892,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+893,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+894,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+895,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+896,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+897,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+898,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+899,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+900,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+901,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+902,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+903,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+904,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+905,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+906,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+907,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+908,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+909,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+910,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+911,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+912,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+913,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+914,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+915,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+916,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+917,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+918,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+919,((vlSelfRef.systolic_array__DOT__a_wire
                                [2U][1U] >> 0x1fU)));
        bufp->chgBit(oldp+920,((vlSelfRef.systolic_array__DOT__b_wire
                                [2U][1U] >> 0x1fU)));
        bufp->chgCData(oldp+921,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                           [2U][1U] 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+922,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                           [2U][1U] 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+923,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                  [2U][1U])),23);
        bufp->chgIData(oldp+924,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                  [2U][1U])),23);
        bufp->chgBit(oldp+925,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+926,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+927,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+928,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+929,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+930,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+931,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+932,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+933,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+934,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+935,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+936,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+937,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+938,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+939,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+940,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+941,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+943,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+944,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+945,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+946,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+947,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+948,(vlSelfRef.systolic_array__DOT__a_wire
                                 [2U][2U]),32);
        bufp->chgIData(oldp+949,(vlSelfRef.systolic_array__DOT__b_wire
                                 [2U][2U]),32);
        bufp->chgBit(oldp+950,(vlSelfRef.systolic_array__DOT__v_wire
                               [2U][2U]));
        bufp->chgIData(oldp+951,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+952,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+953,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+954,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+955,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+956,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+957,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+958,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+959,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+960,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+961,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+962,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+963,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+964,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+965,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+966,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+967,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+968,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+969,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+970,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+971,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                >> 0x1fU)));
        bufp->chgBit(oldp+972,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                >> 0x1fU)));
        bufp->chgCData(oldp+973,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+974,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+975,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+976,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                   >> 0x17U)))
                                   ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                   : (0x800000U | (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+977,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+978,((IData)(((0x7f800000U 
                                         == (0x7f800000U 
                                             & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                        & (0U != (0x7fffffU 
                                                  & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+979,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+980,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+981,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+982,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+983,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+984,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+985,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+986,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+987,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+988,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+989,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+990,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+991,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+992,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+993,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+994,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+995,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+996,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+997,((vlSelfRef.systolic_array__DOT__a_wire
                                [2U][2U] >> 0x1fU)));
        bufp->chgBit(oldp+998,((vlSelfRef.systolic_array__DOT__b_wire
                                [2U][2U] >> 0x1fU)));
        bufp->chgCData(oldp+999,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                           [2U][2U] 
                                           >> 0x17U))),8);
        bufp->chgCData(oldp+1000,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                            [2U][2U] 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1001,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                   [2U][2U])),23);
        bufp->chgIData(oldp+1002,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                   [2U][2U])),23);
        bufp->chgBit(oldp+1003,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+1004,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+1005,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+1006,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+1007,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+1008,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+1009,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+1010,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+1011,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+1012,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+1013,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+1014,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+1015,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+1016,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+1017,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+1018,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+1019,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+1021,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+1022,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+1023,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+1024,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+1025,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+1026,(vlSelfRef.systolic_array__DOT__a_wire
                                  [2U][3U]),32);
        bufp->chgIData(oldp+1027,(vlSelfRef.systolic_array__DOT__b_wire
                                  [2U][3U]),32);
        bufp->chgBit(oldp+1028,(vlSelfRef.systolic_array__DOT__v_wire
                                [2U][3U]));
        bufp->chgIData(oldp+1029,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+1030,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+1031,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+1032,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+1033,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+1034,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+1035,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+1036,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+1037,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+1038,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+1039,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+1040,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+1041,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+1042,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+1043,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+1044,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+1045,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+1046,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+1047,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+1048,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+1049,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                 >> 0x1fU)));
        bufp->chgBit(oldp+1050,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                 >> 0x1fU)));
        bufp->chgCData(oldp+1051,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1052,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1053,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+1054,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+1055,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+1056,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+1057,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+1058,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+1059,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+1060,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+1061,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+1062,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+1063,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+1064,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+1065,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+1066,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+1067,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+1068,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+1069,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+1070,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+1071,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+1072,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+1073,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+1074,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+1075,((vlSelfRef.systolic_array__DOT__a_wire
                                 [2U][3U] >> 0x1fU)));
        bufp->chgBit(oldp+1076,((vlSelfRef.systolic_array__DOT__b_wire
                                 [2U][3U] >> 0x1fU)));
        bufp->chgCData(oldp+1077,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                            [2U][3U] 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1078,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                            [2U][3U] 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1079,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                   [2U][3U])),23);
        bufp->chgIData(oldp+1080,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                   [2U][3U])),23);
        bufp->chgBit(oldp+1081,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+1082,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+1083,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+1084,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+1085,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+1086,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+1087,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+1088,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+1089,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+1090,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+1091,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+1092,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+1093,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+1094,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+1095,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+1096,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+1097,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+1099,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+1100,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+1101,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+1102,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+1103,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+1104,(vlSelfRef.systolic_array__DOT__a_wire
                                  [3U][0U]),32);
        bufp->chgIData(oldp+1105,(vlSelfRef.systolic_array__DOT__b_wire
                                  [3U][0U]),32);
        bufp->chgBit(oldp+1106,(vlSelfRef.systolic_array__DOT__v_wire
                                [3U][0U]));
        bufp->chgIData(oldp+1107,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+1108,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+1109,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+1110,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+1111,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+1112,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+1113,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+1114,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+1115,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+1116,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+1117,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+1118,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+1119,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+1120,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+1121,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+1122,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+1123,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+1124,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+1125,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+1126,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+1127,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                 >> 0x1fU)));
        bufp->chgBit(oldp+1128,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                 >> 0x1fU)));
        bufp->chgCData(oldp+1129,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1130,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1131,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+1132,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+1133,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+1134,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+1135,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+1136,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+1137,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+1138,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+1139,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+1140,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+1141,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+1142,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+1143,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+1144,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+1145,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+1146,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+1147,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+1148,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+1149,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+1150,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+1151,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+1152,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+1153,((vlSelfRef.systolic_array__DOT__a_wire
                                 [3U][0U] >> 0x1fU)));
        bufp->chgBit(oldp+1154,((vlSelfRef.systolic_array__DOT__b_wire
                                 [3U][0U] >> 0x1fU)));
        bufp->chgCData(oldp+1155,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                            [3U][0U] 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1156,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                            [3U][0U] 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1157,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                   [3U][0U])),23);
        bufp->chgIData(oldp+1158,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                   [3U][0U])),23);
        bufp->chgBit(oldp+1159,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+1160,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+1161,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+1162,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+1163,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+1164,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+1165,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+1166,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+1167,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+1168,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+1169,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+1170,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+1171,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+1172,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+1173,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+1174,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+1175,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+1177,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+1178,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+1179,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+1180,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+1181,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+1182,(vlSelfRef.systolic_array__DOT__a_wire
                                  [3U][1U]),32);
        bufp->chgIData(oldp+1183,(vlSelfRef.systolic_array__DOT__b_wire
                                  [3U][1U]),32);
        bufp->chgBit(oldp+1184,(vlSelfRef.systolic_array__DOT__v_wire
                                [3U][1U]));
        bufp->chgIData(oldp+1185,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+1186,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+1187,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+1188,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+1189,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+1190,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+1191,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+1192,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+1193,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+1194,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+1195,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+1196,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+1197,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+1198,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+1199,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+1200,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+1201,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+1202,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+1203,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+1204,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+1205,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                 >> 0x1fU)));
        bufp->chgBit(oldp+1206,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                 >> 0x1fU)));
        bufp->chgCData(oldp+1207,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1208,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1209,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+1210,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+1211,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+1212,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+1213,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+1214,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+1215,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+1216,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+1217,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+1218,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+1219,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+1220,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+1221,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+1222,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+1223,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+1224,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+1225,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+1226,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+1227,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+1228,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+1229,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+1230,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+1231,((vlSelfRef.systolic_array__DOT__a_wire
                                 [3U][1U] >> 0x1fU)));
        bufp->chgBit(oldp+1232,((vlSelfRef.systolic_array__DOT__b_wire
                                 [3U][1U] >> 0x1fU)));
        bufp->chgCData(oldp+1233,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                            [3U][1U] 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1234,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                            [3U][1U] 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1235,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                   [3U][1U])),23);
        bufp->chgIData(oldp+1236,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                   [3U][1U])),23);
        bufp->chgBit(oldp+1237,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+1238,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+1239,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+1240,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+1241,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+1242,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+1243,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+1244,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+1245,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+1246,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+1247,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+1248,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+1249,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+1250,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+1251,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+1252,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+1253,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+1255,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+1256,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+1257,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+1258,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+1259,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+1260,(vlSelfRef.systolic_array__DOT__a_wire
                                  [3U][2U]),32);
        bufp->chgIData(oldp+1261,(vlSelfRef.systolic_array__DOT__b_wire
                                  [3U][2U]),32);
        bufp->chgBit(oldp+1262,(vlSelfRef.systolic_array__DOT__v_wire
                                [3U][2U]));
        bufp->chgIData(oldp+1263,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+1264,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+1265,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+1266,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+1267,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+1268,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+1269,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+1270,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+1271,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+1272,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+1273,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+1274,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+1275,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+1276,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+1277,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+1278,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+1279,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+1280,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+1281,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+1282,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+1283,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                 >> 0x1fU)));
        bufp->chgBit(oldp+1284,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                 >> 0x1fU)));
        bufp->chgCData(oldp+1285,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1286,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1287,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+1288,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+1289,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+1290,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+1291,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+1292,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+1293,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+1294,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+1295,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+1296,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+1297,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+1298,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+1299,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+1300,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+1301,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+1302,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+1303,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+1304,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+1305,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+1306,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+1307,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+1308,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+1309,((vlSelfRef.systolic_array__DOT__a_wire
                                 [3U][2U] >> 0x1fU)));
        bufp->chgBit(oldp+1310,((vlSelfRef.systolic_array__DOT__b_wire
                                 [3U][2U] >> 0x1fU)));
        bufp->chgCData(oldp+1311,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                            [3U][2U] 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1312,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                            [3U][2U] 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1313,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                   [3U][2U])),23);
        bufp->chgIData(oldp+1314,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                   [3U][2U])),23);
        bufp->chgBit(oldp+1315,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+1316,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+1317,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+1318,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+1319,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+1320,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+1321,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+1322,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+1323,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+1324,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+1325,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+1326,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+1327,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+1328,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+1329,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+1330,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+1331,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+1333,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+1334,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+1335,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+1336,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+1337,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+1338,(vlSelfRef.systolic_array__DOT__a_wire
                                  [3U][3U]),32);
        bufp->chgIData(oldp+1339,(vlSelfRef.systolic_array__DOT__b_wire
                                  [3U][3U]),32);
        bufp->chgBit(oldp+1340,(vlSelfRef.systolic_array__DOT__v_wire
                                [3U][3U]));
        bufp->chgIData(oldp+1341,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),32);
        bufp->chgIData(oldp+1342,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),32);
        bufp->chgBit(oldp+1343,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
        bufp->chgIData(oldp+1344,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
        bufp->chgBit(oldp+1345,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
        bufp->chgIData(oldp+1346,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_result),32);
        bufp->chgBit(oldp+1347,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s3_valid));
        bufp->chgIData(oldp+1348,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
        bufp->chgIData(oldp+1349,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
        bufp->chgIData(oldp+1350,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
        bufp->chgIData(oldp+1351,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
        bufp->chgIData(oldp+1352,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
        bufp->chgBit(oldp+1353,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
        bufp->chgCData(oldp+1354,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
        bufp->chgIData(oldp+1355,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
        bufp->chgBit(oldp+1356,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
        bufp->chgIData(oldp+1357,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
        bufp->chgBit(oldp+1358,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
        bufp->chgBit(oldp+1359,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
        bufp->chgIData(oldp+1360,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
        bufp->chgBit(oldp+1361,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                 >> 0x1fU)));
        bufp->chgBit(oldp+1362,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                 >> 0x1fU)));
        bufp->chgCData(oldp+1363,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1364,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1365,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
        bufp->chgIData(oldp+1366,(((0U == (0xffU & 
                                           (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                            >> 0x17U)))
                                    ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                    : (0x800000U | 
                                       (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
        bufp->chgBit(oldp+1367,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
        bufp->chgBit(oldp+1368,((IData)(((0x7f800000U 
                                          == (0x7f800000U 
                                              & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                         & (0U != (0x7fffffU 
                                                   & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
        bufp->chgBit(oldp+1369,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
        bufp->chgBit(oldp+1370,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
        bufp->chgBit(oldp+1371,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
        bufp->chgBit(oldp+1372,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
        bufp->chgBit(oldp+1373,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
        bufp->chgBit(oldp+1374,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
        bufp->chgCData(oldp+1375,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
        bufp->chgCData(oldp+1376,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
        bufp->chgIData(oldp+1377,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
        bufp->chgIData(oldp+1378,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
        bufp->chgIData(oldp+1379,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
        bufp->chgIData(oldp+1380,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
        bufp->chgBit(oldp+1381,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
        bufp->chgCData(oldp+1382,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
        bufp->chgIData(oldp+1383,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
        bufp->chgCData(oldp+1384,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
        bufp->chgIData(oldp+1385,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
        bufp->chgIData(oldp+1386,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
        bufp->chgBit(oldp+1387,((vlSelfRef.systolic_array__DOT__a_wire
                                 [3U][3U] >> 0x1fU)));
        bufp->chgBit(oldp+1388,((vlSelfRef.systolic_array__DOT__b_wire
                                 [3U][3U] >> 0x1fU)));
        bufp->chgCData(oldp+1389,((0xffU & (vlSelfRef.systolic_array__DOT__a_wire
                                            [3U][3U] 
                                            >> 0x17U))),8);
        bufp->chgCData(oldp+1390,((0xffU & (vlSelfRef.systolic_array__DOT__b_wire
                                            [3U][3U] 
                                            >> 0x17U))),8);
        bufp->chgIData(oldp+1391,((0x7fffffU & vlSelfRef.systolic_array__DOT__a_wire
                                   [3U][3U])),23);
        bufp->chgIData(oldp+1392,((0x7fffffU & vlSelfRef.systolic_array__DOT__b_wire
                                   [3U][3U])),23);
        bufp->chgBit(oldp+1393,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_a));
        bufp->chgBit(oldp+1394,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__zero_b));
        bufp->chgBit(oldp+1395,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_a));
        bufp->chgBit(oldp+1396,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__inf_b));
        bufp->chgBit(oldp+1397,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_a));
        bufp->chgBit(oldp+1398,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__nan_b));
        bufp->chgBit(oldp+1399,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sign));
        bufp->chgSData(oldp+1400,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_exp),10);
        bufp->chgIData(oldp+1401,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_a),24);
        bufp->chgIData(oldp+1402,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_sig_b),24);
        bufp->chgBit(oldp+1403,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_zero));
        bufp->chgBit(oldp+1404,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_inf));
        bufp->chgBit(oldp+1405,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_is_nan));
        bufp->chgBit(oldp+1406,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s1_valid));
        bufp->chgBit(oldp+1407,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_sign));
        bufp->chgSData(oldp+1408,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_exp),10);
        bufp->chgQData(oldp+1409,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_product),48);
        bufp->chgBit(oldp+1411,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_zero));
        bufp->chgBit(oldp+1412,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_inf));
        bufp->chgBit(oldp+1413,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_is_nan));
        bufp->chgBit(oldp+1414,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__s2_valid));
        bufp->chgIData(oldp+1415,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+1416,(vlSelfRef.clk));
    bufp->chgBit(oldp+1417,(vlSelfRef.rst_n));
    bufp->chgIData(oldp+1418,(vlSelfRef.a_in[0]),32);
    bufp->chgIData(oldp+1419,(vlSelfRef.a_in[1]),32);
    bufp->chgIData(oldp+1420,(vlSelfRef.a_in[2]),32);
    bufp->chgIData(oldp+1421,(vlSelfRef.a_in[3]),32);
    bufp->chgIData(oldp+1422,(vlSelfRef.b_in[0]),32);
    bufp->chgIData(oldp+1423,(vlSelfRef.b_in[1]),32);
    bufp->chgIData(oldp+1424,(vlSelfRef.b_in[2]),32);
    bufp->chgIData(oldp+1425,(vlSelfRef.b_in[3]),32);
    bufp->chgBit(oldp+1426,(vlSelfRef.valid_in));
    bufp->chgIData(oldp+1427,(vlSelfRef.result[0U][0U]),32);
    bufp->chgIData(oldp+1428,(vlSelfRef.result[0U][1U]),32);
    bufp->chgIData(oldp+1429,(vlSelfRef.result[0U][2U]),32);
    bufp->chgIData(oldp+1430,(vlSelfRef.result[0U][3U]),32);
    bufp->chgIData(oldp+1431,(vlSelfRef.result[1U][0U]),32);
    bufp->chgIData(oldp+1432,(vlSelfRef.result[1U][1U]),32);
    bufp->chgIData(oldp+1433,(vlSelfRef.result[1U][2U]),32);
    bufp->chgIData(oldp+1434,(vlSelfRef.result[1U][3U]),32);
    bufp->chgIData(oldp+1435,(vlSelfRef.result[2U][0U]),32);
    bufp->chgIData(oldp+1436,(vlSelfRef.result[2U][1U]),32);
    bufp->chgIData(oldp+1437,(vlSelfRef.result[2U][2U]),32);
    bufp->chgIData(oldp+1438,(vlSelfRef.result[2U][3U]),32);
    bufp->chgIData(oldp+1439,(vlSelfRef.result[3U][0U]),32);
    bufp->chgIData(oldp+1440,(vlSelfRef.result[3U][1U]),32);
    bufp->chgIData(oldp+1441,(vlSelfRef.result[3U][2U]),32);
    bufp->chgIData(oldp+1442,(vlSelfRef.result[3U][3U]),32);
    bufp->chgBit(oldp+1443,(vlSelfRef.result_valid));
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
