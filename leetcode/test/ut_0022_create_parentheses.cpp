#include "0022_create_parentheses/create_parentheses.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include <vector>

TEST(create_parentheses, test0) {
  std::vector<string> result = CreateParentheses().generateParenthesis(3);
  std::vector<string> expect = {"((()))", "(()())", "(())()", "()(())",
                                "()()()"};
  std::sort(result.begin(), result.end());
  EXPECT_EQ(result, expect);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
