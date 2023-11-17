#include "s21_matrix.h"
#include "s21_matrix_test.h"

START_TEST(s21_create_matrix_1) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  ck_assert_int_eq(s21_create_matrix(-1, -3, &matrix), MATRIX_ERROR);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  ck_assert_int_eq(s21_create_matrix(0, 3, &matrix), MATRIX_ERROR);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  ck_assert_int_eq(s21_create_matrix(-1, 4, &matrix), MATRIX_ERROR);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t A = {0};
  int error = MATRIX_ERROR;
  int status = s21_create_matrix(-2, 0, &A);
  ck_assert_int_eq(status, error);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  const int rows = 0;
  const int cols = 5;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), MATRIX_ERROR);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  matrix_t A = {0};
  int error = MATRIX_ERROR;
  int status = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(status, error);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  matrix_t A = {0};
  int error = MATRIX_ERROR;
  int status = s21_create_matrix(2, 0, &A);
  ck_assert_int_eq(status, error);
}
END_TEST

START_TEST(s21_create_matrix_8) {
  matrix_t A = {0};
  int error = MATRIX_ERROR;
  int status = s21_create_matrix(0, 2, &A);
  ck_assert_int_eq(status, error);
}
END_TEST

START_TEST(s21_create_matrix_9) {
  matrix_t matrix = {.rows = 0, .cols = 0, .matrix = NULL};
  ck_assert_int_eq(s21_create_matrix(1, 4, &matrix), OK);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_10) {
  matrix_t A = {0};
  int error = MATRIX_ERROR;
  int status = s21_create_matrix(0, -9, &A);
  ck_assert_int_eq(status, error);
}
END_TEST

START_TEST(s21_create_matrix_11) {
  matrix_t A = {0};
  int error = MATRIX_ERROR;
  int status = s21_create_matrix(-4, -2, &A);
  ck_assert_int_eq(status, error);
}
END_TEST

START_TEST(s21_create_matrix_12) {
  matrix_t A_p = {0};
  matrix_t *A = &A_p;
  int error = OK;
  int status = s21_create_matrix(3, 3, A);
  ck_assert_int_eq(status, error);
  s21_remove_matrix(A);
}
END_TEST

START_TEST(s21_create_matrix_13) {
  matrix_t A = {0};
  int error = OK;
  A.matrix = NULL;
  int status = s21_create_matrix(10, 3, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(status, error);
}
END_TEST

Suite *s21_create_mat(void) {
  Suite *s = suite_create("s21_create_mat");
  TCase *tc = tcase_create("s21_create_mat");

  tcase_add_test(tc, s21_create_matrix_1);
  tcase_add_test(tc, s21_create_matrix_2);
  tcase_add_test(tc, s21_create_matrix_3);
  tcase_add_test(tc, s21_create_matrix_4);
  tcase_add_test(tc, s21_create_matrix_5);
  tcase_add_test(tc, s21_create_matrix_6);
  tcase_add_test(tc, s21_create_matrix_7);
  tcase_add_test(tc, s21_create_matrix_8);
  tcase_add_test(tc, s21_create_matrix_9);
  tcase_add_test(tc, s21_create_matrix_10);
  tcase_add_test(tc, s21_create_matrix_11);
  tcase_add_test(tc, s21_create_matrix_12);
  tcase_add_test(tc, s21_create_matrix_13);

  suite_add_tcase(s, tc);
  return s;
}