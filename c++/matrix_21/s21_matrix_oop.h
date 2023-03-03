#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <iostream>
#include <ctime>

class S21Matrix
{
	private:
		int rows_ = 1, cols_ = 1;
		double **matrix;

	public:
		S21Matrix();
		S21Matrix(int, int);
		~S21Matrix();
		S21Matrix(const S21Matrix& o);
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
};

#endif
