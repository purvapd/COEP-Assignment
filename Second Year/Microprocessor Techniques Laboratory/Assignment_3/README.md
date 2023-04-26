
# Assignment_3

## Problem Statement:-

Arranging a given list in ascending and descending order


### Code_1 :- sort_ascending.asm

The assembly code provided earlier implements the Bubble Sort algorithm to sort a given list of integers in ascending order. 
It uses the x86 assembly language and assumes the list is stored in an array named arr and the number of integers in the list is 
stored in a variable named n. The code compares adjacent elements in the list and swaps them if they are in the wrong order, 
repeatedly until the entire list is sorted. The sorted list is then displayed using system calls for write to stdout.

### Run the Program

	# Assemble the code
	nasm -f elf32 sort_ascending.asm -o sort_ascending.o


	# Link the object file
	ld -m elf_i386 sort_ascending.o -o sort_ascending

	# Run the executable:
	./sort_ascending
	
	
### Code_2 :- sort_descending.asm

The provided assembly language code implements the Bubble Sort algorithm to sort a given list of integers in descending order. 
It starts by loading the number of integers and initializing loop counters. Then, it uses nested loops to compare adjacent elements 
in the list and swaps them if they are in the wrong order, effectively "bubbling" the largest value to the top in each pass. 
This process is repeated until the entire list is sorted in descending order. Finally, the sorted list is displayed using system calls.

### Run the Program

	# Assemble the code
	nasm -f elf32 sort_descending.asm -o sort_descending.o


	# Link the object file
	ld -m elf_i386 sort_descending.o -o sort_descending

	# Run the executable:
	./sort_descending



