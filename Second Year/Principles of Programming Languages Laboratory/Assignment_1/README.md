
# Assignment_1

## Problem Statement:-

Compile a C program with gcc with various options like -S, --save-temps.

### Code_1 :- example.c
Now, you can use gcc to compile this C program with different options:

  1.  -S option: 
  
      This option generates assembly language code (.s file) without assembling or linking it.
      This will generate an assembly language code file named example.s which contains the assembly code
      corresponding to the C program.
    
  2. --save-temps option: 
  
      This option saves intermediate compilation files (.i, .s, .o) along with the final executable.
      This will generate multiple files including example.i (preprocessed source code), example.s 
      assembly language code), example.o (object file), and a.out (final executable).
     
     
### Run the program.

 1.  -S option: 
  
    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ gcc -s example.c -o example

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ ./example
    
    Sum: 15

  2. --save-temps option: 

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ gcc --save-temps example.c -o example

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ ./example
    
    Sum: 15


