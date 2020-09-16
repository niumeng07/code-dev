#include <iostream>
#include <string>
#include <vector>

#include "0049_group_anagrams/group_anagrams.h"
#include "gtest/gtest.h"

using namespace std;

TEST(group_anagrams, test0) {
    clock_t start = clock();
    vector<string> strs({"eat", "tea", "tan", "ate", "nat", "bat"});
    for (int i = 0; i < 1000; i++) {
        GroupAnagrams().groupAnagrams(strs);
    }
    clock_t end = clock();
    std::cout << "test0 used: " << end - start << std::endl;
}

TEST(group_anagrams, test1) {
    clock_t start = clock();
    vector<string> strs({"eat", "tea", "tan", "ate", "nat", "bat"});
    for (int i = 0; i < 1000; i++) {
        vector<vector<string>> res = GroupAnagrams().groupAnagramsRv(strs);
    }
    clock_t end = clock();
    std::cout << "test1 used: " << end - start << std::endl;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
