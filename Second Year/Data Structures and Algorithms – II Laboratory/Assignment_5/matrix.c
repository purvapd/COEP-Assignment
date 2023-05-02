#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100 // maximum number of non-zero terms in the sparse matrix

typedef struct {
    int row, col, value;
} Term; // a non-zero element of the matrix

typedef struct {
    Term terms[MAX_TERMS + 1]; // the non-zero terms of the matrix, sorted by row-major order
    int rows, cols, terms_count; // the number of rows, columns, and non-zero terms in the matrix
} SparseMatrix;

// initializes an empty sparse matrix with the given number of rows and columns
void init_sparse_matrix(SparseMatrix *matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->terms_count = 0;
}

// inserts a non-zero element into the sparse matrix
void insert_sparse_matrix_element(SparseMatrix *matrix, int row, int col, int value) {
    if (matrix->terms_count >= MAX_TERMS) {
        fprintf(stderr, "Maximum number of terms exceeded\n");
        exit(1);
    }
    matrix->terms[matrix->terms_count].row = row;
    matrix->terms[matrix->terms_count].col = col;
    matrix->terms[matrix->terms_count].value = value;
    matrix->terms_count++;
}

// compares two terms by row-major order
int compare_terms(const void *a, const void *b) {
    Term *term_a = (Term*)a;
    Term *term_b = (Term*)b;
    if (term_a->row < term_b->row) {
        return -1;
    } else if (term_a->row > term_b->row) {
        return 1;
    } else {
        if (term_a->col < term_b->col) {
            return -1;
        } else if (term_a->col > term_b->col) {
            return 1;
        } else {
            return 0;
        }
    }
}

// sorts the non-zero terms of the sparse matrix by row-major order
void sort_sparse_matrix(SparseMatrix *matrix) {
    qsort(matrix->terms, matrix->terms_count, sizeof(Term), compare_terms);
}

// adds two sparse matrices and returns the result as a new sparse matrix
SparseMatrix add_sparse_matrices(SparseMatrix *matrix1, SparseMatrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        fprintf(stderr, "Matrices have different sizes\n");
        exit(1);
    }
    SparseMatrix result;
    init_sparse_matrix(&result, matrix1->rows, matrix1->cols);
    int index1 = 0, index2 = 0;
    while (index1 < matrix1->terms_count && index2 < matrix2->terms_count) {
        if (matrix1->terms[index1].row < matrix2->terms[index2].row ||
            (matrix1->terms[index1].row == matrix2->terms[index2].row &&
             matrix1->terms[index1].col < matrix2->terms[index2].col)) {
            insert_sparse_matrix_element(&result,
                                         matrix1->terms[index1].row,
                                         matrix1->terms[index1].col,
                                         matrix1->terms[index1].value);
            index1++;
        } else if (matrix1->terms[index1].row > matrix2->terms[index2].row ||
                   (matrix1->terms[index1].row == matrix2->terms[index2].row &&                   
                    matrix1->terms[index1].col > matrix2->terms[index2].col)) {
                    insert_sparse_matrix_element(&result,
                                                matrix2->terms[index2].row,
                                                matrix2->terms[index2].col,
                                                matrix2->terms[index2].value);
                                                index2++;
        } else {
        int sum = matrix1->terms[index1].value + matrix2->terms[index2].value;
        if (sum != 0) {
            insert_sparse_matrix_element(&result,
            matrix1->terms[index1].row,
            matrix1->terms[index1].col,
            sum);
        }
            index1++;
            index2++;
            }
        }
        while (index1 < matrix1->terms_count) {
            insert_sparse_matrix_element(&result,
            matrix1->terms[index1].row,
            matrix1->terms[index1].col,
            matrix1->terms[index1].value);
            index1++;
        }
        while (index2 < matrix2->terms_count) {
            insert_sparse_matrix_element(&result,
            matrix2->terms[index2].row,
            matrix2->terms[index2].col,
            matrix2->terms[index2].value);
            index2++;
        }
        return result;
}

// transposes a sparse matrix and returns the result as a new sparse matrix
SparseMatrix transpose_sparse_matrix(SparseMatrix *matrix) {
SparseMatrix result;
init_sparse_matrix(&result, matrix->cols, matrix->rows);
for (int i = 0; i < matrix->terms_count; i++) {
insert_sparse_matrix_element(&result,
matrix->terms[i].col,
matrix->terms[i].row,
matrix->terms[i].value);
}
sort_sparse_matrix(&result);
return result;
}

// prints a sparse matrix
void print_sparse_matrix(SparseMatrix *matrix) {
printf("Sparse matrix (%d x %d):\n", matrix->rows, matrix->cols);
for (int i = 0; i < matrix->terms_count; i++) {
printf("(%d, %d) = %d\n", matrix->terms[i].row, matrix->terms[i].col, matrix->terms[i].value);
}
}

// example usage
int main() {
    SparseMatrix matrix1, matrix2, result;
    printf("After Inserting Elements:- \n Sorted Sparse Matrix A:- \n");
    init_sparse_matrix(&matrix1, 3, 3);
    insert_sparse_matrix_element(&matrix1, 0, 0, 1);
    insert_sparse_matrix_element(&matrix1, 0, 1, 0);
    insert_sparse_matrix_element(&matrix1, 0, 2, 2);
    insert_sparse_matrix_element(&matrix1, 1, 0, 0);
    insert_sparse_matrix_element(&matrix1, 1, 1, 3);
    insert_sparse_matrix_element(&matrix1, 1, 2, 0);
    insert_sparse_matrix_element(&matrix1, 2, 0, 4);
    insert_sparse_matrix_element(&matrix1, 2, 1, 0);
    insert_sparse_matrix_element(&matrix1, 2, 2, 5);
    sort_sparse_matrix(&matrix1);
    print_sparse_matrix(&matrix1);

    printf("After Inserting Elements:- \n Sorted Sparse Matrix B:- \n");
    init_sparse_matrix(&matrix2, 3, 3);
    insert_sparse_matrix_element(&matrix2, 0, 0, 1);
    insert_sparse_matrix_element(&matrix2, 0, 1, 0);
    insert_sparse_matrix_element(&matrix2, 0, 2, 0);
    insert_sparse_matrix_element(&matrix2, 1, 0, 0);
    insert_sparse_matrix_element(&matrix2, 1, 1, 0);
    insert_sparse_matrix_element(&matrix2, 1, 2, 7);
    insert_sparse_matrix_element(&matrix2, 2, 0, 0);
    insert_sparse_matrix_element(&matrix2, 2, 1, 9);
    insert_sparse_matrix_element(&matrix2, 2, 2, 0);
    sort_sparse_matrix(&matrix2);
    print_sparse_matrix(&matrix2);

    printf("Addition of the Matrix A and Matrix B:- \n ");
    result = add_sparse_matrices(&matrix1, &matrix2);
    print_sparse_matrix(&result);

    printf("Transpose of the addition of Matrix A and Matrix B:- \n ");
    SparseMatrix transpose = transpose_sparse_matrix(&result);
    print_sparse_matrix(&transpose);
    return 0;
}