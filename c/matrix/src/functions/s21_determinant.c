#include "../s21_matrix.h"

int s21_determinant(matrix_t *matrix, double *D) {
  int out = 0;
  *D = 0;
  if (incorrect_matrix(matrix))
    out = 1;
  else if (matrix->rows != matrix->columns)
    out = 2;
  if (!out) {
    if (matrix->rows == 1)
      *D = matrix->matrix[0][0];
    if (matrix->rows == 2) {
      det_2x2(matrix, D);
    } else if (matrix->rows > 2) {
      for (int j = 0; j < matrix->rows && !out; j++) {
        double tmp_det = 0;
        matrix_t tmp = INIT_M;
        find_minor(matrix, 0, j, &tmp);
        s21_determinant(&tmp, &tmp_det);
        *D += pow(-1, j) * matrix->matrix[0][j] * (tmp_det);
        s21_remove_matrix(&tmp);
      }
    }
  }
  return out;
}
