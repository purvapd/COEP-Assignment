#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A structure to represent a term of a polynomial
typedef struct Term {
    int coef;   // coefficient of the term
    int exp;    // exponent of the term
    struct Term* next;  // pointer to the next term
} Term;

// A structure to represent a polynomial
typedef struct Polynomial {
    Term* head; // pointer to the first term of the polynomial
} Polynomial;

// Function to create an empty polynomial
Polynomial createEmptyPolynomial() {
    Polynomial p;
    p.head = NULL;
    return p;
}

// Function to insert a term into a polynomial
void insertTerm(Polynomial* p, int coef, int exp) {
    // create a new term with the given coefficient and exponent
    Term* t = (Term*) malloc(sizeof(Term));
    t->coef = coef;
    t->exp = exp;
    t->next = NULL;
    
    // if the polynomial is empty, set the new term as the head
    if (p->head == NULL) {
        p->head = t;
        return;
    }
    
    // otherwise, insert the new term in the correct position based on the exponent
    Term* prev = NULL;
    Term* curr = p->head;
    while (curr != NULL && curr->exp > exp) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL && curr->exp == exp) {
        // if a term with the same exponent already exists, add their coefficients
        curr->coef += coef;
        free(t);
    } else {
        // otherwise, insert the new term before the current term
        t->next = curr;
        if (prev == NULL) {
            p->head = t;
        } else {
            prev->next = t;
        }
    }
}

// Function to add two polynomials and return the result as a polynomial
Polynomial addPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial res = createEmptyPolynomial();
    Term* t1 = p1.head;
    Term* t2 = p2.head;
    while (t1 != NULL && t2 != NULL) {
        if (t1->exp > t2->exp) {
            insertTerm(&res, t1->coef, t1->exp);
            t1 = t1->next;
        } else if (t1->exp < t2->exp) {
            insertTerm(&res, t2->coef, t2->exp);
            t2 = t2->next;
        } else {
            insertTerm(&res, t1->coef + t2->coef, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    // append the remaining terms of p1 or p2, if any
    while (t1 != NULL) {
        insertTerm(&res, t1->coef, t1->exp);
        t1 = t1->next;
    }
    while (t2 != NULL) {
        insertTerm(&res, t2->coef, t2->exp);
        t2 = t2->next;
    }
    return res;
}

// Function to evaluate a polynomial at a given value of x
int evaluatePolynomial(Polynomial p, int x) {
    int result = 0;
    Term* t = p.head;
    while (t != NULL) {
    result += t->coef * pow(x, t->exp);
    t = t->next;
    }
    return result;
    }

    // Function to print a polynomial
    void printPolynomial(Polynomial p) {
    Term* t = p.head;
    while (t != NULL) {
    printf("%dx^%d", t->coef, t->exp);
    t = t->next;
    if (t != NULL) {
    printf(" + ");
    }
    }
    printf("\n");
    }

    // Example usage
    int main() {
    Polynomial p1 = createEmptyPolynomial();
    insertTerm(&p1, 2, 3);
    insertTerm(&p1, 4, 1);
    insertTerm(&p1, 5, 0);
    printf("p1 = ");
    printPolynomial(p1);
    Polynomial p2 = createEmptyPolynomial();
    insertTerm(&p2, 3, 4);
    insertTerm(&p2, -1, 3);
    insertTerm(&p2, 2, 2);
    insertTerm(&p2, 5, 0);
    printf("p2 = ");
    printPolynomial(p2);

    Polynomial sum = addPolynomials(p1, p2);
    printf("p1 + p2 = ");
    printPolynomial(sum);

    int x = 2;
    int result = evaluatePolynomial(p1, x);
    printf("p1(%d) = %d\n", x, result);

    return 0;
}
