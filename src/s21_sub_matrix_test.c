#include "s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(s21_sub_matrix_1) {
  matrix_t matrixA = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(4, 3, &matrixA);
  s21_create_matrix(4, 3, &matrixB);
  matrixFull(2.987865, &matrixA);
  matrixFull(6.098686564653, &matrixB);
  ck_assert_int_eq(s21_sub_matrix(&matrixA, &matrixB, &result), OK);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  matrix_t matrixA = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(0, 3, &matrixA);
  matrixFull(0, &matrixA);
  s21_create_matrix(4, 3, &matrixB);
  matrixFull(-4, &matrixB);
  ck_assert_int_eq(s21_sub_matrix(&matrixA, &matrixB, &result), MATRIX_ERROR);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  matrix_t matrixA = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(2, 5, &matrixA);
  s21_create_matrix(4, 5, &matrixB);
  matrixFull(9, &matrixA);
  matrixFull(0, &matrixB);
  ck_assert_int_eq(s21_sub_matrix(&matrixA, &matrixB, &result), CALC_ERROR);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_sub_matrix_test(void) {
  Suite *s = suite_create("s21_sub_matrix_test");
  TCase *tc = tcase_create("s21_sub_matrix_test");
  tcase_add_test(tc, s21_sub_matrix_1);
  tcase_add_test(tc, s21_sub_matrix_2);
  tcase_add_test(tc, s21_sub_matrix_3);
  suite_add_tcase(s, tc);
  return s;
}