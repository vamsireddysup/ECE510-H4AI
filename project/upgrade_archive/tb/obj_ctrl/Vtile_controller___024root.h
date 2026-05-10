// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtile_controller.h for the primary calling header

#ifndef VERILATED_VTILE_CONTROLLER___024ROOT_H_
#define VERILATED_VTILE_CONTROLLER___024ROOT_H_  // guard

#include "verilated.h"


class Vtile_controller__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtile_controller___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(start,0,0);
        VL_IN8(matrix_size,3,0);
        VL_OUT8(done,0,0);
        VL_IN8(s_tvalid,0,0);
        VL_OUT8(s_tready,0,0);
        VL_IN8(s_tlast,0,0);
        VL_OUT8(m_tvalid,0,0);
        VL_IN8(m_tready,0,0);
        VL_OUT8(m_tlast,0,0);
        VL_OUT8(sq_wr_en,0,0);
        VL_OUT8(sq_wr_addr,4,0);
        VL_OUT8(sq_rd_addr,3,0);
        VL_OUT8(sk_rd_addr,3,0);
        VL_OUT8(q_wr_en,0,0);
        VL_OUT8(q_wr_row,1,0);
        VL_OUT8(q_wr_col,1,0);
        VL_OUT8(q_wr_data,3,0);
        VL_OUT8(q_rd_row,1,0);
        VL_OUT8(q_rd_col,1,0);
        VL_IN8(q_rd_data,3,0);
        VL_OUT8(k_wr_en,0,0);
        VL_OUT8(k_wr_row,1,0);
        VL_OUT8(k_wr_col,1,0);
        VL_OUT8(k_wr_data,3,0);
        VL_OUT8(k_rd_row,1,0);
        VL_OUT8(k_rd_col,1,0);
        VL_IN8(k_rd_data,3,0);
        VL_OUT8(out_wr_en,0,0);
        VL_OUT8(out_wr_row,1,0);
        VL_OUT8(out_wr_col,1,0);
        VL_OUT8(out_rd_row,1,0);
        VL_OUT8(out_rd_col,1,0);
        VL_OUT8(arr_valid_in,0,0);
        VL_IN8(arr_result_valid,0,0);
        VL_OUT8(deq_valid,0,0);
        VL_IN8(deq_result_valid,0,0);
        CData/*3:0*/ tile_controller__DOT__state;
        CData/*3:0*/ tile_controller__DOT__tile_row;
        CData/*3:0*/ tile_controller__DOT__tile_col;
        CData/*3:0*/ tile_controller__DOT__n_tiles;
        CData/*0:0*/ tile_controller__DOT__deq_phase;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT(tile_count,31,0);
        VL_OUT(cycle_count,31,0);
        VL_OUT(tile_cycles,31,0);
        VL_OUT(sq_wr_data,31,0);
        VL_IN(sq_rd_data,31,0);
        VL_IN(sk_rd_data,31,0);
        VL_OUT(out_wr_data,31,0);
        VL_IN(out_rd_data,31,0);
        VL_OUT(deq_a,31,0);
        VL_OUT(deq_b,31,0);
        VL_IN(deq_result,31,0);
        IData/*31:0*/ tile_controller__DOT__d_counter;
        IData/*31:0*/ tile_controller__DOT__load_count;
        IData/*31:0*/ tile_controller__DOT__cap_row;
        IData/*31:0*/ tile_controller__DOT__cap_col;
        IData/*31:0*/ tile_controller__DOT__deq_row;
        IData/*31:0*/ tile_controller__DOT__deq_col;
    };
    struct {
        IData/*31:0*/ tile_controller__DOT__send_count;
        IData/*31:0*/ tile_controller__DOT__tile_start_cycle;
        IData/*31:0*/ tile_controller__DOT__deq_intermediate;
        IData/*31:0*/ tile_controller__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ tile_controller__DOT__unnamedblk3__DOT__i;
        IData/*31:0*/ __VactIterCount;
        VL_IN64(s_tdata,63,0);
        VL_OUT64(m_tdata,63,0);
        VL_OUT8(arr_a_in[4],3,0);
        VL_OUT8(arr_b_in[4],3,0);
        VL_IN(arr_result[4][4],31,0);
        VlUnpacked<CData/*3:0*/, 4> tile_controller__DOT__arr_a_in;
        VlUnpacked<CData/*3:0*/, 4> tile_controller__DOT__arr_b_in;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 4>, 4> tile_controller__DOT__arr_result;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtile_controller__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtile_controller___024root(Vtile_controller__Syms* symsp, const char* v__name);
    ~Vtile_controller___024root();
    VL_UNCOPYABLE(Vtile_controller___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
