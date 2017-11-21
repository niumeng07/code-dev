#include <string>
using namespace std;
class Solution
{
public:
    /*
     * 下面是循环解法，缺点是会不断循环，耗时极大
     * */
    bool isInterleave(string s1, string s2, string s3)
    {
        if( s1.size() + s2.size() != s3.size()) return false;
        if( s1.size() == 0 ) return s2==s3;
        if( s2.size() == 0 ) return s1==s3;
        if( char(s1[0]) == char(s3[0]) && char(s2[0]) != char(s3[0]) ) 
            return isInterleave(s1.substr(1, s1.size() - 1), s2, s3.substr(1, s3.size() - 1));
        if( char(s2[0]) == char(s3[0]) && char(s1[0]) != char(s3[0])) 
            return isInterleave(s1, s2.substr(1, s2.size() - 1), s3.substr(1, s3.size() - 1));
        if( char(s2[0]) == char(s3[0]) && char(s1[0]) == char(s3[0]))
            return isInterleave(s1.substr(1, s1.size() - 1), s2, s3.substr(1, s3.size() - 1)) || isInterleave(s1, s2.substr(1, s2.size() - 1), s3.substr(1, s3.size() - 1));
        return false;
    }
    /*
     * 动态规划算法，把前面的结果保存起来，后面接着用
     * 解释：用s1的前i个字符和s2的前j个字符组成s3的前i+j个字符
     *  在s1的前i-1个字符和s2的前j个字符能组成s3的i+j-1个字符的基础上选取s1的第i个
     *  或s1的前i个字符和s2的前j-1个字符能组成d3的i+j-1个字符的基础上选取s2的第j个
     * 迭代公式: f(i,j) = ({ f(i-1,j)==true } && s1[i-1]== s3[i+j-1]) || ({ f(i, j-1)==true } && s2[j-1] == s3[i+j-1] )
     * 边界条件，i==0或j==0
     * 初始条件若i==0,且j==0,则f(i,j)=true (s1的前0个字符和s2的前0个字符能组成s3的前0个字符） 
     * */
	bool isInterleaveDP(string s1, string s2, string s3) 
    {
		if(s3.length() != s1.length() + s2.length())
			return false;
        if(s1.empty()) return s2 == s3;
        if(s2.empty()) return s1 == s3;
		
		bool table[s1.length()+1][s2.length()+1];
		for(int i=0; i<s1.length()+1; i++)
        {
			for(int j=0; j< s2.length()+1; j++)
            {
				if(i==0 && j==0)
					table[i][j] = true;
				else if(i == 0)
					table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
				else if(j == 0)
					table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
				else
					table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
			}
        }	
		return table[s1.length()][s2.length()];
	}
};

