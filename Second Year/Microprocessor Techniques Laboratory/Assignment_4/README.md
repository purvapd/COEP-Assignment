
# Assignment_4

## Problem Statement:-

8/16/32 bit addition, 8/16/32 bit subtraction, multiplication, division


### Code_1 :- 8_bit.asm
### Code_2 :- 16_bit.asm
### Code_3 :- 32_bit.asm

Addition: The addition operation involves adding two numbers together. In assembly language, the operands are 
loaded into appropriate registers, such as AL, BL, AX, BX, EAX, or EBX, and the add instruction is used to perform the addition. 
The result is stored in the destination register or memory location.

Subtraction: The subtraction operation involves subtracting one number from another. Similarly, the operands are loaded into 
registers, and the sub instruction is used to perform the subtraction. The result is stored in the destination register or memory location.

Multiplication: The multiplication operation involves multiplying two numbers. The operands are loaded into registers, and the mul or
imul instruction is used to perform the multiplication. The result is usually stored in a pair of registers, such as AX/DX:AX or EAX/EDX:EAX,
which represent the high and low parts of the result.

Division: The division operation involves dividing one number by another. The operands are loaded into registers, and the div or idiv instruction 
is used to perform the division. The quotient and remainder are usually stored in registers, such as AL/AH or AX/DX, or EAX/EDX, respectively.

It's important to consider the data sizes (8-bit, 16-bit, or 32-bit) and signed vs. unsigned numbers when developing these assembly programs.

### Run the Program- Code_1:- 8_bit.asm

	# Assemble the code
	nasm -f elf32 8_bit.asm -o 8_bit.o

	# Link the object file
	ld -m elf_i386 8_bit.o -o 8_bit

	# Run the executable:
	./8_bit

### Run the Program- Code_2:-16_bit.asm

	# Assemble the code
	nasm -f elf32 16_bit.asm -o 16_bit.o

	# Link the object file
	ld -m elf_i386 16_bit.o -o 16_bit

	# Run the executable:
	./16_bit
	
### Run the Program- Code_3:-32_bit.asm

	# Assemble the code
	nasm -f elf32 32_bit.asm -o 32_bit.o

	# Link the object file
	ld -m elf_i386 32_bit.o -o 32_bit

	# Run the executable:
	./32_bit
