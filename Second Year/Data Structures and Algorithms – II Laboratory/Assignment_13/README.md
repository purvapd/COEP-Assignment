
# Assignment_13

## Problem Statement:-

Implement a dictionary using a sparse matrix data structure. 

### Code_1 :- sparse.c

his program defines two structs: Element and SparseMatrix. Element represents a single element in the matrix and 
contains its row, column, and value. SparseMatrix contains information about the dimensions of the matrix and an array 
of Element structs that make up the sparse matrix.

The createSparseMatrix function initializes a SparseMatrix struct with the given number of rows and columns.

The setElement function sets an element in the matrix at the specified row and column with the given value. If the value 
is 0 or the row and column indices are out of range, an error is printed and no changes are made to the matrix.

The getElement function returns the value at the specified row and column in the matrix. If the row and column indices are 
out of range, an error is printed and 0 is returned.

The printSparseMatrix function prints the matrix in row-major order.

In the main function, a SparseMatrix is created with 3 rows and 3 columns. Three elements are then added to the matrix

### Run the program.


    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc sparse.c -o sparse



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./sparse

    Sparse Matrix:-

    1 0 0

    0 2 0

    0 0 3




