#include <vector>
#include <iostream>
#include "Solution_N2.h"
#include "Solution_N.h"

using namespace std;

int main()
{
    vector<int> in({5,7,9,1,3,2,4});
    Solution_N su;
    vector<int> out = su.twoSum(in, 6);
    for(auto x : out)
    {std::cout << x << "\t" << std::ends;}
    std::cout << std::endl;
    return 0;
}
