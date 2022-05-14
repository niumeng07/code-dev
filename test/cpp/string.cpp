#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void test1() {
    string line = "12345";
    cout << line.size() << "\t" << line.capacity() << endl;
    line.reserve(200);
    cout << line.size() << "\t" << line.capacity() << endl;
    size_t offset = line.find((char)2);
    cout << line << endl;
    cout << offset << endl;  // 18446744073709551615
    char xx = (char)2;
    cout << xx << endl;

    std::cout << "----------" << std::endl;
    std::ostringstream ss;
    vector<int> x{1, 0, 0};
    for (int i = 0; i < x.size(); i++) {
        ss << i + 1 << ":10000:" << x[i] << ";";
    }
    std::cout << line + ";" + ss.str() << endl;
}

void test2() {
    string x = "abc";
    cout << x.substr(1, x.size() -1) << endl;
    x = "";
    cout << x.empty() << endl;
}

void test3(string& x) {
    cout << x << endl;
}

void test3() {
    string x = "abc";
    cout << x.substr(1, 2) << endl;
    cout << x << endl;
}

int main() {
    // test1();
    // test2();
    test3();
    return 0;
}
