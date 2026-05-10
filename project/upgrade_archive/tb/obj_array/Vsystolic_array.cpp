// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsystolic_array__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsystolic_array::Vsystolic_array(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsystolic_array__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , valid_in{vlSymsp->TOP.valid_in}
    , result_valid{vlSymsp->TOP.result_valid}
    , a_in{vlSymsp->TOP.a_in}
    , b_in{vlSymsp->TOP.b_in}
    , result{vlSymsp->TOP.result}
    , __PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__1__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__2__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__1__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__2__KET____DOT__u_pe}
    , __PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe{vlSymsp->TOP.__PVT__systolic_array__DOT__gen_row__BRA__3__KET____DOT__gen_col__BRA__3__KET____DOT__u_pe}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vsystolic_array::Vsystolic_array(const char* _vcname__)
    : Vsystolic_array(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsystolic_array::~Vsystolic_array() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsystolic_array___024root___eval_debug_assertions(Vsystolic_array___024root* vlSelf);
#endif  // VL_DEBUG
void Vsystolic_array___024root___eval_static(Vsystolic_array___024root* vlSelf);
void Vsystolic_array___024root___eval_initial(Vsystolic_array___024root* vlSelf);
void Vsystolic_array___024root___eval_settle(Vsystolic_array___024root* vlSelf);
void Vsystolic_array___024root___eval(Vsystolic_array___024root* vlSelf);

void Vsystolic_array::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsystolic_array::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsystolic_array___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsystolic_array___024root___eval_static(&(vlSymsp->TOP));
        Vsystolic_array___024root___eval_initial(&(vlSymsp->TOP));
        Vsystolic_array___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsystolic_array___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsystolic_array::eventsPending() { return false; }

uint64_t Vsystolic_array::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsystolic_array::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsystolic_array___024root___eval_final(Vsystolic_array___024root* vlSelf);

VL_ATTR_COLD void Vsystolic_array::final() {
    Vsystolic_array___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsystolic_array::hierName() const { return vlSymsp->name(); }
const char* Vsystolic_array::modelName() const { return "Vsystolic_array"; }
unsigned Vsystolic_array::threads() const { return 1; }
void Vsystolic_array::prepareClone() const { contextp()->prepareClone(); }
void Vsystolic_array::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsystolic_array::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsystolic_array___024root__trace_decl_types(VerilatedVcd* tracep);

void Vsystolic_array___024root__trace_init_top(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsystolic_array___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsystolic_array___024root*>(voidSelf);
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array___024root__trace_decl_types(tracep);
    Vsystolic_array___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array___024root__trace_register(Vsystolic_array___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsystolic_array::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsystolic_array::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsystolic_array___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
