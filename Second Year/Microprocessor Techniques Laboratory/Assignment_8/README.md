
# Assignment_8

## Problem Statement:-

Finding the 1‟s and 2‟s complement of a given number.


### Code_1 :- 1st_complement.asm

The 1's complement code written above is an assembly language program for the X86 microprocessor that takes a 16-bit integer i
nput from the user and finds its 1's complement. The program first prompts the user for input and reads in the value using the Linux system calls. 
It then finds the 1's complement of the input by performing a bitwise NOT operation on the value. Finally, it displays the output to the user
using the Linux system calls and exits the program.

### Code_2 :- 2nd_complement.asm

The program starts by displaying a prompt to the user asking for a 16-bit integer input. It then reads the input from the user and stores
it in a variable called "input."
Next, the program uses the "neg" instruction to find the 2's complement of the input, which is equivalent to taking the 1's complement of 
the input and adding one.
After finding the 2's complement, the program displays the result to the user by first displaying a message "2's complement: " and 
then printing the result to the console. Finally, the program exits using the "exit" system call.

### Run the Program- Code_1:-  1st_complement.asm

	# Assemble the code
	nasm -f elf32 1st_complement.asm -o 1st_complement.o

	# Link the object file
	ld -m elf_i386 1st_complement.o -o 1st_complement

	# Run the executable:
	./1st_complement
	
### Run the Program- Code_2:-  2nd_complement.asm

	# Assemble the code
	nasm -f elf32 2nd_complement.asm -o 2nd_complement.o

	# Link the object file
	ld -m elf_i386 2nd_complement.o -o 2nd_complement

	# Run the executable:
	./2nd_complement

