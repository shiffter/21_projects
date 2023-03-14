#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &o) {
  if (o.rows_ != rows_ || o.cols_ != cols_) {
    return false;
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::fabs(matrix[i][j] - o.matrix[i][j]) > 1e-6) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix &o) {
  if (cols_ != o.cols_ || rows_ != o.rows_) {
    throw "Diff matrix size";
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix[i][j] += o.matrix[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &o) {
  if (cols_ != o.cols_ || rows_ != o.rows_) {
    throw "Diff matrix size";
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix[i][j] -= o.matrix[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &o) {
  if (cols_ != o.rows_) {
    throw "Incorrect matrix size";
  }

  // Это лишнее, не надо tmp
  // S21Matrix tmp = *this;
  free_matrix();
  S21Matrix result(rows_, o.cols_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      double t = 0;
      for (int k = 0; k < cols_; k++) {
        //t += tmp.matrix[i][k] * o.matrix[k][j];
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
      tmp.matrix[i][j] = matrix[j][i];
    }
  }
  *this = std::move(tmp);
  return *this;
}

double S21Matrix::Determinant() {
  double d = 0;
  // add check
  if (rows_ == 1) {
    d = matrix[0][0];
  }
  if (rows_ == 2) {
    d = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
  } else if (rows_ > 2) {
    for (int j = 0; j < rows_; j++) {
      double tmp_d = 0;
      S21Matrix tmp = find_minor(0, j);
      tmp_d = tmp.Determinant();
      d += pow(-1, j) * matrix[0][j] * tmp_d;
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
      out.matrix[i][j] = d;
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
        result.matrix[i][j] /= d;
      }
    }
  }

  return result;
}
