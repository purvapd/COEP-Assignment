

# Assignment_3

## Problem Statement:-

Write a code for level order traversal of a binary tree with and without stack.


### Code_1 :- binary.c
    

In this code, we first define a `struct node` to represent a node in the binary tree. We also define a `newNode()` function 
to create a new node with the given data.

The `levelOrderTraversalWithoutStack()` function uses a queue to traverse the tree in level order. We first create a queue of size 
100 and initialize the front and rear pointers to 0. We enqueue the root node to the queue, and then we loop through the queue until 
the front pointer is less than the rear pointer. In each iteration, we dequeue the front node of the queue, print its data, and enqueue 
its left and right children (if they exist) to the queue.

The `levelOrderTraversalWithStack()` function uses two stacks to traverse the tree in level order. We first create two stacks of size 100 
and initialize their top pointers to -1. We push the root node to stack1, and then we loop until both stacks are empty. In each iteration,
we pop all nodes from stack1 and print their data. For each popped node, we push its right child to stack2 (if it exists) and then its left 
child to stack2 (if it exists). Then, we pop all nodes from stack2 and print their data. For each popped node, we push its left child to stack1
(if it exists) and then its right child to stack1 (if it exists).

In the `main()` function, we create a binary tree with some sample nodes, and then we call the `levelOrderTraversalWithoutStack()` and 
`levelOrderTraversalWithStack()` functions to traverse the tree in level order without and with using stack, respectively.

### Run the program.


    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc binary.c -o binary



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./binary

    Level order traversal without stack: 1 2 3 4 5 6 7

    Level order traversal with stack: 1 2 3 7 6 5 4

