
# Assignment_1.c

## Problem Statement:-

Write a program to determine a string is a palindrome or not. A palindrome is a word, 
number, phrase, or other sequence of characters which reads the same backward as 
forward, such as madam, racecar.


### Code_1 :- palindrome.c
    
    To determine whether a string is a palindrome or not, we can use the stack data structure. The basic idea 
    is to push the first half of the string onto the stack, and then compare it with the second half of the 
    string by popping elements from the stack.

  

### Code_2 :- palindrome_1.c

    Here's another implementation of the program without using stack:
    
    In this implementation, we iterate through the first half of the string and compare each character with 
    its corresponding character in the second half of the string. If they don't match, the string is not a palindrome; 
    otherwise, it is.


### Run the program.

VSK@DESKTOP-8LMS4JT MINGW64 ~

$ gcc palindrome.c -o palindrome

VSK@DESKTOP-8LMS4JT MINGW64 ~

$ ./palindrome

Enter a string: purva

purva is not a palindrome.

VSK@DESKTOP-8LMS4JT MINGW64 ~

$ ./palindrome

Enter a string: racecar

racecar is a palindrome.


