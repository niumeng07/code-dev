#include "helloworld/helloworld.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(helloworld, test0) { EXPECT_EQ(HelloWorld().sayHelloWorld(), 0); }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
