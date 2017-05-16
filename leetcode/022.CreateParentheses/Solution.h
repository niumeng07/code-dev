#include <vector>
#include <string>

using namespace std;
void generate(vector<string>& ret, int left, int right, int n, string s)
{
    cout << left << "\t" << right << endl;
    if( left == n && right == n)
    {
        cout << "a" << endl;
        ret.emplace_back(s);
        return;
    }
    if ( left == n && right < n )
    {
        generate( ret, left, right + 1, n, s + ")" );
    }
    if ( left < n )
    {
        if ( left == right )
        {
            cout << "b" << endl;
            generate( ret, left + 1, right, n, s + "(" );
        }
        else
        {
            cout << "c" << endl;
            generate( ret, left + 1, right, n, s + "(" );
            generate( ret, left, right + 1, n, s + ")" );
        }
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
    }
};
