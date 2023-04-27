
# Assignment_13

## Problem Statement:-

DAC - Generate Ramp, Triangle, Square, Sine waveform

### Code_1 :- DAC.asm

### Run the Program- code:-  <File Name>.asm

	# Assemble the code
	nasm -f elf32 <File Name>.asm -o <File Name>.o

	# Link the object file
	ld -m elf_i386 <File Name>.o -o <File Name>

	# Run the executable:
	./<File Name>
	


