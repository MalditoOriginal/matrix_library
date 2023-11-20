#include "s21_matrix.h"

#define EPSILON 1e-7

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    if (A->rows != B->rows || A->cols != B->cols) {
        return FAILURE;
    }

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            double eps = fabs(matrixVal(A, i, j) - matrixVal(B, i, j));
            if (eps >= EPSILON) {
                return FAILURE;
            }
        }
    }

    return SUCCESS;
}