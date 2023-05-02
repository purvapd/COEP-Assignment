
# Assignment_6

## Problem Statement:-

Develop C functions to insert and delete into/from a max heap under the assumption that a dynamically allocated 
array is used, the initial capacity of this array is 1, and array doubling is done whenever we are to insert into a max heap that is full.
 

### Code_1 :- heap.c

The C code implements the insertion and deletion operations of a max heap using a dynamically allocated array. 
The initial capacity of the array is 1, and it is doubled whenever the array is full.

The max_heap struct holds the array of integers, the current size of the heap, and the current capacity of the array. 
The create_max_heap() function allocates memory for the max_heap struct and its data array, initializes the size to 0 and the 
capacity to 1, and returns a pointer to the max_heap struct.

The insert() function first checks if the array is full and doubles its capacity if needed. Then, it inserts the new value at 
the end of the array and performs the necessary swaps to maintain the max heap property.

The delete_max() function deletes the maximum value from the heap (which is the root of the tree) and returns it. If the heap is 
empty, it prints an error message.

Finally, the main() function creates a max heap, inserts some values into it, deletes the maximum value repeatedly, and 
then destroys the heap.


### Run the program.


    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc heap.c -o heap



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./heap

    Insert the 10 in to the heap.

    Insert the 5 in to the heap.

    Insert the 20 in to the heap.

    Insert the 30 in to the heap.



    Delete the max element from heap:-

    Deleted 30 from heap.

    Delete the max element from heap:-

    Deleted 20  from heap.

    Delete the max element from heap:-

    Deleted 10  from heap.

    Delete the max element from heap:-

    Deleted 5  from heap.

    Delete the max element from heap:-

    Error: Cannot delete from an empty heap.

    Deleted -1  from heap.



