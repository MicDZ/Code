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

const int MAXN=800000+10;

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int g[MAXN],in[MAXN];

queue<int> q;

int dept[MAXN],fa[MAXN][20];

int id[MAXN];

void dfs(int u,int _id) {
	dept[u]=dept[fa[u][0]]+1;id[u]=_id;
	REP(i,1,18) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		fa[v][0]=u;
		dfs(v,_id);
	}
}

int lca(int u,int v) {
	if(dept[u]>dept[v]) swap(u,v);
	int len=dept[v]-dept[u];
	DREP(i,18,0) if(len&(1<<i)) v=fa[v][i];
	if(u==v) return u;
	DREP(i,18,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

struct edge {
	int lca_dep,id,u,v;
} fy[MAXN];

bool operator < (edge a,edge b) {
	if(a.lca_dep==b.lca_dep) return a.id<b.id;
	return a.lca_dep>b.lca_dep;
}

int f[MAXN];

int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void link(int x,int y) {
	f[find(x)]=f[y];
}

int main() {
	int n=read(),m=read(),k=read();
	
	REP(i,1,n) g[i]=read();
	REP(i,1,n) f[i]=i;	
	REP(i,1,m) {
		int u=read(),v=read();
		addedge(i+n,f[u]);
		addedge(i+n,f[v]);		
		f[v]=i+n; f[u]=i+n;
	}
	int tot=0;
	DREP(i,n+m,1) 
		if(!dept[i]) {
			tot++;
			id[i]=tot;
			dfs(i,tot);
		}
	tot=0;
	REP(i,1,k) {
		int u=read(),v=read();
		if(id[u]==id[v]) 
			fy[++tot]=(edge){dept[lca(u,v)],i,u,v};

	}

	ll ans=0;
	sort(fy+1,fy+1+tot);

	REP(i,1,tot) {
		int u=fy[i].u,v=fy[i].v,w=min(g[u],g[v]);
		ans+=w*2;g[u]-=w;g[v]-=w;
	}

	printf("%lld\n",ans);
	return 0;
}
