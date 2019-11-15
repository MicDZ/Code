#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define int ll
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

int n,m,s,t;

const int MAXN=5000+10,MAXM=100000+10;
const ll INF=0x3f3f3f3f;

int cur[MAXN],head[MAXN],_next[MAXM],to[MAXM],weigh[MAXM],cnt=1;
ll cost[MAXM];

void addedge(int u,int v,int w,int f) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
	cost[cnt]=f;
}


queue<int> q;
int dist[MAXN],inq[MAXN];
bool SPFA() {
	q.push(s);inq[s]=1;
	REP(i,1,n) dist[i]=INF;
	dist[s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();inq[u]=0;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(weigh[i]&&dist[v]>dist[u]+cost[i]) {
				dist[v]=dist[u]+cost[i];
				if(!inq[v]) {
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dist[t]!=INF;
}


ll min_cost;

int dfs(int u,int minn) {
	if(u==t) return minn;
	int sum=0,ft=0;
	inq[u]=1;
	for(int i=cur[u]; i; i=_next[i]) {
		cur[u]=i;
		int v=to[i];
		if(!inq[v]&&weigh[i]&&dist[v]==dist[u]+cost[i]) {
			ft=dfs(v,min(minn-sum,weigh[i]));
			if(ft) {
				weigh[i]-=ft;
				weigh[i^1]+=ft;
				sum+=ft;
				min_cost+=1ll*ft*cost[i];
			}
		}
	}
	inq[u]=0;
	return sum;
}


signed main() {
	file("mcmf-SPFA");
	n=read(),m=read(),s=read(),t=read();
	REP(i,1,m) {
		int u=read(),v=read(),w=read(),f=read();
		addedge(u,v,w,f);
		addedge(v,u,0,-f);
	}
	
	int max_flow=0;
	while(SPFA()) {
		REP(i,1,n) cur[i]=head[i];
		while(1) {
			int x=dfs(s,INF);
			if(!x) break;
			max_flow+=x;
		}
	}
	printf("%lld %lld\n",max_flow,min_cost);
	return 0;
}

