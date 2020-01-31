#include <vector>
#include <string>

using namespace std;
void generate(vector<string>& ret, int left, int right, int n, string s)
{
    if( left == n && left == right)
        ret.emplace_back(s);
    if( left == n && left != right)
        generate( ret, left, right + 1, n, s + ")" );

    if ( left < n && left == right )
        generate( ret, left + 1, right, n, s + "(" );
    if( left <n && left != right)
    {
        generate( ret, left + 1, right, n, s + "(" );
        generate( ret, left, right + 1, n, s + ")" );
    }
    return;
}
class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ret;       
        generate( ret, 0, 0, n, "");
        return ret;
    }
};
