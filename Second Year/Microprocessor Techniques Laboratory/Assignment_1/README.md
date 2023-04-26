
# Assignment_1

## Problem Statement:-

Implement Block data Transfer , Exchange Overlapping and non-overlapping blocks.


### Code :- block_data_transfer.asm

Here's an example of an assembly program for the x86 microprocessor that implements block data transfer using overlapping
and non-overlapping blocks. This program uses the MOVSB (move byte from ES:[SI] to ES:[DI]) instruction for block data transfer.

This program demonstrates two scenarios 
- one with overlapping blocks where the source and destination buffers share some bytes, 
- one with non-overlapping blocks where the source and destination buffers do not share any bytes. 
The rep movsb instruction is used to perform block data transfer, and the cld instruction is used to clear the direction flag for forward movement. 
The program uses the x86 assembly syntax and assumes the use of Linux or a compatible operating system for system calls. 
Please note that actual implementation details may vary depending on the specific x86 microprocessor architecture and operating system used.


### Run the Program

	```nasm -f elf32 block_data_transfer.asm -o block_data_transfer.o

	ld -m elf_i386 block_data_transfer.o -o block_data_transfer

	./block_data_transfer

```python
# Example Python Code with Syntax Highlighting and Line Numbers

```python
