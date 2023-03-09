#include "../s21_matrix_oop.cpp"
#include <gtest/gtest.h>
#include <thread>


TEST(CreateMatrix, DefaultConstr) {
	S21Matrix a;
	ASSERT_EQ(0, a.getR());
	ASSERT_EQ(0, a.getC());
}

TEST(CreateMatrix, ParamConstr) {
	S21Matrix a(3, 5);
	ASSERT_EQ(3, a.getR());
	ASSERT_EQ(5, a.getC());

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
	try	{
		m1.SumMatrix(m2);
	} catch (const char* msg) {
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
	m1.PrintMatrix();

	double** p1 = m1.getM();
	double** p2 = m2.getM();

	cout << p1[0][0] << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			double t = 0;
			for (int k = 0; k < m1.getC(); k++){
				t += p[i][k] * p2[k][j];
			}
			// ASSERT_EQ(p1[i][j], t);
			cout << p1[i][j] << "  "<< t << endl;
		}
	}


}



int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
