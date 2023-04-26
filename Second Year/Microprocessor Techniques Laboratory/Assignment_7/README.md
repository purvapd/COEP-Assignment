
# Assignment_7

## Problem Statement:-

Performing - (a + b) * (c + d) and (a * b) + (c * d).


### Code_1 :- example_1.asm
Assembly program for (a + b) * (c + d):

### Code_2 :- example_2.asm
Assembly program for (a * b) + (c * d):

These assembly programs are written for a 16-bit X86 microprocessor and use the NASM syntax. The imul instruction is used for signed multiplication, while mul instruction can be used for unsigned multiplication. The result is stored in a memory variable result in both programs. The program uses the Linux system call exit with code 1 to terminate the program. Please ensure to assemble and run these programs on a compatible system with the appropriate permissions.

### Run the Program- Code_1:-  example_1.asm

	# Assemble the code
	nasm -f elf32 example_1.asm -o example_1.o

	# Link the object file
	ld -m elf_i386 example_1.o -o example_1

	# Run the executable:
	./example_1
	
### Run the Program- Code_2:-  example_2.asm

	# Assemble the code
	nasm -f elf32 example_2.asm -o example_2.o

	# Link the object file
	ld -m elf_i386 example_2.o -o example_2

	# Run the executable:
	./example_2

