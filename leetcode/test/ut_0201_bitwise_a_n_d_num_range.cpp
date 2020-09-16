#include <iostream>

#include "0201_bitwise_a_n_d_num_range/bitwise_a_n_d_num_range.h"
#include "gtest/gtest.h"
using namespace std;

TEST(bitwise_and_num_range, test0) {
    cout << BitwiseANDNumRange().rangeBitwiseAndTimeExc(5, 7) << endl;
    cout << BitwiseANDNumRange().rangeBitwiseAndTimeExc(7, 8) << endl;
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
