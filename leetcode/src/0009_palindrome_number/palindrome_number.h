/**
 * @brief 判断是否为循环数
 */
#include <iostream>
using namespace std;

class PalindromeNumber {
public:
  bool is_debug;
  PalindromeNumber() : is_debug(false) {}
  PalindromeNumber(bool d) : is_debug(d) {}
  bool isPalindrome(int x) {
    int x_ori = x;
    if (x < 0)
      return false;
    long result = 0;
    while (x != 0) {
      result = result * 10 + x % 10;
      x = x / 10;
    }
    if ((long)x_ori == result)
      return true;
    return false;
  }

  bool isPalindromeUint64(uint64_t x) {
    uint64_t big_number = 10000000000000000000;
    uint64_t y = 0;
    uint32_t b = 0;
    uint32_t one = x % 10;
    if (x > big_number) {
      if (one != 1)
        return false;
      x = x - big_number;
      x = x / 10;
    }
    uint64_t xx = x;
    while (x > 0) {
      y = 10 * y + (x % 10);
      x = x / 10;
    }
    if (y == xx) {
      return true;
    } else {
      return false;
    }
  }
};
