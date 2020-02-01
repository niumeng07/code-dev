#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "0027_remove_element/remove_element.h"
using namespace std;

int main(int argc, char **argv)
{
    RemoveElement su;
    vector<int> v({3,2,2,3});
    cout << su.removeElement(v, 3) << endl;
    return 0;
}
