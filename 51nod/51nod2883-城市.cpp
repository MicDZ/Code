#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

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

const int MAXN=1e6+10,MAXM=4e5+10,INF=0x3f3f3f3f;

int n,m;

struct graph {
	int head[MAXN],_next[MAXM<<1],to[MAXM<<1],weigh[MAXM<<1],cnt;
	graph() {cnt=0;memset(head,0,sizeof(head));}
	void addedge(int u,int v,int w=0) {
		cnt++;
		_next[cnt]=head[u];
		head[u]=cnt;
		to[cnt]=v;
		weigh[cnt]=w;
	}
} o,g,t;


int id[MAXN];

int dist[MAXN],inq[MAXN];

queue<int> q;

void SPFA(int s,int *dist) {
	q.push(s);inq[s]=1;
	REP(i,1,n) dist[i]=INF;
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
int tot,in[MAXN],sz[MAXN],fa[MAXN],f[MAXN][20],sum[MAXM],ans[MAXN];

void dfs(int u) {
	sz[u]=(u<=n);
	for(int i=t.head[u]; i; i=t._next[i]) dfs(t.to[i]),sz[u]+=sz[t.to[i]]; 
	sum[id[u]]=sz[u];
}

int dept[MAXN];

int lca(int u,int v) {
	if(dept[u]<dept[v]) swap(u,v);
	int len=dept[u]-dept[v];
	DREP(i,19,0) if(len&(1<<i)) u=f[u][i];
	if(u==v) return u;
	DREP(i,19,0) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}

void build() {
	memset(fa,-1,sizeof(fa));
	REP(i,1,tot) if(!in[i]) q.push(i),fa[i]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		t.addedge(fa[u],u);
		dept[u]=dept[fa[u]]+1;
		f[u][0]=fa[u];
		REP(i,1,16) f[u][i]=f[f[u][i-1]][i-1];
		for(int i=g.head[u]; i; i=g._next[i]) {
			int v=g.to[i];
			if(fa[v]==-1) fa[v]=u;
			else fa[v]=lca(fa[v],u);
			if(!--in[v]) q.push(v);
		}
	}
}
//End DT


struct edge {
	int u,v,w;
} e[MAXM];


int main() {
	n=read(),m=read();
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		o.addedge(u,v,w);o.addedge(v,u,w);
		e[i]=(edge){u,v,w};
	}
	int s=read();
	tot=n;
	SPFA(s,dist);
	REP(i,1,m) {
		if(dist[e[i].v]+e[i].w==dist[e[i].u]) {
			id[++tot]=i;
			g.addedge(e[i].v,tot);in[tot]++;
			g.addedge(tot,e[i].u);in[e[i].u]++;
		}
		if(dist[e[i].u]+e[i].w==dist[e[i].v]) {
			id[++tot]=i;
			g.addedge(e[i].u,tot);in[tot]++;
			g.addedge(tot,e[i].v);in[e[i].v]++;
		}
	}
	build();dfs(s);
	
	REP(i,1,m) ans[e[i].u]+=sum[i],ans[e[i].v]+=sum[i];

	REP(i,1,n) printf("%d\n",ans[i]);
	return 0;
}

