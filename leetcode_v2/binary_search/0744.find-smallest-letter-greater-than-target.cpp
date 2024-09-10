/*
 * 给你一个字符数组 letters，该数组按非递减顺序排序，以及一个字符 target。letters 里至少有两个不同的字符。
 * 返回 letters 中大于 target 的最小的字符。如果不存在这样的字符，则返回 letters 的第一个字符。
 *
 * 示例 1：
 * 输入: letters = ["c", "f", "j"]，target = "a"
 * 输出: "c"
 * 解释：letters 中字典上比 'a' 大的最小字符是 'c'。
 *
 * 示例 2:
 * 输入: letters = ["c","f","j"], target = "c"
 * 输出: "f"
 * 解释：letters 中字典顺序上大于 'c' 的最小字符是 'f'。
 *
 * 示例 3:
 * 输入: letters = ["x","x","y","y"], target = "z"
 * 输出: "x"
 * 解释：letters 中没有一个字符在字典上大于 'z'，所以我们返回 letters[0]。
 * */
#include "header.h"

// class Solution {
// public:
// 如果输入有序可以二分查找
    char nextGreatestLetter(vector<char>& letters, char target) {
        char result = '~';

        for (int i = 0; i < letters.size(); i++) {
            if (letters[i] > target) {
                result = min(result, letters[i]);
            }
        }

        if (result == '~') {
            result = letters[0];
        }

        return result;
    }

    char nextGreatestLetter2(vector<char>& letters, char target) {
        char result = letters[0];

        for (int i = 1; i < letters.size(); i++) {
            if (letters[i] > target && result > target) {
                result = min(result, letters[i]);
            } else if (letters[i] > target) {
                result = letters[i];
            }
        }

        return result;
    }

// };

int main(int argc, char *argv[])
{
    vector<char> letters = {'x','x','y','y'};
    // cout << nextGreatestLetter(letters, 'z') << endl;

    letters = {'c','f','j'};
    cout << nextGreatestLetter(letters, 'c') << endl;
    return 0;
}
