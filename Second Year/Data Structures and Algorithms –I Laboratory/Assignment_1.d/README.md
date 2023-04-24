
# Assignment_1.d

## Problem Statement:-

Write a program in C to define a structure for a Customer bank account that holds
information like Account Number, Name of account holder, balance, internet banking
facility availed(Yes or No), Pin code (422001 to 422013), Account type(saving,
recurring, deposit).

i. Read account details for N customers

ii. Classify the customer as Golden, Silver and General based on the following
criteria: Golden customers: Balance> 10, 00000, Silver Customers: 
Balance >500000 and <500000, General customers: Balance <500000>

iii. Display the list of customers availing the Internet banking facility.

iv. Display the customers belonging to a particular geographical location depending
on postal code.

v. Display the customer list as per their account type


### Code :- palindrome.c
    
   The program first defines the structure for the Customer bank account, with the required fields. 
   It then reads account details for N customers, stores them in an array of customer structures.


  
### Run the program.

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ gcc customer_bank_data.c -o customer_bank_data

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ ./customer_bank_data
    
    Enter the number of customers: 4
    
    Enter details for customer 1:
    
    Account Number: 100001
    
    Name: purva
    
    Balance: 50000
    
    Internet Banking Facility (Yes or No): yes
    
    Pin code: 422001
    
    Account Type (saving, recurring, deposit): saving
    
    Enter details for customer 2:
    
    Account Number: 1230001
    
    Name: amit
    
    Balance: 8900000
    
    Internet Banking Facility (Yes or No): No
    
    Pin code: 422010
    
    Account Type (saving, recurring, deposit): saving
    
    Enter details for customer 3:
    
    Account Number: 1000015
    
    Name: Raghav
    
    Balance: 1000000
    
    Internet Banking Facility (Yes or No): No
    
    Pin code: 422007
    
    Account Type (saving, recurring, deposit): recurring
    
    Enter details for customer 4:
    
    Account Number: 19990002
    
    Name: Ajit
    
    Balance: 10000000000
    
    Internet Banking Facility (Yes or No): yes
    
    Pin code: 422009
    
    Account Type (saving, recurring, deposit): deposit


    Customer classification:

    purva - General

    amit - Golden

    Raghav - Silver

    Ajit - Golden



    Customers availing Internet banking facility:



    Enter a postal code to search for customers: 422009


    Customers belonging to postal code 422009:

    Ajit



    Enter an account type to search for customers (saving, recurring, deposit): saving


    Customers with account type saving:

    purva

    amit
