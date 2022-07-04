#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystack_size = haystack.size();
        int needle_size = needle.size();
        if (needle_size > haystack_size) return -1;
        for (int i = 0; i <= haystack_size - needle_size;) {
            if (haystack[i] == needle[0] && haystack.substr(i, needle_size) == needle) {
                return i;
            } else {
                i++;
            }
        }
        return -1;
    }
};
