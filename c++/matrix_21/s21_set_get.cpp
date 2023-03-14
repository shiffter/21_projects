#include "s21_matrix_oop.h"

void S21Matrix::setM() { matrix = nullptr; }
void S21Matrix::setR(int val) { _rows = val; }
void S21Matrix::setC(int val) { _cols = val; }

int S21Matrix::getR() const { return _rows; }
int S21Matrix::getC() const { return _cols; }
double **S21Matrix::getM() const { return matrix; }
