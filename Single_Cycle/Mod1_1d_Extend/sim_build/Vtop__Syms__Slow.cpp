// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(124);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_signextend = new VerilatedScope{this, "signextend", "signextend", "signextend", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_signextend);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("imm_source", &(TOP.imm_source), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("immediate", &(TOP.immediate), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("raw_input", &(TOP.raw_input), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,24,0);
    __Vscopep_signextend->varInsert("gathered_imm", &(TOP.signextend__DOT__gathered_imm), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,11,0);
    __Vscopep_signextend->varInsert("imm_source", &(TOP.signextend__DOT__imm_source), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_signextend->varInsert("immediate", &(TOP.signextend__DOT__immediate), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_signextend->varInsert("raw_input", &(TOP.signextend__DOT__raw_input), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,24,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_signextend);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_signextend, __Vscopep_signextend = nullptr);
    // Tear down sub module instances
}
