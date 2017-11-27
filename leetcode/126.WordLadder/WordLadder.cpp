#include <iostream>
#include <vector>
#include <string>
using namespace std;
int diff(string a, string b)
{
    if(a.size() != b.size())
        return -1;
    int diff = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i])
            diff++;
    }
    return diff;
}
void ledder(string begin, string end, vector<string> dict, vector<vector<string > > &result)
{
}
vector<vector<string> > ledder(string begin, string end, vector<string> dict)
{
    vector<vector<string> > result;
    ledder(begin, end, dict, result);
    return result;
}
int main()
{
    string begin = "hit";
    string end = "cog";
    vector<string> dict({"hit", "hot", "dot", "dog", "cog"});
    vector<vector<string> > result = ledder(begin, end, dict);
    for(auto vec : result)
    {
        for(auto s : vec)
            cout << s << "\t";
        cout << endl;
    }
    return 0;
}
