#include <string>
#include <vector>
#include <limits>

using namespace std;
/*
 * Write a function to find the longest common prefix string amongst an array of
 * strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 * Example 2:
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * Note:
 *
 * All given inputs are in lowercase letters a-z.
 * */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { 
        string res = "";
        uint32_t strsNum = strs.size();
        if (strsNum == 0) return res;
        uint32_t strLen = std::numeric_limits<uint32_t>::max();
        for (auto s: strs) {
            if (s.size() < strLen) strLen = s.size();
        }
        // strLen是所有str的最小长度
        for (int idx = 0; idx < strLen; idx++) {
            char base = strs[0][idx];
            for (int j = 1; j < strsNum; j++) {
                if (strs[j][idx] - base) return res;
            }
            res.push_back(base);
        }
        return res;
    }
};
