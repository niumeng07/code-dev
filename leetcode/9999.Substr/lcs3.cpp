#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 最长公共子序列
 * */

//#define METRIC_SIZE 100

void print_metric(vector<vector<int> > &input) {
    for(auto vec : input) {
        for(auto i : vec)
            cout << i << ", ";
        cout << endl;
    }
}
// 构造动态规划表
void build_metrics(string &left, string &right, 
        vector<vector<int> > &metrics) {
    for(int i = 0; i <= left.size(); i++)
        metrics[i][0] = 0;
    for(int j = 0; j <= right.size(); j++) 
        metrics[0][j] = 0;
    for(int i = 1; i <= left.size(); i++) {
        for(int j = 1; j <= right.size(); j++) {
            if(left[i - 1] == right[j - 1])
                metrics[i][j] = metrics[i - 1][j - 1] + 1;
            else
                metrics[i][j] = metrics[i - 1][j] > metrics[i][j - 1] ? metrics[i - 1][j] : metrics[i][j - 1];
        }
    }
}

// 根据动态规划表求得一个最长序列(若要求输出所有最长序列呢？)
void build_comstring(string &left, string &right,
        vector<vector<int> > &metrics, 
        int left_index, int right_index, 
        string &lcs) {
    if(left_index == 0 || right_index == 0)
        return;

    if(metrics[left_index][right_index] == metrics[left_index-1][right_index])
        build_comstring(left, right, metrics, left_index - 1, right_index, lcs);
    else if(metrics[left_index][right_index] == metrics[left_index][right_index-1])
        build_comstring(left, right, metrics, left_index, right_index - 1, lcs);
    else {
        lcs = left[left_index - 1] + lcs;
        build_comstring(left, right, metrics, left_index - 1, right_index - 1, lcs);
    }
}
// 根据动态规划表求得所有最长序列呢
void build_all_comstring(string &left, string &right, 
    vector<vector<int> > &metrics, 
    int left_index, int right_index,
    vector<string> &lcss) {

}

int main(){
    string left = "abcdef";
    string right = "gacfk";
    vector<int> column(right.size() + 1, 0);
    vector<vector<int> > metrics(left.size() + 1, column);
    build_metrics(left, right, metrics);
    print_metric(metrics);
    string result = "";
    build_comstring(left, right, metrics, left.size(), right.size(), result);
    cout << "result: " << result << endl;
}
