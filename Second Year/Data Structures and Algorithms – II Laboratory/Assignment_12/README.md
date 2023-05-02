
# Assignment_12

## Problem Statement:-

Develop a hash table implementation in which overflows are resolved using chaining. Read a set of records from a file, insert them 
into hash table, then perform a set of searches using use supplied data and show the search results.

### Code_1 :- hash_table.c

In this implementation, the hash function sums the ASCII values of the characters in the key string and takes the remainder when divided
by the size of the hash table. This determines the index in the table where the key-value pair will be stored. If there is a collision 
(i.e. two keys hash to the same index), the new key-value pair is added to the end of a linked list at that index.

The insert function takes a key and value as parameters, computes the hash index, and creates a new node containing the key-value pair.
If there is no existing node at the computed index, the new node is added to the table. Otherwise, the new node is added to the end of 
the linked list at that index.

The search function takes a key as a parameter, computes the hash index, and searches the linked list at that index for a node with a 
matching key. If a match is found, the corresponding value is returned. Otherwise, -1 is returned to indicate that the key was not
found in the table.

### Run the program.


    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc hash_table.c -o hash_table



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./hash_table

    Enter a key to search for: banana

    Value for key 'banana' is 3



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./hash_table

    Enter a key to search for: chiku
    
    Key 'chiku' not found in table



