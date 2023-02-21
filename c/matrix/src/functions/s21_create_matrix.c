#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int out = 0;
  result->matrix = NULL;
  result->rows = rows;
  result->columns = columns;
  if (rows <= 0 || columns <= 0)
    out = 1;
  if (!out) {
    result->matrix = (double **)malloc(sizeof(double *) * rows +
                                       sizeof(double) * rows * columns);
    if (result->matrix) {
      double *ptr = (double *)(result->matrix + rows);
      for (int i = 0; i < rows; i++)
        result->matrix[i] = (ptr + columns * i);

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
          result->matrix[i][j] = 0;
      }
    } else {
      out = 1;
    }
  }
  return out;
}
