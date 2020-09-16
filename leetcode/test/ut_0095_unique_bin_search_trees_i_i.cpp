#include <time.h>

#include <iostream>
#include <vector>

#include "0095_unique_bin_search_trees_i_i/unique_bin_search_trees_i_i.h"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char **argv) {
    UniqueBinSearchTreesII su;
    clock_t start, end;
    start = clock();
    vector<TreeNode *> result = su.generateTrees(3);
    end = clock();
    cout << "time used: " << end - start << " us" << endl;
    for (vector<TreeNode *>::iterator iter = result.begin();
         iter != result.end(); iter++) {
        TravelTree(*iter);
    }
    return 0;
}
