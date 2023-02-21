#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int out = 0;
  if (A->matrix != NULL) {
    out = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; !out && i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
    }
  } else {
    out = 1;
  }
  return out;
}
