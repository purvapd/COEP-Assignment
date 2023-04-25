
# Assignment_10

## Problem Statement:-

Implement a Set data type using sequentially linked structures. Support operations like create 
an empty set, insert an element into set, do a union of two sets and return results as a set, etc. 

### Code_1 :- link.c
    
    In this implementation, we define a Set structure that contains a pointer to the head of a linked list 
    and the size of the set. We then define functions to create an empty set, check if an element is in the set, 
    insert an element into the set, do a union of two sets and return the result as a set, and print the elements of the set. 
    We also define a function to free the memory used by the set.



### Run the program.

  VSK@DESKTOP-8LMS4JT MINGW64 ~
  
  $ gcc link.c -o link

  VSK@DESKTOP-8LMS4JT MINGW64 ~
  
  $ ./link
  
  Set 1: {3, 2, 1}
  
  Set 2: {4, 3, 2}
  
  Set 3 (union of set 1 and set 2): {4, 1, 2, 3}
