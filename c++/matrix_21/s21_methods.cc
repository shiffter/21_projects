#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  if (other.rows_ != rows_ || other.cols_ != cols_) {
    return false;
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::fabs((*this)(i, j) - (other)(i, j)) > 1e-6) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    throw std::exception();
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) += other(i, j);
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    throw std::exception();
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) -= other(i, j);
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::exception();
  }

  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      // double t = 0;
      for (int k = 0; k < cols_; k++) {
        result(i,j) += (*this)(i, k) * other(k, j);
      }
    }
  }
  *this = std::move(result);
}

// Должен копию возвращать, this не менять
S21Matrix S21Matrix::Transponse() const {
  S21Matrix tmp(cols_, rows_);
  for (int i = 0; i < tmp.rows_; i++) {
    for (int j = 0; j < tmp.cols_; j++) {
      tmp(i, j) = (*this)(j, i);
    }
  }
  return tmp;
}

double S21Matrix::Determinant() const{
  double det = 0;
	if (rows_ != cols_) {
		throw std::exception();
	}

  if (rows_ == 1) {
    det = (*this)(0, 0);
  }

  if (rows_ == 2) {
    det = (*this)(0, 0) * (*this)(1, 1) - (*this)(1, 0) * (*this)(0, 1);
  } else if (rows_ > 2) {
    for (int j = 0; j < rows_; j++) {
      double tmp_det = 0;
      S21Matrix tmp = find_minor(0, j);
      tmp_det = tmp.Determinant();
      det += pow(-1, j) *(*this)(0, j) * tmp_det;
    }
  }
  return det;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::exception();
  }

  S21Matrix out(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      double d = 0;
      S21Matrix tmp_m = find_minor(i, j);
      d = tmp_m.Determinant();
      if ((i + j) % 2 != 0)
        d *= -1.0;
      out(i, j) = d;
    }
  }
  return out;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::exception();
  }

  double d = Determinant();
  if (d == 0) { 
		throw std::exception();
	}

  S21Matrix result(rows_, cols_);
  result = Transponse().CalcComplements();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        result(i, j) /= d;
      }
    }

  return result;
}
