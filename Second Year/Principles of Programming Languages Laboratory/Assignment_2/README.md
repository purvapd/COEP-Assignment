

# Assignment_2

## Problem Statement:-

Use objdump to read the object file of a C program and demonstrate how a stack frame is 
built and destroyed.

### Code_1 :- example.c

    'objdump' to read the object file of a C program and demonstrate how a stack frame is built and destroyed. 

    This will disassemble the object file and show the corresponding assembly code. In the assembly code, 
    you will see instructions related to stack frame creation and destruction, typically involving the push, 
    pop, mov, and leave instructions.

     
     
### Run the program.


    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc -c example.c -o example.o

    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ objdump -d example.o

    example.o:     file format pe-x86-64


    Disassembly of section .text:

    0000000000000000 <add>:

       0:   55                      push   %rbp

       1:   48 89 e5                mov    %rsp,%rbp

       4:   48 83 ec 10             sub    $0x10,%rsp

       8:   89 4d 10                mov    %ecx,0x10(%rbp)

       b:   89 55 18                mov    %edx,0x18(%rbp)

       e:   8b 55 10                mov    0x10(%rbp),%edx

      11:   8b 45 18                mov    0x18(%rbp),%eax

      14:   01 d0                   add    %edx,%eax

      16:   89 45 fc                mov    %eax,-0x4(%rbp)

      19:   8b 45 fc                mov    -0x4(%rbp),%eax

      1c:   48 83 c4 10             add    $0x10,%rsp

      20:   5d                      pop    %rbp

      21:   c3                      ret

    0000000000000022 <main>:

      22:   55                      push   %rbp

      23:   48 89 e5                mov    %rsp,%rbp

      26:   48 83 ec 30             sub    $0x30,%rsp

      2a:   e8 00 00 00 00          call   2f <main+0xd>

      2f:   c7 45 fc 05 00 00 00    movl   $0x5,-0x4(%rbp)

      36:   c7 45 f8 0a 00 00 00    movl   $0xa,-0x8(%rbp)

      3d:   8b 55 f8                mov    -0x8(%rbp),%edx

      40:   8b 45 fc                mov    -0x4(%rbp),%eax

      43:   89 c1                   mov    %eax,%ecx

      45:   e8 b6 ff ff ff          call   0 <add>

      4a:   89 45 f4                mov    %eax,-0xc(%rbp)

      4d:   8b 45 f4                mov    -0xc(%rbp),%eax

      50:   89 c2                   mov    %eax,%edx

      52:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # 59 <main+0x37>

      59:   48 89 c1                mov    %rax,%rcx

      5c:   e8 00 00 00 00          call   61 <main+0x3f>

      61:   b8 00 00 00 00          mov    $0x0,%eax

      66:   48 83 c4 30             add    $0x30,%rsp

      6a:   5d                      pop    %rbp

      6b:   c3                      ret

      6c:   90                      nop

      6d:   90                      nop

      6e:   90                      nop

      6f:   90                      nop


