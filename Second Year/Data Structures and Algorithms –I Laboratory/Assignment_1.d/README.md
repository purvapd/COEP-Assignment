
# Assignment_1.d

## Problem Statement:-

Write a program in C to define a structure for a Customer bank account that holds
information like Account Number, Name of account holder, balance, internet banking
facility availed(Yes or No), Pin code (422001 to 422013), Account type(saving,
recurring, deposit).

i. Read account details for N customers

ii. Classify the customer as Golden, Silver and General based on the following
criteria: Golden customers: Balance> 10, 00000, Silver Customers: Balance
>500000 and <500000, General customers: Balance <500000
>
iii. Display the list of customers availing the Internet banking facility.

iv. Display the customers belonging to a particular geographical location depending
on postal code.

v. Display the customer list as per their account type


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



