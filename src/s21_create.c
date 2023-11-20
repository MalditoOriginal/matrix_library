#include "s21_matrix.h"

int s21_create_matrix(int rows, int cols, matrix_t *result) {
    int ret = 0; // Assume success initially

    if (rows <= 0 || cols <= 0) {
        ret = 1; // Invalid matrix dimensions
    } else {
        result->rows = rows;
        result->cols = cols;
        result->matrix = (double **)calloc(rows, sizeof(double *));

        if (result->matrix == NULL) {
            ret = 1; // Memory allocation failed for rows
        } else {
            for (int i = 0; i < rows; i++) {
                result->matrix[i] = (double *)calloc(cols, sizeof(double));

                if (result->matrix[i] == NULL) {
                    // Memory allocation failed for a row, clean up and set error
                    s21_remove_matrix(result);
                    ret = 1;
                    break; // Exit the loop on failure
                }
            }
        }
    }

    return ret;
}

void s21_remove_matrix(matrix_t *A) {
    if (A != NULL) {
        if (A->matrix != NULL) {
            for (int i = 0; i < A->rows; i++) {
                free(A->matrix[i]);
                A->matrix[i] = NULL; // Set the pointer to NULL after freeing
            }
            free(A->matrix);
            A->matrix = NULL; // Set the pointer to NULL after freeing
        }
        A->rows = 0;
        A->cols = 0;
    }
}
