#include "s21_matrix_oop.h"


S21Matrix::S21Matrix() {
	_rows = 0;
	_cols = 0;
	matrix = nullptr;
}


S21Matrix::S21Matrix(size_t r, size_t c) {
	if (r < 1 || c < 1) {
		throw "incorrect size";
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(-3, 3);
	_rows = r;
	_cols = c;
	matrix = new double*[r];
	for (int i = 0; i < r; i++) {
		matrix[i] = new double[c];
	}
	for (int i=0; i < r; i++) {
		for (int j=0; j < c; j++) {
			matrix[i][j] = 0;// rand() % 20;// dist(gen);
		}
	}
}

S21Matrix::S21Matrix(const S21Matrix& o) {
	_rows = o.getR();
	_cols = o.getC();
	// matrix = nullptr;
	double** matrixO = o.getM();	
	matrix = new double*[_rows];
	for (int i = 0; i < _rows; i++) {
		matrix[i] = new double[_cols];
	}
	for (int i=0; i < _rows; i++) {
		for (int j=0; j < _cols; j++) {
			matrix[i][j] = matrixO[i][j];
		}
	}
	cout << "Copy constr used" << endl;
}


S21Matrix::S21Matrix(S21Matrix&& o){
	_rows = o._rows;
	_cols = o._cols;
	matrix = o.matrix;
	o._rows = 0;
	o._cols = 0;
	o.matrix = nullptr;
	cout << "move constructor using" << endl;
	// return *this;
}
// S21Matrix a {b};
// S21Matrix a;
// a = b;



S21Matrix::~S21Matrix() {
	if (matrix) {
		for (int i = 0; i < _rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

int main() {
	cout << "main";
}
