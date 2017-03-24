#include <vector>
#include <iostream>
#include <string>
#include <iostream>
#include <limits>
using namespace std;
class Solution
{
public:
	int reverse(int input) 
	{
        int sign = (input > 0) ? 1 : -1;
        long tmp = input * sign;
        cout << tmp << endl;
	}
};
