#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
    float x = 1.2345848484848875;
    float y = 1.2345848484848875;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(20) << x << "," << y;
    std::cout << ss.str() << std::endl;
    return 0;
}
