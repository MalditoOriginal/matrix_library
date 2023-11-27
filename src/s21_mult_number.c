#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  /* Check for invalid input matrix or null result matrix pointer
  Create the result matrix_struct
  */
  if (matrixWrong(A) || result == NULL ||
      (s21_create_matrix(A->rows, A->columns, result) != 0)) {
    return MATRIX_ERROR;  // Error: Invalid matrix or null result matrix pointer
                          // or mem           allocation failed
  }

  // Multiply each element of A by the given number
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = matrixVal(A, i, j) * number;
    }
  }

  return 0;  // Success
}
