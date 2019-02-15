#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//具有不重复字符的最长子串
int main(int argc, char *argv[]) {
    string s = "abcabcbb";
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) 
    {
        if (dict[s[i]] > start) {
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    cout << maxLen << endl;
    return 0;
}
