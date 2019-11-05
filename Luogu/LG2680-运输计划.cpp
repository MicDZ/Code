#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
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

const int MAXN=300000+10;

int head[MAXN],to[MAXN<<1],_next[MAXN<<1],weigh[MAXN<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

queue<int> q;

int fa[MAXN][20],dept[MAXN],dist[MAXN];
int w[MAXN];
void bfs(int s) {
	q.push(s);
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(fa[u][0]==v) continue;
			w[v]=weigh[i];
			fa[v][0]=u;
			dept[v]=dept[u]+1;
			dist[v]=dist[u]+weigh[i];
			q.push(v);
		}
	}
}


int Lca(int u,int v) {
	if(dept[u]>dept[v]) swap(u,v);
	int len=dept[v]-dept[u];
	DREP(i,18,0) if(len&(1<<i)) v=fa[v][i];
	if(u==v) return u;
	DREP(i,18,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

int u[MAXN],v[MAXN],dis[MAXN],lca[MAXN];

int n,m,cf[MAXN];
int num,del;
void dfs(int u) {
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u][0]==v) continue;
		dfs(v);
		cf[u]+=cf[v];
	}
	if(cf[u]==num&&w[del]<w[u]) del=u; 
}

int max_len;
bool check(int x) {
	num=0;
	REP(i,1,n) cf[i]=0;
	REP(i,1,m) if(dis[i]>x) cf[u[i]]++,cf[v[i]]++,cf[lca[i]]-=2,num++;
	del=1;
	dfs(1);
	return max_len-w[del]<=x;
}
	
int main() {
	n=read(),m=read();int maxw=0;
	REP(i,1,n-1) {
		int u=read(),v=read(),w=read();maxw=max(maxw,w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	bfs(1);
	REP(j,1,18) REP(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];
 
	REP(i,1,m) u[i]=read(),v[i]=read(),lca[i]=Lca(u[i],v[i]),dis[i]=dist[u[i]]+dist[v[i]]-2*dist[lca[i]];
	
	int maxx=0;

	REP(i,1,m) maxx=max(maxx,dis[i]);
	max_len=maxx;
	int l=maxx-maxw,r=maxx;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}

	printf("%d\n",l);
	return 0;
}
