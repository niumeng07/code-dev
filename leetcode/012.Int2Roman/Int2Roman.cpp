#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
 * 罗马数字: I II III IV VI VII VIII IX X      1-10
 *           X XX XXX XL L LX LXX LXXX XC C    (1-10)*10
 *           C CC CCC CD D DC DCC DCCC CM M    (1-10)*100
 *           M MM MMM
 *           I: 1  V: 5 X: 10 L: 50 C: 100 D: 500 M: 1000
 * */
int main()
{
    map<int, vector<string> > hash;
    vector<string> tmp1({"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"});
    vector<string> tmp2({"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"});
    vector<string> tmp3({"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"});
    vector<string> tmp4({"", "M", "MM", "MMM"});
    hash.insert(std::make_pair(1, tmp1));
    hash.insert(std::make_pair(10, tmp2));
    hash.insert(std::make_pair(100, tmp3));
    hash.insert(std::make_pair(1000, tmp4));
    int x = 99; // IC(100-1: wrong)  XCIX(XC=90, IX=9: right)
    int m = x / 1000;
    int h = x % 1000 /100;
    int t = x % 1000 % 100 /10;
    int o = x % 1000 % 100 % 10;
    string result = hash[1000][m] + hash[100][h] + hash[10][t] + hash[1][o];
    cout << "result: " << result << ", label: " << "XCIX" << endl;
    return 0;
}
