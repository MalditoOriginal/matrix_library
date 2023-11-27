#include "s21_matrix.h"

void rmRowCol(matrix_t *origMatrix, matrix_t *result, int i, int j) {
  s21_create_matrix(origMatrix->rows - 1, origMatrix->columns - 1, result);
  int new_rows = 0, new_cols = 0, row, col;
  for (row = 0; row < origMatrix->rows; row++) {
    if (row != i) {
      for (col = 0; col < origMatrix->columns; col++) {
        if (col != j) {
          result->matrix[new_rows][new_cols] = origMatrix->matrix[row][col];
          new_cols++;
        }
      }
      new_rows++;    // Incremented here to move to the next row in the result
                     // matrix
      new_cols = 0;  // Reset new_cols for the next row
    }
  }
}

int s21_transpose(matrix_t *inputMatrix, matrix_t *resultMatrix) {
  /* Check if the input matrix is valid or null result matrix pointer
  Create a new matrix with swapped rows and columns
  */

  if (matrixWrong(inputMatrix) || resultMatrix == NULL ||
      (s21_create_matrix(inputMatrix->columns, inputMatrix->rows,
                         resultMatrix) != 0)) {
    return MATRIX_ERROR;  // Error: Invalid input matrix or null result matrix
                          // pointer or memory allocation failed for the result
                          // matrix
  }

  // Perform the transpose operation
  for (int i = 0; i < resultMatrix->rows; i++) {
    for (int j = 0; j < resultMatrix->columns; j++) {
      resultMatrix->matrix[i][j] = inputMatrix->matrix[j][i];
    }
  }

  return 0;  // Success
}

int matrixWrong(matrix_t *result) {
  return (result != NULL && result->matrix != NULL && result->columns > 0 &&
          result->rows > 0)
             ? 0
             : 1;
}

double matrixVal(matrix_t *A, int row, int colummn) {
  return A->matrix[row][colummn];
}

int sizeCheck(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns) ? 1 : 0;
}

void matrixFull(double count, matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = count++;
    }
  }
}

bool matrix_error(matrix_t *A, matrix_t *B, matrix_t *result) {
  // Check for invalid input matrices or null result matrix pointer; create the
  // result matrix
  return (matrixWrong(A) || matrixWrong(B) || result == NULL ||
          (s21_create_matrix(A->rows, A->columns, result) != 0))
             ? false
             : true;  // Error: Invalid matrix or null result matrix pointer;
                      // Mem allocation failed for the result matrix_struct
}
