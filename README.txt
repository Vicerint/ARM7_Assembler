Code written by: Michael Agnew
CPE 221/01
11/28/2023

Instructions for running "ARM.cpp"

Open up the program in an IDE for C++ of your choice.

It should be able to run automatically, but if not, compile it using the makefile that is provided. Simply type "make" and the program along with its header and main.cpp file will compile together. This makefile will produce an executable named "Assembler" which can be run to fully execute the code. Simply type "./Assembler" into the terminal and the code will be run. If you would like to clear the executable and uncompile the code then type "make clean" into the terminal and this will delete the executable. In order to recompile the code simply type "make" again.

If the makefile provided does not work, then the following command may be used to compile the code: 
g++ -std=c++11 ARM.cpp main.cpp ARM.h -o Assembler (c++11 must be used for this compilation)

After this code is run, the program will compile and "./Assembler" can be utilized to run the program.


After the code is run, you will be prompted for a <.s> input file. Input the file of your choice as long as it follows the given parameters.

The code will then take this file and all of the ARM instructions located in it and convert them to Hexadecimal machine code.

This hex machine code is then output to an output file called "output.s" which is where all of the output can be found for the given input file. 

