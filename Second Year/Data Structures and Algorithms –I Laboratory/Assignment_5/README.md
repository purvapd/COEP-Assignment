
# Assignment_1.a

## Problem Statement:-

Compare the time complexity of two sorting algorithms, by following the given steps. Create 
a set of data files with count of integers varying into thousands and millions. Sort the files 
using both the algorithms. Plot graph of the time taken by both the programs using tool like 
gnuplot. Compare the graphs and comment on the time complexity theoretically predicted 
and practically observed.

### Code_1 :- data.c
    
   Created a set of data files with the count of integers varying into thousands and millions. 
   Make sure the files are in the same format and have the same set of integers.! Here's an 
   example C program that generates data files with varying counts of integers:

### Run the program.

      VSK@DESKTOP-8LMS4JT MINGW64 ~

      $ gcc data.c -o data

      VSK@DESKTOP-8LMS4JT MINGW64 ~

      $ ./data

      Data files generated successfully!
  
  --------------------------------------------------------------------------------------------------------------------

### Code_2 :- insertion.c

    Here's an example C program that implements the Insertion Sort algorithm and measures the time taken to sort each data file:


### Run the program.
    
    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ gcc insertion.c -o insertion

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ ./insertion
    
    Time taken to sort 10000 integers using Insertion Sort: 0.046000 seconds
    
    Time taken to sort 100000 integers using Insertion Sort: 6.937000 seconds


  --------------------------------------------------------------------------------------------------------------------

### Code_3 :- quick.c

    Here's an example C program that implements the Quick Sort algorithm and measures the time taken to sort each data file:


### Run the program.

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ gcc quick.c -o quick

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ ./quick
    
    Time taken to sort 10000 integers using Quick Sort: 0.000000 seconds
    
    Time taken to sort 100000 integers using Quick Sort: 0.015000 seconds

