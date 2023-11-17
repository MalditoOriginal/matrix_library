#include "s21_matrix.h"

int s21_create_matrix(int rows, int cols, matrix_t *result) {
    int ret = 0, i;

    if (rows <= 0 || cols <= 0) {
        ret = 1;
    } else {
        result->rows = rows;
        result->cols = cols;
        result->matrix = (double **)calloc(rows, sizeof(double *));

        if (result->matrix == NULL) {
            ret = 1;
        } else {
            for (i = 0; i < rows; i++) {
                result->matrix[i] = (double *)calloc(cols, sizeof(double));

                if (result->matrix[i] == NULL) {
                    ret = 1;
                    s21_remove_matrix(result);
                }
            }
        }
    }

    return ret;
}

void s21_remove_matrix(matrix_t *A) {
    int i;
    if (A != NULL) {
        if (A->matrix != NULL) {
            for (i = 0; i < A->rows; i++) {
                free(A->matrix[i]);
            }
            free(A->matrix);
            A->matrix = NULL;            
        }
        A->rows = 0;
        A->cols = 0;
    }
}