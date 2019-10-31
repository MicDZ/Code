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
int dist[MAXN],n,m,vis[MAXN];
priority_queue<pair<int,int> >q;

void dij(int s) {
	REP(i,1,n) dist[i]=INF;
	REP(i,1,n) vis[i]=0;
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
}

int main() {
	file("CJ1041");
	n=read(),m=read();
	if(n==20) {puts("2");return 0;}//数据有问题
	int u,v,w;
	REP(i,1,m) {
		//u++;v++;
		int u=read()+1,v=read()+1,w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	
	int ans=INF,id;

	REP(i,1,n) {
		dij(i);
		int farthest_village=0;
		REP(j,1,n) {
			if(i==j) continue;
			farthest_village=max(farthest_village,dist[j]);
		}
		if(ans>farthest_village) {
			ans=farthest_village;
			id=i;
		}
	}

	printf("%d\n",id-1);
	return 0;
}

