#include "s21_matrix.h"

void rmRowCol(matrix_t *origMatrix, matrix_t *result, int i, int j) {
    s21_create_matrix(origMatrix->rows-1, origMatrix->cols-1, result);
    int new_rows = 0, new_cols = 0, row, col;

    for (row = 0; row < origMatrix->rows; row++) {
        if (row != i) {
            for (col = 0; col < origMatrix->cols; col++) {
                if (col != j) {
                    result->matrix[new_rows][new_cols] = origMatrix->matrix[row][col];
                    new_cols++;
                }
            }
            new_cols = 0;
            new_rows = 0;
        }
    }
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int out = 0;
  if (matrixWrong(A) == 0) {
    out = s21_create_matrix(A->cols, A->rows, result);
    if (out == 0) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  } else {
    out = 1;
  }
  return out;
}

int matrixWrong(matrix_t *result) {
  int out = 1;
  if (result->cols > 0 && result->rows > 0 && result->matrix != NULL &&
      result != NULL)
    out = 0;
  return out;
}

double matrixVal(matrix_t *A, int row, int colummn) {
  return A->matrix[row][colummn];
}

int sizeCheck(matrix_t *A, matrix_t *B) {
  int out = 0;
  if (A->rows == B->rows && A->cols == B->cols) {
    out = 1;
  }
  return out;
}