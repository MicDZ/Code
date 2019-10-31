#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=2147483647,MAXN=100000+10,MAXM=200000+10;

int head[MAXN],_next[MAXM<<1],to[MAXM<<1],weigh[MAXM<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
} 

priority_queue <pair<int,int> > q;

int dist[MAXN],book[MAXN];

int n,m,s;

void Dij(int s) {
	q.push(make_pair(0,s));
	REP(i,1,n) dist[i]=INF;
	dist[s]=0;
	while(!q.empty()) {
		int u=q.top().second;q.pop();
		if(book[u]) continue;
		book[u]=1;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[v]>dist[u]+weigh[i]) {
				dist[v]=dist[u]+weigh[i];
				q.push(make_pair(-dist[v],v));
			}
		}
	}
}

int main() {
	n=read(),m=read(),s=read();
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
	}
	
	Dij(s);

	REP(i,1,n) printf("%d ",dist[i]);
	return 0;
}

