#include<bits/stdc++.h>
#define MAXN 1000+10
using namespace std;
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[MAXN],dp[MAXN][MAXN];
int main() {
    int n=read(),sum=0;
    for(int i=1; i<=n; i++) {
        a[i]=read();
        dp[i][i]=a[i];
        a[i]=a[i-1]+a[i];
        
    }
    for(int l=1; l<n; l++) 
        for(int i=1; i+l<=n; i++)
            dp[i][i+l]=a[i+l]-a[i-1]-min(dp[i+1][i+l],dp[i][i+l-1]);
    cout<<dp[1][n]<<" "<<a[n]-dp[1][n]<<endl;
}
