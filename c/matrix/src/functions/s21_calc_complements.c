#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int out = 0;
  if (incorrect_matrix(A))
    return 1;
  if (A->columns != A->rows)
    return 2;
  out = s21_create_matrix(A->rows, A->columns, result);
  if (!out) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; !out && j < A->columns; j++) {
        double D = 0;
        matrix_t tmp_m = INIT_M;
        if (!find_minor(A, i, j, &tmp_m) && !s21_determinant(&tmp_m, &D)) {
          if ((i + j) % 2 != 0)
            D *= -1.0;
          result->matrix[i][j] = D;
          s21_remove_matrix(&tmp_m);
        } else {
          out = 1;
        }
      }
  }
  return out;
}
