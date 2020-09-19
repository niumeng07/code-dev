#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. A mapping of digit to
 * letters (just like on the telephone buttons) is given below. Note that 1 does
 * not map to any letters.
 * Example:
 *   Input: "23"
 *   Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * */
class CombinationOfPhoneNumber {
public:
    CombinationOfPhoneNumber() {
        hash[2] = {'a', 'b', 'c'};
        hash[3] = {'d', 'e', 'f'};
        hash[4] = {'g', 'h', 'i'};
        hash[5] = {'j', 'k', 'l'};
        hash[6] = {'m', 'n', 'o'};
        hash[7] = {'p', 'q', 'r', 's'};
        hash[8] = {'t', 'u', 'v'};
        hash[9] = {'w', 'x', 'y', 'z'};
    }
    vector<int> toDigit(string digits) {
        vector<int> res;
        res.reserve(digits.size());
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] == '1') continue;
            res.emplace_back(digits[i] - '0');
        }
        exceptedStringSize = res.size();
        return res;
    }

    void search(vector<int> iDigits, vector<string>& result, string& str) {
        if (iDigits.size() == 0 && str.size() == exceptedStringSize &&
            str.size() > 0) {
            result.push_back(str);
        }

        for (auto iterDigits = iDigits.begin();
             iterDigits != iDigits.end();) {  // 遍历候选数字
            vector<char> local = hash[*iterDigits];  //候选字符
            iDigits.erase(iterDigits);
            for (auto iter = local.begin(); iter != local.end();
                 iter++) {  // 遍历候选字符
                str.push_back(*iter);
                search(iDigits, result, str);
                str.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        // string digits拆开
        vector<int> iDigits = toDigit(digits);
        // 构造
        vector<string> result;
        string str = "";
        search(iDigits, result, str);
        return result;
    }

public:
    unordered_map<int, vector<char> > hash;
    int exceptedStringSize;
};
