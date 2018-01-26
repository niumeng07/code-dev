#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
void print_vector(vector<T> vec)
{
    for( int i = 0; i < vec.size(); i++)
        cout << vec[i] << "\t";
    cout << endl;
}
/* 思路：
 * 每行至多一个皇后，每列至多一个皇后
 * 则可以用n个整数来表示每行中皇后的位置
 * 判断这个n个数是否符合NQueens的要求
 *     判断方法:
 *         对任意第i行和第j行[i,j], 以及对应的皇后位置a[i],a[j]
 *         a[i]!=a[j]且abs(a[i]-a[j])!=abs(i-j)则符合
 * 若：符合，string化到输出
 *     不符合，std::next_permutation(t.begin(), t.end())
 * */
bool is_nqueens(vector<int> t)
{
    for(int i = 0; i < t.size(); i++)
    {
        for(int j = i + 1; j < t.size(); j++)
        {
            if(abs(i - j) == abs(t[i] - t[j] ))
                return false;
        }
    }
    return true;
}
vector<vector<string> > NQueens(int n)
{
    vector<int> tmp;
    for(int i = 0; i < n; i++)
    {
        tmp.push_back(i);
    }
    vector<vector<string > > result;
    do{
        if(is_nqueens(tmp))
        {
            vector<string > v;
            for(int i = 0; i < n; i++)
            {
                string x(n, '.');
                x[tmp[i]] = 'Q';
                v.push_back(x);
            }
            result.push_back(std::move(v));
        }
    }while(std::next_permutation(tmp.begin(), tmp.end()));
    return result;
}
int main()
{
    vector<vector<string> > res = NQueens(8);
    for(auto vec : res)
        print_vector(vec);
    res = NQueens(4); 
    cout << "4: " << res.size() << endl;
    res = NQueens(5);
    cout << "5: " << res.size() << endl;
    res = NQueens(6);
    cout << "6: " << res.size() << endl;
    res = NQueens(7);
    cout << "7: " << res.size() << endl;
    res = NQueens(8);
    cout << "8: " << res.size() << endl;
    res = NQueens(9);
    cout << "9: " << res.size() << endl;
    res = NQueens(10);
    cout << "10: " << res.size() << endl;
    return 0;
}
