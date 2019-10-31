#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f3f,MAXN=500+10;

int t[MAXN],sum[MAXN],dp[MAXN][MAXN];

int main() {
    int n=read(),m=read();
    REP(i,1,n) t[i]=read();
    sort(t+1,t+1+n);
	REP(i,1,n) sum[i]=sum[i-1]+t[i];
	t[0]=-INF;

	REP(i,0,n) REP(j,0,n+m) dp[i][j]=INF;
	
	dp[0][0]=0;

	REP(i,0,n) {
		int length=min(m-1,t[i+1]-t[i]);
		REP(j,0,length) {
			if(dp[i][j]!=INF) {
				REP(k,1,n-i) {
					int now=max(t[i]+j+m-t[i+k],0);
					dp[i+k][now]=min(dp[i+k][now],dp[i][j]+(t[i+k]+now)*k-(sum[i+k]-sum[i]));
				}
			} 
		}
	}
	int ans=INF;
	REP(i,0,m-1) ans=min(ans,dp[n][i]);

	printf("%d\n",ans);
	return 0;
}

