#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_nqueens(vector<int> t)
{
    for(int i = 0; i < t.size(); i++)
    {
        for(int j = i + 1; j < t.size(); j++)
            if( abs(i-j) == abs(t[i] - t[j]))
                return false;
    }
    return true;
}
int NQueensII(int n)
{
    vector<vector<string> > result;
    vector<int> t;
    for(int i = 0; i < n; i++)
        t.push_back(i);
    do{
        if(is_nqueens(t))
        {
            vector<string> tmp;
            for(int i = 0; i<n;i++)
            {
                string x(n,'.');
                x[i] = 'Q';
                tmp.push_back(x);
            }
            result.push_back(tmp);
        }
    }while(std::next_permutation(t.begin(), t.end()));
    //result.erase(std::unique(result.begin(), result.end()), result.end());
    return result.size();
}
int main()
{
    cout << NQueensII(8) << endl;
    return 0;
}
