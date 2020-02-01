#include "0004_media_arrays/media_arrays.h"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
using namespace std;

TEST(ut_0004_media_arrays, test0) {
  vector<int> a({1, 3});
  vector<int> b({2});
  EXPECT_EQ(MediaArrays().findMedianSortedArrays(a, b), 2.0);
}

TEST(ut_0004_media_arrays, test2) {
  vector<int> a({1});
  vector<int> b({2});
  EXPECT_EQ(MediaArrays().findMedianSortedArrays(a, b), 1.5);
  a.clear();
  a.push_back(0);
  b.clear();
  EXPECT_EQ(MediaArrays().findMedianSortedArrays(a, b), 0.0);
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
