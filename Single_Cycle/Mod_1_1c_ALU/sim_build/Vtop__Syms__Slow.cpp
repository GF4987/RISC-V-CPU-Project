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
    __Vscopep_alu = new VerilatedScope{this, "alu", "alu", "alu", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_alu);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("alu_control", &(TOP.alu_control), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_TOP->varInsert("alu_result", &(TOP.alu_result), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("operand1", &(TOP.operand1), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("operand2", &(TOP.operand2), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("zero", &(TOP.zero), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_alu->varInsert("alu_control", &(TOP.alu__DOT__alu_control), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_alu->varInsert("alu_result", &(TOP.alu__DOT__alu_result), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_alu->varInsert("operand1", &(TOP.alu__DOT__operand1), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_alu->varInsert("operand2", &(TOP.alu__DOT__operand2), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_alu->varInsert("zero", &(TOP.alu__DOT__zero), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_alu);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_alu, __Vscopep_alu = nullptr);
    // Tear down sub module instances
}
