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
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(-3, 3);
  // 1) Дублирование кода
  // 2) Не реализована базовая гарантия безопасности исключений
  // try {
  matrix = new double [rows_ * cols_];
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
  matrix = new double [rows_ * cols_];
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
S21Matrix::S21Matrix(S21Matrix &&o) {
  rows_ = o.rows_;
  cols_ = o.cols_;
  matrix = o.matrix;
  o.rows_ = 0;
  o.cols_ = 0;
  o.matrix = nullptr;
  cout << "move constructor using" << endl;
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
int main() {
	S21Matrix a{5, 5};
	a(1, 1) = 3;
	// cout << a(1, 1) << endl;
	a.PrintMatrix();

}
