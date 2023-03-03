#include "s21_matrix_oop.h"

using std::cout;
using std::endl;

S21Matrix::S21Matrix() {
	rows_ = 0;
	cols_ = 0;
	matrix = nullptr;
}


S21Matrix::S21Matrix(int r, int c) {
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
}; 

int main() {
	S21Matrix asd(3,5);
	S21Matrix P2 = asd;
	cout << endl;
	P2.PrintMatrix();
	return 0;
}
