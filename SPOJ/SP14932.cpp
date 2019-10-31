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
const int MAXN=80000+10;
int _next[MAXN],to[MAXN],head[MAXN],weigh[MAXN],cnt,dept[MAXN],fa[MAXN][25],dist[MAXN];

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

void dfs(int x) {
	for(int i=head[x]; i; i=_next[i]) {
		int y=to[i];
		if(y==fa[x][0]) continue;
		dept[y]=dept[x]+1;
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

int main() {
	int T=read();
	REP(t,1,T) {
		n=read();
		cnt=0;
		memset(head,0,sizeof(head));

		REP(i,1,n) {
			int tot=read();
			REP(j,1,tot) {
				int v=read();
				addedge(i,v);
				addedge(v,i);
			}
		}	
		memset(dept,0,sizeof(dept));
		memset(dist,0,sizeof(dist));
		memset(fa,0,sizeof(fa));

		dfs(1);
		
		REP(i,1,n) REP(j,1,21) {
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
		
		int m=read();
		printf("Case %d:\n",t);
		REP(i,1,m) {
			int u=read(),v=read();
			printf("%d\n",lca(u,v));
		}
	}
}

