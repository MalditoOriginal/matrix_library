#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!matrix_error(A, B, result)) {
    return MATRIX_ERROR;
  }

  // Check if the number of columns in A is not equal to the number of rows in B
  if (A->columns != B->rows) {
    return CALC_ERROR;  // Error: Incompatible matrix dimensions for
                        // multiplication
  }

  // Perform matrix multiplication
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      double product = 0;
      for (int col = 0; col < B->rows; col++) {
        product += matrixVal(A, i, col) * matrixVal(B, col, j);
      }
      result->matrix[i][j] = product;
    }
  }

  return OK;  // Success
}