#include <iostream>
#include "Solution.h"

int main() {
    Solution su;
    std::cout << su.buddyStrings("ab", "ba") << std::endl;
    std::cout << su.buddyStrings("aaaaaaabc", "aaaaaaacb") << std::endl;
    std::cout << su.buddyStrings("ab", "ab") << std::endl;
    std::cout << su.buddyStrings("aa", "aa") << std::endl;
    return 0;
}
