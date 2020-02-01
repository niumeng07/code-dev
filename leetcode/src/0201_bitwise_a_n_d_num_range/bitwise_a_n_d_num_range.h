#include <iostream>

class BitwiseANDNumRange {
public:
  bool isEven(int x) {
    if (x % 2 == 0)
      return true;
    else
      return false;
  }
  int rangeBitwiseAndTimeExc(int m, int n) {
    int bitwiseand = 2147483647;
    for (int i = m; i <= n; i++) {
      bitwiseand = bitwiseand & i;
    }
    return bitwiseand;
  }
  int rangeBitwiseAndTime(int m, int n) {
    if (n > m)
      return 0;
    if (n == m)
      return m;
    int result = 0;
    int index = 0;
    for (int i = m; i <= n; i++) {
      if (m == 0 && n == 0)
        break;
      if (isEven(i)) {
        result = result | (1 << index);
        index++;
        continue;
      }
    }
    return 0;
  }
};

/*
1001001
1001010
1001011
1001100
1001101
全部为1的位
1001000
*/
/*
 * 101
 * 110
 * 111
 * */
