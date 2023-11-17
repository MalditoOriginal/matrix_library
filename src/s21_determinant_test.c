#include "s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(s21_determinant_1) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  double result;
  s21_create_matrix(5, 5, &matrix);
  matrixFull(-1, &matrix);
  ck_assert_int_eq(s21_determinant(&matrix, &result), 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  double result;
  s21_create_matrix(6, 4, &matrix);
  matrixFull(-1.676675645, &matrix);
  ck_assert_int_eq(s21_determinant(&matrix, &result), CALC_ERROR);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  double result;
  s21_create_matrix(0, 4, &matrix);
  ck_assert_int_eq(s21_determinant(&matrix, &result), MATRIX_ERROR);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  double result = 0;
  s21_create_matrix(2, 2, &matrix);
  matrixFull(5, &matrix);
  ck_assert_int_eq(s21_determinant(&matrix, &result), OK);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant_5) {
  double result = 0;
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 9;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[0][3] = 4;

  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 4;
  matrix.matrix[1][3] = 4;

  matrix.matrix[2][0] = 4;
  matrix.matrix[2][1] = 4;
  matrix.matrix[2][2] = 9;
  matrix.matrix[2][3] = 9;

  matrix.matrix[3][0] = 1;
  matrix.matrix[3][1] = 1;
  matrix.matrix[3][2] = 5;
  matrix.matrix[3][3] = 1;
  s21_determinant(&matrix, &result);
  ck_assert_int_eq(result, -578);
  s21_remove_matrix(&matrix);
}
END_TEST

Suite *s21_determinant_test(void) {
  Suite *s = suite_create("s21_determinant_test");
  TCase *tc = tcase_create("s21_determinant_test");
  tcase_add_test(tc, s21_determinant_1);
  tcase_add_test(tc, s21_determinant_2);
  tcase_add_test(tc, s21_determinant_3);
  tcase_add_test(tc, s21_determinant_4);
  tcase_add_test(tc, s21_determinant_5);
  suite_add_tcase(s, tc);
  return s;
}