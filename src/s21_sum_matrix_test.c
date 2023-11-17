#include "s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(s21_sum_matrix_1) {
  matrix_t matrixA = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(2, 8, &matrixA);
  s21_create_matrix(2, 8, &matrixB);
  matrixFull(1.986875765, &matrixA);
  matrixFull(5.9867576, &matrixB);
  ck_assert_int_eq(s21_sum_matrix(&matrixA, &matrixB, &result), OK);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t matrixA = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(2, 8, &matrixA);
  matrixFull(1, &matrixA);
  s21_create_matrix(0, 8, &matrixB);
  ck_assert_int_eq(s21_sum_matrix(&matrixA, &matrixB, &result), MATRIX_ERROR);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t matrixA = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(2, 8, &matrixA);
  s21_create_matrix(2, 7, &matrixB);
  matrixFull(1, &matrixA);
  matrixFull(2, &matrixB);
  ck_assert_int_eq(s21_sum_matrix(&matrixA, &matrixB, &result), CALC_ERROR);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_sum_matrix_test(void) {
  Suite *s = suite_create("s21_sum_matrix_test");
  TCase *tc = tcase_create("s21_sum_matrix_test");
  tcase_add_test(tc, s21_sum_matrix_1);
  tcase_add_test(tc, s21_sum_matrix_2);
  tcase_add_test(tc, s21_sum_matrix_3);
  suite_add_tcase(s, tc);
  return s;
}