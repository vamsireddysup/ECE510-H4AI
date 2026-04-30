// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VFP4_MUL__SYMS_H_
#define VERILATED_VFP4_MUL__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vfp4_mul.h"

// INCLUDE MODULE CLASSES
#include "Vfp4_mul___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vfp4_mul__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vfp4_mul* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vfp4_mul___024root             TOP;

    // CONSTRUCTORS
    Vfp4_mul__Syms(VerilatedContext* contextp, const char* namep, Vfp4_mul* modelp);
    ~Vfp4_mul__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
