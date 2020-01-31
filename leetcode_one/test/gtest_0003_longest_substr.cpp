#include "gtest/gtest.h"
#include "0003_longest_substr/longest_substr.h"
#include <iostream>

int main() {
  Solution su;
  std::string str =
      "abcfdsfadqpei jakdjfadhjagh "
      "ajdfakldsjflqejr38rujaklejfaldhgadjflakjdfdlkajfkadjfkaljfabcbb";
  str = "abadb";
  std::cout << su.lengthOfLongestSubstring(str) << std::endl;
  return 0;
}
