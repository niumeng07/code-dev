#include <vector>

using namespace std;

class SpiralMatrixII 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int> > result(n, vector<int>(n));
		int k = 1, i = 0;
		while( k <= n * n )
		{
			int j = i;
			while( j < n - i )  result[i][j++] = k++;
			j = i + 1;
			while( j < n - i )  result[j++][n-i-1] = k++;
			j = n - i - 2;
			while( j > i )      result[n-i-1][j--] = k++;
			j = n - i - 1;
			while( j > i )      result[j--][i] = k++;
			i++;
		}
        return result;
    }
};
