/**
 * @brief
 * Given a string s, find the longest palindromic substring in s. You may assume
 * that the maximum length of s is 1000.
 *
 * Example:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 * Example:
 * Input: "cbbd"
 * Output: "bb"
 *
 */
#include <iostream>
#include <string>
using namespace std;
class Palindrome {
public:
  bool isPalind(string s) {
    if (s.length() <= 1)
      return true;
    int begin = 0, end = s.length() - 1;
    while (end >= begin) {
      if (char(s[begin]) != char(s[end]))
        return false;
      end--;
      begin++;
    }
    return true;
  }
  string longestPalindrome(string s) {
    if (s.length() <= 1)
      return s;
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
      for (int k = 0; k < s.length(); k++) {
        if (isPalind(s.substr(i, k - i + 1)) &&
            ((k - i + 1) > (end - start + 1))) {
          start = i;
          end = k;
        }
      }
    }
    cout << s << "    " << s.substr(start, end - start + 1) << endl;
    return s.substr(start, end - start + 1);
  }
  /*
   * 该方法思路：
   *   以任意一个字符为中心向两边扩展，求最大循环长度
   *   若连续N个字符相同，则这个N个字符被视为一个整体向两边扩展
   * */
  std::string longestPalindrome2(string s) {
    if (s.size() < 2)
      return s;
    int len = s.size(), max_left = 0, max_len = 1, left, right;
    for (int start = 0; start < len && len - start > max_len / 2;) {
      left = right = start;
      while (right < len - 1 && s[right + 1] == s[right])
        ++right;
      start = right + 1;
      while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
        ++right;
        --left;
      }
      if (max_len < right - left + 1) {
        max_left = left;
        max_len = right - left + 1;
      }
    }
    return s.substr(max_left, max_len);
  }
  std::string longestPalindrome3(string s) {
    if (s.size() < 2)
      return s;
    int max_len = 1;
    int left, right, max_l, max_r;
    for (int i = 0; i < s.size(); i++) {
      left = i, right = i;
      for (int k = 1; i - k >= 0 && i + k < s.size(); k++) {
        if (char(s[i - k]) != char(s[i + k]))
          break;
        left = i - k;
        right = i + k;
        if (right - left + 1 > max_len) {
          max_len = right - left + 1;
          max_l = left;
          max_r = right;
        }
      }

      if (i + 1 < s.size()) {
        if (char(s[i]) != char(s[i + 1]))
          continue;
        left = i;
        right = i + 1;
        if (right - left + 1 > max_len) {
          max_len = right - left + 1;
          max_l = left;
          max_r = right;
        }
        for (int k = 1; i - k >= 0 && i + k + 1 < s.size(); k++) {
          left = i - k;
          right = i + 1 + k;
          if (char(s[i - k]) != char(s[i + 1 + k]))
            break;
          if (right - left + 1 > max_len) {
            max_len = right - left + 1;
            max_l = left;
            max_r = right;
          }
        }
      }
    }
    return s.substr(max_l, max_len);
  }
};
