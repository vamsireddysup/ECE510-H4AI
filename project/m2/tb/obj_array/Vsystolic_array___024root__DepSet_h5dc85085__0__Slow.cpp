// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array__Syms.h"
#include "Vsystolic_array___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__stl(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsystolic_array___024root___eval_triggers__stl(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_triggers__stl\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsystolic_array___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array___024root____Vm_traceActivitySetAll(Vsystolic_array___024root* vlSelf);
VL_ATTR_COLD void Vsystolic_array___024root___stl_sequent__TOP__0(Vsystolic_array___024root* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);

VL_ATTR_COLD void Vsystolic_array___024root___eval_stl(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_stl\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array___024root____Vm_traceActivitySetAll(vlSelf);
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array___024root___stl_sequent__TOP__0(vlSelf);
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
    }
}

VL_ATTR_COLD void Vsystolic_array___024root___stl_sequent__TOP__0(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___stl_sequent__TOP__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.systolic_array__DOT__a_in[0U] = vlSelfRef.a_in
        [0U];
    vlSelfRef.systolic_array__DOT__a_in[1U] = vlSelfRef.a_in
        [1U];
    vlSelfRef.systolic_array__DOT__a_in[2U] = vlSelfRef.a_in
        [2U];
    vlSelfRef.systolic_array__DOT__a_in[3U] = vlSelfRef.a_in
        [3U];
    vlSelfRef.systolic_array__DOT__b_in[0U] = vlSelfRef.b_in
        [0U];
    vlSelfRef.systolic_array__DOT__b_in[1U] = vlSelfRef.b_in
        [1U];
    vlSelfRef.systolic_array__DOT__b_in[2U] = vlSelfRef.b_in
        [2U];
    vlSelfRef.systolic_array__DOT__b_in[3U] = vlSelfRef.b_in
        [3U];
    vlSelfRef.systolic_array__DOT__pe_result_valid[0U][0U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[0U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[0U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[0U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[1U][0U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[1U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[1U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[1U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[2U][0U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[2U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[2U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[2U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[3U][0U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[3U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[3U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__pe_result_valid[3U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid;
    vlSelfRef.systolic_array__DOT__v_wire[0U][0U] = 
        vlSelfRef.systolic_array__DOT__v_stagger_a[0U]
        [0U];
    vlSelfRef.systolic_array__DOT__v_wire[1U][0U] = 
        vlSelfRef.systolic_array__DOT__v_stagger_a[1U]
        [1U];
    vlSelfRef.systolic_array__DOT__v_wire[2U][0U] = 
        vlSelfRef.systolic_array__DOT__v_stagger_a[2U]
        [2U];
    vlSelfRef.systolic_array__DOT__v_wire[3U][0U] = 
        vlSelfRef.systolic_array__DOT__v_stagger_a[3U]
        [3U];
    vlSelfRef.systolic_array__DOT__v_wire[0U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[0U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[0U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[0U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[1U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[1U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[1U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[1U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[2U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[2U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[2U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[2U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[3U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[3U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[3U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire[3U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__a_wire[0U][0U] = 
        vlSelfRef.systolic_array__DOT__a_stagger[0U]
        [0U];
    vlSelfRef.systolic_array__DOT__a_wire[1U][0U] = 
        vlSelfRef.systolic_array__DOT__a_stagger[1U]
        [1U];
    vlSelfRef.systolic_array__DOT__a_wire[2U][0U] = 
        vlSelfRef.systolic_array__DOT__a_stagger[2U]
        [2U];
    vlSelfRef.systolic_array__DOT__a_wire[3U][0U] = 
        vlSelfRef.systolic_array__DOT__a_stagger[3U]
        [3U];
    vlSelfRef.systolic_array__DOT__b_wire[0U][0U] = 
        vlSelfRef.systolic_array__DOT__b_stagger[0U]
        [0U];
    vlSelfRef.systolic_array__DOT__b_wire[0U][1U] = 
        vlSelfRef.systolic_array__DOT__b_stagger[1U]
        [1U];
    vlSelfRef.systolic_array__DOT__b_wire[0U][2U] = 
        vlSelfRef.systolic_array__DOT__b_stagger[2U]
        [2U];
    vlSelfRef.systolic_array__DOT__b_wire[0U][3U] = 
        vlSelfRef.systolic_array__DOT__b_stagger[3U]
        [3U];
    vlSelfRef.systolic_array__DOT__b_wire[1U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[0U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[1U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[0U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[1U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[0U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[1U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[0U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[2U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[1U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[2U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[1U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[2U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[1U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[2U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[1U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[3U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[2U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[3U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[2U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[3U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[2U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[3U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[2U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[4U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[3U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[4U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[3U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[4U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[3U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[4U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__a_wire[3U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out;
    vlSelfRef.result[0U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[0U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[0U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[0U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[1U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[1U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[1U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[1U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[2U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[2U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[2U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[2U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[3U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[3U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[3U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result[3U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.result_valid = vlSelfRef.systolic_array__DOT__pe_result_valid
        [3U][3U];
    vlSelfRef.systolic_array__DOT__result[0U][0U] = 
        vlSelfRef.result[0U][0U];
    vlSelfRef.systolic_array__DOT__result[0U][1U] = 
        vlSelfRef.result[0U][1U];
    vlSelfRef.systolic_array__DOT__result[0U][2U] = 
        vlSelfRef.result[0U][2U];
    vlSelfRef.systolic_array__DOT__result[0U][3U] = 
        vlSelfRef.result[0U][3U];
    vlSelfRef.systolic_array__DOT__result[1U][0U] = 
        vlSelfRef.result[1U][0U];
    vlSelfRef.systolic_array__DOT__result[1U][1U] = 
        vlSelfRef.result[1U][1U];
    vlSelfRef.systolic_array__DOT__result[1U][2U] = 
        vlSelfRef.result[1U][2U];
    vlSelfRef.systolic_array__DOT__result[1U][3U] = 
        vlSelfRef.result[1U][3U];
    vlSelfRef.systolic_array__DOT__result[2U][0U] = 
        vlSelfRef.result[2U][0U];
    vlSelfRef.systolic_array__DOT__result[2U][1U] = 
        vlSelfRef.result[2U][1U];
    vlSelfRef.systolic_array__DOT__result[2U][2U] = 
        vlSelfRef.result[2U][2U];
    vlSelfRef.systolic_array__DOT__result[2U][3U] = 
        vlSelfRef.result[2U][3U];
    vlSelfRef.systolic_array__DOT__result[3U][0U] = 
        vlSelfRef.result[3U][0U];
    vlSelfRef.systolic_array__DOT__result[3U][1U] = 
        vlSelfRef.result[3U][1U];
    vlSelfRef.systolic_array__DOT__result[3U][2U] = 
        vlSelfRef.result[3U][2U];
    vlSelfRef.systolic_array__DOT__result[3U][3U] = 
        vlSelfRef.result[3U][3U];
}
