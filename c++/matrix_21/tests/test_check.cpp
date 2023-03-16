#include "../s21_cotr.cc"
#include "../s21_matrix_oop.h"
#include "../s21_methods.cc"
#include "../s21_operators.cc"
#include "../s21_set_get.cc"
#include "../helpers.cc"
#include <gtest/gtest.h>
#include <thread>

// TODO: отформатировать файл через clang-format
TEST(CreateMatrix, DefaultCtor) {
	S21Matrix test_mtrx{};
	ASSERT_EQ(1, test_mtrx.get_rows());
	ASSERT_EQ(1, test_mtrx.get_cols());
}

TEST(CreateMatrix, ParamCtor) {
	S21Matrix a{3, 5};
	ASSERT_EQ(3, a.get_rows());
	ASSERT_EQ(5, a.get_cols());

	S21Matrix b;
	ASSERT_ANY_THROW(S21Matrix s(0, 0));
}

TEST(CreateMatrix, OneParamCtor) {
	S21Matrix a{3};
	ASSERT_EQ(3, a.get_rows());
	ASSERT_EQ(3, a.get_cols());

	S21Matrix b;
	ASSERT_ANY_THROW(S21Matrix s(0, 0));
}


TEST(Eq, Matrix) {
	S21Matrix matr_1(5, 5);
	S21Matrix matr_2(5, 5);
	S21Matrix matr_3(4, 5);
	ASSERT_TRUE(matr_1.EqMatrix(matr_2));
	ASSERT_FALSE(matr_1.EqMatrix(matr_3));
}


TEST(Copy, Ctor) {
	S21Matrix a(4, 5);
	S21Matrix b(4, 5);
	S21Matrix c(3, 4);
	b = a;
	ASSERT_TRUE(a.EqMatrix(b));
	ASSERT_FALSE(a.EqMatrix(c));
}


TEST(Move, Ctor) { 
	S21Matrix src{5, 5};
	S21Matrix dest = std::move(src);
	ASSERT_EQ(0, src.get_rows());
	ASSERT_EQ(0, src.get_cols());
}




TEST(Sum, Matrix) {
	S21Matrix m1(3, 3);		
	S21Matrix m2(3, 3);		
	m1.set_rand_value();
	m2.set_rand_value();
	S21Matrix tmp_at_m1 = m1;
	m1.SumMatrix(m2);
	for (int i = 0; i < m1.get_rows(); i++) {
		for (int j = 0; j < m1.get_cols(); j++) {
			ASSERT_EQ(tmp_at_m1(i, j)+m2(i, j), m1(i, j));
		}
	}
	ASSERT_ANY_THROW(m1.SumMatrix(S21Matrix{3, 4}));
}

TEST(Sub, Matrix) {
	S21Matrix m1(3, 3);		
	S21Matrix m2(3, 3);		
	m1.set_rand_value();
	m2.set_rand_value();
	S21Matrix tmp_at_m1 = m1;
	m1.SubMatrix(m2);
	for (int i = 0; i < m1.get_rows(); i++) {
		for (int j = 0; j < m1.get_cols(); j++) {
			ASSERT_EQ(tmp_at_m1(i, j)-m2(i, j), m1(i, j));
		}
	}
	ASSERT_ANY_THROW(m1.SumMatrix(S21Matrix{3, 4}));
}

TEST(Mul, Number){
	S21Matrix m1(5, 5);
	m1.set_rand_value();
	S21Matrix tmp = m1;
	m1.MulNumber(3);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ASSERT_EQ(tmp(i, j)*3, m1(i, j));
		}
	}
}


TEST(Mul, Matrix){
	S21Matrix m1(3, 4);
	S21Matrix m2(4, 5);
	m1.set_rand_value();
	m2.set_rand_value();
	S21Matrix tmp_m1 = m1;
	m1.MulMatrix(m2);


	for (int i = 0; i < m1.get_rows(); i++) {
		for (int j = 0; j < m1.get_cols(); j++) {
			double t = 0;
			for (int k = 0; k < tmp_m1.get_cols(); k++){
				t += tmp_m1(i, k) * m2(k, j);
			}
			ASSERT_EQ(m1(i, j), t);
		}
	}

	ASSERT_ANY_THROW(m1.MulMatrix(S21Matrix{3, 3}));
}

TEST(Transpose, Matrix) {
	S21Matrix m1(3, 6);
	m1.set_rand_value();

	S21Matrix result = m1.Transponse();
	result = result.Transponse();
	ASSERT_TRUE(m1 == result);
	
	// for (int i = 0; i < m1.getC(); i++) {
	// 	for (int j = 0; j < m1.getR(); j++) {
	// 		ASSERT_EQ(tmp_p(i, j), m1_p[j][i]);
	// 	}
	// }
}

//
TEST(Determinant, Matrix) {
	S21Matrix m1(1,1);
	m1.set_rand_value();
	ASSERT_EQ(m1(0, 0), m1.Determinant());

	S21Matrix m2(2,2);
	m2.set_rand_value();
	double d = m2(0, 0) * m2(1, 1) - m2(1, 0) * m2(0, 1);
	ASSERT_EQ(m2.Determinant(), d);
	
	S21Matrix m3(3, 3);
	m3(0, 0) = 5; m3(0, 1) = -0.2; m3(0, 2) = 1.5;
	m3(1, 0) = 3.3; m3(1, 1) = 1.7; m3(1, 2) = -5.3;
	m3(2, 0) = -2.1; m3(2, 1) = 16.43; m3(2, 2) = 2;
	d = 538.1725;
	ASSERT_EQ(d, m3.Determinant());

	S21Matrix m4{4, 3};
	ASSERT_ANY_THROW(m4.Determinant());

}


TEST(Calculate, Complements) {
	S21Matrix m1{4, 3};
	ASSERT_ANY_THROW(m1.Determinant());

	S21Matrix m2{3, 3};
	m2(0, 0) = 5; m2(0, 1) = -0.2; m2(0, 2) = 1.5;
	m2(1, 0) = 3.3; m2(1, 1) = 1.7; m2(1, 2) = -5.3;
	m2(2, 0) = -2.1; m2(2, 1) = 16.43; m2(2, 2) = 2;

	S21Matrix result{3, 3};
	result(0, 0) = 90.479; result(0, 1) = 4.53; result(0, 2) = 57.789;
	result(1, 0) = 25.045; result(1, 1) = 13.15; result(1, 2) = -81.73;
	result(2, 0) = -1.49; result(2, 1) = 31.45; result(2, 2) = 9.16;

	ASSERT_TRUE(result == m2.CalcComplements());
}

TEST(Inverse, Matrix) {
	S21Matrix m1{4, 3};
	ASSERT_ANY_THROW(m1.Determinant());

	S21Matrix m2(3, 3);
	m2(0, 0) = 5; m2(0, 1) = -0.2; m2(0, 2) = 1.5;
	m2(1, 0) = 3.3; m2(1, 1) = 1.7; m2(1, 2) = -5.3;
	m2(2, 0) = -2.1; m2(2, 1) = 16.43; m2(2, 2) = 2;
	
	S21Matrix result{3, 3};
	result(0, 0) = 0.168123; result(0, 1) = 0.0465371; result(0, 2) = -0.00276863;
	result(1, 0) = 0.008417; result(1, 1) = 0.0244345; result(1, 2) = 0.0584385;
	result(2, 0) = 0.10738; result(2, 1) = -0.151866; result(2, 2) = 0.0170206;

	ASSERT_TRUE(result.EqMatrix(m2.InverseMatrix()));
}


TEST(ChangeSize, Rows) {
	S21Matrix m1{3, 4};
	m1.set_rows(5);

	ASSERT_EQ(m1.get_rows(), 5);
	ASSERT_EQ(m1.get_cols(), 4);

	m1.set_rows(2);
	ASSERT_EQ(m1.get_rows(), 2);

	ASSERT_ANY_THROW(m1.set_rows(0));

} 


TEST(ChangeSize, Cols) {
	S21Matrix m1{5, 3};
	m1.set_cols(4);

	ASSERT_EQ(m1.get_rows(), 5);
	ASSERT_EQ(m1.get_cols(), 4);

	m1.set_cols(2);
	ASSERT_EQ(m1.get_cols(), 2);

	ASSERT_ANY_THROW(m1.set_cols(0));

} 
int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
