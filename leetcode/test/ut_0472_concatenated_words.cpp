#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0472_concatenated_words/concatenated_words.h"

TEST(concatenated_words0, test0) {
    vector<string> words({"cat", "cats", "catsdogcats", "dog", "dogcatsdog",
                          "hippopotamuses", "rat", "ratcatdogcat"});
    vector<string> excepted({"catsdogcats", "dogcatsdog", "ratcatdogcat"});

    EXPECT_EQ(Solution().findAllConcatenatedWordsInADict(words), excepted);
    vector<string> output = Solution().findAllConcatenatedWordsInADict(words);
    std::sort(output.begin(), output.end());
    std::sort(excepted.begin(), excepted.end());
    EXPECT_EQ(output, excepted);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
