#include "s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(s21_mul_number_1) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(3, 3, &matrix);
  matrixFull(-1, &matrix);
  ck_assert_int_eq(s21_mul_number(&matrix, 2, &result), OK);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mul_number_2) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(0, 3, &matrix);
  ck_assert_int_eq(s21_mul_number(&matrix, 2, &result), MATRIX_ERROR);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mul_number_3) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(1, 3, &matrix);
  matrixFull(1, &matrix);
  ck_assert_int_eq(s21_mul_number(&matrix, 2.2222222, &result), OK);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mul_number_test(void) {
  Suite *s = suite_create("s21_mul_number_test");
  TCase *tc = tcase_create("s21_mul_number_test");
  tcase_add_test(tc, s21_mul_number_1);
  tcase_add_test(tc, s21_mul_number_2);
  tcase_add_test(tc, s21_mul_number_3);
  suite_add_tcase(s, tc);
  return s;
}