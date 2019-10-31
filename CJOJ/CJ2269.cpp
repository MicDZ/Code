#include<bits/stdc++.h>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;
const int MAXN=200000+10;
int _next[MAXN],to[MAXN],head[MAXN],weigh[MAXN],cnt,dept[MAXN],fa[MAXN][17],dist[MAXN];
void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	weigh[cnt]=w;
	to[cnt]=v;
}
void dfs(int x) {
	for(int i=head[x]; i; i=_next[i]) {
		int y=to[i];
		if(y==fa[x][0]) continue;
		dept[y]=dept[x]+1;
		dist[y]=dist[x]+weigh[i];
		fa[y][0]=x;
		dfs(y);
	}
}
void DEBUG() {
	REP(i,1,n) printf("%d ",dept[i]);
}
int lca(int u,int v) {
	if(dept[u]<dept[v]) swap(u,v);
	int h1=dept[u]-dept[v];
	DREP(i,log(n)/log(2),0)		
		if((1<<i)&h1) u=fa[u][i];
	if(u==v) return u;
	DREP(i,log(n)/log(2),0) 		
		if(fa[u][i]!=fa[v][i]) {
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
int main() {
	n=read(),m=read();
	REP(i,1,n-1) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	dept[1]=0;
	dfs(1);
	REP(j,1,log(n)/log(2)) REP(i,1,n) {
		fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	REP(i,1,m) {
		int u=read(),v=read();
		printf("%d\n",dist[u]+dist[v]-2*dist[lca(u,v)]);
	}
}
