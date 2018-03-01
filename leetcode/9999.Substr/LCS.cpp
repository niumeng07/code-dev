#include <iostream>
#include <string>
using namespace std;
// longest child string
// 不连续
int lcs(string a, string b)
{
    if(a.size() == 0 || b.size() == 0)
        return 0;
    if(a[0] == b[0]){
        return 1 + lcs(a.substr(1, a.size() -1), b.substr(1,b.size()-1));
    }
    else{
        int l = lcs(a.substr(1, a.size() -1), b.substr(1,b.size()-1));
        if (lcs(a.substr(1, a.size() -1), b) > l )
            l = lcs(a.substr(1, a.size() -1), b);
        if (lcs(a, b.substr(1,b.size()-1)) > l )
            l = lcs(a, b.substr(1,b.size()-1));
        return l;
    }
}
int main()
{
    string a ="afcdefgi";
    string b = "acfhi";
    int result = lcs(a,b);
    cout << result << endl;
    return 0;
}
