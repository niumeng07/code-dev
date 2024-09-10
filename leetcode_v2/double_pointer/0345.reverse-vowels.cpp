#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        if (s.size() <= 1) {
            return s;
        }
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            unordered_set<char>::iterator iter_left = vowels.find(s[i]);
            unordered_set<char>::iterator iter_right = vowels.find(s[j]);
            if (iter_left != vowels.end() && iter_right!= vowels.end()) { // left right 属于 vowels
                char swp = s[i];
                s[i] = s[j];
                s[j] = swp;
                i ++;
                j --;
            } else if (iter_left != vowels.end()) { // left不属于vowels
                j--; 
            } else if (iter_right!= vowels.end()) {  // right 不属于vowels
                i++;
            } else {  // 左右都不属于vowels
                i ++;
                j --;
            }
        }
        return s;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    cout << solution.reverseVowels("hello") << endl;
    cout << solution.reverseVowels("leetcode") << endl;

    return 0;
}
