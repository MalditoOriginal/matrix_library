#include "s21_matrix.h"

void rmRowCol(matrix_t *origMatrix, matrix_t *result, int i, int j) {
    s21_create_matrix(origMatrix->rows - 1, origMatrix->cols - 1, result);
    int new_rows = 0, new_cols = 0, row, col;

    for (row = 0; row < origMatrix->rows; row++) {
        if (row != i) {
            for (col = 0; col < origMatrix->cols; col++) {
                if (col != j) {
                    result->matrix[new_rows][new_cols] = origMatrix->matrix[row][col];
                    new_cols++;
                }
            }
            new_rows++;  // Incremented here to move to the next row in the result matrix
            new_cols = 0;  // Reset new_cols for the next row
        }
    }
}

int s21_transpose(matrix_t *inputMatrix, matrix_t *resultMatrix) {
    // Check if the input matrix is valid
    if (matrixWrong(inputMatrix)) {
        return 1;  // Invalid input matrix
    }

    // Create a new matrix with swapped rows and columns
  if (s21_create_matrix(inputMatrix->cols, inputMatrix->rows, resultMatrix))
{    // Perform the transpose operation
    for (int i = 0; i < resultMatrix->rows; i++) {
        for (int j = 0; j < resultMatrix->cols; j++) {
            resultMatrix->matrix[i][j] = inputMatrix->matrix[j][i];
        }
    }
    }

    return 0;  // Success
}


int matrixWrong(matrix_t *result) {
    if (result != NULL && result->matrix != NULL && result->cols > 0 && result->rows > 0) {
        return 0;  // Matrix is valid
    }
    return 1;  // Matrix is invalid
}

double matrixVal(matrix_t *A, int row, int colummn) {
  return A->matrix[row][colummn];
}

int sizeCheck(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->cols == B->cols) ? 1 : 0;
}