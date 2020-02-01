#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HappyNumber {
public:
    bool isHappy(int n) {
        origin.push_back(n);
        return isHappyImpl(n);
    }
    bool isHappyImpl(int n) {
        int sum = 0;
        while(n != 0) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        if(sum == 1) {
            return true;
        } else if(std::count(origin.begin(), origin.end(), sum)) {
            return false;
        } else {
            origin.push_back(sum);
            return isHappyImpl(sum);
        }
    }
    vector<int> origin;
};
