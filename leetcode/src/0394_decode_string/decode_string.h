#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> nums;
        stack<string> strs;
        int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            } else if ((s[i] >= 'a' && s[i] <= 'z')) {
                res = res + s[i];
            } else if (s[i] == '[') {
                nums.push(num);
                num = 0;
                strs.push(res);
                res = "";
            } else {
                int times = nums.top();
                nums.pop();
                for (int j = 0; j < times; ++j) strs.top() += res;
                res = strs.top();
                strs.pop();
            }
        }
        return res;
    }
};
