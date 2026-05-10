// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfp4_mul__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vfp4_mul::Vfp4_mul(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfp4_mul__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , valid_in{vlSymsp->TOP.valid_in}
    , valid_out{vlSymsp->TOP.valid_out}
    , result{vlSymsp->TOP.result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vfp4_mul::Vfp4_mul(const char* _vcname__)
    : Vfp4_mul(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfp4_mul::~Vfp4_mul() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfp4_mul___024root___eval_debug_assertions(Vfp4_mul___024root* vlSelf);
#endif  // VL_DEBUG
void Vfp4_mul___024root___eval_static(Vfp4_mul___024root* vlSelf);
void Vfp4_mul___024root___eval_initial(Vfp4_mul___024root* vlSelf);
void Vfp4_mul___024root___eval_settle(Vfp4_mul___024root* vlSelf);
void Vfp4_mul___024root___eval(Vfp4_mul___024root* vlSelf);

void Vfp4_mul::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfp4_mul::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfp4_mul___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfp4_mul___024root___eval_static(&(vlSymsp->TOP));
        Vfp4_mul___024root___eval_initial(&(vlSymsp->TOP));
        Vfp4_mul___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfp4_mul___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vfp4_mul::eventsPending() { return false; }

uint64_t Vfp4_mul::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vfp4_mul::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfp4_mul___024root___eval_final(Vfp4_mul___024root* vlSelf);

VL_ATTR_COLD void Vfp4_mul::final() {
    Vfp4_mul___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfp4_mul::hierName() const { return vlSymsp->name(); }
const char* Vfp4_mul::modelName() const { return "Vfp4_mul"; }
unsigned Vfp4_mul::threads() const { return 1; }
void Vfp4_mul::prepareClone() const { contextp()->prepareClone(); }
void Vfp4_mul::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vfp4_mul::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vfp4_mul___024root__trace_decl_types(VerilatedVcd* tracep);

void Vfp4_mul___024root__trace_init_top(Vfp4_mul___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfp4_mul___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfp4_mul___024root*>(voidSelf);
    Vfp4_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vfp4_mul___024root__trace_decl_types(tracep);
    Vfp4_mul___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfp4_mul___024root__trace_register(Vfp4_mul___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vfp4_mul::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vfp4_mul::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vfp4_mul___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
