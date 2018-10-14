#include <iostream>
#include "Solution.h"

int main(int argc, char *argv[])
{
    Solution su;
    vector<int> input({3,2,1,5,6,4});
    cout << su.findKthLargest(input, 2) << endl;
    cout << su.findKthLargest2(input, 2) << endl;
    return 0;
}
