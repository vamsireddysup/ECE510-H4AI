// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtile_controller__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtile_controller::Vtile_controller(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtile_controller__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , start{vlSymsp->TOP.start}
    , matrix_size{vlSymsp->TOP.matrix_size}
    , done{vlSymsp->TOP.done}
    , s_tvalid{vlSymsp->TOP.s_tvalid}
    , s_tready{vlSymsp->TOP.s_tready}
    , s_tlast{vlSymsp->TOP.s_tlast}
    , m_tvalid{vlSymsp->TOP.m_tvalid}
    , m_tready{vlSymsp->TOP.m_tready}
    , m_tlast{vlSymsp->TOP.m_tlast}
    , sq_wr_en{vlSymsp->TOP.sq_wr_en}
    , sq_wr_addr{vlSymsp->TOP.sq_wr_addr}
    , sq_rd_addr{vlSymsp->TOP.sq_rd_addr}
    , sk_rd_addr{vlSymsp->TOP.sk_rd_addr}
    , q_wr_en{vlSymsp->TOP.q_wr_en}
    , q_wr_row{vlSymsp->TOP.q_wr_row}
    , q_wr_col{vlSymsp->TOP.q_wr_col}
    , q_wr_data{vlSymsp->TOP.q_wr_data}
    , q_rd_row{vlSymsp->TOP.q_rd_row}
    , q_rd_col{vlSymsp->TOP.q_rd_col}
    , q_rd_data{vlSymsp->TOP.q_rd_data}
    , k_wr_en{vlSymsp->TOP.k_wr_en}
    , k_wr_row{vlSymsp->TOP.k_wr_row}
    , k_wr_col{vlSymsp->TOP.k_wr_col}
    , k_wr_data{vlSymsp->TOP.k_wr_data}
    , k_rd_row{vlSymsp->TOP.k_rd_row}
    , k_rd_col{vlSymsp->TOP.k_rd_col}
    , k_rd_data{vlSymsp->TOP.k_rd_data}
    , out_wr_en{vlSymsp->TOP.out_wr_en}
    , out_wr_row{vlSymsp->TOP.out_wr_row}
    , out_wr_col{vlSymsp->TOP.out_wr_col}
    , out_rd_row{vlSymsp->TOP.out_rd_row}
    , out_rd_col{vlSymsp->TOP.out_rd_col}
    , arr_valid_in{vlSymsp->TOP.arr_valid_in}
    , arr_result_valid{vlSymsp->TOP.arr_result_valid}
    , deq_valid{vlSymsp->TOP.deq_valid}
    , deq_result_valid{vlSymsp->TOP.deq_result_valid}
    , tile_count{vlSymsp->TOP.tile_count}
    , cycle_count{vlSymsp->TOP.cycle_count}
    , tile_cycles{vlSymsp->TOP.tile_cycles}
    , sq_wr_data{vlSymsp->TOP.sq_wr_data}
    , sq_rd_data{vlSymsp->TOP.sq_rd_data}
    , sk_rd_data{vlSymsp->TOP.sk_rd_data}
    , out_wr_data{vlSymsp->TOP.out_wr_data}
    , out_rd_data{vlSymsp->TOP.out_rd_data}
    , deq_a{vlSymsp->TOP.deq_a}
    , deq_b{vlSymsp->TOP.deq_b}
    , deq_result{vlSymsp->TOP.deq_result}
    , s_tdata{vlSymsp->TOP.s_tdata}
    , m_tdata{vlSymsp->TOP.m_tdata}
    , arr_a_in{vlSymsp->TOP.arr_a_in}
    , arr_b_in{vlSymsp->TOP.arr_b_in}
    , arr_result{vlSymsp->TOP.arr_result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtile_controller::Vtile_controller(const char* _vcname__)
    : Vtile_controller(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtile_controller::~Vtile_controller() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtile_controller___024root___eval_debug_assertions(Vtile_controller___024root* vlSelf);
#endif  // VL_DEBUG
void Vtile_controller___024root___eval_static(Vtile_controller___024root* vlSelf);
void Vtile_controller___024root___eval_initial(Vtile_controller___024root* vlSelf);
void Vtile_controller___024root___eval_settle(Vtile_controller___024root* vlSelf);
void Vtile_controller___024root___eval(Vtile_controller___024root* vlSelf);

void Vtile_controller::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtile_controller::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtile_controller___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtile_controller___024root___eval_static(&(vlSymsp->TOP));
        Vtile_controller___024root___eval_initial(&(vlSymsp->TOP));
        Vtile_controller___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtile_controller___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtile_controller::eventsPending() { return false; }

uint64_t Vtile_controller::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtile_controller::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtile_controller___024root___eval_final(Vtile_controller___024root* vlSelf);

VL_ATTR_COLD void Vtile_controller::final() {
    Vtile_controller___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtile_controller::hierName() const { return vlSymsp->name(); }
const char* Vtile_controller::modelName() const { return "Vtile_controller"; }
unsigned Vtile_controller::threads() const { return 1; }
void Vtile_controller::prepareClone() const { contextp()->prepareClone(); }
void Vtile_controller::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtile_controller::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtile_controller___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtile_controller___024root__trace_init_top(Vtile_controller___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtile_controller___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtile_controller___024root*>(voidSelf);
    Vtile_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vtile_controller___024root__trace_decl_types(tracep);
    Vtile_controller___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtile_controller___024root__trace_register(Vtile_controller___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtile_controller::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtile_controller::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtile_controller___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
