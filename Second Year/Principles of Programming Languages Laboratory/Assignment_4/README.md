

# Assignment_4

## Problem Statement:-

Explain how pass by reference works, using assembly code generated using g++ -S on a 
C++ program. 

### Code_1 :- swap.cpp

	In C++, pass by reference is a mechanism that allows a function to access and modify the original value of a variable, 
	rather than creating a copy of the value. This   can be achieved using pointers or references. 
	
	Here is an example of how pass by reference works in assembly code, generated using g++ -S on a C++ program:
     
### Run the program.

     VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ g++ -S swap.cpp

    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ cat swap.s

            .file   "swap.cpp"

            .text

            .globl  _Z4swapRiS_

            .def    _Z4swapRiS_;    .scl    2;      .type   32;     .endef

            .seh_proc       _Z4swapRiS_

    _Z4swapRiS_:

    .LFB0:
            pushq   %rbp

            .seh_pushreg    %rbp


            movq    %rsp, %rbp

            .seh_setframe   %rbp, 0

            subq    $16, %rsp

            .seh_stackalloc 16

            .seh_endprologue


            movq    %rcx, 16(%rbp)

            movq    %rdx, 24(%rbp)

            movq    16(%rbp), %rax

            movl    (%rax), %eax

            movl    %eax, -4(%rbp)

            movq    24(%rbp), %rax

            movl    (%rax), %edx

            movq    16(%rbp), %rax

            movl    %edx, (%rax)

            movq    24(%rbp), %rax

            movl    -4(%rbp), %edx

            movl    %edx, (%rax)

            nop

            addq    $16, %rsp

            popq    %rbp

            ret

            .seh_endproc

            .ident  "GCC: (GNU) 11.3.0"


