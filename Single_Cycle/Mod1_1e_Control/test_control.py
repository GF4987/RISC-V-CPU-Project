import cocotb
from cocotb.triggers import Timer
import random
from cocotb import BinaryValue

@cocotb.coroutine()
async def set_unknown(dut):
    #for future use
    await Timer(1, units="ns")
    dut.op.value = BinaryValue("XXXXXXX")
    #
    # Uncomment the following throughout the course when needed
    #
    # dut.func3.value = BinaryValue("XXX")
    # dut.func7.value = BinaryValue("XXXXXXX")
    # dut.alu_zero.value = BinaryValue("X")
    # dut.alu_last_bit.value = BinaryValue("X")
    await Timer(1, units="ns")
    
@cocotb.test()
async def control_test(dut):
    await set_unknown(dut)
    #Test control signals for LW instruction
    await Timer(1, units="ns")
    dut.op.value = 0b000011 #lw instruction
    await Timer(1, units="ns")
    assert dut.alu_control.value == "000"
    assert dut.imm_source.value == "00"
    assert dut.mem_write.value == "0"
    assert dut.reg_write.value == "1"
    
    