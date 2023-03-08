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




int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
