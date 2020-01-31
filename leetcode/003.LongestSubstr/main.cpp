#include "Solution.h"
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
