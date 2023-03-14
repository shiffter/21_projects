#include "s21_matrix_oop.h"

// 1) Но такие вещи надо отмечать const:
// S21Matrix::operator==(const S21Matrix &right) const {
// И так надо сделать много где
// 2) this-> не надо!
bool S21Matrix::operator==(const S21Matrix &right) {
  return this->EqMatrix(right);
}

// S21Matrix S21Matrix::operator+(const S21Matrix &m2) const {
S21Matrix &S21Matrix::operator+(const S21Matrix &m2) {
  this->SumMatrix(m2);
  cout << "+ operator used" << endl;
  return *this;
}

// копию
S21Matrix &S21Matrix::operator-(const S21Matrix &m2) {
  this->SubMatrix(m2);
  cout << "- operator used" << endl;
  return *this;
}

// if (this != &other) { ... }
S21Matrix &S21Matrix::operator=(const S21Matrix &m2) {
  this->free_matrix();
  this->matrix = this->alloc();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix[i][j] = m2.matrix[i][j];
    }
  }
  cout << "= copy operator used" << endl;
  return *this;
}

// if (this != &other) { ... }
S21Matrix &S21Matrix::operator=(S21Matrix &&o) {
  // необязательно, можно this и other swap
  this->free_matrix();
  rows_ = o.rows_;
  cols_ = o.cols_;
  matrix = o.matrix;
  o.rows_ = 0;
  o.cols_ = 0;
  o.matrix = nullptr;
  // Никогда не вызывать деструктор класса напрямую - всё что будет дальше будет UB
  // o.~S21Matrix();
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
