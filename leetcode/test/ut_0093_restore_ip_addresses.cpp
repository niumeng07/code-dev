#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0093_restore_ip_addresses/restore_ip_addresses.h"

TEST(restore_ip_addresses0, test0) {
    EXPECT_EQ(Solution().restoreIpAddresses("25525511135"),
              vector<string>({"255.255.11.135", "255.255.111.35"}));
    EXPECT_EQ(Solution().restoreIpAddresses("0000"),
              vector<string>({"0.0.0.0"}));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
