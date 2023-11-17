#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int ret = 0, i = 0, j = 0;
    
    if (matrixWrong(A) == 0) {
        if (A->rows == A->cols) {
            ret = s21_create_matrix(A->rows, A->cols, result);
            if (ret == 0) {
                for (i = 0; i < A->rows; i++) {
                    for (j = 0; j < A->cols; j++) {
                        matrix_t flags;
                        double res = 0;
                        rmRowCol(A, &flags, i, j);
                        ret = s21_determinant(&flags, &res);
                        if (ret == 0) {
                            result->matrix[i][j] = res * pow(-1, j + i);
                        }
                        s21_remove_matrix(&flags);
                    }
                }
            }
        } else {
            ret = 2;
        }
    } else {
        ret = 1;
    }
    return ret;
}