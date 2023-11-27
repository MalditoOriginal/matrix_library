#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (A->rows != B->rows || A->columns != B->columns ||
          fabs(matrixVal(A, i, j) - matrixVal(B, i, j)) >= EPSILON) {
        return FAILURE;
      }
    }
  }
  return SUCCESS;
}
