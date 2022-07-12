#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0394_decode_string/decode_string.h"

TEST(decode_string0, test0) {
    EXPECT_EQ(Solution().decodeString("3[a]2[bc]"), "aaabcbc");
    EXPECT_EQ(Solution().decodeString("3[a2[c]]"), "accaccacc");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
