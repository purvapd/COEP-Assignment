
# Assignment_12

## Problem Statement:-

Perform the following operations on a string: Find the length of a string and Reverse a string, Concatenate two strings and Compare two strings, 
Search a string for a given substring, Change the case of the string, Copy from one string to another string , Check whether the 
given string is a palindrome


### Code_1 :- len_str.asm

 It declares a data segment with the string "Hello, world!" and a terminating null character. The code segment loads the data segment address, 
 points DS to the data segment, loads SI with the offset of the string, clears the CX register, compares each byte at SI to the null character, 
 increments SI to point to the next byte, increments CX to count the string length, and continues looping until the end of the string is reached.
 Finally, the length of the string is stored in CX and any necessary operations can be performed.
 

### Code_2 :- reverse_str.asm

The code declares a string "Hello, world!" and a variable to hold its length. It then uses a loop to determine the length of the string and
reverses the string by swapping characters using another loop. The resulting code will reverse the original string "Hello, world!" to "!dlrow ,olleH".

### Code_3 :- concat_str.asm

code that declares two strings, "Hello" and "world!", and a result buffer with 32 bytes. It then loads the data segment address into the AX register, 
points DS to the data segment, and loads the offsets of the first string and the result buffer into the SI and DI registers, respectively. 
It then copies the contents of the first string into the result buffer byte-by-byte using the MOV instruction and increments the SI register 
until it reaches the end of the first string.

### Code_4 :- compare_str.asm

Code is used to compare two strings, STRING1 and STRING2, to see if they are equal. The DATA segment declares the two strings with a terminating
null character. The CODE segment then loads the data segment address, points to the data segment, loads the offsets of the two strings, and compares
the bytes of each string using a loop. If the strings are equal, the code will perform necessary operations, and if not, it will also perform 
necessary operations. The program then ends by jumping to END_COMPARE.

### Code_5 :- change_str.asm

In the DATA segment, two strings are declared, one with the phrase "The quick brown fox jumps over the lazy dog" and another with "Hello, world!".
In the CODE segment, there are two separate blocks of code. The first block changes the case of each character in the first string to its 
opposite case.
The second block searches for a substring within the first string and saves the offset of the first matching character in DX. If no match is found, 
DX is set to 0.

### Code_6 :- search_str.asm

It converts the case of characters in a string from lowercase to uppercase and vice versa. It first declares a string 'Hello, world!' in the 
data segment and initializes the data segment pointer. It then uses a loop to iterate through each character in the string and checks if it is a 
lowercase or uppercase character. If it is lowercase, it converts it to uppercase and vice versa using ASCII arithmetic. Finally, it stores the 
converted character back into the string.


### Code_7 :- copy_str.asm

It declares two strings - SOURCE and DEST - within the DATA SEGMENT. The program then copies the SOURCE string to the DEST string using a loop 
that runs until the maximum length of DEST (20) is reached or the null character is encountered in the SOURCE string. The program ends after the
copy operation is complete.

### Code_8 :- palindrome_str.asm

. The string "racecar" is declared in the data segment, and the program uses a loop to check each character of the string for symmetry. If the 
string is found to be a palindrome, the program jumps to the "PALINDROME" label, and if not, it jumps to the "NOT_PALINDROME" label. At the end
of the program, it jumps to the "END_PROGRAM" label to terminate the program.

### Run the Program- code:- File Name.asm

	# Assemble the code
	nasm -f elf32 <File Name>.asm -o <File Name>.o

	# Link the object file
	ld -m elf_i386 <File Name>.o -o <File Name>

	# Run the executable:
	./<File Name>
	



