
# Assignment_10

## Problem Statement:-

Multiplication by rotation and addition.


### Code_1 :- multiplication.asm

The code demonstrates how to implement multiplication by rotation and addition on the x86 microprocessor. 
The program takes two input values, eax and ebx, and multiplies them by rotating ebx left and adding it to eax for each set bit in eax. 
The result is stored in eax.

The program first sets up the input values, then initializes the necessary registers. It uses a loop to iterate through each bit in eax, 
checking if the bit is set and adding ebx to eax if it is. After processing all the bits, the result is outputted using a system call.

### Run the Program- Code_1:-  multiplication.asm

	# Assemble the code
	nasm -f elf32 multiplication.asm -o multiplication.o

	# Link the object file
	ld -m elf_i386 multiplication.o -o multiplication

	# Run the executable:
	./multiplication
	

