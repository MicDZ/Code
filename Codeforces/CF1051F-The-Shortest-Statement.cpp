#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
#define int ll 

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

const int MAXN=200000+10,INF=0x3f3f3f3f3f3f3f;

struct edge {
	int u,v,w;
} a[MAXN];

int f[MAXN];

int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

int link(int x,int y) {
	f[find(x)]=find(y);
}

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],weigh[MAXN<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

queue<int> q1;

int n,m,dept[MAXN],dis[MAXN],fa[MAXN][25];

void bfs(int s) {
	q1.push(s);
	while(!q1.empty()) {
		int u=q1.front();q1.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(fa[u][0]==v) continue;
			fa[v][0]=u;
			dept[v]=dept[u]+1;
			dis[v]=dis[u]+weigh[i];
			q1.push(v);
		}
	}
}

priority_queue<pair<int,int> > q;

int book[MAXN],dist[44][MAXN];

void dij(int op,int s) {
	q.push(make_pair(0,s));
	REP(i,1,n) book[i]=0;
	REP(i,1,n) dist[op][i]=INF;
	dist[op][s]=0;
	while(!q.empty()) {
		int u=q.top().second;q.pop();
		if(book[u]) continue;
		book[u]=1;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[op][v]>dist[op][u]+weigh[i]) {
				dist[op][v]=dist[op][u]+weigh[i];
				q.push(make_pair(-dist[op][v],v));
			}
		}
	}
	return ;
} 

int used[MAXN];

int lca(int u,int v) {
	if(dept[u]>dept[v]) swap(u,v);
	int len=dept[v]-dept[u];
	DREP(i,19,0) if((1<<i)&len) v=fa[v][i];
	if(u==v) return u;
	DREP(i,19,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

signed main() {
	n=read(),m=read();
	REP(i,1,m) 
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	
	REP(i,1,n) f[i]=i;
	
	int num=0;
	
	REP(i,1,m) {
		if(find(a[i].u)==find(a[i].v)) continue;
		link(a[i].u,a[i].v);
		addedge(a[i].u,a[i].v,a[i].w);
		addedge(a[i].v,a[i].u,a[i].w);
		used[i]=1;
		num++;
		if(num==n-1) break;
	}
		bfs(1);
	REP(j,1,19) REP(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];
	

	REP(i,1,m)
		if(!used[i]) addedge(a[i].u,a[i].v,a[i].w),addedge(a[i].v,a[i].u,a[i].w);
	int op=0;
	REP(i,1,m) {
		if(!used[i]) {
			dij(++op,a[i].u);
			dij(++op,a[i].v);
		}
	}
	int q=read();
	REP(i,1,q) {
		int u=read(),v=read();
		int ans=dis[u]+dis[v]-2*dis[lca(u,v)];
		REP(j,1,op) ans=min(ans,dist[j][u]+dist[j][v]);
		printf("%lld\n",ans);
	}

	return 0;
}
