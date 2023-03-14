#include "s21_matrix_oop.h"

void S21Matrix::PrintMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// хреновый free
// надо rows_ = 0; cols_ = 0;
// Иначе неконсистентная матрица будет
// Кстати FreeMatrix() по гугл-стилю
void S21Matrix::free_matrix() {
  if (matrix) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix[i];
      matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
  }
}

// Приватной должна быть 100%
double **S21Matrix::alloc() {
  matrix = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix[i] = new double[cols_];
  }
  return matrix;
}

S21Matrix S21Matrix::find_minor(int r, int c) {
  S21Matrix result(rows_ - 1, cols_ - 1);

  for (int i = 0, k = 0; i < rows_;) {
    if (i == r) {
      i++;
      continue;
    }

    for (int j = 0, m = 0; j < cols_;) {
      if (j == c) {
        j++;
        continue;
      }
      result.matrix[k][m] = matrix[i][j];
      j++;
      m++;
    }
    i++;
    k++;
  }
  return result;
}
