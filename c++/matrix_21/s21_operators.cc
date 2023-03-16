#include "s21_matrix_oop.h"

bool S21Matrix::operator==(const S21Matrix &right) const {
  return EqMatrix(right);
}

bool S21Matrix::operator!=(const S21Matrix &right) const {
  return !EqMatrix(right);
}

S21Matrix& S21Matrix::operator=(const S21Matrix &other) {
	if (*this != other) {
		if (matrix) { this->free_matrix(); }
		this->matrix = alloc();
		std::memcpy(matrix, other.matrix, rows_ * cols_ * sizeof(double));
	}
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result = *this;
	result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const{
	S21Matrix result = *this;
	result.SubMatrix(other);
  return result;
}

double& S21Matrix::operator()(int row, int col){
	if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
		throw std::exception();
	}
	return matrix[row * cols_ + col];
}

double& S21Matrix::operator()(int row, int col) const {
	if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
		throw std::exception();
	}
	return matrix[row * cols_ + col];
}


S21Matrix& S21Matrix::operator=(S21Matrix &&other) {
	if (*this != other) {
		this->free_matrix();
		rows_ = other.rows_;
		cols_ = other.cols_;
		matrix = other.matrix;
		other.rows_ = 0;
		other.cols_ = 0;
		other.matrix = nullptr;
	}
  return *this;
}

S21Matrix& S21Matrix::operator+=(S21Matrix const &other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(S21Matrix const &other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*(S21Matrix &other) {
	S21Matrix result = *this;
  result.MulMatrix(other);
  return result;
}

S21Matrix operator*(double n, S21Matrix& obj) {
  obj.MulNumber(n);
  return obj;
}

S21Matrix operator*(S21Matrix& obj, double n) {
  obj.MulNumber(n);
  return obj;
}

S21Matrix& S21Matrix::operator*=(S21Matrix const &other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(double n) {
  this->MulNumber(n);
  return *this;
}
