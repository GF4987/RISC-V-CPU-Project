import cocotb
from cocotb.triggers import Timer
import random

@cocotb.test()
async def add_test(dut):
    '''Test the Add operation of the ALU'''
    await Timer(1, units="ns")
    dut.alu_control.value = 0b000 #000 corresponds to add
    for x in range(1000):
        operand1 = random.randint(0, 0xFFFFFFFF)
        operand2 = random.randint(0, 0xFFFFFFFF)
        dut.operand1.value = operand1
        dut.operand2.value = operand2
        #mask the expected result to not take account of overflow
        expected = (operand1 + operand2) & 0xFFFFFFFF
        #wait 1ns for results to propagate
        await Timer(1, units="ns")
        assert int(dut.alu_result.value) == expected

'''These tests will be improved on later'''       
@cocotb.test()
async def default_test(dut):
    await Timer(1, units="ns")
    dut.alu_control.value = 0b111
    src1 = random.randint(0,0xFFFFFFFF)
    src2 = random.randint(0,0xFFFFFFFF)
    dut.src1.value = src1
    dut.src2.value = src2
    expected = 0
    # Await 1 ns for the infos to propagate
    await Timer(1, units="ns")
    assert int(dut.alu_result.value) == expected
    
@cocotb.test()
async def zero_test(dut):
    await Timer(1, units="ns")
    dut.alu_control.value = 0b000
    dut.src1.value = 123
    dut.src2.value = -123
    await Timer(1, units="ns")
    print(int(dut.alu_result.value))
    assert int(dut.zero.value) == 1
    assert int(dut.alu_result.value) == 0