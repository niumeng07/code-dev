#include "gtest/gtest.h"
#include <vector>
#include <iostream>
#include "0035_search_insert_position/search_insert_position.h"
using namespace std;
int main(int argc, char **argv)
{
    SearchInsertPosition su;
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
