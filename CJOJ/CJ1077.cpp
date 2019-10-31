#include<bits/stdc++.h>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=400+10;

int a[MAXN],sum[MAXN],dp[MAXN][MAXN][2];

int main() {
	//file("book");
	int n=read();

	/*REP(i,1,n) {
		int w=read(),v=read();		
		a[i]=w-v;
	}*/
	REP(i,1,n) a[i]=read();

	REP(i,1,n) sum[i]=sum[i-1]+a[i];
	
	memset(dp,1,sizeof(dp));

	REP(i,1,n) 
		dp[i][i][0]=dp[i][i][1]=0;
	REP(i,1,n) REP(j,1,n) dp[i][j][1]=0;

	REP(len,2,n) REP(l,1,n) {
		int r=l+len-1;
		
		REP(k,l,r-1) {
			dp[l][r][1]=max(dp[l][r][1],dp[l][k][1]+dp[k+1][r][1]);
			dp[l][r][0]=min(dp[l][r][0],dp[l][k][0]+dp[k+1][r][0]);
			//printf("l=%d r=%d k=%d d=%d\n",l,r,k,dp[l][r]);
		}
		dp[l][r][0]+=sum[r]-sum[l-1];	
		dp[l][r][1]+=sum[r]-sum[l-1];
	}

	printf("%d\n%d\n",dp[1][n][0],dp[1][n][1]);
}

