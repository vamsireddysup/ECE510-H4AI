// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtile_controller.h for the primary calling header

#include "Vtile_controller__pch.h"
#include "Vtile_controller___024root.h"

void Vtile_controller___024root___ico_sequent__TOP__0(Vtile_controller___024root* vlSelf);

void Vtile_controller___024root___eval_ico(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_ico\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtile_controller___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vtile_controller___024root___ico_sequent__TOP__0(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___ico_sequent__TOP__0\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tile_controller__DOT__arr_result[0U][0U] 
        = vlSelfRef.arr_result[0U][0U];
    vlSelfRef.tile_controller__DOT__arr_result[0U][1U] 
        = vlSelfRef.arr_result[0U][1U];
    vlSelfRef.tile_controller__DOT__arr_result[0U][2U] 
        = vlSelfRef.arr_result[0U][2U];
    vlSelfRef.tile_controller__DOT__arr_result[0U][3U] 
        = vlSelfRef.arr_result[0U][3U];
    vlSelfRef.tile_controller__DOT__arr_result[1U][0U] 
        = vlSelfRef.arr_result[1U][0U];
    vlSelfRef.tile_controller__DOT__arr_result[1U][1U] 
        = vlSelfRef.arr_result[1U][1U];
    vlSelfRef.tile_controller__DOT__arr_result[1U][2U] 
        = vlSelfRef.arr_result[1U][2U];
    vlSelfRef.tile_controller__DOT__arr_result[1U][3U] 
        = vlSelfRef.arr_result[1U][3U];
    vlSelfRef.tile_controller__DOT__arr_result[2U][0U] 
        = vlSelfRef.arr_result[2U][0U];
    vlSelfRef.tile_controller__DOT__arr_result[2U][1U] 
        = vlSelfRef.arr_result[2U][1U];
    vlSelfRef.tile_controller__DOT__arr_result[2U][2U] 
        = vlSelfRef.arr_result[2U][2U];
    vlSelfRef.tile_controller__DOT__arr_result[2U][3U] 
        = vlSelfRef.arr_result[2U][3U];
    vlSelfRef.tile_controller__DOT__arr_result[3U][0U] 
        = vlSelfRef.arr_result[3U][0U];
    vlSelfRef.tile_controller__DOT__arr_result[3U][1U] 
        = vlSelfRef.arr_result[3U][1U];
    vlSelfRef.tile_controller__DOT__arr_result[3U][2U] 
        = vlSelfRef.arr_result[3U][2U];
    vlSelfRef.tile_controller__DOT__arr_result[3U][3U] 
        = vlSelfRef.arr_result[3U][3U];
    vlSelfRef.arr_a_in[0U] = 0U;
    vlSelfRef.arr_a_in[1U] = 0U;
    vlSelfRef.arr_a_in[2U] = 0U;
    vlSelfRef.arr_a_in[3U] = 0U;
    vlSelfRef.arr_b_in[0U] = 0U;
    vlSelfRef.arr_b_in[1U] = 0U;
    vlSelfRef.arr_b_in[2U] = 0U;
    vlSelfRef.arr_b_in[3U] = 0U;
    if ((4U == (IData)(vlSelfRef.tile_controller__DOT__state))) {
        vlSelfRef.arr_a_in[0U] = vlSelfRef.q_rd_data;
        vlSelfRef.arr_a_in[1U] = vlSelfRef.q_rd_data;
        vlSelfRef.arr_a_in[2U] = vlSelfRef.q_rd_data;
        vlSelfRef.arr_a_in[3U] = vlSelfRef.q_rd_data;
        vlSelfRef.arr_b_in[0U] = vlSelfRef.k_rd_data;
        vlSelfRef.arr_b_in[1U] = vlSelfRef.k_rd_data;
        vlSelfRef.arr_b_in[2U] = vlSelfRef.k_rd_data;
        vlSelfRef.arr_b_in[3U] = vlSelfRef.k_rd_data;
    }
    vlSelfRef.tile_controller__DOT__arr_a_in[0U] = 
        vlSelfRef.arr_a_in[0U];
    vlSelfRef.tile_controller__DOT__arr_a_in[1U] = 
        vlSelfRef.arr_a_in[1U];
    vlSelfRef.tile_controller__DOT__arr_a_in[2U] = 
        vlSelfRef.arr_a_in[2U];
    vlSelfRef.tile_controller__DOT__arr_a_in[3U] = 
        vlSelfRef.arr_a_in[3U];
    vlSelfRef.tile_controller__DOT__arr_b_in[0U] = 
        vlSelfRef.arr_b_in[0U];
    vlSelfRef.tile_controller__DOT__arr_b_in[1U] = 
        vlSelfRef.arr_b_in[1U];
    vlSelfRef.tile_controller__DOT__arr_b_in[2U] = 
        vlSelfRef.arr_b_in[2U];
    vlSelfRef.tile_controller__DOT__arr_b_in[3U] = 
        vlSelfRef.arr_b_in[3U];
}

void Vtile_controller___024root___eval_triggers__ico(Vtile_controller___024root* vlSelf);

bool Vtile_controller___024root___eval_phase__ico(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_phase__ico\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtile_controller___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtile_controller___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtile_controller___024root___eval_act(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_act\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtile_controller___024root___nba_sequent__TOP__0(Vtile_controller___024root* vlSelf);

void Vtile_controller___024root___eval_nba(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_nba\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtile_controller___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

VL_INLINE_OPT void Vtile_controller___024root___nba_sequent__TOP__0(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___nba_sequent__TOP__0\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__cycle_count;
    __Vdly__cycle_count = 0;
    CData/*0:0*/ __Vdly__s_tready;
    __Vdly__s_tready = 0;
    CData/*0:0*/ __Vdly__m_tvalid;
    __Vdly__m_tvalid = 0;
    CData/*3:0*/ __Vdly__tile_controller__DOT__state;
    __Vdly__tile_controller__DOT__state = 0;
    IData/*31:0*/ __Vdly__tile_controller__DOT__tile_start_cycle;
    __Vdly__tile_controller__DOT__tile_start_cycle = 0;
    CData/*3:0*/ __Vdly__tile_controller__DOT__tile_col;
    __Vdly__tile_controller__DOT__tile_col = 0;
    IData/*31:0*/ __Vdly__tile_controller__DOT__load_count;
    __Vdly__tile_controller__DOT__load_count = 0;
    IData/*31:0*/ __Vdly__tile_controller__DOT__send_count;
    __Vdly__tile_controller__DOT__send_count = 0;
    IData/*31:0*/ __Vdly__tile_controller__DOT__deq_col;
    __Vdly__tile_controller__DOT__deq_col = 0;
    IData/*31:0*/ __Vdly__tile_controller__DOT__cap_col;
    __Vdly__tile_controller__DOT__cap_col = 0;
    IData/*31:0*/ __Vdly__tile_controller__DOT__d_counter;
    __Vdly__tile_controller__DOT__d_counter = 0;
    // Body
    __Vdly__cycle_count = vlSelfRef.cycle_count;
    __Vdly__s_tready = vlSelfRef.s_tready;
    __Vdly__m_tvalid = vlSelfRef.m_tvalid;
    __Vdly__tile_controller__DOT__tile_start_cycle 
        = vlSelfRef.tile_controller__DOT__tile_start_cycle;
    __Vdly__tile_controller__DOT__load_count = vlSelfRef.tile_controller__DOT__load_count;
    __Vdly__tile_controller__DOT__send_count = vlSelfRef.tile_controller__DOT__send_count;
    __Vdly__tile_controller__DOT__cap_col = vlSelfRef.tile_controller__DOT__cap_col;
    __Vdly__tile_controller__DOT__d_counter = vlSelfRef.tile_controller__DOT__d_counter;
    __Vdly__tile_controller__DOT__tile_col = vlSelfRef.tile_controller__DOT__tile_col;
    __Vdly__tile_controller__DOT__deq_col = vlSelfRef.tile_controller__DOT__deq_col;
    __Vdly__tile_controller__DOT__state = vlSelfRef.tile_controller__DOT__state;
    if (vlSelfRef.rst_n) {
        if (((0U != (IData)(vlSelfRef.tile_controller__DOT__state)) 
             & (0xaU != (IData)(vlSelfRef.tile_controller__DOT__state)))) {
            __Vdly__cycle_count = ((IData)(1U) + vlSelfRef.cycle_count);
        }
        vlSelfRef.arr_valid_in = 0U;
        __Vdly__s_tready = 0U;
        vlSelfRef.sq_wr_en = 0U;
        vlSelfRef.q_wr_en = 0U;
        vlSelfRef.k_wr_en = 0U;
        vlSelfRef.out_wr_en = 0U;
        vlSelfRef.deq_valid = 0U;
        __Vdly__m_tvalid = 0U;
        vlSelfRef.m_tlast = 0U;
        if ((8U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
            if ((4U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
                __Vdly__tile_controller__DOT__state = 0U;
            } else if ((2U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
                    __Vdly__tile_controller__DOT__state = 0U;
                } else {
                    vlSelfRef.done = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
                __Vdly__tile_controller__DOT__tile_start_cycle 
                    = vlSelfRef.cycle_count;
                if (((IData)(vlSelfRef.tile_controller__DOT__tile_col) 
                     == ((IData)(vlSelfRef.tile_controller__DOT__n_tiles) 
                         - (IData)(1U)))) {
                    __Vdly__tile_controller__DOT__tile_col = 0U;
                    if (((IData)(vlSelfRef.tile_controller__DOT__tile_row) 
                         == ((IData)(vlSelfRef.tile_controller__DOT__n_tiles) 
                             - (IData)(1U)))) {
                        __Vdly__tile_controller__DOT__state = 0xaU;
                    } else {
                        vlSelfRef.tile_controller__DOT__tile_row 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.tile_controller__DOT__tile_row)));
                        __Vdly__tile_controller__DOT__state = 2U;
                        __Vdly__tile_controller__DOT__load_count = 0U;
                    }
                } else {
                    __Vdly__tile_controller__DOT__tile_col 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.tile_controller__DOT__tile_col)));
                    __Vdly__tile_controller__DOT__state = 3U;
                    __Vdly__tile_controller__DOT__load_count = 0U;
                }
            } else {
                vlSelfRef.m_tdata = ((QData)((IData)(vlSelfRef.out_rd_data)) 
                                     << 0x20U);
                vlSelfRef.m_tlast = (0xfU == vlSelfRef.tile_controller__DOT__send_count);
                if (((IData)(vlSelfRef.m_tvalid) & (IData)(vlSelfRef.m_tready))) {
                    __Vdly__tile_controller__DOT__send_count 
                        = ((IData)(1U) + vlSelfRef.tile_controller__DOT__send_count);
                    if ((0xfU == vlSelfRef.tile_controller__DOT__send_count)) {
                        __Vdly__tile_controller__DOT__state = 9U;
                    }
                }
                __Vdly__m_tvalid = 1U;
            }
        } else if ((4U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
                    if (vlSelfRef.tile_controller__DOT__deq_phase) {
                        vlSelfRef.deq_a = vlSelfRef.tile_controller__DOT__deq_intermediate;
                        vlSelfRef.deq_b = vlSelfRef.sk_rd_data;
                        vlSelfRef.deq_valid = 1U;
                        if (vlSelfRef.deq_result_valid) {
                            vlSelfRef.out_wr_en = 1U;
                            vlSelfRef.out_wr_row = 
                                (3U & vlSelfRef.tile_controller__DOT__deq_row);
                            vlSelfRef.out_wr_data = vlSelfRef.deq_result;
                            vlSelfRef.tile_controller__DOT__deq_phase = 0U;
                            vlSelfRef.out_wr_col = 
                                (3U & vlSelfRef.tile_controller__DOT__deq_col);
                            if ((3U == vlSelfRef.tile_controller__DOT__deq_col)) {
                                __Vdly__tile_controller__DOT__deq_col = 0U;
                                if ((3U == vlSelfRef.tile_controller__DOT__deq_row)) {
                                    vlSelfRef.tile_count 
                                        = ((IData)(1U) 
                                           + vlSelfRef.tile_count);
                                    __Vdly__tile_controller__DOT__send_count = 0U;
                                    vlSelfRef.tile_cycles 
                                        = (vlSelfRef.cycle_count 
                                           - vlSelfRef.tile_controller__DOT__tile_start_cycle);
                                    __Vdly__tile_controller__DOT__state = 8U;
                                } else {
                                    vlSelfRef.tile_controller__DOT__deq_row 
                                        = ((IData)(1U) 
                                           + vlSelfRef.tile_controller__DOT__deq_row);
                                }
                            } else {
                                __Vdly__tile_controller__DOT__deq_col 
                                    = ((IData)(1U) 
                                       + vlSelfRef.tile_controller__DOT__deq_col);
                            }
                        }
                    } else {
                        vlSelfRef.deq_a = vlSelfRef.out_rd_data;
                        vlSelfRef.deq_b = vlSelfRef.sq_rd_data;
                        vlSelfRef.deq_valid = 1U;
                        if (vlSelfRef.deq_result_valid) {
                            vlSelfRef.tile_controller__DOT__deq_intermediate 
                                = vlSelfRef.deq_result;
                            vlSelfRef.tile_controller__DOT__deq_phase = 1U;
                        }
                    }
                } else {
                    vlSelfRef.out_wr_en = 1U;
                    vlSelfRef.out_wr_row = (3U & vlSelfRef.tile_controller__DOT__cap_row);
                    vlSelfRef.out_wr_col = (3U & vlSelfRef.tile_controller__DOT__cap_col);
                    vlSelfRef.out_wr_data = vlSelfRef.arr_result
                        [(3U & vlSelfRef.tile_controller__DOT__cap_row)]
                        [(3U & vlSelfRef.tile_controller__DOT__cap_col)];
                    if ((3U == vlSelfRef.tile_controller__DOT__cap_col)) {
                        __Vdly__tile_controller__DOT__cap_col = 0U;
                        if ((3U == vlSelfRef.tile_controller__DOT__cap_row)) {
                            vlSelfRef.tile_controller__DOT__deq_row = 0U;
                            __Vdly__tile_controller__DOT__deq_col = 0U;
                            __Vdly__tile_controller__DOT__state = 7U;
                            vlSelfRef.tile_controller__DOT__deq_phase = 0U;
                        } else {
                            vlSelfRef.tile_controller__DOT__cap_row 
                                = ((IData)(1U) + vlSelfRef.tile_controller__DOT__cap_row);
                        }
                    } else {
                        __Vdly__tile_controller__DOT__cap_col 
                            = ((IData)(1U) + vlSelfRef.tile_controller__DOT__cap_col);
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
                if (vlSelfRef.arr_result_valid) {
                    vlSelfRef.tile_controller__DOT__cap_row = 0U;
                    __Vdly__tile_controller__DOT__cap_col = 0U;
                    __Vdly__tile_controller__DOT__state = 6U;
                }
            } else {
                __Vdly__tile_controller__DOT__d_counter 
                    = ((IData)(1U) + vlSelfRef.tile_controller__DOT__d_counter);
                vlSelfRef.tile_controller__DOT__unnamedblk3__DOT__i = 4U;
                vlSelfRef.arr_valid_in = 1U;
                vlSelfRef.q_rd_row = 0U;
                vlSelfRef.k_rd_row = 0U;
                vlSelfRef.q_rd_col = (3U & vlSelfRef.tile_controller__DOT__d_counter);
                vlSelfRef.q_rd_row = 1U;
                vlSelfRef.k_rd_row = 1U;
                vlSelfRef.k_rd_col = (3U & vlSelfRef.tile_controller__DOT__d_counter);
                vlSelfRef.q_rd_row = 2U;
                vlSelfRef.k_rd_row = 2U;
                if ((3U == vlSelfRef.tile_controller__DOT__d_counter)) {
                    __Vdly__tile_controller__DOT__state = 5U;
                }
                vlSelfRef.q_rd_row = 3U;
                vlSelfRef.k_rd_row = 3U;
            }
        } else if ((2U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
                if (((IData)(vlSelfRef.s_tvalid) & (IData)(vlSelfRef.s_tready))) {
                    vlSelfRef.k_wr_en = 1U;
                    vlSelfRef.k_wr_row = (3U & (vlSelfRef.tile_controller__DOT__load_count 
                                                >> 2U));
                    vlSelfRef.k_wr_data = (0xfU & (IData)(vlSelfRef.s_tdata));
                    vlSelfRef.k_wr_col = (3U & vlSelfRef.tile_controller__DOT__load_count);
                    __Vdly__tile_controller__DOT__load_count 
                        = ((IData)(1U) + vlSelfRef.tile_controller__DOT__load_count);
                    if ((0xfU == vlSelfRef.tile_controller__DOT__load_count)) {
                        __Vdly__tile_controller__DOT__state = 4U;
                        __Vdly__tile_controller__DOT__d_counter = 0U;
                    }
                }
                __Vdly__s_tready = 1U;
            } else {
                if (((IData)(vlSelfRef.s_tvalid) & (IData)(vlSelfRef.s_tready))) {
                    vlSelfRef.q_wr_en = 1U;
                    vlSelfRef.q_wr_row = (3U & (vlSelfRef.tile_controller__DOT__load_count 
                                                >> 2U));
                    vlSelfRef.q_wr_data = (0xfU & (IData)(vlSelfRef.s_tdata));
                    vlSelfRef.q_wr_col = (3U & vlSelfRef.tile_controller__DOT__load_count);
                    __Vdly__tile_controller__DOT__load_count 
                        = ((IData)(1U) + vlSelfRef.tile_controller__DOT__load_count);
                    if ((0xfU == vlSelfRef.tile_controller__DOT__load_count)) {
                        __Vdly__tile_controller__DOT__state = 3U;
                        __Vdly__tile_controller__DOT__load_count = 0U;
                    }
                }
                __Vdly__s_tready = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.tile_controller__DOT__state))) {
            if (((IData)(vlSelfRef.s_tvalid) & (IData)(vlSelfRef.s_tready))) {
                vlSelfRef.sq_wr_en = 1U;
                vlSelfRef.sq_wr_addr = (0x1fU & vlSelfRef.tile_controller__DOT__load_count);
                vlSelfRef.sq_wr_data = (IData)(vlSelfRef.s_tdata);
                __Vdly__tile_controller__DOT__load_count 
                    = ((IData)(1U) + vlSelfRef.tile_controller__DOT__load_count);
                if ((vlSelfRef.tile_controller__DOT__load_count 
                     == (VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.matrix_size), 1U) 
                         - (IData)(1U)))) {
                    __Vdly__tile_controller__DOT__state = 2U;
                    __Vdly__tile_controller__DOT__load_count = 0U;
                    __Vdly__tile_controller__DOT__tile_start_cycle 
                        = vlSelfRef.cycle_count;
                }
            }
            __Vdly__s_tready = 1U;
        } else {
            vlSelfRef.tile_controller__DOT__tile_row = 0U;
            __Vdly__tile_controller__DOT__tile_col = 0U;
            vlSelfRef.done = 0U;
            vlSelfRef.tile_controller__DOT__n_tiles 
                = (0xfU & VL_SHIFTR_III(4,4,32, (IData)(vlSelfRef.matrix_size), 2U));
            if (vlSelfRef.start) {
                __Vdly__tile_controller__DOT__state = 1U;
                __Vdly__tile_controller__DOT__load_count = 0U;
            }
        }
    } else {
        __Vdly__cycle_count = 0U;
        vlSelfRef.tile_controller__DOT__tile_row = 0U;
        __Vdly__tile_controller__DOT__tile_col = 0U;
        vlSelfRef.tile_controller__DOT__cap_row = 0U;
        __Vdly__tile_controller__DOT__cap_col = 0U;
        vlSelfRef.tile_controller__DOT__deq_row = 0U;
        __Vdly__tile_controller__DOT__deq_col = 0U;
        __Vdly__tile_controller__DOT__send_count = 0U;
        vlSelfRef.tile_count = 0U;
        __Vdly__s_tready = 0U;
        __Vdly__m_tvalid = 0U;
        __Vdly__tile_controller__DOT__state = 0U;
        vlSelfRef.done = 0U;
        vlSelfRef.tile_controller__DOT__n_tiles = 0U;
        __Vdly__tile_controller__DOT__d_counter = 0U;
        __Vdly__tile_controller__DOT__load_count = 0U;
        vlSelfRef.tile_cycles = 0U;
        __Vdly__tile_controller__DOT__tile_start_cycle = 0U;
        vlSelfRef.tile_controller__DOT__deq_phase = 0U;
        vlSelfRef.tile_controller__DOT__deq_intermediate = 0U;
        vlSelfRef.arr_valid_in = 0U;
        vlSelfRef.m_tdata = 0ULL;
        vlSelfRef.m_tlast = 0U;
        vlSelfRef.sq_wr_en = 0U;
        vlSelfRef.sq_wr_addr = 0U;
        vlSelfRef.sq_wr_data = 0x3f800000U;
        vlSelfRef.q_wr_en = 0U;
        vlSelfRef.q_wr_row = 0U;
        vlSelfRef.q_wr_col = 0U;
        vlSelfRef.q_wr_data = 0U;
        vlSelfRef.k_wr_en = 0U;
        vlSelfRef.k_wr_row = 0U;
        vlSelfRef.k_wr_col = 0U;
        vlSelfRef.k_wr_data = 0U;
        vlSelfRef.out_wr_en = 0U;
        vlSelfRef.out_wr_row = 0U;
        vlSelfRef.out_wr_col = 0U;
        vlSelfRef.out_wr_data = 0U;
        vlSelfRef.q_rd_row = 0U;
        vlSelfRef.q_rd_col = 0U;
        vlSelfRef.k_rd_row = 0U;
        vlSelfRef.k_rd_col = 0U;
        vlSelfRef.deq_valid = 0U;
        vlSelfRef.deq_a = 0U;
        vlSelfRef.deq_b = 0U;
    }
    vlSelfRef.s_tready = __Vdly__s_tready;
    vlSelfRef.m_tvalid = __Vdly__m_tvalid;
    vlSelfRef.cycle_count = __Vdly__cycle_count;
    vlSelfRef.tile_controller__DOT__tile_start_cycle 
        = __Vdly__tile_controller__DOT__tile_start_cycle;
    vlSelfRef.tile_controller__DOT__load_count = __Vdly__tile_controller__DOT__load_count;
    vlSelfRef.tile_controller__DOT__send_count = __Vdly__tile_controller__DOT__send_count;
    vlSelfRef.tile_controller__DOT__cap_col = __Vdly__tile_controller__DOT__cap_col;
    vlSelfRef.tile_controller__DOT__d_counter = __Vdly__tile_controller__DOT__d_counter;
    vlSelfRef.tile_controller__DOT__tile_col = __Vdly__tile_controller__DOT__tile_col;
    vlSelfRef.tile_controller__DOT__deq_col = __Vdly__tile_controller__DOT__deq_col;
    vlSelfRef.tile_controller__DOT__state = __Vdly__tile_controller__DOT__state;
    vlSelfRef.out_rd_col = (3U & vlSelfRef.tile_controller__DOT__deq_col);
    vlSelfRef.sk_rd_addr = (0xfU & (vlSelfRef.tile_controller__DOT__deq_col 
                                    + VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tile_controller__DOT__tile_col), 2U)));
    vlSelfRef.out_rd_row = (3U & vlSelfRef.tile_controller__DOT__deq_row);
    vlSelfRef.sq_rd_addr = (0xfU & (vlSelfRef.tile_controller__DOT__deq_row 
                                    + VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tile_controller__DOT__tile_row), 2U)));
    vlSelfRef.arr_a_in[0U] = 0U;
    vlSelfRef.arr_a_in[1U] = 0U;
    vlSelfRef.arr_a_in[2U] = 0U;
    vlSelfRef.arr_a_in[3U] = 0U;
    vlSelfRef.arr_b_in[0U] = 0U;
    vlSelfRef.arr_b_in[1U] = 0U;
    vlSelfRef.arr_b_in[2U] = 0U;
    vlSelfRef.arr_b_in[3U] = 0U;
    if ((4U == (IData)(vlSelfRef.tile_controller__DOT__state))) {
        vlSelfRef.tile_controller__DOT__unnamedblk2__DOT__i = 4U;
        vlSelfRef.arr_a_in[0U] = vlSelfRef.q_rd_data;
        vlSelfRef.arr_a_in[1U] = vlSelfRef.q_rd_data;
        vlSelfRef.arr_a_in[2U] = vlSelfRef.q_rd_data;
        vlSelfRef.arr_a_in[3U] = vlSelfRef.q_rd_data;
        vlSelfRef.arr_b_in[0U] = vlSelfRef.k_rd_data;
        vlSelfRef.arr_b_in[1U] = vlSelfRef.k_rd_data;
        vlSelfRef.arr_b_in[2U] = vlSelfRef.k_rd_data;
        vlSelfRef.arr_b_in[3U] = vlSelfRef.k_rd_data;
    }
    vlSelfRef.tile_controller__DOT__arr_a_in[0U] = 
        vlSelfRef.arr_a_in[0U];
    vlSelfRef.tile_controller__DOT__arr_a_in[1U] = 
        vlSelfRef.arr_a_in[1U];
    vlSelfRef.tile_controller__DOT__arr_a_in[2U] = 
        vlSelfRef.arr_a_in[2U];
    vlSelfRef.tile_controller__DOT__arr_a_in[3U] = 
        vlSelfRef.arr_a_in[3U];
    vlSelfRef.tile_controller__DOT__arr_b_in[0U] = 
        vlSelfRef.arr_b_in[0U];
    vlSelfRef.tile_controller__DOT__arr_b_in[1U] = 
        vlSelfRef.arr_b_in[1U];
    vlSelfRef.tile_controller__DOT__arr_b_in[2U] = 
        vlSelfRef.arr_b_in[2U];
    vlSelfRef.tile_controller__DOT__arr_b_in[3U] = 
        vlSelfRef.arr_b_in[3U];
}

void Vtile_controller___024root___eval_triggers__act(Vtile_controller___024root* vlSelf);

bool Vtile_controller___024root___eval_phase__act(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_phase__act\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtile_controller___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtile_controller___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtile_controller___024root___eval_phase__nba(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_phase__nba\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtile_controller___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtile_controller___024root___dump_triggers__ico(Vtile_controller___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtile_controller___024root___dump_triggers__nba(Vtile_controller___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtile_controller___024root___dump_triggers__act(Vtile_controller___024root* vlSelf);
#endif  // VL_DEBUG

void Vtile_controller___024root___eval(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtile_controller___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../rtl/tile_controller.sv", 35, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtile_controller___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtile_controller___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/tile_controller.sv", 35, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtile_controller___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/tile_controller.sv", 35, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtile_controller___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtile_controller___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtile_controller___024root___eval_debug_assertions(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_debug_assertions\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");}
    if (VL_UNLIKELY(((vlSelfRef.matrix_size & 0xf0U)))) {
        Verilated::overWidthError("matrix_size");}
    if (VL_UNLIKELY(((vlSelfRef.s_tvalid & 0xfeU)))) {
        Verilated::overWidthError("s_tvalid");}
    if (VL_UNLIKELY(((vlSelfRef.s_tlast & 0xfeU)))) {
        Verilated::overWidthError("s_tlast");}
    if (VL_UNLIKELY(((vlSelfRef.m_tready & 0xfeU)))) {
        Verilated::overWidthError("m_tready");}
    if (VL_UNLIKELY(((vlSelfRef.q_rd_data & 0xf0U)))) {
        Verilated::overWidthError("q_rd_data");}
    if (VL_UNLIKELY(((vlSelfRef.k_rd_data & 0xf0U)))) {
        Verilated::overWidthError("k_rd_data");}
    if (VL_UNLIKELY(((vlSelfRef.arr_result_valid & 0xfeU)))) {
        Verilated::overWidthError("arr_result_valid");}
    if (VL_UNLIKELY(((vlSelfRef.deq_result_valid & 0xfeU)))) {
        Verilated::overWidthError("deq_result_valid");}
}
#endif  // VL_DEBUG
