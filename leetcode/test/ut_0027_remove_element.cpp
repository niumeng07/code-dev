#include "0027_remove_element/remove_element.h"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
using namespace std;

TEST(remove_element, test0) {
  vector<int> v({3, 2, 2, 3});
  EXPECT_EQ(RemoveElement().removeElement(v, 3), 2);
}

TEST(remove_element, test1) {
  vector<int> v({3, 2, 4, 2, 2, 3});
  EXPECT_EQ(RemoveElement().removeElement(v, 3), 4);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
