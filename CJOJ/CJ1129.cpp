#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

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
const int MAXN=80000+10;
int _next[MAXN],to[MAXN],head[MAXN],weigh[MAXN],cnt,dept[MAXN],fa[MAXN][25],dist[MAXN];
void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	weigh[cnt]=w;
	to[cnt]=v;
}
void dfs(int u,int f) {
	fa[u][0]=f;
	for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(v==f) continue;
			dist[v]=weigh[i]+dist[u];
			dept[v]=dept[u]+1;
			//fa[v][0]=u;
			dfs(v,u);
		}
}

int lca(int u,int v) {
	if(dept[u]<dept[v]) swap(u,v);
	int h1=dept[u]-dept[v];
	DREP(i,20,0)	
		if((1<<i)&h1) u=fa[u][i];
	if(u==v) return u;
	DREP(i,20,0) 	
		if(fa[u][i]!=fa[v][i]) {
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}


void DEBUG() {
	REP(i,1,n) printf("%d ",dist[i]);
}


int main() {
//	freopen("1.out","w",stdout);
	n=read(),m=read();
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	//memset(dist,1,sizeof(dist));
	//memset(dept,1,sizeof(dept));
	dept[1]=1;
	dfs(1,0);
	REP(j,1,21) REP(i,1,n) {
		fa[i][j]=fa[fa[i][j-1]][j-1];
	}
//	DEBUG();
	int q=read();

	REP(i,1,q) {
		int u=read(),v=read();
	//	printf("%d %d %d\n",dist[u],dist[v],lca(u,v));
		printf("%d\n",dist[u]+dist[v]-2*dist[lca(u,v)]);
	}
}

