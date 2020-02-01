#include <vector>
#include <iostream>
using namespace std;
class PlusOne
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int addOne = 1;
        for(int i = digits.size() -1; i>=0; i--)
        {
            int tmp = digits[i];
            digits[i] = ( tmp + addOne ) % 10;
            addOne = ( tmp + addOne ) / 10;
        }
        if ( addOne == 1 )
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
