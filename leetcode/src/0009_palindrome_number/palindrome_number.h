#include <iostream>
using namespace std;

class PalindromeNumber
{
public:
    bool isPalindrome(int x) 
    {
        int x_ori =x;
        if ( x < 0) return false;
        long result = 0;
        while(x!= 0)
        {
            result = result * 10 + x % 10;
            x = x/10;
        }
        if ( (long)x_ori == result ) return true;
        return false;
    }
};
