#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    int rows;
    int cols;
    int count;
    Element data[MAX_SIZE];
} SparseMatrix;

SparseMatrix createSparseMatrix(int rows, int cols) {
    SparseMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.count = 0;
    return matrix;
}

void setElement(SparseMatrix *matrix, int row, int col, int value) {
    if (row >= matrix->rows || col >= matrix->cols) {
        printf("Error: index out of range\n");
        return;
    }
    if (value == 0) {
        printf("Error: cannot set element to 0\n");
        return;
    }
    for (int i = 0; i < matrix->count; i++) {
        Element *elem = &matrix->data[i];
        if (elem->row == row && elem->col == col) {
            elem->value = value;
            return;
        }
    }
    Element elem = { row, col, value };
    matrix->data[matrix->count] = elem;
    matrix->count++;
}

int getElement(SparseMatrix *matrix, int row, int col) {
    if (row >= matrix->rows || col >= matrix->cols) {
        printf("Error: index out of range\n");
        return 0;
    }
    for (int i = 0; i < matrix->count; i++) {
        Element *elem = &matrix->data[i];
        if (elem->row == row && elem->col == col) {
            return elem->value;
        }
    }
    return 0;
}

void printSparseMatrix(SparseMatrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", getElement(matrix, i, j));
        }
        printf("\n");
    }
}


int main() {
    SparseMatrix matrix = createSparseMatrix(3, 3);
    setElement(&matrix, 0, 0, 1);
    setElement(&matrix, 1, 1, 2);
    setElement(&matrix, 2, 2, 3);

    printf("Sparse Matrix:- \n");
    printSparseMatrix(&matrix);
    return 0;
}
