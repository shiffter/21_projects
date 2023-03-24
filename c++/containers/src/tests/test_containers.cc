// #include "all_headers"



TEST(Operator, MultiplicationEqualMatrix) {
  S21Matrix a{3, 3};
  S21Matrix b{3, 3};
  a.set_rand_value();
  b.set_rand_value();
  S21Matrix tmp = a;
  a *= b;
  ASSERT_TRUE(a.EqMatrix(tmp * b));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
