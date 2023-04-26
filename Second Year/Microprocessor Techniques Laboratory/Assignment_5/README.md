
# Assignment_5

## Problem Statement:-

Finding the factorial of a given number.


### Code_1 :- factorial.asm

The assembly program provided calculates the factorial of a given number using a loop on an x86 microprocessor. 
It uses NASM syntax and assumes a 32-bit architecture. The program loads the number to calculate into a register and 
initializes the result to 1. It then enters a loop that multiplies the result by the current number and decrements the number 
until it becomes zero. The final factorial result is stored in memory and printed to the standard output using a custom print_word function.
The program exits with a return code of 0 using a system call.


### Run the Program- Code_1:- factorial.asm

	# Assemble the code	
  	nasm -f elf32 factorial.asm -o factorial.o

	# Link the object file	
  	ld -m elf_i386 factorial.o -o factorial

	# Run the executable:	
  	./factorial

