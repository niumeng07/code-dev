#include <iostream>
#include <limits>
using namespace std;

static inline std::string fast_int64_cross(uint64_t fea_value1,
                                           uint64_t fea_value2) {
    uint64_t temp[2];
    temp[0] = fea_value1;
    temp[1] = fea_value2;
    const char* y = (const char*)&temp[0];
    cout << "y: " << y << endl;
    string x = std::string((const char*)&temp[0]);
    // return std::to_string(fea_value1) + "|" + std::to_string(fea_value2);
    return x;
}

static inline std::string fast_int64_cross2(uint64_t fea_value1, uint64_t fea_value2) {
    uint64_t temp[2];
    temp[0] = fea_value1;
    temp[1] = fea_value2;
    return std::string((const char*)(&temp[0], 128));
}

void test4() {
    uint64_t x = -1;
    if (x == -1) {
        cout << "is -1" << endl;
    }
}

void test5() {
    cout << "test5" << endl;
    cout << "uint64_t min " << std::numeric_limits<uint64_t>::min() << endl;
    cout << "uint64_t max " << std::numeric_limits<uint64_t>::max() << endl;
    cout << "int64_t min " << std::numeric_limits<int64_t>::min() << endl;
    cout << "int64_t max " << std::numeric_limits<int64_t>::max() << endl;
    cout << "long min " << std::numeric_limits<long>::min() << endl;
    cout << "long max " << std::numeric_limits<long>::max() << endl;
    cout << "long long min " << std::numeric_limits<long long>::min() << endl;
    cout << "long long max " << std::numeric_limits<long long>::max() << endl;
}

int main(int argc, char *argv[]) {
    // cout << fast_int64_cross(100108493, 10891897) << endl;
    // test4();
    
    test5();
    return 0;
}
