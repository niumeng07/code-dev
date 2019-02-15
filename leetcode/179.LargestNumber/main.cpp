#include <iostream>
#include "Solution.h"

int main(int argc, char *argv[])
{
    Solution su;
    vector<int> input({3,30,34,5,9});
    string result = su.largestNumber(input);
    cout << result << endl;
    return 0;
}
