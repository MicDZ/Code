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

const int MAXN=600000+10;

int head[MAXN],_next[MAXN],to[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int w[MAXN],s[MAXN],t[MAXN];

queue<int> q;

int fa[MAXN][20],dept[MAXN];

void bfs(int s) {
	q.push(s);
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(fa[u][0]==v) continue;
			fa[v][0]=u;
			dept[v]=dept[u]+1;
			q.push(v);
		}
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

vector<int> g1[MAXN],g2[MAXN];

int num[MAXN],ans[MAXN],dist[MAXN];

int a[MAXN],b[MAXN];

void dfs(int u) {
	int t1=a[w[u]+dept[u]],t2=b[w[u]-dept[u]+300000];
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u][0]==v) continue;
		dfs(v);
	}	
	a[dept[u]]+=num[u];
	REP(i,0,(int)g1[u].size()-1) {
		int v=g1[u][i];
		b[dist[v]-dept[t[v]]+300000]++;
	}
	ans[u]+=a[w[u]+dept[u]]+b[w[u]-dept[u]+300000]-t1-t2;
	REP(i,0,(int)g2[u].size()-1) {
		int v=g2[u][i];
		a[dept[s[v]]]--;
		b[dist[v]-dept[t[v]]+300000]--;
	}
}

int main() {
	int n=read(),m=read();
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	
	bfs(1);
	REP(j,1,18) REP(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];
	
	REP(i,1,n) w[i]=read();
	
	REP(i,1,m) {
		s[i]=read(),t[i]=read();
		int k=lca(s[i],t[i]);
		dist[i]=dept[s[i]]+dept[t[i]]-2*dept[k];
		num[s[i]]++;
		g1[t[i]].push_back(i);
		g2[k].push_back(i);
		if(dept[k]+w[k]==dept[s[i]]) ans[k]--;
	}
	dfs(1);

	REP(i,1,n) printf("%d ",ans[i]);
	return 0;
}
