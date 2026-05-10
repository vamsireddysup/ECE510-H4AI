// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsystolic_array__Syms.h"


VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("a_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+971+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("b_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+975+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+979,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("result", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+980,0,"[0]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+981,0,"[1]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+982,0,"[2]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+983,0,"[3]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+984,0,"[0]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+985,0,"[1]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+986,0,"[2]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+987,0,"[3]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+988,0,"[0]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+989,0,"[1]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+990,0,"[2]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+991,0,"[3]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+992,0,"[0]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+993,0,"[1]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+994,0,"[2]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+995,0,"[3]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBit(c+996,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("systolic_array", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+997,0,"SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+997,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+998,0,"ACC_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("a_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("b_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+5+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+979,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("result", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+9,0,"[0]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"[1]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"[2]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"[3]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+13,0,"[0]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"[1]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"[2]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"[3]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+17,0,"[0]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"[1]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"[2]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"[3]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+21,0,"[0]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"[1]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"[2]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"[3]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBit(c+996,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("a_wire", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+25,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+26,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+27,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+28,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+29,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+30,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+31,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+32,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+33,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+34,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+35,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+36,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+37,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+38,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+39,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+40,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+41,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+42,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+43,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+44,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("b_wire", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+45,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+46,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+47,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+48,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+49,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+50,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+51,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+52,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+53,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+54,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+55,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+56,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+57,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+58,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+59,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+60,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[4]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+61,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+62,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+63,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+64,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("v_wire_a", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+65,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+70,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+75,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+80,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("a_stagger", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+85,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+86,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+87,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+88,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+89,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+90,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+91,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+92,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+93,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+94,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+95,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+96,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+97,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+98,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+99,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+100,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("b_stagger", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+101,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+102,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+103,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+104,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+105,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+106,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+107,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+108,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+109,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+110,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+111,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+112,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+113,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+114,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+115,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+116,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("v_stagger_a", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+117,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+121,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+125,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+129,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("pe_result_valid", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+133,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+137,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+140,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+141,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+145,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+147,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_row[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("gen_col[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_row[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("gen_col[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_row[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("gen_col[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_row[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("gen_col[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_col[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+149,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+150,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+151,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+152,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+153,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+154,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+155,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+156,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+157,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+158,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+159,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+160,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+161,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+162,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+163+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+167,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+168,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+169,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+170,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+159,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+171,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+172,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+173,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+159,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+171,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+172,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+173,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+178,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+179,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+180,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+181,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+182,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+184,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+185,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+186,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+190,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+191,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+192,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+193,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+194,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+195,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+196,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+198,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+199,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+200,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+201,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+153,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+154,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+155,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+161,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+162,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+202,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+153,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+154,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+202,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+203,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+204,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+205,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+206,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+207,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+208,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+209,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+210,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+211,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+212,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+213,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+214+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+218,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+219,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+220,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+221,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+224,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+225,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+210,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+226,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+224,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+229,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+230,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+231,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+232,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+233,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+234,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+235,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+237,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+238,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+239,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+240,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+241,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+242,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+243,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+244,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+245,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+246,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+247,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+248,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+249,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+250,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+251,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+252,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+204,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+205,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+206,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+212,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+213,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+253,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+204,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+205,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+253,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+254,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+255,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+256,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+257,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+258,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+259,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+260,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+261,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+262,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+263,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+264,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+265+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+269,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+270,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+271,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+272,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+261,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+273,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+274,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+275,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+276,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+261,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+277,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+273,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+274,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+275,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+278,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+280,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+281,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+282,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+283,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+284,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+285,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+286,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+287,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+288,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+289,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+292,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+293,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+294,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+295,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+296,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+297,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+298,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+299,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+300,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+301,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+302,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+303,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+255,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+256,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+257,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+263,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+264,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+304,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+255,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+256,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+304,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+305,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+307,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+308,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+310,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+311,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+312,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+313,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+314,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+315,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+316+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+320,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+321,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+322,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+323,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+312,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+324,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+325,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+326,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+327,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+312,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+328,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+324,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+325,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+326,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+329,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+330,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+331,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+332,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+333,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+334,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+335,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+336,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+337,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+338,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+339,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+340,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+341,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+342,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+343,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+344,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+345,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+346,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+347,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+348,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+349,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+350,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+351,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+352,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+353,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+354,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+307,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+308,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+314,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+315,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+355,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+306,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+307,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+355,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+356,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+357,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+358,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+359,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+360,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+361,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+362,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+363,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+364,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+365,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+366,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+367+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+371,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+372,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+373,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+374,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+363,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+375,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+376,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+377,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+378,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+363,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+379,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+375,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+376,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+377,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+380,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+381,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+382,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+383,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+384,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+385,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+386,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+387,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+388,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+389,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+390,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+391,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+392,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+393,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+394,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+395,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+396,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+397,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+398,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+399,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+400,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+401,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+402,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+403,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+404,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+405,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+357,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+358,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+359,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+365,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+366,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+406,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+357,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+358,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+406,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+407,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+408,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+409,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+410,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+411,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+412,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+413,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+414,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+415,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+416,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+417,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+418+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+422,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+423,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+424,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+425,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+414,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+426,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+427,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+428,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+429,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+414,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+430,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+426,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+427,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+428,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+431,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+432,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+433,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+434,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+435,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+436,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+437,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+438,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+439,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+440,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+441,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+442,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+443,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+444,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+445,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+446,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+447,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+448,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+449,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+450,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+451,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+452,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+453,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+454,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+455,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+456,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+408,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+409,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+410,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+416,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+417,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+457,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+408,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+409,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+457,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+458,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+459,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+460,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+461,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+462,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+463,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+464,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+465,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+466,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+467,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+468,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+469+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+473,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+474,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+475,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+476,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+465,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+477,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+478,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+479,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+480,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+465,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+481,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+477,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+478,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+479,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+482,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+483,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+484,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+485,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+486,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+487,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+488,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+489,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+490,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+491,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+492,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+493,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+494,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+495,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+496,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+497,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+498,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+499,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+500,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+501,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+502,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+503,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+504,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+505,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+506,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+507,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+459,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+460,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+461,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+467,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+468,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+508,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+459,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+460,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+508,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+509,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+510,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+511,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+512,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+513,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+514,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+515,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+516,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+517,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+518,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+519,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+520+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+524,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+525,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+526,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+527,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+516,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+528,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+529,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+530,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+531,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+516,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+532,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+528,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+529,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+530,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+533,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+534,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+535,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+536,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+537,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+538,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+539,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+540,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+541,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+542,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+543,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+544,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+545,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+546,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+547,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+548,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+549,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+550,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+551,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+552,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+553,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+554,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+555,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+556,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+557,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+558,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+510,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+511,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+512,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+518,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+519,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+559,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+510,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+511,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+559,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+560,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+561,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+562,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+563,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+564,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+565,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+566,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+567,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+568,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+569,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+570,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+571+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+575,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+576,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+577,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+578,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+567,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+579,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+580,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+581,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+582,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+567,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+583,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+579,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+580,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+581,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+584,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+585,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+586,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+587,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+588,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+589,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+590,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+591,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+592,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+593,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+594,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+595,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+596,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+597,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+598,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+599,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+600,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+601,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+602,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+603,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+604,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+605,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+606,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+607,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+608,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+609,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+561,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+562,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+563,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+569,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+570,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+610,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+561,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+562,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+610,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+611,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+612,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+613,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+614,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+615,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+616,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+617,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+618,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+619,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+620,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+621,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+622+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+626,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+627,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+628,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+629,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+618,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+630,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+631,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+632,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+633,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+618,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+634,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+630,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+631,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+632,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+635,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+636,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+637,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+638,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+639,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+640,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+641,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+642,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+643,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+644,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+645,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+646,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+647,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+648,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+649,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+650,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+651,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+652,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+653,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+654,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+655,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+656,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+657,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+658,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+659,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+660,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+612,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+613,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+614,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+620,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+621,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+661,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+612,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+613,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+661,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+662,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+663,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+664,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+665,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+666,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+667,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+668,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+669,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+670,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+671,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+672,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+673+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+677,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+678,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+679,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+680,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+669,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+681,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+682,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+683,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+684,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+669,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+685,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+681,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+682,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+683,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+686,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+687,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+688,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+689,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+690,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+691,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+692,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+693,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+694,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+695,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+696,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+697,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+698,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+699,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+700,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+701,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+702,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+703,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+704,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+705,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+706,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+707,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+708,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+709,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+710,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+711,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+663,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+664,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+665,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+671,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+672,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+712,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+663,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+664,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+712,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+713,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+714,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+715,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+716,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+717,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+718,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+719,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+720,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+721,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+722,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+723,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+724+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+728,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+729,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+730,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+731,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+720,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+732,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+733,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+734,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+735,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+720,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+736,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+732,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+733,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+734,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+737,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+738,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+739,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+740,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+741,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+742,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+743,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+744,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+745,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+746,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+747,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+748,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+749,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+750,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+751,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+752,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+753,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+754,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+755,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+756,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+757,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+758,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+759,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+760,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+761,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+762,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+714,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+715,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+716,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+722,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+723,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+763,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+714,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+715,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+763,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+764,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+765,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+766,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+767,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+768,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+769,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+770,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+771,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+772,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+773,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+774,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+775+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+779,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+780,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+781,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+782,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+771,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+783,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+784,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+785,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+786,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+771,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+787,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+783,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+784,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+785,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+788,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+789,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+790,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+791,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+792,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+793,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+794,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+795,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+796,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+797,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+798,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+799,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+800,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+801,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+802,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+803,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+804,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+805,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+806,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+807,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+808,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+809,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+810,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+811,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+812,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+813,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+765,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+766,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+767,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+773,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+774,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+814,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+765,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+766,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+814,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+815,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+816,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+817,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+818,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+819,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+820,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+821,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+822,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+823,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+824,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+825,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+826+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+830,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+831,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+832,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+833,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+822,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+834,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+835,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+836,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+837,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+822,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+838,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+834,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+835,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+836,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+839,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+840,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+841,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+842,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+843,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+844,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+845,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+846,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+847,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+848,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+849,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+850,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+851,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+852,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+853,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+854,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+855,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+856,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+857,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+858,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+859,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+860,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+861,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+862,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+863,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+864,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+816,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+817,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+818,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+824,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+825,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+865,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+816,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+817,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+865,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+866,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+867,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+868,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+869,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+870,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+871,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+872,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+873,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+874,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+875,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+876,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+877+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+881,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+882,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+883,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+884,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+873,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+885,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+886,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+887,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+888,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+873,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+889,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+885,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+886,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+887,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+890,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+891,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+892,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+893,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+894,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+895,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+896,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+897,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+898,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+899,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+900,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+901,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+902,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+903,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+904,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+905,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+906,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+907,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+908,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+909,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+910,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+911,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+912,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+913,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+914,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+915,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+867,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+868,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+869,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+875,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+876,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+916,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+867,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+868,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+916,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+917,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_sub__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+997,0,"D_HEAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+918,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+919,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+920,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+921,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+922,0,"b_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+923,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+924,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+925,0,"result_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+926,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+927,0,"product_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("prod_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+928+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+932,0,"prod_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+933,0,"all_collected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+934,0,"acc_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+935,0,"add_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+924,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+936,0,"acc_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+937,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+938,0,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+939,0,"waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+924,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+940,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+936,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+937,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+938,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+941,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+942,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+943,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+944,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+945,0,"sig_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+946,0,"sig_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+947,0,"nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+948,0,"nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+949,0,"inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+950,0,"inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+951,0,"zero_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+952,0,"zero_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+953,0,"sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+954,0,"sign_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+955,0,"exp_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+956,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+957,0,"sig_l_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+958,0,"sig_s_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+959,0,"sig_s_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+960,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBit(c+961,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+962,0,"result_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+963,0,"result_man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+964,0,"lz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+965,0,"norm_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+966,0,"add_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+969,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+970,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+918,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+919,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+920,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+926,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+927,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+967,0,"lut_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_lut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+918,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+919,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+967,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+968,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_init_top(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_init_top\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsystolic_array___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vsystolic_array___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsystolic_array___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsystolic_array___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsystolic_array___024root__trace_register(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_register\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vsystolic_array___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vsystolic_array___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vsystolic_array___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vsystolic_array___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_const_0_sub_0(Vsystolic_array___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsystolic_array___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_const_0\n"); );
    // Init
    Vsystolic_array___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsystolic_array___024root*>(voidSelf);
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsystolic_array___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_const_0_sub_0(Vsystolic_array___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_const_0_sub_0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+997,(4U),32);
    bufp->fullIData(oldp+998,(0x20U),32);
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_full_0_sub_0(Vsystolic_array___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsystolic_array___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_full_0\n"); );
    // Init
    Vsystolic_array___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsystolic_array___024root*>(voidSelf);
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsystolic_array___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_full_0_sub_0(Vsystolic_array___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root__trace_full_0_sub_0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelfRef.systolic_array__DOT__a_in[0]),4);
    bufp->fullCData(oldp+2,(vlSelfRef.systolic_array__DOT__a_in[1]),4);
    bufp->fullCData(oldp+3,(vlSelfRef.systolic_array__DOT__a_in[2]),4);
    bufp->fullCData(oldp+4,(vlSelfRef.systolic_array__DOT__a_in[3]),4);
    bufp->fullCData(oldp+5,(vlSelfRef.systolic_array__DOT__b_in[0]),4);
    bufp->fullCData(oldp+6,(vlSelfRef.systolic_array__DOT__b_in[1]),4);
    bufp->fullCData(oldp+7,(vlSelfRef.systolic_array__DOT__b_in[2]),4);
    bufp->fullCData(oldp+8,(vlSelfRef.systolic_array__DOT__b_in[3]),4);
    bufp->fullIData(oldp+9,(vlSelfRef.systolic_array__DOT__result
                            [0U][0U]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.systolic_array__DOT__result
                             [0U][1U]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.systolic_array__DOT__result
                             [0U][2U]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.systolic_array__DOT__result
                             [0U][3U]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.systolic_array__DOT__result
                             [1U][0U]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.systolic_array__DOT__result
                             [1U][1U]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.systolic_array__DOT__result
                             [1U][2U]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.systolic_array__DOT__result
                             [1U][3U]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.systolic_array__DOT__result
                             [2U][0U]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.systolic_array__DOT__result
                             [2U][1U]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.systolic_array__DOT__result
                             [2U][2U]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.systolic_array__DOT__result
                             [2U][3U]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.systolic_array__DOT__result
                             [3U][0U]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.systolic_array__DOT__result
                             [3U][1U]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.systolic_array__DOT__result
                             [3U][2U]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.systolic_array__DOT__result
                             [3U][3U]),32);
    bufp->fullCData(oldp+25,(vlSelfRef.systolic_array__DOT__a_wire
                             [0U][0U]),4);
    bufp->fullCData(oldp+26,(vlSelfRef.systolic_array__DOT__a_wire
                             [0U][1U]),4);
    bufp->fullCData(oldp+27,(vlSelfRef.systolic_array__DOT__a_wire
                             [0U][2U]),4);
    bufp->fullCData(oldp+28,(vlSelfRef.systolic_array__DOT__a_wire
                             [0U][3U]),4);
    bufp->fullCData(oldp+29,(vlSelfRef.systolic_array__DOT__a_wire
                             [0U][4U]),4);
    bufp->fullCData(oldp+30,(vlSelfRef.systolic_array__DOT__a_wire
                             [1U][0U]),4);
    bufp->fullCData(oldp+31,(vlSelfRef.systolic_array__DOT__a_wire
                             [1U][1U]),4);
    bufp->fullCData(oldp+32,(vlSelfRef.systolic_array__DOT__a_wire
                             [1U][2U]),4);
    bufp->fullCData(oldp+33,(vlSelfRef.systolic_array__DOT__a_wire
                             [1U][3U]),4);
    bufp->fullCData(oldp+34,(vlSelfRef.systolic_array__DOT__a_wire
                             [1U][4U]),4);
    bufp->fullCData(oldp+35,(vlSelfRef.systolic_array__DOT__a_wire
                             [2U][0U]),4);
    bufp->fullCData(oldp+36,(vlSelfRef.systolic_array__DOT__a_wire
                             [2U][1U]),4);
    bufp->fullCData(oldp+37,(vlSelfRef.systolic_array__DOT__a_wire
                             [2U][2U]),4);
    bufp->fullCData(oldp+38,(vlSelfRef.systolic_array__DOT__a_wire
                             [2U][3U]),4);
    bufp->fullCData(oldp+39,(vlSelfRef.systolic_array__DOT__a_wire
                             [2U][4U]),4);
    bufp->fullCData(oldp+40,(vlSelfRef.systolic_array__DOT__a_wire
                             [3U][0U]),4);
    bufp->fullCData(oldp+41,(vlSelfRef.systolic_array__DOT__a_wire
                             [3U][1U]),4);
    bufp->fullCData(oldp+42,(vlSelfRef.systolic_array__DOT__a_wire
                             [3U][2U]),4);
    bufp->fullCData(oldp+43,(vlSelfRef.systolic_array__DOT__a_wire
                             [3U][3U]),4);
    bufp->fullCData(oldp+44,(vlSelfRef.systolic_array__DOT__a_wire
                             [3U][4U]),4);
    bufp->fullCData(oldp+45,(vlSelfRef.systolic_array__DOT__b_wire
                             [0U][0U]),4);
    bufp->fullCData(oldp+46,(vlSelfRef.systolic_array__DOT__b_wire
                             [0U][1U]),4);
    bufp->fullCData(oldp+47,(vlSelfRef.systolic_array__DOT__b_wire
                             [0U][2U]),4);
    bufp->fullCData(oldp+48,(vlSelfRef.systolic_array__DOT__b_wire
                             [0U][3U]),4);
    bufp->fullCData(oldp+49,(vlSelfRef.systolic_array__DOT__b_wire
                             [1U][0U]),4);
    bufp->fullCData(oldp+50,(vlSelfRef.systolic_array__DOT__b_wire
                             [1U][1U]),4);
    bufp->fullCData(oldp+51,(vlSelfRef.systolic_array__DOT__b_wire
                             [1U][2U]),4);
    bufp->fullCData(oldp+52,(vlSelfRef.systolic_array__DOT__b_wire
                             [1U][3U]),4);
    bufp->fullCData(oldp+53,(vlSelfRef.systolic_array__DOT__b_wire
                             [2U][0U]),4);
    bufp->fullCData(oldp+54,(vlSelfRef.systolic_array__DOT__b_wire
                             [2U][1U]),4);
    bufp->fullCData(oldp+55,(vlSelfRef.systolic_array__DOT__b_wire
                             [2U][2U]),4);
    bufp->fullCData(oldp+56,(vlSelfRef.systolic_array__DOT__b_wire
                             [2U][3U]),4);
    bufp->fullCData(oldp+57,(vlSelfRef.systolic_array__DOT__b_wire
                             [3U][0U]),4);
    bufp->fullCData(oldp+58,(vlSelfRef.systolic_array__DOT__b_wire
                             [3U][1U]),4);
    bufp->fullCData(oldp+59,(vlSelfRef.systolic_array__DOT__b_wire
                             [3U][2U]),4);
    bufp->fullCData(oldp+60,(vlSelfRef.systolic_array__DOT__b_wire
                             [3U][3U]),4);
    bufp->fullCData(oldp+61,(vlSelfRef.systolic_array__DOT__b_wire
                             [4U][0U]),4);
    bufp->fullCData(oldp+62,(vlSelfRef.systolic_array__DOT__b_wire
                             [4U][1U]),4);
    bufp->fullCData(oldp+63,(vlSelfRef.systolic_array__DOT__b_wire
                             [4U][2U]),4);
    bufp->fullCData(oldp+64,(vlSelfRef.systolic_array__DOT__b_wire
                             [4U][3U]),4);
    bufp->fullBit(oldp+65,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [0U][0U]));
    bufp->fullBit(oldp+66,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [0U][1U]));
    bufp->fullBit(oldp+67,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [0U][2U]));
    bufp->fullBit(oldp+68,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [0U][3U]));
    bufp->fullBit(oldp+69,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [0U][4U]));
    bufp->fullBit(oldp+70,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [1U][0U]));
    bufp->fullBit(oldp+71,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [1U][1U]));
    bufp->fullBit(oldp+72,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [1U][2U]));
    bufp->fullBit(oldp+73,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [1U][3U]));
    bufp->fullBit(oldp+74,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [1U][4U]));
    bufp->fullBit(oldp+75,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [2U][0U]));
    bufp->fullBit(oldp+76,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [2U][1U]));
    bufp->fullBit(oldp+77,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [2U][2U]));
    bufp->fullBit(oldp+78,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [2U][3U]));
    bufp->fullBit(oldp+79,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [2U][4U]));
    bufp->fullBit(oldp+80,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [3U][0U]));
    bufp->fullBit(oldp+81,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [3U][1U]));
    bufp->fullBit(oldp+82,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [3U][2U]));
    bufp->fullBit(oldp+83,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [3U][3U]));
    bufp->fullBit(oldp+84,(vlSelfRef.systolic_array__DOT__v_wire_a
                           [3U][4U]));
    bufp->fullCData(oldp+85,(vlSelfRef.systolic_array__DOT__a_stagger
                             [0U][0U]),4);
    bufp->fullCData(oldp+86,(vlSelfRef.systolic_array__DOT__a_stagger
                             [0U][1U]),4);
    bufp->fullCData(oldp+87,(vlSelfRef.systolic_array__DOT__a_stagger
                             [0U][2U]),4);
    bufp->fullCData(oldp+88,(vlSelfRef.systolic_array__DOT__a_stagger
                             [0U][3U]),4);
    bufp->fullCData(oldp+89,(vlSelfRef.systolic_array__DOT__a_stagger
                             [1U][0U]),4);
    bufp->fullCData(oldp+90,(vlSelfRef.systolic_array__DOT__a_stagger
                             [1U][1U]),4);
    bufp->fullCData(oldp+91,(vlSelfRef.systolic_array__DOT__a_stagger
                             [1U][2U]),4);
    bufp->fullCData(oldp+92,(vlSelfRef.systolic_array__DOT__a_stagger
                             [1U][3U]),4);
    bufp->fullCData(oldp+93,(vlSelfRef.systolic_array__DOT__a_stagger
                             [2U][0U]),4);
    bufp->fullCData(oldp+94,(vlSelfRef.systolic_array__DOT__a_stagger
                             [2U][1U]),4);
    bufp->fullCData(oldp+95,(vlSelfRef.systolic_array__DOT__a_stagger
                             [2U][2U]),4);
    bufp->fullCData(oldp+96,(vlSelfRef.systolic_array__DOT__a_stagger
                             [2U][3U]),4);
    bufp->fullCData(oldp+97,(vlSelfRef.systolic_array__DOT__a_stagger
                             [3U][0U]),4);
    bufp->fullCData(oldp+98,(vlSelfRef.systolic_array__DOT__a_stagger
                             [3U][1U]),4);
    bufp->fullCData(oldp+99,(vlSelfRef.systolic_array__DOT__a_stagger
                             [3U][2U]),4);
    bufp->fullCData(oldp+100,(vlSelfRef.systolic_array__DOT__a_stagger
                              [3U][3U]),4);
    bufp->fullCData(oldp+101,(vlSelfRef.systolic_array__DOT__b_stagger
                              [0U][0U]),4);
    bufp->fullCData(oldp+102,(vlSelfRef.systolic_array__DOT__b_stagger
                              [0U][1U]),4);
    bufp->fullCData(oldp+103,(vlSelfRef.systolic_array__DOT__b_stagger
                              [0U][2U]),4);
    bufp->fullCData(oldp+104,(vlSelfRef.systolic_array__DOT__b_stagger
                              [0U][3U]),4);
    bufp->fullCData(oldp+105,(vlSelfRef.systolic_array__DOT__b_stagger
                              [1U][0U]),4);
    bufp->fullCData(oldp+106,(vlSelfRef.systolic_array__DOT__b_stagger
                              [1U][1U]),4);
    bufp->fullCData(oldp+107,(vlSelfRef.systolic_array__DOT__b_stagger
                              [1U][2U]),4);
    bufp->fullCData(oldp+108,(vlSelfRef.systolic_array__DOT__b_stagger
                              [1U][3U]),4);
    bufp->fullCData(oldp+109,(vlSelfRef.systolic_array__DOT__b_stagger
                              [2U][0U]),4);
    bufp->fullCData(oldp+110,(vlSelfRef.systolic_array__DOT__b_stagger
                              [2U][1U]),4);
    bufp->fullCData(oldp+111,(vlSelfRef.systolic_array__DOT__b_stagger
                              [2U][2U]),4);
    bufp->fullCData(oldp+112,(vlSelfRef.systolic_array__DOT__b_stagger
                              [2U][3U]),4);
    bufp->fullCData(oldp+113,(vlSelfRef.systolic_array__DOT__b_stagger
                              [3U][0U]),4);
    bufp->fullCData(oldp+114,(vlSelfRef.systolic_array__DOT__b_stagger
                              [3U][1U]),4);
    bufp->fullCData(oldp+115,(vlSelfRef.systolic_array__DOT__b_stagger
                              [3U][2U]),4);
    bufp->fullCData(oldp+116,(vlSelfRef.systolic_array__DOT__b_stagger
                              [3U][3U]),4);
    bufp->fullBit(oldp+117,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [0U][0U]));
    bufp->fullBit(oldp+118,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [0U][1U]));
    bufp->fullBit(oldp+119,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [0U][2U]));
    bufp->fullBit(oldp+120,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [0U][3U]));
    bufp->fullBit(oldp+121,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [1U][0U]));
    bufp->fullBit(oldp+122,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [1U][1U]));
    bufp->fullBit(oldp+123,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [1U][2U]));
    bufp->fullBit(oldp+124,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [1U][3U]));
    bufp->fullBit(oldp+125,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [2U][0U]));
    bufp->fullBit(oldp+126,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [2U][1U]));
    bufp->fullBit(oldp+127,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [2U][2U]));
    bufp->fullBit(oldp+128,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [2U][3U]));
    bufp->fullBit(oldp+129,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [3U][0U]));
    bufp->fullBit(oldp+130,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [3U][1U]));
    bufp->fullBit(oldp+131,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [3U][2U]));
    bufp->fullBit(oldp+132,(vlSelfRef.systolic_array__DOT__v_stagger_a
                            [3U][3U]));
    bufp->fullBit(oldp+133,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [0U][0U]));
    bufp->fullBit(oldp+134,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [0U][1U]));
    bufp->fullBit(oldp+135,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [0U][2U]));
    bufp->fullBit(oldp+136,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [0U][3U]));
    bufp->fullBit(oldp+137,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [1U][0U]));
    bufp->fullBit(oldp+138,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [1U][1U]));
    bufp->fullBit(oldp+139,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [1U][2U]));
    bufp->fullBit(oldp+140,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [1U][3U]));
    bufp->fullBit(oldp+141,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [2U][0U]));
    bufp->fullBit(oldp+142,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [2U][1U]));
    bufp->fullBit(oldp+143,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [2U][2U]));
    bufp->fullBit(oldp+144,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [2U][3U]));
    bufp->fullBit(oldp+145,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [3U][0U]));
    bufp->fullBit(oldp+146,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [3U][1U]));
    bufp->fullBit(oldp+147,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [3U][2U]));
    bufp->fullBit(oldp+148,(vlSelfRef.systolic_array__DOT__pe_result_valid
                            [3U][3U]));
    bufp->fullIData(oldp+149,(vlSelfRef.systolic_array__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+150,(vlSelfRef.systolic_array__DOT__unnamedblk1__DOT__unnamedblk2__DOT__d),32);
    bufp->fullIData(oldp+151,(vlSelfRef.systolic_array__DOT__unnamedblk3__DOT__j),32);
    bufp->fullIData(oldp+152,(vlSelfRef.systolic_array__DOT__unnamedblk3__DOT__unnamedblk4__DOT__d),32);
    bufp->fullCData(oldp+153,(vlSelfRef.systolic_array__DOT__a_wire
                              [0U][0U]),4);
    bufp->fullCData(oldp+154,(vlSelfRef.systolic_array__DOT__b_wire
                              [0U][0U]),4);
    bufp->fullBit(oldp+155,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [0U][0U]));
    bufp->fullCData(oldp+156,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+157,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+158,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+159,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+160,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+161,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+162,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+163,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+164,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+165,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+166,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+167,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+168,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+169,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+170,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+171,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+172,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+173,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+174,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+175,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+176,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+177,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+178,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+179,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+180,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+181,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+182,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+183,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+184,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+185,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+186,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+187,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+188,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+189,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+190,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+191,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+192,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+193,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+194,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+195,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+196,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+197,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+198,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+199,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+200,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+201,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+202,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+203,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+204,(vlSelfRef.systolic_array__DOT__a_wire
                              [0U][1U]),4);
    bufp->fullCData(oldp+205,(vlSelfRef.systolic_array__DOT__b_wire
                              [0U][1U]),4);
    bufp->fullBit(oldp+206,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [0U][1U]));
    bufp->fullCData(oldp+207,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+208,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+209,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+210,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+211,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+212,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+213,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+214,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+215,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+216,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+217,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+218,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+219,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+220,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+221,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+222,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+223,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+224,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+225,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+226,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+227,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+228,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+229,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+230,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+231,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+232,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+233,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+234,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+235,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+236,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+237,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+238,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+239,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+240,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+241,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+242,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+243,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+244,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+245,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+246,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+247,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+248,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+249,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+250,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+251,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+252,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+253,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+254,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+255,(vlSelfRef.systolic_array__DOT__a_wire
                              [0U][2U]),4);
    bufp->fullCData(oldp+256,(vlSelfRef.systolic_array__DOT__b_wire
                              [0U][2U]),4);
    bufp->fullBit(oldp+257,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [0U][2U]));
    bufp->fullCData(oldp+258,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+259,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+260,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+261,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+262,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+263,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+264,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+265,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+266,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+267,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+268,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+269,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+270,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+271,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+272,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+273,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+274,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+275,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+276,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+277,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+278,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+279,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+280,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+281,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+282,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+283,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+284,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+285,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+286,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+287,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+288,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+289,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+290,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+291,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+292,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+293,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+294,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+295,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+296,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+297,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+298,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+299,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+300,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+301,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+302,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+303,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+304,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+305,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+306,(vlSelfRef.systolic_array__DOT__a_wire
                              [0U][3U]),4);
    bufp->fullCData(oldp+307,(vlSelfRef.systolic_array__DOT__b_wire
                              [0U][3U]),4);
    bufp->fullBit(oldp+308,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [0U][3U]));
    bufp->fullCData(oldp+309,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+310,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+311,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+312,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+313,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+314,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+315,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+316,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+317,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+318,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+319,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+320,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+321,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+322,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+323,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+324,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+325,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+326,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+327,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+328,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+329,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+330,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+331,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+332,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+333,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+334,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+335,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+336,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+337,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+338,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+339,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+340,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+341,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+342,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+343,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+344,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+345,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+346,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+347,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+348,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+349,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+350,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+351,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+352,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+353,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+354,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+355,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+356,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+357,(vlSelfRef.systolic_array__DOT__a_wire
                              [1U][0U]),4);
    bufp->fullCData(oldp+358,(vlSelfRef.systolic_array__DOT__b_wire
                              [1U][0U]),4);
    bufp->fullBit(oldp+359,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [1U][0U]));
    bufp->fullCData(oldp+360,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+361,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+362,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+363,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+364,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+365,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+366,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+367,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+368,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+369,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+370,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+371,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+372,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+373,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+374,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+375,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+376,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+377,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+378,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+379,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+380,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+381,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+382,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+383,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+384,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+385,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+386,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+387,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+388,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+389,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+390,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+391,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+392,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+393,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+394,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+395,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+396,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+397,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+398,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+399,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+400,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+401,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+402,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+403,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+404,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+405,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+406,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+407,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+408,(vlSelfRef.systolic_array__DOT__a_wire
                              [1U][1U]),4);
    bufp->fullCData(oldp+409,(vlSelfRef.systolic_array__DOT__b_wire
                              [1U][1U]),4);
    bufp->fullBit(oldp+410,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [1U][1U]));
    bufp->fullCData(oldp+411,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+412,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+413,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+414,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+415,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+416,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+417,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+418,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+419,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+420,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+421,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+422,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+423,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+424,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+425,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+426,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+427,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+428,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+429,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+430,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+431,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+432,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+433,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+434,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+435,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+436,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+437,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+438,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+439,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+440,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+441,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+442,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+443,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+444,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+445,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+446,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+447,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+448,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+449,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+450,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+451,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+452,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+453,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+454,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+455,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+456,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+457,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+458,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+459,(vlSelfRef.systolic_array__DOT__a_wire
                              [1U][2U]),4);
    bufp->fullCData(oldp+460,(vlSelfRef.systolic_array__DOT__b_wire
                              [1U][2U]),4);
    bufp->fullBit(oldp+461,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [1U][2U]));
    bufp->fullCData(oldp+462,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+463,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+464,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+465,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+466,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+467,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+468,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+469,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+470,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+471,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+472,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+473,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+474,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+475,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+476,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+477,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+478,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+479,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+480,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+481,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+482,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+483,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+484,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+485,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+486,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+487,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+488,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+489,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+490,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+491,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+492,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+493,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+494,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+495,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+496,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+497,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+498,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+499,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+500,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+501,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+502,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+503,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+504,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+505,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+506,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+507,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+508,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+509,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+510,(vlSelfRef.systolic_array__DOT__a_wire
                              [1U][3U]),4);
    bufp->fullCData(oldp+511,(vlSelfRef.systolic_array__DOT__b_wire
                              [1U][3U]),4);
    bufp->fullBit(oldp+512,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [1U][3U]));
    bufp->fullCData(oldp+513,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+514,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+515,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+516,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+517,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+518,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+519,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+520,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+521,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+522,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+523,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+524,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+525,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+526,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+527,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+528,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+529,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+530,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+531,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+532,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+533,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+534,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+535,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+536,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+537,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+538,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+539,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+540,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+541,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+542,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+543,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+544,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+545,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+546,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+547,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+548,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+549,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+550,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+551,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+552,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+553,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+554,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+555,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+556,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+557,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+558,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+559,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+560,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+561,(vlSelfRef.systolic_array__DOT__a_wire
                              [2U][0U]),4);
    bufp->fullCData(oldp+562,(vlSelfRef.systolic_array__DOT__b_wire
                              [2U][0U]),4);
    bufp->fullBit(oldp+563,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [2U][0U]));
    bufp->fullCData(oldp+564,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+565,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+566,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+567,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+568,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+569,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+570,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+571,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+572,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+573,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+574,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+575,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+576,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+577,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+578,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+579,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+580,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+581,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+582,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+583,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+584,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+585,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+586,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+587,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+588,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+589,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+590,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+591,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+592,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+593,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+594,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+595,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+596,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+597,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+598,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+599,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+600,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+601,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+602,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+603,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+604,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+605,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+606,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+607,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+608,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+609,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+610,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+611,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+612,(vlSelfRef.systolic_array__DOT__a_wire
                              [2U][1U]),4);
    bufp->fullCData(oldp+613,(vlSelfRef.systolic_array__DOT__b_wire
                              [2U][1U]),4);
    bufp->fullBit(oldp+614,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [2U][1U]));
    bufp->fullCData(oldp+615,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+616,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+617,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+618,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+619,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+620,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+621,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+622,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+623,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+624,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+625,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+626,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+627,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+628,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+629,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+630,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+631,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+632,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+633,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+634,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+635,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+636,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+637,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+638,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+639,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+640,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+641,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+642,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+643,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+644,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+645,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+646,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+647,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+648,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+649,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+650,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+651,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+652,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+653,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+654,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+655,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+656,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+657,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+658,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+659,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+660,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+661,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+662,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+663,(vlSelfRef.systolic_array__DOT__a_wire
                              [2U][2U]),4);
    bufp->fullCData(oldp+664,(vlSelfRef.systolic_array__DOT__b_wire
                              [2U][2U]),4);
    bufp->fullBit(oldp+665,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [2U][2U]));
    bufp->fullCData(oldp+666,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+667,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+668,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+669,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+670,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+671,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+672,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+673,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+674,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+675,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+676,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+677,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+678,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+679,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+680,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+681,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+682,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+683,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+684,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+685,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+686,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+687,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+688,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+689,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+690,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+691,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+692,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+693,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+694,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+695,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+696,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+697,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+698,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+699,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+700,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+701,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+702,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+703,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+704,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+705,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+706,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+707,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+708,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+709,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+710,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+711,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+712,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+713,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+714,(vlSelfRef.systolic_array__DOT__a_wire
                              [2U][3U]),4);
    bufp->fullCData(oldp+715,(vlSelfRef.systolic_array__DOT__b_wire
                              [2U][3U]),4);
    bufp->fullBit(oldp+716,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [2U][3U]));
    bufp->fullCData(oldp+717,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+718,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+719,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+720,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+721,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+722,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+723,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+724,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+725,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+726,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+727,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+728,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+729,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+730,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+731,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+732,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+733,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+734,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+735,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+736,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+737,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+738,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+739,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+740,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+741,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+742,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+743,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+744,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+745,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+746,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+747,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+748,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+749,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+750,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+751,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+752,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+753,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+754,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+755,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+756,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+757,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+758,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+759,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+760,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+761,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+762,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+763,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+764,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+765,(vlSelfRef.systolic_array__DOT__a_wire
                              [3U][0U]),4);
    bufp->fullCData(oldp+766,(vlSelfRef.systolic_array__DOT__b_wire
                              [3U][0U]),4);
    bufp->fullBit(oldp+767,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [3U][0U]));
    bufp->fullCData(oldp+768,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+769,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+770,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+771,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+772,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+773,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+774,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+775,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+776,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+777,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+778,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+779,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+780,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+781,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+782,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+783,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+784,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+785,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+786,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+787,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+788,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+789,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+790,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+791,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+792,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+793,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+794,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+795,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+796,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+797,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+798,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+799,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+800,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+801,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+802,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+803,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+804,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+805,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+806,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+807,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+808,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+809,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+810,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+811,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+812,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+813,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+814,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+815,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+816,(vlSelfRef.systolic_array__DOT__a_wire
                              [3U][1U]),4);
    bufp->fullCData(oldp+817,(vlSelfRef.systolic_array__DOT__b_wire
                              [3U][1U]),4);
    bufp->fullBit(oldp+818,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [3U][1U]));
    bufp->fullCData(oldp+819,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+820,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+821,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+822,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+823,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+824,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+825,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+826,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+827,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+828,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+829,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+830,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+831,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+832,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+833,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+834,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+835,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+836,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+837,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+838,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+839,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+840,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+841,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+842,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+843,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+844,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+845,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+846,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+847,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+848,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+849,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+850,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+851,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+852,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+853,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+854,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+855,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+856,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+857,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+858,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+859,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+860,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+861,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+862,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+863,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+864,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+865,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+866,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+867,(vlSelfRef.systolic_array__DOT__a_wire
                              [3U][2U]),4);
    bufp->fullCData(oldp+868,(vlSelfRef.systolic_array__DOT__b_wire
                              [3U][2U]),4);
    bufp->fullBit(oldp+869,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [3U][2U]));
    bufp->fullCData(oldp+870,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+871,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+872,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+873,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+874,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+875,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+876,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+877,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+878,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+879,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+880,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+881,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+882,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+883,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+884,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+885,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+886,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+887,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+888,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+889,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+890,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+891,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+892,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+893,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+894,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+895,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+896,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+897,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+898,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+899,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+900,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+901,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+902,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+903,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+904,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+905,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+906,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+907,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+908,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+909,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+910,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+911,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+912,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+913,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+914,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+915,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+916,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+917,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+918,(vlSelfRef.systolic_array__DOT__a_wire
                              [3U][3U]),4);
    bufp->fullCData(oldp+919,(vlSelfRef.systolic_array__DOT__b_wire
                              [3U][3U]),4);
    bufp->fullBit(oldp+920,(vlSelfRef.systolic_array__DOT__v_wire_a
                            [3U][3U]));
    bufp->fullCData(oldp+921,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out),4);
    bufp->fullCData(oldp+922,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out),4);
    bufp->fullBit(oldp+923,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out));
    bufp->fullIData(oldp+924,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc),32);
    bufp->fullBit(oldp+925,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid));
    bufp->fullIData(oldp+926,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product),32);
    bufp->fullBit(oldp+927,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__product_valid));
    bufp->fullIData(oldp+928,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[0]),32);
    bufp->fullIData(oldp+929,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[1]),32);
    bufp->fullIData(oldp+930,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[2]),32);
    bufp->fullIData(oldp+931,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_buf[3]),32);
    bufp->fullIData(oldp+932,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count),32);
    bufp->fullBit(oldp+933,((4U == vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__prod_count)));
    bufp->fullCData(oldp+934,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_state),2);
    bufp->fullIData(oldp+935,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_idx),32);
    bufp->fullBit(oldp+936,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc_valid_in));
    bufp->fullIData(oldp+937,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_result),32);
    bufp->fullBit(oldp+938,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__add_valid));
    bufp->fullBit(oldp+939,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__waiting));
    bufp->fullIData(oldp+940,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b),32);
    bufp->fullBit(oldp+941,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                             >> 0x1fU)));
    bufp->fullBit(oldp+942,((vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                             >> 0x1fU)));
    bufp->fullCData(oldp+943,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                        >> 0x17U))),8);
    bufp->fullCData(oldp+944,((0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+945,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)))),24);
    bufp->fullIData(oldp+946,(((0U == (0xffU & (vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b 
                                                >> 0x17U)))
                                ? (0x7fffffU & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)
                                : (0x800000U | (0x7fffffU 
                                                & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)))),24);
    bufp->fullBit(oldp+947,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc))))));
    bufp->fullBit(oldp+948,((IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b)) 
                                     & (0U != (0x7fffffU 
                                               & vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__b))))));
    bufp->fullBit(oldp+949,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_a));
    bufp->fullBit(oldp+950,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__inf_b));
    bufp->fullBit(oldp+951,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_a));
    bufp->fullBit(oldp+952,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__zero_b));
    bufp->fullBit(oldp+953,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_l));
    bufp->fullBit(oldp+954,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sign_s));
    bufp->fullCData(oldp+955,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_l),8);
    bufp->fullCData(oldp+956,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__exp_diff),8);
    bufp->fullIData(oldp+957,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_l_ext),25);
    bufp->fullIData(oldp+958,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_ext),25);
    bufp->fullIData(oldp+959,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sig_s_aligned),25);
    bufp->fullIData(oldp+960,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__sum),25);
    bufp->fullBit(oldp+961,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_sign));
    bufp->fullCData(oldp+962,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_exp),8);
    bufp->fullIData(oldp+963,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__result_man),23);
    bufp->fullCData(oldp+964,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__lz),5);
    bufp->fullIData(oldp+965,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__norm_sig),25);
    bufp->fullIData(oldp+966,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_add__DOT__add_result_comb),32);
    bufp->fullIData(oldp+967,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__u_mul__DOT__lut_result),32);
    bufp->fullIData(oldp+968,(vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+969,(vlSelfRef.clk));
    bufp->fullBit(oldp+970,(vlSelfRef.rst_n));
    bufp->fullCData(oldp+971,(vlSelfRef.a_in[0]),4);
    bufp->fullCData(oldp+972,(vlSelfRef.a_in[1]),4);
    bufp->fullCData(oldp+973,(vlSelfRef.a_in[2]),4);
    bufp->fullCData(oldp+974,(vlSelfRef.a_in[3]),4);
    bufp->fullCData(oldp+975,(vlSelfRef.b_in[0]),4);
    bufp->fullCData(oldp+976,(vlSelfRef.b_in[1]),4);
    bufp->fullCData(oldp+977,(vlSelfRef.b_in[2]),4);
    bufp->fullCData(oldp+978,(vlSelfRef.b_in[3]),4);
    bufp->fullBit(oldp+979,(vlSelfRef.valid_in));
    bufp->fullIData(oldp+980,(vlSelfRef.result[0U][0U]),32);
    bufp->fullIData(oldp+981,(vlSelfRef.result[0U][1U]),32);
    bufp->fullIData(oldp+982,(vlSelfRef.result[0U][2U]),32);
    bufp->fullIData(oldp+983,(vlSelfRef.result[0U][3U]),32);
    bufp->fullIData(oldp+984,(vlSelfRef.result[1U][0U]),32);
    bufp->fullIData(oldp+985,(vlSelfRef.result[1U][1U]),32);
    bufp->fullIData(oldp+986,(vlSelfRef.result[1U][2U]),32);
    bufp->fullIData(oldp+987,(vlSelfRef.result[1U][3U]),32);
    bufp->fullIData(oldp+988,(vlSelfRef.result[2U][0U]),32);
    bufp->fullIData(oldp+989,(vlSelfRef.result[2U][1U]),32);
    bufp->fullIData(oldp+990,(vlSelfRef.result[2U][2U]),32);
    bufp->fullIData(oldp+991,(vlSelfRef.result[2U][3U]),32);
    bufp->fullIData(oldp+992,(vlSelfRef.result[3U][0U]),32);
    bufp->fullIData(oldp+993,(vlSelfRef.result[3U][1U]),32);
    bufp->fullIData(oldp+994,(vlSelfRef.result[3U][2U]),32);
    bufp->fullIData(oldp+995,(vlSelfRef.result[3U][3U]),32);
    bufp->fullBit(oldp+996,(vlSelfRef.result_valid));
}
