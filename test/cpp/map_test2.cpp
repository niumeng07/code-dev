#include <iostream>
#include <map>
using namespace std;

void test1() {
    map<int, int> m;
    map<int, int>::iterator it = m.find(1);
    for (auto pair1 : m) {
        cout << pair1.first << ":" << pair1.second << endl;
    }
}

int main(int argc, char *argv[]) {
    test1();
    return 0;
}
