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

const int MAXN=65534+10,MAXM=MAXN*100;

struct graph {
	int head[MAXN],_next[MAXM],to[MAXM],cnt;
	graph() {memset(head,0,sizeof(head));cnt=0;}
	void addedge(int u,int v) {cnt++;_next[cnt]=head[u];head[u]=cnt;to[cnt]=v;}
} g,t;

int n;

//Begin DT

int in[MAXN],dept[MAXN],f[MAXN][20],fa[MAXN],sz[MAXN];

int lca(int u,int v) {
	if(dept[u]>dept[v]) swap(u,v);
	int len=dept[v]-dept[u];
	DREP(i,19,0) if(len&(1<<i)) v=f[v][i];
	if(u==v) return u;
	DREP(i,19,0) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}

queue<int> q;

void build() {
	memset(fa,-1,sizeof(fa));
	REP(i,1,n) if(!in[i]) q.push(i),fa[i]=0;	
	while(!q.empty()) {
		int u=q.front();t.addedge(fa[u],u);dept[u]=dept[fa[u]]+1;
		f[u][0]=fa[u];
		REP(i,1,19) f[u][i]=f[f[u][i-1]][i-1];
		q.pop();
		for(int i=g.head[u]; i; i=g._next[i]) {
			int v=g.to[i];
				if(fa[v]==-1) fa[v]=u;
				else fa[v]=lca(fa[v],u);
				if(!--in[v]) q.push(v);
		}
	}
}

void dfs(int u) {
	sz[u]=1;
	for(int i=t.head[u]; i; i=t._next[i]) dfs(t.to[i]),sz[u]+=sz[t.to[i]];
}

//End DT

int main() {
	n=read();
	REP(i,1,n) {
		int x=read();
		while(x) in[i]++,g.addedge(x,i),x=read();
	}
	build();dfs(0);	
	REP(i,1,n) printf("%d\n",sz[i]-1);
	return 0;
}

