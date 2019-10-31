// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1000000+10;

int _next[MAXN],head[MAXN],to[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int dept[MAXN],fa[MAXN][30],vis[MAXN];

queue<int> q;

void bfs(int s) {
	q.push(s);vis[s]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(vis[v]) continue;
			fa[v][0]=u;
			dept[v]=dept[u]+1;
			q.push(v);
			vis[v]=1;
		}
	}
}

int lca(int u,int v) {
	if(dept[u]<dept[v]) swap(u,v);
	int len=dept[u]-dept[v];
	
	DREP(i,19,0) if((1<<i)&len) u=fa[u][i];
	
	if(u==v) return u;
	
	DREP(i,19,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	
	return fa[u][0];
}

struct city{
	int id,dep;
}ci[5];

bool cmp(city a,city b) {
	return a.dep>b.dep;
}

int main() {
//	file("c");
	int n=read(),m=read();
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}

	bfs(1);
	
	REP(j,1,19) REP(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];
	
	REP(i,1,m) {
		int x=read(),y=read(),z=read();
		ci[1].id=lca(x,y); ci[1].dep=dept[ci[1].id];
		ci[2].id=lca(y,z); ci[2].dep=dept[ci[2].id];
		ci[3].id=lca(x,z); ci[3].dep=dept[ci[3].id];
		
		//printf("%d %d %d\n",ci[1].id,ci[2].id,ci[3].id);
		
		sort(ci+1,ci+1+3,cmp);
		
		printf("%d %d\n",ci[1].id,dept[x]+dept[y]+dept[z]-dept[ci[1].id]-dept[ci[2].id]-dept[ci[3].id]);
	}
} 
/*
9 5
1 2
1 3
2 4
2 5
3 6
3 7
6 8
7 9
*/
