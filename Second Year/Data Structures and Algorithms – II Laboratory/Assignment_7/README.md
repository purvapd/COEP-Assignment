
# Assignment_7

## Problem Statement:-

Implement Heap sort algorithm on a set of records, with a specified key. 
 

### Code_1 :- heap_sort.c

In this implementation, we define a Record struct to represent the records that we're sorting. We also define two functions:
heapify and heapSort.

The heapify function takes an array arr, its size n, an index i that represents the root of a subtree, and an index keyIndex 
that specifies which field of the Record struct contains the key we're sorting on. It recursively transforms the subtree 
rooted at i into a max heap (i.e., a binary tree where each node is greater than or equal to its children with respect to the key field).

The heapSort function takes an array arr, its size n, and an index keyIndex. It first builds a max heap from the array by 
calling heapify on each non-leaf node in reverse order. It then repeatedly extracts the maximum element from the heap 
(which is always the root), places it at the end of the array, and calls heapify on the remaining heap to restore the 
max heap property.

In the main function, we create an example array of Record structs, call heapSort on it, and print the sorted array.

### Run the program.


    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc heap_sort.c -o heap_sort



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./heap_sort

    Input array: 10 7 8 9 1 5

    Sorted array: 1 5 7 8 9 10


