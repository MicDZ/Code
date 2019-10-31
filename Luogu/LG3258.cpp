#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;
#define ll long long
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define int ll

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=300000+10;

int a[MAXN];

int _next[MAXN<<1],to[MAXN<<1],head[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int dept[MAXN],vis[MAXN],fa[MAXN][35],ans[MAXN];

queue<int> q;

void bfs(int s) {
	q.push(s);
	dept[s]=1;vis[s]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(!vis[v]) {
				vis[v]=1;
				dept[v]=dept[u]+1;
				fa[v][0]=u;
				q.push(v);
			}
		}
	}
}

int lca(int u,int v) {
	if(dept[u]<dept[v]) swap(u,v);
	int len=dept[u]-dept[v];
	DREP(i,29,0) if((1<<i)&len) u=fa[u][i];

	if(u==v) return u;

	DREP(i,29,0) 
		if(fa[u][i]!=fa[v][i]) {
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}

void dfs(int u) {
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u][0]==v) continue ;
		dfs(v);
		ans[u]+=ans[v];
	}
}

signed main() {
	file("q");
	int n=read();
	REP(i,1,n) a[i]=read();

	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	
	bfs(1);
	
	//REP(i,1,n) printf("%d ",dept[i]);puts("");

	REP(j,1,29) REP(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];

	fa[1][0]=0;
	REP(i,1,n-1) {
		int u=a[i],v=a[i+1];
		ans[u]++;
		ans[v]++;
		int q=lca(u,v);
	//	printf("%d ",q);
		ans[q]--;
		ans[fa[q][0]]--;
	}
	//puts("");
	//REP(i,1,n) printf("%d ",ans[i]);
dfs(1);
	
	REP(i,2,n) ans[a[i]]--;
	
	REP(i,1,n) printf("%d\n",ans[i]);
return 0;
}
