#include "s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(s21_eq_matrix_1) {
  matrix_t matrixA = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(2, 8, &matrixA);
  s21_create_matrix(2, 8, &matrixB);
  matrixFull(1, &matrixA);
  matrixFull(1, &matrixB);
  ck_assert_int_eq(s21_eq_matrix(&matrixA, &matrixB), SUCCESS);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t matrixA = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(2, 8, &matrixA);
  s21_create_matrix(2, 8, &matrixB);
  matrixFull(-1, &matrixA);
  matrixFull(5, &matrixB);
  ck_assert_int_eq(s21_eq_matrix(&matrixA, &matrixB), FAILURE);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t matrixA = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t matrixB = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(2, 3, &matrixA);
  s21_create_matrix(3, 2, &matrixB);
  matrixFull(1, &matrixA);
  matrixFull(1, &matrixB);
  ck_assert_int_eq(s21_eq_matrix(&matrixA, &matrixB), FAILURE);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

Suite *s21_eq_matrix_test(void) {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc = tcase_create("s21_eq_matrix");
  tcase_add_test(tc, s21_eq_matrix_1);
  tcase_add_test(tc, s21_eq_matrix_2);
  tcase_add_test(tc, s21_eq_matrix_3);
  suite_add_tcase(s, tc);
  return s;
}