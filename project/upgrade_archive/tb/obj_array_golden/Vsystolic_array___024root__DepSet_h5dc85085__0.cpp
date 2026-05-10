// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array__Syms.h"
#include "Vsystolic_array___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__ico(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG

void Vsystolic_array___024root___eval_triggers__ico(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_triggers__ico\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsystolic_array___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array___024root___dump_triggers__act(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG

void Vsystolic_array___024root___eval_triggers__act(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_triggers__act\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsystolic_array___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array___024root___nba_sequent__TOP__0(Vsystolic_array___024root* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);
void Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe__D4* vlSelf);

void Vsystolic_array___024root___eval_nba(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_nba\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array___024root___nba_sequent__TOP__0(vlSelf);
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe__D4___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
    }
}

VL_INLINE_OPT void Vsystolic_array___024root___nba_sequent__TOP__0(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___nba_sequent__TOP__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v0;
    __VdlyVal__systolic_array__DOT__a_stagger__v0 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v1;
    __VdlyVal__systolic_array__DOT__a_stagger__v1 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v2;
    __VdlyVal__systolic_array__DOT__a_stagger__v2 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v3;
    __VdlyVal__systolic_array__DOT__a_stagger__v3 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v4;
    __VdlyVal__systolic_array__DOT__a_stagger__v4 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v5;
    __VdlyVal__systolic_array__DOT__a_stagger__v5 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v6;
    __VdlyVal__systolic_array__DOT__a_stagger__v6 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v7;
    __VdlyVal__systolic_array__DOT__a_stagger__v7 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v8;
    __VdlyVal__systolic_array__DOT__a_stagger__v8 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v9;
    __VdlyVal__systolic_array__DOT__a_stagger__v9 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v10;
    __VdlyVal__systolic_array__DOT__a_stagger__v10 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v11;
    __VdlyVal__systolic_array__DOT__a_stagger__v11 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v12;
    __VdlyVal__systolic_array__DOT__a_stagger__v12 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v13;
    __VdlyVal__systolic_array__DOT__a_stagger__v13 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v14;
    __VdlyVal__systolic_array__DOT__a_stagger__v14 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__a_stagger__v15;
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
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v0;
    __VdlyVal__systolic_array__DOT__b_stagger__v0 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v1;
    __VdlyVal__systolic_array__DOT__b_stagger__v1 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v2;
    __VdlyVal__systolic_array__DOT__b_stagger__v2 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v3;
    __VdlyVal__systolic_array__DOT__b_stagger__v3 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v4;
    __VdlyVal__systolic_array__DOT__b_stagger__v4 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v5;
    __VdlyVal__systolic_array__DOT__b_stagger__v5 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v6;
    __VdlyVal__systolic_array__DOT__b_stagger__v6 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v7;
    __VdlyVal__systolic_array__DOT__b_stagger__v7 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v8;
    __VdlyVal__systolic_array__DOT__b_stagger__v8 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v9;
    __VdlyVal__systolic_array__DOT__b_stagger__v9 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v10;
    __VdlyVal__systolic_array__DOT__b_stagger__v10 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v11;
    __VdlyVal__systolic_array__DOT__b_stagger__v11 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v12;
    __VdlyVal__systolic_array__DOT__b_stagger__v12 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v13;
    __VdlyVal__systolic_array__DOT__b_stagger__v13 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v14;
    __VdlyVal__systolic_array__DOT__b_stagger__v14 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array__DOT__b_stagger__v15;
    __VdlyVal__systolic_array__DOT__b_stagger__v15 = 0;
    // Body
    vlSelfRef.systolic_array__DOT__unnamedblk1__DOT__unnamedblk2__DOT__d = 4U;
    vlSelfRef.systolic_array__DOT__unnamedblk1__DOT__i = 4U;
    vlSelfRef.systolic_array__DOT__unnamedblk3__DOT__unnamedblk4__DOT__d = 4U;
    vlSelfRef.systolic_array__DOT__unnamedblk3__DOT__j = 4U;
    vlSelfRef.systolic_array__DOT__pe_result_valid[0U][0U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[0U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[0U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[0U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[0U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[0U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[0U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[0U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[1U][0U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[1U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[1U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[1U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[1U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[1U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[1U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[1U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[2U][0U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[2U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[2U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[2U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[2U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[2U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[2U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[2U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[3U][0U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[3U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[3U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[3U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__pe_result_valid[3U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[3U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__a_wire[0U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[0U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[0U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[0U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[1U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[1U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[1U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[1U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[2U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[2U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[2U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[2U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[3U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[3U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__a_wire[3U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[1U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[1U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[1U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[1U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[2U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[2U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[2U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[2U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[3U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[3U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[3U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[3U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[4U][0U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[4U][1U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__b_wire[4U][2U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__pe_result_valid[3U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[3U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc;
    vlSelfRef.systolic_array__DOT__a_wire[3U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out;
    vlSelfRef.systolic_array__DOT__b_wire[4U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[0U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[0U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[0U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[0U][4U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[1U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[1U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[1U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[1U][4U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[2U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[2U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[2U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[2U][4U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[3U][1U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[3U][2U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[3U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe.valid_out;
    vlSelfRef.systolic_array__DOT__v_wire_a[3U][4U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.valid_out;
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
    vlSelfRef.systolic_array__DOT__v_wire_a[0U][0U] 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [0U][0U];
    vlSelfRef.systolic_array__DOT__v_wire_a[1U][0U] 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [1U][1U];
    vlSelfRef.systolic_array__DOT__v_wire_a[2U][0U] 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [2U][2U];
    vlSelfRef.systolic_array__DOT__v_wire_a[3U][0U] 
        = vlSelfRef.systolic_array__DOT__v_stagger_a
        [3U][3U];
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
}
