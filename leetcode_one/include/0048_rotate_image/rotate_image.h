#include <vector>
#include <iostream>
using namespace std;

/*
 * 解决方法
 * 1. 以主对角线为轴交换位置
 * 2. 左右交换位置
 * */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int N = matrix.size();
      if( N <=1 ) return;
      if( matrix[0].size() != N) return;
      for(int i = 0; i < N; i++){
        for( int j = i + 1; j < N; j++){
          swap(matrix[i][j], matrix[j][i]);
        }
      }
      for(int i = 0; i < N; i++){
        int start = 0, end = N - 1;
        while(start < end){
          swap(matrix[i][start], matrix[i][end]);
          start++;
          end--;
        }
      }
    }
};
