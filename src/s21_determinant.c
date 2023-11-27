#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int ret = 0;
  *result = 0;
  if (matrixWrong(A) != 0) {
    ret = 1;  // Invalid matrix
  } else if (A->columns != A->rows) {
    ret = 2;  // Not a square matrix
  } else if (A->rows == 1) {
    *result = matrixVal(A, 0, 0);
  } else if (A->rows == 2) {
    *result = matrixVal(A, 0, 0) * matrixVal(A, 1, 1) -
              matrixVal(A, 0, 1) * matrixVal(A, 1, 0);
  } else {
    for (int i = 0; i < A->rows; i++) {
      matrix_t res;
      rmRowCol(A, &res, i, 0);
      double middle = 0;
      ret = s21_determinant(&res, &middle);
      s21_remove_matrix(&res);
      if (ret != 0) {
        return ret;  // Propagate the error
      }
      *result += pow(-1, i + 2) * matrixVal(A, i, 0) * middle;
    }
  }
  return ret;  // Success or Error
}
