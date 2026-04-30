// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vaxi4_lite_ctrl__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vaxi4_lite_ctrl::Vaxi4_lite_ctrl(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vaxi4_lite_ctrl__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , awvalid{vlSymsp->TOP.awvalid}
    , awready{vlSymsp->TOP.awready}
    , wvalid{vlSymsp->TOP.wvalid}
    , wready{vlSymsp->TOP.wready}
    , wstrb{vlSymsp->TOP.wstrb}
    , bvalid{vlSymsp->TOP.bvalid}
    , bready{vlSymsp->TOP.bready}
    , bresp{vlSymsp->TOP.bresp}
    , arvalid{vlSymsp->TOP.arvalid}
    , arready{vlSymsp->TOP.arready}
    , rvalid{vlSymsp->TOP.rvalid}
    , rready{vlSymsp->TOP.rready}
    , rresp{vlSymsp->TOP.rresp}
    , start{vlSymsp->TOP.start}
    , done{vlSymsp->TOP.done}
    , awaddr{vlSymsp->TOP.awaddr}
    , wdata{vlSymsp->TOP.wdata}
    , araddr{vlSymsp->TOP.araddr}
    , rdata{vlSymsp->TOP.rdata}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vaxi4_lite_ctrl::Vaxi4_lite_ctrl(const char* _vcname__)
    : Vaxi4_lite_ctrl(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vaxi4_lite_ctrl::~Vaxi4_lite_ctrl() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vaxi4_lite_ctrl___024root___eval_debug_assertions(Vaxi4_lite_ctrl___024root* vlSelf);
#endif  // VL_DEBUG
void Vaxi4_lite_ctrl___024root___eval_static(Vaxi4_lite_ctrl___024root* vlSelf);
void Vaxi4_lite_ctrl___024root___eval_initial(Vaxi4_lite_ctrl___024root* vlSelf);
void Vaxi4_lite_ctrl___024root___eval_settle(Vaxi4_lite_ctrl___024root* vlSelf);
void Vaxi4_lite_ctrl___024root___eval(Vaxi4_lite_ctrl___024root* vlSelf);

void Vaxi4_lite_ctrl::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vaxi4_lite_ctrl::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vaxi4_lite_ctrl___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vaxi4_lite_ctrl___024root___eval_static(&(vlSymsp->TOP));
        Vaxi4_lite_ctrl___024root___eval_initial(&(vlSymsp->TOP));
        Vaxi4_lite_ctrl___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vaxi4_lite_ctrl___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vaxi4_lite_ctrl::eventsPending() { return false; }

uint64_t Vaxi4_lite_ctrl::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vaxi4_lite_ctrl::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vaxi4_lite_ctrl___024root___eval_final(Vaxi4_lite_ctrl___024root* vlSelf);

VL_ATTR_COLD void Vaxi4_lite_ctrl::final() {
    Vaxi4_lite_ctrl___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vaxi4_lite_ctrl::hierName() const { return vlSymsp->name(); }
const char* Vaxi4_lite_ctrl::modelName() const { return "Vaxi4_lite_ctrl"; }
unsigned Vaxi4_lite_ctrl::threads() const { return 1; }
void Vaxi4_lite_ctrl::prepareClone() const { contextp()->prepareClone(); }
void Vaxi4_lite_ctrl::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vaxi4_lite_ctrl::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vaxi4_lite_ctrl___024root__trace_decl_types(VerilatedVcd* tracep);

void Vaxi4_lite_ctrl___024root__trace_init_top(Vaxi4_lite_ctrl___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vaxi4_lite_ctrl___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi4_lite_ctrl___024root*>(voidSelf);
    Vaxi4_lite_ctrl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vaxi4_lite_ctrl___024root__trace_decl_types(tracep);
    Vaxi4_lite_ctrl___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vaxi4_lite_ctrl___024root__trace_register(Vaxi4_lite_ctrl___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vaxi4_lite_ctrl::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vaxi4_lite_ctrl::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vaxi4_lite_ctrl___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
