#include "s21_matrix.h"

int s21_mul_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int out = 0;
  if (matrixWrong(A) == 0 && matrixWrong(B) == 0) {
    if (A->cols == B->rows) {
      out = s21_create_matrix(A->rows, B->cols, result);
      if (out == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->cols; j++) {
            double mul = 0;
            for (int col = 0; col < B->rows; col++) {
              mul = (matrixVal(A, i, col) * matrixVal(B, col, j)) + mul;
            }
            result->matrix[i][j] = mul;
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