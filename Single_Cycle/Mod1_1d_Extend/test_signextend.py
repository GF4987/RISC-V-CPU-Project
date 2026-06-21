import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Timer, RisingEdge
import random
import numpy as np

@cocotb.test()
async def random_write_read_test(dut):
    #Test a positive intermediate: 123 with source = 0
    imm = 0b000001111011 #123
    imm <<= 13 # Leave some extra bits for randomization
    source = 0b00
    #25 bits are sent to sign extend and it containts data that willl be ignored (rd, f3, etc)
    #masked to leave room for intermediate test data
    random_stuff = 0b000000000000_1010101010101
    raw_data = random_stuff | imm
    await Timer(1, units='ns')
    dut.raw_input.value = raw_data
    dut.imm_source.value = source
    await Timer(1, units='ns')
    assert dut.immediate.value.signed_integer == 123


    #Test a negative intermediate: -123 with source = 0
    imm = 0b111110000101 # -123
    imm <<= 13 # Leave some extra bits for randomization
    source = 0b00
    #25 bits are sent to sign extend and it containts data that willl be ignored (rd, f3, etc)
    #masked to leave room for intermediate test data
    random_stuff = 0b000000000000_1010101010101
    raw_data = random_stuff | imm
    await Timer(1, units='ns')
    dut.raw_input.value = raw_data
    dut.imm_source.value = source
    await Timer(1, units='ns')
    assert dut.immediate.value.signed_integer == -123