#include <iostream>
#include <stdint.h>
#include <limits>
using namespace std;

int reverse_int(int x){
    long result = 0;
    while(x!=0)
    {
        result = result*10 + x%10;
        if(result > numeric_limits<int>::max() || result < numeric_limits<int>::min())
            return 0;
        x = x/10;
    }
    return result;
}
int main()
{
    cout << reverse_int(1234509999) << endl;
}
