#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    //O(N)空间复杂度的，不符合要求
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
    
    void reverseWords2(string &s) {
        int ll = 0, lr = 0;
        int rl = s.size() - 1, rr = s.size() - 1;
        while (true) {
            if ( rl < lr )
                break;
            if (s[lr] != ' ') {
                lr++;
                continue;
            }
            if (s[rl] != ' ') {
                rl--;
                continue;
            }
            //the sky is blue
            //   .      .
            s = s.substr(rl + 1, rr - rl) + " " + s.substr(lr + 1, rl - 1 - lr) + " " + s.substr(ll, lr - ll + 1);
            cout << s << endl;
            ll = lr + 1 + (rr - rl - (lr - ll + 1));
            rr = rl - 1 - ( rl - rr + (lr - ll + 1));
            lr = ll + 1;
            rl = rr - 1;
        }
    }
};
