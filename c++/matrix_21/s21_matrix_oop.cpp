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
	
	S21Matrix tmp = *this;
	free_matrix();
	S21Matrix result(tmp._rows, o._cols);
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < o.getC(); j++ ) {
			double t = 0;
			for (int k = 0; k < _cols; k++) {
				t += tmp.matrix[i][k] * o.matrix[k][j];
			}
			result.matrix[i][j] = t;
		}
	}
	*this = std::move(result);
}


S21Matrix S21Matrix::Transponse() {
	if (_rows < 1 || _cols < 1) {
		throw "Empty matrix";
	}

	S21Matrix tmp(_cols, _rows);
	for (int i = 0; i < tmp._rows; i++) {
		for (int j = 0; j < tmp._cols; j++ ) {
			tmp.matrix[i][j] = matrix[j][i];
		}
	}
	*this = std::move(tmp);
	return *this;
}


// S21Matrix CalcComplements(){
// 	if (_rows != _cols) {
// 		throw "Matrix should be square";
// 	}
//
// 	
// }
//helpers func

void S21Matrix::free_matrix() {
	if (matrix) {
		for (int i = 0; i < _rows; i++) {
			delete[] matrix[i];
			matrix[i] = nullptr;
		}
		delete[] matrix;
		matrix = nullptr;
	}
}		

double** S21Matrix::alloc() {
	matrix = new double*[_rows];
	for (int i = 0; i < _rows; i++) {
		matrix[i] = new double[_cols];
	}
	return matrix;
}


S21Matrix S21Matrix::find_minor(int r, int c){
	S21Matrix result(_rows-1, _cols-1);
	
	for (int i = 0, k = 0; i < _rows;) {
		if (i == r) { i++; continue; }

		for (int j = 0, m = 0; j < _cols;) {
			if (j == c) { j++; continue; }
			result.matrix[k][m] = matrix[i][j];
			j++; m++;
		}
	i++; k++;
	}
	return result;
}


double S21Matrix::Determinant() {
	double d = 0; 	
	// add check
	if (_rows == 1) {
		d = matrix[0][0];
	}
	if (_rows == 2) {
	d = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	} else if (_rows > 2) {
		for (int j = 0; j < _rows; j++) {
			double tmp_d = 0;
			S21Matrix tmp = find_minor(0, j);
			tmp_d = tmp.Determinant();
			d += pow(-1, j) * matrix[0][j] * tmp_d;
		}
	}
	return d;
}


//Operators
bool S21Matrix::operator==(const S21Matrix& right) {
	return this->EqMatrix(right);
}

S21Matrix& S21Matrix::operator+(const S21Matrix& m2) {
	this->SumMatrix(m2);
	cout << "Plus operator used" << endl;
	return *this;
}


S21Matrix& S21Matrix::operator-(const S21Matrix& m2) {
	this->SubMatrix(m2);
	cout << "- operator used" << endl;
	return *this;
}


S21Matrix& S21Matrix::operator=(const S21Matrix& m2) {
	this->free_matrix();
	this->matrix = this->alloc();
	for (int i=0; i < _rows; i++) {
		for (int j=0; j < _cols; j++) {
			matrix[i][j] = m2.matrix[i][j];
		}
	}
	cout << "= copy operator used" << endl;
	return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& o) {
	this->free_matrix();
	_rows = o._rows;
	_cols = o._cols;
	matrix = o.matrix;
	o._rows = 0;
	o._cols = 0;
	o.matrix = nullptr;
	// o.~S21Matrix();
	cout << "= move operator used" << endl;
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
	S21Matrix a(3, 3);
	a.PrintMatrix();
	cout << a.Determinant() << endl;
}
