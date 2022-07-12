#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        while (true) {
            if (n == 0) {
                return false;
            } else if (n == 1) {
                return true;
            } else if ((n % 5) == 0) {
                n = n / 5;
            } else if ((n % 2) == 0) {
                n = n / 2;
            } else if ((n % 3) == 0) {
                n = n / 3;
            } else {
                break;
            }
        }
        return false;
    }
};
