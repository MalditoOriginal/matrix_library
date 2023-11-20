#include "s21_matrix.h"

int s21_mul_number(matrix_t *A, double number, matrix_t *result) {
  // Check for invalid input matrix
  if (matrixWrong(A)) {
    return 1;  // Error: Invalid matrix
  }
  if (s21_create_matrix(A->rows, A->cols, result)) {
    // Multiply each element of A by the given number
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->cols; j++) {
        result->matrix[i][j] = matrixVal(A, i, j) * number;
      }
    }
  }
  return 0;
}