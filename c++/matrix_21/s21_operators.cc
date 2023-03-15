#include "s21_matrix_oop.h"

// 1) Но такие вещи надо отмечать const:
// S21Matrix::operator==(const S21Matrix &right) const {
// И так надо сделать много где
// 2) this-> не надо!
bool S21Matrix::operator==(const S21Matrix &right) const {
  return EqMatrix(right);
}

bool S21Matrix::operator!=(const S21Matrix &right) const {
  return !EqMatrix(right);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  cout << "+ operator used" << endl;
// S21Matrix &S21Matrix::operator+(const S21Matrix &m2) {
  S21Matrix result{rows_, cols_};
	result.SumMatrix(other);
  return result;
}

// копию
S21Matrix &S21Matrix::operator-(const S21Matrix &m2) {
  this->SubMatrix(m2);
  cout << "- operator used" << endl;
  return *this;
}

double& S21Matrix::operator()(int row, int col){
	if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
		throw std::exception();
	}

  // cout << "() operator used" << endl;
	return matrix[row * cols_ + col];
}

double& S21Matrix::operator()(int row, int col) const {
	if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
		throw std::exception();
	}
  // cout << "const () operator used" << endl;
	return matrix[row * cols_ + col];
}

// if (this != &other) { ... }
S21Matrix &S21Matrix::operator=(const S21Matrix &m2) {
	if (matrix) { this->free_matrix(); }
  this->matrix = alloc();
	std::memcpy(matrix, m2.matrix, rows_ * cols_ * sizeof(double));
  // for (int i = 0; i < rows_; i++) {
  //   for (int j = 0; j < cols_; j++) {
  //     (*this)(i, j) = m2(i, j);
  //   }
  // }
  cout << "= copy operator used" << endl;
  return *this;
}

// if (this != &other) { ... }
S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  // необязательно, можно this и other swap
  this->free_matrix();
	// swap_class(other);
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix = other.matrix;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix = nullptr;
  // Никогда не вызывать деструктор класса напрямую - всё что будет дальше будет UB
  // other.~S21Matrix();
  cout << "= move operator used" << endl;
  return *this;
}

// S21Matrix& S21Matrix::operator+=(const S21Matrix &o) {
// Тело написано верно, неправильно только возвращаемый тип
S21Matrix S21Matrix::operator+=(S21Matrix &o) {
  this->SumMatrix(o);
  cout << "+= operator used" << endl;
  return *this;
}

// Аналогично operator+=
S21Matrix S21Matrix::operator-=(S21Matrix &o) {
  this->SubMatrix(o);
  cout << "-= operator used" << endl;
  return *this;
}

// копию внтури надо делать, this не должен меняться
S21Matrix S21Matrix::operator*(S21Matrix &o) {
  this->MulMatrix(o);
  cout << "* matrix operator used" << endl;
  return *this;
}

// Надо сделать вторую перегрузку - умножение числа на матрицу - см. materials
// friend необязательно
S21Matrix S21Matrix::operator*(double n) {
  this->MulNumber(n);
  cout << "* number operator used" << endl;
  return *this;
}

// Аналогично operator+=
S21Matrix S21Matrix::operator*=(S21Matrix &o) {
  this->MulMatrix(o);
  cout << "*= matrix operator used" << endl;
  return *this;
}

// Аналогично operator+=
S21Matrix S21Matrix::operator*=(double n) {
  this->MulNumber(n);
  cout << "*= number operator used" << endl;
  return *this;
}


