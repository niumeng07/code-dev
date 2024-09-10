#include "header.h"
/*
 * 给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。
 * 返回 已排序的字符串 。如果有多个答案，返回其中任何一个。
 *
 * 示例 1:
 * 输入: s = "tree"
 * 输出: "eert"
 * 解释: 'e'出现两次，'r'和't'都只出现一次。
 * 因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
 *
 * 示例 2:
 * 输入: s = "cccaaa"
 * 输出: "cccaaa"
 * 解释: 'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
 * 注意"cacaca"是不正确的，因为相同的字母必须放在一起。
 *
 * 示例 3:
 * 输入: s = "Aabb"
 * 输出: "bbAa"
 * 解释: 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
 * 注意'A'和'a'被认为是两种不同的字符。
 *
 *
 * 提示:
 * 1 <= s.length <= 5 * 105
 * s 由大小写英文字母和数字组成
 **/

// bool comp(pair<char,int> a, pair<char,int> b) {
//     return a.second > b.second;
// }

// class Solution {
// public:
    string frequencySort(string s) {
        std::unordered_map<char, int> freqs;  // 频次计数
        for (size_t i = 0; i < s.size(); i++) {
            if (freqs.find(s[i]) == freqs.end()) {
                freqs[s[i]] = 1;
            } else {
                freqs[s[i]]++;
            }
        }

        // 遍历所有频率拼接成新的字符器
        std::vector<std::pair<char, int>> sortedfreqs(freqs.begin(), freqs.end());

        // std::sort(sortedfreqs.begin(), sortedfreqs.end(), comp);
        std::sort(sortedfreqs.begin(), sortedfreqs.end(),
                  [](pair<char, int> a, pair<char, int> b) { return a.second > b.second; });

        string results = "";
        for (const auto& item : sortedfreqs) {
            for (int i = 0; i < item.second; i++) {
                results += item.first;  // 这里写成re = re + .. 会超内存
            }
        }

        return results;
    }
// };

int main(int argc, char* argv[]) {
    cout << frequencySort("Aabb") << endl;
    return 0;
}
