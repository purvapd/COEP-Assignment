
# Assignment_13

## Problem Statement:-

Interface the following with the 8086: -
8255, 8253, 8259, 8251


### Code_1 :- 8255.asm

To interface the 8255 with the 8086, the following steps can be followed:

Connect the data bus of the 8255 to the data bus of the 8086.
Connect the address bus of the 8255 to the address bus of the 8086.
Connect the control signals of the 8255 to the control signals of the 8086.
Here is an example assembly program that reads data from port A of the 8255 and writes it to memory:

In this example, the port A address of the 8255 is set to 0x00. The control word is set to 0x80, which sets the mode of port A to input. 
The control word is written to the 8255 using the OUT instruction.

The data from port A is then read using the IN instruction and stored in the AL register. The destination memory address is set to 0x1000, 
and the data is written to memory using the MOV instruction.
 
### Code_2 :- 8253.asm

The 8253 Programmable Interval Timer (PIT) is a device that can be used to generate accurate timing signals in a computer system. It can be 
interfaced with the 8086 microprocessor through its I/O ports.

In this example program, we first load the control word 34h into the AL register and send it to the timer through the OUT instruction 
to port 43h. This sets the timer to mode 2 (rate generator) and sets the counting interval to be based on the clock frequency divided by 
1, which is 1.19318 MHz.

Next, we load an initial count value of 0B00h into the AX register and send the LSB and MSB of the count to the timer through the OUT
instruction to port 40h. This sets the timer to count down from 0B00h, which is 2,048 in decimal.

We then enter a loop where we read the status of the timer through the IN instruction from port 40h, AND the result with 1 to check if the 
timer has expired, and jump back to the loop if the timer has not yet expired. Once the timer has expired, we simply return from the program.

### Code_3 :- 8259.asm

To interface the 8259 Programmable Interrupt Controller with the 8086 microprocessor, the following steps can be followed:

Connect the Interrupt Request (IRQ) lines of the devices to the corresponding IRQ inputs of the 8259.
Connect the Interrupt Service Routine (ISR) of the 8086 to the Interrupt Vector Table (IVT) of the 8259.
Initialize the 8259 by sending appropriate initialization commands and masks.
Enable or disable the interrupts as required by the program.

### Code_4 :- 8251.asm

The 8251 is a programmable communication interface chip that can be used to implement a variety of serial communication protocols. The 8086
is a microprocessor that is part of the x86 family of processors. To interface the 8251 with the 8086, we need to use the appropriate 
input/output instructions and memory-mapped I/O (MMIO) addresses.

To receive data from the serial device, we can use the IN instruction to read the data from the 8251's data register:


### Run the Program- code:-  <File Name>.asm

	# Assemble the code
	nasm -f elf32 <File Name>.asm -o <File Name>.o

	# Link the object file
	ld -m elf_i386 <File Name>.o -o <File Name>

	# Run the executable:
	./<File Name>
	



