#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <iostream>
#include <ctime>
#include <cmath>

class S21Matrix
{
	private:
		int rows_, cols_;
		double **matrix;

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
			rows_ = val;
		}
		void setC(int val){
			cols_ = val;
		}

		int getR() const {
			return rows_;
		}
		int getC() const {
			return cols_;
		}
		double** getM() const { return matrix; }

		//methods 
		void PrintMatrix();
		bool EqMatrix(const S21Matrix& o);
		void SumMatrix(const S21Matrix& o);

		// Operators
		friend bool operator==(const S21Matrix, const S21Matrix);
};

#endif
