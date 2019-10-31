#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define ll long long
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)


int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=50000+10;

int num[MAXN][35],dp[MAXN][35],ans;

int main() {
	file("4");
	int n=read(),m=read();	
	REP(i,1,m) {
		int a=read(),b=read(),c=read(),like=0,fear=0;
		REP(j,1,b) {int t=read();t=(t-a+n)%n;fear|=(1<<t);}
		REP(j,1,c) {int t=read();t=(t-a+n)%n;like|=(1<<t);}
		REP(j,0,31) if((j&fear)||(~j&like)) num[a][j]++;
	}
	REP(i,0,31) {
		memset(dp,-127,sizeof(dp));
		dp[0][i]=0;
		REP(j,1,n) REP(s,0,31) dp[j][s]=max(dp[j-1][(s&15)<<1],dp[j-1][(s&15)<<1|1])+num[j][s];
		ans=max(ans,dp[n][i]);
	}
	printf("%d\n",ans);
	return 0;
}
