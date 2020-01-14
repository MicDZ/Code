#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

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

const int MAXN=5e5+10,INF=0x3f3f3f3f;

int head[MAXN],_next[MAXN],to[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int f[MAXN];

int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void link(int x,int y) {
	f[find(x)]=find(y);
}

int fa[MAXN][30];

queue<int> q;

int book[MAXN],dist[MAXN];

int dfs(int u) {
	book[u]=1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(dist[v]<dist[u]) 
		dist[v]=dist[u]+1;
	}
}

int lca(int u,int v) {
	if(dist[u]>dist[v]) swap(u,v);
	int len=dist[v]-dist[u];
	DREP(i,20,0) if((i<<i)&len) v=fa[v][i];
	if(u==v) return u;
	DREP(i,20,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

int main() {
	int n=read(),q=read();
	
	REP(i,1,n) f[i]=i,dist[i]=INF;
	
	REP(u,1,n) {
		int v=read();
		addedge(u,v);
		link(u,v);
	}

	REP(i,1,n) if(!book[i]) dfs(i);	
	
	REP(j,1,20) REP(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];

	REP(i,1,q) {
		int u=read(),v=read();
		if(find(u)!=find(v)) puts("-1 -1");
		
	}

	return 0;
}

