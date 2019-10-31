#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>

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

const int MAXN=1e6+10;

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int ans=1,fa[MAXN];
int n,k,rt;

int in[MAXN];

int dfs(int u) {
	if(in[u]==1) return 0;
	vector<int> g;

	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v) continue;
		fa[v]=u;
		g.push_back(dfs(v)+1);
	}

	sort(g.begin(),g.end());
	int pos;
	while(g.size()>1) {
		if(g[g.size()-1]+g[g.size()-2]<=k) break;
		ans++;
		g.pop_back();
	}

	return g.back();
}


int main() {
	n=read(),k=read(),rt=1;
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
		in[u]++;in[v]++;
		
	}
	REP(i,1,n) if(in[i]>1) {
		rt=i;
		break;
	}	
	dfs(rt);

	printf("%d\n",ans);

	return 0; 
}
