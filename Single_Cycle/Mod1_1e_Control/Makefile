# Design configuration
#The top-level system verilog module name (must match the .sv module name)
TOPLEVEL = control

#List all your .sv source files here (space-separated if multiple)
VERILOG_SOURCES = $(PWD)/control.sv

#Testbench configuratiion
#The python testbench file without .py extension
MODULE = test_control

#---Simulator
#optionsL icarus, verilator, xelium, questa, modelsim
SIM = verilator

#Use System Verilog instead of Verilog
TOPLEVEL_LANG = verilog
EXTRA_ARGS += --sv --trace -Wall #tells verilator to use systemverilog syntax and generate a waveform

#Waveform dumping (optional, for debugging)
#Uncommment to generate a .vcd file you can open in GTKWave
COCOTB_ENABLE_PROFILING = 1
export CXXFLAGS = -std=c++14 #always include this line for verilator clang++ compiler flags
COMPILE_ARGS += --timescale 1ns/1ps
CXX = clang++

#---cocotb boilerplate configuration
#finds and includes the cocotb core Makefile rules
#This should be the last line in the file always
include $(shell cocotb-config --makefiles)/Makefile.sim


#---Optional convenience targets
# 'make waves' will generate a waveform file for GTKWave with the dump file
waves:
	gtkwave dump.vcd &

# 'make clean_all' will remove ALL generated artefacts including cocotb logs
clean_all: clean
	rm -rf __pycache__ results.xml dump.vcd sim_build/
