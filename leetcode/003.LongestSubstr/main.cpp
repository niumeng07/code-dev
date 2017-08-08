#include "Solution.h"
#include "Solution_B.h"
#include <iostream>

int main()
{
    Solution su;
    Solution_B su2;
    std::string str = "abcfdsfadqpei jakdjfadhjagh ajdfakldsjflqejr38rujaklejfaldhgadjflakjdfdlkajfkadjfkaljfabcbb";
    str = "abadb";
    std::cout << su.lengthOfLongestSubstring(str) << std::endl;;
    std::cout << su2.lengthOfLongestSubstring(str) << std::endl;;
    return 0;
}
