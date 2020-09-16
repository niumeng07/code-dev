#include "gtest/gtest.h"
/**
 * @file main.cpp
 * @brief
 * @author myliuda@sina.com
 * @version 0.0
 * @date 2020-01-28
 */

#include <iostream>
#include <vector>

#include "0287_findthe_duplicate_number/findthe_duplicate_number.h"
using namespace std;

int main(int argc, char **argv) {
    vector<int> v({1, 2, 3, 4, 1, 2, 3});
    // std::cout << FindtheDuplicateNumber().findSingleNum(v) << std::endl;
    v = {13, 13, 46, 46, 8, 11, 11};
    /*v = {13, 46, 8,  11, 20, 17, 40, 13, 13, 13, 14, 1,  13, 36, 48, 41, 13,
         13, 13, 13, 45, 13, 28, 42, 13, 10, 15, 22, 13, 13, 13, 13, 23, 9,
         6,  13, 47, 49, 16, 13, 13, 39, 35, 13, 32, 29, 13, 25, 30, 13};*/
    std::cout << FindtheDuplicateNumber().findDuplicate2(v) << std::endl;
    std::cout << FindtheDuplicateNumber().findSingleRv(v) << std::endl;
    return 0;
}
