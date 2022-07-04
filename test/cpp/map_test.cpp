#include <time.h>

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <time.h>

using namespace std;

void test11() {
    map<int, int> m;
    map<int, int>::iterator it = m.find(1);
    for (auto pair1 : m) {
        cout << pair1.first << ":" << pair1.second << endl;
    }
}
// void test() {
//   std::map<string, string> _mp;
//   _mp["KeyA"] = "ValueA";
//   _mp["KeyB"] = "ValueB";
//   _mp["KeyC"] = "ValueC";
//   _mp["KeyD"] = "ValueD";
//
//   std::cout << _mp.size() << std::endl;
//   srand(time(NULL));
//   for (int i = 0; i < 100; i++)
//     cout << rand() % _mp.size() << endl;
//   int index = rand() % _mp.size();
//   auto item = _mp[index];
//   return;
// }

void test2() {
    std::map<int, std::map<int, std::vector<int>>> mpFeedsRecordPosition;
    mpFeedsRecordPosition =
            *(new std::map<int, std::map<int, std::vector<int>>>);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 0; j++) {
            mpFeedsRecordPosition[i][j].push_back(10 * i + j);
        }
    }
    for (auto& _pair : mpFeedsRecordPosition) {
        int X = _pair.first;
        auto& Js = _pair.second;
        for (auto& _pair2 : Js) {
            auto type = _pair2.first;
            std::vector<int>& positions = _pair2.second;
            if (positions.size() > 0) {
                std::cout << type << "," << positions[0] << std::endl;
            }
        }
    }
    return;
}

void test3() {
    std::map<int, string> x{{1, "1"}};
    std::cout << x[1] << std::endl;
    const std::map<int, string> y = x;
    std::cout << y.at(1) << std::endl;

    const std::unordered_map<int, string> z{{1, "1"}, {2, "2"}};
    std::cout << z.at(1)
              << std::endl;  // const map/unordered_map gets value by .at(key)
    // std::cout << z[1] << std::endl;  // const map/unordered_map can't get
    // value by [] operator. std::cout << y[1] << std::endl;
}

class TestClass {
public:
    int t;
    int* t2;
};
void test4() {
    std::unordered_map<int, TestClass> x;
    TestClass y = x[0];
    cout << y.t << endl;
    cout << *(y.t2) << endl;
}

void test5() {
    std::map<int, int> x{{1, 1}};
    auto iter = x.find(1);
    if (iter != x.end()) {
        cout << iter->second << endl;
    } else {
        cout << 0 << endl;
    }
}

void test6() {
    map<int, map<int, int>> x;
    x[0][0] = 1;
}

void test7() {
    map<int, int> mp;
    mp[1] = 1;
    mp[2] = 2;
    for (auto& pair1 : mp) {
        mp[100] = pair1.second;
        cout << pair1.first;
    }
    cout << endl;
}

void test8() {
    map<int, int> mp;
    mp[0]++;
    mp[1]++;
    for (auto& pair : mp) {
        cout << pair.first << ":" << pair.second << endl;
    }
}

void test9() {
    clock_t start = clock();
    for (size_t i = 0; i < 10000; ++i) {
        map<int, int> mp;
        mp[0] = 0;
        mp[1] = 1;
        mp[2] = 2;
    }
    clock_t end = clock();
    cout << end - start << endl;

    start = clock();
    map<int, int> mp;
    for (size_t i = 0; i < 10000; ++i) {
        mp.clear();
        mp[0] = 0;
        mp[1] = 1;
        mp[2] = 2;
    }

    end = clock();
    cout << end - start << endl;

    start = clock();
    map<int, int> mp2{{0, 23}, {1, 11}, {2, 22}};
    for (size_t i = 0; i < 10000; ++i) {
        mp2[0] = 0;
        mp2[1] = 1;
        mp2[2] = 2;
        mp2[0] = 0;
        mp2[1] = 0;
        mp2[2] = 0;
    }
    end = clock();
    cout << end - start << endl;
}

void test10(int& x) { x = 1; }

void test12() {
    map<int, int> x;
    x.insert(std::make_pair(1, 1));
    x.insert(std::make_pair(2, 2));
    ++x[1];
    ++x[2];
    ++x[2];
    ++x[2];
    for (auto i : x) {
        cout << i.first << ":" << i.second << ", ";
    }
    cout << endl;
}

void test13() {
    std::unordered_map<int, int> x;
    for (int i = 0; i < 10000; i++) {
        x.insert(std::make_pair(i, i));
    }
    clock_t start = clock();
    std::unordered_map<int, int> y = x;
    cout << clock() - start << endl;
    std::unordered_map<int, int> z;
    z.reserve(10000);
    start = clock_t();
    z.insert(x.begin(), x.end());
    cout << clock() - start << endl;
}

int main(int argc, char* argv[]) {
    // test12();
    test13();
    return 0;
}
