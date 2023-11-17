# Matrix Operations Library

This library provides a set of functions for performing various matrix operations in C. It includes functions for matrix creation, addition, subtraction, multiplication, transposition, determinant calculation, and matrix inversion.

## Table of Contents

- [Overview](#overview)
- [Functions](#functions)
  - [Matrix Creation](#matrix-creation)
  - [Matrix Removal](#matrix-removal)
  - [Matrix Equality Check](#matrix-equality-check)
  - [Matrix Addition and Subtraction](#matrix-addition-and-subtraction)
  - [Matrix Scalar Multiplication](#matrix-scalar-multiplication)
  - [Matrix Multiplication](#matrix-multiplication)
  - [Matrix Transposition](#matrix-transposition)
  - [Matrix Complement Calculation](#matrix-complement-calculation)
  - [Matrix Determinant Calculation](#matrix-determinant-calculation)
  - [Matrix Inversion](#matrix-inversion)
- [Utility Functions](#utility-functions)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Overview

The library defines a `matrix_t` structure to represent matrices, with associated functions to perform common matrix operations. Each function is designed to operate on matrices and, in some cases, scalar values.

## Functions

### Matrix Creation

- **`int s21_create_matrix(int rows, int cols, matrix_t *result)`**
  - Creates a matrix with the specified number of rows and columns.
  - Returns `SUCCESS` on successful creation, `FAILURE` otherwise.

- **`void s21_remove_matrix(matrix_t *A)`**
  - Removes a matrix and frees the associated memory.

### Matrix Equality Check

- **`int s21_eq_matrix(matrix_t *A, matrix_t *B)`**
  - Checks if two matrices are equal.
  - Returns `1` if equal, `0` otherwise.

### Matrix Addition and Subtraction

- **`int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result)`**
  - Adds two matrices.
  - Returns `SUCCESS` on successful addition, `FAILURE` otherwise.

- **`int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result)`**
  - Subtracts matrix B from matrix A.
  - Returns `SUCCESS` on successful subtraction, `FAILURE` otherwise.

### Matrix Scalar Multiplication

- **`int s21_mul_number(matrix_t *A, double number, matrix_t *result)`**
  - Multiplies a matrix by a scalar.
  - Returns `SUCCESS` on successful multiplication, `FAILURE` otherwise.

### Matrix Multiplication

- **`int s21_mul_matrix(matrix_t *A, matrix_t *B, matrix_t *result)`**
  - Multiplies two matrices.
  - Returns `SUCCESS` on successful multiplication, `FAILURE` otherwise.

### Matrix Transposition

- **`int s21_transpose(matrix_t *A, matrix_t *result)`**
  - Transposes a matrix.
  - Returns `SUCCESS` on successful transposition, `FAILURE` otherwise.

### Matrix Complement Calculation

- **`int s21_calc_complements(matrix_t *A, matrix_t *result)`**
  - Calculates the complements of a matrix.
  - Returns `SUCCESS` on successful calculation, `FAILURE` otherwise.

### Matrix Determinant Calculation

- **`int s21_determinant(matrix_t *A, double *result)`**
  - Calculates the determinant of a matrix.
  - Returns `SUCCESS` on successful calculation, `FAILURE` otherwise.

### Matrix Inversion

- **`int s21_inverse_matrix(matrix_t *A, matrix_t *result)`**
  - Inverts a matrix.
  - Returns `SUCCESS` on successful inversion, `FAILURE` otherwise.

## Utility Functions

- **`void rmRowCol(matrix_t *origMatrix, matrix_t *result, int i, int j)`**
  - Removes a specified row and column from a matrix.

- **`int sizeCheck(matrix_t *A, matrix_t *B)`**
  - Checks if two matrices have compatible dimensions for a given operation.

- **`void matrixFull(double count, matrix_t *matrix)`**
  - Fills a matrix with a specified value.

- **`double matrixVal(matrix_t *A, int row, int col)`**
  - Retrieves a value from a matrix at a specified position.

- **`int matrixWrong(matrix_t *result)`**
  - Checks if a matrix operation resulted in an error.

## Usage

To use this library, include the provided header file in your C code:

```c
#include "matrix.h"
