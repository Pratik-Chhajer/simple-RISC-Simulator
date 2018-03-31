# Functional Simulator for simpleRISC processor
The software runs a simpleRISC assembly code given in the form of Program Counter and proper encoded Instructions . The software is implemetation with as well as without pipeline.


## Directory Structure:
```bash
  |
  |- bin
      |
      |- mySimpleSim
  |- include
      |
      |- mySimpleSim.h
  |- src
      |- main.cpp
      |- Makefile
      |- mySimpleSim.cpp
  |- test
      |- fun.mem
      |- fibonacci.mem
      |- array_sum.mem
      |- loop.mem
      |- mov.mem
      |- power.mem
      |- square.mem
      |- call.mem
      |- n1.mem
```

## How to build
- For building:
  ```bash
	 $cd src
	 $make
  ```

- For cleaning the project:
  ```bash
	 $cd src
	 $make clean
  ```

## How to execute
```bash
$cd bin
./mySimpleSim "..test/array_sum.mem"
```
After that select choices accordingly.


## Limitations
- We have taken a maximum limit of 1000 instructions(4000 bytes) per code.
- Data memory is limited to 12000 bytes.
- Each register can hold an integer of size atmost 4 bytes.


## Output
After execution of each instruction the terminal shows value of - 
  - Program Counter
  - Instruction(For each stage in case of pipeline)
  - Registers from 0 to 15

A data_out.mem file is made after execution of the code in the bin directory which contains the entire memory of 4000 bytes having instructions and data memory.
