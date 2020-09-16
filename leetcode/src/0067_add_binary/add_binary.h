#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class AddBinary {
public:
    string addBinary(string aa, string bb) {
        string a = aa.size() >= bb.size() ? aa : bb;
        string b = aa.size() < bb.size() ? aa : bb;
        string res = "";
        int a_len = a.size(), b_len = b.size();
        int i = a_len - 1, j = b_len - 1;
        int andOne = 0;
        while (i >= 0 && j >= 0) {
            res += ((char)a[i] - '0' + (char)b[j] - '0' + andOne) % 2 + '0';
            andOne = ((char)a[i] - '0' + (char)b[j] - '0' + andOne) / 2;
            i--;
            j--;
        }
        while (i >= 0) {
            res += ((char)a[i] - '0' + andOne) % 2 + '0';
            andOne = ((char)a[i] - '0' + andOne) / 2;
            i--;
        }
        if (andOne) res += andOne + '0';
        reverse(res.begin(), res.end());
        return res;
    }
};
