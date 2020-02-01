#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Parentheses 
{
public:
    int longestValidParentheses(string s) 
    {
        int length = 0;
        int tail_size = s.size();
        for ( int i = 0; i < s.size(); )
        {
            int curr = 0;
            int left = i, right = i;
            int j = i;
            for ( j = i; j < s.size(); j++)
            {
                if(char(s[j]) == '(' ) curr++;
                if(char(s[j]) == ')' ) curr--;
                if(curr < 0 || curr > tail_size / 2 + 1 ) break;
                if(curr == 0 && j - i + 1 > length) 
                {
                    left = i; 
                    right = j;
                    length = right - left + 1;
                }
            }
            i = right + 1;
            tail_size = s.size () - i + 1;
        }
        return length;
    }
	int longestValidParenthesesDP(string s) 
    {
        if(s.length() <= 1) return 0;
        int curMax = 0;
        vector<int> longest(s.size(),0);
        for(int i=1; i < s.length(); i++)
        {
            if(s[i] == ')')
            {
                if(s[i-1] == '(')
                {
                    longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
                    curMax = max(longest[i],curMax);
                }
                else
                { // if s[i-1] == ')', combine the previous length.
                    if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '(')
                    {
                        longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                        curMax = max(longest[i],curMax);
                    }
                }
            }
            //else if s[i] == '(', skip it, because longest[i] must be 0
        }
        return curMax;
    }
	int longestValidParentheses8ms(string s) 
    {
        stack<int> stk;
        stk.push(-1);
        int maxL=0;
        for(int i=0;i<s.size();i++)
        
        {
            int t=stk.top();
            if(t!=-1&&s[i]==')'&&s[t]=='(')
            
            {
                stk.pop();
                maxL=max(maxL,i-stk.top());
            }
            else
                stk.push(i);
        }
        return maxL;
    }
};
