#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (1 && 1 && 1) std::cout << 1 << std::endl;
    bool test = std::stoi("2");
    if (test) {
        cout << "2 to true" << std::endl;
    }
    return 0;
}
