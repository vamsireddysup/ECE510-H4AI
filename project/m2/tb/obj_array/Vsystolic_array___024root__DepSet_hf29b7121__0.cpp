// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array___024root.h"

void Vsystolic_array___024root___ico_sequent__TOP__0(Vsystolic_array___024root* vlSelf);

void Vsystolic_array___024root___eval_ico(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_ico\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vsystolic_array___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vsystolic_array___024root___ico_sequent__TOP__0(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___ico_sequent__TOP__0\n"); );
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
}

void Vsystolic_array___024root___eval_triggers__ico(Vsystolic_array___024root* vlSelf);

bool Vsystolic_array___024root___eval_phase__ico(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_phase__ico\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vsystolic_array___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vsystolic_array___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vsystolic_array___024root___eval_act(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_act\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_INLINE_OPT void Vsystolic_array___024root___nba_sequent__TOP__0(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___nba_sequent__TOP__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v0;
    __VdlyVal__systolic_array__DOT__a_stagger__v0 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v1;
    __VdlyVal__systolic_array__DOT__a_stagger__v1 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v2;
    __VdlyVal__systolic_array__DOT__a_stagger__v2 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v3;
    __VdlyVal__systolic_array__DOT__a_stagger__v3 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v4;
    __VdlyVal__systolic_array__DOT__a_stagger__v4 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v5;
    __VdlyVal__systolic_array__DOT__a_stagger__v5 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v6;
    __VdlyVal__systolic_array__DOT__a_stagger__v6 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v7;
    __VdlyVal__systolic_array__DOT__a_stagger__v7 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v8;
    __VdlyVal__systolic_array__DOT__a_stagger__v8 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v9;
    __VdlyVal__systolic_array__DOT__a_stagger__v9 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v10;
    __VdlyVal__systolic_array__DOT__a_stagger__v10 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v11;
    __VdlyVal__systolic_array__DOT__a_stagger__v11 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v12;
    __VdlyVal__systolic_array__DOT__a_stagger__v12 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v13;
    __VdlyVal__systolic_array__DOT__a_stagger__v13 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v14;
    __VdlyVal__systolic_array__DOT__a_stagger__v14 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v15;
    __VdlyVal__systolic_array__DOT__a_stagger__v15 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v0;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v0 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v1;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v1 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v2;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v2 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v3;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v3 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v4;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v4 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v5;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v5 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v6;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v6 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v7;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v7 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v8;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v8 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v9;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v9 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v10;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v10 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v11;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v11 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v12;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v12 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v13;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v13 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v14;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v14 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_a__v15;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v15 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v0;
    __VdlyVal__systolic_array__DOT__b_stagger__v0 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v1;
    __VdlyVal__systolic_array__DOT__b_stagger__v1 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v2;
    __VdlyVal__systolic_array__DOT__b_stagger__v2 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v3;
    __VdlyVal__systolic_array__DOT__b_stagger__v3 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v4;
    __VdlyVal__systolic_array__DOT__b_stagger__v4 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v5;
    __VdlyVal__systolic_array__DOT__b_stagger__v5 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v6;
    __VdlyVal__systolic_array__DOT__b_stagger__v6 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v7;
    __VdlyVal__systolic_array__DOT__b_stagger__v7 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v8;
    __VdlyVal__systolic_array__DOT__b_stagger__v8 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v9;
    __VdlyVal__systolic_array__DOT__b_stagger__v9 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v10;
    __VdlyVal__systolic_array__DOT__b_stagger__v10 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v11;
    __VdlyVal__systolic_array__DOT__b_stagger__v11 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v12;
    __VdlyVal__systolic_array__DOT__b_stagger__v12 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v13;
    __VdlyVal__systolic_array__DOT__b_stagger__v13 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v14;
    __VdlyVal__systolic_array__DOT__b_stagger__v14 = 0;
    IData/*31:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v15;
    __VdlyVal__systolic_array__DOT__b_stagger__v15 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v0;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v0 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v1;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v1 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v2;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v2 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v3;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v3 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v4;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v4 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v5;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v5 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v6;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v6 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v7;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v7 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v8;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v8 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v9;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v9 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v10;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v10 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v11;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v11 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v12;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v12 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v13;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v13 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v14;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v14 = 0;
    CData/*0:0*/ __VdlyVal__systolic_array__DOT__v_stagger_b__v15;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v15 = 0;
    // Body
    vlSelfRef.systolic_array__DOT__unnamedblk1__DOT__unnamedblk2__DOT__d = 4U;
    vlSelfRef.systolic_array__DOT__unnamedblk1__DOT__i = 4U;
    vlSelfRef.systolic_array__DOT__unnamedblk3__DOT__unnamedblk4__DOT__d = 4U;
    vlSelfRef.systolic_array__DOT__unnamedblk3__DOT__j = 4U;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v0 
        = vlSelfRef.valid_in;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v1 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [0U][0U];
    __VdlyVal__systolic_array__DOT__v_stagger_b__v2 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [0U][1U];
    __VdlyVal__systolic_array__DOT__v_stagger_b__v3 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [0U][2U];
    __VdlyVal__systolic_array__DOT__v_stagger_b__v4 
        = vlSelfRef.valid_in;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v5 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [1U][0U];
    __VdlyVal__systolic_array__DOT__v_stagger_b__v6 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [1U][1U];
    __VdlyVal__systolic_array__DOT__v_stagger_b__v7 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [1U][2U];
    __VdlyVal__systolic_array__DOT__v_stagger_b__v8 
        = vlSelfRef.valid_in;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v9 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [2U][0U];
    __VdlyVal__systolic_array__DOT__v_stagger_b__v10 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [2U][1U];
    __VdlyVal__systolic_array__DOT__v_stagger_b__v11 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [2U][2U];
    __VdlyVal__systolic_array__DOT__v_stagger_b__v12 
        = vlSelfRef.valid_in;
    __VdlyVal__systolic_array__DOT__v_stagger_b__v13 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [3U][0U];
    __VdlyVal__systolic_array__DOT__v_stagger_b__v14 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [3U][1U];
    __VdlyVal__systolic_array__DOT__v_stagger_b__v15 
        = vlSelfRef.systolic_array__DOT__v_stagger_b
        [3U][2U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v0 
        = vlSelfRef.valid_in;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v1 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [0U][0U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v2 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [0U][1U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v3 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [0U][2U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v4 
        = vlSelfRef.valid_in;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v5 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [1U][0U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v6 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [1U][1U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v7 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [1U][2U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v8 
        = vlSelfRef.valid_in;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v9 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [2U][0U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v10 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [2U][1U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v11 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [2U][2U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v12 
        = vlSelfRef.valid_in;
    __VdlyVal__systolic_array__DOT__v_stagger_a__v13 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [3U][0U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v14 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [3U][1U];
    __VdlyVal__systolic_array__DOT__v_stagger_a__v15 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [3U][2U];
    __VdlyVal__systolic_array__DOT__a_stagger__v0 = 
        vlSelfRef.a_in[0U];
    __VdlyVal__systolic_array__DOT__a_stagger__v1 = 
        vlSelfRef.systolic_array__DOT__a_stagger[0U]
        [0U];
    __VdlyVal__systolic_array__DOT__a_stagger__v2 = 
        vlSelfRef.systolic_array__DOT__a_stagger[0U]
        [1U];
    __VdlyVal__systolic_array__DOT__a_stagger__v3 = 
        vlSelfRef.systolic_array__DOT__a_stagger[0U]
        [2U];
    __VdlyVal__systolic_array__DOT__a_stagger__v4 = 
        vlSelfRef.a_in[1U];
    __VdlyVal__systolic_array__DOT__a_stagger__v5 = 
        vlSelfRef.systolic_array__DOT__a_stagger[1U]
        [0U];
    __VdlyVal__systolic_array__DOT__a_stagger__v6 = 
        vlSelfRef.systolic_array__DOT__a_stagger[1U]
        [1U];
    __VdlyVal__systolic_array__DOT__a_stagger__v7 = 
        vlSelfRef.systolic_array__DOT__a_stagger[1U]
        [2U];
    __VdlyVal__systolic_array__DOT__a_stagger__v8 = 
        vlSelfRef.a_in[2U];
    __VdlyVal__systolic_array__DOT__a_stagger__v9 = 
        vlSelfRef.systolic_array__DOT__a_stagger[2U]
        [0U];
    __VdlyVal__systolic_array__DOT__a_stagger__v10 
        = vlSelfRef.systolic_array__DOT__a_stagger[2U]
        [1U];
    __VdlyVal__systolic_array__DOT__a_stagger__v11 
        = vlSelfRef.systolic_array__DOT__a_stagger[2U]
        [2U];
    __VdlyVal__systolic_array__DOT__a_stagger__v12 
        = vlSelfRef.a_in[3U];
    __VdlyVal__systolic_array__DOT__a_stagger__v13 
        = vlSelfRef.systolic_array__DOT__a_stagger[3U]
        [0U];
    __VdlyVal__systolic_array__DOT__a_stagger__v14 
        = vlSelfRef.systolic_array__DOT__a_stagger[3U]
        [1U];
    __VdlyVal__systolic_array__DOT__a_stagger__v15 
        = vlSelfRef.systolic_array__DOT__a_stagger[3U]
        [2U];
    __VdlyVal__systolic_array__DOT__b_stagger__v0 = 
        vlSelfRef.b_in[0U];
    __VdlyVal__systolic_array__DOT__b_stagger__v1 = 
        vlSelfRef.systolic_array__DOT__b_stagger[0U]
        [0U];
    __VdlyVal__systolic_array__DOT__b_stagger__v2 = 
        vlSelfRef.systolic_array__DOT__b_stagger[0U]
        [1U];
    __VdlyVal__systolic_array__DOT__b_stagger__v3 = 
        vlSelfRef.systolic_array__DOT__b_stagger[0U]
        [2U];
    __VdlyVal__systolic_array__DOT__b_stagger__v4 = 
        vlSelfRef.b_in[1U];
    __VdlyVal__systolic_array__DOT__b_stagger__v5 = 
        vlSelfRef.systolic_array__DOT__b_stagger[1U]
        [0U];
    __VdlyVal__systolic_array__DOT__b_stagger__v6 = 
        vlSelfRef.systolic_array__DOT__b_stagger[1U]
        [1U];
    __VdlyVal__systolic_array__DOT__b_stagger__v7 = 
        vlSelfRef.systolic_array__DOT__b_stagger[1U]
        [2U];
    __VdlyVal__systolic_array__DOT__b_stagger__v8 = 
        vlSelfRef.b_in[2U];
    __VdlyVal__systolic_array__DOT__b_stagger__v9 = 
        vlSelfRef.systolic_array__DOT__b_stagger[2U]
        [0U];
    __VdlyVal__systolic_array__DOT__b_stagger__v10 
        = vlSelfRef.systolic_array__DOT__b_stagger[2U]
        [1U];
    __VdlyVal__systolic_array__DOT__b_stagger__v11 
        = vlSelfRef.systolic_array__DOT__b_stagger[2U]
        [2U];
    __VdlyVal__systolic_array__DOT__b_stagger__v12 
        = vlSelfRef.b_in[3U];
    __VdlyVal__systolic_array__DOT__b_stagger__v13 
        = vlSelfRef.systolic_array__DOT__b_stagger[3U]
        [0U];
    __VdlyVal__systolic_array__DOT__b_stagger__v14 
        = vlSelfRef.systolic_array__DOT__b_stagger[3U]
        [1U];
    __VdlyVal__systolic_array__DOT__b_stagger__v15 
        = vlSelfRef.systolic_array__DOT__b_stagger[3U]
        [2U];
    vlSelfRef.systolic_array__DOT__v_stagger_b[0U][0U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v0;
    vlSelfRef.systolic_array__DOT__v_stagger_b[0U][1U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v1;
    vlSelfRef.systolic_array__DOT__v_stagger_b[0U][2U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v2;
    vlSelfRef.systolic_array__DOT__v_stagger_b[0U][3U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v3;
    vlSelfRef.systolic_array__DOT__v_stagger_b[1U][0U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v4;
    vlSelfRef.systolic_array__DOT__v_stagger_b[1U][1U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v5;
    vlSelfRef.systolic_array__DOT__v_stagger_b[1U][2U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v6;
    vlSelfRef.systolic_array__DOT__v_stagger_b[1U][3U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v7;
    vlSelfRef.systolic_array__DOT__v_stagger_b[2U][0U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v8;
    vlSelfRef.systolic_array__DOT__v_stagger_b[2U][1U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v9;
    vlSelfRef.systolic_array__DOT__v_stagger_b[2U][2U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v10;
    vlSelfRef.systolic_array__DOT__v_stagger_b[2U][3U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v11;
    vlSelfRef.systolic_array__DOT__v_stagger_b[3U][0U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v12;
    vlSelfRef.systolic_array__DOT__v_stagger_b[3U][1U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v13;
    vlSelfRef.systolic_array__DOT__v_stagger_b[3U][2U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v14;
    vlSelfRef.systolic_array__DOT__v_stagger_b[3U][3U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_b__v15;
    vlSelfRef.systolic_array__DOT__v_stagger_a[0U][0U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v0;
    vlSelfRef.systolic_array__DOT__v_stagger_a[0U][1U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v1;
    vlSelfRef.systolic_array__DOT__v_stagger_a[0U][2U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v2;
    vlSelfRef.systolic_array__DOT__v_stagger_a[0U][3U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v3;
    vlSelfRef.systolic_array__DOT__v_stagger_a[1U][0U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v4;
    vlSelfRef.systolic_array__DOT__v_stagger_a[1U][1U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v5;
    vlSelfRef.systolic_array__DOT__v_stagger_a[1U][2U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v6;
    vlSelfRef.systolic_array__DOT__v_stagger_a[1U][3U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v7;
    vlSelfRef.systolic_array__DOT__v_stagger_a[2U][0U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v8;
    vlSelfRef.systolic_array__DOT__v_stagger_a[2U][1U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v9;
    vlSelfRef.systolic_array__DOT__v_stagger_a[2U][2U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v10;
    vlSelfRef.systolic_array__DOT__v_stagger_a[2U][3U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v11;
    vlSelfRef.systolic_array__DOT__v_stagger_a[3U][0U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v12;
    vlSelfRef.systolic_array__DOT__v_stagger_a[3U][1U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v13;
    vlSelfRef.systolic_array__DOT__v_stagger_a[3U][2U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v14;
    vlSelfRef.systolic_array__DOT__v_stagger_a[3U][3U] 
        = __VdlyVal__systolic_array__DOT__v_stagger_a__v15;
    vlSelfRef.systolic_array__DOT__a_stagger[0U][0U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v0;
    vlSelfRef.systolic_array__DOT__a_stagger[0U][1U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v1;
    vlSelfRef.systolic_array__DOT__a_stagger[0U][2U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v2;
    vlSelfRef.systolic_array__DOT__a_stagger[0U][3U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v3;
    vlSelfRef.systolic_array__DOT__a_stagger[1U][0U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v4;
    vlSelfRef.systolic_array__DOT__a_stagger[1U][1U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v5;
    vlSelfRef.systolic_array__DOT__a_stagger[1U][2U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v6;
    vlSelfRef.systolic_array__DOT__a_stagger[1U][3U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v7;
    vlSelfRef.systolic_array__DOT__a_stagger[2U][0U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v8;
    vlSelfRef.systolic_array__DOT__a_stagger[2U][1U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v9;
    vlSelfRef.systolic_array__DOT__a_stagger[2U][2U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v10;
    vlSelfRef.systolic_array__DOT__a_stagger[2U][3U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v11;
    vlSelfRef.systolic_array__DOT__a_stagger[3U][0U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v12;
    vlSelfRef.systolic_array__DOT__a_stagger[3U][1U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v13;
    vlSelfRef.systolic_array__DOT__a_stagger[3U][2U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v14;
    vlSelfRef.systolic_array__DOT__a_stagger[3U][3U] 
        = __VdlyVal__systolic_array__DOT__a_stagger__v15;
    vlSelfRef.systolic_array__DOT__b_stagger[0U][0U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v0;
    vlSelfRef.systolic_array__DOT__b_stagger[0U][1U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v1;
    vlSelfRef.systolic_array__DOT__b_stagger[0U][2U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v2;
    vlSelfRef.systolic_array__DOT__b_stagger[0U][3U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v3;
    vlSelfRef.systolic_array__DOT__b_stagger[1U][0U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v4;
    vlSelfRef.systolic_array__DOT__b_stagger[1U][1U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v5;
    vlSelfRef.systolic_array__DOT__b_stagger[1U][2U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v6;
    vlSelfRef.systolic_array__DOT__b_stagger[1U][3U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v7;
    vlSelfRef.systolic_array__DOT__b_stagger[2U][0U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v8;
    vlSelfRef.systolic_array__DOT__b_stagger[2U][1U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v9;
    vlSelfRef.systolic_array__DOT__b_stagger[2U][2U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v10;
    vlSelfRef.systolic_array__DOT__b_stagger[2U][3U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v11;
    vlSelfRef.systolic_array__DOT__b_stagger[3U][0U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v12;
    vlSelfRef.systolic_array__DOT__b_stagger[3U][1U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v13;
    vlSelfRef.systolic_array__DOT__b_stagger[3U][2U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v14;
    vlSelfRef.systolic_array__DOT__b_stagger[3U][3U] 
        = __VdlyVal__systolic_array__DOT__b_stagger__v15;
}

void Vsystolic_array___024root___eval_triggers__act(Vsystolic_array___024root* vlSelf);

bool Vsystolic_array___024root___eval_phase__act(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_phase__act\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsystolic_array___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsystolic_array___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vsystolic_array___024root___eval_nba(Vsystolic_array___024root* vlSelf);

bool Vsystolic_array___024root___eval_phase__nba(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_phase__nba\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsystolic_array___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__ico(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__nba(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__act(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG

void Vsystolic_array___024root___eval(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vsystolic_array___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../rtl/systolic_array.sv", 29, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vsystolic_array___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsystolic_array___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/systolic_array.sv", 29, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsystolic_array___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/systolic_array.sv", 29, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsystolic_array___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsystolic_array___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsystolic_array___024root___eval_debug_assertions(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_debug_assertions\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.valid_in & 0xfeU)))) {
        Verilated::overWidthError("valid_in");}
}
#endif  // VL_DEBUG
