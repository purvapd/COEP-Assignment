
# Assignment_11

## Problem Statement:-

Write a sorting program with the following features: Reads data from a text file and sorts it 
alphabetically by default. If the file has data in rows and columns (separated by space or tab) 
then allows sorting on a particular column. Allows any sort using numeric or alphbetical 
ordering

### Code_1 :- sort.c
    
   This program assumes that the text file contains data with a maximum of 1000 rows and 100 columns, 
   with each field having a maximum length of 256 characters. You may adjust these constants according to your needs. 
   Also, please ensure that the input text file follows the specified format with data in rows and columns separated by spaces or tabs.
  

### Run the program.

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ gcc sort.c -o sort

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ ./sort
    
    Enter the name of the text file: data.txt
    
    Enter the column number to sort (starting from 1): 1
    
    Enter the sort order (alphabetical/numeric): alphabetical


    Sorted Data:
    
    Alice   25      F
    
    Bob     30      M
    
    Charlie 20      M
    
    David   22      M
    
    Eve     28      F
