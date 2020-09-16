#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class CombinationOfPhoneNumber {
public:
    CombinationOfPhoneNumber() {
        hash[2] = {'a', 'b', 'c'};
        hash[3] = {'d', 'e', 'f'};
        hash[4] = {'j', 'k', 'l'};
        hash[5] = {'j', 'k', 'l'};
        hash[6] = {'m', 'n', 'o'};
        hash[7] = {'p', 'q', 'r', 's'};
        hash[8] = {'t', 'u', 'v'};
        hash[9] = {'w', 'x', 'y', 'z'};
        hash[0] = {' '};
    }
    // 这是一个搜索算法
    void combineDFS(vector<string>& result, int numIter, string digits) {
        if (numIter == 0) return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int numIter = digits.size();
        combineDFS(result, numIter, digits);
        return result;
    }

public:
    unordered_map<int, vector<char> > hash;
};
