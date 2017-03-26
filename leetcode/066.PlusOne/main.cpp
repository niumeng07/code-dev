#include "Solution.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{ 
    Solution su;
    vector<int> vec1({1,2,3,4,5});
    su.plusOne(vec1);
    vector<int> vec2({0});
    su.plusOne(vec2);
    vector<int> vec3({9,9,9,9,9,9});
    su.plusOne(vec3);
    vector<int> vec4({1,9,9,9,9,9,9});
    su.plusOne(vec4);
    return 0;
}
