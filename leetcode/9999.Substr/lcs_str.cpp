#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAXLEN 50

void LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN]) {
    int i, j;
    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    for(j = 1; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i<= m; i++) {
        for(j = 1; j <= n; j++) {
            if(x[i-1] == y[j-1]) {                          //仅仅去掉了对b数组的使用，其它都没变
                c[i][j] = c[i-1][j-1] + 1;
            } else {
                c[i][j] = c[i-1][j] >= c[i][j-1] ? c[i-1][j] : c[i][j-1];
            }
        }
    }
}
void PrintLCS(int c[][MAXLEN], char *x, int i, int j) {
    if(i == 0 || j == 0)
        return;
    if(c[i][j] == c[i-1][j]) {
        PrintLCS(c, x, i-1, j);
    } else if(c[i][j] == c[i][j-1])
        PrintLCS(c, x, i, j-1);
    else {
        PrintLCS(c, x, i-1, j-1);
        printf("%c ",x[i-1]);
    }
}

int main() {
    char x[MAXLEN] = {"ABCBDAB"};
    char y[MAXLEN] = {"BDCABA"};
    int  c[MAXLEN][MAXLEN];     //仅仅使用一个c表
    int m = strlen(x), n = strlen(y);
    LCSLength(x, y, m, n, c);//x,y输入的string, m,n两个string的长度, c动态规划表: 该函数是构造的一个动态规划表
    for(int i = 0; i<= m; i++) {
        for(int j = 0; j <= n; j++) {
            cout << c[i][j] << ", ";
        }
        cout << endl;
    }
    PrintLCS(c, x, m, n);//该函数根据动态规划表输出结果,采用递归的方法从后向前打印，也可改写为拼接到一个引用参数里
    return 0;
}
