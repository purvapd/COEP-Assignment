
# Assignment_8

## Problem Statement:-

Write an data type called "Integer". The data type should represent integers of unlimited 
length.

### Code_1 :- datatype.c
    
    In this implementation, the "Integer" data type is defined as a structure that contains an array of digits 
    and a size variable that stores the number of digits in the integer. The "init" function initializes the integer to 
    zero, the "set" function sets the integer to a value given as a string, the "print" function prints the integer as a string, 
    and the "add" function adds two integers and stores the result in another integer.

    This implementation allows for integers of unlimited length, but it is limited by the size of the array used to 
    store the digits (in this case, 1000 digits). To create a truly unlimited-length integer data type, the array size 
    would need to be dynamically allocated as needed.


### Run the program.

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ gcc datatype.c -o datatype

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ ./datatype
    
    Enter the first number: 66666666666666666666677777777777777777777788888888888888888888888899999999999999999999999
    
    Enter the second number: 9999999999999999999998888888888888888888888888888888555555555555555555555555533333333333333333333333333332222222222222
    
    Sum of the numbers: 9999999999999999999998888888955555555555555555555566333333333333333333344444422222222222222222233333333332222222222221
