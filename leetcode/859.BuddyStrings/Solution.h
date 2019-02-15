#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    //
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length())
            return false;
        int l = 0, r = 0;
        int num = 0;
        for (int i = 0; i < A.length(); i++) {
            if (A[i] != B[i]) {
                num++;
                if (num == 1) l = i;
                else r = i;
            }
        }
        if (num != 2)
            return false;
        if ( !( A[l] == B[r]&& A[r] == B[l]))
            return false;
        return true;
    }
};
