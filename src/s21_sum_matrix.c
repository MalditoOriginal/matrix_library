#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int out = 0, i = 0, j = 0;
  if (matrixWrong(A) == 0 && matrixWrong(B) == 0) {
    if (sizeCheck(A, B)) {
      out = s21_create_matrix(A->rows, A->cols, result);
      if (out == 0) {
        for (i = 0; i < result->rows; i++) {
          for (j = 0; j < result->cols; j++) {
            result->matrix[i][j] = matrixVal(A, i, j) + matrixVal(B, i, j);
          }
        }
      }
    } else {
      out = 2;
    }
  } else {
    out = 1;
  }
  return out;
}