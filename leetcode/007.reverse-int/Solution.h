#include <limits>
using namespace std;
class Solution
{
public:
	int reverse(int input) 
	{
        long result = 0;
        while(input != 0)
        {
            result = result * 10 + input % 10;
            if ( result > numeric_limits<int>::max() || result <numeric_limits<int>::min() )
                return 0;
            input = input /10;
        }
        return result;
	}
};
