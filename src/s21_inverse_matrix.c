#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int ret = 1;
  if (matrixWrong(A) == 0) {
    ret = 2;
    double inter_out;
    ret = s21_determinant(A, &inter_out);
    if (ret == 0) {
      if (fabs(inter_out) > 1e-07) {
        matrix_t for_alg_ext;
        ret = s21_calc_complements(A, &for_alg_ext);
        if (ret == 0) {
          matrix_t for_transp;
          ret = s21_transpose(&for_alg_ext, &for_transp);
          if (ret == 0) {
            ret = s21_mul_number(&for_transp, 1.0 / inter_out, result);
          }
          s21_remove_matrix(&for_transp);
        }
        s21_remove_matrix(&for_alg_ext);
      }
    }
  }
  return ret;
}