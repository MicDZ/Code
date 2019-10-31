#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
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

const int MAXN=500000+10;

int fa[MAXN][30];

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

queue<int> q;
int dept[MAXN];
void bfs(int s) {
	q.push(s);
	dept[s]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(fa[u][0]==v) continue;
			fa[v][0]=u;
			dept[v]=dept[u]+1;
			q.push(v);
		}
	}
}

int lca(int u,int v) {
	if(dept[u]>dept[v]) swap(u,v);
	int len=dept[v]-dept[u];
	DREP(i,20,0) if((1<<i)&len) v=fa[v][i];
	if(u==v) return u;
	DREP(i,20,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

int main() {
	int n=read(),m=read(),s=read();
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	
	bfs(s);	

	REP(j,1,20) REP(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];

	REP(i,1,m) {
		int u=read(),v=read();
		printf("%d\n",lca(u,v));
	}

	return 0;
}
