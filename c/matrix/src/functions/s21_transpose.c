#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int out = 0;
  if (incorrect_matrix(A))
    out = 1;
  if (!out) {
    out = s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; !out && i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++)
        result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return out;
}
