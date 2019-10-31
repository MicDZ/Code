#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=80+10;
int a[MAXN][MAXN],dp[MAXN][MAXN],ans[MAXN][MAXN];

int main() {
	int n=read();
	REP(i,1,n) REP(j,1,i) a[i][j]=read();

	REP(i,1,n) dp[n][i]=a[n][i];
	
	DREP(i,n-1,1) REP(j,1,i) {
		if(dp[i+1][j]<dp[i+1][j+1]) dp[i][j]=dp[i+1][j+1]+a[i][j],ans[i][j]=j+1;
		else dp[i][j]=dp[i+1][j]+a[i][j],ans[i][j]=j;
	}

	printf("%d\n",dp[1][1]);

	int x=1,y=1;
	while(x<=n) {
		printf("%d ",a[x][y]);
		y=ans[x][y];
		x++;
	}
	puts("");
	return 0;
}


