#include <gtest/gtest.h>
int add(int a,int b){
    return a+b;
}
TEST(testCase,test0){ //passed
    EXPECT_EQ(add(2,3),5);
}
TEST(testCase,test1) {//failed
    EXPECT_EQ(add(3,3),4);
}
int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
