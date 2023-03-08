#include "s21_matrix_oop.h"

using std::cout;
using std::endl;

S21Matrix::S21Matrix() {
	rows_ = 0;
	cols_ = 0;
	matrix = nullptr;
}


S21Matrix::S21Matrix(size_t r, size_t c) {
	if (r < 1 || c < 1) {
		throw "incorrect size";
	}
	rows_ = r;
	cols_ = c;
	matrix = new double*[r];
	for (int i = 0; i < r; i++) {
		matrix[i] = new double[c];
	}
	for (int i=0; i < r; i++) {
		for (int j=0; j < c; j++) {
			srand(time(0));
			matrix[i][j] = 1 + rand() % 100 ;
		}
	}
}

S21Matrix::S21Matrix(const S21Matrix& o) {
	rows_ = o.getR();
	cols_ = o.getC();
	matrix = nullptr;
	double** matrixO = o.getM();	
	matrix = new double*[rows_];
	for (int i = 0; i < rows_; i++) {
		matrix[i] = new double[cols_];
	}
	for (int i=0; i < rows_; i++) {
		for (int j=0; j < cols_; j++) {
			matrix[i][j] = matrixO[i][j];
		}
	}
}


S21Matrix::S21Matrix(S21Matrix&& o){
	matrix = o.getM();
	rows_ = o.getR();
	cols_ = o.getC();
	o.setR(0);
	o.setC(0);
	o.setM();
	cout << "move constructor using" << endl;
}
// S21Matrix a {b};
// S21Matrix a;
// a = b;



S21Matrix::~S21Matrix() {
	if (matrix) {
		for (int i = 0; i < rows_; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

void S21Matrix::PrintMatrix() {
	for (int i=0; i < rows_; i++) {
		for (int j=0; j < cols_; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}	
}


bool S21Matrix::EqMatrix(const S21Matrix& o) {
	if (o.rows_ != rows_ || o.cols_ != cols_){
		return false;
	}
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			if (std::fabs(matrix[i][j] - o.matrix[i][j]) > 1e-6)  {
				return false;
			}
		}
	}
	return true;	
}


// void SumMatrix(const S21Matrix& o){
// 	for (int i = 0; i < this->rows_; i++) {
// 		for (int j = 0; j < )
// 	}
// }


bool operator==(S21Matrix left, S21Matrix right) {
	return left.EqMatrix(right);
}

S21Matrix pass(S21Matrix s) {
	S21Matrix b(s.getR(), s.getC()); 
	return b;
}
//
// int main() {
// 	S21Matrix a(5, 3);
// 	S21Matrix b = std::move(a);
// 	cout << b.getC() << endl;
// 	cout << a.getC() << endl;
// }
