#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define int ll
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

const int MAXN=100000+10,MAXM=MAXN<<1;

int head[MAXN],_next[MAXM<<1],to[MAXM<<1],weigh[MAXM<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

queue<int> q;

int fa[MAXN];

void bfs(int s,int *dis) {
	q.push(s);
	memset(dis,127,sizeof(dis));
	memset(fa,0,sizeof(fa));

	dis[s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(fa[u]==v) continue;
			fa[v]=u;
			dis[v]=dis[u]+weigh[i];
			q.push(v);
		}
	}
}

int dist[MAXN],dis1[MAXN],dis2[MAXN];

signed main() {
	int n=read(),m=read();
	
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	
	int a=1,b=1;
	
	bfs(1,dist);
	REP(i,1,n) if(dist[i]>dist[a]) a=i;
	bfs(a,dis1);
	REP(i,1,n) if(dis1[i]>dis1[b]) b=i;
	bfs(b,dis2);
	
	int ans=0;

	REP(i,1,n) ans=max(ans,min(dis1[i],dis2[i])+dis1[b]);

	printf("%lld\n",ans);
	return 0;
}

