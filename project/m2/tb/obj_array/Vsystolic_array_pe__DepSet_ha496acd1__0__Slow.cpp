// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array__Syms.h"
#include "Vsystolic_array_pe.h"

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [0U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [0U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [0U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [0U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][0U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [0U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [0U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [0U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [0U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][1U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [0U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [0U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [0U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [0U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][2U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [0U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [0U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [0U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [0U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [0U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [0U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [0U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [0U][3U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [1U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [1U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [1U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [1U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][0U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [1U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [1U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [1U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [1U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][1U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [1U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [1U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [1U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [1U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][2U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [1U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [1U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [1U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [1U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [1U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [1U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [1U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [1U][3U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [2U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [2U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [2U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [2U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][0U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [2U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [2U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [2U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [2U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][1U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [2U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [2U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [2U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [2U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][2U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [2U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [2U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [2U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [2U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [2U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [2U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [2U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [2U][3U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [3U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [3U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [3U]
                                                      [0U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [3U]
                                               [0U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][0U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][0U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][0U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][0U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [3U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [3U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [3U]
                                                      [1U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [3U]
                                               [1U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][1U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][1U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][1U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][1U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [3U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [3U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [3U]
                                                      [2U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [3U]
                                               [2U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][2U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][2U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][2U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][2U])));
}

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe__1\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_mul__DOT__zero_b = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__b_wire
                                                      [3U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__b_wire
                                               [3U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_b = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__b_wire
                                             [3U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__b_wire
                                              [3U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__zero_a = ((0U == (0xffU 
                                                   & (vlSymsp->TOP.systolic_array__DOT__a_wire
                                                      [3U]
                                                      [3U] 
                                                      >> 0x17U))) 
                                           & (0U == 
                                              (0x7fffffU 
                                               & vlSymsp->TOP.systolic_array__DOT__a_wire
                                               [3U]
                                               [3U])));
    vlSelfRef.__PVT__u_mul__DOT__inf_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][3U] 
                                             >> 0x17U))) 
                                          & (0U == 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][3U])));
    vlSelfRef.__PVT__u_mul__DOT__nan_a = ((0xffU == 
                                           (0xffU & 
                                            (vlSymsp->TOP.systolic_array__DOT__a_wire
                                             [3U][3U] 
                                             >> 0x17U))) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSymsp->TOP.systolic_array__DOT__a_wire
                                              [3U][3U])));
}
