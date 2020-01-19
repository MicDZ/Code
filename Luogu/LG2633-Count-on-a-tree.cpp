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

const int MAXN=200000+10,MAXM=MAXN*18;

int rt[MAXM],a[MAXN],b[MAXN];

struct President_Tree {
	int cnt,ls[MAXM],rs[MAXM],sum[MAXM];
	President_Tree() {
		cnt=0;
		memset(ls,0,sizeof(ls));
		memset(rs,0,sizeof(rs));
		memset(sum,0,sizeof(sum));
	}
	void build(int &p,int l,int r) {
		p=++cnt;
		if(l==r) return ;
		int mid=(l+r)>>1;
		build(ls[p],l,mid);
		build(rs[p],mid+1,r);
	}
	void change(int &p,int l,int r,int u,int x) {
		p=++cnt,ls[p]=ls[u],rs[p]=rs[u],sum[p]=sum[u]+1;	
		
		if(l==r) return ;
		int mid=(l+r)>>1;
		if(x<=mid) change(ls[p],l,mid,ls[u],x);
		else change(rs[p],mid+1,r,rs[u],x);
	}
	int ask(int x,int y,int l,int r,int lc,int falc,int k) {
		if(x==y) return x;
		int mid=(x+y)>>1;
		int v=sum[ls[l]]+sum[ls[r]]-sum[ls[lc]]-sum[ls[falc]];
		if(v>=k) return ask(x,mid,ls[l],ls[r],ls[lc],ls[falc],k);
		else return ask(mid+1,y,rs[l],rs[r],rs[lc],rs[falc],k-v);
	}
} s;


int head[MAXN],_next[MAXM],to[MAXM],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int fa[MAXN][25],dist[MAXN];

queue<int> q;

int sz;

void bfs(int s) {
	q.push(s);
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(fa[u][0]==v) continue;
			fa[v][0]=u;
			dist[v]=dist[u]+1;
			q.push(v);
		}
	}
}

void dfs(int u) {
	s.change(rt[u],1,sz,rt[fa[u][0]],a[u]);
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u][0]==v) continue;
		dfs(v);
	}
}

int lca(int u,int v) {
	if(dist[u]<dist[v]) swap(u,v);
	int len=dist[u]-dist[v];
	DREP(i,19,0) if(1<<i&len) u=fa[u][i];
	if(u==v) return u;
	DREP(i,19,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

int last=0;

int main() {
	int n=read(),m=read();
	REP(i,1,n) a[i]=b[i]=read();
	sort(b+1,b+1+n);
	sz=unique(b+1,b+1+n)-b-1;
	s.build(rt[0],1,sz);
	REP(i,1,n) a[i]=lower_bound(b+1,b+1+sz,a[i])-b;	
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	
	bfs(1);
	REP(j,1,19) REP(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];
	
	dfs(1);	
	REP(i,1,m) {
		int u=read()^last,v=read(),k=read(),_lca=lca(u,v);
		last=b[s.ask(1,sz,rt[u],rt[v],rt[_lca],rt[fa[_lca][0]],k)];
	
		printf("%d\n",last);
	}
	return 0;
}


