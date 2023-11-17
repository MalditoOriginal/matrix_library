#include "s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(s21_calc_complements_1) {
    matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
    matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};

    s21_create_matrix(5, 5, &matrix);
    matrixFull(13, &matrix);

    ck_assert_int_eq(s21_calc_complements(&matrix, &result), OK);
    s21_remove_matrix(&matrix);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(5, 7, &matrix);
  matrixFull(2, &matrix);
  ck_assert_int_eq(s21_calc_complements(&matrix, &result), CALC_ERROR);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .cols = 0, .matrix = NULL};
  s21_create_matrix(0, 0, &matrix);
  matrixFull(1, &matrix);
  ck_assert_int_eq(s21_calc_complements(&matrix, &result), MATRIX_ERROR);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_calc_complements_test(void) {
    Suite *s = suite_create("s21_calc_complements_test");
    TCase *tc = tcase_create("s21_calc_complements_test");

  tcase_add_test(tc, s21_calc_complements_1);
  tcase_add_test(tc, s21_calc_complements_2);
  tcase_add_test(tc, s21_calc_complements_3);

  suite_add_tcase(s, tc);
  
  return s;
}