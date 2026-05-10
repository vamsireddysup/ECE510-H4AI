// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtile_controller__Syms.h"


void Vtile_controller___024root__trace_chg_0_sub_0(Vtile_controller___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtile_controller___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root__trace_chg_0\n"); );
    // Init
    Vtile_controller___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtile_controller___024root*>(voidSelf);
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtile_controller___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtile_controller___024root__trace_chg_0_sub_0(Vtile_controller___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root__trace_chg_0_sub_0\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tile_controller__DOT__arr_result
                               [0U][0U]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tile_controller__DOT__arr_result
                               [0U][1U]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.tile_controller__DOT__arr_result
                               [0U][2U]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.tile_controller__DOT__arr_result
                               [0U][3U]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.tile_controller__DOT__arr_result
                               [1U][0U]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.tile_controller__DOT__arr_result
                               [1U][1U]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.tile_controller__DOT__arr_result
                               [1U][2U]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.tile_controller__DOT__arr_result
                               [1U][3U]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.tile_controller__DOT__arr_result
                               [2U][0U]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.tile_controller__DOT__arr_result
                               [2U][1U]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.tile_controller__DOT__arr_result
                                [2U][2U]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.tile_controller__DOT__arr_result
                                [2U][3U]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.tile_controller__DOT__arr_result
                                [3U][0U]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.tile_controller__DOT__arr_result
                                [3U][1U]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.tile_controller__DOT__arr_result
                                [3U][2U]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.tile_controller__DOT__arr_result
                                [3U][3U]),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgCData(oldp+16,(vlSelfRef.tile_controller__DOT__arr_a_in[0]),4);
        bufp->chgCData(oldp+17,(vlSelfRef.tile_controller__DOT__arr_a_in[1]),4);
        bufp->chgCData(oldp+18,(vlSelfRef.tile_controller__DOT__arr_a_in[2]),4);
        bufp->chgCData(oldp+19,(vlSelfRef.tile_controller__DOT__arr_a_in[3]),4);
        bufp->chgCData(oldp+20,(vlSelfRef.tile_controller__DOT__arr_b_in[0]),4);
        bufp->chgCData(oldp+21,(vlSelfRef.tile_controller__DOT__arr_b_in[1]),4);
        bufp->chgCData(oldp+22,(vlSelfRef.tile_controller__DOT__arr_b_in[2]),4);
        bufp->chgCData(oldp+23,(vlSelfRef.tile_controller__DOT__arr_b_in[3]),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+24,(vlSelfRef.tile_controller__DOT__state),4);
        bufp->chgCData(oldp+25,(vlSelfRef.tile_controller__DOT__tile_row),4);
        bufp->chgCData(oldp+26,(vlSelfRef.tile_controller__DOT__tile_col),4);
        bufp->chgCData(oldp+27,(vlSelfRef.tile_controller__DOT__n_tiles),4);
        bufp->chgIData(oldp+28,(vlSelfRef.tile_controller__DOT__d_counter),32);
        bufp->chgIData(oldp+29,(vlSelfRef.tile_controller__DOT__load_count),32);
        bufp->chgIData(oldp+30,(vlSelfRef.tile_controller__DOT__cap_row),32);
        bufp->chgIData(oldp+31,(vlSelfRef.tile_controller__DOT__cap_col),32);
        bufp->chgIData(oldp+32,(vlSelfRef.tile_controller__DOT__deq_row),32);
        bufp->chgIData(oldp+33,(vlSelfRef.tile_controller__DOT__deq_col),32);
        bufp->chgIData(oldp+34,(vlSelfRef.tile_controller__DOT__send_count),32);
        bufp->chgIData(oldp+35,(vlSelfRef.tile_controller__DOT__tile_start_cycle),32);
        bufp->chgBit(oldp+36,(vlSelfRef.tile_controller__DOT__deq_phase));
        bufp->chgIData(oldp+37,(vlSelfRef.tile_controller__DOT__deq_intermediate),32);
        bufp->chgIData(oldp+38,(vlSelfRef.tile_controller__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+39,(vlSelfRef.tile_controller__DOT__unnamedblk3__DOT__i),32);
    }
    bufp->chgBit(oldp+40,(vlSelfRef.clk));
    bufp->chgBit(oldp+41,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+42,(vlSelfRef.start));
    bufp->chgCData(oldp+43,(vlSelfRef.matrix_size),4);
    bufp->chgBit(oldp+44,(vlSelfRef.done));
    bufp->chgIData(oldp+45,(vlSelfRef.tile_count),32);
    bufp->chgIData(oldp+46,(vlSelfRef.cycle_count),32);
    bufp->chgIData(oldp+47,(vlSelfRef.tile_cycles),32);
    bufp->chgBit(oldp+48,(vlSelfRef.s_tvalid));
    bufp->chgBit(oldp+49,(vlSelfRef.s_tready));
    bufp->chgQData(oldp+50,(vlSelfRef.s_tdata),64);
    bufp->chgBit(oldp+52,(vlSelfRef.s_tlast));
    bufp->chgBit(oldp+53,(vlSelfRef.m_tvalid));
    bufp->chgBit(oldp+54,(vlSelfRef.m_tready));
    bufp->chgQData(oldp+55,(vlSelfRef.m_tdata),64);
    bufp->chgBit(oldp+57,(vlSelfRef.m_tlast));
    bufp->chgBit(oldp+58,(vlSelfRef.sq_wr_en));
    bufp->chgCData(oldp+59,(vlSelfRef.sq_wr_addr),5);
    bufp->chgIData(oldp+60,(vlSelfRef.sq_wr_data),32);
    bufp->chgCData(oldp+61,(vlSelfRef.sq_rd_addr),4);
    bufp->chgIData(oldp+62,(vlSelfRef.sq_rd_data),32);
    bufp->chgCData(oldp+63,(vlSelfRef.sk_rd_addr),4);
    bufp->chgIData(oldp+64,(vlSelfRef.sk_rd_data),32);
    bufp->chgBit(oldp+65,(vlSelfRef.q_wr_en));
    bufp->chgCData(oldp+66,(vlSelfRef.q_wr_row),2);
    bufp->chgCData(oldp+67,(vlSelfRef.q_wr_col),2);
    bufp->chgCData(oldp+68,(vlSelfRef.q_wr_data),4);
    bufp->chgCData(oldp+69,(vlSelfRef.q_rd_row),2);
    bufp->chgCData(oldp+70,(vlSelfRef.q_rd_col),2);
    bufp->chgCData(oldp+71,(vlSelfRef.q_rd_data),4);
    bufp->chgBit(oldp+72,(vlSelfRef.k_wr_en));
    bufp->chgCData(oldp+73,(vlSelfRef.k_wr_row),2);
    bufp->chgCData(oldp+74,(vlSelfRef.k_wr_col),2);
    bufp->chgCData(oldp+75,(vlSelfRef.k_wr_data),4);
    bufp->chgCData(oldp+76,(vlSelfRef.k_rd_row),2);
    bufp->chgCData(oldp+77,(vlSelfRef.k_rd_col),2);
    bufp->chgCData(oldp+78,(vlSelfRef.k_rd_data),4);
    bufp->chgBit(oldp+79,(vlSelfRef.out_wr_en));
    bufp->chgCData(oldp+80,(vlSelfRef.out_wr_row),2);
    bufp->chgCData(oldp+81,(vlSelfRef.out_wr_col),2);
    bufp->chgIData(oldp+82,(vlSelfRef.out_wr_data),32);
    bufp->chgCData(oldp+83,(vlSelfRef.out_rd_row),2);
    bufp->chgCData(oldp+84,(vlSelfRef.out_rd_col),2);
    bufp->chgIData(oldp+85,(vlSelfRef.out_rd_data),32);
    bufp->chgCData(oldp+86,(vlSelfRef.arr_a_in[0]),4);
    bufp->chgCData(oldp+87,(vlSelfRef.arr_a_in[1]),4);
    bufp->chgCData(oldp+88,(vlSelfRef.arr_a_in[2]),4);
    bufp->chgCData(oldp+89,(vlSelfRef.arr_a_in[3]),4);
    bufp->chgCData(oldp+90,(vlSelfRef.arr_b_in[0]),4);
    bufp->chgCData(oldp+91,(vlSelfRef.arr_b_in[1]),4);
    bufp->chgCData(oldp+92,(vlSelfRef.arr_b_in[2]),4);
    bufp->chgCData(oldp+93,(vlSelfRef.arr_b_in[3]),4);
    bufp->chgBit(oldp+94,(vlSelfRef.arr_valid_in));
    bufp->chgIData(oldp+95,(vlSelfRef.arr_result[0U]
                            [0U]),32);
    bufp->chgIData(oldp+96,(vlSelfRef.arr_result[0U]
                            [1U]),32);
    bufp->chgIData(oldp+97,(vlSelfRef.arr_result[0U]
                            [2U]),32);
    bufp->chgIData(oldp+98,(vlSelfRef.arr_result[0U]
                            [3U]),32);
    bufp->chgIData(oldp+99,(vlSelfRef.arr_result[1U]
                            [0U]),32);
    bufp->chgIData(oldp+100,(vlSelfRef.arr_result[1U]
                             [1U]),32);
    bufp->chgIData(oldp+101,(vlSelfRef.arr_result[1U]
                             [2U]),32);
    bufp->chgIData(oldp+102,(vlSelfRef.arr_result[1U]
                             [3U]),32);
    bufp->chgIData(oldp+103,(vlSelfRef.arr_result[2U]
                             [0U]),32);
    bufp->chgIData(oldp+104,(vlSelfRef.arr_result[2U]
                             [1U]),32);
    bufp->chgIData(oldp+105,(vlSelfRef.arr_result[2U]
                             [2U]),32);
    bufp->chgIData(oldp+106,(vlSelfRef.arr_result[2U]
                             [3U]),32);
    bufp->chgIData(oldp+107,(vlSelfRef.arr_result[3U]
                             [0U]),32);
    bufp->chgIData(oldp+108,(vlSelfRef.arr_result[3U]
                             [1U]),32);
    bufp->chgIData(oldp+109,(vlSelfRef.arr_result[3U]
                             [2U]),32);
    bufp->chgIData(oldp+110,(vlSelfRef.arr_result[3U]
                             [3U]),32);
    bufp->chgBit(oldp+111,(vlSelfRef.arr_result_valid));
    bufp->chgIData(oldp+112,(vlSelfRef.deq_a),32);
    bufp->chgIData(oldp+113,(vlSelfRef.deq_b),32);
    bufp->chgBit(oldp+114,(vlSelfRef.deq_valid));
    bufp->chgIData(oldp+115,(vlSelfRef.deq_result),32);
    bufp->chgBit(oldp+116,(vlSelfRef.deq_result_valid));
}

void Vtile_controller___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root__trace_cleanup\n"); );
    // Init
    Vtile_controller___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtile_controller___024root*>(voidSelf);
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
