
# Assignment_6

## Problem Statement:-

Finding the Fibonacci series of n terms.


### Code_1 :- fibonacci.asm

The code implements a program that calculates and prints the Fibonacci series up to n terms for the x86 microprocessor. 
It uses the system calls read and write to read input (n) from the user and print the Fibonacci series. T
he program starts by reading input (n) from the user and initializing variables for the first two terms of the Fibonacci series. 
It then prints the header and the first two terms of the series.

Next, the program enters a loop that calculates and prints the remaining terms of the Fibonacci series using a basic iterative approach. 
It uses registers (eax, ebx, ecx, edx, esi) to store intermediate results and perform arithmetic operations. The calculated terms are 
converted to ASCII and printed using the write system call. The loop continues until the desired number of terms (n) is reached.

After printing the Fibonacci series, a newline character is printed, and the program exits with a status code of 0 using the exit system call.


### Run the Program- Code_1:- fibonacci.asm

```bash
# Assemble the code
nasm -f elf32 fibonacci.asm -o fibonacci.o

# Link the object file
ld -m elf_i386 fibonacci.o -o fibonacci

# Run the executable:
./fibonacci

