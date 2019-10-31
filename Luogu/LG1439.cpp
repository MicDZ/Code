#include<bits/stdc++.h>
using namespace std;

#define MAXN 10000+10

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[MAXN],b[MAXN],dp[MAXN][MAXN];

int main() {
	int n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=n; i++) b[i]=read();

	for(int i=1; i<=n; i++) dp[i][0]=0,dp[0][i]=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(a[i]==b[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
		}
	cout<<dp[n][n]<<endl;
}
