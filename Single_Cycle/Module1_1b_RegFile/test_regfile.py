'''Simply use random write on address 3, read after each write on both address, then compare to theoretical perfect state update in software'''
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import random
import numpy as np

@cocotb.test()
async def random_write_read_test(dut):
    #Start a 10ns clock
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    await RisingEdge(dut.clk)
    
    #Init and reset
    dut.rst_n.value = 0
    dut.write_enable.value = 0
    dut.write_data.value = 0
    dut.rs1.value = 0
    dut.rs2.value = 0
    dut.rs3.value = 0
    
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1 #Release rst_n
    await RisingEdge(dut.clk)
    
    #fill a theoretical state of registers, all initialized to 0
    theoretical_regs = [0 for x in range(32)]
    
    #Loop to write and read random balues, 1000 test cases
    for x in range(1000):
        #Generate a random register address (1 to 31, skip 0)
        rs1 = random.randint(1, 31)
        rs2 = random.randint(1, 31)
        rs3 = random.randint(1, 31)
        write_value = random.randint(0, 0xFFFFFFFF) #Random
        
        #Perform read of address
        await Timer(1, units="ns") # wait 1ns to test async read combinational logic
        dut.rs1.value = rs1
        dut.rs2.value = rs2
        await Timer(1, units="ns") # wait 1ns to test async read combinational logic
        assert dut.read_data1.value == theoretical_regs[rs1], f"Read data 1 mismatch at iteration {x}: expected {theoretical_regs[rs1]}, got {dut.read_data1.value}"
        assert dut.read_data2.value == theoretical_regs[rs2], f"Read data 2 mismatch at iteration {x}: expected {theoretical_regs[rs2]}, got {dut.read_data2.value}"
        
        #Perform a random write operation
        dut.rs3.value = rs3
        dut.write_enable.value = 1
        dut.write_data.value = write_value #Random address value
        await RisingEdge(dut.clk)
        dut.write_enable.value = 0
        theoretical_regs[rs3] = write_value #Update theoretical state
        await Timer(1, units="ns")
        
        
    #Try to write at 0 and check if its still 0
    await Timer(1, units="ns")
    dut.rs3.value = 0
    dut.write_enable.value = 1
    dut.write_data.value = 0xAEAEAEAE
    await RisingEdge(dut.clk)
    dut.write_enable.value = 0
    theoretical_regs[rs3] = 0
    
    await Timer(1, units="ns") #testing asynch read
    dut.rs1.value = 0
    await Timer(1, units="ns")
    print(dut.read_data1.value)
    assert int(dut.read_data1.value) == 0
    
    print("Random write/read operation test completed successfully!")