
# Assignment_1

## Problem Statement:-

Write the following functions for a binary search tree implementation: Searches the 
maximum value in the tree, preorder traversal without using recursion, Search the string in 
the tree and returns a pointer to the node, print the binary tree so that it looks like a tree.


### Code_1 :- binary.c
    

In the main function, we create a binary search tree with some values and strings, and then we call the `preorder` 
function to perform a preorder traversal of the tree without using recursion. The output will be a list of nodes in 
preorder traversal order.

Note that the `preorder` function uses a stack to keep track of nodes to be visited. It starts by pushing the root node onto 
the stack, and then it pops nodes from the stack one by one and prints their data and strings. Finally, it pushes the right 
child and then the left child of the current node onto the stack, if they exist. This ensures that the left child is visited 
before the right child.


### Run the program.

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ gcc binary.c -o binary


    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ ./binary
    
    The binary search tree:

              35 thirty-five

         30 thirty

              25 twenty-five

    20 twenty

              15 fifteen

         10 ten

              5 five

The maximum value in the tree is 35.

The string thirty is not in the tree.

Preorder of the Tree is :-

20 twenty 10 ten 5 five 15 fifteen 30 thirty 25 twenty-five 35 thirty-five


