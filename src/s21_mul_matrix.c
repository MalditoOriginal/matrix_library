#include "s21_matrix.h"

int s21_mul_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    // Check for invalid input matrices
    if (matrixWrong(A) || matrixWrong(B)) {
        return 1; // Error: Invalid matrix
    }

    // Check if the number of columns in A is not equal to the number of rows in B
    if (A->cols != B->rows) {
        return 2; // Error: Incompatible matrix dimensions for multiplication
    }

    // Create the result matrix
    if (s21_create_matrix(A->rows, B->cols, result)) {
    // Perform matrix multiplication
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++) {
            double product = 0;
            for (int col = 0; col < B->rows; col++) {
                product += matrixVal(A, i, col) * matrixVal(B, col, j);
            }
            result->matrix[i][j] = product;
        }
    }
    }

    return 0; // Success
}