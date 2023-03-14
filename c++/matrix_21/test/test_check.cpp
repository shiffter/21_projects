#include "../s21_cotr.cpp"
#include "../s21_matrix_oop.h"
#include "../s21_methods.cpp"
#include "../s21_operators.cpp"
#include "../s21_set_get.cpp"
#include "../helpers.cpp"
#include <gtest/gtest.h>
#include <thread>

// TODO: отформатировать файл через clang-format
TEST(CreateMatrix, DefaultConstr) {
	S21Matrix test_mtrx();
	ASSERT_EQ(1, test_mtrx.getR());
	ASSERT_EQ(1, test_mtrx.getC());
}

TEST(CreateMatrix, ParamConstr) {
	S21Matrix a{3, 5);
	ASSERT_EQ(3, a.getR());
	ASSERT_EQ(5, a.getC());

	ASSERT_ANY_THROW(S21Matrix a{0, 0});
	try {
		S21Matrix a(0, 0);
	} catch(const char* msg) {
		ASSERT_EQ("incorrect size", msg);
	} 
}



TEST(Copy, Constr) {
	S21Matrix a(4, 5);
	S21Matrix b = a;
	double** aP = a.getM();
	double** bP = b.getM();
	for (int i = 0; i < a.getR(); i++) {
		for (int j = 0; j < a.getC(); j++) {
			ASSERT_EQ(aP[i][j], bP[i][j]);
		}
	}
}


TEST(Mv, Constr) {
	S21Matrix a(5, 3);
	S21Matrix b = std::move(a);

	ASSERT_EQ(0, a.getR());
	ASSERT_EQ(0, a.getC());
	ASSERT_EQ(nullptr, a.getM());

	ASSERT_EQ(5, b.getR());
	ASSERT_EQ(3, b.getC());
	ASSERT_NE(nullptr, b.getM());
}


// Destructor tests


TEST(Sum, Matrix) {
	S21Matrix m1(5, 5);		
	S21Matrix tmp = m1;
	double** pTmp = tmp.getM();
	S21Matrix m2(5, 5);		
	double** p2 = m2.getM();
	m1.SumMatrix(m2);
	double** p1 = m1.getM();
	for (int i = 0; i < m1.getR(); i++) {
		for (int j = 0; j < m1.getC(); j++) {
			ASSERT_EQ(pTmp[i][j]+p2[i][j], p1[i][j]);
		}
	}
}

TEST(Sum, InccorectSize){
	S21Matrix m1(3, 2);
	S21Matrix m2(4, 3);
	// TODO: можно так
	// ASSERT_THROW(m1.SumMatrix(m2), std::exception);
	// ASSERT_ANY_THROW(m1.SumMatrix(m2));
	try	{
		m1.SumMatrix(m2);
	} catch (const char* msg) {
	//
		ASSERT_EQ(msg, "Diff matrix size");
	}

}

TEST(Sub, Matrix) {
	S21Matrix m1(5, 5);		
	S21Matrix tmp = m1;
	double** pTmp = tmp.getM();
	S21Matrix m2(5, 5);		
	double** p2 = m2.getM();
	m1.SubMatrix(m2);
	double** p1 = m1.getM();
	for (int i = 0; i < m1.getR(); i++) {
		for (int j = 0; j < m1.getC(); j++) {
			ASSERT_EQ(pTmp[i][j]-p2[i][j], p1[i][j]);
		}
	}
}

TEST(Sub, InccorectSize){
	S21Matrix m1(3, 2);
	S21Matrix m2(4, 3);
	try	{
		m1.SumMatrix(m2);
	} catch (const char* msg) {
		ASSERT_EQ(msg, "Diff matrix size");
	}

}


TEST(Mul, Number){
	S21Matrix m1(5, 5);
	S21Matrix tmp = m1;
	m1.MulNumber(3);
	double** m2_p = m1.getM();
	double** p = tmp.getM();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ASSERT_EQ(p[i][j]*3, m2_p[i][j]);
		}
	}
}


TEST(Mul, Matrix){
	S21Matrix m1(3, 4);
	S21Matrix tmp = m1;
	double** p = tmp.getM();
	S21Matrix m2(4, 5);
	m1.MulMatrix(m2);

	double** p1 = m1.getM();
	double** p2 = m2.getM();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			double t = 0;
			for (int k = 0; k < 4; k++){
				t += p[i][k] * p2[k][j];
			}
			ASSERT_EQ(p1[i][j], t);
		}
	}


}


TEST(Transpose, Matrix) {
	S21Matrix m1(3, 6);
	S21Matrix tmp = m1;

	m1.Transponse();

	double** m1_p = m1.getM();
	double** tmp_p = tmp.getM();

	ASSERT_TRUE(m1 == tmp);
	
	ASSERT_EQ(m1, tmp);

	for (int i = 0; i < m1.getC(); i++) {
		for (int j = 0; j < m1.getR(); j++) {
			ASSERT_EQ(tmp_p[i][j], m1_p[j][i]);
		}
	}
}


TEST(Determinant, Matrix) {
	S21Matrix m1(3,3);
	double** m1_p = m1.getM();
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (j % 2 == 0) {
				m1_p[i-1][j-1] = j*3.3;
			} else {
			m1_p[i-1][j-1] = i/1.5; }
		}
	}
	m1.PrintMatrix();
	double det = m1.Determinant();
	cout << det << endl;
	ASSERT_EQ( det, 0);
}


TEST(Inverse, Matrix) {
	S21Matrix result(5, 5);	
	S21Matrix tmp = result;
	result = result.InverseMatrix();
	double d = tmp.Determinant();
	if (d != 0) {
	S21Matrix alg_comp = tmp.CalcComplements();
	tmp = alg_comp.Transponse();
	double** tmp_p = tmp.getM();
	double** res_p = result.getM();
	for (int i = 0; i < tmp.getR(); i++) {
		for (int j = 0; j < tmp.getC(); j++ ) {
			tmp_p[i][j] /= d;
			ASSERT_EQ(res_p[i][j], tmp_p[i][j]);
		}
	}
	}
}


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
