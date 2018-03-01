#include<cstring>
#include<cmath>
#include<cstring>
#include<cstdio>
const int qq=1e3+10;
char x[qq],y[qq];
int dp[qq][qq];
int main()
{
    while(~scanf("%s%s",x+1,y+1)){
        x[0]=y[0]='.';
        int len=strlen(x)>strlen(y)?strlen(x):strlen(y);
    //    printf("%d %d\n",strlen(x),strlen(y));
        for(int i=0;i<=len;++i)
            dp[i][0]=dp[0][i]=0;
        for(int j,i=1;i<strlen(x);++i)
            for(j=1;j<strlen(y);++j)
                if(x[i]==y[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
        printf("%d\n",dp[strlen(x)-1][strlen(y)-1]);
    }
    return 0;
}
