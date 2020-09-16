#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string x = "   123.345    ";   
    cout << "|" << x.c_str() << "|" << endl;
    cout << atof(x.c_str()) + 1000 << endl;
    return 0;
}
