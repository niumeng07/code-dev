#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string y = "12.34";
    float x = atof(y.c_str());
    cout << x << endl;
    return 0;
}
