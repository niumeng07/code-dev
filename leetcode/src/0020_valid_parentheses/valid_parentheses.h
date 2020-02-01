#include <vector>
#include <iostream>
using namespace std;

bool match(char a, char b)
{
    if ( a == '(' && b == ')')
        return true;
    if ( a == '[' && b == ']')
        return true;
    if ( a == '{' && b == '}')
        return true;
    return false;
}
class ValidParentheses 
{
public:
    bool isValid(string s) 
    {
        vector<char> q;
        for(int i = 0; i < s.size(); i++)
        {
            if( char(s[i]) == '(' || char(s[i]) == '[' || char(s[i]) =='{')
                q.push_back(char(s[i]));
            else if(char(s[i]) == ')' || char(s[i]) == ']' || char(s[i]) =='}')
            {
                if(q.empty()) return false;
                if( match(q.back(), char(s[i])) )
                    q.pop_back();
                else
                {
                    return false;
                }
            }
        }
        if( !q.empty() ) return false;

        return true;
    }
};
