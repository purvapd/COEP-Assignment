
# Assignment_3

## Problem Statement:-

Use gdb to read assembly code for C program to find factorial of a number with recursion 
and demonstrate how parameters are passed using pass by value. 

### Code_1 :- example.c
	
    This is example C program that calculates the factorial of a number using recursion:
    Now, let's use gdb (GNU Debugger) to read the assembly code and understand how the parameters are passed using pass-by-value.

### Run the program.

    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc -g -o example example.c

    VSK@DESKTOP-8LMS4JT MINGW64 ~

    gdb ./factorial

    VSK@DESKTOP-8LMS4JT MINGW64 ~

    break factorial

    VSK@DESKTOP-8LMS4JT MINGW64 ~

    run

    VSK@DESKTOP-8LMS4JT MINGW64 ~

    disassemble


    Dump of assembler code for function factorial:

    0x000055555555517d <+0>:     push   %rbp

    0x000055555555517e <+1>:     mov    %rsp,%rbp

    0x0000555555555181 <+4>:     sub    $0x10,%rsp

    0x0000555555555185 <+8>:     mov    %edi,-0x4(%rbp)   ; Save the value of n on the stack

    0x0000555555555188 <+11>:    cmp    $0x0,-0x4(%rbp)    ; Check if n == 0

    0x000055555555518c <+15>:    jne    0x55555555519c <factorial+31> ; Jump to recursion if not

    0x000055555555518e <+17>:    mov    $0x1,%eax          ; Return 1 if n == 0

    0x0000555555555193 <+22>:    jmp    0x5555555551b0 <factorial+51> ; Jump to the end

    0x0000555555555195 <+24>:    lea    -0x1(%rdi),%eax    ; Calculate n - 1

    0x0000555555555198 <+27>:    call   0x55555555517d <factorial> ; Recursively call factorial with n - 1

    0x000055555555519d <+32>:    imul   %edi,%eax          ; Multiply n with the result of recursive call

    0x00005555555551a0 <+35>:    jmp    0x5555555551b0 <factorial+51> ; Jump to the end

    0x00005555555551a2 <+37>:    mov    $0x0,%eax          ; Return 0

    0x00005555555551a7 <+42>:    add    $0x10,%rsp

    .
    .
    .
    .
    .
    .






