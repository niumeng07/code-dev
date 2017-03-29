#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalind(string s)
    {
        if (s.length() <= 1 ) return true;
        int begin = 0, end = s.length() - 1;
        while(end >= begin )
        {
            if ( char(s[begin]) != char(s[end]) ) return false;
            end--;
            begin++;
        }
        return true;
    }
    string longestPalindrome(string s) 
    {
        if(s.length() <= 1) return s;    
        int start = 0, end = 0;
        for( int i = 0; i < s.length(); i++)
        {
            for(int k = 0; k < s.length(); k++)
            {
                if( isPalind(s.substr(i, k - i + 1) ) &&( (k - i + 1) >( end -start +1)) )
                {
                    start = i;
                    end = k;
                }
            }
        }
        cout << s << "    " << s.substr(start, end-start+1) << endl;
        return s.substr(start, end-start+1);
    }
	std::string longestPalindrome2(string s) 
    {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) 
        {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) 
            {
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
};
