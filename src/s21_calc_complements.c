#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int ret = 0;
  if (matrixWrong(A) != 0) {
    ret = 1;  // Invalid matrix
  } else if (A->rows != A->columns) {
    ret = 2;  // Not a square matrix
  } else {
    ret = s21_create_matrix(A->rows, A->columns, result);
    if (ret == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t cofactor;
          double determinant = 0;
          // Calculate the determinant of the submatrix
          rmRowCol(A, &cofactor, i, j);
          ret = s21_determinant(&cofactor, &determinant);
          s21_remove_matrix(&cofactor);
          if (ret != 0) {
            // Error in determinant calculation
            s21_remove_matrix(result);
            return ret;
          }
          // Apply the cofactor formula
          result->matrix[i][j] = determinant * pow(-1, i + j);
        }
      }
    }
  }
  return ret;
}