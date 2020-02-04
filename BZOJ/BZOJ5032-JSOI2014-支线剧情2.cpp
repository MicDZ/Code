#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
#define int ll
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1000000+10;

int head[MAXN],_next[MAXN],to[MAXN],weigh[MAXN],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int num[MAXN],f[MAXN],dp[MAXN];

void dfs(int u,int dis) {
	int sum=0;num[u]=1&(!head[u]);
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		dfs(v,dis+weigh[i]);
		num[u]+=num[v];f[u]+=f[v]+weigh[i]*num[v];
		sum+=min(f[v]+weigh[i]*num[v],dp[v]+dis+weigh[i]);
	}
	dp[u]=f[u];
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		dp[u]=min(dp[u],sum-min(f[v]+weigh[i]*num[v],dp[v]+dis+weigh[i])+dp[v]+weigh[i]);
	}
}
signed main() {
	int n=read();
	REP(u,1,n) {
		int k=read();
		REP(j,1,k) {
			int v=read(),w=read();
			addedge(u,v,w);
		}
	}
	dfs(1,0);

	printf("%lld\n",dp[1]);
	return 0;
}

