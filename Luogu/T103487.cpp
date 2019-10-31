#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

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

struct edge {
	int x,y,id;
} a[MAXN];

bool cmp1(edge a,edge b) {
	return a.x<b.x;
}

bool cmp2(edge a,edge b) {
	return a.y<b.y;
}

int head[MAXN],_next[MAXN<<2],to[MAXN<<2],weigh[MAXN<<2],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int dist[MAXN],inq[MAXN];

queue<int> q;

void SPFA(int s) {
	q.push(s);
	inq[s]=1;
	memset(dist,127,sizeof(dist));
	dist[s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();inq[u]=0;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[v]>dist[u]+weigh[i]) {
				dist[v]=dist[u]+weigh[i];
				if(!inq[v]) {
					inq[v]=1;
					q.push(v);
				}
			}	
		}
	}
}

bool book[MAXN];
priority_queue<pair<int,int> > q2;
void dij(int s) {
	memset(dist,127,sizeof(dist));
	dist[s]=0;
	q2.push(make_pair(0,s));
	while(!q2.empty()) {
		int u=q2.top().second;q2.pop();
		if(book[u]) continue;
		book[u]=1;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[v]>dist[u]+weigh[i]) {
				dist[v]=dist[u]+weigh[i];
				q2.push(make_pair(-dist[v],v));
			}
		}
	}
}

int main() {
	int n=read();
	REP(i,1,n) 
		a[i]=(edge){read(),read(),i};
	
	sort(a+1,a+1+n,cmp1);
	REP(i,1,n-1) {
		addedge(a[i].id,a[i+1].id,a[i+1].x-a[i].x);
		addedge(a[i+1].id,a[i].id,a[i+1].x-a[i].x);
	}
	
	sort(a+1,a+1+n,cmp2);

	REP(i,1,n-1) {
		addedge(a[i].id,a[i+1].id,a[i+1].y-a[i].y);
		addedge(a[i+1].id,a[i].id,a[i+1].y-a[i].y);
	}

	dij(1);
	//SPFA(1);
	printf("%d\n",dist[n]);
	return 0;
}
