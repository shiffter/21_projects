#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) {
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
    throw "Diff matrix size";
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) += other(i, j);
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    throw "Diff matrix size";
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
    throw "Incorrect matrix size";
  }

  // Это лишнее, не надо tmp
  // S21Matrix tmp = *this;
  free_matrix();
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      double t = 0;
      for (int k = 0; k < cols_; k++) {
        //t += tmp.matrix[i][k] * other.matrix[k][j];
        // result(i,j) += (*this)(i, k) * other(k, j);
      }
      //result.matrix[i][j] = t;
    }
  }
  *this = std::move(result);
}

// Должен копию возвращать, this не менять
S21Matrix S21Matrix::Transponse() {
  if (rows_ < 1 || cols_ < 1) {
    throw "Empty matrix";
  }

  S21Matrix tmp(cols_, rows_);
  for (int i = 0; i < tmp.rows_; i++) {
    for (int j = 0; j < tmp.cols_; j++) {
      tmp(i, j) = (*this)(i, j);
    }
  }
  *this = std::move(tmp);
  return *this;
}

double S21Matrix::Determinant() {
  double d = 0;
  // add check
  if (rows_ == 1) {
    d = (*this)(0, 0);
  }
  if (rows_ == 2) {
    d = (*this)(0, 0) * (*this)(1, 1) - (*this)(1, 0) * (*this)(0, 1);
  } else if (rows_ > 2) {
    for (int j = 0; j < rows_; j++) {
      double tmp_d = 0;
      S21Matrix tmp = find_minor(0, j);
      tmp_d = tmp.Determinant();
      d += pow(-1, j) *(*this)(0, j) * tmp_d;
    }
  }
  return d;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw "Matrix should be square";
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
    throw "Matrix should be square";
  }

  S21Matrix result(rows_, cols_);
  double d = Determinant();
  // Сравнивать d с 0 нельзя никогда
  if (d != 0) {
    result = Transponse().CalcComplements();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        result(i, j) /= d;
      }
    }
  }

  return result;
}
