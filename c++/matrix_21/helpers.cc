#include "s21_matrix_oop.h"

void S21Matrix::PrintMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      cout << (*this)(i, j) << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void S21Matrix::free_matrix() {
  if (matrix) {
    delete[] matrix;
    matrix = nullptr;
  }
}

double* S21Matrix::alloc() {
  matrix = new double [rows_ * cols_];
  return matrix;
}


int S21Matrix::elem_count() const{
	return rows_ * cols_;	
}

S21Matrix S21Matrix::find_minor(int r, int c) const {
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
      result(k, m) = (*this)(i, j);
      j++;
      m++;
    }
    i++;
    k++;
  }
  return result;
}


void S21Matrix::set_rand_value() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(-3, 3);
	for (int cur = 0; cur < rows_ * cols_; cur++){
		matrix[cur] = dist(gen);  // rand() % 20;
	}
}
