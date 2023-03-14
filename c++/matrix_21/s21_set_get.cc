#include "s21_matrix_oop.h"

// Это нельзя
void S21Matrix::setM() { matrix = nullptr; }
// Абсолютно неверно надо перевыделять
void S21Matrix::set_rows(int val) { rows_ = val; }
// Абсолютно неверно
void S21Matrix::set_cols(int val) { cols_ = val; }

int S21Matrix::get_rows() const { return rows_; }
int S21Matrix::get_cols() const { return cols_; }
// Это нельзя
double **S21Matrix::getM() const { return matrix; }


// double &S21Matrix::operator()(int row, int col) {
// const double &S21Matrix::operator()(int row, int col) const {
