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

const int MAXN=2e5+10,MAXM=6e5;

struct graph {
	int head[MAXN],_next[MAXM],to[MAXM],weigh[MAXM],cnt;
	graph() {memset(head,0,sizeof(head));cnt=0;}
	void addedge(int u,int v,int w=0) {cnt++;_next[cnt]=head[u];head[u]=cnt;to[cnt]=v;weigh[cnt]=w;}
} o,g,t;

int n;

queue<int> q;

int dist[MAXN],inq[MAXN];

void SPFA(int s) {
	q.push(s);inq[s]=1;
	memset(dist,127,sizeof(dist));
	dist[s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();inq[u]=0;
		for(int i=o.head[u]; i; i=o._next[i]) {
			int v=o.to[i];
			if(dist[v]>dist[u]+o.weigh[i]) {
				dist[v]=dist[u]+o.weigh[i];
				if(!inq[v]) {
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}

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
	sz[u]=(dist[u]!=dist[0]);
	for(int i=t.head[u]; i; i=t._next[i]) dfs(t.to[i]),sz[u]+=sz[t.to[i]];
}

//End DT

struct edge{
	int u,v,w;
} e[MAXM];

int main() {
	n=read();int m=read(),s=read();
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		o.addedge(u,v,w);
		o.addedge(v,u,w);
		e[i]=(edge){u,v,w};
	}
	SPFA(s);
	REP(i,1,m) {
		if(dist[e[i].u]+e[i].w==dist[e[i].v]) 
			g.addedge(e[i].u,e[i].v),in[e[i].v]++;
		if(dist[e[i].v]+e[i].w==dist[e[i].u]) 
			g.addedge(e[i].v,e[i].u),in[e[i].u]++;
	}
	build();dfs(0);	
	int ans=0;
	REP(i,1,n) if(i!=s) ans=max(ans,sz[i]);

	printf("%d\n",ans);
	return 0;
}


