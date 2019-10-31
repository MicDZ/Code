#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

const int MAXN=10000000+10;

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int _next[MAXN],from[MAXN],head[MAXN],to[MAXN],weigh[MAXN],cnt,dp[MAXN];

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
	from[cnt]=v;
}

int dis[MAXN];

bool book[MAXN];
int main() {
	int n=read(),m=read(),r=read();
	REP(i,1,m) {
		int u=read(),v=read(),e=read();
		addedge(v,u,e);
	}
	
	//memset(dp,0,sizeof(dp));
	REP(j,1,n) {
		dp[j]=dp[j-1];
		for(int i=head[j]; i; i=_next[i]) dp[j]=max(dp[j],dp[max(0,from[i]-r)]+weigh[i]);
	}

	//REP(i,1,n) cout<<dp[i]<<" ";
	//puts("");
	printf("%d\n",dp[n]);
}
