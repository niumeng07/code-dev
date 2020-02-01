#include "gtest/gtest.h"
#include <vector>
#include <iostream>
#include "0075_sort_colors/sort_colors.h"

using namespace std;

int main(int argc, char **argv)
{
    SortColors su;
    vector<int> v({2,0,1,2,1,2,1,1,1,0,0});
    su.sortColors(v);
    for(auto x : v)
        cout << x << ", ";
    cout << endl;
    return 0;
}
