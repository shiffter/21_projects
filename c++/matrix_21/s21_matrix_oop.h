#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <iostream>
#include <random>
#include <cstring>

using std::cout;
using std::endl;

class S21Matrix {

public:
  // cotr
  S21Matrix();
	S21Matrix(int);
  S21Matrix(int, int);
  ~S21Matrix();
  S21Matrix(const S21Matrix &o);
  S21Matrix(S21Matrix &&o) noexcept;

  // setters, getters
  // void setM();
  void set_rows(int);
  void set_cols(int);
  int get_rows() const;
  int get_cols() const;
  // double **getM() const;

  // methods
  void PrintMatrix();
  bool EqMatrix(const S21Matrix &) const;
  void SumMatrix(const S21Matrix &);
  void SubMatrix(const S21Matrix &);
  void MulNumber(const double);
  void MulMatrix(const S21Matrix &);
  S21Matrix Transponse() const;
  S21Matrix CalcComplements();
  double Determinant() const;
  S21Matrix InverseMatrix();

  // help methods
  void free_matrix();
  double* alloc();
  S21Matrix find_minor(int, int) const;
	S21Matrix swap_class(S21Matrix &other);
	void set_rand_value();

  // Operators
  bool operator==(const S21Matrix&) const;
	bool operator!=(const S21Matrix&) const; 
  S21Matrix operator+(const S21Matrix&) const;
  S21Matrix &operator-(const S21Matrix&);
  S21Matrix &operator=(const S21Matrix&);
  S21Matrix &operator=(S21Matrix &&);
  S21Matrix operator+=(S21Matrix &);
  S21Matrix operator-=(S21Matrix &);
  S21Matrix operator*(S21Matrix &);
  S21Matrix operator*(double);
  S21Matrix operator*=(S21Matrix &);
  S21Matrix operator*=(double);
  double& operator()(int, int);
  double& operator() (int, int) const;


private:
  int rows_, cols_;
  double *matrix;

	//methods
};

#endif
