#include "gtest/gtest.h"
#include <iostream>
#include "0859_buddy_strings/buddy_strings.h"

int main(int argc, char **argv) {
    BuddyStrings su;
    std::cout << su.buddyStrings("ab", "ba") << std::endl;
    std::cout << su.buddyStrings("aaaaaaabc", "aaaaaaacb") << std::endl;
    std::cout << su.buddyStrings("ab", "ab") << std::endl;
    std::cout << su.buddyStrings("aa", "aa") << std::endl;
    return 0;
}
