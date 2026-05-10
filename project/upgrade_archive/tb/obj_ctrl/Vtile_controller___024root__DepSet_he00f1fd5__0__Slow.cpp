// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtile_controller.h for the primary calling header

#include "Vtile_controller__pch.h"
#include "Vtile_controller___024root.h"

VL_ATTR_COLD void Vtile_controller___024root___eval_static(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_static\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vtile_controller___024root___eval_initial(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_initial\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtile_controller___024root___eval_final(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_final\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtile_controller___024root___dump_triggers__stl(Vtile_controller___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtile_controller___024root___eval_phase__stl(Vtile_controller___024root* vlSelf);

VL_ATTR_COLD void Vtile_controller___024root___eval_settle(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_settle\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtile_controller___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../rtl/tile_controller.sv", 35, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtile_controller___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtile_controller___024root___dump_triggers__stl(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___dump_triggers__stl\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtile_controller___024root___stl_sequent__TOP__0(Vtile_controller___024root* vlSelf);
VL_ATTR_COLD void Vtile_controller___024root____Vm_traceActivitySetAll(Vtile_controller___024root* vlSelf);

VL_ATTR_COLD void Vtile_controller___024root___eval_stl(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_stl\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtile_controller___024root___stl_sequent__TOP__0(vlSelf);
        Vtile_controller___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vtile_controller___024root___stl_sequent__TOP__0(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___stl_sequent__TOP__0\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.out_rd_row = (3U & vlSelfRef.tile_controller__DOT__deq_row);
    vlSelfRef.out_rd_col = (3U & vlSelfRef.tile_controller__DOT__deq_col);
    vlSelfRef.sq_rd_addr = (0xfU & (vlSelfRef.tile_controller__DOT__deq_row 
                                    + VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tile_controller__DOT__tile_row), 2U)));
    vlSelfRef.sk_rd_addr = (0xfU & (vlSelfRef.tile_controller__DOT__deq_col 
                                    + VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tile_controller__DOT__tile_col), 2U)));
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

VL_ATTR_COLD void Vtile_controller___024root___eval_triggers__stl(Vtile_controller___024root* vlSelf);

VL_ATTR_COLD bool Vtile_controller___024root___eval_phase__stl(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___eval_phase__stl\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtile_controller___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtile_controller___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtile_controller___024root___dump_triggers__ico(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___dump_triggers__ico\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtile_controller___024root___dump_triggers__act(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___dump_triggers__act\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtile_controller___024root___dump_triggers__nba(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___dump_triggers__nba\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtile_controller___024root____Vm_traceActivitySetAll(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root____Vm_traceActivitySetAll\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vtile_controller___024root___ctor_var_reset(Vtile_controller___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtile_controller___024root___ctor_var_reset\n"); );
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->matrix_size = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17558779229204722347ull);
    vlSelf->done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    vlSelf->tile_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2419852463654692044ull);
    vlSelf->cycle_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 812857792956672393ull);
    vlSelf->tile_cycles = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18125357477197821640ull);
    vlSelf->s_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5856568867834129024ull);
    vlSelf->s_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14368903921307703071ull);
    vlSelf->s_tdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7101865465292779667ull);
    vlSelf->s_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17697317467885297558ull);
    vlSelf->m_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6330821876457450032ull);
    vlSelf->m_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15425253223298272161ull);
    vlSelf->m_tdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16534874751520676056ull);
    vlSelf->m_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9494342378649836147ull);
    vlSelf->sq_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8132567653980831184ull);
    vlSelf->sq_wr_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17976296689029208418ull);
    vlSelf->sq_wr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10622545417063953584ull);
    vlSelf->sq_rd_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17221136914317926900ull);
    vlSelf->sq_rd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1778937896583938275ull);
    vlSelf->sk_rd_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15897535909751632490ull);
    vlSelf->sk_rd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8399580524944441269ull);
    vlSelf->q_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9565469845145902543ull);
    vlSelf->q_wr_row = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11892464816475930824ull);
    vlSelf->q_wr_col = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9411448794495853802ull);
    vlSelf->q_wr_data = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8358855490828099864ull);
    vlSelf->q_rd_row = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8465485439606129509ull);
    vlSelf->q_rd_col = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3759949680489292947ull);
    vlSelf->q_rd_data = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8527376849088404402ull);
    vlSelf->k_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8646769049732477282ull);
    vlSelf->k_wr_row = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10566981868800600472ull);
    vlSelf->k_wr_col = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11856151773969696846ull);
    vlSelf->k_wr_data = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16372217547408930318ull);
    vlSelf->k_rd_row = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13136616331377828600ull);
    vlSelf->k_rd_col = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10686588402017835331ull);
    vlSelf->k_rd_data = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18407627037893736649ull);
    vlSelf->out_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15096835177312460065ull);
    vlSelf->out_wr_row = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 619992018190961693ull);
    vlSelf->out_wr_col = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6938831302452253798ull);
    vlSelf->out_wr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17570240043177843908ull);
    vlSelf->out_rd_row = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10220616591805795035ull);
    vlSelf->out_rd_col = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1509765215225758145ull);
    vlSelf->out_rd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6674657435186929573ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->arr_a_in[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15512900868006112654ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->arr_b_in[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2037295346979408772ull);
    }
    vlSelf->arr_valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18362230647743324060ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->arr_result[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17841660780471261211ull);
        }
    }
    vlSelf->arr_result_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 143330037527301970ull);
    vlSelf->deq_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 520961632111335049ull);
    vlSelf->deq_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6381603230612808837ull);
    vlSelf->deq_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16408766479533735427ull);
    vlSelf->deq_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9082792528316945079ull);
    vlSelf->deq_result_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6062011047238965751ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tile_controller__DOT__arr_a_in[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16602322154745506161ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tile_controller__DOT__arr_b_in[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18224919399204969121ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->tile_controller__DOT__arr_result[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14613232308424596178ull);
        }
    }
    vlSelf->tile_controller__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8554460364547380374ull);
    vlSelf->tile_controller__DOT__tile_row = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1909134670898829441ull);
    vlSelf->tile_controller__DOT__tile_col = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11148694352335370994ull);
    vlSelf->tile_controller__DOT__n_tiles = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4701452751509784344ull);
    vlSelf->tile_controller__DOT__d_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6333864735163038501ull);
    vlSelf->tile_controller__DOT__load_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17978150185568712912ull);
    vlSelf->tile_controller__DOT__cap_row = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16943031832351632141ull);
    vlSelf->tile_controller__DOT__cap_col = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13987861669887757284ull);
    vlSelf->tile_controller__DOT__deq_row = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17972355190308701955ull);
    vlSelf->tile_controller__DOT__deq_col = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1490058005689985104ull);
    vlSelf->tile_controller__DOT__send_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3432346448999597843ull);
    vlSelf->tile_controller__DOT__tile_start_cycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8150121880127068294ull);
    vlSelf->tile_controller__DOT__deq_phase = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5664156717725965283ull);
    vlSelf->tile_controller__DOT__deq_intermediate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 756014264471404757ull);
    vlSelf->tile_controller__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->tile_controller__DOT__unnamedblk3__DOT__i = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
