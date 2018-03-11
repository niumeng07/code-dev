#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> stack;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            if (s[i] == ' ') {
                stack.push_back(s.substr(left, (i - left)));
                left = i + 1;
            }
        }
        stack.push_back(s.substr(left, (s.size() - left)));
        if (!stack.empty())
            s = stack[stack.size() - 1];
        for (int j = stack.size() - 2; j >= 0; j--) {
            s = s + " " + stack[j];
        }
    }
};
