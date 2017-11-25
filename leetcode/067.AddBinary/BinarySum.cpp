#include <iostream>
#include <string>
using namespace std;

string add_bianry(string left, string right)
{
    int length = (left.size() > right.size()) ? left.size() + 1 : right.size() + 1;
    string sum(length,'0');
    int i = left.size() - 1, j = right.size() - 1, one = 0, k = sum.size() - 1;
    while( i >= 0 && j >= 0)
    {
        if( (left[i] != '0' && left[i] != '1' ) || (right[j] != '0' && right[j] != '1'))// 二进制数合法性检测
            return "0";
        sum[k] = char((left[i] - '0' + right[j] - '0' + one ) % 2 + '0');
        one = (left[i] - '0' + right[j] - '0' + one ) / 2;
        k--;
        i--;
        j--;
    }
    while( i >= 0)
    {
        if( left[i] != '0' && left[i] != '1' ) // 二进制数合法性检测
            return "0";
        sum[k] = char((left[i] - '0' + one ) % 2 + '0');
        one = (left[i] - '0' + one ) / 2;
        i--;
        k--;
    }
    while( j >= 0)
    {
        if(right[j] != '0' && right[j] != '1')// 二进制数合法性检测
            return "0";
        sum[k] = char((right[j] - '0' + one ) % 2 + '0');
        one = (right[j] - '0' + one ) / 2;
        j--;
        k--;
    }
    sum[0] = char('0' + one);
    k = 0;
    while(sum[k] == '0')
        k++;
    return (sum.substr(k, sum.size() - k).empty()) ? "0" : sum.substr(k, sum.size() - k);
}
int main()
{
    cout << add_bianry("111", "1") << endl;
    cout << add_bianry("110", "1") << endl;
    cout << add_bianry("101", "1") << endl;
    cout << add_bianry("101", "10111") << endl;
    cout << add_bianry("12", "111") << endl;
    cout << add_bianry("0", "0")<< endl;
    return 0;
}
