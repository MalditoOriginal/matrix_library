#include "s21_matrix.h"

int s21_create_matrix(int rows, int cols, matrix_t *result) {
  if (result == NULL || rows <= 0 || cols <= 0) {
    return 1;  // Error: Invalid result matrix pointer or non-positive
               // dimensions
  }

  // Allocate memory for the matrix array
  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) {
    return 1;  // Error: Memory allocation failure for matrix array
  }

  result->rows = rows;
  result->columns = cols;

  for (int i = 0; i < rows; i++) {
    // Allocate memory for each row
    result->matrix[i] = (double *)calloc(cols, sizeof(double));
    if (result->matrix[i] == NULL) {
      // Memory allocation failed for a row, clean up and set error
      s21_remove_matrix(result);
      return 1;  // Error: Memory allocation failed for a row
    }
  }

  return 0;  // Success
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
        A->matrix[i] = NULL;  // Set the pointer to NULL after freeing
      }
      free(A->matrix);
      A->matrix = NULL;  // Set the pointer to NULL after freeing
    }
    A->rows = 0;
    A->columns = 0;
  }
}
