#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

const int MAXN=1000+10;

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int dp[MAXN][35],a[MAXN];

int main() {
	int n=read(),w=read();
	REP(i,1,n) a[i]=read();	
	REP(i,1,n) REP(j,0,w) {
		if(j==0) dp[i][j]=dp[i-1][j];
		else dp[j]=max(dp[i-1][j],dp[i-1][j-1]);
		if((j%2==1&&a[i]==2)||(j%2==0&&a[i]==1)) 
			dp[i][j]++;
	}

	int ans=0;
	REP(i,1,w) ans=max(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}
