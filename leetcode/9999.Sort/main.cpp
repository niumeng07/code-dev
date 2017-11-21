#include "sort.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v({1,2,5,2,5,9,5,0});
    ld_sort s;
    s.quickSort(v);
    for( auto x:v)
        cout <<x << " ";
    cout <<endl;
    return 0;
}
