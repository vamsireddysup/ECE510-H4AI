// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpe__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vpe::Vpe(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpe__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , valid_in{vlSymsp->TOP.valid_in}
    , valid_out{vlSymsp->TOP.valid_out}
    , result_valid{vlSymsp->TOP.result_valid}
    , a_in{vlSymsp->TOP.a_in}
    , b_in{vlSymsp->TOP.b_in}
    , a_out{vlSymsp->TOP.a_out}
    , b_out{vlSymsp->TOP.b_out}
    , result{vlSymsp->TOP.result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vpe::Vpe(const char* _vcname__)
    : Vpe(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpe::~Vpe() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpe___024root___eval_debug_assertions(Vpe___024root* vlSelf);
#endif  // VL_DEBUG
void Vpe___024root___eval_static(Vpe___024root* vlSelf);
void Vpe___024root___eval_initial(Vpe___024root* vlSelf);
void Vpe___024root___eval_settle(Vpe___024root* vlSelf);
void Vpe___024root___eval(Vpe___024root* vlSelf);

void Vpe::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpe::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpe___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vpe___024root___eval_static(&(vlSymsp->TOP));
        Vpe___024root___eval_initial(&(vlSymsp->TOP));
        Vpe___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vpe___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vpe::eventsPending() { return false; }

uint64_t Vpe::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vpe::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vpe___024root___eval_final(Vpe___024root* vlSelf);

VL_ATTR_COLD void Vpe::final() {
    Vpe___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpe::hierName() const { return vlSymsp->name(); }
const char* Vpe::modelName() const { return "Vpe"; }
unsigned Vpe::threads() const { return 1; }
void Vpe::prepareClone() const { contextp()->prepareClone(); }
void Vpe::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vpe::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vpe___024root__trace_decl_types(VerilatedVcd* tracep);

void Vpe___024root__trace_init_top(Vpe___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vpe___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpe___024root*>(voidSelf);
    Vpe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vpe___024root__trace_decl_types(tracep);
    Vpe___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpe___024root__trace_register(Vpe___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpe::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vpe::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vpe___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
