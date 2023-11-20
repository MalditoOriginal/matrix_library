#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  // Check for invalid input matrices
  if (matrixWrong(A) || matrixWrong(B)) {
    return 1;  // Error: Invalid matrix
  }

  // Check if matrices A and B have the same dimensions
  if (!sizeCheck(A, B)) {
    return 2;  // Error: Matrices have different dimensions
  }

  // Create the result matrix
  if (s21_create_matrix(A->rows, A->cols, result)) {
    // Add corresponding elements of A and B to populate the result matrix
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->cols; j++) {
        result->matrix[i][j] = matrixVal(A, i, j) + matrixVal(B, i, j);
      }
    }
  }
  return 0;
}
