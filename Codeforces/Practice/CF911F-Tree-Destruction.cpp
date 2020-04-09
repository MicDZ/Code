#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;
#define int ll
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

const int MAXN=200000+10;

int head[MAXN],to[MAXN<<1],_next[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int dist[MAXN],on[MAXN],fa[MAXN];

void dfs(int u,int f) {
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(v==f) continue;
		fa[v]=u;
		dist[v]=dist[u]+1;
		dfs(v,u);
	
	}
}

void dfs2(int u,int fa) {
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(v==fa) continue;
		dfs2(v,u);
		on[u]=on[u]|on[v];
	}
}

int sum=0;
vector<pair<int,int> > ans;

int st,ed;

int vis[MAXN];

void dfs3(int u,int fa,int rt) {
	
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(v!=fa) 
			dfs3(v,u,on[v]?v:rt);
		//DE("%lld\n",u);
		
	}
	if(!on[u]) {
			if(dist[u]>dist[u]+dist[ed]-2*dist[rt]) {
				sum+=dist[u];
				ans.push_back(make_pair(st,u));
			}
			else {
				sum+=dist[u]+dist[ed]-2*dist[rt];
				ans.push_back(make_pair(ed,u));
			}
			
		}
}

signed main() {
	int n=read();
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	
	dist[1]=0;dfs(1,0);
	st=1,ed=1;
	REP(i,1,n) if(dist[i]>dist[st]) st=i;
	dist[st]=0;dfs(st,0);
	REP(i,1,n) if(dist[i]>dist[ed]) ed=i;
	
	on[ed]=1;
	

	dfs2(st,0);
	//REP(i,1,n) DE("%lld ",on[i]);
	dfs3(st,0,st);
	

	for(;st!=ed;ed=fa[ed]) {sum+=dist[ed],ans.push_back(make_pair(st,ed));}
	printf("%lld\n",sum); 
	
	REP(i,0,(int)ans.size()-1) {
		printf("%lld %lld %lld\n",ans[i].first,ans[i].second,ans[i].second);
	}
	return 0;
}
