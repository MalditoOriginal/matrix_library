#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define EPSILON 1e-7

enum status { OK, MATRIX_ERROR, CALC_ERROR };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int cols, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void rmRowCol(matrix_t *origMatrix, matrix_t *result, int i, int j);
int sizeCheck(matrix_t *A, matrix_t *B);
void matrixFull(double count, matrix_t *matrix);
double matrixVal(matrix_t *A, int row, int col);
int matrixWrong(matrix_t *result);
bool matrix_error(matrix_t *A, matrix_t *B, matrix_t *result);