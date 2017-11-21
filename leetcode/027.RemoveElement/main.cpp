#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main()
{
    Solution su;
    vector<int> v({3,2,2,3});
    cout << su.removeElement(v, 3) << endl;
    return 0;
}
