#include <vector>
#include <iostream>
#include "Solution.h"
using namespace std;
int main()
{
    Solution su;
    vector<int> input({1,3,5,6});
    int target = 5;
    cout << su.searchInsert(input, target)<< endl;
    target = 2;
    cout << su.searchInsert(input, target)<< endl;
    target = 7;
    cout << su.searchInsert(input, target)<< endl;
    target = 0;
    cout << su.searchInsert(input, target)<< endl;
    return 0;
}