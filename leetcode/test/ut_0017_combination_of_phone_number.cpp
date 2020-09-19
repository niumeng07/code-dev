#include <iostream>
#include <string>
#include <algorithm>

#include "0017_combination_of_phone_number/combination_of_phone_number.h"
#include "gtest/gtest.h"

using namespace std;
TEST(combination_of_phone_number, test0) {
    vector<string> except{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    std::sort(except.begin(), except.end());
    vector<string> output = CombinationOfPhoneNumber().letterCombinations("123");
    std::sort(output.begin(), output.end());
    EXPECT_EQ(except, output);
}

TEST(combination_of_phone_number, test1) {
    vector<string> except{};
    std::sort(except.begin(), except.end());
    vector<string> output = CombinationOfPhoneNumber().letterCombinations("1");
    std::sort(output.begin(), output.end());
    EXPECT_EQ(except, output);
}

TEST(combination_of_phone_number, test2) {
    vector<string> except{};
    std::sort(except.begin(), except.end());
    vector<string> output = CombinationOfPhoneNumber().letterCombinations("");
    std::sort(output.begin(), output.end());
    EXPECT_EQ(except, output);
}

TEST(combination_of_phone_number, test3) {
    vector<string> except{"a", "b", "c"};
    std::sort(except.begin(), except.end());
    vector<string> output = CombinationOfPhoneNumber().letterCombinations("2");
    std::sort(output.begin(), output.end());
    EXPECT_EQ(except, output);
}

TEST(vector_erase, test0) {
    vector<int> x{1,2,3};
    auto iter = x.begin();
    x.erase(iter);
    x.insert(iter, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
