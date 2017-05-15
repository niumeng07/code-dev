#include <iostream>
#include "Solution.h"
using namespace std;

int main()
{
    Solution su;
    if(su.isValid("]"))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
