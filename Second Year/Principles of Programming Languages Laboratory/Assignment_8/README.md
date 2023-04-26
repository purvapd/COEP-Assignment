

# Assignment_8

## Problem Statement:-

Write a program to raise an exception and handle it.

### Code_1 :- division.cpp

    In this example, we use a try block to enclose the code that may throw an exception. We perform division between numerator and 
    denominator variables. If the denominator is zero, we throw an exception with the error message "Error: Division by zero!" using the 
    throw statement. In the catch block, we catch the exception of type const char* and print the error message. If the denominator is not
    zero, we perform the division and print the result.
		
		
### Run the program.


    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ g++ division.cpp -o division



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./division

    Enter numerator: 78

    Enter denominator: 23

    Result: 3.3913



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./division

    Enter numerator: 90

    Enter denominator: 0

    Exception caught: Error: Division by zero!


