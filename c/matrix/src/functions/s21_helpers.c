#include "../s21_matrix.h"

void matrix_print(matrix_t *matrixx) {
  int rows = matrixx->rows, columns = matrixx->columns;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
      printf("%5.6lf ", matrixx->matrix[i][j]);
    printf("\n");
  }
}

double det_2x2(matrix_t *A, double *res) {
  double sum = 0.0, diff = 0.0, tmp_res = 0;
  if (A->rows == 2) {
    sum = A->matrix[0][0] * A->matrix[1][1];
    diff = A->matrix[1][0] * A->matrix[0][1];
    tmp_res = sum - diff;
    *res = tmp_res;
  }
  return 0;
}

int find_minor(matrix_t *A, int row, int column, matrix_t *res) {
  int out = 0;
  if (incorrect_matrix(A))
    return 1;
  s21_create_matrix(A->rows - 1, A->columns - 1, res);
  for (int i = 0, k = 0; i < A->rows && !out;) {
    if (i == row) {
      i++;
      continue;
    }
    for (int j = 0, m = 0; j < A->columns;) {
      if (j == column) {
        j++;
        continue;
      }
      res->matrix[k][m] = A->matrix[i][j];
      j++;
      m++;
    }
    i++;
    k++;
  }
  return out;
}

int incorrect_matrix(matrix_t *matrix) {
  int out = 0;
  if (matrix->matrix == NULL || matrix->rows <= 0 || matrix->columns <= 0)
    out = 1;
  return out;
}

int compare_matrix(matrix_t *M1, matrix_t *M2) {
  int out = 0;
  if (M1->rows != M2->rows || M1->columns != M2->columns)
    out = 1;
  return out;
}
