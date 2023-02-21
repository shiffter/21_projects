#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int out = 0;
  if (compare_matrix(A, B))
    out = 2;
  if (!out) {
    out = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; !out && i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return out;
}
