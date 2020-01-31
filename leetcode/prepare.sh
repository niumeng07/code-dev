name=""
for i in $*
do
    name=${name}$i
done
mkdir $name

cp ./SConstruct CMakeLists.txt $name

echo "\
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

};" > $name/Solution.hpp

echo "\
#include \"Solution.hpp\"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;
TEST(testCase, test0) {
  // EXPECT_EQ(Solution().processFun(...), correctResult);
}
TEST(testCase, test1) {
  // EXPECT_EQ(Solution().processFun(...), correctResult);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
" > $name/main.cpp

echo "" > $name/readme

