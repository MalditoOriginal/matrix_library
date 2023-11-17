#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ret = SUCCESS, i = 0, j = 0;
  if (A->rows == B->rows && A->cols == B->cols) {
    for (i = 0; i < A->rows && ret != FAILURE; i++) {
      for (j = 0; j < A->cols && ret != FAILURE; j++) {
        double eps = fabs(matrixVal(A, i, j) - matrixVal(B, i, j));
        if (eps < 1e-7) {
          ret = SUCCESS;
        } else {
          ret = FAILURE;
        }
      }
    }
  } else {
    ret = FAILURE;
  }
  return ret;
}