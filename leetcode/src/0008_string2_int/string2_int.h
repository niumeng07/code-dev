#include <vector>
#include <iostream>
#include <string>
#include <iostream>
#include <limits>
using namespace std;
class String2Int
{
public:
	int myAtoi(string str) 
	{
		long result = 0;
		int sign = 1;
	    int i = str.find_first_not_of(' ');
		for(; i<str.size();)
		{
			if(str[i] == '-' || str[i] == '+')
				sign = (str[i++] == '-')? -1 : 1;
			while('0'<= str[i] && str[i] <= '9') 
			{
				result = result*10 + (str[i++]-'0');
				if(result*sign >= numeric_limits<int>::max()) return numeric_limits<int>::max();
				if(result*sign <= numeric_limits<int>::min()) return numeric_limits<int>::min();                
			}
			return result*sign;
		}
        return result;
	}
};
