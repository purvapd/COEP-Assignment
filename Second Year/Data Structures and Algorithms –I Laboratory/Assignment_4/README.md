
# Assignment_4

## Problem Statement:-

Write a program to remove duplicate doubles from an array of doubles. In the program, write 
a function which accepts an array of doubles and removes the duplicates from the array and 
has return type void

### Code_1 :- histogram.c
    
    This C program takes an array of doubles as input from the user and removes any duplicate values 
    from the array using a nested loop. The remove_duplicates() function shifts all the elements after a duplicate value 
    one position to the left and decrements the size of the array by one. Finally, the program outputs the original array and 
    the resulting array after removing the duplicates.


### Run the program.
    
    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ gcc array.c -o array



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./array

    Enter the size of the array: 10

    Enter 10 double values: 1.2

    3.4
    
    5.1
    
    9.0
    
    3.4
    
    5.1
    
    5.1
    
    3.8
    
    5.5
    
    7.8
    
    Original array: 1.20 3.40 5.10 9.00 3.40 5.10 5.10 3.80 5.50 7.80
    
    Array after removing duplicates: 1.20 3.40 5.10 9.00 3.80 5.50 7.80 7.80 7.80 7.80

