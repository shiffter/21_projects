#include "s21_matrix_oop.h"

// TODO: S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix(nullptr)
// И во всех конструкторах
S21Matrix::S21Matrix() : rows_(1), cols_(1) {
	matrix = new double[1]{};
	cout << "default constctor usd" << endl;
  // все переменные не по Google Style
  // rows_
  // cols_
  // matrix_
  // Goole style: https://evgenykislov.com/wp-content/custom/cpp_codestyle/cppguide_ru.html
}


S21Matrix::S21Matrix(int common_len) {
	if (common_len < 1) {
		throw std::exception();
	}
	rows_ = cols_ = common_len;
	matrix = new double [common_len^2]{};
	cout << "const with one param" << endl;
}

// Google Style: однобуквенные переменные нельзя кроме некоторых случаев
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    // Так исключения бросать нельзя
    // Бросать надо всегда объекты std::exception или его наследников
    // Из стандартных можно только std::logic_error и std::runtime_error и их
    // наследников
    throw std::exception();
  }

  // TODO: не забыть выпилить
  // 1) Дублирование кода
  // 2) Не реализована базовая гарантия безопасности исключений
  // try {
  matrix = new double [rows_ * cols_]{};
  // for (int i = 0; i < rows_; i++) {
  //   matrix[i] = new double[cols_]{};
  // }
  // Примерно так базовая гарантия:
  /*} catch (...) {
    for (int j = 0; j < i; ++j) {
      free(matrix[j]);      
    }
    free(matrix);
    throw;
  }*/
  // 3) Можно не обнулять так тупо в цикле. new умеет делать дефолтную инициализацию
  // Вместо: 
  // matrix[i] = new double[c];
  // пишем
  // matrix[i] = new double[c]{};
  // или
  // matrix[i] = new double[c]();
  // for (int i = 0; i < rows; i++) {
  //   for (int j = 0; j < cols; j++) {
  //     matrix(i, j) = 0; // rand() % 20;// dist(gen);
  //   }
  // }
	cout << "param constctor usd" << endl;
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  rows_ = other.get_rows();
  cols_ = other.get_cols();
  // matrix = nullptr;
  // Основной смысл инкапсуляции защитить инварианты класса и его приватные данные
  // matrixO - можно менять напрямую - плохо
  // Работать с указателями - очень плохо
  // Указателей, особенно других матриц, не должно использоваться нигде
  // double **matrixO = o.getM();
	// Не понимаю почему нельзя так освобождать память, тест Sum Matrix, 70 str, free(invalid pointer) 
	// if (matrix != nullptr) {
	// 	delete[] matrix;
	// 	matrix = nullptr;
	// }
  matrix = new double[rows_ * cols_] {};
	std::memcpy(matrix, other.matrix, rows_ * cols_ * sizeof(double));		
  // for (int i = 0; i < rows_; i++) {
  //   matrix[i] = new double[cols_];
  // }
  // for (int i = 0; i < rows_; i++) {
  //   for (int j = 0; j < cols_; j++) {
      // можно так:
      // (*this)(i,j) = o(i,j);
      // так тоже можно (но не рекомендую):
      // matrix(i, j) = other.matrix(i, j);
      // matrix(i, j) = matrixO(i, j);
    // }
  // }
  cout << "Copy constr used" << endl;
}

// C++ Core guidline обязывает нас конструктор переносом помечать как noexcept
// Узнать про RVO и NRVO: https://habr.com/ru/company/vk/blog/666330/
S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  cout << "move constructor using" << endl;
	// swap_class(other);
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix = other.matrix;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix = nullptr;
  // return *this;
}
// S21Matrix a {b};
// S21Matrix a;
// a = b;

// А почему бы не вызывать free_matrix() ?
S21Matrix::~S21Matrix() {
  // if (matrix) {
	  //
  //   for (int i = 0; i < rows_; i++) {
  //     delete[] matrix[i];
  //   }
    delete[] matrix;
  // }
}

// TODO: ни в коем случае!!!
// int main() {
// 	S21Matrix a{5, 5};
// 	S21Matrix b{5, 5};
// 	S21Matrix c = std::move(b);
	// cout << "end" << endl;
	// a.PrintMatrix();

// }
