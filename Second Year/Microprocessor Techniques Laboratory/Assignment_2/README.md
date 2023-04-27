
# Assignment_2

## Problem Statement:-

Finding the smallest and largest number from a given list.


### Code_1 :- asm_program.asm

The given assembly code is for the x86 microprocessor and finds the smallest and largest numbers from a given list of integers. 
The list of integers is assumed to be stored in an array in memory, and the length of the array is known beforehand.

The code uses a loop to iterate through the list and compares the numbers to find the smallest and largest numbers.
It uses unsigned comparison instructions (ja, jb) to compare the numbers, and updates the smallest and largest numbers accordingly.

Once the smallest and largest numbers are found, they are stored in memory as ASCII values of characters for printing. 
Finally, the program uses DOS interrupts to print the smallest and largest numbers, and then exits with a return code of 0.


### Run the Program


```bash
# Assemble the code
nasm -f elf32 asm_program.asm -o asm_program.o



# Link the object file
ld -m elf_i386 asm_program.o -o asm_program

# Run the executable:
./asm_program




