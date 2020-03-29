#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

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

const int MAXN=500000+10;

int head[MAXN],to[MAXN<<1],_next[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int fa[MAXN],size[MAXN],dept[MAXN],hson[MAXN];

void dfs1(int u) {
	size[u]=1;
	dept[u]=dept[fa[u]]+1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v) continue;
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
		if(!hson[u]||size[hson[u]]<size[v]) hson[u]=v;
	}
}

int top[MAXN],id[MAXN],tot;

void dfs2(int u,int nowtop) {
	id[u]=++tot;
	top[u]=nowtop;
	if(hson[u]) dfs2(hson[u],nowtop);
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v||hson[u]==v) continue;
		fa[v]=u;
		dfs2(v,v);
	}
}

int lca(int u,int v) {
	while(top[u]!=top[v]) {
		if(dept[top[u]]<dept[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	if(dept[u]<dept[v]) swap(u,v);
	return v;
}

int main() {
	int n=read(),m=read(),rt=read();
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	dfs1(rt);dfs2(rt,rt);
	
	REP(i,1,m) {
		int u=read(),v=read();
		printf("%d\n",lca(u,v));
	}
	return 0;
}

