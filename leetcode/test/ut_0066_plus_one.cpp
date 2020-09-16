#include <iostream>
#include <vector>

#include "0066_plus_one/plus_one.h"
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char **argv) {
    PlusOne su;
    vector<int> vec1({1, 2, 3, 4, 5});
    su.plusOne(vec1);
    vector<int> vec2({0});
    su.plusOne(vec2);
    vector<int> vec3({9, 9, 9, 9, 9, 9});
    su.plusOne(vec3);
    vector<int> vec4({1, 9, 9, 9, 9, 9, 9});
    su.plusOne(vec4);
    return 0;
}
