/**
 * @brief Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Return:
 *
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note: All inputs will be in lower-case.
 *
 * Subscribe to see which companies asked this question.
 *
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
bool sfun(vector<string> &a, vector<string> &b) { return a.size() < b.size(); }
class GroupAnagrams {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;

    map<string, vector<string>> m;
    vector<string> tmp;

    for (auto word : strs) {
      sort(word.begin(), word.end());
      m[word] = tmp;
    }
    string st;
    for (auto word : strs) {
      st = word;
      sort(st.begin(), st.end());
      m[st].push_back(word);
    }
    for (auto iter = m.begin(); iter != m.end(); iter++) {
      sort(iter->second.begin(), iter->second.end());
      res.push_back(std::move(iter->second));
    }
    sort(res.begin(), res.end(), sfun);
    return res;
  }

  vector<vector<string>> groupAnagramsRv(vector<string> &strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;
    for (auto str : strs) {
      sort(str.begin(), str.end());
      m[str].push_back(str);
    }
    for (auto v : m) {
      res.push_back(v.second);
    }
    return res;
  }
};
