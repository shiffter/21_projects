#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <iostream>
#include <random>

class S21Matrix
{

	public:
		S21Matrix();
		S21Matrix(size_t, size_t);
		~S21Matrix();
		S21Matrix(const S21Matrix& o);
		S21Matrix(S21Matrix&& o);
		void setM() {
			matrix = nullptr;
		}
		void setR(int val) {
			_rows = val;
		}
		void setC(int val){
			_cols = val;
		}

		int getR() const {
			return _rows;
		}
		int getC() const {
			return _cols;
		}
		double** getM() const { return matrix; }

		//methods 
		void PrintMatrix();
		bool EqMatrix(const S21Matrix&);
		void SumMatrix(const S21Matrix&);
		void SubMatrix(const S21Matrix&);
		void MulNumber(const double);
		void MulMatrix(const S21Matrix&);
		S21Matrix Transponse();
		S21Matrix CalcComplements();
		double Determinant();
		// help methods
		void free_matrix();		
		double** alloc(); 
		S21Matrix find_minor(int, int); 
		// Operators
		bool operator==(const S21Matrix& r);
		S21Matrix& operator+(const S21Matrix& r);
		S21Matrix& operator-(const S21Matrix& r);
		S21Matrix& operator=(const S21Matrix&);
		S21Matrix& operator=(S21Matrix&&);
		// S21Matrix& operator*(const S21Matrix&);

	private:
		int _rows, _cols;
		double **matrix;
};

#endif
