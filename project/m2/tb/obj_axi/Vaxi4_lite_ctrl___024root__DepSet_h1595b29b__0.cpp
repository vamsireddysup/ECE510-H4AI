// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi4_lite_ctrl.h for the primary calling header

#include "Vaxi4_lite_ctrl__pch.h"
#include "Vaxi4_lite_ctrl___024root.h"

void Vaxi4_lite_ctrl___024root___eval_act(Vaxi4_lite_ctrl___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_lite_ctrl___024root___eval_act\n"); );
    Vaxi4_lite_ctrl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vaxi4_lite_ctrl___024root___nba_sequent__TOP__0(Vaxi4_lite_ctrl___024root* vlSelf);

void Vaxi4_lite_ctrl___024root___eval_nba(Vaxi4_lite_ctrl___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_lite_ctrl___024root___eval_nba\n"); );
    Vaxi4_lite_ctrl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaxi4_lite_ctrl___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vaxi4_lite_ctrl___024root___nba_sequent__TOP__0(Vaxi4_lite_ctrl___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_lite_ctrl___024root___nba_sequent__TOP__0\n"); );
    Vaxi4_lite_ctrl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__axi4_lite_ctrl__DOT__waddr_lat;
    __Vdly__axi4_lite_ctrl__DOT__waddr_lat = 0;
    CData/*1:0*/ __Vdly__axi4_lite_ctrl__DOT__wstate;
    __Vdly__axi4_lite_ctrl__DOT__wstate = 0;
    IData/*31:0*/ __Vdly__axi4_lite_ctrl__DOT__raddr_lat;
    __Vdly__axi4_lite_ctrl__DOT__raddr_lat = 0;
    CData/*1:0*/ __Vdly__axi4_lite_ctrl__DOT__rstate;
    __Vdly__axi4_lite_ctrl__DOT__rstate = 0;
    // Body
    __Vdly__axi4_lite_ctrl__DOT__raddr_lat = vlSelfRef.axi4_lite_ctrl__DOT__raddr_lat;
    __Vdly__axi4_lite_ctrl__DOT__rstate = vlSelfRef.axi4_lite_ctrl__DOT__rstate;
    __Vdly__axi4_lite_ctrl__DOT__waddr_lat = vlSelfRef.axi4_lite_ctrl__DOT__waddr_lat;
    __Vdly__axi4_lite_ctrl__DOT__wstate = vlSelfRef.axi4_lite_ctrl__DOT__wstate;
    if (vlSelfRef.rst_n) {
        vlSelfRef.arready = 0U;
        if ((0U == (IData)(vlSelfRef.axi4_lite_ctrl__DOT__rstate))) {
            vlSelfRef.rvalid = 0U;
            if (vlSelfRef.arvalid) {
                __Vdly__axi4_lite_ctrl__DOT__raddr_lat 
                    = vlSelfRef.araddr;
                vlSelfRef.arready = 1U;
                __Vdly__axi4_lite_ctrl__DOT__rstate = 2U;
            }
        } else if ((2U == (IData)(vlSelfRef.axi4_lite_ctrl__DOT__rstate))) {
            vlSelfRef.arready = 0U;
            vlSelfRef.rvalid = 1U;
            vlSelfRef.rresp = 0U;
            vlSelfRef.rdata = ((0U == vlSelfRef.axi4_lite_ctrl__DOT__raddr_lat)
                                ? vlSelfRef.axi4_lite_ctrl__DOT__ctrl_reg
                                : ((4U == vlSelfRef.axi4_lite_ctrl__DOT__raddr_lat)
                                    ? (IData)(vlSelfRef.done)
                                    : 0xdeadbeefU));
            if (vlSelfRef.rready) {
                vlSelfRef.rvalid = 0U;
                __Vdly__axi4_lite_ctrl__DOT__rstate = 0U;
            }
        } else {
            __Vdly__axi4_lite_ctrl__DOT__rstate = 0U;
        }
        vlSelfRef.awready = 0U;
        vlSelfRef.wready = 0U;
        if ((1U & vlSelfRef.axi4_lite_ctrl__DOT__ctrl_reg)) {
            vlSelfRef.axi4_lite_ctrl__DOT__ctrl_reg 
                = (0xfffffffeU & vlSelfRef.axi4_lite_ctrl__DOT__ctrl_reg);
        }
        if ((0U == (IData)(vlSelfRef.axi4_lite_ctrl__DOT__wstate))) {
            vlSelfRef.bvalid = 0U;
            if (vlSelfRef.awvalid) {
                __Vdly__axi4_lite_ctrl__DOT__waddr_lat 
                    = vlSelfRef.awaddr;
                vlSelfRef.awready = 1U;
                __Vdly__axi4_lite_ctrl__DOT__wstate = 2U;
            }
        } else if ((2U == (IData)(vlSelfRef.axi4_lite_ctrl__DOT__wstate))) {
            vlSelfRef.awready = 0U;
            if (vlSelfRef.wvalid) {
                vlSelfRef.wready = 1U;
                if ((0U == vlSelfRef.axi4_lite_ctrl__DOT__waddr_lat)) {
                    vlSelfRef.axi4_lite_ctrl__DOT__ctrl_reg 
                        = vlSelfRef.wdata;
                }
                __Vdly__axi4_lite_ctrl__DOT__wstate = 3U;
            }
        } else if ((3U == (IData)(vlSelfRef.axi4_lite_ctrl__DOT__wstate))) {
            vlSelfRef.wready = 0U;
            vlSelfRef.bvalid = 1U;
            vlSelfRef.bresp = 0U;
            if (vlSelfRef.bready) {
                vlSelfRef.bvalid = 0U;
                __Vdly__axi4_lite_ctrl__DOT__wstate = 0U;
            }
        } else {
            __Vdly__axi4_lite_ctrl__DOT__wstate = 0U;
        }
    } else {
        __Vdly__axi4_lite_ctrl__DOT__rstate = 0U;
        vlSelfRef.arready = 0U;
        vlSelfRef.rvalid = 0U;
        vlSelfRef.rdata = 0U;
        vlSelfRef.rresp = 0U;
        __Vdly__axi4_lite_ctrl__DOT__raddr_lat = 0U;
        vlSelfRef.axi4_lite_ctrl__DOT__ctrl_reg = 0U;
        __Vdly__axi4_lite_ctrl__DOT__wstate = 0U;
        vlSelfRef.awready = 0U;
        vlSelfRef.wready = 0U;
        vlSelfRef.bvalid = 0U;
        vlSelfRef.bresp = 0U;
        __Vdly__axi4_lite_ctrl__DOT__waddr_lat = 0U;
    }
    vlSelfRef.axi4_lite_ctrl__DOT__raddr_lat = __Vdly__axi4_lite_ctrl__DOT__raddr_lat;
    vlSelfRef.axi4_lite_ctrl__DOT__rstate = __Vdly__axi4_lite_ctrl__DOT__rstate;
    vlSelfRef.axi4_lite_ctrl__DOT__waddr_lat = __Vdly__axi4_lite_ctrl__DOT__waddr_lat;
    vlSelfRef.axi4_lite_ctrl__DOT__wstate = __Vdly__axi4_lite_ctrl__DOT__wstate;
    vlSelfRef.start = (1U & vlSelfRef.axi4_lite_ctrl__DOT__ctrl_reg);
}

void Vaxi4_lite_ctrl___024root___eval_triggers__act(Vaxi4_lite_ctrl___024root* vlSelf);

bool Vaxi4_lite_ctrl___024root___eval_phase__act(Vaxi4_lite_ctrl___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_lite_ctrl___024root___eval_phase__act\n"); );
    Vaxi4_lite_ctrl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vaxi4_lite_ctrl___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vaxi4_lite_ctrl___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vaxi4_lite_ctrl___024root___eval_phase__nba(Vaxi4_lite_ctrl___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_lite_ctrl___024root___eval_phase__nba\n"); );
    Vaxi4_lite_ctrl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vaxi4_lite_ctrl___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi4_lite_ctrl___024root___dump_triggers__nba(Vaxi4_lite_ctrl___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi4_lite_ctrl___024root___dump_triggers__act(Vaxi4_lite_ctrl___024root* vlSelf);
#endif  // VL_DEBUG

void Vaxi4_lite_ctrl___024root___eval(Vaxi4_lite_ctrl___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_lite_ctrl___024root___eval\n"); );
    Vaxi4_lite_ctrl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vaxi4_lite_ctrl___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/axi4_lite_ctrl.sv", 30, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vaxi4_lite_ctrl___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/axi4_lite_ctrl.sv", 30, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vaxi4_lite_ctrl___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vaxi4_lite_ctrl___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vaxi4_lite_ctrl___024root___eval_debug_assertions(Vaxi4_lite_ctrl___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi4_lite_ctrl___024root___eval_debug_assertions\n"); );
    Vaxi4_lite_ctrl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.awvalid & 0xfeU)))) {
        Verilated::overWidthError("awvalid");}
    if (VL_UNLIKELY(((vlSelfRef.wvalid & 0xfeU)))) {
        Verilated::overWidthError("wvalid");}
    if (VL_UNLIKELY(((vlSelfRef.wstrb & 0xf0U)))) {
        Verilated::overWidthError("wstrb");}
    if (VL_UNLIKELY(((vlSelfRef.bready & 0xfeU)))) {
        Verilated::overWidthError("bready");}
    if (VL_UNLIKELY(((vlSelfRef.arvalid & 0xfeU)))) {
        Verilated::overWidthError("arvalid");}
    if (VL_UNLIKELY(((vlSelfRef.rready & 0xfeU)))) {
        Verilated::overWidthError("rready");}
    if (VL_UNLIKELY(((vlSelfRef.done & 0xfeU)))) {
        Verilated::overWidthError("done");}
}
#endif  // VL_DEBUG
