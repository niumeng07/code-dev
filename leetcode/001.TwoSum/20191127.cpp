#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> input({1,2,4,6,7,8,9,10});
    unordered_map<int, int> p_map;
    int target = 11;

    for(int i = 0; i < input.size(); i++) {
        p_map[target - input[i]] = i;
    }
    for(int i = 0; i < input.size(); i++) {
        if (p_map.find(input[i]) != p_map.end()) {
            std::cout << i << ": " << input[i] << "\t" << p_map[input[i]] << ": " << input[p_map[input[i]]] << std::endl;
            // break;
        }
    }
    return 0;
}
