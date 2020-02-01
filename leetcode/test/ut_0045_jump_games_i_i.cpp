#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "0045_jump_games_i_i/jump_games_i_i.h"
using namespace std;
int main(int argc, char **argv)
{
    JumpGamesII su;
    vector<int> steps({2,3,1,1,4});
    cout << su.jump(steps) << endl;
    return 0;
}
