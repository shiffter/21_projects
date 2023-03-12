#include "s21_matrix_oop.h"


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

S21Matrix S21Matrix::CalcComplements(){
	if (_rows != _cols) {
		throw "Matrix should be square";
	}

	S21Matrix out(_rows, _cols);
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++ ) {
			double d = 0;
			S21Matrix tmp_m = find_minor(i, j); 
			d = tmp_m.Determinant();
			if ((i+j) % 2 != 0) d *= -1.0;
			out.matrix[i][j] = d;
		}
	}
	return out;
}


S21Matrix S21Matrix::InverseMatrix(){
	if (_rows != _cols) {
		throw "Matrix should be square";
	}

	S21Matrix result(_rows, _cols);
	double d = Determinant();
	if (d != 0) {
	result = Transponse().CalcComplements();	
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++ ) {
			result.matrix[i][j] /= d;
		}
	}
}

	return result;
	}
