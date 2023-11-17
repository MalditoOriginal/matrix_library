#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
    int ret = 0, i;
    *result = 0;

    if (matrixWrong(A) == 0) {
        if (A->cols == A->rows) {
            if (A->rows == 1) {
                *result = matrixVal(A, 0, 0);
            } else if (A->rows == 2) {
                *result = matrixVal(A, 0, 0) * matrixVal(A, 1, 1) - matrixVal(A, 0, 1) * matrixVal(A, 1, 0);
            } else if ( A->rows > 2) {
                for (i = 0; i < A->rows && ret == 0; i++) {
                    matrix_t res;
                    rmRowCol(A, &res, i, 0);
                    double middle = 0;
                    ret = s21_determinant(&res, &middle);
                    if (ret == 0) {
                        *result = *result + pow(-1, i+2) * matrixVal(A, i, 0) * middle;
                    }
                    s21_remove_matrix(&res);
                }
            }
        } else
        ret = 2;
    } else
        ret = 1;

    return ret;
}