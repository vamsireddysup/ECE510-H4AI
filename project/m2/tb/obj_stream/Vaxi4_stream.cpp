// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vaxi4_stream__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vaxi4_stream::Vaxi4_stream(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vaxi4_stream__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , s_tvalid{vlSymsp->TOP.s_tvalid}
    , s_tready{vlSymsp->TOP.s_tready}
    , s_tlast{vlSymsp->TOP.s_tlast}
    , m_tvalid{vlSymsp->TOP.m_tvalid}
    , m_tready{vlSymsp->TOP.m_tready}
    , m_tlast{vlSymsp->TOP.m_tlast}
    , start{vlSymsp->TOP.start}
    , done{vlSymsp->TOP.done}
    , s_tdata{vlSymsp->TOP.s_tdata}
    , m_tdata{vlSymsp->TOP.m_tdata}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vaxi4_stream::Vaxi4_stream(const char* _vcname__)
    : Vaxi4_stream(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vaxi4_stream::~Vaxi4_stream() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vaxi4_stream___024root___eval_debug_assertions(Vaxi4_stream___024root* vlSelf);
#endif  // VL_DEBUG
void Vaxi4_stream___024root___eval_static(Vaxi4_stream___024root* vlSelf);
void Vaxi4_stream___024root___eval_initial(Vaxi4_stream___024root* vlSelf);
void Vaxi4_stream___024root___eval_settle(Vaxi4_stream___024root* vlSelf);
void Vaxi4_stream___024root___eval(Vaxi4_stream___024root* vlSelf);

void Vaxi4_stream::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vaxi4_stream::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vaxi4_stream___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vaxi4_stream___024root___eval_static(&(vlSymsp->TOP));
        Vaxi4_stream___024root___eval_initial(&(vlSymsp->TOP));
        Vaxi4_stream___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vaxi4_stream___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vaxi4_stream::eventsPending() { return false; }

uint64_t Vaxi4_stream::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vaxi4_stream::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vaxi4_stream___024root___eval_final(Vaxi4_stream___024root* vlSelf);

VL_ATTR_COLD void Vaxi4_stream::final() {
    Vaxi4_stream___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vaxi4_stream::hierName() const { return vlSymsp->name(); }
const char* Vaxi4_stream::modelName() const { return "Vaxi4_stream"; }
unsigned Vaxi4_stream::threads() const { return 1; }
void Vaxi4_stream::prepareClone() const { contextp()->prepareClone(); }
void Vaxi4_stream::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vaxi4_stream::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vaxi4_stream___024root__trace_decl_types(VerilatedVcd* tracep);

void Vaxi4_stream___024root__trace_init_top(Vaxi4_stream___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vaxi4_stream___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi4_stream___024root*>(voidSelf);
    Vaxi4_stream__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vaxi4_stream___024root__trace_decl_types(tracep);
    Vaxi4_stream___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vaxi4_stream___024root__trace_register(Vaxi4_stream___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vaxi4_stream::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vaxi4_stream::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vaxi4_stream___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
