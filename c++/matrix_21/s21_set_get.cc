#include "s21_matrix_oop.h"

// Это нельзя
// void S21Matrix::setM() { matrix = nullptr; }
// Абсолютно неверно надо перевыделять
void S21Matrix::set_rows(int val) { 
	if (val < 1) {
		throw std::exception();
	}
	if (val == rows_) return;
	double* new_matrix = new double[val * cols_] {0};
	if (val > rows_) {
		std::memcpy(new_matrix, matrix, rows_ * cols_ * sizeof(double));
	} else {
		std::memcpy(new_matrix, matrix, val * cols_ * sizeof(double));
	}
	delete[] matrix;
	matrix = new_matrix;
	rows_ = val; 
}

// Абсолютно неверно
void S21Matrix::set_cols(int val) {   
	if (val < 1) {
		throw std::exception();
	}
	if (val == rows_) return;

	double* new_matrix = new double[rows_ * val] {0};

	for (int i = 0; i < rows_; i++) {
		for (int j = 0, k = 0; j < cols_ && k < val; j++, k++) {
			new_matrix[i * val + k] = matrix[i * cols_ + j];
		}
	}
	
	delete[] matrix;
	matrix = new_matrix;
	cols_ = val;
}

int S21Matrix::get_rows() const { return rows_; }
int S21Matrix::get_cols() const { return cols_; }
// Это нельзя
// double **S21Matrix::getM() const { return matrix; }


// double &S21Matrix::operator()(int row, int col) {
// const double &S21Matrix::operator()(int row, int col) const {
