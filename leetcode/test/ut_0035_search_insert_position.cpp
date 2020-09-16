#include <iostream>
#include <vector>

#include "0035_search_insert_position/search_insert_position.h"
#include "gtest/gtest.h"
using namespace std;

TEST(search_insert_position, test0) {
    vector<int> input({1, 3, 5, 6});
    EXPECT_EQ(SearchInsertPosition().searchInsert(input, 5), 2);
    EXPECT_EQ(SearchInsertPosition().searchInsert(input, 2), 1);
    EXPECT_EQ(SearchInsertPosition().searchInsert(input, 7), 4);
    EXPECT_EQ(SearchInsertPosition().searchInsert(input, 0), 0);
}

TEST(search_insert_position, test1) {
    vector<int> input({1, 3, 5, 6});
    EXPECT_EQ(SearchInsertPosition().searchInsert_Review(input, 5), 2);
    EXPECT_EQ(SearchInsertPosition().searchInsert_Review(input, 2), 1);
    EXPECT_EQ(SearchInsertPosition().searchInsert_Review(input, 7), 4);
    EXPECT_EQ(SearchInsertPosition().searchInsert_Review(input, 0), 0);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
