/**
 * @brief
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge,
 please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given
 input specs). You are responsible to gather all the input requirements up
 front.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 function signature accepts a const char * argument, please click the reload
 button  to reset your code definition.
 *
 * spoilers alert... click to show requirements for atoi.
 *
 * Subscribe to see which companies asked this question.

 */
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;
class String2Int {
public:
  int myAtoi(string str) {
    long result = 0;
    int sign = 1;
    int i = str.find_first_not_of(' ');
    for (; i < str.size();) {
      if (str[i] == '-' || str[i] == '+')
        sign = (str[i++] == '-') ? -1 : 1;
      while ('0' <= str[i] && str[i] <= '9') {
        result = result * 10 + (str[i++] - '0');
        if (result * sign >= numeric_limits<int>::max())
          return numeric_limits<int>::max();
        if (result * sign <= numeric_limits<int>::min())
          return numeric_limits<int>::min();
      }
      return result * sign;
    }
    return result;
  }
};
