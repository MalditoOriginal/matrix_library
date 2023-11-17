#include "s21_matrix.h"

int s21_mul_number(matrix_t *A, double number, matrix_t *result) {
  int out = 0, i = 0, j = 0;
  if (matrixWrong(A) == 0) {
    out = s21_create_matrix(A->rows, A->cols, result);
    if (out == 0) {
      for (i = 0; i < A->rows; i++) {
        for (j = 0; j < A->cols; j++) {
          result->matrix[i][j] = matrixVal(A, i, j) * number;
        }
      }
    }
  } else {
    out = 1;
  }
  return out;
}