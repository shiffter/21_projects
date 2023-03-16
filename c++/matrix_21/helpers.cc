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

// хреновый free
// надо rows_ = 0; cols_ = 0;
// Иначе неконсистентная матрица будет
// Кстати FreeMatrix() по гугл-стилю
void S21Matrix::free_matrix() {
  if (matrix) {
    // for (int i = 0; i < rows_; i++) {
    //   delete[] matrix[i];
    //   matrix[i] = nullptr;
    // }
    delete[] matrix;
    matrix = nullptr;
  }
}

// Приватной должна быть 100%
double* S21Matrix::alloc() {
  matrix = new double [rows_ * cols_];
  // for (int i = 0; i < rows_; i++) {
  //   matrix[i] = new double[cols_];
  // }
  return matrix;
}


int S21Matrix::elem_count() const{
	return rows_ * cols_;	
}



S21Matrix S21Matrix::swap_class(S21Matrix &other){
	// if (*this != other){
		// std::swap(cols_, other.cols_);
		// std::swap(rows_, other.rows_);
		// std::swap(matrix, other.matrix);
		// other.matrix = nullptr;
  // rows_ = other.rows_;
  // cols_ = other.cols_;
  // matrix = other.matrix;
  // other.rows_ = 0;
  // other.cols_ = 0;
  // other.matrix = nullptr;
	// }
	return *this;
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
