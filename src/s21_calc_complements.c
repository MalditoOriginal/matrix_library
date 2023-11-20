#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int ret = 0;

  if (matrixWrong(A) == 0) {
    if (A->rows == A->cols) {
      ret = s21_create_matrix(A->rows, A->cols, result);

      if (ret == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->cols; j++) {
            matrix_t cofactor;
            double determinant = 0;

            // Calculate the determinant of the submatrix
            rmRowCol(A, &cofactor, i, j);
            ret = s21_determinant(&cofactor, &determinant);
            s21_remove_matrix(&cofactor);

            if (ret == 0) {
              // Apply the cofactor formula
              result->matrix[i][j] = determinant * pow(-1, i + j);
            } else {
              // Error in determinant calculation
              s21_remove_matrix(result);
              return ret;
            }
          }
        }
      }
    } else {
      // Not a square matrix
      ret = 2;
    }
  } else {
    // Invalid matrix
    ret = 1;
  }

  return ret;
}