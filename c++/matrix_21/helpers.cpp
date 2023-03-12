#include "s21_matrix_oop.h"

void S21Matrix::PrintMatrix() {
	for (int i=0; i < _rows; i++) {
		for (int j=0; j < _cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}	
		cout << endl;
}



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

