#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <iostream>
#include <random>

using std::cout;
using std::endl;

class S21Matrix {

public:
  // cotr
  S21Matrix();
  S21Matrix(int, int);
  ~S21Matrix();
  S21Matrix(const S21Matrix &o);
  S21Matrix(S21Matrix &&o);

  // setters, getters
  void setM();
  void setR(int);
  void setC(int);
  int get_rows() const;
  int get_cols() const;
  double **getM() const;

  // methods
  void PrintMatrix();
  bool EqMatrix(const S21Matrix &);
  void SumMatrix(const S21Matrix &);
  void SubMatrix(const S21Matrix &);
  void MulNumber(const double);
  void MulMatrix(const S21Matrix &);
  S21Matrix Transponse();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // help methods
  void free_matrix();
  double **alloc();
  S21Matrix find_minor(int, int);

  // Operators
  bool operator==(const S21Matrix &r);
  S21Matrix &operator+(const S21Matrix &r);
  S21Matrix &operator-(const S21Matrix &r);
  S21Matrix &operator=(const S21Matrix &);
  S21Matrix &operator=(S21Matrix &&);
  S21Matrix operator+=(S21Matrix &);
  S21Matrix operator-=(S21Matrix &);
  S21Matrix operator*(S21Matrix &);
  S21Matrix operator*(double);
  S21Matrix operator*=(S21Matrix &);
  S21Matrix operator*=(double);

private:
  int rows_, cols_;
  double **matrix;
};

#endif
