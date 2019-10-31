#include<bits/stdc++.h>
#define MAXN 500000+10
#define INF 0x3f3f3f3f
using namespace std;
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int head[MAXN<<1],to[MAXN<<1],next[MAXN<<1],weigh[MAXN<<1],cnt=0;

int n,m,s,t;

void addedge(int u,int v,int w) {
    cnt++;
    to[cnt]=v;
    next[cnt]=head[u];
    head[u]=cnt;
	weigh[cnt]=w;
}

struct node {
	int u,d;
	bool operator< (const node& rhs) const {
		return d>rhs.d;
	}
};

int d[MAXN];
void Dijkstra() {
	//priority_queue<int,vector<int>,greater<int> >q;
	priority_queue<node> q;
	memset(d,INF,sizeof(d));
	d[s]=0;
	q.push((node){s,d[s]});
	while(!q.empty()) {
		node x=q.top(); q.pop();
		int u=x.u;
		if(x.d!=d[u]) continue;
		for(int i=head[u]; i; i=next[i]) {
			int v=to[i],w=weigh[i];
			if(d[u]+w<d[v]) {
				d[v]=d[u]+w;
				q.push((node){v,d[v]});
			}
		}
	}
}

int main() {
	memset(head,-1,sizeof(head));
	n=read(); m=read(); s=read();
	for(int i=1; i<=m; i++) {
		int u,v,w;
		u=read(); v=read(); w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	Dijkstra();
	for(int i=1; i<=n; i++) printf("%d ",d[i]);
	return 0;
}
