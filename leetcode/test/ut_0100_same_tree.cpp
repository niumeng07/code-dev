#include <string>

#include "0100_same_tree/same_tree.h"
#include "gtest/gtest.h"

using namespace std;

TEST(same_tree, test0) {}

TEST(same_tree, test_r0) {
    Node<string> *root = new Node<string>("root");
    root->left = new Node<string>("left");
    root->right = new Node<string>("left");
    EXPECT_TRUE(MirrorTree<string>().isMirrorTree(root));
    root->right = new Node<string>("right");
    EXPECT_FALSE(MirrorTree<string>().isMirrorTree(root));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
