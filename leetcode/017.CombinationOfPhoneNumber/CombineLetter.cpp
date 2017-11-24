#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
void dfs(vector<string> &result, string& tmp, string input, unordered_map<string, vector<string> > hash)
{
    if(input.size() == 0)
        result.push_back(tmp); // 这里不能用std::move(tmp);
    else
    {
        string num = input.substr(0,1);
        input = input.substr(1, input.size() - 1);
        for( auto x : hash[num])
        {
            tmp = tmp + x;
            dfs(result, tmp, input, hash);
            tmp = tmp.substr(0, tmp.size() - 1);
        }
    }
}
vector<string> dfs(string input, unordered_map<string, vector<string> > hash)
{
    vector<string> result;
    string tmp = "";
    dfs(result, tmp, input, hash);
    return result;
}
int main()
{
    vector<string> v0({" "});
    vector<string> v1({});
    vector<string> v2({"a","b","c"});
    vector<string> v3({"d","e","f"});
    vector<string> v4({"g","h","i"});
    vector<string> v5({"j","k","l"});
    vector<string> v6({"m","n","o"});
    vector<string> v7({"p","q","r","s"});
    vector<string> v8({"t","u","v"});
    vector<string> v9({"w","x","y","z"});
    unordered_map<string, vector<string> > hash;
    hash.insert(make_pair("0", v0));
    hash.insert(make_pair("1", v1));
    hash.insert(make_pair("2", v2));
    hash.insert(make_pair("3", v3));
    hash.insert(make_pair("4", v4));
    hash.insert(make_pair("5", v5));
    hash.insert(make_pair("6", v6));
    hash.insert(make_pair("7", v7));
    hash.insert(make_pair("8", v8));
    hash.insert(make_pair("9", v9));
    string input = "23";
    vector<string> result = dfs(input, hash);
    for(auto x : result)
    { 
        cout << x << endl;
    }
    return 0;
}
