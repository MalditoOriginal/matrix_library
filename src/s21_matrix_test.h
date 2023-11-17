#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#define OK 0
#define MATRIX_ERROR 1
#define CALC_ERROR 2

int run_suite(Suite *);

Suite *s21_create_mat(void);
Suite *s21_eq_matrix_test(void);
Suite *s21_sum_matrix_test(void);
Suite *s21_sub_matrix_test(void);
Suite *s21_determinant_test(void);
Suite *s21_mul_number_test(void);
Suite *s21_calc_complements_test(void);
Suite *s21_inverse_matrix_test(void);
Suite *s21_mul_matrix_test(void);