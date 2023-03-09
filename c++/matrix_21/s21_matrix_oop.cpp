#include "s21_matrix_oop.h"

using std::cout;
using std::endl;

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
			matrix[i][j] =  rand() % 100;// dist(gen);
		}
	}
}

S21Matrix::S21Matrix(const S21Matrix& o) {
	_rows = o.getR();
	_cols = o.getC();
	matrix = nullptr;
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
}


S21Matrix::S21Matrix(S21Matrix&& o){
	matrix = o.getM();
	_rows = o.getR();
	_cols = o.getC();
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
		for (int i = 0; i < _rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

void S21Matrix::PrintMatrix() {
	for (int i=0; i < _rows; i++) {
		for (int j=0; j < _cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}	
		cout << endl;
}


bool S21Matrix::EqMatrix(const S21Matrix& o) {
	if (o._rows != _rows || o._cols != _cols){
		return false;
	}
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			if (std::fabs(matrix[i][j] - o.matrix[i][j]) > 1e-6)  {
				return false;
			}
		}
	}
	return true;	
}


void S21Matrix::SumMatrix(const S21Matrix& o){
	if (_cols != o._cols || _rows != o._rows) {
		throw "Diff matrix size";
	}

	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++ ) {
			matrix[i][j] += o.matrix[i][j];
		}
	}
}


void S21Matrix::SubMatrix(const S21Matrix& o){
	if (_cols != o._cols || _rows != o._rows) {
		throw "Diff matrix size";
	}

	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++ ) {
			matrix[i][j] -= o.matrix[i][j];
		}
	}
}

void S21Matrix::MulNumber(const double num){
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++ ) {
			this->matrix[i][j] *= num;
		}
	}
}


void S21Matrix::MulMatrix(const S21Matrix& o) {
	if (_cols != o._rows) {
		throw "Incorrect matrix size";
	}

	S21Matrix result(_rows, o.getC());
	S21Matrix tmp = *this;
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < o.getC(); j++ ) {
			double t = 0;
			for (int k = 0; k < _cols; k++) {
				t += tmp.matrix[i][k] * o.matrix[k][j];
			}
			result.matrix[i][j] = t;
		}
	}
	this = std::move(&result);
}
	



bool S21Matrix::operator==(const S21Matrix& right) {
	return this->EqMatrix(right);
}

S21Matrix& S21Matrix::operator+(const S21Matrix& m2) {
	this->SumMatrix(m2);
	return *this;
}


S21Matrix& S21Matrix::operator-(const S21Matrix& m2) {
	this->SubMatrix(m2);
	return *this;
}


S21Matrix& S21Matrix::operator=(const S21Matrix& m2) {
	*this = std::move(m2); 
	return *this;
}


// S21Matrix& operator=(const S21Matrix& m1) {
// 	this* = std::move(m1);
// }
//
// S21Matrix pass(S21Matrix s) {
// 	S21Matrix b(s.getR(), s.getC()); 
// 	return b;
// }

int main() {
	S21Matrix a(3, 4);
	S21Matrix b(4, 5);
	a.PrintMatrix();
	b.PrintMatrix();
	a.MulMatrix(b);
	a.PrintMatrix();
}
