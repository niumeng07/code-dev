#include <iostream>
#include <fstream>
#include <unordered_map>
#include <random>
#include <stdio.h>
#include <limits>

using namespace std;

int main(int argc, char *argv[])
{
    ofstream fsout;
    fsout.open("./data.txt");
    std::unordered_map<uint64_t, float> model;
    std::default_random_engine e;
    uniform_int_distribution<uint64_t> u(0, std::numeric_limits<uint64_t>::max()); //随机数分布对象 
    uniform_real_distribution<> dis(0.0, 10.0);
    // cout << u(e) << endl; //生成随机数
    // cout << setprecision(20) << dis(e) << endl; //生成随机数

    getchar();
    for (uint64_t i = 0; i < 5000000; ++i) {
        uint64_t key = u(e);
        double value = dis(e);
        model[key] = value;
        fsout << to_string(key) << ","  << setprecision(32) << value << endl;
    }
    std::cout << "model.size: " << model.size() << std::endl;
    fsout.close();
    getchar();
    return 0;
}
