#include "s21_matrix_oop.h"

bool S21Matrix::operator==(const S21Matrix &right) {
  return this->EqMatrix(right);
}

S21Matrix &S21Matrix::operator+(const S21Matrix &m2) {
  this->SumMatrix(m2);
  cout << "+ operator used" << endl;
  return *this;
}

S21Matrix &S21Matrix::operator-(const S21Matrix &m2) {
  this->SubMatrix(m2);
  cout << "- operator used" << endl;
  return *this;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &m2) {
  this->free_matrix();
  this->matrix = this->alloc();
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      matrix[i][j] = m2.matrix[i][j];
    }
  }
  cout << "= copy operator used" << endl;
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&o) {
  this->free_matrix();
  _rows = o._rows;
  _cols = o._cols;
  matrix = o.matrix;
  o._rows = 0;
  o._cols = 0;
  o.matrix = nullptr;
  // o.~S21Matrix();
  cout << "= move operator used" << endl;
  return *this;
}

S21Matrix S21Matrix::operator+=(S21Matrix &o) {
  this->SumMatrix(o);
  cout << "+= operator used" << endl;
  return *this;
}

S21Matrix S21Matrix::operator-=(S21Matrix &o) {
  this->SubMatrix(o);
  cout << "-= operator used" << endl;
  return *this;
}
//
S21Matrix S21Matrix::operator*(S21Matrix &o) {
  this->MulMatrix(o);
  cout << "* matrix operator used" << endl;
  return *this;
}

S21Matrix S21Matrix::operator*(double n) {
  this->MulNumber(n);
  cout << "* number operator used" << endl;
  return *this;
}

S21Matrix S21Matrix::operator*=(S21Matrix &o) {
  this->MulMatrix(o);
  cout << "*= matrix operator used" << endl;
  return *this;
}

S21Matrix S21Matrix::operator*=(double n) {
  this->MulNumber(n);
  cout << "*= number operator used" << endl;
  return *this;
}
