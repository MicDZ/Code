#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=2000000+10,INF=0x3f3f3f3f;

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],weigh[MAXN<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int fa[MAXN],f[MAXN],ans[MAXN];

int in[MAXN],vis[MAXN];

void dp(int u) {
	f[u]=0;vis[u]=1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(vis[v]) continue;
		dp(v);
		if(in[v]==1) f[u]+=weigh[i];
		else f[u]+=min(f[v],weigh[i]);
	}
}

void dfs(int u) {
	vis[u]=1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(vis[v]) continue;
		if(in[u]==1) ans[v]=f[v]+weigh[i];
		else ans[v]=f[v]+min(ans[u]-min(f[v],weigh[i]),weigh[i]);
		dfs(v);
	}
}

int main() {
	int t=read();
	while(t--) {
		int n=read();
		cnt=0;REP(i,0,2000000) head[i]=vis[i]=in[i]=ans[i]=fa[i]=0,f[i]=INF;
		REP(i,1,n-1) {
			int u=read(),v=read(),w=read();
			addedge(u,v,w);
			addedge(v,u,w);
			in[u]++,in[v]++;
		}
		int rt=2;
		dp(rt);
		ans[rt]=f[rt];memset(vis,0,sizeof(vis));
		dfs(rt);
		int maxx=0;
		REP(i,1,n) maxx=max(maxx,ans[i]);

		printf("%d\n",maxx);
	}
	return 0;
}
/*
1
5
1 2 11
1 4 13
3 4 5
4 5 10
*/
