#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0187_dupilicates_dna/dupilicates_dna.h"

TEST(dupilicates_dna0, test0) {
    EXPECT_EQ(Solution().findRepeatedDnaSequences("AAAAAAAAAAA"),
              std::vector<string>({"AAAAAAAAAA"}));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
