#include "gtest/gtest.h"
#include "0029_divide_two_integer/divide_two_integer.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;

Solution su;
TEST(testCase,test0){ //passed
    EXPECT_EQ(su.plus(2,3),5);
}
TEST(testCase,test1) {//failed
    EXPECT_EQ(su.plus(113,3),116);
}
int main(int argc,char **argv) {
  // cout << su.plus(3,4) << endl;
  cout << su.plus(2,3) << endl;
  testing::InitGoogleTest(&argc,argv);
  // int ret = RUN_ALL_TESTS();
  return 0;
  //test();
}
