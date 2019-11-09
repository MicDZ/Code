#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;
#define int ll
#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ll MAXN=50000+10,MAXM=200000+10,INF=0x3f3f3f3f3f3f;

int head[MAXN],_next[MAXM<<1],to[MAXM<<1],cnt;

ll weigh[MAXM<<1];

void addedge(int u,int v,ll w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

priority_queue<pair<int,ll> > q;

int book[MAXN];

int n,m,k;

void Dij(ll *dis,int s) {
	q.push(make_pair(0,s));
	
	REP(i,1,n) book[i]=0,dis[i]=INF;
	dis[s]=0;
	while(!q.empty()) {
		int u=q.top().second;q.pop();
		if(book[u]) continue;
		book[u]=1;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dis[v]>dis[u]+weigh[i]) {
				dis[v]=dis[u]+weigh[i];
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}

struct edge {
	int u,v;
	ll w;
} e[MAXN];


ll dist[30][MAXN],f[4097][30];

signed main() {
	n=read(),m=read(),k=read();

	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
		if(i<=k) e[i]=(edge){u,v,w};
	}
	
	REP(i,1,k) Dij(dist[2*i],e[i].u),Dij(dist[2*i+1],e[i].v);
	Dij(dist[1],1);
	
	int S=1<<k;
	
	memset(f,127,sizeof(f));
	
	f[0][1]=0;
	REP(i,0,S-1) REP(j,1,k) {
		if(i&(1<<j-1)) continue;
		ll s=i|(1<<j-1);
		REP(m,1,2*k+1) {
			f[s][j<<1]=min(f[s][j<<1],f[i][m]+dist[m][e[j].v]+weigh[2*j]);
			f[s][j<<1|1]=min(f[s][j<<1|1],f[i][m]+dist[m][e[j].u]+weigh[2*j]);
		}
	}
	ll ans=INF;
	REP(i,1,k*2+1) ans=min(ans,f[S-1][i]+dist[i][1]);

	printf("%lld\n",ans);
}

