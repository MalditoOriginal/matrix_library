#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!matrix_error(A, B, result)) {
    return MATRIX_ERROR;
  }

  // Check if matrices A and B have the same dimensions
  if (!sizeCheck(A, B)) {
    return CALC_ERROR;  // Error: Matrices have different dimensions
  }

  // Add corresponding elements of A and B to populate the result matrix
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = matrixVal(A, i, j) + matrixVal(B, i, j);
    }
  }

  return 0;  // Success
}