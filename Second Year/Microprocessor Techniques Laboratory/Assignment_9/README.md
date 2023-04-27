
# Assignment_9

## Problem Statement:-

Check whether a number is even or odd.


### Code_1 :- even_odd.asm

In this program, we first move the number we want to test into the AX register. Then, we use the TEST instruction to test the 
LSB of AX. If the LSB is 0 (even), the zero flag (ZF) is set, and we jump to the even label. If the LSB is 1 (odd), the ZF flag is cleared, 
and we fall through to the next instruction.

In the even and odd sections of the code, you can add any additional code you want to handle even and odd numbers, respectively.

Finally, the program exits using the exit system call.


### Run the Program- Code_1:-  even_odd.asm

	# Assemble the code
	nasm -f elf32 even_odd.asm -o even_odd.o

	# Link the object file
	ld -m elf_i386 even_odd.o -o even_odd

	# Run the executable:
	./even_odd
	

