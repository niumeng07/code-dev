#include <vector>
#include <iostream>
#include "Solution_N2.h"
#include "Solution_N.h"
#include "Solution_B.h"
#include "Solution_Review.h"

using namespace std;

int main()
{
    vector<int> in({5,7,9,1,3,2,4});
    Solution_C su;
    vector<int> out = su.twoSum(in, 6);
    for(auto x : out)
    {std::cout << x << "\t" << std::ends;}
    std::cout << std::endl;
    Solution_Review sur;
    vector<int> out2 = sur.towSum(in, 6);
    for(auto x: out2)
    {std::cout << x << "\t" << std::ends;}
    std::cout << std::endl;
    vector<vector<int> > out3 = sur.twoSumAll(in, 6);
    for(auto vec : out3){
        for (auto x : vec){
            std::cout << x << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}
