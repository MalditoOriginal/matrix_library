#include "s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(s21_inverse_matrix_1) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 2;
  matrix.matrix[0][1] = 8;
  matrix.matrix[0][2] = 2;
  matrix.matrix[1][0] = 8;
  matrix.matrix[1][1] = 2;
  matrix.matrix[1][2] = 8;
  matrix.matrix[2][0] = 2;
  matrix.matrix[2][1] = -8;
  matrix.matrix[2][2] = -2;
  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), OK);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(6, 8, &matrix);
  matrixFull(5, &matrix);
  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), CALC_ERROR);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(0, 0, &matrix);
  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), MATRIX_ERROR);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(2, 2, &matrix);
  matrixFull(7, &matrix);
  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), OK);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_inverse_matrix_test(void) {
  Suite *s = suite_create("s21_inverse_matrix_test");
  TCase *tc = tcase_create("s21_inverse_matrix_test");
  tcase_add_test(tc, s21_inverse_matrix_1);
  tcase_add_test(tc, s21_inverse_matrix_2);
  tcase_add_test(tc, s21_inverse_matrix_3);
  tcase_add_test(tc, s21_inverse_matrix_4);
  suite_add_tcase(s, tc);
  return s;
}