#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
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

const int MAXN=10000+10,MAXM=100000+10;

int head[MAXN],_next[MAXM],to[MAXM],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int a[MAXN];

struct stack {
	int s[MAXN],tp;
	int top() {return s[tp];}
	void pop() {tp--;}
	void push(int x) {s[++tp]=x;}
	int size() {return tp;}
} s;

int dfn[MAXN],low[MAXN],tot,id[MAXN],color,ins[MAXN];

int w[MAXN];

void tarjan(int u) {
	dfn[u]=low[u]=++tot;
	ins[u]=1;s.push(u);
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) {
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) 
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]) {
		int v;color++;
		do {
			v=s.top();s.pop();ins[v]=0;
			id[v]=color;
			w[color]+=a[v];
		} while(u!=v);
	}
}

vector<int> g[MAXN];

int f[MAXN];

void dfs(int u,int dist) {
	if(dist<f[u]) return ;
	f[u]=max(f[u],dist);
	REP(i,0,(int)g[u].size()-1) {
		int v=g[u][i];
		dfs(v,dist+w[v]);
	}
}

int main() {
	int n=read(),m=read();
	
	REP(i,1,n) a[i]=read();

	REP(i,1,m) {
		int u=read(),v=read();
		addedge(u,v);
	}

	REP(i,1,n) if(!dfn[i]) tarjan(i);
	REP(u,1,n) {
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(id[u]!=id[v]) {
				g[id[u]].push_back(id[v]);
			}
		}
	}

	REP(i,1,color) dfs(i,w[i]);
	int ans=0;
	REP(i,1,color) ans=max(ans,f[i]);

	printf("%d\n",ans);
	return 0;
}

