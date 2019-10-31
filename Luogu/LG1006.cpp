#include<bits/stdc++.h>
using namespace std;

#define MAXN 50+5

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int dp[MAXN][MAXN][MAXN][MAXN],a[MAXN][MAXN];

int main() {
    int n=read(),m=read();
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            a[i][j]=read();

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            for(int k=1; k<=n; k++)
                for(int l=j+1; l<=m; l++) {
                    dp[i][j][k][l]=max(dp[i-1][j][k-1][l],max(dp[i][j-1][k-1][l],max(dp[i][j-1][k][l-1],dp[i-1][j][k][l-1])))+a[i][j]+a[k][l];

                    //if(i==k&&j==l) dp[i][j][k][l]-=a[i][j];
    }

    printf("%d",dp[n][m-1][n-1][m]);
}
