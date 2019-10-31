#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=50000+10,INF=0x3f3f3f;

int head[MAXN],_next[MAXN],to[MAXN],weigh[MAXN],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}
int dist[MAXN],inq[MAXN],n,m;
/*priority_queue<pair<int,int> >q;

void dij(int s) {
	REP(i,1,n) dist[i]=INF;
	dist[s]=0;
	q.push(make_pair(-dist[s],s));
	while(!q.empty()) {
		int u=q.top().second,s=-q.top().first;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[v]>s+weigh[i]) {
				dist[v]=s+weigh[i];
				q.push(make_pair(-dist[v],v));
			}
		}
	}
}*/


queue<int> q;

void SPFA(int s) {
	REP(i,1,n) dist[i]=INF;
	dist[s]=0;inq[s]=1;
	q.push(s);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[v]>dist[u]+weigh[i]) {
				dist[v]=dist[u]+weigh[i];
				if(!inq[v]) {
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}

int main() {
	n=read(),m=read();int s=read(),t=read();
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	SPFA(s);
	printf("%d\n",dist[t]);
	return 0;
}
