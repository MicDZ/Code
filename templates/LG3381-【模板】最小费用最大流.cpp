#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

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

const int MAXN=5000+10,MAXM=100000+10,INF=0x3f3f3f;

int cur[MAXN],head[MAXN],_next[MAXM],to[MAXM],weigh[MAXM],cost[MAXM],cnt=1;

void addedge(int u,int v,int w,int c) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
	cost[cnt]=c;
}

int n,m,s,t;

int dist[MAXN],inq[MAXN];

queue<int> q;

bool SPFA() {
	REP(i,1,n) dist[i]=INF;
	q.push(s);
	dist[s]=0,inq[s]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();inq[u]=0;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(weigh[i]&&dist[v]>dist[u]+cost[i]) {
				dist[v]=dist[u]+cost[i];
			//	DE("%d\n",dist[v]);
				if(!inq[v]) {
					q.push(v);
					inq[v]=1;
				}
			}
		}

	}
	return dist[t]!=INF;
}

ll flow;

int dfs(int u,int minn) {
	if(u==t) return minn;
	inq[u]=1;
	int ans=0,ft=0;
	for(int i=cur[u]; i&&ans<minn; i=_next[i]) {
		cur[u]=i;
		int v=to[i];
		if(!inq[v]&&weigh[i]&&dist[v]==dist[u]+cost[i]) {
			ft=dfs(v,min(weigh[i],minn-ans));
			if(ft) flow+=1ll*ft*cost[i],weigh[i]-=ft,weigh[i^1]+=ft,ans+=ft;
		}
	}
	inq[u]=0;
	return ans;
}

int main() {
	n=read(),m=read(),s=read(),t=read();
	REP(i,1,m) {
		int u=read(),v=read(),w=read(),c=read();
		addedge(u,v,w,c);
		addedge(v,u,0,-c);
	}
	int ans=0;	
	while(SPFA()) {
		REP(i,1,n) cur[i]=head[i];
		while(1) {
			int x=dfs(s,INF);
			if(!x) break;
			ans+=x;
		}
	}
	printf("%d %lld\n",ans,flow);
	return 0;
}

