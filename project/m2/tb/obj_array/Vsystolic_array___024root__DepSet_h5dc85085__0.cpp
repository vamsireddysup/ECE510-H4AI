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

void Vsystolic_array___024root___nba_sequent__TOP__0(Vsystolic_array___024root* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf);
void Vsystolic_array___024root___nba_sequent__TOP__1(Vsystolic_array___024root* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);
void Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf);

void Vsystolic_array___024root___eval_nba(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___eval_nba\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsystolic_array___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__0((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array___024root___nba_sequent__TOP__1(vlSelf);
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe));
        Vsystolic_array_pe___nba_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1((&vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe));
    }
}

VL_INLINE_OPT void Vsystolic_array___024root___nba_sequent__TOP__1(Vsystolic_array___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array___024root___nba_sequent__TOP__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.systolic_array__DOT__pe_result_valid[3U][3U] 
        = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.result_valid;
    vlSelfRef.result[3U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.__PVT__acc;
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
    vlSelfRef.systolic_array__DOT__a_wire[3U][4U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.a_out;
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
    vlSelfRef.systolic_array__DOT__b_wire[4U][3U] = vlSymsp->TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe.b_out;
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
