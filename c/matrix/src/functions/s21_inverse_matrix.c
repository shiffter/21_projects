#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int out = 0;
  if (incorrect_matrix(A))
    return 1;
  if (A->rows != A->columns)
    return 2;
  double D = 0;

  if (!s21_determinant(A, &D) && D && !out) {
    matrix_t alg_complements = INIT_M;
    out = s21_calc_complements(A, &alg_complements);
    if (!out)
      out = s21_transpose(&alg_complements, result);
    for (int i = 0; !out && i < result->rows; i++)
      for (int j = 0; !out && j < result->columns; j++) {
        result->matrix[i][j] /= (D);
      }
    s21_remove_matrix(&alg_complements);
  } else if (D == 0) {
    out = 2;
  } else {
    out = 1;
  }
  return out;
}
