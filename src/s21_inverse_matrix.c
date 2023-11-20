#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int ret = 1;

  // Check if the input matrix is valid
  if (matrixWrong(A) == 0) {
    ret = 2;

    // Calculate the determinant of the input matrix
    double determinant;
    ret = s21_determinant(A, &determinant);

    if (ret == 0 && fabs(determinant) > 1e-07) {
      // Initialize matrices for algebraic complement and its transpose
      matrix_t cofactor_matrix, transposed_cofactor;

      // Calculate the complements of the input matrix
      ret = s21_calc_complements(A, &cofactor_matrix);

      if (ret == 0) {
        // Transpose the matrix of algebraic complements
        ret = s21_transpose(&cofactor_matrix, &transposed_cofactor);

        if (ret == 0) {
          // Calculate the inverse matrix by dividing the transposed complement
          // matrix by the determinant
          ret = s21_mul_number(&transposed_cofactor, 1.0 / determinant, result);
        }

        // Clean up the temporary matrices
        s21_remove_matrix(&transposed_cofactor);
      }

      s21_remove_matrix(&cofactor_matrix);
    }
  }

  return ret;
}
