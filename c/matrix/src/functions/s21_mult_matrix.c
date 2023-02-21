#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int out = 0;
  if (incorrect_matrix(A) || incorrect_matrix(B))
    out = 1;
  if (A->columns != B->rows)
    out = 2;
  if (!out) {
    out = s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; !out && i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        double tmp = 0.0;
        for (int k = 0; k < A->columns; k++)
          tmp += (A->matrix[i][k] * B->matrix[k][j]);
        result->matrix[i][j] = tmp;
      }
    }
  }
  return out;
}
