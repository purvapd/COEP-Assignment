
# Assignment_7

## Problem Statement:-

Implement a queue (that is write queue.c and queue.h only) of characters, such that on an 
enqueue, the char is added at the end of queue, and on a dequeue the first element is taken 
out, but the queue uses only a 'head' pointer and not a 'tail pointer. 

### Code_1 :- queue.h

    The queue.h file is a header file that contains declarations of functions and types used in the 
    implementation of a queue. It cannot be run directly, but rather needs to be included in a 
    C source file (e.g. queue.c) that defines the implementation of the functions declared in queue.h.

### Code_2 :- queue.c

    queue.c is a source file that implements the basic functionality of a queue data structure in C. It defines four functions 
    - queue_create, queue_destroy, queue_enqueue, and queue_dequeue - that allow you to create a new queue, add elements to the 
    end of the queue, remove elements from the front of the queue, and destroy the queue and free its memory.

### Code_2 :- main.c
  
    main.c is a source file that contains the entry point of the program. In this file, we have included the queue.h header 
    file to use the queue_create, queue_destroy, queue_enqueue, and queue_dequeue functions implemented in the queue.c source file.


### Run the program.

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ gcc -o main main.c queue.c

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ ./main
    
    a b c
