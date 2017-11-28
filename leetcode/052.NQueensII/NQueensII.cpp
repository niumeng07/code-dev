#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

bool is_nqueens(vector<int> t)
{
    for(int i = 0; i < t.size(); i++)
    {
        for(int j = i + 1; j < t.size(); j++)
            if( abs(i-j) == abs(t[i] - t[j]))
                return false;
    }
    return true;
}
int NQueensII(int n)
{
    vector<vector<string> > result;
    vector<int> t;
    for(int i = 0; i < n; i++)
        t.push_back(i);
    do{
        if(is_nqueens(t))
        {
            vector<string> tmp;
            for(int i = 0; i<n;i++)
            {
                string x(n,'.');
                x[i] = 'Q';
                tmp.push_back(x);
            }
            result.push_back(tmp);
        }
    }while(std::next_permutation(t.begin(), t.end()));
    //result.erase(std::unique(result.begin(), result.end()), result.end());
    return result.size();
}
void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool>& main, vector<bool> &anti, int &count) {
        if (i == row.size()) {
            count++;
            return;
        }
       for (int j = 0; j < col.size(); j++) {
         if (col[j] && main[i+j] && anti[i+col.size()-1-j]) {
             row[i] = j;
             col[j] = main[i+j] = anti[i+col.size()-1-j] = false;
             dfs(i+1, row, col, main, anti, count);
             col[j] = main[i+j] = anti[i+col.size()-1-j] = true;
      }
    }
}
int totalNQueens(int n) {
    vector<bool> col(n, true);
    vector<bool> anti(2*n-1, true);
    vector<bool> main(2*n-1, true);
    vector<int> row(n, 0);
    int count = 0;
    dfs(0, row, col, main, anti, count);
    return count;
}

int main()
{
    clock_t start, end;
    start = clock();
    cout << NQueensII(10) << endl;
    end = clock();
    cout << "meth 1 uses time " << (end - start)/1000.0 << " ms" << endl;
    start = clock();
    cout << totalNQueens(10) << endl;
    end = clock();
    cout << "meth 1 uses time " << (end - start )/1000.0<< " ms" << endl;
    return 0;
}
