#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int out = SUCCESS;
  if (A == NULL || B == NULL)
    out = FAILURE;
  if (out && A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns && out; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS)
          out = FAILURE;
        else
          continue;
      }
    }
  } else {
    out = FAILURE;
  }
  return out;
}
