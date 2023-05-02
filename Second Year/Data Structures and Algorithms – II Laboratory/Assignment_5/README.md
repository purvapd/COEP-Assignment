
# Assignment_5

## Problem Statement:-

Implement a sparse matrix with operations like initialize empty sparse matrix, insert an element, sort a sparse matrix on row-column,
add two matrices and return the result as a matrix, transpose a matrix, etc. 

### Code_1 :- matrix.c

The C with various operations such as initializing an empty matrix, inserting an element, sorting the matrix based on the row and column, 
adding two matrices and returning the result, and transposing a matrix.

The code uses structures to represent the sparse matrix, where each element of the matrix is stored as a row, column, and value. The code
defines functions to initialize the matrix, insert an element, sort the matrix, add two matrices, and transpose a matrix.

In the main function, the code creates two sparse matrices, inserts elements, sorts the matrices, adds them, and transposes the resulting matrix. 
Finally, the program prints the original matrices, the sum of the matrices, and the transposed matrix.


### Run the program.

    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc matrix.c -o matrix



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./matrix

    After Inserting Elements:-

    Sorted Sparse Matrix A:-

    Sparse matrix (3 x 3):

    (0, 0) = 1

    (0, 1) = 0

    (0, 2) = 2

    (1, 0) = 0

    (1, 1) = 3

    (1, 2) = 0

    (2, 0) = 4

    (2, 1) = 0

    (2, 2) = 5

    After Inserting Elements:-

    Sorted Sparse Matrix B:-

    Sparse matrix (3 x 3):

    (0, 0) = 1

    (0, 1) = 0


    (0, 2) = 0

    (1, 0) = 0

    (1, 1) = 0

    (1, 2) = 7

    (2, 0) = 0

    (2, 1) = 9

    (2, 2) = 0

    Addition of the Matrix A and Matrix B:-

    Sparse matrix (3 x 3):

    (0, 0) = 2

    (0, 2) = 2

    (1, 1) = 3

    (1, 2) = 7

    (2, 0) = 4

    (2, 1) = 9

    (2, 2) = 5

    Transpose of the addition of Matrix A and Matrix B:-

    Sparse matrix (3 x 3):

    (0, 0) = 2

    (0, 2) = 4

    (1, 1) = 3

    (1, 2) = 9

    (2, 0) = 2

    (2, 1) = 7

    (2, 2) = 5


