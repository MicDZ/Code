#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
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

vector<int> g[2][MAXN];

int f[MAXN],fa[2][MAXN];

void dfs1(int id,int u) {
	REP(i,0,(int)g[id][u].size()-1) {
		int v=g[id][u][i];
		if(fa[id][u]==v) continue;
		fa[id][v]=u;
		dfs1(id,v);
	}
}

int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

int cnt=0;

struct edge {
	int x,y,u,v;
} ans[MAXN];

void dfs2(int u) {
	REP(i,0,(int)g[0][u].size()-1) {
		int v=g[0][u][i];
		if(v==fa[0][u]) continue;
		dfs2(v);
		if(fa[1][v]!=u&&fa[1][u]!=v) ans[++cnt]=(edge){u,v,find(v),fa[1][find(v)]};
	}
}

int main() {
	int k=read();
	REP(i,1,k-1) {
		int u=read(),v=read();
		g[0][u].push_back(v);
		g[0][v].push_back(u);
	}
	REP(i,1,k-1) {
		int u=read(),v=read();
		g[1][u].push_back(v);
		g[1][v].push_back(u);
	}
	dfs1(0,1);
	dfs1(1,1);
	REP(i,1,k)
		f[i]=(fa[1][i]==0||(fa[0][i]!=fa[1][i]&&fa[0][fa[1][i]]!=i))?i:fa[1][i];
	dfs2(1);

	printf("%d\n",cnt);
	REP(i,1,cnt) printf("%d %d %d %d\n",ans[i].x,ans[i].y,ans[i].u,ans[i].v);
	return 0;
}
