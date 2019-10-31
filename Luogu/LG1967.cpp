//////////////////////////////////////////////
// Author: MicDZ 
// Email: micdzcn@gmail.com 
// Last modified: 2019-07-31 09:54
// Filename: LG1967.cpp
//////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10,INF=0x3f3f3f;

int head[MAXN],_next[MAXN],to[MAXN],weigh[MAXN],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

struct edge {
	int u,v,w;
}a[MAXN];

bool cmp(edge a,edge b) {
	return a.w>b.w;
}

int f[MAXN];

int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void link(int x,int y) {
	f[find(x)]=find(y);
}

int dept[MAXN],dist[MAXN],w[MAXN][22],fa[MAXN][22];
bool vis[MAXN];

void dfs(int x) {
	vis[x]=1;
	for(int i=head[x]; i; i=_next[i]) {
		int y=to[i];
		if(vis[y]) continue;
		fa[y][0]=x;
		dept[y]=dept[x]+1;
		w[y][0]=weigh[i];
		dfs(y);
	}
}

int lca(int u,int v) {
	if(find(u)!=find(v)) return -1;
	int ans=INF;
	if(dept[u]>dept[v]) swap(u,v);
	int s=dept[v]-dept[u];
	DREP(i,20,0) if(dept[fa[v][i]]>=dept[u]) {
		v=fa[v][i];
		ans=min(ans,w[v][i]);
	}
	if(u==v) return ans;
	DREP(i,20,0) 
		if(fa[u][i]!=fa[v][i]) {
			ans=min(ans,min(w[u][i],w[v][i]));
			u=fa[u][i];
			v=fa[v][i];	
		}	
	return min(ans,min(w[u][0],w[v][0]));
}

int main() {
	int n=read(),m=read();
	REP(i,1,m) {
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
	}
	REP(i,1,n) f[i]=i;
	sort(a+1,a+1+m,cmp);
	REP(i,1,m) {
		if(find(a[i].u)==find(a[i].v)) continue;
		link(a[i].u,a[i].v);
		addedge(a[i].u,a[i].v,a[i].w);
		addedge(a[i].v,a[i].u,a[i].w);
	}

	REP(i,1,n) if(!vis[i]) {
		dept[i]=1;
		dfs(i);
		fa[i][0]=i;w[i][0]=INF;
	}

	REP(j,1,20) REP(i,1,n) {
		fa[i][j]=fa[fa[i][j-1]][j-1];
		w[i][j]=min(w[i][j-1],w[fa[i][j-1]][j-1]);
	}
	int q=read();
	REP(i,1,q) {
		int u=read(),v=read();
		printf("%d\n",lca(u,v));
	}
	return 0;
}

