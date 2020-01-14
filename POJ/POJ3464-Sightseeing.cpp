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
#define mp(a,b) make_pair(a,b)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1000+10,MAXM=10000+10,INF=0x3f3f3f3f;

int head[MAXN],_next[MAXM<<1],to[MAXM<<1],weigh[MAXM<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int f[MAXN][2],dist[MAXN][2];

void init() {
	cnt=0;
	memset(head,0,sizeof(head));
	memset(f,0,sizeof(f));
	memset(dist,127,sizeof(dist));
}

int s,t;

priority_queue<pair<int,int> > q;

int book[MAXN];

void Dij() {
	q.push(mp(0,s));
	while(!q.empty()) {
		int u=q.top().second;q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[v][0]>dist[u][0]+weigh[i]) {
				dist[v][0]=dist[u][0]+weigh[i];
				f[v][]
			}
		}
	}
}

int main() {
	int t=read();
	while(t--) {
		init();
		int n=read(),m=read();
		REP(i,1,m) {
			int u=read(),v=read(),w=read();
			addedge(u,v,w);
			addedge(v,u,w);
		}
		s=read(),t=read();
		
	}
	return 0;
}

