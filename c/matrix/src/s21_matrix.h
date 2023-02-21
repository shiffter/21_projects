#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define EPS 1e-6
#define INIT_M                                                                 \
  (matrix_t) { NULL, 0, 0 }

#define SUCCESS 1
#define FAILURE 0

/* Matrix structure */
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

/* Matrix operations */
void s21_remove_matrix(matrix_t *);
int s21_create_matrix(int, int, matrix_t *);
int s21_eq_matrix(matrix_t *, matrix_t *);
int s21_sum_matrix(matrix_t *, matrix_t *, matrix_t *);
int s21_sub_matrix(matrix_t *, matrix_t *, matrix_t *);
int s21_mult_number(matrix_t *, double, matrix_t *);
int s21_mult_matrix(matrix_t *, matrix_t *, matrix_t *);
int s21_transpose(matrix_t *, matrix_t *);
int s21_calc_complements(matrix_t *, matrix_t *);
int s21_determinant(matrix_t *, double *);
int s21_inverse_matrix(matrix_t *, matrix_t *);

/* Helpers function */
void matrix_print(matrix_t *);
int s21_minor(matrix_t *matrix, double *M, int row, int column);
double det_2x2(matrix_t *A, double *res);
int find_minor(matrix_t *A, int row, int column, matrix_t *res);
int incorrect_matrix(matrix_t *matrix);
int compare_matrix(matrix_t *, matrix_t *);

static const double MATR[5][5] = {
    {12, 5, -3, 13, 321},
    {8, -4, 123, 12, 132},
    {0.0, 12, -78, 42, 53},
    {1, 0, -25, 13, 41.3},
    {82.3, -41.6, 123.5, 12.3, 102.1},

};

#endif // SRC_S21_MATRIX_H_
