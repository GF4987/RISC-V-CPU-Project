# RISC-V CPU (RV32I) Implementation

This repository contains a custom implementation of a **RISC-V-based CPU core** targeting the RV32I instruction set architecture. The design is written in Verilog/SystemVerilog and is structured to be modular, extensible, and suitable for future hardware acceleration extensions.

---

## Overview

The goal of this project is to build a functional single-core RISC-V processor and extend it with hardware accelerators for compute-heavy workloads.

The current implementation focuses on:
- RV32I base integer instruction set
- Basic pipeline architecture (fetch, decode, execute, memory, writeback)
- Simple memory interface (non-AXI, direct mapped)
- Register file and ALU design
- Testbench-driven verification

Future extensions will introduce:
- AXI-compatible memory subsystem
- Memory-mapped custom accelerator units
- Hardware dot-product engine for vector/matrix operations

---

## Architecture

The CPU follows a classic modular datapath:

### 1. Instruction Fetch (IF)
- Program counter (PC) updates sequentially or via branch/jump logic
- Instruction memory interface (currently direct read)

### 2. Instruction Decode (ID)
- Decodes RV32I instruction formats (R, I, S, B, U, J)
- Generates control signals
- Reads source registers from register file

### 3. Execute (EX)
- ALU operations (ADD, SUB, AND, OR, XOR, shifts, comparisons)
- Branch decision logic
- Immediate handling

### 4. Memory (MEM)
- Load/store operations
- Byte/halfword/word access support (in progress depending on implementation)

### 5. Writeback (WB)
- Writes results back to register file

---

## Memory System

The current memory model is a simplified direct-mapped interface intended for simulation and early-stage FPGA testing.

Planned upgrades include:
- AXI4-Lite / AXI4 full interface
- Cache layer (optional future extension)
- Memory-mapped peripheral support

---

## Future Work: AXI + Dot-Product Accelerator

### 1. AXI Memory Subsystem

A major planned upgrade is migration to an **AXI-compatible bus architecture**.

This will enable:
- Standardized communication with external memory
- Integration with FPGA IP cores (DDR controllers, BRAM, etc.)
- Easier scalability for multi-module SoC design

Proposed structure:
- AXI Master Interface (CPU core)
- AXI Interconnect
- AXI Slave peripherals (memory, accelerators)

---

### 2. Memory-Mapped Dot-Product Unit

A custom **dot-product accelerator** will be added as a memory-mapped hardware unit.

#### Purpose
Accelerate:
- Machine learning inference kernels
- DSP operations
- Linear algebra workloads

#### Interface Design (planned)

The unit will be exposed via memory-mapped registers:

| Address Offset | Function |
|----------------|----------|
| 0x00           | Vector A base pointer |
| 0x04           | Vector B base pointer |
| 0x08           | Vector length |
| 0x0C           | Control (start/done) |
| 0x10           | Result output |

#### Execution Model
1. CPU writes vector addresses and length
2. Sets start bit in control register
3. Accelerator fetches data via AXI
4. Computes dot product in hardware pipeline
5. Writes result back to result register
6. Raises done flag / interrupt (future enhancement)

#### Hardware Design (planned)
- Fully pipelined multiply-accumulate (MAC) array
- Optional SIMD-style parallel lanes
- Streaming data interface over AXI

---

## Verification Strategy

Current and planned verification methods:
- SystemVerilog testbenches
- Directed tests for RV32I instruction coverage
- Randomized instruction sequences (future)
- Co-simulation with reference ISA models (future)

---

## Build & Simulation

Typical simulation flow (example):

```bash
# Compile (Icarus / Verilator / ModelSim depending on setup)
iverilog -o cpu_tb src/*.v tb/*.v

# Run simulation
vvp cpu_tb