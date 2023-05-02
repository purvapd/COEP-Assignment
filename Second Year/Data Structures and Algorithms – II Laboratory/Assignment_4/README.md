
# Assignment_4

## Problem Statement:-

Start with an empty AVL tree and perform series of insertions like : December, January, April, March, July, August, October, February, 
November, May, June. Display the tree

### Code_1 :- avl.c
    

The C program that creates an AVL tree data structure and performs a series of insertions. The program defines a node structure for 
the AVL tree with a key, height, and left and right child pointers. It includes functions to get the height and balance factor of a 
node, perform left and right rotations on nodes, create a new node, and insert a node into the AVL tree.

The main function performs a series of insertions into the AVL tree with the keys "December", "January", "April", "March", "July", 
"August", "October", "February", "November", "May", and "June". After the insertions are complete, the program prints the inorder 
traversal of the AVL tree, which displays the keys in sorted order.
The resulting AVL tree has a balanced structure, with the heights of the left and right subtrees of each node differing by at most one.

### Run the program.


    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc avl.c -o avl



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./avl

    Inorder traversal of the AVL tree: April August December February January July June March May November October


