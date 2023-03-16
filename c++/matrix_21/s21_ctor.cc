#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(1), cols_(1) {
	matrix = new double[1]{};
}


S21Matrix::S21Matrix(int common_len) {
	if (common_len < 1) {
		throw std::exception();
	}
	rows_ = cols_ = common_len;
	matrix = new double [common_len^2]{};
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::exception();
  }
  matrix = new double [rows_ * cols_]{};
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  rows_ = other.get_rows();
  cols_ = other.get_cols();
  matrix = new double[rows_ * cols_] {};
	std::memcpy(matrix, other.matrix, rows_ * cols_ * sizeof(double));		
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix = other.matrix;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix = nullptr;
}

S21Matrix::~S21Matrix() {
    delete[] matrix;
}
