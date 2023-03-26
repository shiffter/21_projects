// #include "all_headers"
#include "s21_containers.h"


TEST(pass, 1) {
  ASSERT_TRUE(1==1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
