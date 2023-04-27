
# Assignment_11

## Problem Statement:-

Matrix addition and subtraction.


### Code_1 :- mat_add.asm
### Code_2 :- mat_sub.asm

The examples assume that the matrices are 3x3 and are stored as arrays of 9 32-bit integers (i.e. each element is a 32-bit integer). 
The result matrix is also stored as an array of 9 32-bit integers. You may need to adjust the code if your matrices are a different size
or stored in a different format.

### Run the Program- Code_1:-  mat_add.asm

	# Assemble the code
	nasm -f elf32 mat_add.asm -o mat_add.o

	# Link the object file
	ld -m elf_i386 mat_add.o -o mat_add

	# Run the executable:
	./mat_add
	

### Run the Program- Code_2:-  mat_sub.asm

	# Assemble the code
	nasm -f elf32 mat_sub.asm -o mat_sub.o

	# Link the object file
	ld -m elf_i386 mat_sub.o -o mat_sub

	# Run the executable:
	./mat_sub

