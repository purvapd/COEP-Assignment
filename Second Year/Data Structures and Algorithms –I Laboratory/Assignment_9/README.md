
# Assignment_9

## Problem Statement:-

Implement a data type to represent a Polynomial with the operations like create an empty 
polynomial, insert an entry into polynomial, add two polynomials and return the result as a 
polynomial, evaluate a polynomial, etc. 

### Code_1 :- poly.c
    
    This implementation includes the following operations:
    - `createEmptyPolynomial`: creates an empty polynomial with no terms.
    - `insertTerm`: inserts a new term with the given coefficient and exponent into the polynomial in the correct 
        position based on the exponent.
    - `addPolynomials`: adds two polynomials and returns the result as a new polynomial.
    - `evaluatePolynomial`: evaluates the polynomial at a given value of x and returns the result.
    - `printPolynomial`: prints the polynomial in the standard mathematical notation.

    The implementation uses dynamic memory allocation to create and manage the linked list of terms. 
    The `insertTerm` function takes care of adding terms with the same exponent by combining their coefficients. 
    The `addPolynomials` function uses a merge-like algorithm to add the terms of the two polynomials in decreasing order
    of exponent. The `evaluatePolynomial` function uses the Horner's method to efficiently evaluate the polynomial for a given value of x. 
    The `printPolynomial` function prints the terms of the polynomial in the standard mathematical notation, with each term separated by a plus sign.

### Run the program.

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ gcc poly.c -o poly

    VSK@DESKTOP-8LMS4JT MINGW64 ~
    
    $ ./poly
    
    p1 = 2x^3 + 4x^1 + 5x^0
    
    p2 = 3x^4 + -1x^3 + 2x^2 + 5x^0
    
    p1 + p2 = 3x^4 + 1x^3 + 2x^2 + 4x^1 + 10x^0
    
    p1(2) = 29

