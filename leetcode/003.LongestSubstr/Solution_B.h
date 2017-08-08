#include <string>
#include <vector> 
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution_B {
public:
    /*
     * the basic idea is, keep a hashmap which stores the characters in string as
     * keys and their positions as values, and keep two pointers which define the 
     * max substring. move the right pointer to scan through the string , and 
     * meanwhile update the hashmap. If the character is already in the hashmap, 
     * then move the left pointer to the right of the same character last found. 
     * Note that the two pointers can only move forward.
     * */
    int lengthOfLongestSubstring(string s) 
    {
        int maxLen = 0;
        unordered_map<char, int> hash;//每一个字符出现的位置
        int i = 0, j = 0;
        for( j = 0; j < s.length(); j++)
        {
            if(hash.find(s[j]) == hash.end())
                hash[s[j]] = j;
            else
            {
                maxLen = max(maxLen, j - i + 1);
                i = j + 1;
            }
        }
        return maxLen;
    }
};
