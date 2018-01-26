#include <iostream>
#include <string>
using namespace std;
// longest child string
// 不连续
int lcs(string a, string b)
{
    if(a[0] == b[0]){
        return 1 + lcs(a.substr(1, a.size() -1), b.substr(1,b.size()-1));
    }
    else{
        return lcs(a.substr(1, a.size() -1), b.substr(1,b.size()-1));
    }
}
int main()
{
    string a ="abcdefghi";
    string b = "acfhi";
    int result = lcs(a,b);
    cout << result << endl;
    return 0;
}
