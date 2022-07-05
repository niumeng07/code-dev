#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int L = 10;
        size_t len = s.size();
        string n;
        std::unordered_map<std::string, int> count;
        std::vector<string> res;
        if (len < L) return res;
        for (int i = 0; i <= len - L; i++) {
             n = s.substr(i, L);
             if (++count[n] == 2) {
                 res.push_back(n);
             }
        }
        return res;
    }
};
