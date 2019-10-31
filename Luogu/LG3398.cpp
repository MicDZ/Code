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

const int MAXN=200000+10;

int n,m,a[MAXN],head[MAXN],_next[MAXN],to[MAXN],cnt,fa[MAXN][20],dept[MAXN],ans[MAXN];

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

void dfs(int x) {
	for(int i=head[x]; i; i=_next[i]) {
		int y=to[i];
		if(fa[x][0]==y) continue;
		fa[y][0]=x;
		dept[y]=dept[x]+1;
		dfs(y);
		
	}
}

int lca(int u,int v) {
	if(dept[u]<dept[v]) swap(u,v);
	int h1=dept[u]-dept[v];
	DREP(i,17,0)
		if((1<<i)&h1) u=fa[u][i];
	if(u==v) return u;


	DREP(i,18,0) 	
		if(fa[u][i]!=fa[v][i]) {
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}

int dist(int a,int b) {
	return dept[a]+dept[b]-2*dept[lca(a,b)];
}


int main() {
	int n=read(),q=read();
	int _root=1;
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	dept[_root]=1;
	dfs(_root);

	REP(j,1,17) REP(i,1,n)
		fa[i][j]=fa[fa[i][j-1]][j-1];	
	REP(i,1,q) {
		int a=read(),b=read(),c=read(),d=read(),x=lca(a,b),y=lca(c,d);
		if(dist(a,y)+dist(y,b)==dist(a,b)||dist(c,x)+dist(x,d)==dist(c,d)) puts("Y");
		else puts("N");
	}

	return 0;
}
/*
6 2 
1 3 
2 1 
1 0 
2 1 
2 1 
1 5
*/

