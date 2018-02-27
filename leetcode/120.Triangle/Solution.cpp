#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
    }
};

void print2DimVec(vector<vector<int> >& input){
    for(auto vec : input){
        for(auto i : vec)
            cout << i << "\t";
        cout << endl;
    }
}
class TreeNode{
public:
    int val;
    TreeNode *left = NULL, *right = NULL;
    TreeNode(int i) : val(i) {}
};
TreeNode* BuildTree(vector<vector<int> > &input){
    if(input.empty())
        return NULL;
}
int main(){
    vector<vector<int> > input({{2},{3,4},{6,5,7},{4,1,8,3}});
    print2DimVec(input);
    return 0;
}
