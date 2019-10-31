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

const int MAXN=100000+10,MAXM=100000+10,INF=0x3f3f3f;

int f[MAXN];

int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void link(int x,int y) {
	f[find(x)]=find(y);	
}

struct edge {
	int u,v,w;
} a[MAXN];

bool cmp(edge a,edge b) {
	return a.w>b.w;
}

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],weigh[MAXN<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int fa[MAXN][21],w[MAXN][21],dept[MAXN],vis[MAXN];

queue<int> q;

void bfs(int s) {
	q.push(s);
	dept[s]=1;
	vis[s]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(vis[v]||fa[u][0]==v) continue;
			fa[v][0]=u;
			w[v][0]=weigh[i];
			dept[v]=dept[u]+1;
			q.push(v);
			vis[v]=1;
		}
	}
}

int lca(int u,int v) {
	int ans=INF;
	if(dept[u]>dept[v]) swap(u,v);
	int len=dept[v]-dept[u];
	
	DREP(i,20,0) if((1<<i)&len) ans=min(ans,w[v][i]),v=fa[v][i];

	if(u==v) return ans;
	
	DREP(i,20,0) {
		if(fa[u][i]!=fa[v][i]) ans=min(ans,min(w[u][i],w[v][i])),u=fa[u][i],v=fa[v][i];
	}

	return min(ans,min(w[u][0],w[v][0]));
}

int main() {
	int n=read(),m=read();
	REP(i,1,m) a[i].u=read(),a[i].v=read(),a[i].w=read();

	sort(a+1,a+1+m,cmp);
	
	int num=0;
	REP(i,1,n) f[i]=i;

	REP(i,1,m) {
		if(find(a[i].u)==find(a[i].v)) continue;
		link(a[i].u,a[i].v);
		addedge(a[i].u,a[i].v,a[i].w);
		addedge(a[i].v,a[i].u,a[i].w);

		DE("%d %d %d \n",a[i].u,a[i].v,a[i].w);
		num++;
		if(num==n-1) break;
	}
	int q=read();
	REP(i,1,n) if(!dept[i]) bfs(i);
	
	REP(j,1,20) REP(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];
	REP(j,1,20) REP(i,1,n) w[i][j]=min(w[i][j-1],w[fa[i][j-1]][j-1]);

	REP(i,1,q) {
		int u=read(),v=read();
		if(find(u)!=find(v)) puts("-1");
		else printf("%d\n",lca(u,v));
	}

	return 0;
}
/*
10 24
4 7 19038
7 10 7375
7 9 17853
9 8 6341
7 2 16976
10 3 2835
10 4 19285
9 4 29193
3 4 4852
3 8 16597
9 1 4138
9 7 21611
7 4 10586
10 4 7821
10 9 25636
3 9 28425
2 3 17229
4 8 11331
9 2 25053
6 4 929
8 3 1738
10 9 28542
1 2 28343
3 5 13215
9
7 5
2 4
10 2
5 10
7 10
4 3
10 1
10 4
8 4
*/
