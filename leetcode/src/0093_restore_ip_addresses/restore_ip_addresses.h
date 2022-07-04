#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /* 用3个点把字符串分成4段,每段最小长度1，最大长度3
     * 然后验证不合理(大于等于255,前导0等)
     * */
    bool check_leagle(const string& item) {
        if (item.size() == 0 || item.size() > 3) return false;
        if (item[0] == '0' && item.size() > 1) return false;
        if (stoi(item) > 255) return false;
        return true;
    }
    void splitStr(string s, vector<string>& single_ip_parts,
                  vector<vector<string>>& splits, int need_parts) {
        if (single_ip_parts.size() == 4 && s.size() == 0) {
            for (const auto& item: single_ip_parts) {
                if (!check_leagle(item)) {
                    return;
                }
            }
            splits.push_back(single_ip_parts);
            return;
        } else if (single_ip_parts.size() >= 4) {
            return;
        }
        for (int i = 1; i <= 3 && i <= s.size(); i++) {
            single_ip_parts.push_back(s.substr(0, i));
            splitStr(s.substr(i, s.size()), single_ip_parts, splits, need_parts - 1);
            single_ip_parts.pop_back();
        }
        return;
    }
    string joinVector(const vector<string>& input, string split) {
        if (input.empty()) return "";
        string result = input[0];
        for (int i = 1; i < input.size(); i++) {
            result += ("." + input[i]);
        }
        return result;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<vector<string>> splits;
        vector<string> single_ip_parts;
        splitStr(s, single_ip_parts, splits, 4);
        vector<string> results;
        for (const auto& ip_parts : splits) {
            results.push_back(joinVector(ip_parts, "."));
        }
        return results;
    }
};
