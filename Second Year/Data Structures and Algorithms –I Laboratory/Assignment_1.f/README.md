

# Assignment_1.d

## Problem Statement:-

Write a C program to accept a string and change the case of each character of the string.
Example “ THIs Is a C Program” changes to “thiSiS A c pROGRAM”


### Code :- change_case.c
    
   To solve this problem using a data structure and algorithm, we can use a character array to store the input string,
   and then iterate over each character of the string. For each character, we can use a conditional statement to check
   whether it is uppercase or lowercase, and then change its case accordingly using the toupper() and tolower() 
   functions from the ctype.h library.


  
### Run the program.
  
  VSK@DESKTOP-8LMS4JT MINGW64 ~
  
  $ gcc change_case.c -o change_case

  VSK@DESKTOP-8LMS4JT MINGW64 ~
  
  $ ./change_case
  
  Enter a string: THIs Is a C Program
  
  Modified string: thiS iS A c pROGRAM
