#include "s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t matrixA = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(7, 4, &matrixA);
  s21_create_matrix(4, 3, &matrixB);
  matrixFull(9, &matrixA);
  matrixFull(6, &matrixB);
  ck_assert_int_eq(s21_mult_matrix(&matrixA, &matrixB, &result), OK);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t matrixA = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(4, 3, &matrixA);
  matrixFull(1, &matrixA);
  s21_create_matrix(-3, 5, &matrixB);
  matrixFull(6, &matrixB);
  ck_assert_int_eq(s21_mult_matrix(&matrixA, &matrixB, &result), MATRIX_ERROR);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t matrixA = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(2, 8, &matrixA);
  s21_create_matrix(4, 5, &matrixB);
  matrixFull(2, &matrixA);
  matrixFull(5, &matrixB);
  ck_assert_int_eq(s21_mult_matrix(&matrixA, &matrixB, &result), CALC_ERROR);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t matrixA = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(4, 6, &matrixA);
  s21_create_matrix(3, 4, &matrixB);
  matrixFull(-5, &matrixA);
  matrixFull(6, &matrixB);
  ck_assert_int_eq(s21_mult_matrix(&matrixA, &matrixB, &result), CALC_ERROR);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_matrix_test(void) {
  Suite *s = suite_create("s21_mult_matrix_test");
  TCase *tc = tcase_create("s21_mult_matrix_test");
  tcase_add_test(tc, s21_mult_matrix_1);
  tcase_add_test(tc, s21_mult_matrix_2);
  tcase_add_test(tc, s21_mult_matrix_3);
  tcase_add_test(tc, s21_mult_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}