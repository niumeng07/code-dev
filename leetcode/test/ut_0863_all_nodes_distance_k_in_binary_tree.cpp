#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0863_all_nodes_distance_k_in_binary_tree/all_nodes_distance_k_in_binary_tree.h"

TEST(all_nodes_distance_k_in_binary_tree0, test0) {
    Solution().distanceK(nullptr, nullptr, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
