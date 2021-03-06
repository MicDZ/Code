#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
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

const int MAXN=10000+10,MAXM=100000+10;

int w[MAXN],head[MAXN],to[MAXM],_next[MAXM],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int dfn[MAXN],low[MAXN],ins[MAXN],tot,color,id[MAXN],weigh[MAXN];

stack<int> s;

void tarjan(int u) {
	dfn[u]=low[u]=++tot;
	s.push(u);ins[u]=1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) {
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u]) {
		color++;
		int v;
		do {
			v=s.top();s.pop();ins[v]=0;
			id[v]=color;
			weigh[color]+=w[v];
		} while(u!=v);
	}
}

vector<int> g[MAXN];

int f[MAXN];

void dfs(int u) {
	if(f[u]) return ;
	f[u]=weigh[u];
	int ans=0;
	REP(i,0,(int)g[u].size()-1) {
		int v=g[u][i];
		if(!f[v]) dfs(v);
		ans=max(ans,f[v]);
	}
	f[u]+=ans;
}

int main() {
	//file("testdata");
	int n=read(),m=read();
	REP(i,1,n) w[i]=read();
	REP(i,1,m) {
		int u=read(),v=read();
		addedge(u,v);
	}

	REP(i,1,n) if(!dfn[i]) tarjan(i);
	
	REP(u,1,n) for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(id[u]==id[v]) continue;
		g[id[u]].push_back(id[v]);
	}

	REP(i,1,color) if(!f[i]) dfs(i);
	
	int ans=0;
	REP(i,1,n) ans=max(ans,f[i]);

	printf("%d\n",ans);
	return 0;
}
